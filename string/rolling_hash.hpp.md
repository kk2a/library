---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\n\n\nconstexpr long long pow_mod_constexpr(long long x, long long n, long long\
    \ m) {\n    if (m == 1) return 0;\n    unsigned long long _m = (unsigned long\
    \ long)(m);\n    unsigned long long r = 1;\n    unsigned long long y = (x % m\
    \ + m) % m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y\
    \ = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n\n#line 5 \"string/rolling_hash.hpp\"\
    \n\n// setbase() must be called before using Hashs\ntemplate <int id>\nstruct\
    \ Hashs {\n    struct Hash {\n        long long h, pw, pwi;\n    };\n    constexpr\
    \ static int b = 5;\n    using T = array<Hash, b>;\n    T table;\n    constexpr\
    \ static int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n\
    \    static int base[b], basei[b];\n\n    static void setbase() {\n        mt19937_64\
    \ rng(time(0));\n        for (int i = 0; i < b; ++i) {\n            unordered_set<int>\
    \ st = {0, 1, modp[i] - 1};\n            while (st.count(base[i] = rng() % modp[i]));\n\
    \            basei[i] = quo(base[i], i);\n        }\n    }\n\n    Hashs(char c)\
    \ {\n        for (int i = 0; i < b; ++i) {\n            table[i].h = c;\n    \
    \        table[i].pw = base[i];\n            table[i].pwi = basei[i];\n      \
    \  }\n    }\n    Hashs(string s) {\n        int n = s.size();\n        for (int\
    \ i = 0; i < b; ++i) {\n            table[i].h = 0;\n            table[i].pw =\
    \ 1;\n            table[i].pwi = 1;\n            for (int j = n - 1; j >= 0; --j)\
    \ {\n                table[i].h = (table[i].h * base[i] + s[j]) % modp[i];\n \
    \               table[i].pw = table[i].pw * base[i] % modp[i];\n             \
    \   table[i].pwi = table[i].pwi * basei[i] % modp[i];\n            }\n       \
    \ }\n    }\n    Hashs() {\n        for (int i = 0; i < b; ++i) {\n           \
    \ table[i].h = 0;\n            table[i].pw = 1;\n            table[i].pwi = 1;\n\
    \        }\n    }\n\n    void push_front(const Hashs &otherHash) {\n        for\
    \ (int i = 0; i < b; ++i) {\n            table[i].h = (otherHash.table[i].h +\
    \ table[i].h * otherHash.table[i].pw) % modp[i];\n            table[i].pw = table[i].pw\
    \ * otherHash.table[i].pw % modp[i];\n            table[i].pwi = table[i].pwi\
    \ * otherHash.table[i].pwi % modp[i];\n        }\n    }\n\n    void push_back(const\
    \ Hashs &otherHash) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h\
    \ = (table[i].h + otherHash.table[i].h * table[i].pw) % modp[i];\n           \
    \ table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n            table[i].pwi\
    \ = table[i].pwi * otherHash.table[i].pwi % modp[i];\n        }\n    }\n\n   \
    \ void pop_front(const Hashs &otherHash) {\n        for (int i = 0; i < b; ++i)\
    \ {\n            table[i].h = (table[i].h - otherHash.table[i].h) * otherHash.table[i].pwi\
    \ % modp[i];\n            if (table[i].h < 0) table[i].h += modp[i];\n       \
    \     table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];\n        \
    \    table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];\n        }\n\
    \    }\n\n    void pop_back(const Hashs &otherHash) {\n        for (int i = 0;\
    \ i < b; ++i) {\n            long long minus = otherHash.table[i].h * table[i].pw\
    \ % modp[i] * otherHash.table[i].pwi % modp[i];\n            table[i].h = (table[i].h\
    \ - minus) % modp[i];\n            if (table[i].h < 0) table[i].h += modp[i];\n\
    \            table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];\n \
    \           table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];\n \
    \       }\n    }\n\n    friend bool operator==(const Hashs &lhs, const Hashs &rhs)\
    \ {\n        for (int i = 0; i < b; ++i) {\n            if (lhs.table[i].h !=\
    \ rhs.table[i].h) return false;\n            if (lhs.table[i].pw != rhs.table[i].pw)\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ Hashs &lhs, const Hashs &rhs) {\n        return !(lhs == rhs);\n    }\n\n  private:\n\
    \    constexpr static long long quo(long long a, int i) {\n        return pow_mod_constexpr(a,\
    \ modp[i] - 2, modp[i]);\n    } \n};\n\ntemplate <int id>\nint Hashs<id>::base[5]\
    \ = {3, 3, 3, 3, 3};\ntemplate <int id>\nint Hashs<id>::basei[5] = {332748118,\
    \ 333333336, 666666673, 666666681, 666666689};\n\nusing Roliha = Hashs<0>;\n\n\
    \n"
  code: "#ifndef ROLLING_HASH_HPP\n#define ROLLING_HASH_HPP 1\n\n#include \"../math_mod/pow_expr.hpp\"\
    \n\n// setbase() must be called before using Hashs\ntemplate <int id>\nstruct\
    \ Hashs {\n    struct Hash {\n        long long h, pw, pwi;\n    };\n    constexpr\
    \ static int b = 5;\n    using T = array<Hash, b>;\n    T table;\n    constexpr\
    \ static int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n\
    \    static int base[b], basei[b];\n\n    static void setbase() {\n        mt19937_64\
    \ rng(time(0));\n        for (int i = 0; i < b; ++i) {\n            unordered_set<int>\
    \ st = {0, 1, modp[i] - 1};\n            while (st.count(base[i] = rng() % modp[i]));\n\
    \            basei[i] = quo(base[i], i);\n        }\n    }\n\n    Hashs(char c)\
    \ {\n        for (int i = 0; i < b; ++i) {\n            table[i].h = c;\n    \
    \        table[i].pw = base[i];\n            table[i].pwi = basei[i];\n      \
    \  }\n    }\n    Hashs(string s) {\n        int n = s.size();\n        for (int\
    \ i = 0; i < b; ++i) {\n            table[i].h = 0;\n            table[i].pw =\
    \ 1;\n            table[i].pwi = 1;\n            for (int j = n - 1; j >= 0; --j)\
    \ {\n                table[i].h = (table[i].h * base[i] + s[j]) % modp[i];\n \
    \               table[i].pw = table[i].pw * base[i] % modp[i];\n             \
    \   table[i].pwi = table[i].pwi * basei[i] % modp[i];\n            }\n       \
    \ }\n    }\n    Hashs() {\n        for (int i = 0; i < b; ++i) {\n           \
    \ table[i].h = 0;\n            table[i].pw = 1;\n            table[i].pwi = 1;\n\
    \        }\n    }\n\n    void push_front(const Hashs &otherHash) {\n        for\
    \ (int i = 0; i < b; ++i) {\n            table[i].h = (otherHash.table[i].h +\
    \ table[i].h * otherHash.table[i].pw) % modp[i];\n            table[i].pw = table[i].pw\
    \ * otherHash.table[i].pw % modp[i];\n            table[i].pwi = table[i].pwi\
    \ * otherHash.table[i].pwi % modp[i];\n        }\n    }\n\n    void push_back(const\
    \ Hashs &otherHash) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h\
    \ = (table[i].h + otherHash.table[i].h * table[i].pw) % modp[i];\n           \
    \ table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n            table[i].pwi\
    \ = table[i].pwi * otherHash.table[i].pwi % modp[i];\n        }\n    }\n\n   \
    \ void pop_front(const Hashs &otherHash) {\n        for (int i = 0; i < b; ++i)\
    \ {\n            table[i].h = (table[i].h - otherHash.table[i].h) * otherHash.table[i].pwi\
    \ % modp[i];\n            if (table[i].h < 0) table[i].h += modp[i];\n       \
    \     table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];\n        \
    \    table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];\n        }\n\
    \    }\n\n    void pop_back(const Hashs &otherHash) {\n        for (int i = 0;\
    \ i < b; ++i) {\n            long long minus = otherHash.table[i].h * table[i].pw\
    \ % modp[i] * otherHash.table[i].pwi % modp[i];\n            table[i].h = (table[i].h\
    \ - minus) % modp[i];\n            if (table[i].h < 0) table[i].h += modp[i];\n\
    \            table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];\n \
    \           table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];\n \
    \       }\n    }\n\n    friend bool operator==(const Hashs &lhs, const Hashs &rhs)\
    \ {\n        for (int i = 0; i < b; ++i) {\n            if (lhs.table[i].h !=\
    \ rhs.table[i].h) return false;\n            if (lhs.table[i].pw != rhs.table[i].pw)\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ Hashs &lhs, const Hashs &rhs) {\n        return !(lhs == rhs);\n    }\n\n  private:\n\
    \    constexpr static long long quo(long long a, int i) {\n        return pow_mod_constexpr(a,\
    \ modp[i] - 2, modp[i]);\n    } \n};\n\ntemplate <int id>\nint Hashs<id>::base[5]\
    \ = {3, 3, 3, 3, 3};\ntemplate <int id>\nint Hashs<id>::basei[5] = {332748118,\
    \ 333333336, 666666673, 666666681, 666666689};\n\nusing Roliha = Hashs<0>;\n\n\
    #endif // ROLLING_HASH_HPP\n"
  dependsOn:
  - math_mod/pow_expr.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-08-08 10:40:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
