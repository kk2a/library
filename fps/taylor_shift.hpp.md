---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/comb.hpp
    title: mod/comb.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/taylor_shift.hpp\"\n\n\n\n#line 1 \"mod/comb.hpp\"\n\
    \n\n\ntemplate <class mint>\nstruct Comb {\n    vector<mint> _frac, _ifrac, _inv;\n\
    \    Comb(int max = 0) {\n        _frac.resize(1, mint(1));\n        _ifrac.resize(1,\
    \ mint(1));\n        _inv.resize(1, mint(1));\n        if (max > 0) extend(max);\n\
    \    }\n\n    void extend(int m = -1) {\n        int n = (int)_frac.size();\n\
    \        if (m == -1) m = n << 1;\n        if (n >= m) return;\n        m = min<int>(m,\
    \ mint::getmod() - 1);\n        _frac.resize(m + 1);\n        _ifrac.resize(m\
    \ + 1);\n        _inv.resize(m + 1);\n        for (int i = n; i <= m; i++) _frac[i]\
    \ = _frac[i - 1] * i;\n        _ifrac[m] = _frac[m].inv();\n        _inv[m] =\
    \ _ifrac[m] * _frac[m - 1];\n        for (int i = m; i > n; i--) {\n         \
    \   _ifrac[i - 1] = _ifrac[i] * i;\n            _inv[i - 1] = _ifrac[i - 1] *\
    \ _frac[i - 2];\n        }\n    }\n\n    mint frac(int n) {\n        if (n < 0)\
    \ return 0;\n        if ((int)_frac.size() <= n) extend(n);\n        return _frac[n];\n\
    \    }\n\n    mint ifrac(int n) {\n        if (n < 0) return 0;\n        if ((int)_ifrac.size()\
    \ <= n) extend(n);\n        return _ifrac[n];\n    }\n\n    mint inv(int n) {\n\
    \        if (n < 0) return -inv(-n);\n        if ((int)_inv.size() <= n) extend(n);\n\
    \        return _inv[n];\n    }\n\n    mint binom(int n, int k) {\n        if\
    \ (n < 0 || k < 0 || k > n) return 0;\n        return frac(n) * ifrac(k) * ifrac(n\
    \ - k);\n    }\n\n    inline mint operator()(int n, int k) { return binom(n, k);\
    \ }\n\n    template <class T>\n    mint multinomial(const vector<T>& r) {\n  \
    \      static_assert(is_integral_v<T>, \"T must be integral\");\n        int n\
    \ = 0;\n        for (auto &x : r) {\n            if (x < 0) return 0;\n      \
    \      n += x;\n        }\n        mint res = frac(n);\n        for (auto &x :\
    \ r) res *= ifrac(x);\n        return res;\n    }\n\n    template <class T>\n\
    \    mint operator()(const vector<T>& r) { return multinomial(r); }\n\n    mint\
    \ binom_naive(int n, int k) {\n        if (n < 0 || k < 0 || k > n) return 0;\n\
    \        mint res = 1;\n        k = min(k, n - k);\n        for (int i = 1; i\
    \ <= k; i++) res *= inv(i) * (n--);\n        return res;\n    }\n\n    mint permu(int\
    \ n, int k) {\n        if (n < 0 || k < 0 || k > n) return 0;\n        return\
    \ frac(n) * ifrac(n - k);\n    }\n\n    mint homo(int n, int k) {\n        if\
    \ (n < 0 || k < 0) return 0;\n        return k == 0 ? 1 : binom(n + k - 1, k);\n\
    \    }\n};\n\n\n#line 5 \"fps/taylor_shift.hpp\"\n\ntemplate <class FPS, class\
    \ mint = FPS::value_type>\nFPS TaylorShift(FPS f, mint a, Comb<mint>& c) {\n \
    \   int n = f.size();\n    for (int i = 0; i < n; i++) f[i] *= c.frac(i);\n  \
    \  reverse(begin(f), end(f));\n    FPS g(n, mint(1));\n    for (int i = 1; i <\
    \ n; i++) g[i] = g[i - 1] * a * c.inv(i);\n    f = (f * g).pre(n).rev();\n   \
    \ for (int i = 0; i < n; i++) f[i] *= c.ifrac(i);\n    return f;\n}\n\n\n"
  code: "#ifndef FPS_TAYLOR_SHIFT_HPP\n#define FPS_TAYLOR_SHIFT_HPP 1\n\n#include\
    \ \"../mod/comb.hpp\"\n\ntemplate <class FPS, class mint = FPS::value_type>\n\
    FPS TaylorShift(FPS f, mint a, Comb<mint>& c) {\n    int n = f.size();\n    for\
    \ (int i = 0; i < n; i++) f[i] *= c.frac(i);\n    reverse(begin(f), end(f));\n\
    \    FPS g(n, mint(1));\n    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a *\
    \ c.inv(i);\n    f = (f * g).pre(n).rev();\n    for (int i = 0; i < n; i++) f[i]\
    \ *= c.ifrac(i);\n    return f;\n}\n\n#endif // FPS_TAYLOR_SHIFT_HPP\n"
  dependsOn:
  - mod/comb.hpp
  isVerificationFile: false
  path: fps/taylor_shift.hpp
  requiredBy: []
  timestamp: '2024-05-23 16:05:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/taylor_shift.hpp
layout: document
redirect_from:
- /library/fps/taylor_shift.hpp
- /library/fps/taylor_shift.hpp.html
title: fps/taylor_shift.hpp
---
