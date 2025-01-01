---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math_mod/inv.hpp
    title: math_mod/inv.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_arb.hpp
    title: convolution/convolution_arb.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    title: verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp_arb.test.cpp
    title: verify/yosupo_fps/fps_exp_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv_arb.test.cpp
    title: verify/yosupo_fps/fps_inv_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log_arb.test.cpp
    title: verify/yosupo_fps/fps_log_arb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/garner.hpp\"\n\n\n\n#include <vector>\n\n#line\
    \ 1 \"math_mod/inv.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace kk2 {\n\n//\
    \ require: modulo >= 1\ntemplate <class T> constexpr T mod_inversion(T a, T modulo)\
    \ {\n    a %= modulo;\n    if (a < 0) a += modulo;\n    T s = modulo, t = a;\n\
    \    T m0 = 0, m1 = 1;\n    while (t) {\n        T u = s / t;\n        std::swap(s\
    \ -= t * u, t);\n        std::swap(m0 -= m1 * u, m1);\n    }\n    if (m0 < 0)\
    \ m0 += modulo;\n    return m0;\n}\n\n} // namespace kk2\n\n\n#line 7 \"math_mod/garner.hpp\"\
    \n\nnamespace kk2 {\n\n// d.size() + 1 == p.size()\nlong long garner(const std::vector<long\
    \ long> &d, const std::vector<long long> &p) {\n    int nm = d.size();\n    std::vector<long\
    \ long> kp(nm + 1, 0), rmult(nm + 1, 1);\n    for (int ii = 0; ii < nm; ii++)\
    \ {\n        long long x = (d[ii] - kp[ii]) * mod_inversion(rmult[ii], p[ii])\
    \ % p[ii];\n        if (x < 0) x += p[ii];\n        for (int iii = ii + 1; iii\
    \ < nm + 1; iii++) {\n            kp[iii] = (kp[iii] + rmult[iii] * x) % p[iii];\n\
    \            rmult[iii] = (rmult[iii] * p[ii]) % p[iii];\n        }\n    }\n \
    \   return kp[nm];\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MOD_GARNER_HPP\n#define MOD_GARNER_HPP 1\n\n#include <vector>\n\n\
    #include \"inv.hpp\"\n\nnamespace kk2 {\n\n// d.size() + 1 == p.size()\nlong long\
    \ garner(const std::vector<long long> &d, const std::vector<long long> &p) {\n\
    \    int nm = d.size();\n    std::vector<long long> kp(nm + 1, 0), rmult(nm +\
    \ 1, 1);\n    for (int ii = 0; ii < nm; ii++) {\n        long long x = (d[ii]\
    \ - kp[ii]) * mod_inversion(rmult[ii], p[ii]) % p[ii];\n        if (x < 0) x +=\
    \ p[ii];\n        for (int iii = ii + 1; iii < nm + 1; iii++) {\n            kp[iii]\
    \ = (kp[iii] + rmult[iii] * x) % p[iii];\n            rmult[iii] = (rmult[iii]\
    \ * p[ii]) % p[iii];\n        }\n    }\n    return kp[nm];\n}\n\n} // namespace\
    \ kk2\n\n#endif // MOD_GARNER_HPP\n"
  dependsOn:
  - math_mod/inv.hpp
  isVerificationFile: false
  path: math_mod/garner.hpp
  requiredBy:
  - convolution/convolution_arb.hpp
  - fps/fps_arb.hpp
  timestamp: '2024-10-16 14:12:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_fps/fps_inv_arb.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_log_arb.test.cpp
documentation_of: math_mod/garner.hpp
layout: document
redirect_from:
- /library/math_mod/garner.hpp
- /library/math_mod/garner.hpp.html
title: math_mod/garner.hpp
---
