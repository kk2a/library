---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/Eratosthenes.hpp
    title: math/Eratosthenes.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/lcm1.hpp\"\n\n\n\n#line 1 \"math/Eratosthenes.hpp\"\
    \n\n\n\nstruct Erato {\n    vector<bool> isprime;\n    vector<int> minfactor;\n\
    \    vector<int> mobius;\n    vector<int> primes;\n\n    Erato(int N) : isprime(N\
    \ + 1, true), minfactor(N + 1, -1),\n                   mobius(N + 1, 1) {\n \
    \       isprime[1] = false;\n        minfactor[1] = 1;\n\n        for (int p =\
    \ 2; p <= N; ++p) {\n            if (!isprime[p]) continue;\n\n            minfactor[p]\
    \ = p;\n            mobius[p] = -1;\n            primes.emplace_back(p);\n   \
    \         \n            for (int q = p * 2; q <= N; q += p) {\n              \
    \  isprime[q] = false;\n                \n                if (minfactor[q] ==\
    \ -1) minfactor[q] = p;\n                if ((q / p) % p == 0) mobius[q] = 0;\n\
    \                else mobius[q] = -mobius[q];\n            }\n        }\n    }\n\
    \n    vector<pair<int, int>> factorize(int n) {\n        vector<pair<int, int>>\
    \ res;\n        while (n > 1) {\n            int p = minfactor[n];\n         \
    \   int exp = 0;\n\n            while (minfactor[n] == p) {\n                n\
    \ /= p;\n                ++exp;\n            }\n            res.emplace_back(p,\
    \ exp);\n        }\n        return res;\n    }  \n\n    vector<int> divisors(int\
    \ n) {\n        vector<int> res({1});\n        auto pf = factorize(n);\n\n   \
    \     for (auto p : pf) {\n            int s = (int)res.size();\n            for\
    \ (int i = 0; i < s; ++i) {\n                int v = 1;\n                for (int\
    \ j = 0; j < p.second; ++j) {\n                    v *= p.first;\n           \
    \         res.push_back(res[i] * v);\n                }\n            }\n     \
    \   }\n        return res;\n    }\n};\n\n\n#line 5 \"convolution/lcm1.hpp\"\n\n\
    // 1-indexed\ntemplate <class FPS, class mint = typename FPS::value_type> \nFPS\
    \ convolution_lcm(FPS& a, FPS b) {\n    int n = int(size(a)); // = int(size(b))\n\
    \    if (!n) return {};\n    n--;\n\n    static const constexpr int mx = 1000000;\n\
    \    Erato pr(mx);\n\n    auto fdt = [&](FPS& a) -> void {\n        for (const\
    \ auto p : pr.primes) {\n            if (p > n) break;\n            for (int i\
    \ = 1; i <= n / p; i++) a[i * p] += a[i];\n        }\n    };\n    auto ifdt =\
    \ [&](FPS& a) -> void {\n        for (const auto p : pr.primes) {\n          \
    \  if (p  > n) break;\n            for (auto i = n / p; i > 0; i--) a[i * p] -=\
    \ a[i];\n        }\n    };\n\n    fdt(a);\n    fdt(b);\n    for (int i = 1; i\
    \ <= n; i++) a[i] *= b[i];\n    ifdt(a);\n\n    return a;\n}\n\n\n"
  code: "#ifndef CONVOLUTION_LCM\n#define CONVOLUTION_LCM 1\n\n#include \"../math/Eratosthenes.hpp\"\
    \n\n// 1-indexed\ntemplate <class FPS, class mint = typename FPS::value_type>\
    \ \nFPS convolution_lcm(FPS& a, FPS b) {\n    int n = int(size(a)); // = int(size(b))\n\
    \    if (!n) return {};\n    n--;\n\n    static const constexpr int mx = 1000000;\n\
    \    Erato pr(mx);\n\n    auto fdt = [&](FPS& a) -> void {\n        for (const\
    \ auto p : pr.primes) {\n            if (p > n) break;\n            for (int i\
    \ = 1; i <= n / p; i++) a[i * p] += a[i];\n        }\n    };\n    auto ifdt =\
    \ [&](FPS& a) -> void {\n        for (const auto p : pr.primes) {\n          \
    \  if (p  > n) break;\n            for (auto i = n / p; i > 0; i--) a[i * p] -=\
    \ a[i];\n        }\n    };\n\n    fdt(a);\n    fdt(b);\n    for (int i = 1; i\
    \ <= n; i++) a[i] *= b[i];\n    ifdt(a);\n\n    return a;\n}\n\n#endif // CONVOLUTION_LCM\n"
  dependsOn:
  - math/Eratosthenes.hpp
  isVerificationFile: false
  path: convolution/lcm1.hpp
  requiredBy: []
  timestamp: '2024-05-23 16:18:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/lcm1.hpp
layout: document
redirect_from:
- /library/convolution/lcm1.hpp
- /library/convolution/lcm1.hpp.html
title: convolution/lcm1.hpp
---
