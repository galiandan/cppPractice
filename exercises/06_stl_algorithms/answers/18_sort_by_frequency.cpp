// 题 18：按出现频率排序

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::vector<int> nums = {3, 1, 2, 3, 2, 3, 1};
    std::unordered_map<int, int> freq;

    for (int n : nums) {
        ++freq[n];
    }

    std::vector<std::pair<int, int>> items(freq.begin(), freq.end());

    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    for (const auto& [num, count] : items) {
        std::cout << num << ": " << count << '\n';
    }
}
