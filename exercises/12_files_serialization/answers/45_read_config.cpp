// 题 45：配置文件读取

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> readConfig(const std::string& filename) {
    std::ifstream input(filename);
    std::unordered_map<std::string, std::string> config;
    std::string line;

    while (std::getline(input, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        auto pos = line.find('=');
        if (pos == std::string::npos) {
            continue;
        }

        config[line.substr(0, pos)] = line.substr(pos + 1);
    }

    return config;
}

int main() {
    auto config = readConfig("app.conf");

    for (const auto& [key, value] : config) {
        std::cout << key << " = " << value << '\n';
    }
}

