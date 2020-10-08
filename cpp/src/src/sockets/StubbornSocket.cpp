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
            int max_tries = 100;
            int tries = 0;

            while (true)
            {
                // Force exit
                if(da::tools::AppStatus::isRunning == false) {
                  break;
                }

                FairLossSocket::send(data);
                usleep(200000);
                tries += 1;
                if(tries >= max_tries) {
                  return;
                }
            }
        }

    } // namespace sockets
} // namespace da