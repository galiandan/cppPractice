// 题 44：CSV 简单解析

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> parseCsvLine(const std::string& line) {
    std::vector<std::string> fields;
    std::istringstream input(line);
    std::string field;

    while (std::getline(input, field, ',')) {
        fields.push_back(field);
    }

    return fields;
}

int main() {
    auto fields = parseCsvLine("Alice,95,cpp");

    for (const auto& field : fields) {
        std::cout << field << '\n';
    }
}

