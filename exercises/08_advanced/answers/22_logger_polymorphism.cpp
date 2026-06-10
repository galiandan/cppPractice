// 题 22：多态版日志系统

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& message) = 0;
};

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << message << '\n';
    }
};

class MemoryLogger : public Logger {
private:
    std::vector<std::string> messages_;

public:
    void log(const std::string& message) override {
        messages_.push_back(message);
    }

    void dump() const {
        for (const auto& message : messages_) {
            std::cout << message << '\n';
        }
    }
};

int main() {
    std::vector<std::unique_ptr<Logger>> loggers;
    loggers.push_back(std::make_unique<ConsoleLogger>());
    loggers.push_back(std::make_unique<MemoryLogger>());

    for (auto& logger : loggers) {
        logger->log("program started");
    }
}
