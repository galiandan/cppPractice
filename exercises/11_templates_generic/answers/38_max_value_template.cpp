// 题 38：函数模板求最大值

#include <iostream>
#include <string>

template <typename T>
const T& maxValue(const T& a, const T& b) {
    return a < b ? b : a;
}

int main() {
    std::cout << maxValue(3, 7) << '\n';
    std::cout << maxValue(2.5, 1.8) << '\n';
    std::cout << maxValue(std::string("cpp"), std::string("stl")) << '\n';
}

