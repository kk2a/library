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
  - elapsed: 0.2850556229999981
    environment: g++
    memory: 6.804
    name: all_same_00
    status: AC
  - elapsed: 0.30959318699999727
    environment: g++
    memory: 6.8
    name: all_same_01
    status: AC
  - elapsed: 0.3259645190000029
    environment: g++
    memory: 6.76
    name: all_same_02
    status: AC
  - elapsed: 0.00259494099999813
    environment: g++
    memory: 3.772
    name: example_00
    status: AC
  - elapsed: 0.3133288660000062
    environment: g++
    memory: 6.744
    name: half_same_00
    status: AC
  - elapsed: 0.34488383000000056
    environment: g++
    memory: 6.792
    name: half_same_01
    status: AC
  - elapsed: 0.32061700199999166
    environment: g++
    memory: 6.8
    name: half_same_02
    status: AC
  - elapsed: 0.3136397560000006
    environment: g++
    memory: 6.756
    name: max_random_00
    status: AC
  - elapsed: 0.3161137310000015
    environment: g++
    memory: 6.8
    name: max_random_01
    status: AC
  - elapsed: 0.3187914770000049
    environment: g++
    memory: 6.8
    name: max_random_02
    status: AC
  - elapsed: 0.3188822660000028
    environment: g++
    memory: 6.792
    name: near_arg_00
    status: AC
  - elapsed: 0.3200919999999883
    environment: g++
    memory: 6.804
    name: near_arg_01
    status: AC
  - elapsed: 0.3224130340000073
    environment: g++
    memory: 6.76
    name: near_arg_02
    status: AC
  - elapsed: 0.3120484770000047
    environment: g++
    memory: 6.8
    name: near_arg_shuffle_00
    status: AC
  - elapsed: 0.31787058599999796
    environment: g++
    memory: 6.796
    name: near_arg_shuffle_01
    status: AC
  - elapsed: 0.3150616420000034
    environment: g++
    memory: 6.8
    name: near_arg_shuffle_02
    status: AC
  - elapsed: 0.002755613999994466
    environment: g++
    memory: 3.8
    name: only_x_axis_00
    status: AC
  - elapsed: 0.1963406670000012
    environment: g++
    memory: 5.668
    name: random_00
    status: AC
  - elapsed: 0.23164216099999635
    environment: g++
    memory: 6.024
    name: random_01
    status: AC
  - elapsed: 0.07880461700000296
    environment: g++
    memory: 4.388
    name: random_02
    status: AC
  - elapsed: 0.0025240729999893574
    environment: g++
    memory: 3.58
    name: small_all_00
    status: AC
  timestamp: '2026-10-11 18:25:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/arg_sort.test.cpp
layout: document
---
