#include "Socket.h"
#include "FairLossSocket.h"
#include "StubbornSocket.h"
#include <iostream>

namespace da
{
    namespace sockets
    {

        StubbornSocket::StubbornSocket(std::string ip, int port) : FairLossSocket(ip, port)
        {
        }

        void StubbornSocket::send(std::string data)
        {
            while (true)
            {
                FairLossSocket::send(data);
            }
        }

    } // namespace sockets
} // namespace da