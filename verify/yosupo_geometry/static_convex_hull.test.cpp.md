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
  - elapsed: 0.3571363210000982
    environment: g++
    memory: 4.248
    name: all_same_00
    status: AC
  - elapsed: 0.34948169500012227
    environment: g++
    memory: 4.688
    name: all_same_01
    status: AC
  - elapsed: 0.002203062000035061
    environment: g++
    memory: 3.816
    name: example_00
    status: AC
  - elapsed: 0.002115158000151496
    environment: g++
    memory: 3.836
    name: example_01
    status: AC
  - elapsed: 0.6575377689998732
    environment: g++
    memory: 64.288
    name: max_ans_00
    status: AC
  - elapsed: 0.5482653169999594
    environment: g++
    memory: 36.696
    name: max_colinear_00
    status: AC
  - elapsed: 0.540915842000004
    environment: g++
    memory: 36.624
    name: max_colinear_01
    status: AC
  - elapsed: 0.5873156810000637
    environment: g++
    memory: 36.72
    name: max_random_00
    status: AC
  - elapsed: 0.4995359260001351
    environment: g++
    memory: 36.788
    name: max_random_01
    status: AC
  - elapsed: 0.5496752090000427
    environment: g++
    memory: 36.788
    name: max_random_02
    status: AC
  - elapsed: 0.5696321110001463
    environment: g++
    memory: 36.7
    name: max_random_03
    status: AC
  - elapsed: 0.5906428230000529
    environment: g++
    memory: 36.792
    name: max_random_04
    status: AC
  - elapsed: 0.49726546000010785
    environment: g++
    memory: 36.788
    name: max_random_05
    status: AC
  - elapsed: 0.5486883169999146
    environment: g++
    memory: 36.696
    name: max_random_06
    status: AC
  - elapsed: 0.5700627310000073
    environment: g++
    memory: 36.788
    name: max_random_07
    status: AC
  - elapsed: 0.6445649629999934
    environment: g++
    memory: 49.452
    name: near_circle_00
    status: AC
  - elapsed: 0.6480451550000907
    environment: g++
    memory: 49.436
    name: near_circle_01
    status: AC
  - elapsed: 0.5919920930000444
    environment: g++
    memory: 4.068
    name: small_random_00
    status: AC
  - elapsed: 0.47722638799996275
    environment: g++
    memory: 4.064
    name: small_random_01
    status: AC
  - elapsed: 0.4963545860000522
    environment: g++
    memory: 3.996
    name: small_random_02
    status: AC
  - elapsed: 0.5018342180001127
    environment: g++
    memory: 4.036
    name: small_random_03
    status: AC
  - elapsed: 0.5903185869999561
    environment: g++
    memory: 4.096
    name: small_random_04
    status: AC
  - elapsed: 0.4787031019998267
    environment: g++
    memory: 3.924
    name: small_random_05
    status: AC
  - elapsed: 0.49839984799996273
    environment: g++
    memory: 3.872
    name: small_random_06
    status: AC
  - elapsed: 0.5044210189998921
    environment: g++
    memory: 4.06
    name: small_random_07
    status: AC
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull.test.cpp
layout: document
---
