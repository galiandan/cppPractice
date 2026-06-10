// 题 29：TCP Echo 服务器

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd == -1) {
        std::cerr << "socket failed\n";
        return 1;
    }

    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(serverFd, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == -1) {
        std::cerr << "bind failed\n";
        close(serverFd);
        return 1;
    }

    if (listen(serverFd, 5) == -1) {
        std::cerr << "listen failed\n";
        close(serverFd);
        return 1;
    }

    std::cout << "server listening on port 8080\n";

    int clientFd = accept(serverFd, nullptr, nullptr);
    if (clientFd == -1) {
        std::cerr << "accept failed\n";
        close(serverFd);
        return 1;
    }

    char buffer[1024];
    while (true) {
        ssize_t n = read(clientFd, buffer, sizeof(buffer));
        if (n <= 0) {
            break;
        }
        write(clientFd, buffer, n);
    }

    close(clientFd);
    close(serverFd);
}
