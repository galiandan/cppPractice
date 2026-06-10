// 题 40：泛型打印容器

#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename Container>
void printContainer(const Container& container) {
    for (const auto& item : container) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::list<std::string> words = {"hello", "cpp"};

    printContainer(nums);
    printContainer(words);
}

