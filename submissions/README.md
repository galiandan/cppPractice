# 提交目录

把你自己写的答案放在这个目录，文件名以题号开头，例如：

- `01_student_class.cpp`
- `13_sort_students.cpp`
- `27_thread_pool.cpp`

检查单题：

```bash
python3 tools/check_progress.py --question 13 --file submissions/13_sort_students.cpp
```

按题号顺序检查整个目录：

```bash
python3 tools/check_progress.py --dir submissions
```

自检全部参考答案：

```bash
python3 tools/check_progress.py --all-answers
```
