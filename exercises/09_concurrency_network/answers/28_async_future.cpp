// 题 28：带返回值的线程池任务

#include <future>
#include <iostream>
#include <numeric>
#include <vector>

long long sumRange(int begin, int end) {
    long long result = 0;
    for (int i = begin; i <= end; ++i) {
        result += i;
    }
    return result;
}

int main() {
    auto left = std::async(std::launch::async, sumRange, 1, 500000);
    auto right = std::async(std::launch::async, sumRange, 500001, 1000000);

    std::cout << left.get() + right.get() << '\n';
}
