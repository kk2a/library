---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math_mod/binom_table.test.cpp
    title: verify/unit_test/math_mod/binom_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/binom_table.hpp\"\n\n\n\n#include <vector>\n\n\
    namespace kk2 {\n\ntemplate <class mint> struct BinomTable {\n    static inline\
    \ std::vector<std::vector<mint>> _binom{{1}};\n\n    BinomTable() = delete;\n\n\
    \    static void set_upper(int m) {\n        int n = (int)_binom.size() - 1;\n\
    \        if (n >= m) return;\n        _binom.resize(m + 1);\n        for (int\
    \ i = n + 1; i <= m; i++) {\n            _binom[i].resize(i + 1);\n          \
    \  _binom[i][0] = _binom[i][i] = 1;\n            for (int j = 1; j < i; j++) _binom[i][j]\
    \ = _binom[i - 1][j - 1] + _binom[i - 1][j];\n        }\n    }\n\n    static mint\
    \ binom(int n, int k) {\n        if (k < 0 || k > n) return 0;\n        if ((int)_binom.size()\
    \ <= n) set_upper(n);\n        return _binom[n][k];\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_MATH_MOD_BINOM_TABLE_HPP\n#define KK2_MATH_MOD_BINOM_TABLE_HPP\
    \ 1\n\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class mint> struct BinomTable\
    \ {\n    static inline std::vector<std::vector<mint>> _binom{{1}};\n\n    BinomTable()\
    \ = delete;\n\n    static void set_upper(int m) {\n        int n = (int)_binom.size()\
    \ - 1;\n        if (n >= m) return;\n        _binom.resize(m + 1);\n        for\
    \ (int i = n + 1; i <= m; i++) {\n            _binom[i].resize(i + 1);\n     \
    \       _binom[i][0] = _binom[i][i] = 1;\n            for (int j = 1; j < i; j++)\
    \ _binom[i][j] = _binom[i - 1][j - 1] + _binom[i - 1][j];\n        }\n    }\n\n\
    \    static mint binom(int n, int k) {\n        if (k < 0 || k > n) return 0;\n\
    \        if ((int)_binom.size() <= n) set_upper(n);\n        return _binom[n][k];\n\
    \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_MOD_BINOM_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/binom_table.hpp
  requiredBy: []
  timestamp: '2025-06-04 12:11:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math_mod/binom_table.test.cpp
documentation_of: math_mod/binom_table.hpp
layout: document
redirect_from:
- /library/math_mod/binom_table.hpp
- /library/math_mod/binom_table.hpp.html
title: math_mod/binom_table.hpp
---
