---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: data_structure/wavelet_matrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/data_structure/bit_vector.test.cpp
    title: verify/unit_test/data_structure/bit_vector.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/data_structure/wavelet_matrix.test.cpp
    title: verify/unit_test/data_structure/wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_kth_smallest.test.cpp
    title: verify/yosupo_ds/ds_range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/bit_vector.hpp\"\n\n\n\n#include <vector>\n\
    \n#line 1 \"bit/bitcount.hpp\"\n\n\n\n#include <cassert>\n\n#line 1 \"type_traits/integral.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
    \ <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value\n         \
    \                         or std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_signed =\n    typename\
    \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n \
    \                             std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
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
    \    }\n}\n\n}; // namespace kk2\n\n\n#line 7 \"data_structure/bit_vector.hpp\"\
    \n\nnamespace kk2 {\n\nstruct BitVector {\n    using u32 = unsigned int;\n   \
    \ using Uint = unsigned long long;\n    static constexpr int B = 64;\n    int\
    \ n, zeros;\n    std::vector<u32> count;\n    std::vector<Uint> bits;\n    BitVector()\
    \ = default;\n\n    BitVector(int n_) : n(n_), count(n_ / B + 1), bits(n_ / B\
    \ + 1) {}\n\n    inline void set(int i) { bits[i / B] |= Uint(1) << (i % B); }\n\
    \n    void build() {\n        for (u32 i = 1; i < count.size(); ++i) count[i]\
    \ = count[i - 1] + popcount(bits[i - 1]);\n        zeros = n - rank1(n);\n   \
    \ }\n\n    inline int get(int i) const { return (bits[i / B] >> (i % B)) & 1;\
    \ }\n\n    inline int rank0(int i) const { return i - rank1(i); }\n\n    inline\
    \ int rank1(int i) const {\n        return count[i / B] + popcount(bits[i / B]\
    \ & ((Uint(1) << (i % B)) - 1));\n    }\n\n    int select0(int i) const {\n  \
    \      if (i >= zeros) return -1;\n        int lb = 0, ub = n;\n        while\
    \ (ub - lb > 1) {\n            int mid = (lb + ub) / 2;\n            if (rank0(mid)\
    \ > i) ub = mid;\n            else lb = mid;\n        }\n        return lb;\n\
    \    }\n\n    int select1(int i) const {\n        if (i >= n - zeros) return -1;\n\
    \        int lb = 0, ub = n;\n        while (ub - lb > 1) {\n            int mid\
    \ = (lb + ub) / 2;\n            if (rank1(mid) > i) ub = mid;\n            else\
    \ lb = mid;\n        }\n        return lb;\n    }\n};\n\n} // namespace kk2\n\n\
    \n"
  code: "#ifndef KK2_DATA_STRUCTURE_BIT_VECTOR_HPP\n#define KK2_DATA_STRUCTURE_BIT_VECTOR_HPP\
    \ 1\n\n#include <vector>\n\n#include \"../bit/bitcount.hpp\"\n\nnamespace kk2\
    \ {\n\nstruct BitVector {\n    using u32 = unsigned int;\n    using Uint = unsigned\
    \ long long;\n    static constexpr int B = 64;\n    int n, zeros;\n    std::vector<u32>\
    \ count;\n    std::vector<Uint> bits;\n    BitVector() = default;\n\n    BitVector(int\
    \ n_) : n(n_), count(n_ / B + 1), bits(n_ / B + 1) {}\n\n    inline void set(int\
    \ i) { bits[i / B] |= Uint(1) << (i % B); }\n\n    void build() {\n        for\
    \ (u32 i = 1; i < count.size(); ++i) count[i] = count[i - 1] + popcount(bits[i\
    \ - 1]);\n        zeros = n - rank1(n);\n    }\n\n    inline int get(int i) const\
    \ { return (bits[i / B] >> (i % B)) & 1; }\n\n    inline int rank0(int i) const\
    \ { return i - rank1(i); }\n\n    inline int rank1(int i) const {\n        return\
    \ count[i / B] + popcount(bits[i / B] & ((Uint(1) << (i % B)) - 1));\n    }\n\n\
    \    int select0(int i) const {\n        if (i >= zeros) return -1;\n        int\
    \ lb = 0, ub = n;\n        while (ub - lb > 1) {\n            int mid = (lb +\
    \ ub) / 2;\n            if (rank0(mid) > i) ub = mid;\n            else lb = mid;\n\
    \        }\n        return lb;\n    }\n\n    int select1(int i) const {\n    \
    \    if (i >= n - zeros) return -1;\n        int lb = 0, ub = n;\n        while\
    \ (ub - lb > 1) {\n            int mid = (lb + ub) / 2;\n            if (rank1(mid)\
    \ > i) ub = mid;\n            else lb = mid;\n        }\n        return lb;\n\
    \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_DATA_STRUCTURE_BIT_VECTOR_HPP\n"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  isVerificationFile: false
  path: data_structure/bit_vector.hpp
  requiredBy:
  - data_structure/wavelet_matrix.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_range_kth_smallest.test.cpp
  - verify/unit_test/data_structure/bit_vector.test.cpp
  - verify/unit_test/data_structure/wavelet_matrix.test.cpp
documentation_of: data_structure/bit_vector.hpp
layout: document
redirect_from:
- /library/data_structure/bit_vector.hpp
- /library/data_structure/bit_vector.hpp.html
title: data_structure/bit_vector.hpp
---
