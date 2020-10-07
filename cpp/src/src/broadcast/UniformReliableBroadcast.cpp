#include "UniformReliableBroadcast.h"
#include "../sockets/PerfectSocket.h"
#include "../threads/ThreadPool.h"

namespace da
{
    namespace broadcast
    {
        UniformReliableBroadcast::UniformReliableBroadcast(std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket) : hosts{hosts}, logger{logger}, socket{socket}
        {
        }

        void UniformReliableBroadcast::broadcast(da::sockets::Data &data)
        {
            this->pending.insert(data.getUniqueIdentifier());

            // Create a thread pool with enough threads for each host (as this is never ending)
            auto &tp = da::threads::ThreadPool::getInstance();
            for (const auto &host: this->hosts)
            {
                std::string logMsg = "b " + std::to_string(data.seq_number) + "\n";
                std::cout << "b " << " " << data  << ":" << host.portReadable() << "\n";
                this->logger.write(logMsg);

                // Send the message in a thread pool
                tp.enqueue([data, &host]() noexcept {
                    da::sockets::PerfectSocket socket(host.ipReadable(), host.portReadable(), da::sockets::SocketType::SEND);
                    socket.send(data);
                });
            }
        }

        void UniformReliableBroadcast::receive(da::sockets::Data &data)
        {
            this->mtx.lock();
            // Add packet to ack
            if(this->ack.find(data.getUniqueIdentifier())   == this->ack.end()) {
                this->ack[data.getUniqueIdentifier()] = 1; // 1 from the actual packet
            } else {
                this->ack[data.getUniqueIdentifier()] += 1;
            }

            // deliver if possible
            if(this->canDeliver(data)) {
                this->deliver(data);
            }
            this->mtx.unlock();
        }

        void UniformReliableBroadcast::receive_loop()
        {
            auto &tp = da::threads::ThreadPool::getInstance();
            tp.enqueue([&]() noexcept {
                while (true)
                {
                    da::sockets::Data data = this->socket.receive();
                    this->receive(data);
                }
            });

            std::cout << "receive loop is done \n";
        }

        void UniformReliableBroadcast::deliver(da::sockets::Data &data)
        {
            std::string logMsg = "d " + std::to_string(data.seq_number) + " " + std::to_string(data.from_pid) + "\n";
            this->logger.write(logMsg);
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