// 题 3：静态成员统计对象数量

#include <iostream>

class Counter {
private:
    static int count_;

public:
    Counter() {
        ++count_;
    }

    static int count() {
        return count_;
    }
};

int Counter::count_ = 0;

int main() {
    Counter a;
    Counter b;
    std::cout << Counter::count() << '\n';
}
