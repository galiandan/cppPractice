// 题 33：简易 HTTP 响应服务器

#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
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

    if (listen(serverFd, 16) == -1) {
        std::cerr << "listen failed\n";
        close(serverFd);
        return 1;
    }

    std::cout << "open http://127.0.0.1:8080\n";

    while (true) {
        int clientFd = accept(serverFd, nullptr, nullptr);
        if (clientFd == -1) {
            continue;
        }

        char buffer[2048];
        read(clientFd, buffer, sizeof(buffer));

        std::string body = "<html><body><h1>Hello C++ HTTP</h1></body></html>";
        std::string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html; charset=utf-8\r\n"
            "Content-Length: " + std::to_string(body.size()) + "\r\n"
            "Connection: close\r\n"
            "\r\n" +
            body;

        write(clientFd, response.data(), response.size());
        close(clientFd);
    }

    close(serverFd);
}
