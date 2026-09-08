#!/usr/bin/env python3

"""Compile and run all standalone tests with GCC coverage instrumentation."""

from __future__ import annotations

import argparse
import concurrent.futures
import os
import shutil
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
STANDALONE_MARKER = "competitive-verifier: STANDALONE"


def standalone_tests() -> list[Path]:
    return sorted(
        path
        for path in (ROOT / "verify").rglob("*.cpp")
        if STANDALONE_MARKER in path.read_text(encoding="utf-8")
    )


def run_test(path: Path, build_directory: Path, timeout: int) -> None:
    relative = path.relative_to(ROOT).with_suffix("")
    test_directory = build_directory / relative
    test_directory.mkdir(parents=True, exist_ok=True)
    executable = test_directory / "a.out"
    log = test_directory / "test.log"

    compile_command = [
        "g++",
        "-std=c++23",
        "-Wall",
        "-O0",
        "-g",
        "--coverage",
        "-fprofile-abs-path",
        f"-I{ROOT}",
        str(path),
        "-o",
        str(executable),
    ]
    with log.open("w", encoding="utf-8") as output:
        subprocess.run(
            compile_command,
            cwd=test_directory,
            stdout=output,
            stderr=subprocess.STDOUT,
            check=True,
        )
        subprocess.run(
            [str(executable)],
            cwd=test_directory,
            stdout=output,
            stderr=subprocess.STDOUT,
            check=True,
            timeout=timeout,
        )


def coverage_report(build_directory: Path, output_directory: Path) -> str:
    output_directory.mkdir(parents=True, exist_ok=True)
    command = [
        "gcovr",
        "--root",
        str(ROOT),
        "--object-directory",
        str(build_directory),
        "--html-details",
        str(output_directory / "index.html"),
        "--html-title",
        "kk2 standalone coverage",
        "--cobertura",
        str(output_directory / "cobertura.xml"),
        "--txt-metric",
        "branch",
        "--print-summary",
        "--include",
        r"^(?!verify/|\.scripts/|\.competitive-verifier/).+\.(?:cpp|hpp|cc|h)$",
        "--exclude",
        r"(^|.*/)verify/.*",
        "--exclude",
        r"(^|.*/)\.scripts/.*",
        "--exclude",
        r"(^|.*/)\.competitive-verifier/.*",
    ]
    result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True, check=True)
    summary = result.stdout + result.stderr
    (output_directory / "summary.txt").write_text(summary, encoding="utf-8")
    print(summary, end="")
    return summary


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--build-directory", type=Path, required=True)
    parser.add_argument("--jobs", type=int, default=max(1, min(4, os.cpu_count() or 1)))
    parser.add_argument("--timeout", type=int, default=10)
    args = parser.parse_args()
    args.output = args.output.resolve()
    args.build_directory = args.build_directory.resolve()

    if shutil.which("g++") is None:
        raise SystemExit("g++ was not found")
    if shutil.which("gcovr") is None:
        raise SystemExit("gcovr was not found")

    tests = standalone_tests()
    if not tests:
        raise SystemExit("no STANDALONE tests were found")

    args.build_directory.mkdir(parents=True, exist_ok=True)
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as executor:
        futures = [executor.submit(run_test, path, args.build_directory, args.timeout) for path in tests]
        for path, future in zip(tests, futures):
            try:
                future.result()
            except Exception as error:
                log = args.build_directory / path.relative_to(ROOT).with_suffix("") / "test.log"
                print(f"{path}: failed\n{log.read_text(encoding='utf-8')}", file=sys.stderr)
                raise SystemExit(1) from error

    coverage_report(args.build_directory, args.output)


if __name__ == "__main__":
    main()
