// 题 34：智能指针管理对象

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() const = 0;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "dog bark\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "cat meow\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& animal : animals) {
        animal->speak();
    }
}

