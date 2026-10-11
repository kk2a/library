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
  - elapsed: 0.3582677839999917
    environment: g++
    memory: 4.236
    name: all_same_00
    status: AC
  - elapsed: 0.34990709800000275
    environment: g++
    memory: 4.648
    name: all_same_01
    status: AC
  - elapsed: 0.002282753000002913
    environment: g++
    memory: 3.772
    name: example_00
    status: AC
  - elapsed: 0.00212980700000287
    environment: g++
    memory: 3.792
    name: example_01
    status: AC
  - elapsed: 0.6546337579999886
    environment: g++
    memory: 64.204
    name: max_ans_00
    status: AC
  - elapsed: 0.5458523550000081
    environment: g++
    memory: 36.788
    name: max_colinear_00
    status: AC
  - elapsed: 0.5438853889999962
    environment: g++
    memory: 36.788
    name: max_colinear_01
    status: AC
  - elapsed: 0.5844524540000009
    environment: g++
    memory: 36.744
    name: max_random_00
    status: AC
  - elapsed: 0.516179293999997
    environment: g++
    memory: 36.788
    name: max_random_01
    status: AC
  - elapsed: 0.5413521100000054
    environment: g++
    memory: 36.788
    name: max_random_02
    status: AC
  - elapsed: 0.5615436960000011
    environment: g++
    memory: 36.704
    name: max_random_03
    status: AC
  - elapsed: 0.5843392530000102
    environment: g++
    memory: 36.784
    name: max_random_04
    status: AC
  - elapsed: 0.5133299670000042
    environment: g++
    memory: 36.788
    name: max_random_05
    status: AC
  - elapsed: 0.5412614459999929
    environment: g++
    memory: 36.692
    name: max_random_06
    status: AC
  - elapsed: 0.5597011060000057
    environment: g++
    memory: 36.792
    name: max_random_07
    status: AC
  - elapsed: 0.6367617829999972
    environment: g++
    memory: 49.408
    name: near_circle_00
    status: AC
  - elapsed: 0.6417931629999885
    environment: g++
    memory: 49.376
    name: near_circle_01
    status: AC
  - elapsed: 0.5829382579999987
    environment: g++
    memory: 3.852
    name: small_random_00
    status: AC
  - elapsed: 0.4692698530000001
    environment: g++
    memory: 4.072
    name: small_random_01
    status: AC
  - elapsed: 0.48821188799999504
    environment: g++
    memory: 3.984
    name: small_random_02
    status: AC
  - elapsed: 0.49395566900000176
    environment: g++
    memory: 3.852
    name: small_random_03
    status: AC
  - elapsed: 0.5830546610000056
    environment: g++
    memory: 3.876
    name: small_random_04
    status: AC
  - elapsed: 0.4733212400000042
    environment: g++
    memory: 4.044
    name: small_random_05
    status: AC
  - elapsed: 0.489368970000001
    environment: g++
    memory: 4.068
    name: small_random_06
    status: AC
  - elapsed: 0.5038847219999951
    environment: g++
    memory: 4.088
    name: small_random_07
    status: AC
  timestamp: '2026-10-11 18:25:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull.test.cpp
layout: document
---
