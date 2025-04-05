---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MOD_COMB_LARGE_HPP\n#define KK2_MATH_MOD_COMB_LARGE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <vector>\n\n#include \"../fps/fps_ntt_friendly.hpp\"\n#include \"../fps/poly_sample_point_shift.hpp\"\
    \n#include \"../type_traits/type_traits.hpp\"\n#include \"comb.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class mint> struct CombLarge {\n    using FPS = FormalPowerSeriesNTTFriendly<mint>;\n\
    \    static constexpr int LOG_BLOCK_SIZE = 9;\n    static constexpr int BLOCK_SIZE\
    \ = 1 << LOG_BLOCK_SIZE;\n    static constexpr int BLOCK_NUM = mint::getmod()\
    \ >> LOG_BLOCK_SIZE;\n\n    static inline int threshold = 2000000;\n\n    CombLarge()\
    \ = delete;\n\n    static mint fact(int n) { return n <= threshold ? Comb<mint>::fact(n)\
    \ : _large_fact(n); }\n\n    static mint ifact(int n) {\n        return n <= threshold\
    \ ? Comb<mint>::ifact(n) : _large_fact(n).inv();\n    }\n\n    static mint inv(int\
    \ n) { return n <= threshold ? Comb<mint>::inv(n) : mint(n).inv(); }\n\n    static\
    \ mint binom(int n, int r) {\n        if (r < 0 || r > n) return mint(0);\n  \
    \      return fact(n) * ifact(r) * ifact(n - r);\n    }\n\n    template <class\
    \ T> static mint multinomial(std::vector<T> r) {\n        static_assert(is_integral<T>::value,\
    \ \"T must be integral\");\n        long long n = 0;\n        for (auto &x : r)\
    \ {\n            assert(x >= 0);\n            n += x;\n        }\n        if (n\
    \ >= mint::getmod()) return 0;\n        mint res = fact(n);\n        for (auto\
    \ &x : r) res *= ifact(x);\n        return res;\n    }\n\n    static mint permu(int\
    \ n, int r) {\n        if (r < 0 || r > n) return mint(0);\n        return fact(n)\
    \ * ifact(n - r);\n    }\n\n    static mint homo(int n, int r) {\n        if (n\
    \ < 0 || r < 0) return mint(0);\n        return r == 0 ? 1 : binom(n + r - 1,\
    \ r);\n    }\n\n  private:\n    static inline std::vector<mint> _block_fact{};\n\
    \n    static void _build() {\n        if (_block_fact.size()) return;\n      \
    \  std::vector<mint> f{1};\n        f.reserve(BLOCK_SIZE);\n        for (int i\
    \ = 0; i < LOG_BLOCK_SIZE; i++) {\n            std::vector<mint> g = sample_point_shift<FPS>(f,\
    \ mint(1 << i), 3 << i);\n            const auto get = [&](int j) {\n        \
    \        return j < (1 << i) ? f[j] : g[j - (1 << i)];\n            };\n     \
    \       f.resize(2 << i);\n            for (int j = 0; j < 2 << i; j++) {\n  \
    \              f[j] = get(2 * j) * get(2 * j + 1) * ((2 * j + 1) << i);\n    \
    \        }\n        }\n\n        if (BLOCK_NUM > BLOCK_SIZE) {\n            std::vector<mint>\
    \ g =\n                sample_point_shift<FPS>(f, mint(BLOCK_SIZE), BLOCK_NUM\
    \ - BLOCK_SIZE);\n            std::move(std::begin(g), std::end(g), std::back_inserter(f));\n\
    \        } else f.resize(BLOCK_NUM);\n        for (int i = 0; i < BLOCK_NUM; i++)\
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
    \ kk2\n\n#endif // KK2_MATH_MOD_COMB_LARGE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/comb_large.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/comb_large.hpp
layout: document
redirect_from:
- /library/math_mod/comb_large.hpp
- /library/math_mod/comb_large.hpp.html
title: math_mod/comb_large.hpp
---
