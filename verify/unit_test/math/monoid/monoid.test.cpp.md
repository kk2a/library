---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/hold.hpp
    title: "\u5E38\u306B\u53F3\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
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
    title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../math/monoid/affine.hpp\"\n#include \"../../../../math/monoid/hold.hpp\"\
    \n#include \"../../../../math/monoid/max.hpp\"\n#include \"../../../../math/monoid/max_min_sumwithsize.hpp\"\
    \n#include \"../../../../math/monoid/min.hpp\"\n#include \"../../../../math/monoid/update.hpp\"\
    \n#include \"../../../../random/gen.hpp\"\n#include \"../../../../template/template.hpp\"\
    \nusing namespace std;\n\nvoid test_monoid() {\n    // Update monoid test\n  \
    \  {\n        using M = kk2::monoid::Update<int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n  \
    \          int val2 = kk2::random::rng(1, 1001);\n            M a(val1), b(val2);\n\
    \n            assert(M::op(unit, a) == a);\n            assert(M::op(a, unit)\
    \ == a);\n            assert(M::op(a, b) == a); // \u5DE6\u5074\u3092\u4FDD\u6301\
    \n            assert(M::op(b, a) == b);\n        }\n        cerr << \"Update:\
    \ 10000 random tests passed!\" << endl;\n    }\n\n    // Min monoid test\n   \
    \ {\n        using M = kk2::monoid::Min<int>;\n        M unit = M::unit();\n\n\
    \        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n   \
    \         int val2 = kk2::random::rng(1, 1001);\n            int val3 = kk2::random::rng(1,\
    \ 1001);\n            M a(val1), b(val2), c(val3);\n\n            assert(M::op(unit,\
    \ a) == a);\n            assert(M::op(a, unit) == a);\n\n            // min\u6F14\
    \u7B97\u306E\u691C\u8A3C\n            int min_ab = min(val1, val2);\n        \
    \    int min_bc = min(val2, val3);\n            int min_ac = min(val1, val3);\n\
    \            assert(M::op(a, b).a == min_ab);\n            assert(M::op(b, c).a\
    \ == min_bc);\n            assert(M::op(a, c).a == min_ac);\n\n            //\
    \ \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            assert(M::op(M::op(a, b),\
    \ c) == M::op(a, M::op(b, c)));\n        }\n        cerr << \"Min: 10000 random\
    \ tests passed!\" << endl;\n    }\n\n    // Max monoid test\n    {\n        using\
    \ M = kk2::monoid::Max<int>;\n        M unit = M::unit();\n\n        rep(10000)\
    \ {\n            int val1 = kk2::random::rng(1, 1001);\n            int val2 =\
    \ kk2::random::rng(1, 1001);\n            int val3 = kk2::random::rng(1, 1001);\n\
    \            M a(val1), b(val2), c(val3);\n\n            assert(M::op(unit, a)\
    \ == a);\n            assert(M::op(a, unit) == a);\n\n            // max\u6F14\
    \u7B97\u306E\u691C\u8A3C\n            int max_ab = max(val1, val2);\n        \
    \    int max_bc = max(val2, val3);\n            int max_ac = max(val1, val3);\n\
    \            assert(M::op(a, b).a == max_ab);\n            assert(M::op(b, c).a\
    \ == max_bc);\n            assert(M::op(a, c).a == max_ac);\n\n            //\
    \ \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            assert(M::op(M::op(a, b),\
    \ c) == M::op(a, M::op(b, c)));\n        }\n        cerr << \"Max: 10000 random\
    \ tests passed!\" << endl;\n    }\n\n    // MaxMinSumWithSize test\n    {\n  \
    \      using M = kk2::monoid::MaxMinSumWithSize<int, int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n  \
    \          int val2 = kk2::random::rng(1, 1001);\n            M a(val1), b(val2);\n\
    \n            assert(M::op(unit, a) == a);\n\n            auto ab = M::op(a, b);\n\
    \            assert(ab.max == max(val1, val2));\n            assert(ab.min ==\
    \ min(val1, val2));\n            assert(ab.sum == val1 + val2);\n            assert(ab.size\
    \ == 2);\n        }\n        cerr << \"MaxMinSumWithSize: 10000 random tests passed!\"\
    \ << endl;\n    }\n\n    // Hold monoid test\n    {\n        using M = kk2::monoid::Hold<int>;\n\
    \        M unit = M::unit();\n\n        rep(10000) {\n            int val1 = kk2::random::rng(1,\
    \ 1001);\n            int val2 = kk2::random::rng(1, 1001);\n            M a(val1),\
    \ b(val2);\n\n            assert(M::op(unit, a) == a);\n            assert(M::op(a,\
    \ unit) == a);\n            assert(M::op(a, b) == b); // \u53F3\u5074\u3092\u4FDD\
    \u6301\n            assert(M::op(b, a) == a);\n        }\n        cerr << \"Hold:\
    \ 10000 random tests passed!\" << endl;\n    }\n\n    // Affine monoid test\n\
    \    {\n        using M = kk2::monoid::Affine<int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int a1 = kk2::random::rng(1, 11), b1 = kk2::random::rng(1,\
    \ 11);\n            int a2 = kk2::random::rng(1, 11), b2 = kk2::random::rng(1,\
    \ 11);\n            int x = kk2::random::rng(1, 101);\n\n            M f(a1, b1),\
    \ g(a2, b2);\n\n            assert(M::op(unit, f) == f);\n            assert(M::op(f,\
    \ unit) == f);\n\n            assert(f.eval(x) == a1 * x + b1);\n            assert(g.eval(x)\
    \ == a2 * x + b2);\n\n            // \u5408\u6210\u306E\u691C\u8A3C f(g(x)) =\
    \ f(a2*x + b2) = a1*(a2*x + b2) + b1 = a1*a2*x + a1*b2 + b1\n            auto\
    \ fg = M::op(f, g);\n            assert(fg.a == a1 * a2);\n            assert(fg.b\
    \ == a1 * b2 + b1);\n            assert(fg.eval(x) == a1 * (a2 * x + b2) + b1);\n\
    \n            // \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            int a3 = kk2::random::rng(1,\
    \ 11), b3 = kk2::random::rng(1, 11);\n            M h(a3, b3);\n            assert(M::op(M::op(f,\
    \ g), h) == M::op(f, M::op(g, h)));\n        }\n        cerr << \"Affine: 10000\
    \ random tests passed!\" << endl;\n    }\n}\n\n\n\nvoid test() {\n    test_monoid();\n\
    \n    // \u5168\u30C6\u30B9\u30C8\u901A\u904E\n    cerr << \"All monoid tests\
    \ passed!\" << endl;\n}\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n \
    \   kout << a + b << kendl;\n\n    test();\n\n    return 0;\n}\n"
  dependsOn:
  - math/monoid/affine.hpp
  - type_traits/io.hpp
  - math/monoid/hold.hpp
  - math/monoid/max.hpp
  - math/monoid/max_min_sumwithsize.hpp
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
  path: verify/unit_test/math/monoid/monoid.test.cpp
  requiredBy: []
  timestamp: '2025-07-08 15:03:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/monoid/monoid.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/monoid/monoid.test.cpp
- /verify/verify/unit_test/math/monoid/monoid.test.cpp.html
title: verify/unit_test/math/monoid/monoid.test.cpp
---
