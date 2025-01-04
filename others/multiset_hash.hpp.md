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
  bundledCode: "#line 1 \"others/multiset_hash.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <array>\n#include <ctime>\n#include <iostream>\n#include <random>\n#include\
    \ <unordered_map>\n\nnamespace kk2 {\n\ntemplate <typename T> struct MultiSetHash\
    \ {\n    constexpr static int b = 5;\n    constexpr static int modp[b] = {998244353,\
    \ 1000000007, 1000000009, 1000000021, 1000000033};\n    using Hashs = std::array<long\
    \ long, b>;\n    int siz;\n    Hashs table;\n    static std::mt19937_64 rng;\n\
    \    static std::unordered_map<T, Hashs> base;\n\n    static Hashs getbase(const\
    \ T &x) {\n        if (base.count(x)) return base[x];\n        base[x] = Hashs();\n\
    \        for (int i = 0; i < b; ++i) { base[x][i] = rng() % modp[i]; }\n     \
    \   return base[x];\n    }\n\n    MultiSetHash() : siz(0) { std::fill(std::begin(table),\
    \ std::end(table), 0); }\n\n    MultiSetHash(const T &x) : siz(1) { table = getbase(x);\
    \ }\n\n    MultiSetHash(const std::vector<T> &v) : siz(v.size()) {\n        for\
    \ (int i = 0; i < siz; i++) {\n            auto tmp = getbase(v[i]);\n       \
    \     for (int j = 0; j < b; ++j) { table[j] = (table[j] + tmp[j]) % modp[j];\
    \ }\n        }\n    }\n\n    MultiSetHash &merge(const MultiSetHash &rhs) {\n\
    \        for (int i = 0; rhs.siz; ++i) { table[i] = (table[i] + rhs.table[i])\
    \ % modp[i]; }\n        siz += rhs.siz;\n        return *this;\n    }\n\n    MultiSetHash\
    \ &merge(const T &x) {\n        auto tmp = getbase(x);\n        for (int i = 0;\
    \ i < b; ++i) { table[i] = (table[i] + tmp[i]) % modp[i]; }\n        siz++;\n\
    \        return *this;\n    }\n\n    // require: rhs \\subset *this\n    MultiSetHash\
    \ &erase(const MultiSetHash &rhs) {\n        for (int i = 0; i < b; ++i) { table[i]\
    \ = (table[i] - rhs.table[i] + modp[i]) % modp[i]; }\n        siz -= rhs.siz;\n\
    \        return *this;\n    }\n\n    // require: x \\in *this\n    MultiSetHash\
    \ &erase(const T &x) {\n        auto tmp = getbase(x);\n        for (int i = 0;\
    \ i < b; ++i) { table[i] = (table[i] - tmp[i] + modp[i]) % modp[i]; }\n      \
    \  siz--;\n        return *this;\n    }\n\n    friend MultiSetHash merge(const\
    \ MultiSetHash &lhs, const MultiSetHash &rhs) {\n        return MultiSetHash(lhs).merge(rhs);\n\
    \    }\n\n    friend MultiSetHash merge(const MultiSetHash &lhs, const T &x) {\n\
    \        return MultiSetHash(lhs).merge(x);\n    }\n\n    friend MultiSetHash\
    \ erase(const MultiSetHash &lhs, const MultiSetHash &rhs) {\n        return MultiSetHash(lhs).erase(rhs);\n\
    \    }\n\n    friend MultiSetHash erase(const MultiSetHash &lhs, const T &x) {\n\
    \        return MultiSetHash(lhs).erase(x);\n    }\n\n    friend bool operator==(const\
    \ MultiSetHash &lhs, const MultiSetHash &rhs) {\n        return lhs.table == rhs.table\
    \ && lhs.siz == rhs.siz;\n    }\n\n    friend bool operator!=(const MultiSetHash\
    \ &lhs, const MultiSetHash &rhs) {\n        return lhs.table != rhs.table || lhs.siz\
    \ != rhs.siz;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const MultiSetHash &msh) {\n        os << \"siz: \" << msh.siz << \" table:\
    \ \";\n        for (int i = 0; i < b; ++i) { os << msh.table[i] << \" \"; }\n\
    \        os << \"\\n\";\n        return os;\n    }\n};\n\ntemplate <typename T>\
    \ std::unordered_map<T, typename MultiSetHash<T>::Hashs> MultiSetHash<T>::base;\n\
    \ntemplate <typename T> std::mt19937_64 MultiSetHash<T>::rng(time(0));\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef KK2_OTHERS_MULTISET_HASH_HPP\n#define KK2_OTHERS_MULTISET_HASH_HPP\
    \ 1\n\n#include <algorithm>\n#include <array>\n#include <ctime>\n#include <iostream>\n\
    #include <random>\n#include <unordered_map>\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> struct MultiSetHash {\n    constexpr static int b = 5;\n    constexpr static\
    \ int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n\
    \    using Hashs = std::array<long long, b>;\n    int siz;\n    Hashs table;\n\
    \    static std::mt19937_64 rng;\n    static std::unordered_map<T, Hashs> base;\n\
    \n    static Hashs getbase(const T &x) {\n        if (base.count(x)) return base[x];\n\
    \        base[x] = Hashs();\n        for (int i = 0; i < b; ++i) { base[x][i]\
    \ = rng() % modp[i]; }\n        return base[x];\n    }\n\n    MultiSetHash() :\
    \ siz(0) { std::fill(std::begin(table), std::end(table), 0); }\n\n    MultiSetHash(const\
    \ T &x) : siz(1) { table = getbase(x); }\n\n    MultiSetHash(const std::vector<T>\
    \ &v) : siz(v.size()) {\n        for (int i = 0; i < siz; i++) {\n           \
    \ auto tmp = getbase(v[i]);\n            for (int j = 0; j < b; ++j) { table[j]\
    \ = (table[j] + tmp[j]) % modp[j]; }\n        }\n    }\n\n    MultiSetHash &merge(const\
    \ MultiSetHash &rhs) {\n        for (int i = 0; rhs.siz; ++i) { table[i] = (table[i]\
    \ + rhs.table[i]) % modp[i]; }\n        siz += rhs.siz;\n        return *this;\n\
    \    }\n\n    MultiSetHash &merge(const T &x) {\n        auto tmp = getbase(x);\n\
    \        for (int i = 0; i < b; ++i) { table[i] = (table[i] + tmp[i]) % modp[i];\
    \ }\n        siz++;\n        return *this;\n    }\n\n    // require: rhs \\subset\
    \ *this\n    MultiSetHash &erase(const MultiSetHash &rhs) {\n        for (int\
    \ i = 0; i < b; ++i) { table[i] = (table[i] - rhs.table[i] + modp[i]) % modp[i];\
    \ }\n        siz -= rhs.siz;\n        return *this;\n    }\n\n    // require:\
    \ x \\in *this\n    MultiSetHash &erase(const T &x) {\n        auto tmp = getbase(x);\n\
    \        for (int i = 0; i < b; ++i) { table[i] = (table[i] - tmp[i] + modp[i])\
    \ % modp[i]; }\n        siz--;\n        return *this;\n    }\n\n    friend MultiSetHash\
    \ merge(const MultiSetHash &lhs, const MultiSetHash &rhs) {\n        return MultiSetHash(lhs).merge(rhs);\n\
    \    }\n\n    friend MultiSetHash merge(const MultiSetHash &lhs, const T &x) {\n\
    \        return MultiSetHash(lhs).merge(x);\n    }\n\n    friend MultiSetHash\
    \ erase(const MultiSetHash &lhs, const MultiSetHash &rhs) {\n        return MultiSetHash(lhs).erase(rhs);\n\
    \    }\n\n    friend MultiSetHash erase(const MultiSetHash &lhs, const T &x) {\n\
    \        return MultiSetHash(lhs).erase(x);\n    }\n\n    friend bool operator==(const\
    \ MultiSetHash &lhs, const MultiSetHash &rhs) {\n        return lhs.table == rhs.table\
    \ && lhs.siz == rhs.siz;\n    }\n\n    friend bool operator!=(const MultiSetHash\
    \ &lhs, const MultiSetHash &rhs) {\n        return lhs.table != rhs.table || lhs.siz\
    \ != rhs.siz;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const MultiSetHash &msh) {\n        os << \"siz: \" << msh.siz << \" table:\
    \ \";\n        for (int i = 0; i < b; ++i) { os << msh.table[i] << \" \"; }\n\
    \        os << \"\\n\";\n        return os;\n    }\n};\n\ntemplate <typename T>\
    \ std::unordered_map<T, typename MultiSetHash<T>::Hashs> MultiSetHash<T>::base;\n\
    \ntemplate <typename T> std::mt19937_64 MultiSetHash<T>::rng(time(0));\n\n} //\
    \ namespace kk2\n\n#endif // KK2_OTHERS_MULTISET_HASH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/multiset_hash.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/multiset_hash.hpp
layout: document
redirect_from:
- /library/others/multiset_hash.hpp
- /library/others/multiset_hash.hpp.html
title: others/multiset_hash.hpp
---
