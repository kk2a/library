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
  - elapsed: 0.4257682439999826
    environment: g++
    memory: 4.236
    name: all_same_00
    status: AC
  - elapsed: 0.43093856299992694
    environment: g++
    memory: 4.66
    name: all_same_01
    status: AC
  - elapsed: 0.0026467940000429735
    environment: g++
    memory: 3.816
    name: example_00
    status: AC
  - elapsed: 0.002499041999953988
    environment: g++
    memory: 3.816
    name: example_01
    status: AC
  - elapsed: 0.7707872359999328
    environment: g++
    memory: 64.616
    name: max_ans_00
    status: AC
  - elapsed: 0.6634475159999056
    environment: g++
    memory: 36.788
    name: max_colinear_00
    status: AC
  - elapsed: 0.6660294130000466
    environment: g++
    memory: 36.788
    name: max_colinear_01
    status: AC
  - elapsed: 0.7133723549999331
    environment: g++
    memory: 36.788
    name: max_random_00
    status: AC
  - elapsed: 0.5906116679999514
    environment: g++
    memory: 36.712
    name: max_random_01
    status: AC
  - elapsed: 0.6569412599999396
    environment: g++
    memory: 36.78
    name: max_random_02
    status: AC
  - elapsed: 0.6880228700000544
    environment: g++
    memory: 36.748
    name: max_random_03
    status: AC
  - elapsed: 0.7136928550000903
    environment: g++
    memory: 36.692
    name: max_random_04
    status: AC
  - elapsed: 0.5877054090000229
    environment: g++
    memory: 36.792
    name: max_random_05
    status: AC
  - elapsed: 0.6575147610000158
    environment: g++
    memory: 36.788
    name: max_random_06
    status: AC
  - elapsed: 0.6866582609999341
    environment: g++
    memory: 36.704
    name: max_random_07
    status: AC
  - elapsed: 0.7645039559999987
    environment: g++
    memory: 49.368
    name: near_circle_00
    status: AC
  - elapsed: 0.7704393719999416
    environment: g++
    memory: 49.288
    name: near_circle_01
    status: AC
  - elapsed: 0.6534510389999468
    environment: g++
    memory: 4.072
    name: small_random_00
    status: AC
  - elapsed: 0.5196501049999824
    environment: g++
    memory: 4.056
    name: small_random_01
    status: AC
  - elapsed: 0.5412176610000188
    environment: g++
    memory: 4.068
    name: small_random_02
    status: AC
  - elapsed: 0.551387931000022
    environment: g++
    memory: 4.056
    name: small_random_03
    status: AC
  - elapsed: 0.6588069670000323
    environment: g++
    memory: 4.04
    name: small_random_04
    status: AC
  - elapsed: 0.518760129000043
    environment: g++
    memory: 4.068
    name: small_random_05
    status: AC
  - elapsed: 0.5457580690000441
    environment: g++
    memory: 4.068
    name: small_random_06
    status: AC
  - elapsed: 0.5505150300000423
    environment: g++
    memory: 4.02
    name: small_random_07
    status: AC
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_1.test.cpp
layout: document
---
