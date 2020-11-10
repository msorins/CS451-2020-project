//
// Created by Sorin Sebastian Mircea on 10/10/2020.
//

#include "SendLoop.h"
#include "StubbornSocket.h"
#include "../threads/InfiniteThreadPool.h"
#include "unistd.h"

namespace da {
  namespace sockets {
    void SendLoop::start_loop() {
      auto &tp = da::threads::InfiniteThreadPool::getInstance();

      std::thread t1([&] {
        while(true) {
          auto datas = da::sockets::StubbornSocket::toSend;
          for(auto entry: da::sockets::StubbornSocket::toSend) {
            auto instance = *entry.second.first;
            auto data = *entry.second.second;
            instance.send(data);
          }
        }
      });

      tp.push_back(t1);
    }
  }
}