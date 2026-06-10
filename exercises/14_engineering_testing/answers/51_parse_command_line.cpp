// 题 51：命令行参数解析

#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> parseArgs(int argc, char* argv[]) {
    std::unordered_map<std::string, std::string> args;

    for (int i = 1; i + 1 < argc; i += 2) {
        std::string key = argv[i];
        std::string value = argv[i + 1];

        if (key.rfind("--", 0) == 0) {
            args[key.substr(2)] = value;
        }
    }

    return args;
}

int main(int argc, char* argv[]) {
    auto args = parseArgs(argc, argv);

    std::cout << "name=" << args["name"] << '\n';
    std::cout << "age=" << args["age"] << '\n';
}

