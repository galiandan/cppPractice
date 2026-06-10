// 题 32：HTTP 请求解析入门

#include <iostream>
#include <sstream>
#include <string>

struct HttpRequestLine {
    std::string method;
    std::string path;
    std::string version;
};

bool parseRequestLine(const std::string& line, HttpRequestLine& result) {
    std::istringstream iss(line);
    return static_cast<bool>(iss >> result.method >> result.path >> result.version);
}

int main() {
    HttpRequestLine line;

    if (parseRequestLine("GET /index.html HTTP/1.1", line)) {
        std::cout << line.method << '\n';
        std::cout << line.path << '\n';
        std::cout << line.version << '\n';
    }
}
