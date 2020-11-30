//
// Created by Sorin Sebastian Mircea on 09/10/2020.
//

#include "InfiniteThreadPool.h"

namespace da {
  namespace threads {
    InfiniteThreadPool InfiniteThreadPool::instance = InfiniteThreadPool() ;

    void InfiniteThreadPool::push_back(std::thread &thread) {
      this->threads.push_back(std::move(thread));
    }

    void InfiniteThreadPool::join() {
      for(auto &thread: this->threads) {
        thread.join();
      }
    }

    int InfiniteThreadPool::size() {
      return static_cast<int>(this->threads.size());
    }
  }
}