---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\n\n\n\n#include <array>\n#include\
    \ <ctime>\n#include <random>\n#include <string>\n#include <vector>\n\n#line 1\
    \ \"math_mod/pow_mod.hpp\"\n\n\n\n#include <cassert>\n\n#line 1 \"type_traits/type_traits.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing\
    \ is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value\n\
    \                                                       or std::is_same<T, __int128>::value,\n\
    \                                                   std::true_type,\n        \
    \                                           std::false_type>::type;\n\ntemplate\
    \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T>\nusing\
    \ is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed_extended =\n\
    \    typename std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_extended\
    \ =\n    typename std::conditional<std::is_unsigned<T>::value or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n#line 7 \"math_mod/pow_mod.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
    \ x, U n, T m) {\n    assert(!is_signed_extended<U>::value || n >= 0);\n    if\
    \ (m == 1) return S(0);\n    S _m = S(m), r = 1;\n    S y = S(x) % _m;\n    if\
    \ (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n  \
    \      y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 11 \"string/rolling_hash.hpp\"\n\nnamespace kk2 {\n\n// setbase()\
    \ must be called before using Hash\nstruct RollingHash {\n    struct Hash {\n\
    \        long long h, pw, pwi;\n    };\n\n    constexpr static int b = 5;\n  \
    \  using T = std::array<Hash, b>;\n    T table;\n    constexpr static int modp[b]\
    \ = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n    static int\
    \ base[b], basei[b];\n\n    static void setbase() {\n        std::mt19937_64 rng(time(0));\n\
    \        for (int i = 0; i < b; ++i) {\n            base[i] = rng() % modp[i];\n\
    \            basei[i] = quo(base[i], i);\n        }\n    }\n\n    RollingHash(const\
    \ int &v) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h = v\
    \ % modp[i];\n            table[i].pw = base[i];\n            table[i].pwi = basei[i];\n\
    \        }\n    }\n\n    RollingHash(const char &c) {\n        for (int i = 0;\
    \ i < b; ++i) {\n            table[i].h = c;\n            table[i].pw = base[i];\n\
    \            table[i].pwi = basei[i];\n        }\n    }\n\n    template <class\
    \ T> RollingHash(const std::vector<T> &v) {\n        int n = v.size();\n     \
    \   for (int i = 0; i < b; ++i) {\n            table[i].h = 0;\n            table[i].pw\
    \ = 1;\n            table[i].pwi = 1;\n            for (int j = n - 1; j >= 0;\
    \ --j) {\n                table[i].h = (table[i].h * base[i] + v[j] % modp[i])\
    \ % modp[i];\n                table[i].pw = table[i].pw * base[i] % modp[i];\n\
    \                table[i].pwi = table[i].pwi * basei[i] % modp[i];\n         \
    \   }\n        }\n    }\n\n    RollingHash(const std::string &s) {\n        int\
    \ n = s.size();\n        for (int i = 0; i < b; ++i) {\n            table[i].h\
    \ = 0;\n            table[i].pw = 1;\n            table[i].pwi = 1;\n        \
    \    for (int j = n - 1; j >= 0; --j) {\n                table[i].h = (table[i].h\
    \ * base[i] + s[j]) % modp[i];\n                table[i].pw = table[i].pw * base[i]\
    \ % modp[i];\n                table[i].pwi = table[i].pwi * basei[i] % modp[i];\n\
    \            }\n        }\n    }\n\n    RollingHash() {\n        for (int i =\
    \ 0; i < b; ++i) {\n            table[i].h = 0;\n            table[i].pw = 1;\n\
    \            table[i].pwi = 1;\n        }\n    }\n\n    RollingHash &push_front(const\
    \ RollingHash &otherHash) {\n        for (int i = 0; i < b; ++i) {\n         \
    \   table[i].h = (otherHash.table[i].h + table[i].h * otherHash.table[i].pw) %\
    \ modp[i];\n            table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n\
    \            table[i].pwi = table[i].pwi * otherHash.table[i].pwi % modp[i];\n\
    \        }\n        return *this;\n    }\n\n    RollingHash &push_back(const RollingHash\
    \ &otherHash) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h\
    \ = (table[i].h + otherHash.table[i].h * table[i].pw) % modp[i];\n           \
    \ table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n            table[i].pwi\
    \ = table[i].pwi * otherHash.table[i].pwi % modp[i];\n        }\n        return\
    \ *this;\n    }\n\n    RollingHash &pop_front(const RollingHash &otherHash) {\n\
    \        for (int i = 0; i < b; ++i) {\n            table[i].h = (table[i].h -\
    \ otherHash.table[i].h) * otherHash.table[i].pwi % modp[i];\n            if (table[i].h\
    \ < 0) table[i].h += modp[i];\n            table[i].pw = table[i].pw * otherHash.table[i].pwi\
    \ % modp[i];\n            table[i].pwi = table[i].pwi * otherHash.table[i].pw\
    \ % modp[i];\n        }\n        return *this;\n    }\n\n    RollingHash &pop_back(const\
    \ RollingHash &otherHash) {\n        for (int i = 0; i < b; ++i) {\n         \
    \   long long minus =\n                otherHash.table[i].h * table[i].pw % modp[i]\
    \ * otherHash.table[i].pwi % modp[i];\n            table[i].h = (table[i].h -\
    \ minus) % modp[i];\n            if (table[i].h < 0) table[i].h += modp[i];\n\
    \            table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];\n \
    \           table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];\n \
    \       }\n        return *this;\n    }\n\n    friend bool operator==(const RollingHash\
    \ &lhs, const RollingHash &rhs) {\n        for (int i = 0; i < b; ++i) {\n   \
    \         if (lhs.table[i].h != rhs.table[i].h) return false;\n            if\
    \ (lhs.table[i].pw != rhs.table[i].pw) return false;\n        }\n        return\
    \ true;\n    }\n\n    friend bool operator!=(const RollingHash &lhs, const RollingHash\
    \ &rhs) { return !(lhs == rhs); }\n\n  private:\n    constexpr static long long\
    \ quo(long long a, int i) {\n        return pow_mod<long long>(a, modp[i] - 2,\
    \ modp[i]);\n    }\n};\n\nint RollingHash::base[5] = {3, 3, 3, 3, 3};\nint RollingHash::basei[5]\
    \ = {332748118, 333333336, 666666673, 666666681, 666666689};\n\n\nusing Roliha\
    \ = RollingHash;\n\n} // namespace kk2\n\n\n\n"
  code: "#ifndef ROLLING_HASH_HPP\n#define ROLLING_HASH_HPP 1\n\n#include <array>\n\
    #include <ctime>\n#include <random>\n#include <string>\n#include <vector>\n\n\
    #include \"../math_mod/pow_mod.hpp\"\n\nnamespace kk2 {\n\n// setbase() must be\
    \ called before using Hash\nstruct RollingHash {\n    struct Hash {\n        long\
    \ long h, pw, pwi;\n    };\n\n    constexpr static int b = 5;\n    using T = std::array<Hash,\
    \ b>;\n    T table;\n    constexpr static int modp[b] = {998244353, 1000000007,\
    \ 1000000009, 1000000021, 1000000033};\n    static int base[b], basei[b];\n\n\
    \    static void setbase() {\n        std::mt19937_64 rng(time(0));\n        for\
    \ (int i = 0; i < b; ++i) {\n            base[i] = rng() % modp[i];\n        \
    \    basei[i] = quo(base[i], i);\n        }\n    }\n\n    RollingHash(const int\
    \ &v) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h = v % modp[i];\n\
    \            table[i].pw = base[i];\n            table[i].pwi = basei[i];\n  \
    \      }\n    }\n\n    RollingHash(const char &c) {\n        for (int i = 0; i\
    \ < b; ++i) {\n            table[i].h = c;\n            table[i].pw = base[i];\n\
    \            table[i].pwi = basei[i];\n        }\n    }\n\n    template <class\
    \ T> RollingHash(const std::vector<T> &v) {\n        int n = v.size();\n     \
    \   for (int i = 0; i < b; ++i) {\n            table[i].h = 0;\n            table[i].pw\
    \ = 1;\n            table[i].pwi = 1;\n            for (int j = n - 1; j >= 0;\
    \ --j) {\n                table[i].h = (table[i].h * base[i] + v[j] % modp[i])\
    \ % modp[i];\n                table[i].pw = table[i].pw * base[i] % modp[i];\n\
    \                table[i].pwi = table[i].pwi * basei[i] % modp[i];\n         \
    \   }\n        }\n    }\n\n    RollingHash(const std::string &s) {\n        int\
    \ n = s.size();\n        for (int i = 0; i < b; ++i) {\n            table[i].h\
    \ = 0;\n            table[i].pw = 1;\n            table[i].pwi = 1;\n        \
    \    for (int j = n - 1; j >= 0; --j) {\n                table[i].h = (table[i].h\
    \ * base[i] + s[j]) % modp[i];\n                table[i].pw = table[i].pw * base[i]\
    \ % modp[i];\n                table[i].pwi = table[i].pwi * basei[i] % modp[i];\n\
    \            }\n        }\n    }\n\n    RollingHash() {\n        for (int i =\
    \ 0; i < b; ++i) {\n            table[i].h = 0;\n            table[i].pw = 1;\n\
    \            table[i].pwi = 1;\n        }\n    }\n\n    RollingHash &push_front(const\
    \ RollingHash &otherHash) {\n        for (int i = 0; i < b; ++i) {\n         \
    \   table[i].h = (otherHash.table[i].h + table[i].h * otherHash.table[i].pw) %\
    \ modp[i];\n            table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n\
    \            table[i].pwi = table[i].pwi * otherHash.table[i].pwi % modp[i];\n\
    \        }\n        return *this;\n    }\n\n    RollingHash &push_back(const RollingHash\
    \ &otherHash) {\n        for (int i = 0; i < b; ++i) {\n            table[i].h\
    \ = (table[i].h + otherHash.table[i].h * table[i].pw) % modp[i];\n           \
    \ table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];\n            table[i].pwi\
    \ = table[i].pwi * otherHash.table[i].pwi % modp[i];\n        }\n        return\
    \ *this;\n    }\n\n    RollingHash &pop_front(const RollingHash &otherHash) {\n\
    \        for (int i = 0; i < b; ++i) {\n            table[i].h = (table[i].h -\
    \ otherHash.table[i].h) * otherHash.table[i].pwi % modp[i];\n            if (table[i].h\
    \ < 0) table[i].h += modp[i];\n            table[i].pw = table[i].pw * otherHash.table[i].pwi\
    \ % modp[i];\n            table[i].pwi = table[i].pwi * otherHash.table[i].pw\
    \ % modp[i];\n        }\n        return *this;\n    }\n\n    RollingHash &pop_back(const\
    \ RollingHash &otherHash) {\n        for (int i = 0; i < b; ++i) {\n         \
    \   long long minus =\n                otherHash.table[i].h * table[i].pw % modp[i]\
    \ * otherHash.table[i].pwi % modp[i];\n            table[i].h = (table[i].h -\
    \ minus) % modp[i];\n            if (table[i].h < 0) table[i].h += modp[i];\n\
    \            table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];\n \
    \           table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];\n \
    \       }\n        return *this;\n    }\n\n    friend bool operator==(const RollingHash\
    \ &lhs, const RollingHash &rhs) {\n        for (int i = 0; i < b; ++i) {\n   \
    \         if (lhs.table[i].h != rhs.table[i].h) return false;\n            if\
    \ (lhs.table[i].pw != rhs.table[i].pw) return false;\n        }\n        return\
    \ true;\n    }\n\n    friend bool operator!=(const RollingHash &lhs, const RollingHash\
    \ &rhs) { return !(lhs == rhs); }\n\n  private:\n    constexpr static long long\
    \ quo(long long a, int i) {\n        return pow_mod<long long>(a, modp[i] - 2,\
    \ modp[i]);\n    }\n};\n\nint RollingHash::base[5] = {3, 3, 3, 3, 3};\nint RollingHash::basei[5]\
    \ = {332748118, 333333336, 666666673, 666666681, 666666689};\n\n\nusing Roliha\
    \ = RollingHash;\n\n} // namespace kk2\n\n\n#endif // ROLLING_HASH_HPP\n"
  dependsOn:
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
