//
// Created by Sorin Sebastian Mircea on 10/10/2020.
//

#ifndef SRC_SENDLOOP_H
#define SRC_SENDLOOP_H

#include "FairLossSocket.h"
#include "../tools/Logger.h"

namespace da {
  namespace sockets {
    class SendLoop{
     private:
      da::tools::Logger &logger;

     public:
      SendLoop(tools::Logger &logger);
      void start_loop();

    };
  }
}



#endif //SRC_SENDLOOP_H
