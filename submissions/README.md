# 旧提交目录

## 当前填写位置

现在每章题目旁边都有自己的填写区，结构更清楚：

- `exercises/01_oop_basics/submissions/`
- `exercises/05_stl_containers/submissions/`
- `exercises/14_engineering_testing/submissions/`

每个 `submissions/` 目录里已经放好了对应题号的空白 `.cpp` 模板。

## 检查命令

检查单题：

```bash
python3 tools/check_progress.py \
  --question 13 \
  --file exercises/05_stl_containers/submissions/13_sort_students.cpp
```

按题号顺序检查所有分类提交：

```bash
python3 tools/check_progress.py --dir exercises
```

自检全部参考答案：

```bash
python3 tools/check_progress.py --all-answers
```
