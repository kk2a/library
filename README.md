# evibblvalabvslkbv

[![Actions Status](https://github.com/kk2a/library/workflows/verify/badge.svg)](https://gitub.com/kk2a/library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://kk2a.github.io/library/)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/kk2a/library?style=flat-square)


### expand_user_file.py
<!-- 強調 -->
**このファイルはもう使っていません．今は，[cpp-bundle](https://github.com/kk2a/cpp-bundle)を使っています．**

#include <kk2/hoge>, #include "hoge.hpp"をすべて展開したものをクリップボードに保存します．その場で展開されるようにしているので，展開前の行の位置関係は保持されます．

以下のようにして使います．

``` concole
python expand_user_file.py hoge.cpp
```

includeされた各ファイルの関係はDAGになっているのでトポロジカルソートして，その順番に展開されていくようになっているので再定義とかはそもそも起きないのですが，保険でインクルードガードの部分は消していないです．

