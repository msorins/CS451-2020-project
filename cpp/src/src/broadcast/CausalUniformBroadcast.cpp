//
// Created by Sorin Sebastian Mircea on 07/10/2020.
//

#include <vector>
#include <algorithm>
#include <iostream>

#include "CausalUniformBroadcast.h"

namespace da {
  namespace broadcast {
    CausalUniformBroadcast::CausalUniformBroadcast(int current_pid, std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket): UniformReliableBroadcast(current_pid, hosts, logger, socket) {
      this->next.resize(hosts.size() + 3);
      std::fill(this->next.begin(), this->next.end(), 1);
    }

    void CausalUniformBroadcast::broadcast(da::sockets::Data &data) {
      data.past = past;
      UniformReliableBroadcast::broadcast(data);
      past.push_back(std::make_pair(data.original_from_pid, data.data));
    }

    void CausalUniformBroadcast::deliver(da::sockets::Data &data, bool commitToLog) {
      // First try to deliver the past
      for(auto dataPast: data.past) {
        std::string pastMsgIdentifier =  std::to_string(dataPast.first) + ":" + std::to_string(dataPast.second);
        
        // if it was not delivered, then deliver
        if(wasDelivered.find(pastMsgIdentifier) == wasDelivered.end()) {
            // Wrap the pair <from_pid, data> to a data object and call the underlying urb
            da::sockets::Data toDeliver;
            toDeliver.from_pid = dataPast.first;
            toDeliver.original_from_pid = dataPast.first;
            toDeliver.data = dataPast.second;
            // To do: add a seq numebr
            toDeliver.seq_number = -1;
            UniformReliableBroadcast::deliver(toDeliver, true);

            wasDelivered.insert(pastMsgIdentifier);
            past.push_back(dataPast);
        }
      }

      // Once the past is delivered, deliver the current data
      UniformReliableBroadcast::deliver(data, true);
      wasDelivered.insert(data.getUniqueIdentifier());
      past.push_back(std::make_pair(data.original_from_pid, data.data));
    }
  }
}