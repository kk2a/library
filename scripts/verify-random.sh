#!/usr/bin/env bash

set -Eeuo pipefail

repo_root="$(git rev-parse --show-toplevel)"
cd "$repo_root"

: "${CXX:=g++}"
: "${CXXFLAGS:=-O2 -std=c++23 -Wall}"
: "${JOBS:=$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 2)}"
: "${TIME_LIMIT:=2}"
: "${MARK_FILE:=.verify-helper/timestamps.random.json}"

if ! [[ "$JOBS" =~ ^[1-9][0-9]*$ ]]; then
    echo "JOBS must be a positive integer: $JOBS" >&2
    exit 2
fi
if ! [[ "$TIME_LIMIT" =~ ^[1-9][0-9]*(\.[0-9]+)?$ ]]; then
    echo "TIME_LIMIT must be a positive number of seconds: $TIME_LIMIT" >&2
    exit 2
fi
if ! command -v timeout >/dev/null 2>&1; then
    echo 'timeout command is required' >&2
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

declare -A previous_marks fingerprints
if [[ -f "$MARK_FILE" ]]; then
    while IFS=$'\t' read -r test_path fingerprint; do
        [[ -n "$test_path" ]] && previous_marks["$test_path"]="$fingerprint"
    done < <(
        python3 - "$MARK_FILE" <<'PY'
import json
import sys

with open(sys.argv[1]) as mark_file:
    marks = json.load(mark_file)

for path, fingerprint in marks.items():
    print(f"{path}\t{fingerprint}")
PY
    )
fi

read -r -a compiler_flags <<< "$CXXFLAGS"

dependency_fingerprint() {
    local test_path="$1"
    local dependency_list dependency repo_path

    dependency_list="$("$CXX" "${compiler_flags[@]}" -MM -MG -MT random_test \
        -I "$repo_root" "$test_path" 2>/dev/null |
        awk 'NR == 1 { sub(/^[^:]*: /, "") } { sub(/\\$/, ""); printf "%s ", $0 }')"

    {
        for dependency in $dependency_list; do
            [[ -f "$dependency" ]] || continue
            repo_path="$(realpath --relative-to="$repo_root" "$dependency")"
            printf '%s\t' "$repo_path"
            if git cat-file -e "HEAD:$repo_path" 2>/dev/null; then
                git rev-parse "HEAD:$repo_path"
            else
                sha256sum "$dependency" | cut -d' ' -f1
            fi
        done
    } | sort | sha256sum | cut -d' ' -f1
}

pending_tests=()
for test_path in "${tests[@]}"; do
    fingerprint="$(dependency_fingerprint "$test_path")"
    fingerprints["$test_path"]="$fingerprint"
    if [[ "${previous_marks[$test_path]-}" == "$fingerprint" ]]; then
        echo "[skip]    $test_path"
    else
        pending_tests+=("$test_path")
    fi
done

if ((${#pending_tests[@]} == 0)); then
    echo "All ${#tests[@]} random tests are up to date."
    exit 0
fi

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

printf '%s\0' "${pending_tests[@]}" |
    xargs -0 -r -n 1 -P "$JOBS" bash -c 'run_test "$1"' _

marker_tmp="$build_root/timestamps.random.json"
marker_entries="$build_root/marker.tsv"
for test_path in "${tests[@]}"; do
    printf '%s\t%s\n' "$test_path" "${fingerprints[$test_path]}" >> "$marker_entries"
done
python3 - "$marker_tmp" "$marker_entries" <<'PY'
import json
import sys

entries = {}
with open(sys.argv[2]) as entries_file:
    for line in entries_file:
        path, fingerprint = line.rstrip("\n").split("\t", 1)
        entries[path] = fingerprint

with open(sys.argv[1], "w") as mark_file:
    json.dump(entries, mark_file, sort_keys=True, indent=0)
    mark_file.write("\n")
PY
mkdir -p "$(dirname "$MARK_FILE")"
mv "$marker_tmp" "$MARK_FILE"

echo "All ${#tests[@]} random tests passed (jobs: $JOBS, time limit: ${TIME_LIMIT}s)."
