---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/max_min_sumwithsize.hpp
    title: math/monoid/max_min_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/update.hpp
    title: math/monoid/update.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../math/monoid/affine.hpp\"\n#include \"../../math/monoid/max_min_sumwithsize.hpp\"\
    \n#include \"../../math/monoid/max.hpp\"\n#include \"../../math/monoid/min.hpp\"\
    \n#include \"../../math/monoid/update.hpp\"\n#include \"../../random/gen.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nvoid test()\
    \ {\n    kk2::monoid::Affine<int> x11(2, 3), x12(3, 4);\n    auto x13 = x11.eval(5);\n\
    \    auto x14 = kk2::monoid::Affine<int>::op(x11, x12);\n    auto x15 = kk2::monoid::Affine<int>::unit();\n\
    \    auto x16 = kk2::monoid::Affine<int>::inv(x11);\n    auto x17 = x11 == x12;\n\
    \    auto x18 = x11 != x12;\n\n    kk2::monoid::MaxMinSumWithSize<int, int> x21(1),\
    \ x22(2, 3, 4, 5);\n    auto x23 = kk2::monoid::MaxMinSumWithSize<int, int>::op(x21,\
    \ x22);\n    auto x24 = kk2::monoid::MaxMinSumWithSize<int, int>::unit();\n  \
    \  auto x25 = x21 == x22;\n    auto x26 = x21 != x22;\n\n    kk2::monoid::Max<int>\
    \ x31(1), x32(2);\n    auto x33 = kk2::monoid::Max<int>::op(x31, x32);\n    auto\
    \ x34 = kk2::monoid::Max<int>::unit();\n    auto x35 = x31 == x32;\n    auto x36\
    \ = x31 != x32;\n\n    kk2::monoid::Min<int> x41(1), x42(2);\n    auto x43 = kk2::monoid::Min<int>::op(x41,\
    \ x42);\n    auto x44 = kk2::monoid::Min<int>::unit();\n    auto x45 = x41 ==\
    \ x42;\n    auto x46 = x41 != x42;\n\n    kk2::monoid::Update<int> x51(1), x52(2);\n\
    \    auto x53 = kk2::monoid::Update<int>::op(x51, x52);\n    auto x54 = kk2::monoid::Update<int>::unit();\n\
    \    auto x55 = x51 == x52;\n    auto x56 = x51 != x52;\n\n    [&](auto, auto,\
    \ auto, auto, auto, auto, auto, auto){}(x11, x12, x13, x14, x15, x16, x17, x18);\n\
    \    [&](auto, auto, auto, auto, auto, auto){}(x21, x22, x23, x24, x25, x26);\n\
    \    [&](auto, auto, auto, auto, auto, auto){}(x31, x32, x33, x34, x35, x36);\n\
    \    [&](auto, auto, auto, auto, auto, auto){}(x41, x42, x43, x44, x45, x46);\n\
    \    [&](auto, auto, auto, auto, auto, auto){}(x51, x52, x53, x54, x55, x56);\n\
    }\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\
    \n    rep (10000) test();\n\n    return 0;\n}\n"
  dependsOn:
  - math/monoid/affine.hpp
  - type_traits/io.hpp
  - math/monoid/max_min_sumwithsize.hpp
  - math/monoid/max.hpp
  - math/monoid/min.hpp
  - math/monoid/update.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/monoid.test.cpp
  requiredBy: []
  timestamp: '2025-04-06 13:01:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/monoid.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/monoid.test.cpp
- /verify/verify/unit_test/monoid.test.cpp.html
title: verify/unit_test/monoid.test.cpp
---
