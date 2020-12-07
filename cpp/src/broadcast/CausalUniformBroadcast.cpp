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
    CausalUniformBroadcast::CausalUniformBroadcast(int current_pid, std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket, std::unordered_set<int> &dependency_list): UniformReliableBroadcast(current_pid, hosts, logger, socket) {
      this->dependency_list = dependency_list;
    }

    void CausalUniformBroadcast::broadcast(da::sockets::Data &data) {
      data.past = past;
      std::cout << "cub broadcast: " << data << "\n" << std::flush;

      UniformReliableBroadcast::broadcast(data);
      // && this->dependency_list.find(data.from_pid) != this->dependency_list.end()
      if(isInPast.find(data.getMessageIdentifier()) == isInPast.end()) {
        da::sockets::Data dataCopy(data);
        dataCopy.past = std::vector<da::sockets::Data>();
        past.push_back(dataCopy);
        isInPast.insert(data.getMessageIdentifier());
      }
    }

    void CausalUniformBroadcast::deliver(da::sockets::Data &data, bool commitToLog) {
      std::cout << "cub deliver: " << data << ": ";
      // First try to deliver the past
      for(auto dataPast: data.past) {
        // std::cout << dataPast.first << " -> " << dataPast.second << ", ";
        // if it was not delivered, then deliver
        if(wasDelivered.find(dataPast.getMessageIdentifier()) == wasDelivered.end()) {
            // Wrap the pair <from_pid, data> to a data object and call the underlying urb
            wasDelivered.insert(dataPast.getMessageIdentifier());
            UniformReliableBroadcast::deliver(dataPast, true);

            // && this->dependency_list.find(dataPast.from_pid) != this->dependency_list.end()
            if(isInPast.find(dataPast.getMessageIdentifier()) == isInPast.end()) {
               da::sockets::Data dataCopy(dataPast);
              dataCopy.past = std::vector<da::sockets::Data>();
              past.push_back(dataCopy);
              isInPast.insert(dataPast.getMessageIdentifier());
            }
        }
      }

      // Once the past is delivered, deliver the current data
      if(wasDelivered.find(data.getMessageIdentifier()) == wasDelivered.end()) {
        UniformReliableBroadcast::deliver(data, true);
        wasDelivered.insert(data.getMessageIdentifier());

        // && this->dependency_list.find(data.from_pid) != this->dependency_list.end()
        if(isInPast.find(data.getMessageIdentifier()) == isInPast.end()) {
          da::sockets::Data dataCopy(data);
          dataCopy.past = std::vector<da::sockets::Data>();
          past.push_back(dataCopy);
          isInPast.insert(data.getMessageIdentifier());
        }
      }
    }
  }
}