// 题 4：观察构造和析构顺序

#include <iostream>

class Tracer {
public:
    Tracer() {
        std::cout << "construct\n";
    }

    ~Tracer() {
        std::cout << "destroy\n";
    }
};

void test() {
    Tracer t;
    std::cout << "inside test\n";
}

int main() {
    std::cout << "before\n";
    test();
    std::cout << "after\n";
}
