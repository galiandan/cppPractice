// 题 41：模板特化

#include <iostream>
#include <string>

template <typename T>
struct TypeName {
    static std::string value() {
        return "unknown";
    }
};

template <>
struct TypeName<int> {
    static std::string value() {
        return "int";
    }
};

template <>
struct TypeName<std::string> {
    static std::string value() {
        return "std::string";
    }
};

int main() {
    std::cout << TypeName<int>::value() << '\n';
    std::cout << TypeName<double>::value() << '\n';
    std::cout << TypeName<std::string>::value() << '\n';
}

