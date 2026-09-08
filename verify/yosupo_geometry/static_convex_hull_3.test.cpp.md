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
      \ + ch.dw.size() - 2 << \"\\n\";\n        vc<kk2::Point<i64>> res(ch.up.size()\
      \ + ch.dw.size() - 2);\n        rep (i, n) {\n            if (ch.idx_up[i] >\
      \ 0) res[ch.dw.size() + ch.up.size() - ch.idx_up[i] - 2] = p[i];\n         \
      \   if (ch.idx_dw[i] != -1) res[ch.idx_dw[i]] = p[i];\n        }\n        for\
      \ (auto &q : res) kout << q << \"\\n\";\n    }\n\n    return 0;\n}\n"
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
  path: verify/yosupo_geometry/static_convex_hull_3.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.35453150099999675
    environment: g++
    memory: 4.288
    name: all_same_00
    status: AC
  - elapsed: 0.34605067800001166
    environment: g++
    memory: 4.636
    name: all_same_01
    status: AC
  - elapsed: 0.002521497000003592
    environment: g++
    memory: 3.808
    name: example_00
    status: AC
  - elapsed: 0.002431610000002138
    environment: g++
    memory: 3.624
    name: example_01
    status: AC
  - elapsed: 0.6844328379999922
    environment: g++
    memory: 64.564
    name: max_ans_00
    status: AC
  - elapsed: 0.5602738970000019
    environment: g++
    memory: 36.712
    name: max_colinear_00
    status: AC
  - elapsed: 0.5589959570000076
    environment: g++
    memory: 36.748
    name: max_colinear_01
    status: AC
  - elapsed: 0.6119802169999957
    environment: g++
    memory: 36.788
    name: max_random_00
    status: AC
  - elapsed: 0.5114545330000055
    environment: g++
    memory: 36.752
    name: max_random_01
    status: AC
  - elapsed: 0.5612810400000114
    environment: g++
    memory: 36.716
    name: max_random_02
    status: AC
  - elapsed: 0.5756196480000142
    environment: g++
    memory: 36.788
    name: max_random_03
    status: AC
  - elapsed: 0.5988333739999803
    environment: g++
    memory: 36.756
    name: max_random_04
    status: AC
  - elapsed: 0.5093297459999917
    environment: g++
    memory: 36.792
    name: max_random_05
    status: AC
  - elapsed: 0.5634469830000057
    environment: g++
    memory: 36.72
    name: max_random_06
    status: AC
  - elapsed: 0.5781230199999925
    environment: g++
    memory: 36.788
    name: max_random_07
    status: AC
  - elapsed: 0.6583092490000126
    environment: g++
    memory: 49.352
    name: near_circle_00
    status: AC
  - elapsed: 0.6593638829999975
    environment: g++
    memory: 49.44
    name: near_circle_01
    status: AC
  - elapsed: 0.5894166029999894
    environment: g++
    memory: 4.096
    name: small_random_00
    status: AC
  - elapsed: 0.471668789000006
    environment: g++
    memory: 4.08
    name: small_random_01
    status: AC
  - elapsed: 0.49080568400000857
    environment: g++
    memory: 4.072
    name: small_random_02
    status: AC
  - elapsed: 0.4979150160000074
    environment: g++
    memory: 4.072
    name: small_random_03
    status: AC
  - elapsed: 0.5886241990000087
    environment: g++
    memory: 4.092
    name: small_random_04
    status: AC
  - elapsed: 0.47194743200000744
    environment: g++
    memory: 3.72
    name: small_random_05
    status: AC
  - elapsed: 0.4888764140000035
    environment: g++
    memory: 4.04
    name: small_random_06
    status: AC
  - elapsed: 0.5006846530000075
    environment: g++
    memory: 4.072
    name: small_random_07
    status: AC
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_3.test.cpp
layout: document
---
