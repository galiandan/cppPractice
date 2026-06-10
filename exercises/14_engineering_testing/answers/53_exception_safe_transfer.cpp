// 题 53：异常安全转账

#include <iostream>
#include <stdexcept>

class Account {
private:
    double balance_;

public:
    explicit Account(double balance) : balance_(balance) {}

    double balance() const {
        return balance_;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("amount must be positive");
        }
        balance_ += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("amount must be positive");
        }
        if (amount > balance_) {
            throw std::runtime_error("not enough balance");
        }
        balance_ -= amount;
    }
};

void transfer(Account& from, Account& to, double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("amount must be positive");
    }
    if (amount > from.balance()) {
        throw std::runtime_error("not enough balance");
    }

    from.withdraw(amount);
    to.deposit(amount);
}

int main() {
    Account a(100);
    Account b(20);

    transfer(a, b, 30);

    std::cout << a.balance() << '\n';
    std::cout << b.balance() << '\n';
}

