---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':question:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':question:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':x:'
    path: fps/sample_point_shift.hpp
    title: fps/sample_point_shift.hpp
  - icon: ':x:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_math/many_factrials.test.cpp
    title: verify/yosupo_math/many_factrials.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
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
    \  [Previous line repeated 3 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef MOD_COMB_LARGE_HPP\n#define MOD_COMB_LARGE_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <vector>\n\n#include \"../fps/ntt_friendly.hpp\"\
    \n#include \"../fps/sample_point_shift.hpp\"\n#include \"../type_traits/type_traits.hpp\"\
    \n#include \"comb.hpp\"\n\nnamespace kk2 {\n\ntemplate <class mint> struct CombLarge\
    \ {\n    using FPS = FormalPowerSeries<mint>;\n    static constexpr int LOG_BLOCK_SIZE\
    \ = 9;\n    static constexpr int BLOCK_SIZE = 1 << LOG_BLOCK_SIZE;\n    static\
    \ constexpr int BLOCK_NUM = mint::getmod() >> LOG_BLOCK_SIZE;\n\n    static inline\
    \ int threshold = 2000000;\n\n    CombLarge() = delete;\n\n    static mint fact(int\
    \ n) { return n <= threshold ? Comb<mint>::fact(n) : _large_fact(n); }\n\n   \
    \ static mint inv_fact(int n) {\n        return n <= threshold ? Comb<mint>::ifact(n)\
    \ : _large_fact(n).inv();\n    }\n\n    static mint binom(int n, int r) {\n  \
    \      if (r < 0 || r > n) return mint(0);\n        return fact(n) * inv_fact(r)\
    \ * inv_fact(n - r);\n    }\n\n    template <class T> static mint multinomial(std::vector<T>\
    \ r) {\n        static_assert(is_integral<T>::value, \"T must be integral\");\n\
    \        long long n = 0;\n        for (auto &x : r) {\n            assert(x >=\
    \ 0);\n            n += x;\n        }\n        if (n >= mint::getmod()) return\
    \ 0;\n        mint res = fact(n);\n        for (auto &x : r) res *= inv_fact(x);\n\
    \        return res;\n    }\n\n    static mint permu(int n, int r) {\n       \
    \ if (r < 0 || r > n) return mint(0);\n        return fact(n) * inv_fact(n - r);\n\
    \    }\n\n    static mint homo(int n, int r) {\n        if (n < 0 || r < 0) return\
    \ mint(0);\n        return r == 0 ? 1 : binom(n + r - 1, r);\n    }\n\n  private:\n\
    \    static inline std::vector<mint> _block_fact{};\n\n    static void _build()\
    \ {\n        if (_block_fact.size()) return;\n        std::vector<mint> f{1};\n\
    \        f.reserve(BLOCK_SIZE);\n        for (int i = 0; i < LOG_BLOCK_SIZE; i++)\
    \ {\n            std::vector<mint> g = SamplePointShift<FPS>(f, mint(1 << i),\
    \ 3 << i);\n            const auto get = [&](int j) {\n                return\
    \ j < (1 << i) ? f[j] : g[j - (1 << i)];\n            };\n            f.resize(2\
    \ << i);\n            for (int j = 0; j < 2 << i; j++) {\n                f[j]\
    \ = get(2 * j) * get(2 * j + 1) * ((2 * j + 1) << i);\n            }\n       \
    \ }\n\n        if (BLOCK_NUM > BLOCK_SIZE) {\n            std::vector<mint> g\
    \ =\n                SamplePointShift<FPS>(f, mint(BLOCK_SIZE), BLOCK_NUM - BLOCK_SIZE);\n\
    \            std::move(std::begin(g), std::end(g), std::back_inserter(f));\n \
    \       } else f.resize(BLOCK_NUM);\n        for (int i = 0; i < BLOCK_NUM; i++)\
    \ { f[i] *= mint(i + 1) * BLOCK_SIZE; }\n        // f[i] = prod_{j = 1} ^ (BLOCK_SIZE)\
    \ (i * BLOCK_SIZE + j)\n\n        f.insert(std::begin(f), 1);\n        for (int\
    \ i = 1; i <= BLOCK_NUM; i++) { f[i] *= f[i - 1]; }\n        _block_fact = std::move(f);\n\
    \    }\n\n    static mint _large_fact(int n) {\n        _build();\n        mint\
    \ res;\n        int q = n / BLOCK_SIZE, r = n % BLOCK_SIZE;\n        if (2 * r\
    \ <= BLOCK_SIZE) {\n            res = _block_fact[q];\n            for (int i\
    \ = 0; i < r; i++) { res *= n - i; }\n        } else if (q != BLOCK_NUM) {\n \
    \           res = _block_fact[q + 1];\n            mint den = 1;\n           \
    \ for (int i = 1; i <= BLOCK_SIZE - r; i++) { den *= n + i; }\n            res\
    \ /= den;\n        } else {\n            res = -1;\n            mint den = 1;\n\
    \            for (int i = mint::getmod() - 1; i > n; i++) { den *= i; }\n    \
    \        res /= den;\n        }\n        return res;\n    }\n};\n\n} // namespace\
    \ kk2\n\n#endif // MOD_COMB_LARGE_HPP\n"
  dependsOn:
  - fps/ntt_friendly.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - fps/fps.hpp
  - fps/sample_point_shift.hpp
  - math_mod/comb.hpp
  isVerificationFile: false
  path: math_mod/comb_large.hpp
  requiredBy: []
  timestamp: '2024-10-22 22:13:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/many_factrials.test.cpp
documentation_of: math_mod/comb_large.hpp
layout: document
redirect_from:
- /library/math_mod/comb_large.hpp
- /library/math_mod/comb_large.hpp.html
title: math_mod/comb_large.hpp
---
