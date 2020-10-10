#include "UniformReliableBroadcast.h"
#include "../sockets/PerfectSocket.h"
#include "../threads/InfiniteThreadPool.h"
#include "../tools/AppStatus.h"
#include <thread>
namespace da
{
    namespace broadcast
    {
        UniformReliableBroadcast::UniformReliableBroadcast(std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket) : hosts{hosts}, logger{logger}, socket{socket}
        {
        }

        void UniformReliableBroadcast::broadcast(da::sockets::Data &data)
        {
            this->add_to_brodcast_mutex.lock();
            this->pending[data.getUniqueIdentifier()] = new da::sockets::Data(data);

            // Create a thread pool with enough threads for each host (as this is never ending)
            auto &tp = da::threads::InfiniteThreadPool::getInstance();
            for (const auto &host: this->hosts)
            {
                // Send the message in a thread pool
                da::sockets::PerfectSocket socket(host.ipReadable(), host.portReadable(), da::sockets::SocketType::SEND);
                socket.send(data);
            }
            this->add_to_brodcast_mutex.unlock();
        }

        void UniformReliableBroadcast::receive(da::sockets::Data &data)
        {
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
        }

        void UniformReliableBroadcast::receive_loop()
        {
            auto &tp = da::threads::InfiniteThreadPool::getInstance();
            std:: thread t1([&]() noexcept {
                while (true)
                {
                    this->receive_mutex.lock();
                    // force exit condition
                    if(da::tools::AppStatus::isRunning == false) {
                      break;
                    }

                    da::sockets::Data data = this->socket.receive();
                    this->receive(data);
                    this->receive_mutex.unlock();
                }
            });
            tp.push_back(t1);

            std::cout << "receive loop is done \n";
        }

        void UniformReliableBroadcast::deliver(da::sockets::Data &data, bool commitToLog)
        {
            // Commit the delivery to log
            if(commitToLog) {
              this->logger.writeDeliver(data.from_pid, data.seq_number);
            }

            // Mark the message as delivered in the socket
            this->socket.deliver(data);

            // Add to pending if doesn't exist and broadcast
            if(this->pending.find(data.getUniqueIdentifier()) == this->pending.end()) {
                this->pending[data.getUniqueIdentifier()] = new da::sockets::Data(data);
                this->broadcast(data);
            }
        }

        bool UniformReliableBroadcast::canDeliver(da::sockets::Data &data)
        {
            if(this->ack.find(data.getUniqueIdentifier()) == this->ack.end()) {
                std::cout << "(0)" << "can deliver uid: " << data.getUniqueIdentifier() << ", data: " << data << ":: " << ack[data.getUniqueIdentifier()] << "\n";
                return false;
            }
            std::cout << "("<< this->ack[data.getUniqueIdentifier()] <<" out of "<< static_cast<int>(this->hosts.size() / 2) << ")" << "can deliver uid: " << data.getUniqueIdentifier() << ", data: " << data << ":: " << ack[data.getUniqueIdentifier()] << "\n";
            return this->ack[data.getUniqueIdentifier()] >= static_cast<int>(this->hosts.size() / 2);
        }
    } // namespace broadcast
} // namespace da