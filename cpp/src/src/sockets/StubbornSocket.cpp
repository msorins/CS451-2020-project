#include "Socket.h"
#include "FairLossSocket.h"
#include "StubbornSocket.h"
#include <iostream>
#include <unistd.h>
namespace da
{
    namespace sockets
    {

        StubbornSocket::StubbornSocket(std::string ip, int port, SocketType socketType) : FairLossSocket(ip, port, socketType)
        {
        }

        void StubbornSocket::send(Data data)
        {
            while (true)
            {
                FairLossSocket::send(data);
                usleep(50000);
            }
        }

    } // namespace sockets
} // namespace da