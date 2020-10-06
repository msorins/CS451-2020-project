#include "UniformReliableBroadcast.h"
#include "../sockets/PerfectSocket.h"
#include "../threads/ThreadPool.h"

namespace da
{
    namespace broadcast
    {
        UniformReliableBroadcast::UniformReliableBroadcast(std::vector<Parser::Host> hosts) : hosts{hosts}
        {
        }

        void UniformReliableBroadcast::broadcast(da::sockets::Data &data)
        {
            this->pending.insert(data.getUniqueIdentifier());

            // Create a thread pool with enough threads for each host (as this is never ending)
            auto &tp = da::threads::ThreadPool::getInstance();
            for (const auto &host: this->hosts)
            {
                // Skip sending to myself
                if(static_cast<int>(host.id) == data.from_pid) {
                    continue;
                }


                // Send the message in a thread pool
                tp.enqueue([data, &host]() noexcept {
                    da::sockets::PerfectSocket socket(host.ipReadable(), host.portReadable(), da::sockets::SocketType::SEND);
                    socket.send(data);
                });
            }
        }

        da::sockets::Data UniformReliableBroadcast::receive(da::sockets::PerfectSocket &socket)
        {
            return socket.receive();
        }

        void UniformReliableBroadcast::receive_loop(da::sockets::PerfectSocket &socket)
        {
            auto &tp = da::threads::ThreadPool::getInstance();
            tp.enqueue([&]() noexcept {
                while (true)
                {
                    da::sockets::Data data = this->receive(socket);
                }
            });

            std::cout << "receive loop is done \n";
        }

        void UniformReliableBroadcast::deliver(da::sockets::Data &data)
        {
        }

        bool UniformReliableBroadcast::canDeliver(da::sockets::Data &m)
        {
            return false;
        }
    } // namespace broadcast
} // namespace da