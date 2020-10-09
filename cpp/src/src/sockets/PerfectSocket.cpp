#include "Socket.h"
#include "FairLossSocket.h"
#include "StubbornSocket.h"
#include "PerfectSocket.h"
#include "../tools/AppStatus.h"
#include <iostream>
#include <unistd.h>
#include <unordered_set>
#include <string>

namespace da
{
    namespace sockets
    {

        PerfectSocket::PerfectSocket(std::string ip, int port, SocketType socketType) : StubbornSocket(ip, port, socketType)
        {
        }

        Data PerfectSocket::receive()
        {
            // Discard all already received packages until a new one is received
            while (true)
            {
                // Force exit condition
                if(da::tools::AppStatus::isRunning == false) {
                  return da::sockets::Data(-1, -1);
                }

                // First Receive data from stubborn socket
                auto data = StubbornSocket::receive();
                auto unique_packet_identifier = data.getUniqueIdentifier();

                // If the data was not found
                if (this->wasDelivered.find(unique_packet_identifier) == this->wasDelivered.end())
                {
                  // return
                  return data;
                }
            }
        }


        void PerfectSocket::deliver(Data &data) {
          StubbornSocket::deliver(data);

          auto unique_packet_identifier = data.getUniqueIdentifier();
          this->wasDelivered.insert(unique_packet_identifier);
        }

    } // namespace sockets
} // namespace da