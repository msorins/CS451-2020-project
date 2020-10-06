#include <string>
#include "Socket.h"
#include <iostream>

namespace da
{
    namespace sockets
    {   
        Socket::Socket(std::string ip, int port, SocketType socketType): ip{ip}, port{port}, socketType{socketType}
        {
        }
    } // namespace sockets
} // namespace da