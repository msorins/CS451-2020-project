#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
            int original_from_pid;
            int from_pid;
            int to_pid;
            int data;
            std::vector<std::pair<int, int>> delivered; // [from_pid, data]

            Data();
            Data(int from_pid, int data);
            Data(int from_pid, int to_pid, int data);
            Data(int seq_number, int from_pid, int to_pid, int data);
            Data(int seq_number, int original_from_pid, int from_pid, int to_pid, int data);
            Data(const Data &other);

            static int increaseSeqNumber();

            std::string getUniqueIdentifier();
            std::string getMessageIdentifier();

            friend std::ostream& operator<<(std::ostream& os, const Data& data);
        };
    } // namespace sockets
} // namespace da

#endif // DATA