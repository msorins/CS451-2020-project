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
                    // Add packet to ack
                    if(this->ack.find(data.getUniqueIdentifier())   == this->ack.end()) {
                        this->ack[data.getUniqueIdentifier()] = 2; // 1 from the itself broadcast + 1 from the actual packet
                    } else {
                        this->ack[data.getUniqueIdentifier()] += 1;
                    }

                    // deliver if possible
                    if(this->canDeliver(data)) {
                        this->deliver(data);
                    }
                }
            });

            std::cout << "receive loop is done \n";
        }

        void UniformReliableBroadcast::deliver(da::sockets::Data &data)
        {
            std::cout << "urb deliver: " << data << "\n";
            if(this->pending.find(data.getUniqueIdentifier()) == this->pending.end()) {
                this->pending.insert(data.getUniqueIdentifier());
                this->broadcast(data);
            }
        }

        bool UniformReliableBroadcast::canDeliver(da::sockets::Data &data)
        {
            if(this->ack.find(data.getUniqueIdentifier()) == this->ack.end()) {
                return false;
            }
            return this->ack[data.getUniqueIdentifier()] >= static_cast<int>(this->hosts.size() / 2);
        }
    } // namespace broadcast
} // namespace da