#include "Socket.h"
#include "FairLossSocket.h"
#include "StubbornSocket.h"
#include "../tools/AppStatus.h"
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
                // Force exit
                if(da::tools::AppStatus::isRunning == false) {
                  break;
                }

                FairLossSocket::send(data);
                usleep(200000);
            }
        }

        void StubbornSocket::deliver(Data &data) {
          FairLossSocket::deliver(data);
        }

    } // namespace sockets
} // namespace da