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
  - elapsed: 0.35770982100000026
    environment: g++
    memory: 4.252
    name: all_same_00
    status: AC
  - elapsed: 0.3486370669999985
    environment: g++
    memory: 4.668
    name: all_same_01
    status: AC
  - elapsed: 0.002600336000000425
    environment: g++
    memory: 3.816
    name: example_00
    status: AC
  - elapsed: 0.0021761960000006297
    environment: g++
    memory: 3.612
    name: example_01
    status: AC
  - elapsed: 0.657486580000004
    environment: g++
    memory: 64.224
    name: max_ans_00
    status: AC
  - elapsed: 0.541596509999998
    environment: g++
    memory: 36.716
    name: max_colinear_00
    status: AC
  - elapsed: 0.5409928920000056
    environment: g++
    memory: 36.752
    name: max_colinear_01
    status: AC
  - elapsed: 0.5820166459999996
    environment: g++
    memory: 36.792
    name: max_random_00
    status: AC
  - elapsed: 0.49492000000000047
    environment: g++
    memory: 36.78
    name: max_random_01
    status: AC
  - elapsed: 0.5407666719999966
    environment: g++
    memory: 36.756
    name: max_random_02
    status: AC
  - elapsed: 0.5580057190000005
    environment: g++
    memory: 36.788
    name: max_random_03
    status: AC
  - elapsed: 0.5835289310000036
    environment: g++
    memory: 36.748
    name: max_random_04
    status: AC
  - elapsed: 0.4925594480000015
    environment: g++
    memory: 36.708
    name: max_random_05
    status: AC
  - elapsed: 0.5411990579999966
    environment: g++
    memory: 36.748
    name: max_random_06
    status: AC
  - elapsed: 0.5573650180000058
    environment: g++
    memory: 36.7
    name: max_random_07
    status: AC
  - elapsed: 0.6368193790000021
    environment: g++
    memory: 49.372
    name: near_circle_00
    status: AC
  - elapsed: 0.636804570999999
    environment: g++
    memory: 49.44
    name: near_circle_01
    status: AC
  - elapsed: 0.5890361330000076
    environment: g++
    memory: 4.028
    name: small_random_00
    status: AC
  - elapsed: 0.47033197400000404
    environment: g++
    memory: 3.924
    name: small_random_01
    status: AC
  - elapsed: 0.4919028240000074
    environment: g++
    memory: 4.084
    name: small_random_02
    status: AC
  - elapsed: 0.49892005200000256
    environment: g++
    memory: 3.876
    name: small_random_03
    status: AC
  - elapsed: 0.5874736589999969
    environment: g++
    memory: 4.02
    name: small_random_04
    status: AC
  - elapsed: 0.4709706689999962
    environment: g++
    memory: 4.064
    name: small_random_05
    status: AC
  - elapsed: 0.49219532300000424
    environment: g++
    memory: 4.02
    name: small_random_06
    status: AC
  - elapsed: 0.5004767700000059
    environment: g++
    memory: 4.028
    name: small_random_07
    status: AC
  timestamp: '2026-09-21 18:50:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull.test.cpp
layout: document
---
