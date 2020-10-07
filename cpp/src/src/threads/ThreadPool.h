// Script inspired from:
// https://stackoverflow.com/questions/49439929/managing-threads-while-practicing-modern-c17s-best-practices
// !!!

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <thread>
#include <future>

#define NUM_THREADS 4000

namespace da
{
    namespace threads
    {

        class ThreadPool final
        {
        public:
            using Task = std::function<void()>;

        private:
            std::vector<std::thread> _threads;
            std::queue<Task> _tasks;

            std::condition_variable _event;
            std::mutex _eventMutex;
            bool _stopping = false;

            explicit ThreadPool(std::size_t numThreads)
            {
                start(numThreads);
            }

        public:
            static ThreadPool &getInstance()
            {
                static ThreadPool instance(NUM_THREADS);
                return instance;
            }

            ~ThreadPool()
            {
                stop();
            }

            ThreadPool(const ThreadPool &c) = delete;
            ThreadPool &operator=(const ThreadPool &c) = delete;

            template <class T>
            auto enqueue(T task) -> std::future<decltype(task())>
            {
                auto wrapper = std::make_shared<std::packaged_task<decltype(task())()>>(std::move(task));

                {
                    std::unique_lock<std::mutex> lock(_eventMutex);
                    _tasks.emplace([=] {
                        (*wrapper)();
                    });
                }

                _event.notify_one();
                return wrapper->get_future();
            }

        private:
            void start(std::size_t numThreads)
            {
                for (auto i = 0u; i < numThreads; ++i)
                {
                    _threads.emplace_back([=] {
                        while (true)
                        {
                            Task task;

                            {
                                std::unique_lock<std::mutex> lock{_eventMutex};
                                _event.wait(lock, [=] { return _stopping || !_tasks.empty(); });

                                if (_stopping && _tasks.empty())
                                    break;

                                task = std::move(_tasks.front());
                                _tasks.pop();
                            }

                            task();
                        }
                    });
                }
            }

            void stop() noexcept
            {
                {
                    std::unique_lock<std::mutex> lock{_eventMutex};
                    _stopping = true;
                }

                _event.notify_all();

                for (auto &thread : _threads)
                    thread.join();
            }
        };

    } // namespace threads
} // namespace da

#endif // THREAD_POOL_H