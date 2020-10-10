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
            protected:
                int current_pid;
                std::vector<Parser::Host> hosts;
                da::tools::Logger &logger;
                da::sockets::PerfectSocket &socket;

                std::unordered_map<std::string, da::sockets::Data*> pending; // package_unique_identifier: string
                std::unordered_map<std::string, int> ack; // <package_unique_identifier:string ; count:integer:
                std::mutex receive_mutex;
                std::mutex add_to_brodcast_mutex;
                void receive(da::sockets::Data &data);
            public:

                UniformReliableBroadcast(int current_pid, std::vector<Parser::Host> hosts, da::tools::Logger &logger, da::sockets::PerfectSocket &socket);

                void broadcast(da::sockets::Data &data);

                void receive_loop();

                virtual void deliver(da::sockets::Data &data, bool commitToLog);

                virtual bool canDeliver(da::sockets::Data &data);

        };
    } // namespace broadcast
} // namespace da

#endif