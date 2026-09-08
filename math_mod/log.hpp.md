---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: discrete_logarithm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/discrete_logarithm.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_MOD_LOG_HPP\n#define KK2_MATH_MOD_LOG_HPP 1\n\n#include\
      \ <cmath>\n#include <unordered_set>\n\nnamespace kk2 {\n\n// if there exists\
      \ 0 <= l < n s.t. x^l = t, return min{0 <= l < n : x^l = t}\n// otherwise, return\
      \ -1\ntemplate <class mint, class HashSet = std::unordered_set<long long>>\n\
      long long discrete_logarithm(mint x, mint t) {\n    if (t == mint(1)) return\
      \ 0;\n    HashSet set;\n    long long m = std::sqrt(mint::getmod());\n    mint\
      \ now = t;\n    for (long long i = 0; i < m; i++) {\n        now *= x;\n   \
      \     set.insert(now.val());\n    }\n    mint x_mth_pw = x.pow(m);\n    now\
      \ = 1;\n    for (long long i = 0; i * m < mint::getmod(); i++) {\n        mint\
      \ next = now * x_mth_pw;\n        if (set.count(next.val())) {\n           \
      \ mint tmp = now;\n            for (long long j = 0; j < m; j++) {\n       \
      \         if (tmp == t) return i * m + j;\n                if (j != m - 1) tmp\
      \ *= x;\n            }\n        }\n        now = next;\n    }\n    return -1;\n\
      }\n\n} // namespace kk2\n\n#endif // KK2_MATH_MOD_LOG_HPP\n"
    name: default
  - code: "#line 1 \"math_mod/log.hpp\"\n\n\n\n#include <cmath>\n#include <unordered_set>\n\
      \nnamespace kk2 {\n\n// if there exists 0 <= l < n s.t. x^l = t, return min{0\
      \ <= l < n : x^l = t}\n// otherwise, return -1\ntemplate <class mint, class\
      \ HashSet = std::unordered_set<long long>>\nlong long discrete_logarithm(mint\
      \ x, mint t) {\n    if (t == mint(1)) return 0;\n    HashSet set;\n    long\
      \ long m = std::sqrt(mint::getmod());\n    mint now = t;\n    for (long long\
      \ i = 0; i < m; i++) {\n        now *= x;\n        set.insert(now.val());\n\
      \    }\n    mint x_mth_pw = x.pow(m);\n    now = 1;\n    for (long long i =\
      \ 0; i * m < mint::getmod(); i++) {\n        mint next = now * x_mth_pw;\n \
      \       if (set.count(next.val())) {\n            mint tmp = now;\n        \
      \    for (long long j = 0; j < m; j++) {\n                if (tmp == t) return\
      \ i * m + j;\n                if (j != m - 1) tmp *= x;\n            }\n   \
      \     }\n        now = next;\n    }\n    return -1;\n}\n\n} // namespace kk2\n\
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math_mod/log.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/discrete_logarithm.test.cpp
documentation_of: math_mod/log.hpp
layout: document
---
