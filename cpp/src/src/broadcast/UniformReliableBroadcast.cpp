#include "UniformReliableBroadcast.h"

namespace da
{
    namespace broadcast
    {
        UniformReliableBroadcast::UniformReliableBroadcast(std::vector<Parser::Host> hosts) {

        }

        void UniformReliableBroadcast::broadcast(da::sockets::Data data) {
            this->pending.insert(data.getUniqueIdentifier());

        }

        void UniformReliableBroadcast::receive_loop() {
            
        }

        void UniformReliableBroadcast::deliver(da::sockets::Data data) {

        }

        bool UniformReliableBroadcast::canDeliver(da::sockets::Data m) {
            return false;
        }
    } // namespace broadcast
} // namespace da