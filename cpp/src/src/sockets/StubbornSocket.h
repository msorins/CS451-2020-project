#ifndef STUBBORN_SOCKET
#define STUBBORN_SOCKET

#include "Socket.h"
#include "FairLossSocket.h"

namespace da
{
    namespace sockets
    {
        class StubbornSocket : public FairLossSocket
        {
        public:
            StubbornSocket(std::string ip, int port);

            // Send String data over UDP channel
            void send(Data data);
        };

    } // namespace sockets
} // namespace da

#endif // STUBBORN_SOCKET