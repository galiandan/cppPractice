// 题 39：类模板栈

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data_;

public:
    void push(T value) {
        data_.push_back(std::move(value));
    }

    void pop() {
        if (data_.empty()) {
            throw std::runtime_error("empty stack");
        }
        data_.pop_back();
    }

    const T& top() const {
        if (data_.empty()) {
            throw std::runtime_error("empty stack");
        }
        return data_.back();
    }

    bool empty() const {
        return data_.empty();
    }
};

int main() {
    Stack<std::string> stack;
    stack.push("first");
    stack.push("second");

    std::cout << stack.top() << '\n';
    stack.pop();
    std::cout << stack.top() << '\n';
}

