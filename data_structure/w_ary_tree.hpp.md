---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_predecessor_problem.test.cpp
    title: verify/yosupo_ds/ds_predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/w_ary_tree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <optional>\n#include <string>\n#include <vector>\n\
    \n#line 1 \"bit/bitcount.hpp\"\n\n\n\n#line 5 \"bit/bitcount.hpp\"\n\n#line 1\
    \ \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace kk2\
    \ {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128 =\n  \
    \  typename std::conditional<std::is_same<T, __int128_t>::value\n            \
    \                      or std::is_same<T, __int128>::value,\n                \
    \              std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T> using is_integral\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename T>\
    \ using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
    \                              make_unsigned_int128<T>,\n                    \
    \          typename std::conditional<std::is_signed<T>::value,\n             \
    \                                           std::make_unsigned<T>,\n         \
    \                                               std::common_type<T>>::type>::type;\n\
    \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
    template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
    template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
    template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
    \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
    template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 7 \"bit/bitcount.hpp\"\n\nnamespace kk2 {\n\n\
    template <typename T> constexpr int ctz(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    if constexpr (sizeof(T) <= 4) {\n        return\
    \ __builtin_ctz(x);\n    } else if constexpr (sizeof(T) <= 8) {\n        return\
    \ __builtin_ctzll(x);\n    } else {\n        if (x & 0xffffffffffffffff)\n   \
    \         return __builtin_ctzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \        return 64 + __builtin_ctzll((unsigned long long)(x >> 64));\n    }\n\
    }\n\ntemplate <typename T> constexpr int lsb(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    return ctz(x);\n}\n\ntemplate <typename T> constexpr\
    \ int clz(T x) {\n    static_assert(is_integral<T>::value);\n    assert(x != T(0));\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_clz(x);\n    }\
    \ else if constexpr (sizeof(T) <= 8) {\n        return __builtin_clzll(x);\n \
    \   } else {\n        if (x >> 64) return __builtin_clzll((unsigned long long)(x\
    \ >> 64));\n        return 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\ntemplate <typename T> constexpr int msb(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    return sizeof(T) * 8 - 1 - clz(x);\n}\n\ntemplate\
    \ <typename T> constexpr int popcount(T x) {\n    static_assert(is_integral<T>::value);\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_popcount(x);\n\
    \    } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_popcountll(x);\n\
    \    } else {\n        return __builtin_popcountll((unsigned long long)(x >> 64))\n\
    \               + __builtin_popcountll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\n}; // namespace kk2\n\n\n#line 11 \"data_structure/w_ary_tree.hpp\"\
    \n\nnamespace kk2 {\n\nstruct w_ary_tree {\n    using Uint = unsigned long long;\n\
    \    constexpr static int W = 64;\n    int _n;\n    std::vector<std::vector<Uint>>\
    \ d;\n\n    w_ary_tree() : d(1) {}\n\n    w_ary_tree(const std::vector<bool> &a)\
    \ : _n(a.size()) {\n        if (_n == 0) return;\n        if (_n == 1) {\n   \
    \         d = {{Uint(a[0])}};\n            return;\n        }\n        for (int\
    \ n = _n; n != 1; n = (n + W - 1) / W) {\n            std::vector<Uint> v((n +\
    \ W - 1) / W);\n            for (int i = 0; i < (n + W - 1) / W; ++i) {\n    \
    \            Uint x = 0;\n                for (int j = 0; j < W && i * W + j <\
    \ n; ++j) {\n                    if (n == _n) x |= (Uint(a[i * W + j]) << j);\n\
    \                    else x |= ((d.back()[i * W + j] ? Uint(1) : Uint(0)) << j);\n\
    \                }\n                v[i] = x;\n            }\n            d.push_back(v);\n\
    \        }\n        std::reverse(d.begin(), d.end());\n    }\n\n    w_ary_tree(const\
    \ std::string &s) : _n(s.size()) {\n        if (_n == 0) return;\n        if (_n\
    \ == 1) {\n            d = {{Uint(s[0] - '0')}};\n            return;\n      \
    \  }\n        for (int n = _n; n != 1; n = (n + W - 1) / W) {\n            std::vector<Uint>\
    \ v((n + W - 1) / W);\n            for (int i = 0; i < (n + W - 1) / W; ++i) {\n\
    \                Uint x = 0;\n                for (int j = 0; j < W && i * W +\
    \ j < n; ++j) {\n                    if (n == _n) x |= (Uint(s[i * W + j] - '0')\
    \ << j);\n                    else x |= ((d.back()[i * W + j] ? Uint(1) : Uint(0))\
    \ << j);\n                }\n                v[i] = x;\n            }\n      \
    \      d.push_back(v);\n        }\n        std::reverse(d.begin(), d.end());\n\
    \    }\n\n    int count(int x) const {\n        assert(0 <= x && x < _n);\n  \
    \      return d.back()[x / W] >> (x % W) & 1;\n    }\n\n    void insert(int x)\
    \ {\n        assert(0 <= x && x < _n);\n        for (int dep = (int)d.size() -\
    \ 1; dep >= 0; --dep, x /= W) {\n            if (d[dep][x / W] >> (x % W) & 1)\
    \ break;\n            d[dep][x / W] |= Uint(1) << (x % W);\n        }\n    }\n\
    \n    void erase(int x) {\n        assert(0 <= x && x < _n);\n        for (int\
    \ dep = (int)d.size() - 1; dep >= 0; --dep, x /= W) {\n            if (dep ==\
    \ (int)d.size() - 1) {\n                if (~d[dep][x / W] >> (x % W) & 1) break;\n\
    \                d[dep][x / W] ^= Uint(1) << (x % W);\n            } else {\n\
    \                if (d[dep + 1][x]) break;\n                if (~d[dep][x / W]\
    \ >> (x % W) & 1) break;\n                d[dep][x / W] ^= Uint(1) << (x % W);\n\
    \            }\n        }\n    }\n\n    // return max y s.t. count(y) == 1 &&\
    \ y <= x\n    std::optional<int> predecessor(int x) const {\n        if (x < 0)\
    \ return std::nullopt;\n        if (x >= _n) x = _n - 1;\n        int dep = (int)d.size()\
    \ - 1;\n        for (;; --dep, x /= W) {\n            Uint mask = up_mask(d[dep][x\
    \ / W], x % W);\n            if (dep != (int)d.size() - 1) mask &= ~(Uint(1) <<\
    \ (x % W));\n            int next = _msb(mask);\n            if (next != -1) {\n\
    \                ++dep;\n                x = (x / W) * W + next;\n           \
    \     break;\n            }\n            if (dep == 0) return std::nullopt;\n\
    \        }\n\n        for (; dep < (int)d.size(); x = x * W + _msb(d[dep][x]),\
    \ ++dep) {}\n        return x;\n    }\n\n    // return min y s.t. count(y) ==\
    \ 1 && y >= x\n    std::optional<int> successor(int x) const {\n        if (x\
    \ >= _n) return std::nullopt;\n        if (x < 0) x = 0;\n        int dep = (int)d.size()\
    \ - 1;\n        for (;; --dep, x /= W) {\n            Uint mask = dw_mask(d[dep][x\
    \ / W], x % W);\n            if (dep != (int)d.size() - 1) mask &= ~(Uint(1) <<\
    \ (x % W));\n            int next = _lsb(mask);\n            if (next != -1) {\n\
    \                ++dep;\n                x = (x / W) * W + next;\n           \
    \     break;\n            }\n            if (dep == 0) return std::nullopt;\n\
    \        }\n\n\n        for (; dep < (int)d.size(); x = x * W + _lsb(d[dep][x]),\
    \ ++dep) {}\n        return x;\n    }\n\n  private:\n    static int _msb(Uint\
    \ x) { return x ? msb<Uint>(x) : -1; }\n\n    static int _lsb(Uint x) { return\
    \ x ? lsb<Uint>(x) : -1; }\n\n    static Uint up_mask(Uint x, int i) { return\
    \ x & (((Uint(1) << i) - 1) | (Uint(1) << i)); }\n\n    static Uint dw_mask(Uint\
    \ x, int i) { return x & ~((Uint(1) << i) - 1); }\n};\n\n} // namespace kk2\n\n\
    \n"
  code: "#ifndef KK2_DATA_STRUCTURE_W_ARY_TREE_HPP\n#define KK2_DATA_STRUCTURE_W_ARY_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <optional>\n#include\
    \ <string>\n#include <vector>\n\n#include \"../bit/bitcount.hpp\"\n\nnamespace\
    \ kk2 {\n\nstruct w_ary_tree {\n    using Uint = unsigned long long;\n    constexpr\
    \ static int W = 64;\n    int _n;\n    std::vector<std::vector<Uint>> d;\n\n \
    \   w_ary_tree() : d(1) {}\n\n    w_ary_tree(const std::vector<bool> &a) : _n(a.size())\
    \ {\n        if (_n == 0) return;\n        if (_n == 1) {\n            d = {{Uint(a[0])}};\n\
    \            return;\n        }\n        for (int n = _n; n != 1; n = (n + W -\
    \ 1) / W) {\n            std::vector<Uint> v((n + W - 1) / W);\n            for\
    \ (int i = 0; i < (n + W - 1) / W; ++i) {\n                Uint x = 0;\n     \
    \           for (int j = 0; j < W && i * W + j < n; ++j) {\n                 \
    \   if (n == _n) x |= (Uint(a[i * W + j]) << j);\n                    else x |=\
    \ ((d.back()[i * W + j] ? Uint(1) : Uint(0)) << j);\n                }\n     \
    \           v[i] = x;\n            }\n            d.push_back(v);\n        }\n\
    \        std::reverse(d.begin(), d.end());\n    }\n\n    w_ary_tree(const std::string\
    \ &s) : _n(s.size()) {\n        if (_n == 0) return;\n        if (_n == 1) {\n\
    \            d = {{Uint(s[0] - '0')}};\n            return;\n        }\n     \
    \   for (int n = _n; n != 1; n = (n + W - 1) / W) {\n            std::vector<Uint>\
    \ v((n + W - 1) / W);\n            for (int i = 0; i < (n + W - 1) / W; ++i) {\n\
    \                Uint x = 0;\n                for (int j = 0; j < W && i * W +\
    \ j < n; ++j) {\n                    if (n == _n) x |= (Uint(s[i * W + j] - '0')\
    \ << j);\n                    else x |= ((d.back()[i * W + j] ? Uint(1) : Uint(0))\
    \ << j);\n                }\n                v[i] = x;\n            }\n      \
    \      d.push_back(v);\n        }\n        std::reverse(d.begin(), d.end());\n\
    \    }\n\n    int count(int x) const {\n        assert(0 <= x && x < _n);\n  \
    \      return d.back()[x / W] >> (x % W) & 1;\n    }\n\n    void insert(int x)\
    \ {\n        assert(0 <= x && x < _n);\n        for (int dep = (int)d.size() -\
    \ 1; dep >= 0; --dep, x /= W) {\n            if (d[dep][x / W] >> (x % W) & 1)\
    \ break;\n            d[dep][x / W] |= Uint(1) << (x % W);\n        }\n    }\n\
    \n    void erase(int x) {\n        assert(0 <= x && x < _n);\n        for (int\
    \ dep = (int)d.size() - 1; dep >= 0; --dep, x /= W) {\n            if (dep ==\
    \ (int)d.size() - 1) {\n                if (~d[dep][x / W] >> (x % W) & 1) break;\n\
    \                d[dep][x / W] ^= Uint(1) << (x % W);\n            } else {\n\
    \                if (d[dep + 1][x]) break;\n                if (~d[dep][x / W]\
    \ >> (x % W) & 1) break;\n                d[dep][x / W] ^= Uint(1) << (x % W);\n\
    \            }\n        }\n    }\n\n    // return max y s.t. count(y) == 1 &&\
    \ y <= x\n    std::optional<int> predecessor(int x) const {\n        if (x < 0)\
    \ return std::nullopt;\n        if (x >= _n) x = _n - 1;\n        int dep = (int)d.size()\
    \ - 1;\n        for (;; --dep, x /= W) {\n            Uint mask = up_mask(d[dep][x\
    \ / W], x % W);\n            if (dep != (int)d.size() - 1) mask &= ~(Uint(1) <<\
    \ (x % W));\n            int next = _msb(mask);\n            if (next != -1) {\n\
    \                ++dep;\n                x = (x / W) * W + next;\n           \
    \     break;\n            }\n            if (dep == 0) return std::nullopt;\n\
    \        }\n\n        for (; dep < (int)d.size(); x = x * W + _msb(d[dep][x]),\
    \ ++dep) {}\n        return x;\n    }\n\n    // return min y s.t. count(y) ==\
    \ 1 && y >= x\n    std::optional<int> successor(int x) const {\n        if (x\
    \ >= _n) return std::nullopt;\n        if (x < 0) x = 0;\n        int dep = (int)d.size()\
    \ - 1;\n        for (;; --dep, x /= W) {\n            Uint mask = dw_mask(d[dep][x\
    \ / W], x % W);\n            if (dep != (int)d.size() - 1) mask &= ~(Uint(1) <<\
    \ (x % W));\n            int next = _lsb(mask);\n            if (next != -1) {\n\
    \                ++dep;\n                x = (x / W) * W + next;\n           \
    \     break;\n            }\n            if (dep == 0) return std::nullopt;\n\
    \        }\n\n\n        for (; dep < (int)d.size(); x = x * W + _lsb(d[dep][x]),\
    \ ++dep) {}\n        return x;\n    }\n\n  private:\n    static int _msb(Uint\
    \ x) { return x ? msb<Uint>(x) : -1; }\n\n    static int _lsb(Uint x) { return\
    \ x ? lsb<Uint>(x) : -1; }\n\n    static Uint up_mask(Uint x, int i) { return\
    \ x & (((Uint(1) << i) - 1) | (Uint(1) << i)); }\n\n    static Uint dw_mask(Uint\
    \ x, int i) { return x & ~((Uint(1) << i) - 1); }\n};\n\n} // namespace kk2\n\n\
    #endif // KK2_DATA_STRUCTURE_W_ARY_TREE_HPP\n"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  isVerificationFile: false
  path: data_structure/w_ary_tree.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_predecessor_problem.test.cpp
documentation_of: data_structure/w_ary_tree.hpp
layout: document
redirect_from:
- /library/data_structure/w_ary_tree.hpp
- /library/data_structure/w_ary_tree.hpp.html
title: data_structure/w_ary_tree.hpp
---
