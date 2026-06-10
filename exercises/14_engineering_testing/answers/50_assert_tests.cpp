// 题 50：用 assert 写单元测试

#include <cassert>

int add(int a, int b) {
    return a + b;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    assert(add(1, 2) == 3);
    assert(add(-1, 1) == 0);

    assert(isPrime(2));
    assert(isPrime(17));
    assert(!isPrime(1));
    assert(!isPrime(100));
}

