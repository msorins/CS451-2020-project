//
// Created by Sorin Sebastian Mircea on 07/10/2020.
//

#ifndef SRC_CAUSALUNIFORMBROADCAST_H
#define SRC_CAUSALUNIFORMBROADCAST_H

#include <vector>
#include <unordered_set>
#include "UniformReliableBroadcast.h"
#include "../sockets/Data.h"

namespace da {
  namespace broadcast {
  class CausalUniformBroadcast: public UniformReliableBroadcast {
  protected:
      std::vector<int> next;
      std::unordered_set<int> dependency_list;
      std::unordered_set<std::string> wasDelivered;

      std::vector<std::pair<int,int>> past; // <source, data>
      std::unordered_set<std::string> isInPast;

  public:
      CausalUniformBroadcast(int current_pid, std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket, std::unordered_set<int> &dependency_list);

      virtual void broadcast(da::sockets::Data &data);
      virtual void deliver(da::sockets::Data &data, bool commitToLog = true);
  };


} }


#endif //SRC_CAUSALUNIFORMBROADCAST_H  
