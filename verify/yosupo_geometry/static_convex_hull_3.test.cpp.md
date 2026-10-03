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
      \ + ch.dw.size() - 2 << \"\\n\";\n        vc<kk2::Point<i64>> res(ch.up.size()\
      \ + ch.dw.size() - 2);\n        rep(i, n) {\n            if (ch.idx_up[i] >\
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
  - elapsed: 0.25092074200000525
    environment: g++
    memory: 4.296
    name: all_same_00
    status: AC
  - elapsed: 0.2466512190000003
    environment: g++
    memory: 4.564
    name: all_same_01
    status: AC
  - elapsed: 0.001620588999969641
    environment: g++
    memory: 3.864
    name: example_00
    status: AC
  - elapsed: 0.0016443409999737923
    environment: g++
    memory: 3.92
    name: example_01
    status: AC
  - elapsed: 0.4639766390000091
    environment: g++
    memory: 64.616
    name: max_ans_00
    status: AC
  - elapsed: 0.37517605099998264
    environment: g++
    memory: 36.592
    name: max_colinear_00
    status: AC
  - elapsed: 0.37159023699996396
    environment: g++
    memory: 36.784
    name: max_colinear_01
    status: AC
  - elapsed: 0.40003616199999215
    environment: g++
    memory: 36.848
    name: max_random_00
    status: AC
  - elapsed: 0.34652478200001724
    environment: g++
    memory: 36.84
    name: max_random_01
    status: AC
  - elapsed: 0.36773088699999334
    environment: g++
    memory: 36.84
    name: max_random_02
    status: AC
  - elapsed: 0.37977192900001455
    environment: g++
    memory: 36.852
    name: max_random_03
    status: AC
  - elapsed: 0.4007098779999865
    environment: g++
    memory: 36.856
    name: max_random_04
    status: AC
  - elapsed: 0.3418581870000139
    environment: g++
    memory: 36.852
    name: max_random_05
    status: AC
  - elapsed: 0.36772429799998463
    environment: g++
    memory: 36.744
    name: max_random_06
    status: AC
  - elapsed: 0.3809167690000095
    environment: g++
    memory: 36.84
    name: max_random_07
    status: AC
  - elapsed: 0.4534022309999841
    environment: g++
    memory: 49.4
    name: near_circle_00
    status: AC
  - elapsed: 0.44975534500002823
    environment: g++
    memory: 49.508
    name: near_circle_01
    status: AC
  - elapsed: 0.41229700899998534
    environment: g++
    memory: 4.164
    name: small_random_00
    status: AC
  - elapsed: 0.32573596299999963
    environment: g++
    memory: 4.164
    name: small_random_01
    status: AC
  - elapsed: 0.3399480730000164
    environment: g++
    memory: 4.12
    name: small_random_02
    status: AC
  - elapsed: 0.34503007200004276
    environment: g++
    memory: 4.076
    name: small_random_03
    status: AC
  - elapsed: 0.42027619499998536
    environment: g++
    memory: 4.136
    name: small_random_04
    status: AC
  - elapsed: 0.32285543900002267
    environment: g++
    memory: 4.124
    name: small_random_05
    status: AC
  - elapsed: 0.33948248799998737
    environment: g++
    memory: 4.136
    name: small_random_06
    status: AC
  - elapsed: 0.34326184000002513
    environment: g++
    memory: 4.156
    name: small_random_07
    status: AC
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_3.test.cpp
layout: document
---
