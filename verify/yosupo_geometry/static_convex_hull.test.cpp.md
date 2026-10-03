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
      \n#include \"../../geometry/static_convex_hull.hpp\"\n\n#include \"../../geometry/point.hpp\"\
      \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
      \ {\n    int t;\n    kin >> t;\n    rep(t) {\n        int n;\n        kin >>\
      \ n;\n        vc<kk2::Point<i64>> p(n);\n        kin >> p;\n        kk2::StaticConvexHull\
      \ ch(p);\n        ch.build();\n        auto hull = ch.hull;\n        kout <<\
      \ ch.hull.size() << \"\\n\";\n        for (auto &q : ch.hull) kout << q << \"\
      \\n\";\n    }\n\n    return 0;\n}\n"
    name: default
  - code: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/resolver.py\"\
      , line 290, in resolve\n    bundled_code = language.bundle(path, basedir=basedir)\n\
      \                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus.py\"\
      , line 243, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 478, in update\n    self.update(\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 478, in update\n    self.update(\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 354, in update\n    raise BundleErrorAt(\ncompetitive_verifier.oj.languages.cplusplus_bundle.BundleErrorAt:\
      \ geometry/point.hpp: line 4: #pragma once found in an include guard with #ifndef\n"
    name: bundle error
  isFailed: false
  isVerificationFile: true
  path: verify/yosupo_geometry/static_convex_hull.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.4075595809999868
    environment: g++
    memory: 4.28
    name: all_same_00
    status: AC
  - elapsed: 0.39734102100010205
    environment: g++
    memory: 4.656
    name: all_same_01
    status: AC
  - elapsed: 0.002522762000012335
    environment: g++
    memory: 3.808
    name: example_00
    status: AC
  - elapsed: 0.0023488519999546043
    environment: g++
    memory: 3.808
    name: example_01
    status: AC
  - elapsed: 0.741639350000014
    environment: g++
    memory: 64.584
    name: max_ans_00
    status: AC
  - elapsed: 0.6235566629999312
    environment: g++
    memory: 36.788
    name: max_colinear_00
    status: AC
  - elapsed: 0.6208280710000054
    environment: g++
    memory: 36.788
    name: max_colinear_01
    status: AC
  - elapsed: 0.6732171050000488
    environment: g++
    memory: 36.716
    name: max_random_00
    status: AC
  - elapsed: 0.5775051389999817
    environment: g++
    memory: 36.78
    name: max_random_01
    status: AC
  - elapsed: 0.623868499000082
    environment: g++
    memory: 36.792
    name: max_random_02
    status: AC
  - elapsed: 0.6433217140000806
    environment: g++
    memory: 36.792
    name: max_random_03
    status: AC
  - elapsed: 0.6746966480000083
    environment: g++
    memory: 36.788
    name: max_random_04
    status: AC
  - elapsed: 0.5736813120000761
    environment: g++
    memory: 36.788
    name: max_random_05
    status: AC
  - elapsed: 0.6256541430000198
    environment: g++
    memory: 36.744
    name: max_random_06
    status: AC
  - elapsed: 0.6480561299999863
    environment: g++
    memory: 36.564
    name: max_random_07
    status: AC
  - elapsed: 0.7347721130000764
    environment: g++
    memory: 49.36
    name: near_circle_00
    status: AC
  - elapsed: 0.7302296499999557
    environment: g++
    memory: 49.356
    name: near_circle_01
    status: AC
  - elapsed: 0.6491820400000279
    environment: g++
    memory: 4.0
    name: small_random_00
    status: AC
  - elapsed: 0.5153553840000313
    environment: g++
    memory: 4.08
    name: small_random_01
    status: AC
  - elapsed: 0.5387470480000047
    environment: g++
    memory: 4.064
    name: small_random_02
    status: AC
  - elapsed: 0.5471017449999636
    environment: g++
    memory: 4.072
    name: small_random_03
    status: AC
  - elapsed: 0.6489881999999625
    environment: g++
    memory: 4.08
    name: small_random_04
    status: AC
  - elapsed: 0.5161708809999936
    environment: g++
    memory: 4.056
    name: small_random_05
    status: AC
  - elapsed: 0.5401492469999312
    environment: g++
    memory: 3.996
    name: small_random_06
    status: AC
  - elapsed: 0.5472317229999817
    environment: g++
    memory: 3.872
    name: small_random_07
    status: AC
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull.test.cpp
layout: document
---
