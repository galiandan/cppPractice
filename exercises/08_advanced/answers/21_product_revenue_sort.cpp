// 题 21：自定义比较器管理对象

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Product {
private:
    std::string name_;
    double price_;
    int sales_;

public:
    Product(std::string name, double price, int sales)
        : name_(std::move(name)), price_(price), sales_(sales) {}

    double revenue() const {
        return price_ * sales_;
    }

    void print() const {
        std::cout << name_ << " revenue=" << revenue() << '\n';
    }
};

int main() {
    std::vector<Product> products = {
        {"Keyboard", 300, 20},
        {"Mouse", 120, 80},
        {"Monitor", 1200, 5}
    };

    std::sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.revenue() > b.revenue();
    });

    for (const auto& product : products) {
        product.print();
    }
}
