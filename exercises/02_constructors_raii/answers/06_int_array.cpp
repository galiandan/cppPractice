// 题 6：简单动态数组

#include <iostream>
#include <stdexcept>

class IntArray {
private:
    int* data_;
    std::size_t size_;

public:
    explicit IntArray(std::size_t size)
        : data_(new int[size]{}), size_(size) {}

    ~IntArray() {
        delete[] data_;
    }

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    int& operator[](std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("index out of range");
        }
        return data_[index];
    }

    const int& operator[](std::size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("index out of range");
        }
        return data_[index];
    }

    std::size_t size() const {
        return size_;
    }
};

int main() {
    IntArray arr(3);
    arr[0] = 10;
    arr[1] = 20;
    std::cout << arr[0] + arr[1] << '\n';
}
