#include <iostream>
#include <string>

#ifndef DATA
#define DATA

namespace da
{
    namespace sockets
    {
        class Data
        {
        private:
            // Initialize static seq_number
            static int seq_number_static;

        public:
            int seq_number;
            int from_pid;
            int to_pid;
            int data;

            Data(int from_pid, int data);
            Data(int from_pid, int to_pid, int data);
            Data(int seq_number, int from_pid, int to_pid, int data);

            static int increaseSeqNumber();

            std::string getUniqueIdentifier();

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };
    } // namespace sockets
} // namespace da

#endif // DATA