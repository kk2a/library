---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../math/action/add_max.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../math/action/add_max.hpp\"\n#include \"../../math/action/add_max_min_sumwithsize.hpp\"\
    \n#include \"../../math/action/add_min.hpp\"\n#include \"../../math/action/add_sumwithsize.hpp\"\
    \n#include \"../../math/action/affine_sumwithsize.hpp\"\n#include \"../../math/action/update_affine.hpp\"\
    \n#include \"../../math/action/update_max.hpp\"\n#include \"../../math/action/update_max_min_sumwithsize.hpp\"\
    \n#include \"../../math/action/update_min.hpp\"\n#include \"../../math/action/update_sumwithsize.hpp\"\
    \n#include \"../../random/gen.hpp\"\n#include \"../../template/template.hpp\"\n\
    using namespace std;\n\nvoid test_action() {\n    // UpdateSumWithSize action\
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
  dependsOn: []
  isVerificationFile: true
  path: verify/unit_test/math/action/action.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/math/action/action.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/action/action.test.cpp
- /verify/verify/unit_test/math/action/action.test.cpp.html
title: verify/unit_test/math/action/action.test.cpp
---
