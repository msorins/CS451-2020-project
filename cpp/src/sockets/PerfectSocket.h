#include <unordered_set>
#include <string>
#ifndef PERFECT_SOCKET
#define PERFECT_SOCKET

#include "Socket.h"
#include "StubbornSocket.h"
#include "SocketType.h"

namespace da
{
    namespace sockets
    {
        class PerfectSocket : public StubbornSocket
        {
        private:
            std::unordered_set<std::string> wasDelivered;

        public:
            PerfectSocket(std::string ip, int port, SocketType socketType);
            Data receive();
            virtual void deliver(Data &data);
        };

    } // namespace sockets
} // namespace da

#endif // PERFECT_SOCKET