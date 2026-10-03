---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/static_convex_hull
    links:
    - https://judge.yosupo.jp/problem/static_convex_hull
  dependencies:
  - files:
    - filename: point.hpp
      icon: LIBRARY_ALL_AC
      path: geometry/point.hpp
    - filename: static_convex_hull.hpp
      icon: LIBRARY_ALL_AC
      path: geometry/static_convex_hull.hpp
    - filename: constant.hpp
      icon: LIBRARY_ALL_AC
      path: template/constant.hpp
    - filename: fastio.hpp
      icon: LIBRARY_ALL_AC
      path: template/fastio.hpp
    - filename: io_util.hpp
      icon: LIBRARY_ALL_AC
      path: template/io_util.hpp
    - filename: macros.hpp
      icon: LIBRARY_ALL_AC
      path: template/macros.hpp
    - filename: template.hpp
      icon: LIBRARY_ALL_AC
      path: template/template.hpp
    - filename: type_alias.hpp
      icon: LIBRARY_ALL_AC
      path: template/type_alias.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - geometry/point.hpp
  - geometry/static_convex_hull.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/template.hpp
  - template/type_alias.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_convex_hull\n\
      \n#include \"../../geometry/point.hpp\"\n#include \"../../geometry/static_convex_hull.hpp\"\
      \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
      \ {\n    int t;\n    kin >> t;\n    rep(t) {\n        int n;\n        kin >>\
      \ n;\n        vc<kk2::Point<i64>> p(n);\n        kin >> p;\n        kk2::StaticConvexHull\
      \ ch(p);\n        ch.build();\n\n        kout << ch.hull.size() << \"\\n\";\n\
      \        vc<kk2::Point<i64>> res(ch.hull.size());\n        rep(i, n) {\n   \
      \         if (ch.idx_hull[i] != -1) res[ch.idx_hull[i]] = p[i];\n        }\n\
      \        for (auto &q : res) kout << q << \"\\n\";\n    }\n\n    return 0;\n\
      }\n"
    name: default
  - code: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/resolver.py\"\
      , line 290, in resolve\n    bundled_code = language.bundle(path, basedir=basedir)\n\
      \                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus.py\"\
      , line 243, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 478, in update\n    self.update(\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 354, in update\n    raise BundleErrorAt(\ncompetitive_verifier.oj.languages.cplusplus_bundle.BundleErrorAt:\
      \ geometry/point.hpp: line 4: #pragma once found in an include guard with #ifndef\n"
    name: bundle error
  isFailed: false
  isVerificationFile: true
  path: verify/yosupo_geometry/static_convex_hull_2.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.290055762999998
    environment: g++
    memory: 4.352
    name: all_same_00
    status: AC
  - elapsed: 0.26569740100001127
    environment: g++
    memory: 4.724
    name: all_same_01
    status: AC
  - elapsed: 0.0017099969999776476
    environment: g++
    memory: 3.912
    name: example_00
    status: AC
  - elapsed: 0.001614458000005925
    environment: g++
    memory: 3.88
    name: example_01
    status: AC
  - elapsed: 0.4963806990000421
    environment: g++
    memory: 64.356
    name: max_ans_00
    status: AC
  - elapsed: 0.39204859500000566
    environment: g++
    memory: 36.852
    name: max_colinear_00
    status: AC
  - elapsed: 0.389218226999958
    environment: g++
    memory: 36.852
    name: max_colinear_01
    status: AC
  - elapsed: 0.4172886140000287
    environment: g++
    memory: 36.836
    name: max_random_00
    status: AC
  - elapsed: 0.3467553360000011
    environment: g++
    memory: 36.832
    name: max_random_01
    status: AC
  - elapsed: 0.3836161529999913
    environment: g++
    memory: 36.844
    name: max_random_02
    status: AC
  - elapsed: 0.39450781599998663
    environment: g++
    memory: 36.836
    name: max_random_03
    status: AC
  - elapsed: 0.4172055479999699
    environment: g++
    memory: 36.76
    name: max_random_04
    status: AC
  - elapsed: 0.3428059589999748
    environment: g++
    memory: 36.852
    name: max_random_05
    status: AC
  - elapsed: 0.37897725599998466
    environment: g++
    memory: 36.852
    name: max_random_06
    status: AC
  - elapsed: 0.3970742789999804
    environment: g++
    memory: 36.856
    name: max_random_07
    status: AC
  - elapsed: 0.4689773609999861
    environment: g++
    memory: 49.456
    name: near_circle_00
    status: AC
  - elapsed: 0.47295646700001726
    environment: g++
    memory: 49.5
    name: near_circle_01
    status: AC
  - elapsed: 0.43331827499997644
    environment: g++
    memory: 4.168
    name: small_random_00
    status: AC
  - elapsed: 0.3284890400000222
    environment: g++
    memory: 3.968
    name: small_random_01
    status: AC
  - elapsed: 0.3424797580000245
    environment: g++
    memory: 4.176
    name: small_random_02
    status: AC
  - elapsed: 0.35257012200003146
    environment: g++
    memory: 4.124
    name: small_random_03
    status: AC
  - elapsed: 0.4341663420000259
    environment: g++
    memory: 4.132
    name: small_random_04
    status: AC
  - elapsed: 0.32794431500002474
    environment: g++
    memory: 4.168
    name: small_random_05
    status: AC
  - elapsed: 0.34124185899997883
    environment: g++
    memory: 3.996
    name: small_random_06
    status: AC
  - elapsed: 0.3473006539999801
    environment: g++
    memory: 4.176
    name: small_random_07
    status: AC
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_2.test.cpp
layout: document
---
