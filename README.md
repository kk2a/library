# evibblvalabvslkbv

[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://kk2a.github.io/library/)



### kyopro.py
#include <kk2/hoge>があれば，すべて展開します．初めて#include <kk2/hoge>が書かれた行から展開されます．以下のようにして使う．exe化してpath通すと楽．

``` concole
python kyopro.py hoge.cpp
```

includeされた各ファイルの関係はDAGになっているのでトポロジカルソートして，その順番に展開されていくようになっているので再定義とかはそもそも起きないのですが，保険でインクルードガードの部分は消していないです．

