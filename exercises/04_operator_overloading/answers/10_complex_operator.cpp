// 题 10：复数类

#include <iostream>

class Complex {
private:
    double real_;
    double imag_;

public:
    Complex(double real = 0, double imag = 0)
        : real_(real), imag_(imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(real_ + other.real_, imag_ + other.imag_);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real_ << " + " << c.imag_ << "i";
        return os;
    }
};

int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    std::cout << a + b << '\n';
}
