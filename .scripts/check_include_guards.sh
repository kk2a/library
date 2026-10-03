#!/usr/bin/env bash

set -euo pipefail
export LC_ALL=C

cd "$(git rev-parse --show-toplevel)"

status=0
declare -A guards=()

while IFS= read -r -d '' file; do
    path=$file
    expected=${path^^}
    expected=${expected//[^A-Z0-9]/_}
    expected="KK2_${expected}"

    first=$(sed -n '1p' "$path")
    second=$(sed -n '2p' "$path")
    last=$(tail -n 1 "$path")

    if [[ $first != "#ifndef $expected" ]]; then
        printf '%s: first line must be `#ifndef %s`\n' "$path" "$expected" >&2
        status=1
    fi
    if [[ $second != "#define $expected 1" ]]; then
        printf '%s: second line must be `#define %s 1`\n' "$path" "$expected" >&2
        status=1
    fi
    if [[ $last != "#endif // $expected" ]]; then
        printf '%s: last line must be `#endif // %s`\n' "$path" "$expected" >&2
        status=1
    fi

    if [[ -n ${guards[$expected]+x} ]]; then
        printf '%s and %s use the same include guard `%s`\n' \
            "${guards[$expected]}" "$path" "$expected" >&2
        status=1
    fi
    guards[$expected]=$path
done < <(git ls-files -z -- '*.hpp')

exit "$status"
