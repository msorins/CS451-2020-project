#include "Socket.h"
#include "FairLossSocket.h"
#include "StubbornSocket.h"
#include "PerfectSocket.h"
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
                // First Receive data from stubborn socket
                auto data = StubbornSocket::receive();
                auto unique_packet_identifier = data.getUniqueIdentifier();

                // If the data was not found
                if (this->wasDelivered.find(unique_packet_identifier) == this->wasDelivered.end())
                {
                    // mark it as found
                    this->wasDelivered.insert(unique_packet_identifier);
//                    std::cout << "perfect link receiving <" << data << "> on " << this->ip << ":" << std::to_string(this->port) << "\n";
                    return data;
                }
            }

        }

    } // namespace sockets
} // namespace da