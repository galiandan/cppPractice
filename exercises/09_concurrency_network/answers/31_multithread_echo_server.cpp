// 题 31：多线程 Echo 服务器

#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <thread>
#include <unistd.h>

void handleClient(int clientFd) {
    char buffer[1024];

    while (true) {
        ssize_t n = read(clientFd, buffer, sizeof(buffer));
        if (n <= 0) {
            break;
        }
        write(clientFd, buffer, n);
    }

    close(clientFd);
}

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

    if (listen(serverFd, 16) == -1) {
        std::cerr << "listen failed\n";
        close(serverFd);
        return 1;
    }

    while (true) {
        int clientFd = accept(serverFd, nullptr, nullptr);
        if (clientFd == -1) {
            std::cerr << "accept failed\n";
            continue;
        }

        std::thread(handleClient, clientFd).detach();
    }

    close(serverFd);
}
