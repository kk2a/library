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
  - elapsed: 0.29327229499995155
    environment: g++
    memory: 6.796
    name: all_same_00
    status: AC
  - elapsed: 0.3167493939999986
    environment: g++
    memory: 6.76
    name: all_same_01
    status: AC
  - elapsed: 0.33151742799987005
    environment: g++
    memory: 6.76
    name: all_same_02
    status: AC
  - elapsed: 0.0025958050000554067
    environment: g++
    memory: 3.76
    name: example_00
    status: AC
  - elapsed: 0.30812839200007147
    environment: g++
    memory: 6.8
    name: half_same_00
    status: AC
  - elapsed: 0.3193666919999032
    environment: g++
    memory: 6.8
    name: half_same_01
    status: AC
  - elapsed: 0.3250922550000723
    environment: g++
    memory: 6.8
    name: half_same_02
    status: AC
  - elapsed: 0.31857983600002626
    environment: g++
    memory: 6.804
    name: max_random_00
    status: AC
  - elapsed: 0.32400049700004274
    environment: g++
    memory: 6.768
    name: max_random_01
    status: AC
  - elapsed: 0.3233874139998534
    environment: g++
    memory: 6.8
    name: max_random_02
    status: AC
  - elapsed: 0.3235717059999388
    environment: g++
    memory: 6.764
    name: near_arg_00
    status: AC
  - elapsed: 0.327413905999947
    environment: g++
    memory: 6.804
    name: near_arg_01
    status: AC
  - elapsed: 0.32012313700010964
    environment: g++
    memory: 6.8
    name: near_arg_02
    status: AC
  - elapsed: 0.32026824100012163
    environment: g++
    memory: 6.756
    name: near_arg_shuffle_00
    status: AC
  - elapsed: 0.32331290599995555
    environment: g++
    memory: 6.804
    name: near_arg_shuffle_01
    status: AC
  - elapsed: 0.3214698379999845
    environment: g++
    memory: 6.74
    name: near_arg_shuffle_02
    status: AC
  - elapsed: 0.002674917999911486
    environment: g++
    memory: 3.628
    name: only_x_axis_00
    status: AC
  - elapsed: 0.20039228899986483
    environment: g++
    memory: 5.668
    name: random_00
    status: AC
  - elapsed: 0.23896016300000156
    environment: g++
    memory: 6.024
    name: random_01
    status: AC
  - elapsed: 0.0803360329998668
    environment: g++
    memory: 4.388
    name: random_02
    status: AC
  - elapsed: 0.0026267279999956372
    environment: g++
    memory: 3.764
    name: small_all_00
    status: AC
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/arg_sort.test.cpp
layout: document
---
