---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 1 \"data_structure/wavelet_matrix.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\n#line 1 \"bit/bitcount.hpp\"\n\n\n\n#include <cassert>\n\n\
    #line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value\n          \
    \                        or std::is_same<T, __int128>::value,\n              \
    \                std::true_type,\n                              std::false_type>::type;\n\
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
    \    }\n}\n\n}; // namespace kk2\n\n\n#line 1 \"data_structure/bit_vector.hpp\"\
    \n\n\n\n#line 5 \"data_structure/bit_vector.hpp\"\n\n#line 7 \"data_structure/bit_vector.hpp\"\
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
    \n#line 9 \"data_structure/wavelet_matrix.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <typename T> struct WaveletMatrix {\n    int n, lg;\n    std::vector<T> a;\n\
    \    std::vector<BitVector> mat;\n    bool built = false;\n\n    WaveletMatrix()\
    \ = default;\n\n    WaveletMatrix(int n_) : n(n_), a(n_) {}\n\n    WaveletMatrix(const\
    \ std::vector<T> &a_) : n(a_.size()), a(a_) { build(); }\n\n    void build() {\n\
    \        built = true;\n        lg = 0;\n        T mx = *std::max_element(a.begin(),\
    \ a.end());\n        if (mx <= 0) mx = 1;\n        lg = msb(mx) + 1;\n       \
    \ mat.resize(lg, BitVector(n));\n        std::vector<T> now(a), nxt(n);\n    \
    \    for (int i = lg - 1; i >= 0; --i) {\n            BitVector &bv = mat[i];\n\
    \            for (int j = 0; j < n; ++j) {\n                if ((now[j] >> i)\
    \ & 1) bv.set(j);\n            }\n            bv.build();\n            int one\
    \ = bv.zeros, zero = 0;\n            for (int j = 0; j < n; ++j) {\n         \
    \       if ((now[j] >> i) & 1) {\n                    nxt[one++] = now[j];\n \
    \               } else {\n                    nxt[zero++] = now[j];\n        \
    \        }\n            }\n            std::swap(now, nxt);\n        }\n    }\n\
    \n    void set(int i, T x) {\n        assert(0 <= i && i < n);\n        assert(x\
    \ >= 0);\n        assert(!built);\n        a[i] = x;\n    }\n\n    T access(int\
    \ k) const {\n        assert(0 <= k && k < n);\n        return a[k];\n    }\n\n\
    \    int rank(T b, int k) {\n        assert(0 <= k && k <= n);\n        int l\
    \ = 0, r = k;\n        for (int i = lg - 1; i >= 0; --i) {\n            r = (b\
    \ >> i & 1) ? mat[i].rank1(r) + mat[i].zeros : mat[i].rank0(r);\n            l\
    \ = (b >> i & 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);\n       \
    \ }\n        return r - l;\n    }\n\n    int select(T b, int k) {\n        assert(0\
    \ <= k && k < n);\n        int l = 0;\n        for (int i = lg - 1; i >= 0; --i)\n\
    \            l = (b >> i & 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);\n\
    \        k += l;\n        for (int i = 0; i < lg; ++i) {\n            k = (b >>\
    \ i & 1) ? mat[i].select1(k - mat[i].zeros) : mat[i].select0(k);\n           \
    \ if (k == -1) return -1;\n        }\n        return k;\n    }\n\n    T kth_smallest(int\
    \ l, int r, int k) const {\n        assert(0 <= l && l <= r && r <= n);\n    \
    \    assert(r - l > k);\n        T res = 0;\n        for (int i = lg - 1; i >=\
    \ 0; --i) {\n            int ll = mat[i].rank0(l), rr = mat[i].rank0(r);\n   \
    \         if (k < rr - ll) {\n                l = ll, r = rr;\n            } else\
    \ {\n                k -= rr - ll;\n                res |= T(1) << i;\n      \
    \          l += mat[i].zeros - ll;\n                r += mat[i].zeros - rr;\n\
    \            }\n        }\n        return res;\n    }\n\n    T kth_largest(int\
    \ l, int r, int k) const {\n        assert(0 <= l && l <= r && r <= n);\n    \
    \    assert(r - l > k);\n        return kth_smallest(l, r, r - l - k - 1);\n \
    \   }\n\n    int range_freq(int l, int r, T upper) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        assert(0 <= upper);\n        if (upper >> lg)\
    \ return r - l;\n        int res = 0;\n        for (int i = lg - 1; i >= 0; --i)\
    \ {\n            if (upper >> i & 1) res += mat[i].rank0(r) - mat[i].rank0(l);\n\
    \            l = (upper >> i & 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);\n\
    \            r = (upper >> i & 1) ? mat[i].rank1(r) + mat[i].zeros : mat[i].rank0(r);\n\
    \            if (l == r) break;\n        }\n        return res;\n    }\n\n   \
    \ int range_freq(int l, int r, T lower, T upper) {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        assert(0 <= lower && lower <= upper);\n        return\
    \ range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\n    T max_not_greater(int\
    \ l, int r, T b) {\n        assert(0 <= l && l <= r && r <= n);\n        int count\
    \ = range_freq(l, r, b + 1);\n        return count == 0 ? -1 : kth_smallest(l,\
    \ r, count - 1);\n    }\n\n    T min_not_less(int l, int r, T b) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        int count = range_freq(l, r, b);\n     \
    \   return count == r - l ? -1 : kth_smallest(l, r, count);\n    }\n};\n\n} //\
    \ namespace kk2\n\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP\n#define KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\n#include \"../bit/bitcount.hpp\"\
    \n#include \"bit_vector.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T> struct\
    \ WaveletMatrix {\n    int n, lg;\n    std::vector<T> a;\n    std::vector<BitVector>\
    \ mat;\n    bool built = false;\n\n    WaveletMatrix() = default;\n\n    WaveletMatrix(int\
    \ n_) : n(n_), a(n_) {}\n\n    WaveletMatrix(const std::vector<T> &a_) : n(a_.size()),\
    \ a(a_) { build(); }\n\n    void build() {\n        built = true;\n        lg\
    \ = 0;\n        T mx = *std::max_element(a.begin(), a.end());\n        if (mx\
    \ <= 0) mx = 1;\n        lg = msb(mx) + 1;\n        mat.resize(lg, BitVector(n));\n\
    \        std::vector<T> now(a), nxt(n);\n        for (int i = lg - 1; i >= 0;\
    \ --i) {\n            BitVector &bv = mat[i];\n            for (int j = 0; j <\
    \ n; ++j) {\n                if ((now[j] >> i) & 1) bv.set(j);\n            }\n\
    \            bv.build();\n            int one = bv.zeros, zero = 0;\n        \
    \    for (int j = 0; j < n; ++j) {\n                if ((now[j] >> i) & 1) {\n\
    \                    nxt[one++] = now[j];\n                } else {\n        \
    \            nxt[zero++] = now[j];\n                }\n            }\n       \
    \     std::swap(now, nxt);\n        }\n    }\n\n    void set(int i, T x) {\n \
    \       assert(0 <= i && i < n);\n        assert(x >= 0);\n        assert(!built);\n\
    \        a[i] = x;\n    }\n\n    T access(int k) const {\n        assert(0 <=\
    \ k && k < n);\n        return a[k];\n    }\n\n    int rank(T b, int k) {\n  \
    \      assert(0 <= k && k <= n);\n        int l = 0, r = k;\n        for (int\
    \ i = lg - 1; i >= 0; --i) {\n            r = (b >> i & 1) ? mat[i].rank1(r) +\
    \ mat[i].zeros : mat[i].rank0(r);\n            l = (b >> i & 1) ? mat[i].rank1(l)\
    \ + mat[i].zeros : mat[i].rank0(l);\n        }\n        return r - l;\n    }\n\
    \n    int select(T b, int k) {\n        assert(0 <= k && k < n);\n        int\
    \ l = 0;\n        for (int i = lg - 1; i >= 0; --i)\n            l = (b >> i &\
    \ 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);\n        k += l;\n  \
    \      for (int i = 0; i < lg; ++i) {\n            k = (b >> i & 1) ? mat[i].select1(k\
    \ - mat[i].zeros) : mat[i].select0(k);\n            if (k == -1) return -1;\n\
    \        }\n        return k;\n    }\n\n    T kth_smallest(int l, int r, int k)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        assert(r - l >\
    \ k);\n        T res = 0;\n        for (int i = lg - 1; i >= 0; --i) {\n     \
    \       int ll = mat[i].rank0(l), rr = mat[i].rank0(r);\n            if (k < rr\
    \ - ll) {\n                l = ll, r = rr;\n            } else {\n           \
    \     k -= rr - ll;\n                res |= T(1) << i;\n                l += mat[i].zeros\
    \ - ll;\n                r += mat[i].zeros - rr;\n            }\n        }\n \
    \       return res;\n    }\n\n    T kth_largest(int l, int r, int k) const {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        assert(r - l > k);\n   \
    \     return kth_smallest(l, r, r - l - k - 1);\n    }\n\n    int range_freq(int\
    \ l, int r, T upper) const {\n        assert(0 <= l && l <= r && r <= n);\n  \
    \      assert(0 <= upper);\n        if (upper >> lg) return r - l;\n        int\
    \ res = 0;\n        for (int i = lg - 1; i >= 0; --i) {\n            if (upper\
    \ >> i & 1) res += mat[i].rank0(r) - mat[i].rank0(l);\n            l = (upper\
    \ >> i & 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);\n            r\
    \ = (upper >> i & 1) ? mat[i].rank1(r) + mat[i].zeros : mat[i].rank0(r);\n   \
    \         if (l == r) break;\n        }\n        return res;\n    }\n\n    int\
    \ range_freq(int l, int r, T lower, T upper) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        assert(0 <= lower && lower <= upper);\n        return\
    \ range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\n    T max_not_greater(int\
    \ l, int r, T b) {\n        assert(0 <= l && l <= r && r <= n);\n        int count\
    \ = range_freq(l, r, b + 1);\n        return count == 0 ? -1 : kth_smallest(l,\
    \ r, count - 1);\n    }\n\n    T min_not_less(int l, int r, T b) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        int count = range_freq(l, r, b);\n     \
    \   return count == r - l ? -1 : kth_smallest(l, r, count);\n    }\n};\n\n} //\
    \ namespace kk2\n\n\n#endif // KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP\n"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - data_structure/bit_vector.hpp
  isVerificationFile: false
  path: data_structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_range_kth_smallest.test.cpp
  - verify/unit_test/data_structure/wavelet_matrix.test.cpp
documentation_of: data_structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/data_structure/wavelet_matrix.hpp
- /library/data_structure/wavelet_matrix.hpp.html
title: data_structure/wavelet_matrix.hpp
---
