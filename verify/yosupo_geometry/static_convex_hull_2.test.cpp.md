---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/static_convex_hull
    links:
    - https://judge.yosupo.jp/problem/static_convex_hull
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_convex_hull\n\
      \n#include \"../../geometry/point.hpp\"\n#include \"../../geometry/static_convex_hull.hpp\"\
      \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
      \ {\n    int t;\n    kin >> t;\n    rep (t) {\n        int n;\n        kin >>\
      \ n;\n        vc<kk2::Point<i64>> p(n);\n        kin >> p;\n        kk2::StaticConvexHull\
      \ ch(p);\n        ch.build();\n\n        kout << ch.hull.size() << \"\\n\";\n\
      \        vc<kk2::Point<i64>> res(ch.hull.size());\n        rep (i, n) {\n  \
      \          if (ch.idx_hull[i] != -1) res[ch.idx_hull[i]] = p[i];\n        }\n\
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
  - elapsed: 0.36119324300000244
    environment: g++
    memory: 4.288
    name: all_same_00
    status: AC
  - elapsed: 0.34990220199998134
    environment: g++
    memory: 4.656
    name: all_same_01
    status: AC
  - elapsed: 0.0024107609999930446
    environment: g++
    memory: 3.668
    name: example_00
    status: AC
  - elapsed: 0.002261500000003025
    environment: g++
    memory: 3.624
    name: example_01
    status: AC
  - elapsed: 0.7003207539999892
    environment: g++
    memory: 64.556
    name: max_ans_00
    status: AC
  - elapsed: 0.5643039509999994
    environment: g++
    memory: 36.788
    name: max_colinear_00
    status: AC
  - elapsed: 0.562503300000003
    environment: g++
    memory: 36.788
    name: max_colinear_01
    status: AC
  - elapsed: 0.6178435299999876
    environment: g++
    memory: 36.716
    name: max_random_00
    status: AC
  - elapsed: 0.5103000839999936
    environment: g++
    memory: 36.784
    name: max_random_01
    status: AC
  - elapsed: 0.569891766000012
    environment: g++
    memory: 36.744
    name: max_random_02
    status: AC
  - elapsed: 0.5925137079999843
    environment: g++
    memory: 36.708
    name: max_random_03
    status: AC
  - elapsed: 0.6143869310000127
    environment: g++
    memory: 36.788
    name: max_random_04
    status: AC
  - elapsed: 0.5040203509999799
    environment: g++
    memory: 36.752
    name: max_random_05
    status: AC
  - elapsed: 0.5686575379999965
    environment: g++
    memory: 36.708
    name: max_random_06
    status: AC
  - elapsed: 0.5932436850000045
    environment: g++
    memory: 36.716
    name: max_random_07
    status: AC
  - elapsed: 0.6747129789999917
    environment: g++
    memory: 49.356
    name: near_circle_00
    status: AC
  - elapsed: 0.6742831199999841
    environment: g++
    memory: 49.36
    name: near_circle_01
    status: AC
  - elapsed: 0.6076989400000059
    environment: g++
    memory: 4.076
    name: small_random_00
    status: AC
  - elapsed: 0.4905174010000053
    environment: g++
    memory: 3.924
    name: small_random_01
    status: AC
  - elapsed: 0.5080389990000072
    environment: g++
    memory: 4.064
    name: small_random_02
    status: AC
  - elapsed: 0.5194517829999938
    environment: g++
    memory: 3.876
    name: small_random_03
    status: AC
  - elapsed: 0.6112959770000259
    environment: g++
    memory: 3.924
    name: small_random_04
    status: AC
  - elapsed: 0.48813636799999927
    environment: g++
    memory: 4.036
    name: small_random_05
    status: AC
  - elapsed: 0.5111305490000007
    environment: g++
    memory: 4.028
    name: small_random_06
    status: AC
  - elapsed: 0.5165384750000044
    environment: g++
    memory: 4.084
    name: small_random_07
    status: AC
  timestamp: '2026-09-07 22:25:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_2.test.cpp
layout: document
---
