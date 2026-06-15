# C++ OOP / STL / 工程化练习

这套题的目标不是刷语法点，而是把 C++ 基础能力串成一条可检查的训练路径：读题、建模、实现、编译、运行、对照、复盘。

每道题都有三个层次：

- **基础通过**：程序能被检查脚本编译并通过指定演示用例。
- **完整实现**：满足题面列出的 API、边界条件和资源管理要求。
- **高质量答案**：符合 [QUALITY.md](QUALITY.md) 的代码质量清单，包括 const-correctness、异常安全、RAII、边界自测和可读性。

## 目录结构

每个分类目录中：

- `questions.md`：题面、验收标准、自测建议。
- `submissions/`：作答区。这里可能有你的代码，更新题库时不应覆盖。
- `answers/`：参考源码。参考答案强调一种可读写法，不代表唯一解。

建议流程：

1. 先读本章 `questions.md`，明确输出格式和边界条件。
2. 在同章 `submissions/` 写对应题号的 `.cpp`。
3. 用检查脚本跑单题。
4. 通过后再看 `answers/`，比较 API、边界处理和代码组织。
5. 按 [QUALITY.md](QUALITY.md) 做一次自查，不只看脚本是否通过。

## 编译与检查

检查脚本在 `tools/check_progress.py`，默认使用 `g++` 和 C++17：

```bash
python3 tools/check_progress.py \
  --question 13 \
  --file exercises/05_stl_containers/submissions/13_sort_students.cpp

python3 tools/check_progress.py --dir exercises

python3 tools/check_progress.py --all-answers
```

可以通过环境变量指定编译器：

```bash
CXX=clang++ python3 tools/check_progress.py --all-answers
```

脚本只覆盖基础验收。题面里的“高质量自测”需要你自己补充测试或手动检查。

## 学习路径

- 第 1 到 4 章：对象模型、构造析构、多态、运算符重载。
- 第 5 到 6 章：STL 容器、算法、比较器、迭代器思维。
- 第 7 到 8 章：小项目和常见 C++ 陷阱。
- 第 9 章：并发和 Linux/POSIX 网络入门，重点是正确关闭资源和避免数据竞争。
- 第 10 到 11 章：现代 C++、移动语义、模板和泛型接口。
- 第 12 到 14 章：文件、序列化、设计模式、测试、调试和异常安全。

## 分类索引

| 章节 | 主题 | 题目 | 填写区 | 参考源码 |
| --- | --- | --- | --- | --- |
| 01 | 类与对象基础 | [题目](01_oop_basics/questions.md) | [submissions](01_oop_basics/submissions) | [answers](01_oop_basics/answers) |
| 02 | 构造、析构与资源管理 | [题目](02_constructors_raii/questions.md) | [submissions](02_constructors_raii/submissions) | [answers](02_constructors_raii/answers) |
| 03 | 继承、多态与虚函数 | [题目](03_inheritance_polymorphism/questions.md) | [submissions](03_inheritance_polymorphism/submissions) | [answers](03_inheritance_polymorphism/answers) |
| 04 | 运算符重载与友元 | [题目](04_operator_overloading/questions.md) | [submissions](04_operator_overloading/submissions) | [answers](04_operator_overloading/answers) |
| 05 | STL 容器 | [题目](05_stl_containers/questions.md) | [submissions](05_stl_containers/submissions) | [answers](05_stl_containers/answers) |
| 06 | STL 算法与函数对象 | [题目](06_stl_algorithms/questions.md) | [submissions](06_stl_algorithms/submissions) | [answers](06_stl_algorithms/answers) |
| 07 | 综合项目题 | [题目](07_projects/questions.md) | [submissions](07_projects/submissions) | [answers](07_projects/answers) |
| 08 | 进阶挑战题 | [题目](08_advanced/questions.md) | [submissions](08_advanced/submissions) | [answers](08_advanced/answers) |
| 09 | 并发与网络扩展 | [题目](09_concurrency_network/questions.md) | [submissions](09_concurrency_network/submissions) | [answers](09_concurrency_network/answers) |
| 10 | 现代 C++ | [题目](10_modern_cpp/questions.md) | [submissions](10_modern_cpp/submissions) | [answers](10_modern_cpp/answers) |
| 11 | 模板与泛型编程 | [题目](11_templates_generic/questions.md) | [submissions](11_templates_generic/submissions) | [answers](11_templates_generic/answers) |
| 12 | 文件、流与简单序列化 | [题目](12_files_serialization/questions.md) | [submissions](12_files_serialization/submissions) | [answers](12_files_serialization/answers) |
| 13 | 常见设计模式 | [题目](13_design_patterns/questions.md) | [submissions](13_design_patterns/submissions) | [answers](13_design_patterns/answers) |
| 14 | 工程化、测试与调试 | [题目](14_engineering_testing/questions.md) | [submissions](14_engineering_testing/submissions) | [answers](14_engineering_testing/answers) |
