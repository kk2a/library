---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: geometry/static_convex_hull.hpp
    title: geometry/static_convex_hull.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ n;\n        vc<kk2::Point<i64>> p(n);\n        kin >> p;\n        kk2::ConvexHull\
    \ ch(p);\n        ch.build();\n        auto hull = ch.hull;\n        kout << ch.hull.size()\
    \ << endl;\n        for (auto &q : ch.hull) kout << q << endl;\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/static_convex_hull.hpp
  - template/template.hpp
  - template/fastio.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: true
  path: verify/yosupo_geometry/static_convex_hull.test.cpp
  requiredBy: []
  timestamp: '2024-10-14 19:35:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_geometry/static_convex_hull.test.cpp
- /verify/verify/yosupo_geometry/static_convex_hull.test.cpp.html
title: verify/yosupo_geometry/static_convex_hull.test.cpp
---
