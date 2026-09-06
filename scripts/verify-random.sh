#!/usr/bin/env bash

set -Eeuo pipefail

repo_root="$(git rev-parse --show-toplevel)"
cd "$repo_root"

: "${CXX:=g++}"
: "${CXXFLAGS:=-O2 -std=c++23 -Wall}"
: "${JOBS:=$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 2)}"
: "${TIME_LIMIT:=2}"

if ! [[ "$JOBS" =~ ^[1-9][0-9]*$ ]]; then
    echo "JOBS must be a positive integer: $JOBS" >&2
    exit 2
fi
if ! [[ "$TIME_LIMIT" =~ ^[1-9][0-9]*(\.[0-9]+)?$ ]]; then
    echo "TIME_LIMIT must be a positive number of seconds: $TIME_LIMIT" >&2
    exit 2
fi

# Only files marked IGNORE are local tests; other .test.cpp files belong to
# oj-verify and may require an online judge problem URL.
mapfile -d '' tests < <(
    find verify/unit_test -type f -name '*.test.cpp' \
        -exec grep -l -Z '^#define IGNORE$' {} + |
        sort -z
)
if ((${#tests[@]} == 0)); then
    echo 'No random tests found.'
    exit 0
fi

build_root="$(mktemp -d "${TMPDIR:-/tmp}/kk2-random-verify.XXXXXX")"
trap 'rm -rf "$build_root"' EXIT

run_test() {
    local test_path="$1"
    local test_dir
    local -a compiler_flags

    test_dir="$(mktemp -d "$build_root/test.XXXXXX")"
    read -r -a compiler_flags <<< "$CXXFLAGS"

    echo "[compile] $test_path"
    "$CXX" "${compiler_flags[@]}" -I "$repo_root" "$test_path" -o "$test_dir/test"

    echo "[run]     $test_path"
    timeout --foreground --kill-after=1s "${TIME_LIMIT}s" "$test_dir/test"
}

export CXX CXXFLAGS TIME_LIMIT build_root repo_root
export -f run_test

printf '%s\0' "${tests[@]}" |
    xargs -0 -r -n 1 -P "$JOBS" bash -c 'run_test "$1"' _

echo "All ${#tests[@]} random tests passed (jobs: $JOBS)."
