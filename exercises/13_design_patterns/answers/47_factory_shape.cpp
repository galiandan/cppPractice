// 题 47：工厂模式

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "draw circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "draw rectangle\n";
    }
};

std::unique_ptr<Shape> createShape(const std::string& type) {
    if (type == "circle") {
        return std::make_unique<Circle>();
    }
    if (type == "rectangle") {
        return std::make_unique<Rectangle>();
    }
    throw std::invalid_argument("unknown shape type");
}

int main() {
    auto shape = createShape("circle");
    shape->draw();
}

