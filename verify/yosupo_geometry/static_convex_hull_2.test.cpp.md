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
  - elapsed: 0.35756687399998555
    environment: g++
    memory: 4.252
    name: all_same_00
    status: AC
  - elapsed: 0.3501152979999915
    environment: g++
    memory: 4.592
    name: all_same_01
    status: AC
  - elapsed: 0.0022219079999103997
    environment: g++
    memory: 3.816
    name: example_00
    status: AC
  - elapsed: 0.0022118769998087373
    environment: g++
    memory: 3.832
    name: example_01
    status: AC
  - elapsed: 0.6938671099999283
    environment: g++
    memory: 64.52
    name: max_ans_00
    status: AC
  - elapsed: 0.56410410400008
    environment: g++
    memory: 36.792
    name: max_colinear_00
    status: AC
  - elapsed: 0.5622575569998389
    environment: g++
    memory: 36.548
    name: max_colinear_01
    status: AC
  - elapsed: 0.6142026610000357
    environment: g++
    memory: 36.752
    name: max_random_00
    status: AC
  - elapsed: 0.5080789940000159
    environment: g++
    memory: 36.788
    name: max_random_01
    status: AC
  - elapsed: 0.5661319559999356
    environment: g++
    memory: 36.792
    name: max_random_02
    status: AC
  - elapsed: 0.5856186739999885
    environment: g++
    memory: 36.788
    name: max_random_03
    status: AC
  - elapsed: 0.620587925000109
    environment: g++
    memory: 36.612
    name: max_random_04
    status: AC
  - elapsed: 0.505757284000083
    environment: g++
    memory: 36.72
    name: max_random_05
    status: AC
  - elapsed: 0.5626508309999281
    environment: g++
    memory: 36.788
    name: max_random_06
    status: AC
  - elapsed: 0.5854783729998871
    environment: g++
    memory: 36.792
    name: max_random_07
    status: AC
  - elapsed: 0.6726457699999173
    environment: g++
    memory: 49.364
    name: near_circle_00
    status: AC
  - elapsed: 0.6743972330000361
    environment: g++
    memory: 49.436
    name: near_circle_01
    status: AC
  - elapsed: 0.5997088510000594
    environment: g++
    memory: 4.068
    name: small_random_00
    status: AC
  - elapsed: 0.4874075279999488
    environment: g++
    memory: 4.06
    name: small_random_01
    status: AC
  - elapsed: 0.5054597519999788
    environment: g++
    memory: 4.092
    name: small_random_02
    status: AC
  - elapsed: 0.5137556629999835
    environment: g++
    memory: 3.876
    name: small_random_03
    status: AC
  - elapsed: 0.6029844370000319
    environment: g++
    memory: 4.048
    name: small_random_04
    status: AC
  - elapsed: 0.48588602600011654
    environment: g++
    memory: 4.072
    name: small_random_05
    status: AC
  - elapsed: 0.5048133459999917
    environment: g++
    memory: 4.08
    name: small_random_06
    status: AC
  - elapsed: 0.5145421219999662
    environment: g++
    memory: 4.028
    name: small_random_07
    status: AC
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_2.test.cpp
layout: document
---
