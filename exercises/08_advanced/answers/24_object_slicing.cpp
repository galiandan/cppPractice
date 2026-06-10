// 题 24：对象切片问题

#include <memory>

class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {
};

void use(const Base& obj) {
    (void)obj;
}

int main() {
    // 错误示例：如果写成 Base b = d;，会发生对象切片。
    Derived d;

    // 正确方式 1：用引用接收派生类对象。
    use(d);

    // 正确方式 2：用基类智能指针指向派生类对象。
    std::unique_ptr<Base> p = std::make_unique<Derived>();
    (void)p;
}
