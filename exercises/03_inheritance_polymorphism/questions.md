# 三、继承、多态与虚函数

本章目标：掌握抽象基类、虚函数、虚析构函数和通过基类接口使用派生类对象。重点是“通过统一接口调用不同实现”。

## 题 7：图形面积

设计抽象基类 `Shape`，派生类 `Circle` 和 `Rectangle` 分别计算面积。

### 功能要求

- `Shape` 包含纯虚函数 `double area() const`。
- `Shape` 必须有 `virtual` 析构函数。
- `Circle` 使用半径计算面积，圆周率使用 `3.1415926` 即可。
- `Rectangle` 使用宽和高计算面积。
- 在 `main()` 中通过 `std::unique_ptr<Shape>` 或引用统一调用 `area()`。

### 演示要求

创建半径为 `2` 的圆和 `3 x 4` 的矩形，并按顺序输出面积。

基础验收输出：

```text
12.5664
12
```

### 自测建议

- 把对象放进 `std::vector<std::unique_ptr<Shape>>`。
- 确认没有手动 `delete`。
- 思考 `area()` 为什么应该是 `const`。

## 题 8：虚析构函数的意义

说明下面代码为什么基类析构函数应该是 `virtual`：

```cpp
Base* p = new Derived();
delete p;
```

### 功能要求

- 写出一个最小 `Base` 类，包含 `virtual ~Base() = default;`。
- 可以补充 `Derived` 类或注释说明。
- 本题只做语法检查，不要求运行输出。

### 必须理解

- 如果通过基类指针删除派生类对象，而基类析构函数不是虚函数，会产生未定义行为。
- 拥有虚函数的多态基类通常应声明虚析构函数。

## 题 9：员工工资系统

设计一个多态工资系统。

### 功能要求

- 基类 `Employee` 保存员工姓名。
- `Employee` 提供纯虚函数 `double salary() const`。
- `Employee` 必须有虚析构函数。
- `FullTimeEmployee` 按固定月薪返回工资。
- `PartTimeEmployee` 按 `hourlyRate * hours` 返回工资。
- 在 `main()` 中通过基类智能指针统一遍历输出。

### 演示要求

创建：

- `Alice`，全职，月薪 `10000`。
- `Bob`，兼职，时薪 `80`，工作 `60` 小时。

基础验收输出：

```text
Alice: 10000
Bob: 4800
```

### 自测建议

- 把不同员工类型放在同一个 `std::vector` 中。
- 不要发生对象切片。
- 思考基类接口是否应该暴露姓名的只读访问函数。
