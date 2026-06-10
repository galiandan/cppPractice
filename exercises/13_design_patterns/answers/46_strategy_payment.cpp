// 题 46：策略模式

#include <iostream>
#include <memory>
#include <string>

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(double amount) = 0;
};

class AlipayStrategy : public PaymentStrategy {
public:
    void pay(double amount) override {
        std::cout << "pay " << amount << " by alipay\n";
    }
};

class BankCardStrategy : public PaymentStrategy {
public:
    void pay(double amount) override {
        std::cout << "pay " << amount << " by bank card\n";
    }
};

class Order {
private:
    std::unique_ptr<PaymentStrategy> strategy_;

public:
    explicit Order(std::unique_ptr<PaymentStrategy> strategy)
        : strategy_(std::move(strategy)) {}

    void checkout(double amount) {
        strategy_->pay(amount);
    }
};

int main() {
    Order order(std::make_unique<AlipayStrategy>());
    order.checkout(99.5);
}

