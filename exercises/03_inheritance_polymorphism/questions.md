# 三、继承、多态与虚函数

### 题 7：图形面积

设计抽象基类 `Shape`，包含纯虚函数 `area()`。派生类 `Circle` 和 `Rectangle` 分别计算面积。

### 题 8：虚析构函数的意义

说明下面代码为什么基类析构函数应该是 `virtual`：

```cpp
Base* p = new Derived();
delete p;
```

### 题 9：员工工资系统

设计基类 `Employee`，派生类 `FullTimeEmployee` 和 `PartTimeEmployee`。要求统一用 `salary()` 计算工资。
