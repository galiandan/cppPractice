// 题 9：员工工资系统

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Employee {
protected:
    std::string name_;

public:
    explicit Employee(std::string name) : name_(std::move(name)) {}
    virtual ~Employee() = default;

    virtual double salary() const = 0;

    const std::string& name() const {
        return name_;
    }
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary_;

public:
    FullTimeEmployee(std::string name, double monthlySalary)
        : Employee(std::move(name)), monthlySalary_(monthlySalary) {}

    double salary() const override {
        return monthlySalary_;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate_;
    int hours_;

public:
    PartTimeEmployee(std::string name, double hourlyRate, int hours)
        : Employee(std::move(name)), hourlyRate_(hourlyRate), hours_(hours) {}

    double salary() const override {
        return hourlyRate_ * hours_;
    }
};

int main() {
    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::make_unique<FullTimeEmployee>("Alice", 10000));
    employees.push_back(std::make_unique<PartTimeEmployee>("Bob", 80, 60));

    for (const auto& employee : employees) {
        std::cout << employee->name() << ": " << employee->salary() << '\n';
    }
}
