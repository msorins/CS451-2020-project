#include "Socket.h"
#include "FairLossSocket.h"
#include "StubbornSocket.h"
#include "../sockets/Data.h"
#include "../tools/AppStatus.h"
#include <algorithm>
#include <iostream>
#include <utility>
namespace da
{
    namespace sockets
    {
        StubbornSocket::StubbornSocket(std::string ip, int port, SocketType socketType) : FairLossSocket(ip, port, socketType)
        {
        }
      std::unordered_map<std::string, std::pair<FairLossSocket*, Data*> > StubbornSocket::toSend = std::unordered_map<std::string, std::pair<FairLossSocket*, Data*> >();

        void StubbornSocket::send(Data data)
        {
            // A thread inifnitely sends the data
            da::sockets::Data *newData = new da::sockets::Data(data);
            if(StubbornSocket::toSend.find(std::to_string(this->port) + ":" + data.getMessageIdentifier()) == StubbornSocket::toSend.end()) {
              std::cout<<"stubborn adding to send loop: " << data << " on port: " << this->port << "; copy: " << newData << "\n";
              StubbornSocket::toSend[std::to_string(this->port) + ":" + data.getMessageIdentifier()] = std::make_pair(new FairLossSocket(this->ip, this->port, this->socketType), newData);
            }
        }

        void StubbornSocket::deliver(Data &data) {
          FairLossSocket::deliver(data);
        }

    } // namespace sockets
} // namespace da