---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/action/add_max.hpp
    title: math/action/add_max.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/add_max_min_sumwithsize.hpp
    title: math/action/add_max_min_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/add_min.hpp
    title: math/action/add_min.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/add_sumwithsize.hpp
    title: math/action/add_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/affine_sumwithsize.hpp
    title: math/action/affine_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_affine.hpp
    title: math/action/update_affine.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_max.hpp
    title: math/action/update_max.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_max_min_sumwithsize.hpp
    title: math/action/update_max_min_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_min.hpp
    title: math/action/update_min.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_sumwithsize.hpp
    title: math/action/update_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/group/add.hpp
    title: math/group/add.hpp
  - icon: ':heavy_check_mark:'
    path: math/group/sum_with_size.hpp
    title: math/group/sum_with_size.hpp
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
    title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':heavy_check_mark:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':heavy_check_mark:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../math/action/add_max.hpp\"\n#include \"../../../../math/action/add_max_min_sumwithsize.hpp\"\
    \n#include \"../../../../math/action/add_min.hpp\"\n#include \"../../../../math/action/add_sumwithsize.hpp\"\
    \n#include \"../../../../math/action/affine_sumwithsize.hpp\"\n#include \"../../../../math/action/update_affine.hpp\"\
    \n#include \"../../../../math/action/update_max.hpp\"\n#include \"../../../../math/action/update_max_min_sumwithsize.hpp\"\
    \n#include \"../../../../math/action/update_min.hpp\"\n#include \"../../../../math/action/update_sumwithsize.hpp\"\
    \n#include \"../../../../random/gen.hpp\"\n#include \"../../../../template/template.hpp\"\
    \nusing namespace std;\n\nvoid test_action() {\n    // UpdateSumWithSize action\
    \ test\n    {\n        using Action = kk2::action::UpdateSumWithSize<int, int>;\n\
    \        using A = Action::A;\n        using S = Action::S;\n\n        rep(10000)\
    \ {\n            int val = kk2::random::rng(1, 1001);\n            int size =\
    \ kk2::random::rng(1, 101);\n            S x(kk2::random::rng(1, 1001), size);\n\
    \            A f(val);\n\n            auto result = Action::act(f, x);\n     \
    \       assert(result.a == val * size);\n            assert(result.size == size);\n\
    \n            // unit action\u306E\u30C6\u30B9\u30C8\n            A unit = A::unit();\n\
    \            auto unit_result = Action::act(unit, x);\n            assert(unit_result\
    \ == x);\n        }\n        cerr << \"UpdateSumWithSize: 10000 random tests passed!\"\
    \ << endl;\n    }\n\n    // UpdateMin action test\n    {\n        using Action\
    \ = kk2::action::UpdateMin<int>;\n        using A = Action::A;\n        using\
    \ S = Action::S;\n\n        rep(10000) {\n            int val = kk2::random::rng(1,\
    \ 1001);\n            S x(kk2::random::rng(1, 1001));\n            A f{S(val)};\n\
    \            A f2{S()};\n\n            auto result = Action::act(f, x);\n    \
    \        assert(result.a == val);\n\n            auto result2 = Action::act(f2,\
    \ x);\n            assert(result2.is_unit);\n\n            // unit action\u306E\
    \u30C6\u30B9\u30C8\n            A unit = A::unit();\n            auto unit_result\
    \ = Action::act(unit, x);\n            assert(unit_result == x);\n        }\n\
    \        cerr << \"UpdateMin: 10000 random tests passed!\" << endl;\n    }\n\n\
    \    // UpdateMax action test\n    {\n        using Action = kk2::action::UpdateMax<int>;\n\
    \        using A = Action::A;\n        using S = Action::S;\n\n        rep(10000)\
    \ {\n            int val = kk2::random::rng(1, 1001);\n            S x(kk2::random::rng(1,\
    \ 1001));\n            A f{S(val)};\n            A f2{S()};\n\n            auto\
    \ result = Action::act(f, x);\n            assert(result.a == val);\n\n      \
    \      auto result2 = Action::act(f2, x);\n            assert(result2.is_unit);\n\
    \n            // unit action\u306E\u30C6\u30B9\u30C8\n            A unit = A::unit();\n\
    \            auto unit_result = Action::act(unit, x);\n            assert(unit_result\
    \ == x);\n        }\n        cerr << \"UpdateMax: 10000 random tests passed!\"\
    \ << endl;\n    }\n\n    // UpdateMaxMinSumWithSize action test\n    {\n     \
    \   using Action = kk2::action::UpdateMaxMinSumWithSize<int, int>;\n        using\
    \ A = Action::A;\n        using S = Action::S;\n\n        rep(10000) {\n     \
    \       int val = kk2::random::rng(1, 1001);\n            int size = kk2::random::rng(1,\
    \ 101);\n            S x(kk2::random::rng(1, 1001),\n                kk2::random::rng(1,\
    \ 1001),\n                kk2::random::rng(1, 1001),\n                size);\n\
    \            A f(val);\n\n            auto result = Action::act(f, x);\n     \
    \       assert(result.max == val);\n            assert(result.min == val);\n \
    \           assert(result.sum == val * size);\n            assert(result.size\
    \ == size);\n\n            // unit action\u306E\u30C6\u30B9\u30C8\n          \
    \  A unit = A::unit();\n            auto unit_result = Action::act(unit, x);\n\
    \            assert(unit_result == x);\n        }\n        cerr << \"UpdateMaxMinSumWithSize:\
    \ 10000 random tests passed!\" << endl;\n    }\n\n    // UpdateAffine action test\n\
    \    {\n        using Action = kk2::action::UpdateAffine<int>;\n        using\
    \ A = Action::A;\n        using S = Action::S;\n\n        rep(10000) {\n     \
    \       int a1 = kk2::random::rng(1, 11);\n            int b1 = kk2::random::rng(1,\
    \ 11);\n            int a2 = kk2::random::rng(1, 11);\n            int b2 = kk2::random::rng(1,\
    \ 11);\n\n            S new_affine(a1, b1);\n            S x(a2, b2);\n      \
    \      A f(new_affine);\n\n            auto result = Action::act(f, x);\n    \
    \        assert(result.a == a1);\n            assert(result.b == b1);\n\n    \
    \        // unit action\u306E\u30C6\u30B9\u30C8\n            A unit = A::unit();\n\
    \            auto unit_result = Action::act(unit, x);\n            assert(unit_result\
    \ == x);\n        }\n        cerr << \"UpdateAffine: 10000 random tests passed!\"\
    \ << endl;\n    }\n\n    // AffineSumWithSize action test\n    {\n        using\
    \ Action = kk2::action::AffineSumWithSize<int, int>;\n        using A = Action::A;\n\
    \        using S = Action::S;\n\n        rep(10000) {\n            int a = kk2::random::rng(1,\
    \ 11);\n            int b = kk2::random::rng(1, 11);\n            int sum = kk2::random::rng(1,\
    \ 1001);\n            int size = kk2::random::rng(1, 101);\n\n            A f(a,\
    \ b);\n            S x(sum, size);\n\n            auto result = Action::act(f,\
    \ x);\n            assert(result.a == a * sum + b * size);\n            assert(result.size\
    \ == size);\n        }\n        cerr << \"AffineSumWithSize: 10000 random tests\
    \ passed!\" << endl;\n    }\n\n    // AddSumWithSize action test\n    {\n    \
    \    using Action = kk2::action::AddSumWithSize<int, int>;\n        using A =\
    \ Action::A;\n        using S = Action::S;\n\n        rep(10000) {\n         \
    \   int add_val = kk2::random::rng(-1000, 1001);\n            int sum = kk2::random::rng(-1000,\
    \ 1001);\n            int size = kk2::random::rng(1, 101);\n\n            A f(add_val);\n\
    \            S x(sum, size);\n\n            auto result = Action::act(f, x);\n\
    \            assert(result.a == sum + add_val * size);\n            assert(result.size\
    \ == size);\n        }\n        cerr << \"AddSumWithSize: 10000 random tests passed!\"\
    \ << endl;\n    }\n\n    // AddMin action test\n    {\n        using Action =\
    \ kk2::action::AddMin<int>;\n        using A = Action::A;\n        using S = Action::S;\n\
    \n        rep(10000) {\n            int add_val = kk2::random::rng(-1000, 1001);\n\
    \            int min_val = kk2::random::rng(-1000, 1001);\n\n            A f(add_val);\n\
    \            S x(min_val);\n\n            auto result = Action::act(f, x);\n \
    \           assert(result.a == min_val + add_val);\n\n            // unit\u5024\
    \u306E\u30C6\u30B9\u30C8\n            S unit_x = S::unit();\n            auto\
    \ unit_result = Action::act(f, unit_x);\n            assert(unit_result == unit_x);\n\
    \        }\n        cerr << \"AddMin: 10000 random tests passed!\" << endl;\n\
    \    }\n\n    // AddMax action test\n    {\n        using Action = kk2::action::AddMax<int>;\n\
    \        using A = Action::A;\n        using S = Action::S;\n\n        rep(10000)\
    \ {\n            int add_val = kk2::random::rng(-1000, 1001);\n            int\
    \ max_val = kk2::random::rng(-1000, 1001);\n\n            A f(add_val);\n    \
    \        S x(max_val);\n\n            auto result = Action::act(f, x);\n     \
    \       assert(result.a == max_val + add_val);\n\n            // unit\u5024\u306E\
    \u30C6\u30B9\u30C8\n            S unit_x = S::unit();\n            auto unit_result\
    \ = Action::act(f, unit_x);\n            assert(unit_result == unit_x);\n    \
    \    }\n        cerr << \"AddMax: 10000 random tests passed!\" << endl;\n    }\n\
    \n    // AddMaxMinSumWithSize action test\n    {\n        using Action = kk2::action::AddMaxMinSumWithSize<int,\
    \ int>;\n        using A = Action::A;\n        using S = Action::S;\n\n      \
    \  rep(10000) {\n            int add_val = kk2::random::rng(-1000, 1001);\n  \
    \          int max_val = kk2::random::rng(-1000, 1001);\n            int min_val\
    \ = kk2::random::rng(-1000, 1001);\n            int sum = kk2::random::rng(-1000,\
    \ 1001);\n            int size = kk2::random::rng(1, 101);\n\n            A f(add_val);\n\
    \            S x(max_val, min_val, sum, size);\n\n            auto result = Action::act(f,\
    \ x);\n            assert(result.max == max_val + add_val);\n            assert(result.min\
    \ == min_val + add_val);\n            assert(result.sum == sum + add_val * size);\n\
    \            assert(result.size == size);\n\n            // unit\u5024\u306E\u30C6\
    \u30B9\u30C8\n            S unit_x = S::unit();\n            auto unit_result\
    \ = Action::act(f, unit_x);\n            assert(unit_result == unit_x);\n    \
    \    }\n        cerr << \"AddMaxMinSumWithSize: 10000 random tests passed!\" <<\
    \ endl;\n    }\n\n    cerr << \"All action tests passed!\" << endl;\n}\n\nint\
    \ main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n\
    \    test_action();\n\n    return 0;\n}\n"
  dependsOn:
  - math/action/add_max.hpp
  - math/group/add.hpp
  - type_traits/io.hpp
  - math/monoid/max.hpp
  - math/action/add_max_min_sumwithsize.hpp
  - math/monoid/max_min_sumwithsize.hpp
  - math/action/add_min.hpp
  - math/monoid/min.hpp
  - math/action/add_sumwithsize.hpp
  - math/group/sum_with_size.hpp
  - math/action/affine_sumwithsize.hpp
  - math/monoid/affine.hpp
  - math/action/update_affine.hpp
  - math/monoid/update.hpp
  - math/action/update_max.hpp
  - math/action/update_max_min_sumwithsize.hpp
  - math/action/update_min.hpp
  - math/action/update_sumwithsize.hpp
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
  path: verify/unit_test/math/action/action.test.cpp
  requiredBy: []
  timestamp: '2025-07-08 15:40:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/action/action.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/action/action.test.cpp
- /verify/verify/unit_test/math/action/action.test.cpp.html
title: verify/unit_test/math/action/action.test.cpp
---
