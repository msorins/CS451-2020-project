#ifndef STUBBORN_SOCKET
#define STUBBORN_SOCKET

#include "Socket.h"
#include "FairLossSocket.h"
#include <unordered_set>
namespace da
{
    namespace sockets
    {
        class StubbornSocket : public FairLossSocket
        {
        public:
            StubbornSocket(std::string ip, int port);

            // Send data
            void send(Data data);
        };

    } // namespace sockets
} // namespace da

#endif // STUBBORN_SOCKET