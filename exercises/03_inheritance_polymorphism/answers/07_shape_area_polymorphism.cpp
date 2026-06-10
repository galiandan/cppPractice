// 题 7：图形面积

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Circle : public Shape {
private:
    double radius_;

public:
    explicit Circle(double radius) : radius_(radius) {}

    double area() const override {
        return 3.1415926 * radius_ * radius_;
    }
};

class Rectangle : public Shape {
private:
    double width_;
    double height_;

public:
    Rectangle(double width, double height)
        : width_(width), height_(height) {}

    double area() const override {
        return width_ * height_;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2));
    shapes.push_back(std::make_unique<Rectangle>(3, 4));

    for (const auto& shape : shapes) {
        std::cout << shape->area() << '\n';
    }
}
