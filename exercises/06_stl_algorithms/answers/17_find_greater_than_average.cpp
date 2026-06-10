// 题 17：查找第一个大于平均值的元素

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9};
    double avg = static_cast<double>(std::accumulate(nums.begin(), nums.end(), 0)) / nums.size();

    auto it = std::find_if(nums.begin(), nums.end(), [avg](int x) {
        return x > avg;
    });

    if (it != nums.end()) {
        std::cout << *it << '\n';
    }
}
