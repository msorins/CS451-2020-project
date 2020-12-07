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
        FairLossSocket::FairLossSocket(std::string ip, int port, SocketType socketType) : Socket(ip, port, socketType)
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
            int optval = 1;
            setsockopt(this->socket_file_descriptor, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));

            if(socketType == da::sockets::SocketType::RECEIVE) {
                auto i = bind(this->socket_file_descriptor, reinterpret_cast<struct sockaddr *>(&socket_address), sizeof(socket_address));
                if (i == -1)
                {
                    perror("cannot bind");
                    exit(-1);
                }
            }
        }

        void FairLossSocket::send(Data data)
        {
            // form the data that must be sent
            std::vector<int> data_to_send = {data.seq_number, data.original_from_pid, data.from_pid, data.to_pid, data.data};

            // form the past vector
            for(auto elem: data.past) {
              data_to_send.push_back(elem.seq_number);
              data_to_send.push_back(elem.original_from_pid);
              data_to_send.push_back(elem.from_pid);
              data_to_send.push_back(elem.to_pid);
              data_to_send.push_back(elem.data);
            }

            // add as the first int the size of the data to be send
            data_to_send.insert(data_to_send.begin(), static_cast<int>(data_to_send.size()));

            // send the actual data
            int* data_pointer = &data_to_send[0];
           sendto(this->socket_file_descriptor, data_pointer, sizeof(int) * static_cast<int>(data_to_send.size()), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), sizeof(this->socket_address));
        }

        Data FairLossSocket::receive()
        {
            socklen_t socket_addr_sizeof = sizeof(this->socket_address);
           
            // get data size
            int data_size = -1;
            if (recvfrom(this->socket_file_descriptor, &data_size, sizeof(data_size), MSG_PEEK, reinterpret_cast<struct sockaddr *>(&this->socket_address), &socket_addr_sizeof) < 0)
            {
                perror("cannot receive 3");
                exit(-1);
            }

            // get the actual data of data_size
            std::vector<int> data(data_size + 1);
            int* data_pointer = &data[0];
            if (recvfrom(this->socket_file_descriptor, data_pointer, sizeof(int) * static_cast<int>(data.size()), 0, reinterpret_cast<struct sockaddr *>(&this->socket_address), &socket_addr_sizeof) < 0)
            {
                perror("cannot receive 2");
                exit(-1);
            }

            // Put the data received into the appropiate structure
            Data formatted_data(data[1], data[2], data[3], data[4], data[5]);

            // Put the delivered
            for(int i = 6; i< static_cast<int>(data.size()); i += 5 ) {
                Data pastData(data[i], data[i+1], data[i+2], data[i+3], data[i+4]);
                if(pastData.seq_number == 0) {
                    continue;
                }
                formatted_data.past.push_back(pastData);
            }

            return formatted_data;
        }

        void FairLossSocket::deliver(Data &data) {
        }

    } // namespace sockets
} // namespace da