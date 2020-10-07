//
// Created by Sorin Sebastian Mircea on 07/10/2020.
//

#include <vector>
#include <algorithm>
#include <iostream>

#include "FifoReliableBroadcast.h"

namespace da {
  namespace broadcast {
    FifoReliableBroadcast::FifoReliableBroadcast(std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket): UniformReliableBroadcast(hosts, logger, socket) {
      this->next.resize(hosts.size() + 3);
      std::fill(this->next.begin(), this->next.end(), 1);
    }

    void FifoReliableBroadcast::deliver(da::sockets::Data &data, bool commitToLog) {
      UniformReliableBroadcast::deliver(data, false);

      bool shouldExit = false;
      while(shouldExit == false) {
        shouldExit = true;

        for(auto packet: this->pending) {
          auto packetData = *packet.second;

          // actually deliver the package
          if(next[data.from_pid] == packetData.seq_number) {
            next[data.from_pid] += 1;

            // commit the delivery
            if(commitToLog) {
              std::string logMsg = "d " + std::to_string(data.from_pid) + " " + std::to_string(packetData.seq_number) + "\n";
              this->logger.write(logMsg);
            }

            // erase from pending
            this->pending.erase(packet.first);
            shouldExit = false;
            break;
          }
        }
      }
    }
  }
}