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
//          std::cout << "to send: " << da::sockets::StubbornSocket::toSend.size() << ": ";

          for(auto entry: da::sockets::StubbornSocket::toSend) {
//            std::cout << entry.second.second->getUniqueIdentifier() << " ";
            // if message was delivered, stop infinite sending that message
            if(logger.delivered.find(entry.second.second->getUniqueIdentifier()) != logger.delivered.end()) {
//              da::sockets::StubbornSocket::toSend.erase(entry.first);
              break;
            }
            // send the message
            auto instance = *entry.second.first;
            auto data = *entry.second.second;
            instance.send(data);
          }

          std::cout << "\n";
        }
      });

      tp.push_back(t1);
    }

  SendLoop::SendLoop(tools::Logger &logger) : logger(logger) {}
  }
}