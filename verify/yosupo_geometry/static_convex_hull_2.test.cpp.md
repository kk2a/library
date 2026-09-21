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
  - elapsed: 0.3563210570000024
    environment: g++
    memory: 4.288
    name: all_same_00
    status: AC
  - elapsed: 0.3490043070000013
    environment: g++
    memory: 4.66
    name: all_same_01
    status: AC
  - elapsed: 0.002256395999992833
    environment: g++
    memory: 3.796
    name: example_00
    status: AC
  - elapsed: 0.002174498000002245
    environment: g++
    memory: 3.84
    name: example_01
    status: AC
  - elapsed: 0.6896987200000098
    environment: g++
    memory: 64.564
    name: max_ans_00
    status: AC
  - elapsed: 0.5688808320000049
    environment: g++
    memory: 36.72
    name: max_colinear_00
    status: AC
  - elapsed: 0.5672431849999953
    environment: g++
    memory: 36.564
    name: max_colinear_01
    status: AC
  - elapsed: 0.6111028720000036
    environment: g++
    memory: 36.788
    name: max_random_00
    status: AC
  - elapsed: 0.5047902630000038
    environment: g++
    memory: 36.788
    name: max_random_01
    status: AC
  - elapsed: 0.5700238109999987
    environment: g++
    memory: 36.716
    name: max_random_02
    status: AC
  - elapsed: 0.5879060219999985
    environment: g++
    memory: 36.744
    name: max_random_03
    status: AC
  - elapsed: 0.6096505699999994
    environment: g++
    memory: 36.784
    name: max_random_04
    status: AC
  - elapsed: 0.5032367820000019
    environment: g++
    memory: 36.716
    name: max_random_05
    status: AC
  - elapsed: 0.5687981829999984
    environment: g++
    memory: 36.716
    name: max_random_06
    status: AC
  - elapsed: 0.5889843060000004
    environment: g++
    memory: 36.692
    name: max_random_07
    status: AC
  - elapsed: 0.6726137710000017
    environment: g++
    memory: 49.392
    name: near_circle_00
    status: AC
  - elapsed: 0.6719060249999984
    environment: g++
    memory: 49.324
    name: near_circle_01
    status: AC
  - elapsed: 0.6079946130000025
    environment: g++
    memory: 4.084
    name: small_random_00
    status: AC
  - elapsed: 0.48747445500001163
    environment: g++
    memory: 4.02
    name: small_random_01
    status: AC
  - elapsed: 0.5117338429999876
    environment: g++
    memory: 4.068
    name: small_random_02
    status: AC
  - elapsed: 0.5169127349999911
    environment: g++
    memory: 3.88
    name: small_random_03
    status: AC
  - elapsed: 0.6074346750000075
    environment: g++
    memory: 4.048
    name: small_random_04
    status: AC
  - elapsed: 0.49290525700000387
    environment: g++
    memory: 4.06
    name: small_random_05
    status: AC
  - elapsed: 0.5097750810000008
    environment: g++
    memory: 4.028
    name: small_random_06
    status: AC
  - elapsed: 0.5207757510000022
    environment: g++
    memory: 4.088
    name: small_random_07
    status: AC
  timestamp: '2026-09-21 19:50:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_2.test.cpp
layout: document
---
