#include "UniformReliableBroadcast.h"
#include "../sockets/PerfectSocket.h"
#include "../threads/InfiniteThreadPool.h"
#include "../tools/AppStatus.h"
#include <thread>
namespace da
{
    namespace broadcast
    {
        UniformReliableBroadcast::UniformReliableBroadcast(int current_pid, std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket) : current_pid{current_pid}, hosts{hosts}, logger{logger}, socket{socket}
        {
        }

        void UniformReliableBroadcast::broadcast(da::sockets::Data &data)
        {
            // Run everything in a mutex
            this->add_to_brodcast_mutex.lock();

            // Modify the data to have the from_pid as current pid
            da::sockets::Data *newData = new da::sockets::Data(data);
            newData->from_pid = this->current_pid;

            // Add it to pending
            this->pending[newData->getUniqueIdentifier()] = newData;

            // Iterate through all hosts and send it
            for (const auto &host: this->hosts)
            {
                // Send the message in a thread pool
                da::sockets::PerfectSocket socket(host.ipReadable(), host.portReadable(), da::sockets::SocketType::SEND);
                socket.send(*newData);
            }

            // Close the Mutex
            this->add_to_brodcast_mutex.unlock();
        }

        void UniformReliableBroadcast::receive(da::sockets::Data &data)
        {
            // Skip empty data
            if(data.from_pid == -1) {
              return;
            }

            // Add packet to ack
            if(this->ack.find(data.getMessageIdentifier())   == this->ack.end()) {
                this->ack[data.getMessageIdentifier()] = 1; // 1 from the actual packet
            } else {
                this->ack[data.getMessageIdentifier()] += 1;
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
            std::cout << "urb deliver: " << data << " ";
            // Commit the delivery to log
            if(commitToLog) {
              this->logger.writeDeliver(data.from_pid, data.seq_number);
            }

            // Mark the message as delivered in the socket
            this->socket.deliver(data);

            // Add to pending if doesn't exist and broadcast
            if(this->pending.find(data.getUniqueIdentifier()) == this->pending.end()) {
                this->pending[data.getUniqueIdentifier()] = new da::sockets::Data(data);
                std::cout<< ", add to pending ";
                this->broadcast(data);
            }
            std::cout << "\n";

            std::cout << "pending: ";
            for(auto elem: this->pending) {
              std::cout << elem.first << ", ";
            }
            std::cout << "\n";
        }

        bool UniformReliableBroadcast::canDeliver(da::sockets::Data &data)
        {
           std::cout << "("<< this->ack[data.getMessageIdentifier()] <<" out of "<< static_cast<int>(this->hosts.size() / 2) << ")" << "can deliver data: " << data.getMessageIdentifier() << ", data: " << data << ", ack " << ack[data.getMessageIdentifier()] << " ";
            if(this->ack.find(data.getMessageIdentifier()) == this->ack.end()) {
                std::cout << "false \n";
                return false;
            }
            std::cout << "\n";
            return this->ack[data.getMessageIdentifier()] >= static_cast<int>(this->hosts.size() / 2);
        }
    } // namespace broadcast
} // namespace da