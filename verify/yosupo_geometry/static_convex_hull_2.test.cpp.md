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
  - elapsed: 0.36327516499999035
    environment: g++
    memory: 4.288
    name: all_same_00
    status: AC
  - elapsed: 0.3557771770000073
    environment: g++
    memory: 4.668
    name: all_same_01
    status: AC
  - elapsed: 0.0022050269999880356
    environment: g++
    memory: 3.764
    name: example_00
    status: AC
  - elapsed: 0.0021040230000011206
    environment: g++
    memory: 3.764
    name: example_01
    status: AC
  - elapsed: 0.7000151860000017
    environment: g++
    memory: 64.288
    name: max_ans_00
    status: AC
  - elapsed: 0.5776183610000061
    environment: g++
    memory: 36.788
    name: max_colinear_00
    status: AC
  - elapsed: 0.573139891000011
    environment: g++
    memory: 36.792
    name: max_colinear_01
    status: AC
  - elapsed: 0.6196547830000014
    environment: g++
    memory: 36.788
    name: max_random_00
    status: AC
  - elapsed: 0.5107688380000042
    environment: g++
    memory: 36.72
    name: max_random_01
    status: AC
  - elapsed: 0.5765297730000043
    environment: g++
    memory: 36.716
    name: max_random_02
    status: AC
  - elapsed: 0.5935030169999891
    environment: g++
    memory: 36.788
    name: max_random_03
    status: AC
  - elapsed: 0.6173011090000102
    environment: g++
    memory: 36.788
    name: max_random_04
    status: AC
  - elapsed: 0.5075212689999944
    environment: g++
    memory: 36.716
    name: max_random_05
    status: AC
  - elapsed: 0.5739277419999951
    environment: g++
    memory: 36.788
    name: max_random_06
    status: AC
  - elapsed: 0.5932182810000057
    environment: g++
    memory: 36.716
    name: max_random_07
    status: AC
  - elapsed: 0.676461486000008
    environment: g++
    memory: 49.336
    name: near_circle_00
    status: AC
  - elapsed: 0.6744159069999967
    environment: g++
    memory: 49.44
    name: near_circle_01
    status: AC
  - elapsed: 0.6129742570000047
    environment: g++
    memory: 3.996
    name: small_random_00
    status: AC
  - elapsed: 0.4960570279999956
    environment: g++
    memory: 4.02
    name: small_random_01
    status: AC
  - elapsed: 0.5161314439999956
    environment: g++
    memory: 4.06
    name: small_random_02
    status: AC
  - elapsed: 0.5265707930000048
    environment: g++
    memory: 3.912
    name: small_random_03
    status: AC
  - elapsed: 0.6203270249999946
    environment: g++
    memory: 3.88
    name: small_random_04
    status: AC
  - elapsed: 0.4956188410000095
    environment: g++
    memory: 4.084
    name: small_random_05
    status: AC
  - elapsed: 0.5206531560000087
    environment: g++
    memory: 4.02
    name: small_random_06
    status: AC
  - elapsed: 0.5238941820000207
    environment: g++
    memory: 4.068
    name: small_random_07
    status: AC
  timestamp: '2026-10-11 18:25:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_2.test.cpp
layout: document
---
