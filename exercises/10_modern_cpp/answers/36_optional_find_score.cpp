// 题 36：std::optional 查询结果

#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int score;
};

std::optional<int> findScore(const std::vector<Student>& students, const std::string& name) {
    for (const auto& student : students) {
        if (student.name == name) {
            return student.score;
        }
    }
    return std::nullopt;
}

int main() {
    std::vector<Student> students = {
        {"Alice", 95},
        {"Bob", 88}
    };

    if (auto score = findScore(students, "Alice")) {
        std::cout << *score << '\n';
    } else {
        std::cout << "not found\n";
    }
}

