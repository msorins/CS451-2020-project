#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <signal.h>

#include "barrier.hpp"
#include "parser.hpp"
#include "sockets/FairLossSocket.h"
#include "sockets/StubbornSocket.h"
#include "sockets/PerfectSocket.h"
#include "sockets/Data.h"
#include "sockets/SocketType.h"
#include "threads/ThreadPool.h"
#include "tools/Logger.h"
#include "broadcast/UniformReliableBroadcast.h"
int getNrOfBroadcastMessages(std::string filePath);
da::tools::Logger *logger;

static void stop(int)
{
  // reset signal handlers to default
  signal(SIGTERM, SIG_DFL);
  signal(SIGINT, SIG_DFL);

  // immediately stop network packet processing
  std::cout << "Immediately stopping network packet processing.\n";
  // !!! To Do !!!

  // write/flush output file if necessary
  std::cout << "Writing output.\n";
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

int main(int argc, char **argv)
{
  signal(SIGTERM, stop);
  signal(SIGINT, stop);

  // `true` means that a config file is required.
  // Call with `false` if no config file is necessary.
  bool requireConfig = true;

  Parser parser(argc, argv, requireConfig);
  parser.parse();

  std::cout << "My PID: " << getpid() << "\n";
  std::cout << "Use `kill -SIGINT " << getpid() << "` or `kill -SIGTERM "
            << getpid() << "` to stop processing packets\n\n";

  std::cout << "My ID: " << parser.id() << "\n\n";

  std::cout << "Path to hosts:\n";
  std::cout << "==============\n";
  std::cout << parser.hostsPath() << "\n\n";

  std::cout << "List of resolved hosts is:\n";
  std::cout << "==========================\n";
  auto hosts = parser.hosts();
  for (auto &host : hosts)
  {
    std::cout << host.id << "\n";
    std::cout << "Human-readable IP: " << host.ipReadable() << "\n";
    std::cout << "Machine-readable IP: " << host.ip << "\n";
    std::cout << "Human-readbale Port: " << host.portReadable() << "\n";
    std::cout << "Machine-readbale Port: " << host.port << "\n";
    std::cout << "\n";
  }
  std::cout << "\n";

  std::cout << "Barrier:\n";
  std::cout << "========\n";
  auto barrier = parser.barrier();
  std::cout << "Human-readable IP: " << barrier.ipReadable() << "\n";
  std::cout << "Machine-readable IP: " << barrier.ip << "\n";
  std::cout << "Human-readbale Port: " << barrier.portReadable() << "\n";
  std::cout << "Machine-readbale Port: " << barrier.port << "\n";
  std::cout << "\n";

  std::cout << "Signal:\n";
  std::cout << "========\n";
  auto signal = parser.signal();
  std::cout << "Human-readable IP: " << signal.ipReadable() << "\n";
  std::cout << "Machine-readable IP: " << signal.ip << "\n";
  std::cout << "Human-readbale Port: " << signal.portReadable() << "\n";
  std::cout << "Machine-readbale Port: " << signal.port << "\n";
  std::cout << "\n";

  std::cout << "Path to output:\n";
  std::cout << "===============\n";
  std::cout << parser.outputPath() << "\n\n";

  if (requireConfig)
  {
    std::cout << "Path to config:\n";
    std::cout << "===============\n";
    std::cout << parser.configPath() << "\n\n";
  }

  std::cout << "Doing some initialization...\n\n";

  // START INIT
  int m = getNrOfBroadcastMessages(std::string(parser.configPath()));
  std::cout << "Nr of messages per process is: " << m << "\n";
  logger = new da::tools::Logger(parser.outputPath());
  // END INIT
  Coordinator coordinator(parser.id(), barrier, signal);
  std::cout << "Waiting for all processes to finish initialization\n\n";
  auto &tp = da::threads::ThreadPool::getInstance(static_cast<int>(parser.hosts().size()) * m * 5);
  coordinator.waitOnBarrier();

  // START RECEIVING
  std::cout << "Start receiving !! \n";
  int currentHostIndex = -1;
  for(int i = 0; i < static_cast<int>(hosts.size()); ++i) {
    if(hosts[i].id == parser.id()) {
      currentHostIndex = i;
    }
  }
  auto selfSocket = da::sockets::PerfectSocket(hosts[currentHostIndex].ipReadable(), static_cast<int>(hosts[currentHostIndex].portReadable()), da::sockets::SocketType::RECEIVE);
  da::broadcast::UniformReliableBroadcast urb(parser.hosts(), *logger, selfSocket);
  urb.receive_loop();
  // END RECEIVING

  // START BROADCAST
  std::cout << "Start broadcasting !! \n";
  int offset = static_cast<int>(parser.id()) * 10000;
  for (int i = 0; i < m; i++)
  {
      da::sockets::Data data(static_cast<int>(parser.id()), i + offset);
      std::cout << "Broadcasting: " << data << "\n";
      urb.broadcast(data);
  }
  // END BROADCAST

  std::cout << "Signaling end of broadcasting messages\n\n";
  // coordinator.finishedBroadcasting();

  while (true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(60));
  }

  return 0;
}
