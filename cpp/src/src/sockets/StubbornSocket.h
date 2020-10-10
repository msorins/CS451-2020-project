#ifndef STUBBORN_SOCKET
#define STUBBORN_SOCKET

#include "Socket.h"
#include "FairLossSocket.h"
#include "SocketType.h"
#include <unordered_set>
#include <vector>
#include <unordered_map>
namespace da
{
    namespace sockets
    {
        class StubbornSocket : public FairLossSocket
        {
        public:
            StubbornSocket(std::string ip, int port, SocketType socketType);
            static std::unordered_map<std::string, std::pair<FairLossSocket*, Data*> > toSend;

            // Send data
            void send(Data data);

            virtual void deliver(Data &data);
        };

    } // namespace sockets
} // namespace da

#endif // STUBBORN_SOCKET