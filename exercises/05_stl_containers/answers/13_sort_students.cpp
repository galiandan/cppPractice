// 题 13：学生成绩排序

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::vector<Student> students = {
        {"Tom", 88},
        {"Alice", 95},
        {"Bob", 88}
    };

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }
        return a.name < b.name;
    });

    for (const auto& s : students) {
        std::cout << s.name << ' ' << s.score << '\n';
    }
}
