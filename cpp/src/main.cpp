#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <signal.h>
#include <unordered_set>
#include "barrier.hpp"
#include "parser.hpp"
#include "sockets/FairLossSocket.h"
#include "sockets/StubbornSocket.h"
#include "sockets/PerfectSocket.h"
#include "sockets/Data.h"
#include "sockets/SocketType.h"
#include "sockets/SendLoop.h"
#include "threads/InfiniteThreadPool.h"
#include "tools/Logger.h"
#include "broadcast/CausalUniformBroadcast.h"
#include "tools/AppStatus.h"

int getNrOfBroadcastMessages(std::string filePath);
std::unordered_set<int> getDependencyList(std::string filePath, int forProcess);
da::tools::Logger *logger;

static void stop(int)
{
  // reset signal handlers to default
  signal(SIGTERM, SIG_DFL);
  signal(SIGINT, SIG_DFL);

  // immediately stop network packet processing
  //std::cout << "Immediately stopping network packet processing.\n";
  da::tools::AppStatus::isRunning = false;

  // write/flush output file if necessary
  logger->closeFile();

  // exit directly from signal handler
  exit(0);
}

int getNrOfBroadcastMessages(std::string filePath)
{
  std::ifstream f(filePath);
  int m = 0;
  f >> m;
  return m;
}

std::unordered_set<int> getDependencyList(std::string filePath, int forProcess) {
  std::unordered_set<int> setOfNumbers;
  std::ifstream input(filePath);
  int lineNr = 0;
  for( std::string line; getline( input, line ); )
  {
    std::cout << "\nline: " << line << "----> " << std::flush;
    if(lineNr == 0) {
      continue;
    }

    int digitNr = 0;
    int digitsForProcId = -1;
    std::stringstream stream(line);
    while(1) {
      std::cout << "intrat " << "\n";
      int n;
      stream >> n;
      std::cout << "nr: " << n << ", " << std::flush;
      if(!stream)
          break;
      if(digitNr == 0) {
          digitsForProcId = n;
      } 
      if(digitNr > 0 && digitsForProcId == forProcess) {
        setOfNumbers.insert(n);
      }
      digitNr++;
    }
  }

  setOfNumbers.insert(forProcess);
  return setOfNumbers;
}

int main(int argc, char **argv)
{
  signal(SIGTERM, stop);
  signal(SIGINT, stop);

  // `true` means that a config file is required.
  // Call with `false` if no config file is necessary.
  bool requireConfig = true;

  Parser parser(argc, argv, requireConfig);
  parser.parse();

  //std::cout << "My PID: " << getpid() << "\n";
  //std::cout << "Use `kill -SIGINT " << getpid() << "` or `kill -SIGTERM "
            // << getpid() << "` to stop processing packets\n\n";

  //std::cout << "My ID: " << parser.id() << "\n\n";

  //std::cout << "Path to hosts:\n";
  //std::cout << "==============\n";
  //std::cout << parser.hostsPath() << "\n\n";

  //std::cout << "List of resolved hosts is:\n";
  //std::cout << "==========================\n";
  auto hosts = parser.hosts();
  for (auto &host : hosts)
  {
    //std::cout << host.id << "\n";
    //std::cout << "Human-readable IP: " << host.ipReadable() << "\n";
    //std::cout << "Machine-readable IP: " << host.ip << "\n";
    //std::cout << "Human-readbale Port: " << host.portReadable() << "\n";
    //std::cout << "Machine-readbale Port: " << host.port << "\n";
    //std::cout << "\n";
  }
  //std::cout << "\n";

  //std::cout << "Barrier:\n";
  //std::cout << "========\n";
  auto barrier = parser.barrier();
  //std::cout << "Human-readable IP: " << barrier.ipReadable() << "\n";
  //std::cout << "Machine-readable IP: " << barrier.ip << "\n";
  //std::cout << "Human-readbale Port: " << barrier.portReadable() << "\n";
  //std::cout << "Machine-readbale Port: " << barrier.port << "\n";
  //std::cout << "\n";

  //std::cout << "Signal:\n";
  //std::cout << "========\n";
  auto signal = parser.signal();
  //std::cout << "Human-readable IP: " << signal.ipReadable() << "\n";
  //std::cout << "Machine-readable IP: " << signal.ip << "\n";
  //std::cout << "Human-readbale Port: " << signal.portReadable() << "\n";
  //std::cout << "Machine-readbale Port: " << signal.port << "\n";
  //std::cout << "\n";

  //std::cout << "Path to output:\n";
  //std::cout << "===============\n";
  //std::cout << parser.outputPath() << "\n\n";

  if (requireConfig)
  {
    //std::cout << "Path to config:\n";
    //std::cout << "===============\n";
    //std::cout << parser.configPath() << "\n\n";
  }

  //std::cout << "Doing some initialization...\n\n";

  // START INIT
  int m = getNrOfBroadcastMessages(std::string(parser.configPath()));
  auto dependencyList = getDependencyList(std::string(parser.configPath()), static_cast<int>(parser.id()));
  std::cout << "dependencies: ";
  for(auto dependency: dependencyList) {
    std::cout << dependency << " ";
  }
  std::cout << "\n" << std::flush;

  //std::cout << "Nr of messages per process is: " << m << "\n";
  logger = new da::tools::Logger(parser.outputPath());
  // END INIT
  Coordinator coordinator(parser.id(), barrier, signal);
  //std::cout << "Waiting for all processes to finish initialization\n\n";
  auto &tp = da::threads::InfiniteThreadPool::getInstance();
  coordinator.waitOnBarrier();

  // START RECEIVING
  int currentHostIndex = -1;
  for(int i = 0; i < static_cast<int>(hosts.size()); ++i) {
    if(hosts[i].id == parser.id()) {
      currentHostIndex = i;
    }
  }
  auto selfSocket = da::sockets::PerfectSocket(hosts[currentHostIndex].ipReadable(), static_cast<int>(hosts[currentHostIndex].portReadable()), da::sockets::SocketType::RECEIVE);
  da::broadcast::CausalUniformBroadcast frb(static_cast<int>(parser.id()), parser.hosts(), *logger, selfSocket, dependencyList);
  frb.receive_loop();
  // END RECEIVING

  // START SEND LOOP
  da::sockets::SendLoop sendLoop;
  sendLoop.start_loop();

  // START BROADCAST
  //std::cout << "Start broadcasting !! \n";
  for (int i = 1; i <= m; i++)
  {
      da::sockets::Data data(static_cast<int>(parser.id()), i);
      logger->writeBroadcast(data.seq_number);
      frb.broadcast(data);
  }
  // Keep broadcasting until we hit the desired nr of delivered messages
  while (true)
  {
    //std::cout << "Nr of delivered items: " << logger->getNrOfDelivers() << "; Nr of threads: " << tp.size();
    if(logger->getNrOfDelivers() >= static_cast<int>(parser.hosts().size()) * m) {
      //std::cout << "App state set to isRunning false" << "\n";
      da::tools::AppStatus::isRunning = false;
      break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }

  // Close File
  logger->closeFile();

  // END BROADCAST
  //std::cout << "Signaling end of broadcasting messages\n\n";
  coordinator.finishedBroadcasting();
  exit(0);
}
