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
#include <vector>

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

        void FairLossSocket::send(Data data)
        {
            std::cout << "sending <" << data.data << "> to " << this->ip << ":" << std::to_string(this->port) << "\n";

            // send the data
            int data_to_send[] = {data.seq_number, data.from_pid, data.to_pid, data.data};
            sendto(this->socket_file_descriptor, &data_to_send, sizeof(data_to_send), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), sizeof(this->socket_address));
        }

        Data FairLossSocket::receive()
        {
            std::cout << "receiving data on " << this->ip << ":" << std::to_string(this->port) << "\n";
            auto i = bind(this->socket_file_descriptor, reinterpret_cast<struct sockaddr *>(&socket_address), sizeof(socket_address));
            if (i == -1)
            {
                perror("cannot bind");
                exit(-1);
            }

            // receive the data
            socklen_t socket_addr_sizeof = sizeof(this->socket_address);
            int data[4];
            if (recvfrom(this->socket_file_descriptor, &data, sizeof(data), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), &socket_addr_sizeof) < 0)
            {
                perror("cannot receive 2");
                exit(-1);
            }

            // Put the data received into the appropiate structure
            Data formatted_data(data[0], data[1], data[2], data[3]);
            return formatted_data;
        }
    } // namespace sockets
} // namespace da