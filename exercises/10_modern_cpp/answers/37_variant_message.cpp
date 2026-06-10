// 题 37：std::variant 表达不同消息

#include <iostream>
#include <string>
#include <variant>

struct TextMessage {
    std::string text;
};

struct LoginMessage {
    std::string user;
};

struct LogoutMessage {
    std::string user;
};

using Message = std::variant<TextMessage, LoginMessage, LogoutMessage>;

struct MessageHandler {
    void operator()(const TextMessage& msg) const {
        std::cout << "text: " << msg.text << '\n';
    }

    void operator()(const LoginMessage& msg) const {
        std::cout << msg.user << " login\n";
    }

    void operator()(const LogoutMessage& msg) const {
        std::cout << msg.user << " logout\n";
    }
};

int main() {
    Message msg = LoginMessage{"Alice"};
    std::visit(MessageHandler{}, msg);
}

