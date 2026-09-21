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
  - elapsed: 0.14752803599998288
    environment: g++
    memory: 6.896
    name: all_same_00
    status: AC
  - elapsed: 0.1610830409999835
    environment: g++
    memory: 6.864
    name: all_same_01
    status: AC
  - elapsed: 0.17493480699999964
    environment: g++
    memory: 6.856
    name: all_same_02
    status: AC
  - elapsed: 0.0019482459999835555
    environment: g++
    memory: 3.824
    name: example_00
    status: AC
  - elapsed: 0.1629224380000096
    environment: g++
    memory: 6.856
    name: half_same_00
    status: AC
  - elapsed: 0.16699048499998526
    environment: g++
    memory: 6.868
    name: half_same_01
    status: AC
  - elapsed: 0.1919102079999675
    environment: g++
    memory: 6.864
    name: half_same_02
    status: AC
  - elapsed: 0.1727755370000068
    environment: g++
    memory: 6.856
    name: max_random_00
    status: AC
  - elapsed: 0.17650682200002166
    environment: g++
    memory: 6.892
    name: max_random_01
    status: AC
  - elapsed: 0.17389258499997595
    environment: g++
    memory: 6.888
    name: max_random_02
    status: AC
  - elapsed: 0.17430168300001014
    environment: g++
    memory: 6.864
    name: near_arg_00
    status: AC
  - elapsed: 0.20340105100001438
    environment: g++
    memory: 6.812
    name: near_arg_01
    status: AC
  - elapsed: 0.20028000900003917
    environment: g++
    memory: 6.896
    name: near_arg_02
    status: AC
  - elapsed: 0.18647294400000192
    environment: g++
    memory: 6.864
    name: near_arg_shuffle_00
    status: AC
  - elapsed: 0.2034184770000138
    environment: g++
    memory: 6.864
    name: near_arg_shuffle_01
    status: AC
  - elapsed: 0.20173374000000877
    environment: g++
    memory: 6.868
    name: near_arg_shuffle_02
    status: AC
  - elapsed: 0.0021674800000255345
    environment: g++
    memory: 3.872
    name: only_x_axis_00
    status: AC
  - elapsed: 0.12289477299998453
    environment: g++
    memory: 5.752
    name: random_00
    status: AC
  - elapsed: 0.14267786099998148
    environment: g++
    memory: 6.124
    name: random_01
    status: AC
  - elapsed: 0.05077441700001373
    environment: g++
    memory: 4.452
    name: random_02
    status: AC
  - elapsed: 0.002113845999986097
    environment: g++
    memory: 3.84
    name: small_all_00
    status: AC
  timestamp: '2026-09-21 18:50:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_geometry/arg_sort.test.cpp
layout: document
---
