#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "../sockets/Data.h"
#include "parser.hpp"

#ifndef UNIFORM_RELIABLE_BROADCAST
#define UNIFORM_RELIABLE_BROADCAST

namespace da
{
    namespace broadcast
    {
        class UniformReliableBroadcast
        {
            private:
                std::vector<Parser::Host> hosts;

                std::unordered_set<std::string> delivered;
                std::unordered_set<std::string> pending;
                std::unordered_set<std::string> ack;
                std::unordered_map<std::string, da::sockets::Data> packets; // will contain all the packets 

            public:

                UniformReliableBroadcast(std::vector<Parser::Host> hosts);

                void broadcast(da::sockets::Data data);

                void receive_loop();

                void deliver(da::sockets::Data data);

                bool canDeliver(da::sockets::Data m);

        };
    } // namespace broadcast
} // namespace da

#endif