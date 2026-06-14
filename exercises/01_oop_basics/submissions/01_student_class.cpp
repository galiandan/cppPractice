// 题 1：学生成绩类
//
// 设计一个 `Student` 类，包含姓名、学号、三门课成绩。要求：
//
// - 构造函数初始化所有成员。
// - 提供 `average()` 返回平均分。
// - 提供 `print()` 输出学生信息。

#include <iostream>
#include <string>

class Student
{
  private:
    std::string Name;
    std::string Id;
    int Math;
    int Chinese;
    int English;

  public:
    Student() : Math(0), Chinese(0), English(0)
    {
    }
    Student(std::string name, std::string id) : Math(0), Chinese(0), English(0)
    {
        this->Name = name;
        this->Id = id;
    }
    Student(std::string name, std::string id, int chinese, int math,
            int english)
    {
        this->Name = name;
        this->Id = id;
        this->Chinese = chinese;
        this->Math = math;
        this->English = english;
    }
    double average()
    {
        return ((this->Chinese + this->Math + this->English) * 1.0) / 3;
    }
    void print()
    {
        std::cout << this->Name << " " << this->Id << std::endl;
    }
};

int main()
{
    Student stu("zhangsan", "12345", 19, 22, 33);
    std::cout << stu.average() << std::endl;
    stu.print();
    return 0;
}
