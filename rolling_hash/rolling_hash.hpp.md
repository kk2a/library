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
  bundledCode: "#line 1 \"rolling_hash/rolling_hash.hpp\"\n\n\n\ntemplate <int id>\n\
    struct Hashs {\n    struct Hash {\n        long long h, pw;\n    };\n    constexpr\
    \ static int b = 5;\n    using T = array<Hash, b>;\n    T table;\n    constexpr\
    \ static int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n\
    \    static int base[b];\n\n    static void setbase() {\n        mt19937_64 rng(time(0));\n\
    \        rep (i, 0, b) {\n            while((base[i] = rng() % modp[i]) == 0);\n\
    \        }\n    }\n    \n    template <class T>\n    Hashs(T c) {\n        rep\
    \ (i, b) {\n            table[i].h = c;\n            table[i].pw = base[i];\n\
    \        }\n    }\n    Hashs() {\n        rep (i, b) {\n            table[i].h\
    \ = 0;\n            table[i].pw = 1;\n        }\n    }\n\n    void push_back(const\
    \ Hashs &rhs) {\n        rep (i, b) {\n            table[i].h = (table[i].h *\
    \ rhs.table[i].pw + rhs.table[i].h) % modp[i];\n            table[i].pw = table[i].pw\
    \ * rhs.table[i].pw % modp[i];\n        }\n    }\n    void push_front(const Hashs\
    \ &rhs) {\n        rep (i, b) {\n            table[i].h = (table[i].h + rhs.table[i].h\
    \ * table[i].pw) % modp[i];\n            table[i].pw = table[i].pw * rhs.table[i].pw\
    \ % modp[i];\n        }\n    }\n    \n    Hashs& operator+=(const Hashs &rhs)\
    \ {\n        rep (i, b) {\n            table[i].h = (table[i].h * rhs.table[i].pw\
    \ + rhs.table[i].h) % modp[i];\n            table[i].pw = table[i].pw * rhs.table[i].pw\
    \ % modp[i];\n        }\n        return *this;\n    }\n    Hashs& operator-=(const\
    \ Hashs &rhs) {\n        rep (i, b) {\n            table[i].h = (table[i].h +\
    \ rhs.table[i].h * table[i].pw) % modp[i];\n            table[i].pw = table[i].pw\
    \ * rhs.table[i].pw % modp[i];\n        }\n        return *this;\n    }\n\n  \
    \  friend Hashs operator+(const Hashs &lhs, const Hashs &rhs) {\n        return\
    \ Hashs(lhs) += rhs;\n    }\n    friend Hashs operator-(const Hashs &lhs, const\
    \ Hashs &rhs) {\n        return Hashs(lhs) -= rhs;\n    }\n\n    friend bool operator==(const\
    \ Hashs &lhs, const Hashs &rhs) {\n        rep (i, b) {\n            if (lhs.table[i].h\
    \ != rhs.table[i].h) return false;\n            if (lhs.table[i].pw != rhs.table[i].pw)\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ Hashs &lhs, const Hashs &rhs) {\n        return !(lhs == rhs);\n    }\n};\n\n\
    template <int id>\nint Hashs<id>::base[5] = {3, 3, 3, 3, 3};\n\n\n"
  code: "#ifndef ROLLING_HASH_HPP\n#define ROLLING_HASH_HPP 1\n\ntemplate <int id>\n\
    struct Hashs {\n    struct Hash {\n        long long h, pw;\n    };\n    constexpr\
    \ static int b = 5;\n    using T = array<Hash, b>;\n    T table;\n    constexpr\
    \ static int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n\
    \    static int base[b];\n\n    static void setbase() {\n        mt19937_64 rng(time(0));\n\
    \        rep (i, 0, b) {\n            while((base[i] = rng() % modp[i]) == 0);\n\
    \        }\n    }\n    \n    template <class T>\n    Hashs(T c) {\n        rep\
    \ (i, b) {\n            table[i].h = c;\n            table[i].pw = base[i];\n\
    \        }\n    }\n    Hashs() {\n        rep (i, b) {\n            table[i].h\
    \ = 0;\n            table[i].pw = 1;\n        }\n    }\n\n    void push_back(const\
    \ Hashs &rhs) {\n        rep (i, b) {\n            table[i].h = (table[i].h *\
    \ rhs.table[i].pw + rhs.table[i].h) % modp[i];\n            table[i].pw = table[i].pw\
    \ * rhs.table[i].pw % modp[i];\n        }\n    }\n    void push_front(const Hashs\
    \ &rhs) {\n        rep (i, b) {\n            table[i].h = (table[i].h + rhs.table[i].h\
    \ * table[i].pw) % modp[i];\n            table[i].pw = table[i].pw * rhs.table[i].pw\
    \ % modp[i];\n        }\n    }\n    \n    Hashs& operator+=(const Hashs &rhs)\
    \ {\n        rep (i, b) {\n            table[i].h = (table[i].h * rhs.table[i].pw\
    \ + rhs.table[i].h) % modp[i];\n            table[i].pw = table[i].pw * rhs.table[i].pw\
    \ % modp[i];\n        }\n        return *this;\n    }\n    Hashs& operator-=(const\
    \ Hashs &rhs) {\n        rep (i, b) {\n            table[i].h = (table[i].h +\
    \ rhs.table[i].h * table[i].pw) % modp[i];\n            table[i].pw = table[i].pw\
    \ * rhs.table[i].pw % modp[i];\n        }\n        return *this;\n    }\n\n  \
    \  friend Hashs operator+(const Hashs &lhs, const Hashs &rhs) {\n        return\
    \ Hashs(lhs) += rhs;\n    }\n    friend Hashs operator-(const Hashs &lhs, const\
    \ Hashs &rhs) {\n        return Hashs(lhs) -= rhs;\n    }\n\n    friend bool operator==(const\
    \ Hashs &lhs, const Hashs &rhs) {\n        rep (i, b) {\n            if (lhs.table[i].h\
    \ != rhs.table[i].h) return false;\n            if (lhs.table[i].pw != rhs.table[i].pw)\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ Hashs &lhs, const Hashs &rhs) {\n        return !(lhs == rhs);\n    }\n};\n\n\
    template <int id>\nint Hashs<id>::base[5] = {3, 3, 3, 3, 3};\n\n#endif // ROLLING_HASH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: rolling_hash/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-05-03 16:15:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: rolling_hash/rolling_hash.hpp
layout: document
redirect_from:
- /library/rolling_hash/rolling_hash.hpp
- /library/rolling_hash/rolling_hash.hpp.html
title: rolling_hash/rolling_hash.hpp
---
