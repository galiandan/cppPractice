// 题 14：去重并保持升序

#include <iostream>
#include <set>

int main() {
    std::set<int> nums;
    int x;

    while (std::cin >> x) {
        nums.insert(x);
    }

    for (int n : nums) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
