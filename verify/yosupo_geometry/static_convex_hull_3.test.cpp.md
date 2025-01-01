---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/static_convex_hull.hpp
    title: geometry/static_convex_hull.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_convex_hull
    links:
    - https://judge.yosupo.jp/problem/static_convex_hull
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/point.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_convex_hull\" \n\
    \n#include \"../../geometry/point.hpp\"\n#include \"../../geometry/static_convex_hull.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int t;\n    kin >> t;\n    rep (t) {\n        int n;\n        kin >>\
    \ n;\n        vc<kk2::Point<i64>> p(n);\n        kin >> p;\n        kk2::StaticConvexHull\
    \ ch(p);\n        ch.build();\n\n        if (n == 0) {\n            kout << 0\
    \ << \"\\n\";\n            continue;\n        }\n\n        if (ch.up.size() ==\
    \ 1u) {\n            kout << 1 << \"\\n\";\n            kout << ch.up[0] << \"\
    \\n\";\n            continue;\n        }\n\n        kout << ch.up.size() + ch.dw.size()\
    \ - 2 << \"\\n\";\n        vc<kk2::Point<i64>> res(ch.up.size() + ch.dw.size()\
    \ - 2);\n        rep (i, n) {\n            if (ch.idx_up[i] > 0) res[ch.dw.size()\
    \ + ch.up.size() - ch.idx_up[i] - 2] = p[i];\n            if (ch.idx_dw[i] !=\
    \ -1) res[ch.idx_dw[i]] = p[i];\n        }\n        for (auto &q : res) kout <<\
    \ q << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - geometry/point.hpp
  - type_traits/type_traits.hpp
  - geometry/static_convex_hull.hpp
  - template/template.hpp
  - template/fastio.hpp
  - template/type_alias.hpp
  - template/constant.hpp
  - template/function_util.hpp
  - template/macros.hpp
  - template/io_util.hpp
  isVerificationFile: true
  path: verify/yosupo_geometry/static_convex_hull_3.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 14:03:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_3.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_geometry/static_convex_hull_3.test.cpp
- /verify/verify/yosupo_geometry/static_convex_hull_3.test.cpp.html
title: verify/yosupo_geometry/static_convex_hull_3.test.cpp
---
