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
        this->fileHandler.close();
    }

    void Logger::write(const std::string& str) {
      mtx.lock();
      this->fileHandler << str;
      this->fileHandler.flush();
      mtx.unlock();
    }

}