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
      \ ch(p);\n        ch.build();\n\n        if (n == 0) {\n            kout <<\
      \ 0 << \"\\n\";\n            continue;\n        }\n\n        if (ch.up.size()\
      \ == 1u) {\n            kout << 1 << \"\\n\";\n            kout << ch.up[0]\
      \ << \"\\n\";\n            continue;\n        }\n\n        kout << ch.up.size()\
      \ + ch.dw.size() - 2 << \"\\n\";\n        for (int i = 0; i < (int)ch.dw.size();\
      \ ++i) { kout << ch.dw[i] << \"\\n\"; }\n        for (int i = (int)ch.up.size()\
      \ - 2; i; --i) { kout << ch.up[i] << \"\\n\"; }\n    }\n\n    return 0;\n}\n"
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
  path: verify/yosupo_geometry/static_convex_hull_1.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.37267271899986554
    environment: g++
    memory: 4.252
    name: all_same_00
    status: AC
  - elapsed: 0.36657109899988427
    environment: g++
    memory: 4.564
    name: all_same_01
    status: AC
  - elapsed: 0.002293387999998231
    environment: g++
    memory: 3.8
    name: example_00
    status: AC
  - elapsed: 0.002146777000007205
    environment: g++
    memory: 3.784
    name: example_01
    status: AC
  - elapsed: 0.6684960630000205
    environment: g++
    memory: 64.556
    name: max_ans_00
    status: AC
  - elapsed: 0.5766937369999141
    environment: g++
    memory: 36.744
    name: max_colinear_00
    status: AC
  - elapsed: 0.5790315120000287
    environment: g++
    memory: 36.716
    name: max_colinear_01
    status: AC
  - elapsed: 0.6206482739999046
    environment: g++
    memory: 36.716
    name: max_random_00
    status: AC
  - elapsed: 0.5293990909999593
    environment: g++
    memory: 36.704
    name: max_random_01
    status: AC
  - elapsed: 0.579893249999941
    environment: g++
    memory: 36.788
    name: max_random_02
    status: AC
  - elapsed: 0.6002540800000133
    environment: g++
    memory: 36.716
    name: max_random_03
    status: AC
  - elapsed: 0.6201217349998842
    environment: g++
    memory: 36.684
    name: max_random_04
    status: AC
  - elapsed: 0.5276603320000959
    environment: g++
    memory: 36.716
    name: max_random_05
    status: AC
  - elapsed: 0.5765046670001084
    environment: g++
    memory: 36.752
    name: max_random_06
    status: AC
  - elapsed: 0.5947156659999564
    environment: g++
    memory: 36.792
    name: max_random_07
    status: AC
  - elapsed: 0.6836041340000065
    environment: g++
    memory: 49.46
    name: near_circle_00
    status: AC
  - elapsed: 0.6670191549999345
    environment: g++
    memory: 49.34
    name: near_circle_01
    status: AC
  - elapsed: 0.5822176770000169
    environment: g++
    memory: 4.072
    name: small_random_00
    status: AC
  - elapsed: 0.4774748259999342
    environment: g++
    memory: 4.096
    name: small_random_01
    status: AC
  - elapsed: 0.49847707200001423
    environment: g++
    memory: 3.924
    name: small_random_02
    status: AC
  - elapsed: 0.5158229070000289
    environment: g++
    memory: 3.852
    name: small_random_03
    status: AC
  - elapsed: 0.5833121460000257
    environment: g++
    memory: 4.072
    name: small_random_04
    status: AC
  - elapsed: 0.47582156699991174
    environment: g++
    memory: 4.092
    name: small_random_05
    status: AC
  - elapsed: 0.4969259299998612
    environment: g++
    memory: 4.04
    name: small_random_06
    status: AC
  - elapsed: 0.5048146370002087
    environment: g++
    memory: 4.032
    name: small_random_07
    status: AC
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_1.test.cpp
layout: document
---
