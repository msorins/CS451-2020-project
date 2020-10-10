#include <iostream>
#include <string>
#include "Data.h"

namespace da
{
    namespace sockets
    {
        // Initialize static seq_number
        int da::sockets::Data::seq_number_static = 0;

        Data::Data(int from_pid, int data) : original_from_pid{from_pid}, from_pid{from_pid}, to_pid{-1}, data{data}
        {
            this->seq_number = da::sockets::Data::increaseSeqNumber();
        }

        Data::Data(int from_pid, int to_pid, int data) : original_from_pid{from_pid}, from_pid{from_pid}, to_pid{to_pid}, data{data}
        {
            this->seq_number = da::sockets::Data::increaseSeqNumber();
        }

        Data::Data(int seq_number, int from_pid, int to_pid, int data) : seq_number{seq_number}, original_from_pid{from_pid}, from_pid{from_pid}, to_pid{to_pid}, data{data}
        {
        }

        Data::Data(int seq_number, int original_from_pid, int from_pid, int to_pid, int data) : seq_number{seq_number}, original_from_pid{original_from_pid}, from_pid{from_pid}, to_pid{to_pid}, data{data}
        {
        }

        Data::Data(const Data &other) {
            this->seq_number = other.seq_number;
            this->from_pid = other.from_pid;
            this->original_from_pid = other.original_from_pid;
            this->to_pid = other.to_pid;
            this->data = other.data;
        }

        int Data::increaseSeqNumber()
        {
            // Return increased seq number
            return ++da::sockets::Data::seq_number_static;
        }

        std::string Data::getUniqueIdentifier() {
            return std::to_string(this->original_from_pid) + ":" + std::to_string(this->seq_number);
        }

        std::string Data::getMessageIdentifier() {
          return std::to_string(this->data);
        }

        std::ostream &operator<<(std::ostream &os, const Data &data)
        {
            os <<  "seq_nr: " << data.seq_number << ", from_pid: " << data.from_pid << ", original_from_pid:" << data.original_from_pid << ", to_pid: " << data.to_pid << ", data: " << data.data;
            return os;
        }
    } // namespace sockets
} // namespace da