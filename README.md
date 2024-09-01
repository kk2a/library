# evibblvalabvslkbv

[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://kk2a.github.io/library/)



### kyopro.py
#include <kk2/hoge>をすべて展開したものをクリップボードに保存します．(ファイルを展開させたままにしたいならself.rollback()の行を消せば良いです．) その場で展開されるようにしているので，展開前の行の位置関係とかは保持されます．

以下のようにして使います．

``` concole
python expand_user_file.py hoge.cpp
```

includeされた各ファイルの関係はDAGになっているのでトポロジカルソートして，その順番に展開されていくようになっているので再定義とかはそもそも起きないのですが，保険でインクルードガードの部分は消していないです．

