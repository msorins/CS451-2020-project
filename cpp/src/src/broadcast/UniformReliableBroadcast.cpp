#include "UniformReliableBroadcast.h"
#include "../sockets/PerfectSocket.h"
#include "../threads/ThreadPool.h"
#include "../tools/AppStatus.h"

namespace da
{
    namespace broadcast
    {
        UniformReliableBroadcast::UniformReliableBroadcast(std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket) : hosts{hosts}, logger{logger}, socket{socket}
        {
        }

        void UniformReliableBroadcast::broadcast(da::sockets::Data &data)
        {
            this->pending[data.getUniqueIdentifier()] = new da::sockets::Data(data);

            // Create a thread pool with enough threads for each host (as this is never ending)
            auto &tp = da::threads::ThreadPool::getInstance();
            for (const auto &host: this->hosts)
            {
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
                this->deliver(data, true);
            }
            this->mtx.unlock();
        }

        void UniformReliableBroadcast::receive_loop()
        {
            auto &tp = da::threads::ThreadPool::getInstance();
            tp.enqueue([&]() noexcept {
                while (true)
                {
                    // force exit condition
                    if(da::tools::AppStatus::isRunning == false) {
                      break;
                    }

                    da::sockets::Data data = this->socket.receive();
                    this->receive(data);
                }
            });

            std::cout << "receive loop is done \n";
        }

        void UniformReliableBroadcast::deliver(da::sockets::Data &data, bool commitToLog)
        {
            if(commitToLog) {
              this->logger.writeDeliver(data.from_pid, data.seq_number);
            }
            if(this->pending.find(data.getUniqueIdentifier()) == this->pending.end()) {
                this->pending[data.getUniqueIdentifier()] = new da::sockets::Data(data);
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