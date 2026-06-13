#!/usr/bin/env python3
"""
C++ exercise checker.

Usage:
  python3 tools/check_progress.py --question 13 --file exercises/05_stl_containers/submissions/13_sort_students.cpp
  python3 tools/check_progress.py --dir exercises
  python3 tools/check_progress.py --all-answers

The checker compiles a solution, runs configured tests, and reports the first
failed question so you can see where progress currently stops.
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_COMPILER = os.environ.get("CXX", "g++")
DEFAULT_FLAGS = ["-std=c++17", "-Wall", "-Wextra", "-pthread"]


@dataclass
class TestCase:
    name: str
    stdin: str = ""
    expected: str | None = None
    contains: list[str] = field(default_factory=list)
    regex: str | None = None
    files: dict[str, str] = field(default_factory=dict)
    args: list[str] = field(default_factory=list)
    timeout: float = 3.0


@dataclass
class CheckSpec:
    mode: str
    tests: list[TestCase] = field(default_factory=list)
    note: str = ""


def normalize_output(text: str) -> str:
    lines = [line.rstrip() for line in text.replace("\r\n", "\n").splitlines()]
    return "\n".join(lines).strip()


def numeric_lines_close(actual: str, expected: str, eps: float = 1e-4) -> bool:
    actual_parts = normalize_output(actual).split()
    expected_parts = normalize_output(expected).split()
    if len(actual_parts) != len(expected_parts):
        return False

    for a, e in zip(actual_parts, expected_parts):
        try:
            if abs(float(a) - float(e)) > eps:
                return False
        except ValueError:
            if a != e:
                return False

    return True


def compile_source(source: Path, output: Path, link: bool) -> tuple[bool, str]:
    command = [DEFAULT_COMPILER, *DEFAULT_FLAGS]
    if not link:
        command.append("-fsyntax-only")
        command.append(str(source))
    else:
        command.extend([str(source), "-o", str(output)])

    result = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    return result.returncode == 0, result.stdout


def run_binary(binary: Path, case: TestCase, workdir: Path) -> tuple[bool, str, str]:
    for name, content in case.files.items():
        (workdir / name).write_text(content, encoding="utf-8")

    try:
        result = subprocess.run(
            [str(binary), *case.args],
            input=case.stdin,
            text=True,
            cwd=workdir,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            timeout=case.timeout,
        )
    except subprocess.TimeoutExpired as exc:
        output = exc.stdout or ""
        return False, output, f"运行超时，超过 {case.timeout} 秒"

    output = result.stdout
    if result.returncode != 0:
        return False, output, f"运行退出码不是 0，而是 {result.returncode}"

    if case.expected is not None and not numeric_lines_close(output, case.expected):
        return False, output, f"输出不匹配，期望：\n{case.expected}"

    for part in case.contains:
        if part not in output:
            return False, output, f"输出中没有找到：{part}"

    if case.regex is not None and re.search(case.regex, output, re.S) is None:
        return False, output, f"输出不符合正则：{case.regex}"

    return True, output, ""


SPECS: dict[int, CheckSpec] = {
    1: CheckSpec("run", [TestCase("default", expected="name: Alice, id: 1001, avg: 89")]),
    2: CheckSpec("run", [TestCase("default", expected="withdraw failed\n150")]),
    3: CheckSpec("run", [TestCase("default", expected="2")]),
    4: CheckSpec("run", [TestCase("default", expected="before\nconstruct\ninside test\ndestroy\nafter")]),
    5: CheckSpec("syntax", note="本题是类声明练习，只检查是否能通过语法检查。"),
    6: CheckSpec("run", [TestCase("default", expected="30")]),
    7: CheckSpec("run", [TestCase("default", expected="12.5664\n12")]),
    8: CheckSpec("syntax", note="本题是概念/类声明练习，只检查是否能通过语法检查。"),
    9: CheckSpec("run", [TestCase("default", expected="Alice: 10000\nBob: 4800")]),
    10: CheckSpec("run", [TestCase("default", expected="4 + 6i")]),
    11: CheckSpec("run", [TestCase("default", expected="5/6\n1")]),
    12: CheckSpec("run", [TestCase("stdin", stdin="cpp stl cpp oop\n", expected="cpp: 2\noop: 1\nstl: 1")]),
    13: CheckSpec("run", [TestCase("default", expected="Alice 95\nBob 88\nTom 88")]),
    14: CheckSpec("run", [TestCase("stdin", stdin="3 1 2 3 2\n", expected="1 2 3")]),
    15: CheckSpec("run", [TestCase("default", expected="github\nstackoverflow\ncppreference")]),
    16: CheckSpec("run", [TestCase("default", expected="12")]),
    17: CheckSpec("run", [TestCase("default", expected="7")]),
    18: CheckSpec("run", [TestCase("default", expected="3: 3\n1: 2\n2: 2")]),
    19: CheckSpec("run", [TestCase("default", contains=["Effective C++", "C++ Primer"])]),
    20: CheckSpec("run", [TestCase("default", contains=["practice STL priority=5", "write notes priority=1"])]),
    21: CheckSpec("run", [TestCase("default", contains=["Mouse revenue=9600", "Keyboard revenue=6000", "Monitor revenue=6000"])]),
    22: CheckSpec("run", [TestCase("default", expected="program started")]),
    23: CheckSpec("run", [TestCase("default", expected="Tom 110\nAlice 100\nBob 90")]),
    24: CheckSpec("run", [TestCase("default", expected="")]),
    25: CheckSpec("run", [TestCase("default", expected="40000")]),
    26: CheckSpec("run", [TestCase("default", expected="1\n2\n3\n4\n5")]),
    27: CheckSpec("run", [TestCase("default", contains=["task 0", "task 9"])]),
    28: CheckSpec("run", [TestCase("default", expected="500000500000")]),
    29: CheckSpec("syntax", note="网络服务端会阻塞等待连接，这里只做语法检查。"),
    30: CheckSpec("syntax", note="网络客户端依赖服务端，这里只做语法检查。"),
    31: CheckSpec("syntax", note="网络服务端会阻塞等待连接，这里只做语法检查。"),
    32: CheckSpec("run", [TestCase("default", expected="GET\n/index.html\nHTTP/1.1")]),
    33: CheckSpec("syntax", note="HTTP 服务端会阻塞等待连接，这里只做语法检查。"),
    34: CheckSpec("run", [TestCase("default", expected="dog bark\ncat meow")]),
    35: CheckSpec("run", [TestCase("default", expected="3 42")]),
    36: CheckSpec("run", [TestCase("default", expected="95")]),
    37: CheckSpec("run", [TestCase("default", expected="Alice login")]),
    38: CheckSpec("run", [TestCase("default", expected="7\n2.5\nstl")]),
    39: CheckSpec("run", [TestCase("default", expected="second\nfirst")]),
    40: CheckSpec("run", [TestCase("default", expected="1 2 3\nhello cpp")]),
    41: CheckSpec("run", [TestCase("default", expected="int\nunknown\nstd::string")]),
    42: CheckSpec("run", [TestCase("file", files={"scores.txt": "Alice 90\nBob 80\n"}, expected="85")]),
    43: CheckSpec("run", [TestCase("default", contains=["1 0 learn file stream", "2 1 write serializer"])]),
    44: CheckSpec("run", [TestCase("default", expected="Alice\n95\ncpp")]),
    45: CheckSpec("run", [TestCase("file", files={"app.conf": "# test\nhost=127.0.0.1\nport=8080\n"}, contains=["host = 127.0.0.1", "port = 8080"])]),
    46: CheckSpec("run", [TestCase("default", expected="pay 99.5 by alipay")]),
    47: CheckSpec("run", [TestCase("default", expected="draw circle")]),
    48: CheckSpec("run", [TestCase("default", expected="phone display: 26.5")]),
    49: CheckSpec("run", [TestCase("default", expected="127.0.0.1")]),
    50: CheckSpec("run", [TestCase("default", expected="")]),
    51: CheckSpec("run", [TestCase("args", args=["--name", "Alice", "--age", "18"], expected="name=Alice\nage=18")]),
    52: CheckSpec("run", [TestCase("default", regex=r"work cost \d+ ms")]),
    53: CheckSpec("run", [TestCase("default", expected="70\n50")]),
}


def infer_question_number(path: Path) -> int | None:
    match = re.match(r"^(\d+)", path.name)
    if match:
        return int(match.group(1))
    return None


def check_solution(question: int, source: Path, keep_build: bool = False) -> bool:
    spec = SPECS.get(question)
    if spec is None:
        print(f"[SKIP] 题 {question}: 暂无检查规则，只能确认文件存在：{source}")
        return True

    if not source.exists():
        print(f"[FAIL] 题 {question}: 找不到文件 {source}")
        return False

    with tempfile.TemporaryDirectory(prefix="cpp_check_") as tmp:
        tmpdir = Path(tmp)
        binary = tmpdir / "a.out"
        link = spec.mode == "run"

        ok, compile_output = compile_source(source, binary, link)
        if not ok:
            print(f"[FAIL] 题 {question}: 编译失败: {source}")
            print(compile_output.strip())
            return False

        if spec.mode == "syntax":
            suffix = f" ({spec.note})" if spec.note else ""
            print(f"[PASS] 题 {question}: 语法检查通过{suffix}")
            return True

        assert spec.mode == "run"
        for case in spec.tests:
            ok, output, reason = run_binary(binary, case, tmpdir)
            if not ok:
                print(f"[FAIL] 题 {question}: 测试 {case.name} 失败: {source}")
                print(reason)
                if output:
                    print("实际输出：")
                    print(output.strip())
                return False

        print(f"[PASS] 题 {question}: {source}")
        return True


def source_files_from_dir(directory: Path) -> list[tuple[int, Path]]:
    files: list[tuple[int, Path]] = []
    for path in sorted(directory.rglob("*.cpp")):
        if "answers" in path.parts:
            continue

        question = infer_question_number(path)
        if question is not None:
            files.append((question, path))
    return sorted(files, key=lambda item: item[0])


def answer_files() -> list[tuple[int, Path]]:
    files: list[tuple[int, Path]] = []
    for path in sorted((ROOT / "exercises").glob("*/answers/*.cpp")):
        question = infer_question_number(path)
        if question is not None:
            files.append((question, path))
    return sorted(files, key=lambda item: item[0])


def main() -> int:
    parser = argparse.ArgumentParser(description="Check C++ practice progress.")
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument("--file", type=Path, help="single .cpp file to check")
    group.add_argument("--dir", type=Path, help="directory containing submitted .cpp files")
    group.add_argument("--all-answers", action="store_true", help="check all reference answers")
    parser.add_argument("--question", type=int, help="question number for --file")

    args = parser.parse_args()

    if shutil.which(DEFAULT_COMPILER) is None:
        print(f"找不到编译器：{DEFAULT_COMPILER}")
        return 2

    if args.file:
        question = args.question or infer_question_number(args.file)
        if question is None:
            print("无法从文件名推断题号，请使用 --question 指定。")
            return 2
        return 0 if check_solution(question, args.file) else 1

    if args.dir:
        files = source_files_from_dir(args.dir)
        if not files:
            print(f"目录中没有可检查的 .cpp 文件：{args.dir}")
            return 2

        passed = 0
        for question, source in files:
            if check_solution(question, source):
                passed += 1
                continue

            print(f"\n进度停止在题 {question}。前面通过 {passed} 题。")
            return 1

        print(f"\n全部通过：{passed} / {len(files)}")
        return 0

    files = answer_files()
    failed = 0
    for question, source in files:
        if not check_solution(question, source):
            failed += 1

    if failed:
        print(f"\n参考答案自检失败：{failed} 个文件。")
        return 1

    print(f"\n参考答案自检全部通过：{len(files)} 个文件。")
    return 0


if __name__ == "__main__":
    sys.exit(main())
