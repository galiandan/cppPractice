// 题 26：生产者消费者队列

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>

template <typename T>
class BlockingQueue {
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;

public:
    void push(T value) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.push(std::move(value));
        }
        cv_.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] {
            return !queue_.empty();
        });

        T value = std::move(queue_.front());
        queue_.pop();
        return value;
    }
};

int main() {
    BlockingQueue<int> queue;

    std::thread producer([&queue] {
        for (int i = 1; i <= 5; ++i) {
            queue.push(i);
        }
    });

    std::thread consumer([&queue] {
        for (int i = 1; i <= 5; ++i) {
            std::cout << queue.pop() << '\n';
        }
    });

    producer.join();
    consumer.join();
}
