# 九、并发与网络扩展

### 题 25：线程安全计数器

实现一个 `ThreadSafeCounter`，多个线程同时调用 `increment()` 时结果必须正确。

### 题 26：生产者消费者队列

实现一个线程安全队列 `BlockingQueue<T>`：

- `push()` 添加数据。
- `pop()` 阻塞等待并取出数据。
- 使用 `std::mutex` 和 `std::condition_variable`。

### 题 27：简易线程池

实现一个线程池：

- 构造时启动固定数量的工作线程。
- `submit()` 添加任务。
- 析构时停止线程池并等待所有线程退出。

### 题 28：带返回值的线程池任务

在题 27 的基础上，了解 `std::future`、`std::packaged_task`、`std::async` 的作用。写一个使用 `std::async` 并行计算两个函数结果的例子。

### 题 29：TCP Echo 服务器

使用 Linux/POSIX socket 实现一个最简单的 TCP Echo 服务器。客户端发什么，服务器回什么。

### 题 30：TCP Echo 客户端

实现一个 TCP 客户端，连接 `127.0.0.1:8080`，读取用户输入并发送给服务器，然后打印服务器返回的数据。

### 题 31：多线程 Echo 服务器

在题 29 基础上改造服务器：每接受一个客户端连接，就创建一个线程处理该客户端。

### 题 32：HTTP 请求解析入门

写一个函数解析 HTTP 请求的第一行，例如：

```text
GET /index.html HTTP/1.1
```

返回 method、path、version。

### 题 33：简易 HTTP 响应服务器

基于 TCP 服务器，实现一个只能返回固定 HTML 的 HTTP 服务器。浏览器访问 `http://127.0.0.1:8080` 时显示页面。
