#include "FairLossSocket.h"
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
#include <string>

namespace da
{
    namespace sockets
    {
        FairLossSocket::FairLossSocket(std::string ip, int port) : Socket(ip, port)
        {
            this->socket_file_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
            if (this->socket_file_descriptor == -1)
            {
                perror("Cannot open the socket");
                exit(-1);
            }

            this->socket_address.sin_family = AF_INET;
            this->socket_address.sin_addr.s_addr = inet_addr(ip.c_str());
            this->socket_address.sin_port = htons(port);
        }

        void FairLossSocket::send(std::string data)
        {
            std::cout << "sending <" << data << "> to " << this->ip << ":" << std::to_string(this->port) << "\n";

            // send the length
            uint32_t len = htons(data.length());
            sendto(this->socket_file_descriptor, static_cast<void *>(&len), sizeof(len), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), sizeof(this->socket_address));

            // send the actual string
            sendto(this->socket_file_descriptor, data.c_str(), data.length(), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), sizeof(this->socket_address));
        }

        std::string FairLossSocket::receive()
        {
            std::cout << "receiving data on " << this->ip << ":" << std::to_string(this->port) << "\n";
            auto i = bind(this->socket_file_descriptor, reinterpret_cast<struct sockaddr *>(&socket_address), sizeof(socket_address));
            if (i == -1)
            {
                perror("cannot bind");
                exit(-1);
            }

            // receive the length
            uint32_t len_received_net;
            socklen_t socket_addr_sizeof = sizeof(this->socket_address);
            if (recvfrom(this->socket_file_descriptor, &len_received_net, sizeof(len_received_net), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), &socket_addr_sizeof) < 0)
            {
                perror("cannot receive 1");
                exit(-1);
            }
            int len_received = ntohs(len_received_net);

            // receive the string
            std::cout << "received data of length: " << len_received << "\n";
            char *recvbuf = new char[len_received + 3];
            if (recvfrom(this->socket_file_descriptor, recvbuf, len_received, 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), &socket_addr_sizeof) < 0)
            {
                perror("cannot receive 2");
                exit(-1);
            }
            recvbuf[len_received] = '\0';
            std::cout << "string received is: " << recvbuf << "\n";
            std::string received(recvbuf);
            return received;
        }
    } // namespace sockets
} // namespace da