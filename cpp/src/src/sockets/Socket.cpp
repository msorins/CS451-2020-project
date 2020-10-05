#include <string>
#include "Socket.h"
#include <iostream>

namespace da
{
    namespace sockets
    {   
        Socket::Socket(std::string ip, int port): ip{ip}, port{port}
        {
        }
    } // namespace sockets
} // namespace da