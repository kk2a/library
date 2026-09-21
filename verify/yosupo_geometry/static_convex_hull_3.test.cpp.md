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
  - elapsed: 0.354433727
    environment: g++
    memory: 4.276
    name: all_same_00
    status: AC
  - elapsed: 0.34646679099999744
    environment: g++
    memory: 4.636
    name: all_same_01
    status: AC
  - elapsed: 0.0022496509999996306
    environment: g++
    memory: 3.612
    name: example_00
    status: AC
  - elapsed: 0.002119827000001351
    environment: g++
    memory: 3.784
    name: example_01
    status: AC
  - elapsed: 0.6817663920000001
    environment: g++
    memory: 64.292
    name: max_ans_00
    status: AC
  - elapsed: 0.5705080909999936
    environment: g++
    memory: 36.78
    name: max_colinear_00
    status: AC
  - elapsed: 0.5662853329999962
    environment: g++
    memory: 36.784
    name: max_colinear_01
    status: AC
  - elapsed: 0.6076374059999949
    environment: g++
    memory: 36.788
    name: max_random_00
    status: AC
  - elapsed: 0.5128085589999927
    environment: g++
    memory: 36.78
    name: max_random_01
    status: AC
  - elapsed: 0.5694699999999955
    environment: g++
    memory: 36.792
    name: max_random_02
    status: AC
  - elapsed: 0.5856855259999918
    environment: g++
    memory: 36.712
    name: max_random_03
    status: AC
  - elapsed: 0.6058672940000065
    environment: g++
    memory: 36.62
    name: max_random_04
    status: AC
  - elapsed: 0.5106497390000015
    environment: g++
    memory: 36.788
    name: max_random_05
    status: AC
  - elapsed: 0.5689750680000003
    environment: g++
    memory: 36.716
    name: max_random_06
    status: AC
  - elapsed: 0.588112389999992
    environment: g++
    memory: 36.788
    name: max_random_07
    status: AC
  - elapsed: 0.6806221960000016
    environment: g++
    memory: 49.368
    name: near_circle_00
    status: AC
  - elapsed: 0.6604287050000011
    environment: g++
    memory: 49.444
    name: near_circle_01
    status: AC
  - elapsed: 0.5891125679999902
    environment: g++
    memory: 3.876
    name: small_random_00
    status: AC
  - elapsed: 0.4775695759999934
    environment: g++
    memory: 4.072
    name: small_random_01
    status: AC
  - elapsed: 0.5018779650000056
    environment: g++
    memory: 4.072
    name: small_random_02
    status: AC
  - elapsed: 0.504527042999996
    environment: g++
    memory: 4.052
    name: small_random_03
    status: AC
  - elapsed: 0.5879654430000016
    environment: g++
    memory: 3.872
    name: small_random_04
    status: AC
  - elapsed: 0.4843432370000045
    environment: g++
    memory: 4.052
    name: small_random_05
    status: AC
  - elapsed: 0.5066338080000037
    environment: g++
    memory: 4.072
    name: small_random_06
    status: AC
  - elapsed: 0.5064095130000084
    environment: g++
    memory: 4.092
    name: small_random_07
    status: AC
  timestamp: '2026-09-21 18:50:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/static_convex_hull_3.test.cpp
layout: document
---
