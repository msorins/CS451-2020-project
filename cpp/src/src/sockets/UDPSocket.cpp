#include "UDPSocket.h"
#include "Socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>

namespace da {
namespace sockets {
    UDPSocket::UDPSocket(std::string ip, int port): Socket(ip, port) {
        this->socket_file_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
        if(this->socket_file_descriptor == -1) {
            perror("Cannot open the socket");
            exit(-1);
        }

        this->socket_address.sin_family = AF_INET;
        this->socket_address.sin_addr.s_addr = inet_addr(ip.c_str());
        this->socket_address.sin_port = htons(port);
    }

    void UDPSocket::send(std::string data) {
        std::cout << "sending <" << data << "> to " << this->ip << ":" << std::to_string(this->port) << "\n";
        
        // send the length
        uint32_t len = htons(data.length());
        sendto(this->socket_file_descriptor, static_cast<void*>(&len), sizeof(len), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), sizeof (this->socket_address));

        // send the actual string
        // char dataChar{data.c_str()}

        // /sendto(this->socket_file_descriptor, (int*)&link, sizeof(link), 0, (struct sockaddr *) &server, sizeof (server));
    }

    std::string UDPSocket::receive() {
        std::cout << "receiving data on " << this->ip << ":" << std::to_string(this->port) << "\n";
        auto i = bind (this->socket_file_descriptor, reinterpret_cast<struct sockaddr *>(&socket_address), sizeof (socket_address));
        if(i == -1) {
            perror("cannot bind");
            exit(-1);
        }

        uint32_t len_received_net;
        socklen_t socket_addr_sizeof = sizeof(this->socket_address);
        recvfrom(this->socket_file_descriptor, &len_received_net, sizeof(len_received_net), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), &socket_addr_sizeof);
        
        int len_received = ntohs(len_received_net);
        return "the value received was: " + std::to_string(len_received);
    }
}
}