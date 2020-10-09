#ifndef STUBBORN_SOCKET
#define STUBBORN_SOCKET

#include "Socket.h"
#include "FairLossSocket.h"
#include "SocketType.h"
#include <unordered_set>

namespace da
{
    namespace sockets
    {
        class StubbornSocket : public FairLossSocket
        {
        public:
            StubbornSocket(std::string ip, int port, SocketType socketType);

            // Send data
            void send(Data data);

            virtual void deliver(Data &data);
        };

    } // namespace sockets
} // namespace da

#endif // STUBBORN_SOCKET