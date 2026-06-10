// 题 25：线程安全计数器

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class ThreadSafeCounter {
private:
    int value_ = 0;
    mutable std::mutex mutex_;

public:
    void increment() {
        std::lock_guard<std::mutex> lock(mutex_);
        ++value_;
    }

    int value() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return value_;
    }
};

int main() {
    ThreadSafeCounter counter;
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([&counter] {
            for (int j = 0; j < 10000; ++j) {
                counter.increment();
            }
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << counter.value() << '\n';
}
