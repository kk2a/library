#!/usr/bin/env bash

set -euo pipefail

mapfile -d '' files < <(git ls-files -z -- '*.cpp' '*.hpp')

if ((${#files[@]} == 0)); then
    exit 0
fi

clang-format --style=file:.clang-format --dry-run --Werror "${files[@]}"
