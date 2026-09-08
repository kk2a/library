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
      \ ch(p);\n        ch.build();\n        auto hull = ch.hull;\n        kout <<\
      \ ch.hull.size() << \"\\n\";\n        for (auto &q : ch.hull) kout << q << \"\
      \\n\";\n    }\n\n    return 0;\n}\n"
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
  path: verify/yosupo_geometry/static_convex_hull.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.35629097000003185
    environment: g++
    memory: 4.288
    name: all_same_00
    status: AC
  - elapsed: 0.34781967100002475
    environment: g++
    memory: 4.664
    name: all_same_01
    status: AC
  - elapsed: 0.0024383130000842357
    environment: g++
    memory: 3.816
    name: example_00
    status: AC
  - elapsed: 0.002238808999891262
    environment: g++
    memory: 3.62
    name: example_01
    status: AC
  - elapsed: 0.6698774929999445
    environment: g++
    memory: 64.564
    name: max_ans_00
    status: AC
  - elapsed: 0.5587038239999629
    environment: g++
    memory: 36.696
    name: max_colinear_00
    status: AC
  - elapsed: 0.5555552650000664
    environment: g++
    memory: 36.712
    name: max_colinear_01
    status: AC
  - elapsed: 0.6055192190000298
    environment: g++
    memory: 36.712
    name: max_random_00
    status: AC
  - elapsed: 0.49507081600006586
    environment: g++
    memory: 36.716
    name: max_random_01
    status: AC
  - elapsed: 0.560944066999923
    environment: g++
    memory: 36.788
    name: max_random_02
    status: AC
  - elapsed: 0.5769112869999162
    environment: g++
    memory: 36.78
    name: max_random_03
    status: AC
  - elapsed: 0.6002420669999537
    environment: g++
    memory: 36.788
    name: max_random_04
    status: AC
  - elapsed: 0.50488572200004
    environment: g++
    memory: 36.788
    name: max_random_05
    status: AC
  - elapsed: 0.5592082100000653
    environment: g++
    memory: 36.788
    name: max_random_06
    status: AC
  - elapsed: 0.5767640500000653
    environment: g++
    memory: 36.748
    name: max_random_07
    status: AC
  - elapsed: 0.6562604439999404
    environment: g++
    memory: 49.368
    name: near_circle_00
    status: AC
  - elapsed: 0.6561737499999936
    environment: g++
    memory: 49.44
    name: near_circle_01
    status: AC
  - elapsed: 0.5896854219998886
    environment: g++
    memory: 4.048
    name: small_random_00
    status: AC
  - elapsed: 0.47343466600000284
    environment: g++
    memory: 4.06
    name: small_random_01
    status: AC
  - elapsed: 0.4968647290000945
    environment: g++
    memory: 4.028
    name: small_random_02
    status: AC
  - elapsed: 0.5026321139999936
    environment: g++
    memory: 4.028
    name: small_random_03
    status: AC
  - elapsed: 0.5881285709999702
    environment: g++
    memory: 4.032
    name: small_random_04
    status: AC
  - elapsed: 0.47685603399997945
    environment: g++
    memory: 4.068
    name: small_random_05
    status: AC
  - elapsed: 0.49686476199997287
    environment: g++
    memory: 3.996
    name: small_random_06
    status: AC
  - elapsed: 0.5023464140000442
    environment: g++
    memory: 3.876
    name: small_random_07
    status: AC
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull.test.cpp
layout: document
---
