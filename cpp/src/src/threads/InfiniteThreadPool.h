#include <vector>
#include <thread>

namespace da {
  namespace threads {
    class InfiniteThreadPool {
    private:
      static InfiniteThreadPool instance;
      std::vector<std::thread> threads;

    public:
      static InfiniteThreadPool &getInstance()
      {
        return InfiniteThreadPool::instance;
      }

      void push_back(std::thread &thread);

      void join();
    };
  }
}