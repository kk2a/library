---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/sample_point_shift.hpp\"\n\n\n\nnamespace kk2 {\n\n\
    template <class FPS, class mint = typename FPS::value_type>\nvector<mint> SamplePointShift(vector<mint>\
    \ &y, mint t, int m = -1) {\n    if (m == -1) m = y.size();\n    long long tval\
    \ = t.val();\n    int k = (int)y.size() - 1;\n    if (tval <= k) {\n        FPS\
    \ ret(m);\n        int ptr = 0;\n        for (long long i = tval; i <= k and ptr\
    \ < m; i++) {\n            ret[ptr++] = y[i];\n        }\n        if (k + 1 <\
    \ tval + m) {\n            auto suf = SamplePointShift<FPS>(y, mint(k + 1), m\
    \ - ptr);\n            for (int i = k + 1; i < tval + m; i++) {\n            \
    \    ret[ptr++] = suf[i - (k + 1)];\n            }\n        }\n        return\
    \ ret;\n    }\n    if (tval + m > mint::getmod()) {\n        auto pref = SamplePointShift<FPS>(y,\
    \ mint(t), mint::getmod() - tval);\n        auto suf = SamplePointShift<FPS>(y,\
    \ mint(0), m - (int)pref.size());\n        copy(begin(suf), end(suf), back_inserter(pref));\n\
    \        return pref;\n    }\n\n    vector<mint> inv(k + 1, 1);\n    FPS d(k +\
    \ 1);\n    for (int i = 2; i <= k; i++) inv[k] *= i;\n    inv[k] = inv[k].inv();\n\
    \    for (int i = k; i >= 1; i--) inv[i - 1] = inv[i] * i;\n    for (int i = 0;\
    \ i <= k; i++) {\n        d[i] = inv[i] * inv[k - i] * y[i];\n        if ((k -\
    \ i) & 1) d[i] = -d[i];\n    }\n\n    FPS h(m + k);\n    for (int i = 0; i < m\
    \ + k; i++) {\n        h[i] = (t - k + i).inv();\n    }\n\n    FPS dh = d * h;\n\
    \n    vector<mint> ret(m);\n    mint cur = t;\n    for (int i = 1; i <= k; i++)\
    \ cur *= t - i;\n    for (int i = 0; i < m; i++) {\n        ret[i] = cur * dh[k\
    \ + i];\n        cur *= t + i + 1;\n        cur *= h[i];\n    }\n    return ret;\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef FPS__SAMPLE_POINT_SHIFT_HPP\n#define FPS__SAMPLE_POINT_SHIFT_HPP\
    \ 1\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    vector<mint> SamplePointShift(vector<mint> &y, mint t, int m = -1) {\n    if (m\
    \ == -1) m = y.size();\n    long long tval = t.val();\n    int k = (int)y.size()\
    \ - 1;\n    if (tval <= k) {\n        FPS ret(m);\n        int ptr = 0;\n    \
    \    for (long long i = tval; i <= k and ptr < m; i++) {\n            ret[ptr++]\
    \ = y[i];\n        }\n        if (k + 1 < tval + m) {\n            auto suf =\
    \ SamplePointShift<FPS>(y, mint(k + 1), m - ptr);\n            for (int i = k\
    \ + 1; i < tval + m; i++) {\n                ret[ptr++] = suf[i - (k + 1)];\n\
    \            }\n        }\n        return ret;\n    }\n    if (tval + m > mint::getmod())\
    \ {\n        auto pref = SamplePointShift<FPS>(y, mint(t), mint::getmod() - tval);\n\
    \        auto suf = SamplePointShift<FPS>(y, mint(0), m - (int)pref.size());\n\
    \        copy(begin(suf), end(suf), back_inserter(pref));\n        return pref;\n\
    \    }\n\n    vector<mint> inv(k + 1, 1);\n    FPS d(k + 1);\n    for (int i =\
    \ 2; i <= k; i++) inv[k] *= i;\n    inv[k] = inv[k].inv();\n    for (int i = k;\
    \ i >= 1; i--) inv[i - 1] = inv[i] * i;\n    for (int i = 0; i <= k; i++) {\n\
    \        d[i] = inv[i] * inv[k - i] * y[i];\n        if ((k - i) & 1) d[i] = -d[i];\n\
    \    }\n\n    FPS h(m + k);\n    for (int i = 0; i < m + k; i++) {\n        h[i]\
    \ = (t - k + i).inv();\n    }\n\n    FPS dh = d * h;\n\n    vector<mint> ret(m);\n\
    \    mint cur = t;\n    for (int i = 1; i <= k; i++) cur *= t - i;\n    for (int\
    \ i = 0; i < m; i++) {\n        ret[i] = cur * dh[k + i];\n        cur *= t +\
    \ i + 1;\n        cur *= h[i];\n    }\n    return ret;\n}\n\n} // namespace kk2\n\
    \n#endif // FPS__SAMPLE_POINT_SHIFT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/sample_point_shift.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/sample_point_shift.hpp
layout: document
redirect_from:
- /library/fps/sample_point_shift.hpp
- /library/fps/sample_point_shift.hpp.html
title: fps/sample_point_shift.hpp
---
