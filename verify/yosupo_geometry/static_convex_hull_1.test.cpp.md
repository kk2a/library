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
      \ {\n    int t;\n    kin >> t;\n    rep (t) {\n        int n;\n        kin >>\
      \ n;\n        vc<kk2::Point<i64>> p(n);\n        kin >> p;\n        kk2::StaticConvexHull\
      \ ch(p);\n        ch.build();\n\n        if (n == 0) {\n            kout <<\
      \ 0 << \"\\n\";\n            continue;\n        }\n\n        if (ch.up.size()\
      \ == 1u) {\n            kout << 1 << \"\\n\";\n            kout << ch.up[0]\
      \ << \"\\n\";\n            continue;\n        }\n\n        kout << ch.up.size()\
      \ + ch.dw.size() - 2 << \"\\n\";\n        for (int i = 0; i < (int)ch.dw.size();\
      \ ++i) {\n            kout << ch.dw[i] << \"\\n\";\n        }\n        for (int\
      \ i = (int)ch.up.size() - 2; i; --i) {\n            kout << ch.up[i] << \"\\\
      n\";\n        }\n    }\n\n    return 0;\n}\n"
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
  - elapsed: 0.3649125260000119
    environment: g++
    memory: 4.22
    name: all_same_00
    status: AC
  - elapsed: 0.3559644690000141
    environment: g++
    memory: 4.476
    name: all_same_01
    status: AC
  - elapsed: 0.0022966750000250613
    environment: g++
    memory: 3.804
    name: example_00
    status: AC
  - elapsed: 0.002111184999989746
    environment: g++
    memory: 3.816
    name: example_01
    status: AC
  - elapsed: 0.6596894299999576
    environment: g++
    memory: 64.292
    name: max_ans_00
    status: AC
  - elapsed: 0.5673828210000238
    environment: g++
    memory: 36.716
    name: max_colinear_00
    status: AC
  - elapsed: 0.5635483879999583
    environment: g++
    memory: 36.788
    name: max_colinear_01
    status: AC
  - elapsed: 0.6109292610000239
    environment: g++
    memory: 36.72
    name: max_random_00
    status: AC
  - elapsed: 0.5282675919999065
    environment: g++
    memory: 36.788
    name: max_random_01
    status: AC
  - elapsed: 0.5712915230000135
    environment: g++
    memory: 36.732
    name: max_random_02
    status: AC
  - elapsed: 0.5871163929999739
    environment: g++
    memory: 36.78
    name: max_random_03
    status: AC
  - elapsed: 0.6103106450000269
    environment: g++
    memory: 36.788
    name: max_random_04
    status: AC
  - elapsed: 0.5260362369999712
    environment: g++
    memory: 36.716
    name: max_random_05
    status: AC
  - elapsed: 0.5654510699999946
    environment: g++
    memory: 36.628
    name: max_random_06
    status: AC
  - elapsed: 0.5883963539999968
    environment: g++
    memory: 36.716
    name: max_random_07
    status: AC
  - elapsed: 0.6560977279999634
    environment: g++
    memory: 49.344
    name: near_circle_00
    status: AC
  - elapsed: 0.6527385389999836
    environment: g++
    memory: 49.44
    name: near_circle_01
    status: AC
  - elapsed: 0.5725918359999014
    environment: g++
    memory: 4.02
    name: small_random_00
    status: AC
  - elapsed: 0.4662669949999554
    environment: g++
    memory: 4.064
    name: small_random_01
    status: AC
  - elapsed: 0.4870825440000317
    environment: g++
    memory: 4.056
    name: small_random_02
    status: AC
  - elapsed: 0.49201635299993995
    environment: g++
    memory: 4.064
    name: small_random_03
    status: AC
  - elapsed: 0.5727033000000574
    environment: g++
    memory: 4.028
    name: small_random_04
    status: AC
  - elapsed: 0.46666690799997923
    environment: g++
    memory: 4.064
    name: small_random_05
    status: AC
  - elapsed: 0.4874926869999854
    environment: g++
    memory: 3.876
    name: small_random_06
    status: AC
  - elapsed: 0.4943291119999458
    environment: g++
    memory: 4.072
    name: small_random_07
    status: AC
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_1.test.cpp
layout: document
---
