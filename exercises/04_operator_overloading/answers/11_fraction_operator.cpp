// 题 11：分数类

#include <iostream>
#include <numeric>

class Fraction {
private:
    int numerator_;
    int denominator_;

    void normalize() {
        int g = std::gcd(numerator_, denominator_);
        numerator_ /= g;
        denominator_ /= g;
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

public:
    Fraction(int numerator, int denominator)
        : numerator_(numerator), denominator_(denominator) {
        normalize();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(
            numerator_ * other.denominator_ + other.numerator_ * denominator_,
            denominator_ * other.denominator_
        );
    }

    bool operator<(const Fraction& other) const {
        return numerator_ * other.denominator_ < other.numerator_ * denominator_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator_ << '/' << f.denominator_;
        return os;
    }
};

int main() {
    Fraction a(1, 2);
    Fraction b(1, 3);
    std::cout << a + b << '\n';
    std::cout << (b < a) << '\n';
}
