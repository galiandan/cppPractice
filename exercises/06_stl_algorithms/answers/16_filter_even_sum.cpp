// 题 16：筛选偶数并求和

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    std::vector<int> evens;

    std::copy_if(nums.begin(), nums.end(), std::back_inserter(evens), [](int x) {
        return x % 2 == 0;
    });

    int sum = std::accumulate(evens.begin(), evens.end(), 0);
    std::cout << sum << '\n';
}
