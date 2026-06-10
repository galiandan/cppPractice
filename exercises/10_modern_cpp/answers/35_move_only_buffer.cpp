// 题 35：移动语义追踪

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>

class Buffer {
private:
    std::size_t size_ = 0;
    int* data_ = nullptr;

public:
    explicit Buffer(std::size_t size)
        : size_(size), data_(new int[size]{}) {}

    ~Buffer() {
        delete[] data_;
    }

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    Buffer(Buffer&& other) noexcept
        : size_(std::exchange(other.size_, 0)),
          data_(std::exchange(other.data_, nullptr)) {}

    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            size_ = std::exchange(other.size_, 0);
            data_ = std::exchange(other.data_, nullptr);
        }
        return *this;
    }

    std::size_t size() const {
        return size_;
    }

    int& operator[](std::size_t index) {
        return data_[index];
    }
};

int main() {
    Buffer a(3);
    a[0] = 42;

    Buffer b(std::move(a));
    std::cout << b.size() << ' ' << b[0] << '\n';
}

