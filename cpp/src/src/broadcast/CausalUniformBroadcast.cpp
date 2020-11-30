//
// Created by Sorin Sebastian Mircea on 07/10/2020.
//

#include <vector>
#include <algorithm>
#include <iostream>

#include "CausalUniformBroadcast.h"

namespace da {
  namespace broadcast {
    std::mutex mtx;
    CausalUniformBroadcast::CausalUniformBroadcast(int current_pid, std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket): UniformReliableBroadcast(current_pid, hosts, logger, socket) {
      this->next.resize(hosts.size() + 3);
      std::fill(this->next.begin(), this->next.end(), 1);
    }

    void CausalUniformBroadcast::broadcast(da::sockets::Data &data) {
      data.past = past;
      past.push_back(std::make_pair(data.original_from_pid, data.data));
      UniformReliableBroadcast::broadcast(data);

      // std::cout << "cub broadcast " << data << " of past size: " << data.past.size() << "\n" << std::flush;
      // for(auto dataPast: data.past) {
      //   std::cout << dataPast.first << " -> " << dataPast.second << "\n "<< std::flush;
      // }
      // std::cout << "\n" << std::flush;
    }

    void CausalUniformBroadcast::deliver(da::sockets::Data &data, bool commitToLog) {
      // std::cout << "cub deliver  " << data << " of past size: " << data.past.size() << "\n" << std::flush;
      // First try to deliver the past
      for(auto dataPast: data.past) {
        // std::cout << dataPast.first << " -> " << dataPast.second << "\n" << std::flush;
        std::string pastMsgIdentifier =  std::to_string(dataPast.first) + ":" + std::to_string(dataPast.second);
        
        // if it was not delivered, then deliver
        if(wasDelivered.find(pastMsgIdentifier) == wasDelivered.end()) {
            // Wrap the pair <from_pid, data> to a data object and call the underlying urb
            da::sockets::Data toDeliver;
            toDeliver.from_pid = dataPast.first;
            toDeliver.original_from_pid = dataPast.first;
            toDeliver.data = dataPast.second;
            // To do: add a seq numebr
            toDeliver.seq_number = dataPast.second;
            past.push_back(dataPast);
            wasDelivered.insert(pastMsgIdentifier);
            UniformReliableBroadcast::deliver(toDeliver, true);
        }
      }

      // Once the past is delivered, deliver the current data
      if(wasDelivered.find(data.getUniqueIdentifier()) == wasDelivered.end()) {
        UniformReliableBroadcast::deliver(data, true);
        wasDelivered.insert(data.getUniqueIdentifier());
        past.push_back(std::make_pair(data.original_from_pid, data.data));
      }
    }
  }
}