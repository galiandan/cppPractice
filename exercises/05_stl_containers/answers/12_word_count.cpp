// 题 12：统计单词出现次数

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> count;
    std::string word;

    while (std::cin >> word) {
        ++count[word];
    }

    for (const auto& [w, c] : count) {
        std::cout << w << ": " << c << '\n';
    }
}
