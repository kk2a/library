---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/gcd1.hpp
    title: convolution/gcd1.hpp
  - icon: ':warning:'
    path: convolution/lcm1.hpp
    title: convolution/lcm1.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Eratosthenes.hpp\"\n\n\n\nstruct Erato {\n    vector<bool>\
    \ isprime;\n    vector<int> minfactor;\n    vector<int> mobius;\n    vector<int>\
    \ primes;\n\n    Erato(int N) : isprime(N + 1, true), minfactor(N + 1, -1),\n\
    \                   mobius(N + 1, 1) {\n        isprime[1] = false;\n        minfactor[1]\
    \ = 1;\n\n        for (int p = 2; p <= N; ++p) {\n            if (!isprime[p])\
    \ continue;\n\n            minfactor[p] = p;\n            mobius[p] = -1;\n  \
    \          primes.emplace_back(p);\n            \n            for (int q = p *\
    \ 2; q <= N; q += p) {\n                isprime[q] = false;\n                \n\
    \                if (minfactor[q] == -1) minfactor[q] = p;\n                if\
    \ ((q / p) % p == 0) mobius[q] = 0;\n                else mobius[q] = -mobius[q];\n\
    \            }\n        }\n    }\n\n    vector<pair<int, int>> factorize(int n)\
    \ {\n        vector<pair<int, int>> res;\n        while (n > 1) {\n          \
    \  int p = minfactor[n];\n            int exp = 0;\n\n            while (minfactor[n]\
    \ == p) {\n                n /= p;\n                ++exp;\n            }\n  \
    \          res.emplace_back(p, exp);\n        }\n        return res;\n    }  \n\
    \n    vector<int> divisors(int n) {\n        vector<int> res({1});\n        auto\
    \ pf = factorize(n);\n\n        for (auto p : pf) {\n            int s = (int)res.size();\n\
    \            for (int i = 0; i < s; ++i) {\n                int v = 1;\n     \
    \           for (int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n};\n\n\n"
  code: "#ifndef MATH_ERATOSTHENES\n#define MATH_ERATOSTHENES 1\n\nstruct Erato {\n\
    \    vector<bool> isprime;\n    vector<int> minfactor;\n    vector<int> mobius;\n\
    \    vector<int> primes;\n\n    Erato(int N) : isprime(N + 1, true), minfactor(N\
    \ + 1, -1),\n                   mobius(N + 1, 1) {\n        isprime[1] = false;\n\
    \        minfactor[1] = 1;\n\n        for (int p = 2; p <= N; ++p) {\n       \
    \     if (!isprime[p]) continue;\n\n            minfactor[p] = p;\n          \
    \  mobius[p] = -1;\n            primes.emplace_back(p);\n            \n      \
    \      for (int q = p * 2; q <= N; q += p) {\n                isprime[q] = false;\n\
    \                \n                if (minfactor[q] == -1) minfactor[q] = p;\n\
    \                if ((q / p) % p == 0) mobius[q] = 0;\n                else mobius[q]\
    \ = -mobius[q];\n            }\n        }\n    }\n\n    vector<pair<int, int>>\
    \ factorize(int n) {\n        vector<pair<int, int>> res;\n        while (n >\
    \ 1) {\n            int p = minfactor[n];\n            int exp = 0;\n\n      \
    \      while (minfactor[n] == p) {\n                n /= p;\n                ++exp;\n\
    \            }\n            res.emplace_back(p, exp);\n        }\n        return\
    \ res;\n    }  \n\n    vector<int> divisors(int n) {\n        vector<int> res({1});\n\
    \        auto pf = factorize(n);\n\n        for (auto p : pf) {\n            int\
    \ s = (int)res.size();\n            for (int i = 0; i < s; ++i) {\n          \
    \      int v = 1;\n                for (int j = 0; j < p.second; ++j) {\n    \
    \                v *= p.first;\n                    res.push_back(res[i] * v);\n\
    \                }\n            }\n        }\n        return res;\n    }\n};\n\
    \n#endif // MATH_ERATOSTHENES\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Eratosthenes.hpp
  requiredBy:
  - convolution/lcm1.hpp
  - convolution/gcd1.hpp
  timestamp: '2024-05-03 16:15:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Eratosthenes.hpp
layout: document
redirect_from:
- /library/math/Eratosthenes.hpp
- /library/math/Eratosthenes.hpp.html
title: math/Eratosthenes.hpp
---
