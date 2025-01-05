---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/poly_sample_point_shift.test.cpp
    title: verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/many_factrials.test.cpp
    title: verify/yosupo_math/many_factrials.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/poly_sample_point_shift.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nstd::vector<mint> sample_point_shift(std::vector<mint> &y,\
    \ mint t, int m = -1) {\n    if (m == -1) m = y.size();\n    long long tval =\
    \ t.val();\n    int k = (int)y.size() - 1;\n    if (tval <= k) {\n        std::vector<mint>\
    \ ret(m);\n        int ptr = 0;\n        for (long long i = tval; i <= k and ptr\
    \ < m; i++) { ret[ptr++] = y[i]; }\n        if (k + 1 < tval + m) {\n        \
    \    auto suf = sample_point_shift<FPS>(y, mint(k + 1), m - ptr);\n          \
    \  for (int i = k + 1; i < tval + m; i++) { ret[ptr++] = suf[i - (k + 1)]; }\n\
    \        }\n        return ret;\n    }\n    if (tval + m > mint::getmod()) {\n\
    \        auto pref = sample_point_shift<FPS>(y, t, mint::getmod() - tval);\n \
    \       auto suf = sample_point_shift<FPS>(y, mint(0), m + tval - (int)mint::getmod());\n\
    \        std::copy(std::begin(suf), std::end(suf), std::back_inserter(pref));\n\
    \        return pref;\n    }\n\n    std::vector<mint> inv(k + 1, 1);\n    FPS\
    \ d(k + 1);\n    for (int i = 2; i <= k; i++) inv[k] *= i;\n    inv[k] = inv[k].inv();\n\
    \    for (int i = k; i >= 1; i--) inv[i - 1] = inv[i] * i;\n    for (int i = 0;\
    \ i <= k; i++) {\n        d[i] = inv[i] * inv[k - i] * y[i];\n        if ((k -\
    \ i) & 1) d[i] = -d[i];\n    }\n\n    FPS h(m + k);\n    for (int i = 0; i < m\
    \ + k; i++) { h[i] = (t - k + i).inv(); }\n\n    FPS dh = d * h;\n\n    std::vector<mint>\
    \ ret(m);\n    mint cur = t;\n    for (int i = 1; i <= k; i++) cur *= t - i;\n\
    \    for (int i = 0; i < m; i++) {\n        ret[i] = cur * dh[k + i];\n      \
    \  cur *= t + i + 1;\n        cur *= h[i];\n    }\n    return ret;\n}\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP\n#define KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint> sample_point_shift(std::vector<mint>\
    \ &y, mint t, int m = -1) {\n    if (m == -1) m = y.size();\n    long long tval\
    \ = t.val();\n    int k = (int)y.size() - 1;\n    if (tval <= k) {\n        std::vector<mint>\
    \ ret(m);\n        int ptr = 0;\n        for (long long i = tval; i <= k and ptr\
    \ < m; i++) { ret[ptr++] = y[i]; }\n        if (k + 1 < tval + m) {\n        \
    \    auto suf = sample_point_shift<FPS>(y, mint(k + 1), m - ptr);\n          \
    \  for (int i = k + 1; i < tval + m; i++) { ret[ptr++] = suf[i - (k + 1)]; }\n\
    \        }\n        return ret;\n    }\n    if (tval + m > mint::getmod()) {\n\
    \        auto pref = sample_point_shift<FPS>(y, t, mint::getmod() - tval);\n \
    \       auto suf = sample_point_shift<FPS>(y, mint(0), m + tval - (int)mint::getmod());\n\
    \        std::copy(std::begin(suf), std::end(suf), std::back_inserter(pref));\n\
    \        return pref;\n    }\n\n    std::vector<mint> inv(k + 1, 1);\n    FPS\
    \ d(k + 1);\n    for (int i = 2; i <= k; i++) inv[k] *= i;\n    inv[k] = inv[k].inv();\n\
    \    for (int i = k; i >= 1; i--) inv[i - 1] = inv[i] * i;\n    for (int i = 0;\
    \ i <= k; i++) {\n        d[i] = inv[i] * inv[k - i] * y[i];\n        if ((k -\
    \ i) & 1) d[i] = -d[i];\n    }\n\n    FPS h(m + k);\n    for (int i = 0; i < m\
    \ + k; i++) { h[i] = (t - k + i).inv(); }\n\n    FPS dh = d * h;\n\n    std::vector<mint>\
    \ ret(m);\n    mint cur = t;\n    for (int i = 1; i <= k; i++) cur *= t - i;\n\
    \    for (int i = 0; i < m; i++) {\n        ret[i] = cur * dh[k + i];\n      \
    \  cur *= t + i + 1;\n        cur *= h[i];\n    }\n    return ret;\n}\n\n} //\
    \ namespace kk2\n\n#endif // KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/poly_sample_point_shift.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
documentation_of: fps/poly_sample_point_shift.hpp
layout: document
redirect_from:
- /library/fps/poly_sample_point_shift.hpp
- /library/fps/poly_sample_point_shift.hpp.html
title: fps/poly_sample_point_shift.hpp
---
