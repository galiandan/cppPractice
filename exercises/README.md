# C++ OOP / STL / 扩展练习

## 目录结构

题目和参考答案已按分类拆分。每个分类目录中：

- `questions.md`：只放题目。
- `submissions/`：你写答案的地方，每道题一个空白 `.cpp` 模板。
- `answers/`：每道题一个 `.cpp` 参考答案源码文件。

建议先看 `questions.md`，在同一目录的 `submissions/` 里写代码，完成后再打开 `answers/` 对照。

## 进度检查

进度检查脚本在 `tools/check_progress.py`：

```bash
python3 tools/check_progress.py \
  --question 13 \
  --file exercises/05_stl_containers/submissions/13_sort_students.cpp
python3 tools/check_progress.py --dir exercises
python3 tools/check_progress.py --all-answers
```

## 分类索引

### 一、类与对象基础

- [题目](01_oop_basics/questions.md)
- [填写区](01_oop_basics/submissions)
- [参考源码](01_oop_basics/answers)

### 二、构造、析构与资源管理

- [题目](02_constructors_raii/questions.md)
- [填写区](02_constructors_raii/submissions)
- [参考源码](02_constructors_raii/answers)

### 三、继承、多态与虚函数

- [题目](03_inheritance_polymorphism/questions.md)
- [填写区](03_inheritance_polymorphism/submissions)
- [参考源码](03_inheritance_polymorphism/answers)

### 四、运算符重载与友元

- [题目](04_operator_overloading/questions.md)
- [填写区](04_operator_overloading/submissions)
- [参考源码](04_operator_overloading/answers)

### 五、STL 容器练习

- [题目](05_stl_containers/questions.md)
- [填写区](05_stl_containers/submissions)
- [参考源码](05_stl_containers/answers)

### 六、STL 算法与函数对象

- [题目](06_stl_algorithms/questions.md)
- [填写区](06_stl_algorithms/submissions)
- [参考源码](06_stl_algorithms/answers)

### 七、综合项目题

- [题目](07_projects/questions.md)
- [填写区](07_projects/submissions)
- [参考源码](07_projects/answers)

### 八、进阶挑战题

- [题目](08_advanced/questions.md)
- [填写区](08_advanced/submissions)
- [参考源码](08_advanced/answers)

### 九、并发与网络扩展

- [题目](09_concurrency_network/questions.md)
- [填写区](09_concurrency_network/submissions)
- [参考源码](09_concurrency_network/answers)

### 十、现代 C++ 练习

- [题目](10_modern_cpp/questions.md)
- [填写区](10_modern_cpp/submissions)
- [参考源码](10_modern_cpp/answers)

### 十一、模板与泛型编程

- [题目](11_templates_generic/questions.md)
- [填写区](11_templates_generic/submissions)
- [参考源码](11_templates_generic/answers)

### 十二、文件、流与简单序列化

- [题目](12_files_serialization/questions.md)
- [填写区](12_files_serialization/submissions)
- [参考源码](12_files_serialization/answers)

### 十三、常见设计模式练习

- [题目](13_design_patterns/questions.md)
- [填写区](13_design_patterns/submissions)
- [参考源码](13_design_patterns/answers)

### 十四、工程化、测试与调试

- [题目](14_engineering_testing/questions.md)
- [填写区](14_engineering_testing/submissions)
- [参考源码](14_engineering_testing/answers)
