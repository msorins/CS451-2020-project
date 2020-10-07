#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "../sockets/Data.h"
#include "../sockets/PerfectSocket.h"
#include "../threads/ThreadPool.h"
#include "../sockets/SocketType.h"
#include "../tools/Logger.h"
#include "parser.hpp"
#include <mutex>
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
                da::tools::Logger &logger;
                da::sockets::PerfectSocket &socket;

                std::unordered_set<std::string> pending; // package_unique_identifier: string
                std::unordered_map<std::string, int> ack; // <package_unique_identifier:string ; count:integer:
                std::unordered_map<std::string, const da::sockets::Data&> packets; // will contain all the packets
                std::mutex mtx;
                void receive(da::sockets::Data &data);
            public:

                UniformReliableBroadcast(std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket);

                void broadcast(da::sockets::Data &data);

                void receive_loop();

                void deliver(da::sockets::Data &data);

                bool canDeliver(da::sockets::Data &data);

        };
    } // namespace broadcast
} // namespace da

#endif