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
  - elapsed: 0.3642699130000011
    environment: g++
    memory: 4.288
    name: all_same_00
    status: AC
  - elapsed: 0.35486715700000104
    environment: g++
    memory: 4.664
    name: all_same_01
    status: AC
  - elapsed: 0.0021535350000050357
    environment: g++
    memory: 3.804
    name: example_00
    status: AC
  - elapsed: 0.002179263000002152
    environment: g++
    memory: 3.668
    name: example_01
    status: AC
  - elapsed: 0.6604583579999996
    environment: g++
    memory: 64.564
    name: max_ans_00
    status: AC
  - elapsed: 0.5656969180000004
    environment: g++
    memory: 36.792
    name: max_colinear_00
    status: AC
  - elapsed: 0.5607943290000037
    environment: g++
    memory: 36.788
    name: max_colinear_01
    status: AC
  - elapsed: 0.6083723420000098
    environment: g++
    memory: 36.792
    name: max_random_00
    status: AC
  - elapsed: 0.514479190000003
    environment: g++
    memory: 36.744
    name: max_random_01
    status: AC
  - elapsed: 0.5655863409999995
    environment: g++
    memory: 36.716
    name: max_random_02
    status: AC
  - elapsed: 0.5825868940000021
    environment: g++
    memory: 36.792
    name: max_random_03
    status: AC
  - elapsed: 0.6045196379999993
    environment: g++
    memory: 36.792
    name: max_random_04
    status: AC
  - elapsed: 0.5124083780000035
    environment: g++
    memory: 36.7
    name: max_random_05
    status: AC
  - elapsed: 0.5637362030000048
    environment: g++
    memory: 36.784
    name: max_random_06
    status: AC
  - elapsed: 0.5831022890000099
    environment: g++
    memory: 36.72
    name: max_random_07
    status: AC
  - elapsed: 0.6516162919999999
    environment: g++
    memory: 49.432
    name: near_circle_00
    status: AC
  - elapsed: 0.6477536320000041
    environment: g++
    memory: 49.344
    name: near_circle_01
    status: AC
  - elapsed: 0.5700172949999995
    environment: g++
    memory: 4.056
    name: small_random_00
    status: AC
  - elapsed: 0.46501236499999266
    environment: g++
    memory: 4.072
    name: small_random_01
    status: AC
  - elapsed: 0.4835851400000024
    environment: g++
    memory: 4.072
    name: small_random_02
    status: AC
  - elapsed: 0.4929706239999945
    environment: g++
    memory: 3.876
    name: small_random_03
    status: AC
  - elapsed: 0.5687074349999932
    environment: g++
    memory: 4.072
    name: small_random_04
    status: AC
  - elapsed: 0.4664968420000122
    environment: g++
    memory: 4.072
    name: small_random_05
    status: AC
  - elapsed: 0.4844709289999969
    environment: g++
    memory: 4.048
    name: small_random_06
    status: AC
  - elapsed: 0.4907316670000057
    environment: g++
    memory: 4.084
    name: small_random_07
    status: AC
  timestamp: '2026-09-21 18:50:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_1.test.cpp
layout: document
---
