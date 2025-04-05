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
  bundledCode: "#line 1 \"fps/bostan_mori.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
    \ kk2 {\n\n// return [x^n] (p(x) / q(x))\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nmint bostan_mori(const FPS &p, const FPS &q, long long n)\
    \ {\n    assert(!p.empty() && !q.empty());\n    if (n == 0) return p[0] / q[0];\n\
    \n    int qsz = q.size();\n    FPS mq(q);\n    for (int i = 1; i < qsz; i += 2)\
    \ mq[i] = -mq[i];\n    FPS p2(p);\n    p2.resize(qsz - 1);\n    p2 *= mq;\n  \
    \  FPS q2 = q * mq;\n    FPS pp(qsz - 1), qq(qsz);\n    for (int i = 0; i < qsz\
    \ - 1; i++) { pp[i] = (n & 1) ? p2[2 * i + 1] : p2[2 * i]; }\n    for (int i =\
    \ 0; i < qsz; i++) { qq[i] = q2[2 * i]; }\n    return bostan_mori(pp, qq, n >>\
    \ 1);\n}\n\n// a_i = \\sum_{j=0}^{d-1} c_ja_{i-j-1} (i >= d)\n// return a_k\n\
    template <class FPS, class mint = typename FPS::value_type>\nmint kth_term_of_linearly_recurrent_sequence(const\
    \ FPS &a, const FPS &c, long long k) {\n    if (k < (long long)a.size()) return\
    \ a[k];\n    return bostan_mori((a * (-(c << 1) + mint(1))).pre(a.size()), -(c\
    \ << 1) + mint(1), k);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_BOSTAN_MORI_HPP\n#define KK2_FPS_BOSTAN_MORI_HPP 1\n\n#include\
    \ <cassert>\n\nnamespace kk2 {\n\n// return [x^n] (p(x) / q(x))\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nmint bostan_mori(const FPS &p,\
    \ const FPS &q, long long n) {\n    assert(!p.empty() && !q.empty());\n    if\
    \ (n == 0) return p[0] / q[0];\n\n    int qsz = q.size();\n    FPS mq(q);\n  \
    \  for (int i = 1; i < qsz; i += 2) mq[i] = -mq[i];\n    FPS p2(p);\n    p2.resize(qsz\
    \ - 1);\n    p2 *= mq;\n    FPS q2 = q * mq;\n    FPS pp(qsz - 1), qq(qsz);\n\
    \    for (int i = 0; i < qsz - 1; i++) { pp[i] = (n & 1) ? p2[2 * i + 1] : p2[2\
    \ * i]; }\n    for (int i = 0; i < qsz; i++) { qq[i] = q2[2 * i]; }\n    return\
    \ bostan_mori(pp, qq, n >> 1);\n}\n\n// a_i = \\sum_{j=0}^{d-1} c_ja_{i-j-1} (i\
    \ >= d)\n// return a_k\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    mint kth_term_of_linearly_recurrent_sequence(const FPS &a, const FPS &c, long\
    \ long k) {\n    if (k < (long long)a.size()) return a[k];\n    return bostan_mori((a\
    \ * (-(c << 1) + mint(1))).pre(a.size()), -(c << 1) + mint(1), k);\n}\n\n} //\
    \ namespace kk2\n\n#endif // KK2_FPS_BOSTAN_MORI_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/bostan_mori.hpp
  requiredBy: []
  timestamp: '2025-03-09 17:35:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/bostan_mori.hpp
layout: document
redirect_from:
- /library/fps/bostan_mori.hpp
- /library/fps/bostan_mori.hpp.html
title: fps/bostan_mori.hpp
---
