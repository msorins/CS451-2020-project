#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>

#ifndef FAIR_LOSS_SOCKET
#define FAIR_LOSS_SOCKET

#include "Socket.h"
#include "Data.h"
#include "SocketType.h"

namespace da
{
    namespace sockets
    {

        class FairLossSocket : public Socket
        {
        private:
            int socket_file_descriptor;
            struct sockaddr_in socket_address;

        public:
            FairLossSocket(std::string ip, int port, SocketType socketType);

            // Send String data over UDP channel
            void send(Data data);

            // Receive data over UDP channel
            // All the data will be received in format <lengthOfString: uint32_t> <string>
            Data receive();
        };

    } // namespace sockets
} // namespace da

#endif // FAIR_LOSS_SOCKET