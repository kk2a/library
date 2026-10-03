---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  dependencies:
  - files:
    - filename: argument_sort.hpp
      icon: LIBRARY_ALL_AC
      path: geometry/argument_sort.hpp
    - filename: point.hpp
      icon: LIBRARY_ALL_AC
      path: geometry/point.hpp
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
  - geometry/argument_sort.hpp
  - geometry/point.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/template.hpp
  - template/type_alias.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sort_points_by_argument\n\
      \n#include \"../../geometry/argument_sort.hpp\"\n#include \"../../geometry/point.hpp\"\
      \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
      \ {\n    int n;\n    kin >> n;\n    vc<kk2::Point<i64>> p(n);\n    kin >> p;\n\
      \    kk2::ArgumentSort<i64>().argument_sort(p);\n    rep(i, n) kout << p[i]\
      \ << \"\\n\";\n\n    return 0;\n}\n"
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
  path: verify/yosupo_geometry/arg_sort.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.32835805399997753
    environment: g++
    memory: 6.792
    name: all_same_00
    status: AC
  - elapsed: 0.35414151200006927
    environment: g++
    memory: 6.8
    name: all_same_01
    status: AC
  - elapsed: 0.3891286040000068
    environment: g++
    memory: 6.792
    name: all_same_02
    status: AC
  - elapsed: 0.002808614999935344
    environment: g++
    memory: 3.772
    name: example_00
    status: AC
  - elapsed: 0.33592182699999285
    environment: g++
    memory: 6.796
    name: half_same_00
    status: AC
  - elapsed: 0.34854319400005807
    environment: g++
    memory: 6.764
    name: half_same_01
    status: AC
  - elapsed: 0.36297726900011185
    environment: g++
    memory: 6.8
    name: half_same_02
    status: AC
  - elapsed: 0.3367163080000637
    environment: g++
    memory: 6.748
    name: max_random_00
    status: AC
  - elapsed: 0.3423413719999644
    environment: g++
    memory: 6.8
    name: max_random_01
    status: AC
  - elapsed: 0.34225261699998555
    environment: g++
    memory: 6.804
    name: max_random_02
    status: AC
  - elapsed: 0.34326247899991813
    environment: g++
    memory: 6.8
    name: near_arg_00
    status: AC
  - elapsed: 0.3457829720000518
    environment: g++
    memory: 6.8
    name: near_arg_01
    status: AC
  - elapsed: 0.3393608349999795
    environment: g++
    memory: 6.8
    name: near_arg_02
    status: AC
  - elapsed: 0.3383107879999443
    environment: g++
    memory: 6.756
    name: near_arg_shuffle_00
    status: AC
  - elapsed: 0.3441715829999339
    environment: g++
    memory: 6.792
    name: near_arg_shuffle_01
    status: AC
  - elapsed: 0.3409875129999591
    environment: g++
    memory: 6.792
    name: near_arg_shuffle_02
    status: AC
  - elapsed: 0.0029357440000694623
    environment: g++
    memory: 3.772
    name: only_x_axis_00
    status: AC
  - elapsed: 0.24095620900004633
    environment: g++
    memory: 5.668
    name: random_00
    status: AC
  - elapsed: 0.25127478599995356
    environment: g++
    memory: 5.992
    name: random_01
    status: AC
  - elapsed: 0.08458886699997947
    environment: g++
    memory: 4.38
    name: random_02
    status: AC
  - elapsed: 0.0029581249999637294
    environment: g++
    memory: 3.776
    name: small_all_00
    status: AC
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/arg_sort.test.cpp
layout: document
---
