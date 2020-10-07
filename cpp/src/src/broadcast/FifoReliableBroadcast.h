//
// Created by Sorin Sebastian Mircea on 07/10/2020.
//

#ifndef SRC_FIFORELIABLEBROADCAST_H
#define SRC_FIFORELIABLEBROADCAST_H

#include <vector>
#include "UniformReliableBroadcast.h"

namespace da {
  namespace broadcast {
  class FifoReliableBroadcast: public UniformReliableBroadcast {
  protected:
      std::vector<int> next;

  public:
      FifoReliableBroadcast(std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket);

      virtual void deliver(da::sockets::Data &data, bool commitToLog = true);
  };


} }


#endif //SRC_FIFORELIABLEBROADCAST_H
