//
// Created by Sorin Sebastian Mircea on 07/10/2020.
//

#include <vector>
#include <algorithm>
#include <iostream>

#include "FifoReliableBroadcast.h"

namespace da {
  namespace broadcast {
    FifoReliableBroadcast::FifoReliableBroadcast(int current_pid, std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket): UniformReliableBroadcast(current_pid, hosts, logger, socket) {
      this->next.resize(hosts.size() + 3);
      std::fill(this->next.begin(), this->next.end(), 1);
    }

    void FifoReliableBroadcast::deliver(da::sockets::Data &data, bool commitToLog) {
      UniformReliableBroadcast::deliver(data, false);

      bool shouldExit = false;
      while(!shouldExit) {
        shouldExit = true;

        //std::cout << "frb deliver: " << data << ": ";
        for(int i = 1; i <= static_cast<int>(this->hosts.size()); ++i ) {
          //std::cout << next[i] << " ";
        }
        //std::cout << "\n";
        for(auto packet: this->pending) {
          auto packetData = *packet.second;
          //std::cout<<"( " << packetData << ") ";

          // actually deliver the package
          if(next[data.original_from_pid] == packetData.seq_number && packetData.original_from_pid == data.original_from_pid) {
            next[data.original_from_pid] += 1;

            // commit the delivery
            if(commitToLog) {
              this->logger.writeDeliver(data.original_from_pid, packetData.seq_number);
            }

            // erase from pending
            this->pending.erase(packet.first);
            shouldExit = false;
            break;
          }
        }
        //std::cout<<"\n\n";
      }

    }
  }
}