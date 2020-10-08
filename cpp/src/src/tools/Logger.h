#include <fstream>
#include <iostream>
#include <string>
#include <mutex>
#ifndef SRC_LOGGER_H
#define SRC_LOGGER_H

namespace da::tools {
    class Logger {
    private:
        std::string filePath;
        std::ofstream fileHandler;
        std::mutex mtx;

    public:
        Logger(std::string filePath);
        ~Logger();

        void writeBroadcast(int seq_nr);
        void writeDeliver(int from_pid, int seq_nr);
        void closeFile();
    };
}

#endif //SRC_LOGGER_H
