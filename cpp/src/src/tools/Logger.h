#include <fstream>
#include <iostream>
#include <string>
#include <mutex>
#include <atomic>
#include <unordered_set>
#ifndef SRC_LOGGER_H
#define SRC_LOGGER_H

namespace da::tools {
    class Logger {
    private:
        std::string filePath;
        std::ofstream fileHandler;
        std::mutex mtx;
        std::atomic_int nrOfDelivers;

    public:
      std::unordered_set<std::string> delivered;
        Logger(std::string filePath);
        ~Logger();

        void writeBroadcast(int seq_nr);
        void writeDeliver(int from_pid, int seq_nr);
        void closeFile();
        int getNrOfDelivers();
    };
}

#endif //SRC_LOGGER_H
