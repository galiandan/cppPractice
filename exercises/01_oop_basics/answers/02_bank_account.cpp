// 题 2：银行账户类

#include <iostream>
#include <string>
#include <utility>

class BankAccount
{
  private:
    std::string owner_;
    double balance_;

  public:
    BankAccount(std::string owner, double balance = 0.0)
        : owner_(std::move(owner)), balance_(balance)
    {
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance_ += amount;
        }
    }

    bool withdraw(double amount)
    {
        if (amount <= 0 || amount > balance_)
        {
            return false;
        }
        balance_ -= amount;
        return true;
    }

    double balance() const
    {
        return balance_;
    }
};

int main()
{
    BankAccount account("Bob", 100);
    account.deposit(50);
    if (!account.withdraw(200))
    {
        std::cout << "withdraw failed\n";
    }
    std::cout << account.balance() << '\n';
}
