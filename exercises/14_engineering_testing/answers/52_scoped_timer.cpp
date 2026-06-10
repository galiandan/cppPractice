// 题 52：计时工具类

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

class ScopedTimer {
private:
    std::string name_;
    std::chrono::steady_clock::time_point start_;

public:
    explicit ScopedTimer(std::string name)
        : name_(std::move(name)), start_(std::chrono::steady_clock::now()) {}

    ~ScopedTimer() {
        auto end = std::chrono::steady_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_);
        std::cout << name_ << " cost " << ms.count() << " ms\n";
    }
};

int main() {
    ScopedTimer timer("work");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

