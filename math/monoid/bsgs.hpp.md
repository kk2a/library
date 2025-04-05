---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/monoid/pow.hpp
    title: math/monoid/pow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/bsgs.hpp\"\n\n\n\n#include <cmath>\n#include\
    \ <unordered_set>\n\n#line 1 \"math/monoid/pow.hpp\"\n\n\n\nnamespace kk2 {\n\n\
    namespace monoid {\n\ntemplate <class M> M pow(M a, long long n) {\n    M res\
    \ = M::unit();\n    while (n > 0) {\n        if (n & 1) res = M::op(res, a);\n\
    \        if (n >>= 1) a = M::op(a, a);\n    }\n    return res;\n}\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n#line 8 \"math/monoid/bsgs.hpp\"\n\nnamespace\
    \ kk2 {\n\n// if there exists 0 <= l < n s.t. s^l = t, return min{0 <= l < n :\
    \ s^l = t}\n// otherwise, return -1\ntemplate <class M,\n          M (*op)(M,\
    \ M),\n          M (*e)(),\n          class S,\n          S (*act)(M, S),\n  \
    \        class Set = std::unordered_set<S>>\nlong long bsgs(S s, S t, M x, long\
    \ long n) {\n    if (n <= 0) return -1;\n    if (s == t) return 0;\n    // \u3053\
    \u3053\u306F\u9069\u5F53\n    long long m = std::sqrt(n);\n    Set set;\n    S\
    \ now = t;\n    for (long long i = 0; i < m; i++) {\n        now = act(x, now);\n\
    \        set.insert(now);\n    }\n    M x_mth_pw = pow<M, op, e>(x, m);\n    now\
    \ = s;\n    for (long long i = 0; i * m < n; i++) {\n        S next = act(x_mth_pw,\
    \ now);\n        if (set.count(next)) {\n            S tmp = now;\n          \
    \  for (long long j = 0; j < m; j++) {\n                if (tmp == t) return i\
    \ * m + j;\n                if (j != m - 1) tmp = act(x, tmp);\n            }\n\
    \        }\n        now = next;\n    }\n    return -1;\n}\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef KK2_MATH_MONOID_BSGS_HPP\n#define KK2_MATH_MONOID_BSGS_HPP 1\n\n\
    #include <cmath>\n#include <unordered_set>\n\n#include \"pow.hpp\"\n\nnamespace\
    \ kk2 {\n\n// if there exists 0 <= l < n s.t. s^l = t, return min{0 <= l < n :\
    \ s^l = t}\n// otherwise, return -1\ntemplate <class M,\n          M (*op)(M,\
    \ M),\n          M (*e)(),\n          class S,\n          S (*act)(M, S),\n  \
    \        class Set = std::unordered_set<S>>\nlong long bsgs(S s, S t, M x, long\
    \ long n) {\n    if (n <= 0) return -1;\n    if (s == t) return 0;\n    // \u3053\
    \u3053\u306F\u9069\u5F53\n    long long m = std::sqrt(n);\n    Set set;\n    S\
    \ now = t;\n    for (long long i = 0; i < m; i++) {\n        now = act(x, now);\n\
    \        set.insert(now);\n    }\n    M x_mth_pw = pow<M, op, e>(x, m);\n    now\
    \ = s;\n    for (long long i = 0; i * m < n; i++) {\n        S next = act(x_mth_pw,\
    \ now);\n        if (set.count(next)) {\n            S tmp = now;\n          \
    \  for (long long j = 0; j < m; j++) {\n                if (tmp == t) return i\
    \ * m + j;\n                if (j != m - 1) tmp = act(x, tmp);\n            }\n\
    \        }\n        now = next;\n    }\n    return -1;\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_MATH_MONOID_BSGS_HPP\n"
  dependsOn:
  - math/monoid/pow.hpp
  isVerificationFile: false
  path: math/monoid/bsgs.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/bsgs.hpp
layout: document
redirect_from:
- /library/math/monoid/bsgs.hpp
- /library/math/monoid/bsgs.hpp.html
title: math/monoid/bsgs.hpp
---
