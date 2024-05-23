---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/inv.hpp
    title: mod/inv.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/garner.hpp\"\n\n\n\n#line 1 \"mod/inv.hpp\"\n\n\n\n\
    template <class T, class U>\nconstexpr long long mod_inversion(T a, U modulo)\
    \ {\n    long long s = modulo, t = a;\n    long long m0 = 0, m1 = 1;\n    while\
    \ (t) {\n        long long u = s / t;\n        swap(s -= t * u, t);\n        swap(m0\
    \ -= m1 * u, m1);\n    }\n    if (m0 < 0) m0 += modulo / s;\n    return m0;\n\
    }\n\n\n#line 5 \"mod/garner.hpp\"\n\nlong long garner(const vector<long long>&\
    \ d, const vector<long long>& p) {\n    static int nm = d.size();\n    vector<long\
    \ long> kp(nm + 1, 0), rmult(nm + 1, 1);\n    for (int ii = 0; ii < nm; ii++)\
    \ {\n        long long x = (d[ii] - kp[ii]) * mod_inversion(rmult[ii], p[ii])\
    \ % p[ii];\n        x = (x + p[ii]) % p[ii];\n        for (int iii = ii + 1; iii\
    \ < nm + 1; iii++) {\n            kp[iii] = (kp[iii] + rmult[iii] * x) % p[iii];\n\
    \            rmult[iii] = (rmult[iii] * p[ii]) % p[iii];\n        }\n    }\n \
    \   return kp[nm];\n}\n\n\n"
  code: "#ifndef MOD_GARNER_HPP\n#define MOD_GARNER_HPP 1\n\n#include \"inv.hpp\"\n\
    \nlong long garner(const vector<long long>& d, const vector<long long>& p) {\n\
    \    static int nm = d.size();\n    vector<long long> kp(nm + 1, 0), rmult(nm\
    \ + 1, 1);\n    for (int ii = 0; ii < nm; ii++) {\n        long long x = (d[ii]\
    \ - kp[ii]) * mod_inversion(rmult[ii], p[ii]) % p[ii];\n        x = (x + p[ii])\
    \ % p[ii];\n        for (int iii = ii + 1; iii < nm + 1; iii++) {\n          \
    \  kp[iii] = (kp[iii] + rmult[iii] * x) % p[iii];\n            rmult[iii] = (rmult[iii]\
    \ * p[ii]) % p[iii];\n        }\n    }\n    return kp[nm];\n}\n\n#endif // MOD_GARNER_HPP\n"
  dependsOn:
  - mod/inv.hpp
  isVerificationFile: false
  path: mod/garner.hpp
  requiredBy:
  - fps/fps_arb.hpp
  - convolution/convo_arb.hpp
  timestamp: '2024-05-14 00:13:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/garner.hpp
layout: document
redirect_from:
- /library/mod/garner.hpp
- /library/mod/garner.hpp.html
title: mod/garner.hpp
---