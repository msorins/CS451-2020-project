#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include "Socket.h"

namespace da {
namespace sockets {

class UDPSocket: public Socket {
    private:
        int socket_file_descriptor;
        struct sockaddr_in socket_address;

    public:
        UDPSocket(std::string ip, int port);

        // Send String data over UDP channel
        void send(std::string data);

        // Receive data over UDP channel
        // All the data will be received in format <lengthOfString: uint32_t> <string>
        std::string receive();
};

}}