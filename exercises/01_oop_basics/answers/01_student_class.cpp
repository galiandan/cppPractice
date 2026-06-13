// 题 1：学生成绩类

#include <array>
#include <iostream>
#include <string>
#include <utility>

class Student
{
  private:
    std::string name_;
    int id_;
    std::array<double, 3> scores_;

  public:
    Student(std::string name, int id, std::array<double, 3> scores)
        : name_(std::move(name)), id_(id), scores_(scores)
    {
    }

    double average() const
    {
        return (scores_[0] + scores_[1] + scores_[2]) / 3.0;
    }

    void print() const
    {
        std::cout << "name: " << name_ << ", id: " << id_
                  << ", avg: " << average() << '\n';
    }
};

int main()
{
    Student s("Alice", 1001, {90, 85, 92});
    s.print();
}
