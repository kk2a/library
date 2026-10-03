#!/usr/bin/env bash

set -euo pipefail

case "${1:-}" in
    --check)
        check_mode=true
        format_options=(--dry-run --Werror)
        ;;
    --write)
        check_mode=false
        format_options=(-i)
        ;;
    *)
        echo "usage: $0 --check|--write" >&2
        exit 2
        ;;
esac

mapfile -d '' files < <(git ls-files -z -- '*.cpp' '*.hpp' '*.cc' '*.h')

if ((${#files[@]} == 0)); then
    exit 0
fi

normal_files=()
no_column_limit_files=()
macro_files=()
for file in "${files[@]}"; do
    case "$file" in
        template/*)
            macro_files+=("$file")
            ;;
        type_traits/*)
            no_column_limit_files+=("$file")
            ;;
        *)
            normal_files+=("$file")
            ;;
    esac
done

if ((${#normal_files[@]} > 0)); then
    clang-format --style=file:.clang-format "${format_options[@]}" "${normal_files[@]}"
fi

if ((${#macro_files[@]} > 0)); then
    compact_macro_file() {
        local file="$1"
        local temp_dir
        temp_dir=$(mktemp -d "${TMPDIR:-/tmp}/kk2-clang-format.XXXXXX")
        awk '
            function trim(s) {
                sub(/^[[:space:]]+/, "", s)
                sub(/[[:space:]]+$/, "", s)
                return s
            }
            /^#define[[:space:]]/ {
                line = $0
                while (line ~ /\\[[:space:]]*$/) {
                    sub(/\\[[:space:]]*$/, "", line)
                    line = trim(line)
                    if (getline next_line <= 0) break
                    line = line " " trim(next_line)
                }
                print line
                next
            }
            { print }
        ' "$file" > "$temp_dir/output"
        if [[ "$check_mode" == true ]]; then
            if ! cmp -s "$file" "$temp_dir/output"; then
                echo "$file: macro definitions should be one line" >&2
                diff -u "$file" "$temp_dir/output" || true
                rm -rf "$temp_dir"
                return 1
            fi
        else
            mv "$temp_dir/output" "$file"
        fi
        rm -rf "$temp_dir"
    }

    for file in "${macro_files[@]}"; do
        compact_macro_file "$file"
    done
fi

if ((${#no_column_limit_files[@]} > 0)); then
    format_no_column_limit_file() {
        local file="$1"
        local style_file=.scripts/.clang-format-no-column-limit
        if [[ "$file" == type_traits/operator.hpp ]]; then
            style_file=.scripts/.clang-format-no-column-limit-operator
        fi
        clang-format --style=file:"$style_file" "${format_options[@]}" "$file"
    }

    for file in "${no_column_limit_files[@]}"; do
        format_no_column_limit_file "$file"
    done
fi
