// 题 30：TCP Echo 客户端

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <unistd.h>

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        std::cerr << "socket failed\n";
        return 1;
    }

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        std::cerr << "invalid address\n";
        close(fd);
        return 1;
    }

    if (connect(fd, reinterpret_cast<sockaddr*>(&server), sizeof(server)) == -1) {
        std::cerr << "connect failed\n";
        close(fd);
        return 1;
    }

    std::string line;
    char buffer[1024];

    while (std::getline(std::cin, line)) {
        write(fd, line.data(), line.size());

        ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
        if (n <= 0) {
            break;
        }

        buffer[n] = '\0';
        std::cout << "echo: " << buffer << '\n';
    }

    close(fd);
}
