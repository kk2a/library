---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math_mod/pow_expr.hpp
    title: math_mod/pow_expr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\n\n\n\n#line 1 \"math_mod/pow_expr.hpp\"\
    \n\n\n\nnamespace kk2 {\n\nconstexpr long long pow_mod_constexpr(long long x,\
    \ long long n, long long m) {\n    if (m == 1) return 0;\n    unsigned long long\
    \ _m = (unsigned long long)(m);\n    unsigned long long r = 1;\n    unsigned long\
    \ long y = (x % m + m) % m;\n    while (n) {\n        if (n & 1) r = (r * y) %\
    \ _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n\
    } // namespace kk2\n\n\n#line 5 \"string/rolling_hash.hpp\"\n\nnamespace kk2 {\n\
    \n// setbase() must be called before using Hash\nstruct RollingHash {\n    struct\
    \ Hash {\n        long long h, pw, pwi;\n    };\n    constexpr static int b =\
    \ 5;\n    using T = array<Hash, b>;\n    T table;\n    constexpr static int modp[b]\
    \ = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n    static int\
    \ base[b], basei[b];\n\n    static void setbase() {\n        mt19937_64 rng(time(0));\n\
    \        for (int i = 0; i < b; ++i) {\n            base[i] = rng() % modp[i];\n\
    \            basei[i] = quo(base[i], i);\n        }\n    }\n\n    template <class\
    \ T>\n    RollingHash(const T &v) {\n        for (int i = 0; i < b; ++i) {\n \
    \           table[i].h = v % modp[i];\n            table[i].pw = base[i];\n  \
    \          table[i].pwi = basei[i];\n        }\n    }\n\n    RollingHash(char\
    \ c) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h = c;\n \
    \           table[i].pw = base[i];\n            table[i].pwi = basei[i];\n   \
    \     }\n    }\n\n    template <class T>\n    RollingHash(const vector<T> &v)\
    \ {\n        int n = v.size();\n        for (int i = 0; i < b; ++i) {\n      \
    \      table[i].h = 0;\n            table[i].pw = 1;\n            table[i].pwi\
    \ = 1;\n            for (int j = n - 1; j >= 0; --j) {\n                table[i].h\
    \ = (table[i].h * base[i] + v[j] % modp[i]) % modp[i];\n                table[i].pw\
    \ = table[i].pw * base[i] % modp[i];\n                table[i].pwi = table[i].pwi\
    \ * basei[i] % modp[i];\n            }\n        }\n    }\n\n    RollingHash(const\
    \ string &s) {\n        int n = s.size();\n        for (int i = 0; i < b; ++i)\
    \ {\n            table[i].h = 0;\n            table[i].pw = 1;\n            table[i].pwi\
    \ = 1;\n            for (int j = n - 1; j >= 0; --j) {\n                table[i].h\
    \ = (table[i].h * base[i] + s[j]) % modp[i];\n                table[i].pw = table[i].pw\
    \ * base[i] % modp[i];\n                table[i].pwi = table[i].pwi * basei[i]\
    \ % modp[i];\n            }\n        }\n    }\n\n    RollingHash() {\n       \
    \ for (int i = 0; i < b; ++i) {\n            table[i].h = 0;\n            table[i].pw\
    \ = 1;\n            table[i].pwi = 1;\n        }\n    }\n\n    RollingHash& push_front(const\
    \ RollingHash &otherHash) {\n        for (int i = 0; i < b; ++i) {\n         \
    \   table[i].h = (otherHash.table[i].h + table[i].h * otherHash.table[i].pw) %\
    \ modp[i];\n            table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n\
    \            table[i].pwi = table[i].pwi * otherHash.table[i].pwi % modp[i];\n\
    \        }\n        return *this;\n    }\n\n    RollingHash& push_back(const RollingHash\
    \ &otherHash) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h\
    \ = (table[i].h + otherHash.table[i].h * table[i].pw) % modp[i];\n           \
    \ table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n            table[i].pwi\
    \ = table[i].pwi * otherHash.table[i].pwi % modp[i];\n        }\n        return\
    \ *this;\n    }\n\n    RollingHash& pop_front(const RollingHash &otherHash) {\n\
    \        for (int i = 0; i < b; ++i) {\n            table[i].h = (table[i].h -\
    \ otherHash.table[i].h) * otherHash.table[i].pwi % modp[i];\n            if (table[i].h\
    \ < 0) table[i].h += modp[i];\n            table[i].pw = table[i].pw * otherHash.table[i].pwi\
    \ % modp[i];\n            table[i].pwi = table[i].pwi * otherHash.table[i].pw\
    \ % modp[i];\n        }\n        return *this;\n    }\n\n    RollingHash& pop_back(const\
    \ RollingHash &otherHash) {\n        for (int i = 0; i < b; ++i) {\n         \
    \   long long minus = otherHash.table[i].h * table[i].pw % modp[i] * otherHash.table[i].pwi\
    \ % modp[i];\n            table[i].h = (table[i].h - minus) % modp[i];\n     \
    \       if (table[i].h < 0) table[i].h += modp[i];\n            table[i].pw =\
    \ table[i].pw * otherHash.table[i].pwi % modp[i];\n            table[i].pwi =\
    \ table[i].pwi * otherHash.table[i].pw % modp[i];\n        }\n        return *this;\n\
    \    }\n\n    friend bool operator==(const RollingHash &lhs, const RollingHash\
    \ &rhs) {\n        for (int i = 0; i < b; ++i) {\n            if (lhs.table[i].h\
    \ != rhs.table[i].h) return false;\n            if (lhs.table[i].pw != rhs.table[i].pw)\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ RollingHash &lhs, const RollingHash &rhs) {\n        return !(lhs == rhs);\n\
    \    }\n\n  private:\n    constexpr static long long quo(long long a, int i) {\n\
    \        return pow_mod_constexpr(a, modp[i] - 2, modp[i]);\n    } \n};\n\nint\
    \ RollingHash::base[5] = {3, 3, 3, 3, 3};\nint RollingHash::basei[5] = {332748118,\
    \ 333333336, 666666673, 666666681, 666666689};\n\n\nusing Roliha = RollingHash;\n\
    \n} // namespace kk2\n\n\n\n"
  code: "#ifndef ROLLING_HASH_HPP\n#define ROLLING_HASH_HPP 1\n\n#include \"../math_mod/pow_expr.hpp\"\
    \n\nnamespace kk2 {\n\n// setbase() must be called before using Hash\nstruct RollingHash\
    \ {\n    struct Hash {\n        long long h, pw, pwi;\n    };\n    constexpr static\
    \ int b = 5;\n    using T = array<Hash, b>;\n    T table;\n    constexpr static\
    \ int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n\
    \    static int base[b], basei[b];\n\n    static void setbase() {\n        mt19937_64\
    \ rng(time(0));\n        for (int i = 0; i < b; ++i) {\n            base[i] =\
    \ rng() % modp[i];\n            basei[i] = quo(base[i], i);\n        }\n    }\n\
    \n    template <class T>\n    RollingHash(const T &v) {\n        for (int i =\
    \ 0; i < b; ++i) {\n            table[i].h = v % modp[i];\n            table[i].pw\
    \ = base[i];\n            table[i].pwi = basei[i];\n        }\n    }\n\n    RollingHash(char\
    \ c) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h = c;\n \
    \           table[i].pw = base[i];\n            table[i].pwi = basei[i];\n   \
    \     }\n    }\n\n    template <class T>\n    RollingHash(const vector<T> &v)\
    \ {\n        int n = v.size();\n        for (int i = 0; i < b; ++i) {\n      \
    \      table[i].h = 0;\n            table[i].pw = 1;\n            table[i].pwi\
    \ = 1;\n            for (int j = n - 1; j >= 0; --j) {\n                table[i].h\
    \ = (table[i].h * base[i] + v[j] % modp[i]) % modp[i];\n                table[i].pw\
    \ = table[i].pw * base[i] % modp[i];\n                table[i].pwi = table[i].pwi\
    \ * basei[i] % modp[i];\n            }\n        }\n    }\n\n    RollingHash(const\
    \ string &s) {\n        int n = s.size();\n        for (int i = 0; i < b; ++i)\
    \ {\n            table[i].h = 0;\n            table[i].pw = 1;\n            table[i].pwi\
    \ = 1;\n            for (int j = n - 1; j >= 0; --j) {\n                table[i].h\
    \ = (table[i].h * base[i] + s[j]) % modp[i];\n                table[i].pw = table[i].pw\
    \ * base[i] % modp[i];\n                table[i].pwi = table[i].pwi * basei[i]\
    \ % modp[i];\n            }\n        }\n    }\n\n    RollingHash() {\n       \
    \ for (int i = 0; i < b; ++i) {\n            table[i].h = 0;\n            table[i].pw\
    \ = 1;\n            table[i].pwi = 1;\n        }\n    }\n\n    RollingHash& push_front(const\
    \ RollingHash &otherHash) {\n        for (int i = 0; i < b; ++i) {\n         \
    \   table[i].h = (otherHash.table[i].h + table[i].h * otherHash.table[i].pw) %\
    \ modp[i];\n            table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n\
    \            table[i].pwi = table[i].pwi * otherHash.table[i].pwi % modp[i];\n\
    \        }\n        return *this;\n    }\n\n    RollingHash& push_back(const RollingHash\
    \ &otherHash) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h\
    \ = (table[i].h + otherHash.table[i].h * table[i].pw) % modp[i];\n           \
    \ table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n            table[i].pwi\
    \ = table[i].pwi * otherHash.table[i].pwi % modp[i];\n        }\n        return\
    \ *this;\n    }\n\n    RollingHash& pop_front(const RollingHash &otherHash) {\n\
    \        for (int i = 0; i < b; ++i) {\n            table[i].h = (table[i].h -\
    \ otherHash.table[i].h) * otherHash.table[i].pwi % modp[i];\n            if (table[i].h\
    \ < 0) table[i].h += modp[i];\n            table[i].pw = table[i].pw * otherHash.table[i].pwi\
    \ % modp[i];\n            table[i].pwi = table[i].pwi * otherHash.table[i].pw\
    \ % modp[i];\n        }\n        return *this;\n    }\n\n    RollingHash& pop_back(const\
    \ RollingHash &otherHash) {\n        for (int i = 0; i < b; ++i) {\n         \
    \   long long minus = otherHash.table[i].h * table[i].pw % modp[i] * otherHash.table[i].pwi\
    \ % modp[i];\n            table[i].h = (table[i].h - minus) % modp[i];\n     \
    \       if (table[i].h < 0) table[i].h += modp[i];\n            table[i].pw =\
    \ table[i].pw * otherHash.table[i].pwi % modp[i];\n            table[i].pwi =\
    \ table[i].pwi * otherHash.table[i].pw % modp[i];\n        }\n        return *this;\n\
    \    }\n\n    friend bool operator==(const RollingHash &lhs, const RollingHash\
    \ &rhs) {\n        for (int i = 0; i < b; ++i) {\n            if (lhs.table[i].h\
    \ != rhs.table[i].h) return false;\n            if (lhs.table[i].pw != rhs.table[i].pw)\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ RollingHash &lhs, const RollingHash &rhs) {\n        return !(lhs == rhs);\n\
    \    }\n\n  private:\n    constexpr static long long quo(long long a, int i) {\n\
    \        return pow_mod_constexpr(a, modp[i] - 2, modp[i]);\n    } \n};\n\nint\
    \ RollingHash::base[5] = {3, 3, 3, 3, 3};\nint RollingHash::basei[5] = {332748118,\
    \ 333333336, 666666673, 666666681, 666666689};\n\n\nusing Roliha = RollingHash;\n\
    \n} // namespace kk2\n\n\n#endif // ROLLING_HASH_HPP\n"
  dependsOn:
  - math_mod/pow_expr.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
