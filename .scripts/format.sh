#!/usr/bin/env bash

set -euo pipefail

exec bash .scripts/clang_format.sh --write
