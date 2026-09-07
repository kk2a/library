#!/usr/bin/env python3

"""Add a common execution timeout to competitive-verifier standalone tests."""

import json
import sys
from pathlib import Path


TIMEOUT = "10s"
STANDALONE_CACHE_MARKER = ".competitive-verifier/cache/standalone/"


def add_timeout(path: Path) -> int:
    with path.open(encoding="utf-8") as file:
        data = json.load(file)

    wrapped = 0
    for file_data in data["files"].values():
        for verification in file_data.get("verification", []):
            if verification.get("type") != "command":
                continue

            command = verification.get("command")
            if not isinstance(command, str) or STANDALONE_CACHE_MARKER not in command:
                continue

            verification["command"] = [
                "timeout",
                "--foreground",
                "--kill-after=1s",
                TIMEOUT,
                command,
            ]
            wrapped += 1

    with path.open("w", encoding="utf-8") as file:
        json.dump(data, file, ensure_ascii=False, indent=2)
        file.write("\n")

    return wrapped


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit(f"usage: {Path(sys.argv[0]).name} VERIFY_JSON")

    path = Path(sys.argv[1])
    wrapped = add_timeout(path)
    print(f"Added {TIMEOUT} timeout to {wrapped} standalone tests in {path}")


if __name__ == "__main__":
    main()
