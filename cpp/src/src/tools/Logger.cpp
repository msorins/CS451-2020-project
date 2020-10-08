#include "Logger.h"

#include <utility>

namespace da::tools {

    Logger::Logger(std::string filePath): filePath{filePath} {
        std::cout << "opening log file: " << filePath << "\n";
        this->fileHandler.open(filePath);
    }

    Logger::~Logger() {
        this->closeFile();
    }

    void Logger::closeFile() {
        std::cout << "closing log file: " << this->filePath << "\n";
        this->fileHandler.flush();
        this->fileHandler.close();
    }

    void Logger::writeBroadcast(int seq_nr) {
      mtx.lock();
      std::string logMsg = "b " + std::to_string(seq_nr) + "\n";
      this->fileHandler << logMsg;
      mtx.unlock();
    }

    void Logger::writeDeliver(int from_pid, int seq_nr) {
      mtx.lock();
      std::string logMsg = "d " + std::to_string(from_pid) + " " + std::to_string(seq_nr);
      this->fileHandler << logMsg;
      mtx.unlock();
    }
}