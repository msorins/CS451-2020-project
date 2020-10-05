#include <iostream>
#include "Data.h"

namespace da
{
    namespace sockets
    {
        // Initialize static seq_number
        int da::sockets::Data::seq_number_static = 0;

        Data::Data(int from_pid, int to_pid, int data) : from_pid{from_pid}, to_pid{to_pid}, data{data}
        {
            this->seq_number = this->increaseSeqNumber();
        }

        Data::Data(int seq_number, int from_pid, int to_pid, int data) : seq_number{seq_number}, from_pid{from_pid}, to_pid{to_pid}, data{data}
        {
            this->seq_number = this->increaseSeqNumber();
        }

        int Data::increaseSeqNumber()
        {
            // Return increased seq number
            return ++da::sockets::Data::seq_number_static;
        }

        std::ostream &operator<<(std::ostream &os, const Data &data)
        {
            os <<  "seq_nr: " << data.seq_number << ", form_pid: " << data.from_pid << ", to_pid: " << data.to_pid << ", data: " << data.data;
            return os;
        }
    } // namespace sockets
} // namespace da