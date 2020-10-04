#include <string>

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

        public:
            Socket(std::string ip, int port);
        };
    } // namespace sockets
} // namespace da

#endif // SOCKET