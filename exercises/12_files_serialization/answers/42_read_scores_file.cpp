// 题 42：读取成绩文件

#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input("scores.txt");
    if (!input) {
        std::cerr << "cannot open scores.txt\n";
        return 1;
    }

    std::string name;
    int score = 0;
    int count = 0;
    int total = 0;

    while (input >> name >> score) {
        total += score;
        ++count;
    }

    if (count > 0) {
        std::cout << static_cast<double>(total) / count << '\n';
    }
}

