#include <fstream>
#include <iostream>
#include <string>
#ifndef SRC_LOGGER_H
#define SRC_LOGGER_H

namespace da::tools {
    class Logger {
    private:
        std::string filePath;
        std::ofstream fileHandler;

    public:
        Logger(std::string filePath);
        ~Logger();

        void write(const std::string& str);
        void closeFile();
    };
}

#endif //SRC_LOGGER_H
