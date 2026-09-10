#!/usr/bin/env bash

set -euo pipefail

mapfile -d '' files < <(git ls-files -z -- '*.cpp' '*.hpp' '*.cc' '*.h')

if ((${#files[@]} == 0)); then
    exit 0
fi

clang-format --style=file:.clang-format -i "${files[@]}"
