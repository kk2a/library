# evibblvalabvslkbv

[![Actions Status](https://github.com/kk2a/library/workflows/verify/badge.svg)](https://gitub.com/kk2a/library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://kk2a.github.io/library/)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/kk2a/library?style=flat-square)

### clang-format の使い方

設定変更後に全ファイルを再フォーマットする場合：

```console
# Windowsの場合（PowerShell）
Get-ChildItem -Recurse -Include *.hpp | ForEach-Object { clang-format -i $_.FullName }

# Unix系の場合（Linux/macOS）
find . -type f \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +
```
