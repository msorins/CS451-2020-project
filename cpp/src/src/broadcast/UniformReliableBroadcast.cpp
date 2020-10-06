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

        void UniformReliableBroadcast::broadcast(da::sockets::Data data)
        {
            this->pending.insert(data.getUniqueIdentifier());

            // Create a thread pool with enough threads for each host (as this is never ending)
            da::threads::ThreadPool tp(this->hosts.size());
            for (auto &host : this->hosts)
            {
                // Send the message in a thread pool
                tp.enqueue([&]() noexcept {
                     da::sockets::PerfectSocket socket(host.ipReadable(), host.portReadable());
                    socket.send(data);
                });
            }
        }

        void UniformReliableBroadcast::receive_loop()
        {
        }

        void UniformReliableBroadcast::deliver(da::sockets::Data data)
        {
        }

        bool UniformReliableBroadcast::canDeliver(da::sockets::Data m)
        {
            return false;
        }
    } // namespace broadcast
} // namespace da