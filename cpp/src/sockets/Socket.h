#include <string>
#include "SocketType.h"

#ifndef SOCKET
#define SOCKET

namespace da
{
    namespace sockets
    {

        class Socket
        {
        protected:
            std::string ip;
            int port;
            SocketType socketType;

        public:
            Socket(std::string ip, int port, SocketType socketType);
        };
    } // namespace sockets
} // namespace da

#endif // SOCKET