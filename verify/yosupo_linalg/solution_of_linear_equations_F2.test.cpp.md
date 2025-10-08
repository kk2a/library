---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: data_structure/my_bitset.hpp
    title: data_structure/my_bitset.hpp
  - icon: ':question:'
    path: matrix/matrix_F2.hpp
    title: "\u6383\u304D\u51FA\u3057"
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
  bundledCode: "#line 1 \"verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2\"\
    \n\n#line 1 \"matrix/matrix_F2.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <optional>\n#include <string>\n#include <vector>\n\
    \n#line 1 \"data_structure/my_bitset.hpp\"\n\n\n\n#line 5 \"data_structure/my_bitset.hpp\"\
    \n#include <bitset>\n#line 8 \"data_structure/my_bitset.hpp\"\n#include <iterator>\n\
    #line 11 \"data_structure/my_bitset.hpp\"\n\n#line 1 \"bit/bitcount.hpp\"\n\n\n\
    \n#line 5 \"bit/bitcount.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n\
    #include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename\
    \ T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T, __int128_t>::value\n\
    \                                  or std::is_same<T, __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
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
    \    }\n}\n\n}; // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include\
    \ <istream>\n#include <ostream>\n#line 7 \"type_traits/io.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\
    \n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
    \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n    \
    \                              || std::is_same<T, std::ifstream>::value,\n   \
    \                           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 14 \"data_structure/my_bitset.hpp\"\n\nnamespace kk2 {\n\nstruct\
    \ DynamicBitSet {\n    using T = DynamicBitSet;\n    using UInt = __uint128_t;\n\
    \    constexpr static int BLOCK_SIZE = sizeof(UInt) * 8;\n    constexpr static\
    \ int BLOCK_SIZE_LOG = __builtin_ctz(BLOCK_SIZE);\n    constexpr static int BLOCK_MASK\
    \ = BLOCK_SIZE - 1;\n    constexpr static UInt ONE = 1;\n    int n;\n    std::vector<UInt>\
    \ block;\n\n    DynamicBitSet(int n_ = 0, bool x = 0) : n(n_) {\n        UInt\
    \ val = x ? -1 : 0;\n        block.assign((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG,\
    \ val);\n        if (n & BLOCK_MASK) block.back() >>= BLOCK_SIZE - (n & BLOCK_MASK);\n\
    \        // fit the last block\n    }\n\n    DynamicBitSet(const std::string &s)\
    \ : n(s.size()) {\n        block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        set(s);\n    }\n\n    inline int size() const { return n; }\n\n    T\
    \ &inplace_combine_top(const T &rhs) {\n        block.resize((n + rhs.n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG);\n        if (!(n & BLOCK_MASK)) {\n            std::copy(std::begin(rhs.block),\n\
    \                      std::end(rhs.block),\n                      std::begin(block)\
    \ + (n >> BLOCK_SIZE_LOG));\n            n += rhs.n;\n            return *this;\n\
    \        }\n        int start = BLOCK_SIZE - (n & BLOCK_MASK);\n        UInt start_mask\
    \ = (ONE << start) - 1;\n        UInt end_mask = ~start_mask;\n        for (int\
    \ i = 0; i < (rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            UInt\
    \ x = rhs.block[i];\n            block[i + (n >> BLOCK_SIZE_LOG)] |= (x & start_mask)\
    \ << (BLOCK_SIZE - start);\n            if (i + (n >> BLOCK_SIZE_LOG) + 1 < (n\
    \ + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)\n                block[i + (n >>\
    \ BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;\n        }\n        n += rhs.n;\n\
    \        return *this;\n    }\n\n    T combine_top(const T &rhs) const { return\
    \ T(*this).inplace_combine_top(rhs); }\n\n    T &inplace_combine_bottom(const\
    \ T &rhs) {\n        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        if (!(rhs.n & BLOCK_MASK)) {\n            std::vector<UInt> tmp(block.begin(),\
    \ block.begin() + n);\n            std::copy(\n                std::begin(tmp),\
    \ std::begin(tmp), std::begin(block) + (rhs.n >> BLOCK_SIZE_LOG));\n         \
    \   std::copy(std::begin(rhs.block), std::end(rhs.block), std::begin(block));\n\
    \            n += rhs.n;\n            return *this;\n        }\n        int start\
    \ = BLOCK_SIZE - (rhs.n & BLOCK_MASK);\n        UInt start_mask = (ONE << start)\
    \ - 1;\n        UInt end_mask = ~start_mask;\n        for (int i = ((n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG) - 1; i >= 0; --i) {\n            UInt x = block[i];\n\
    \            block[i + (rhs.n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE\
    \ - start);\n            if (i + (rhs.n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n +\
    \ BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)\n                block[i + (rhs.n >> BLOCK_SIZE_LOG)\
    \ + 1] |= (x & end_mask) >> start;\n        }\n        block[(rhs.n >> BLOCK_SIZE_LOG)]\
    \ =\n            ((block[0] & start_mask) << (BLOCK_SIZE - start)) | rhs.block.back();\n\
    \        std::copy(std::begin(rhs.block), std::prev(std::end(rhs.block)), std::begin(block));\n\
    \        n += rhs.n;\n        return *this;\n    }\n\n    T combine_bottom(const\
    \ T &rhs) const { return T(*this).inplace_combine_bottom(rhs); }\n\n    void set(int\
    \ i, int x) {\n        assert(0 <= i && i < n);\n        if (x) block[i >> BLOCK_SIZE_LOG]\
    \ |= ONE << (i & BLOCK_MASK);\n        else block[i >> BLOCK_SIZE_LOG] &= ~(ONE\
    \ << (i & BLOCK_MASK));\n    }\n\n    void set(const std::string &s) {\n     \
    \   assert((int)s.size() == n);\n        for (int i = 0; i < (n + BLOCK_SIZE -\
    \ 1) >> BLOCK_SIZE_LOG; i++) {\n            int r = n - (i << BLOCK_SIZE_LOG),\
    \ l = std::max(0, r - BLOCK_SIZE);\n            block[i] = 0;\n            for\
    \ (int j = l; j < r; j++) block[i] = (block[i] << 1) | (s[j] - '0');\n       \
    \ }\n    }\n\n    void set_reversed(const std::string &s) {\n        assert((int)s.size()\
    \ == n);\n        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i++) {\n            int l = i << BLOCK_SIZE_LOG, r = std::min(n, l + BLOCK_SIZE);\n\
    \            block[i] = 0;\n            for (int j = r - 1; j >= l; --j) block[i]\
    \ = (block[i] << 1) | (s[j] - '0');\n        }\n    }\n\n    struct BitReference\
    \ {\n        std::vector<UInt> &block;\n        int idx;\n\n      public:\n  \
    \      BitReference(std::vector<UInt> &block_, int idx_) : block(block_), idx(idx_)\
    \ {}\n\n        operator bool() const { return (block[idx >> BLOCK_SIZE_LOG] >>\
    \ (idx & BLOCK_MASK)) & 1; }\n\n        template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n        friend IStream &operator>>(IStream &is, BitReference a)\
    \ {\n            bool c;\n            is >> c;\n            a = c;\n         \
    \   return is;\n        }\n\n        BitReference &operator=(bool x) {\n     \
    \       if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n  \
    \          else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n\
    \            return *this;\n        }\n\n        BitReference &operator=(const\
    \ BitReference &other) {\n            if (other) block[idx >> BLOCK_SIZE_LOG]\
    \ |= ONE << (idx & BLOCK_MASK);\n            else block[idx >> BLOCK_SIZE_LOG]\
    \ &= ~(ONE << (idx & BLOCK_MASK));\n            return *this;\n        }\n\n \
    \       BitReference &operator&=(bool x) {\n            if (!x) block[idx >> BLOCK_SIZE_LOG]\
    \ &= ~(ONE << (idx & BLOCK_MASK));\n            return *this;\n        }\n\n \
    \       BitReference &operator&=(const BitReference &other) {\n            if\
    \ (!other) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n   \
    \         return *this;\n        }\n\n        BitReference &operator|=(bool x)\
    \ {\n            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n\
    \            return *this;\n        }\n\n        BitReference &operator|=(const\
    \ BitReference &other) {\n            if (other) block[idx >> BLOCK_SIZE_LOG]\
    \ |= ONE << (idx & BLOCK_MASK);\n            return *this;\n        }\n\n    \
    \    BitReference &operator^=(bool x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG]\
    \ ^= ONE << (idx & BLOCK_MASK);\n            return *this;\n        }\n\n    \
    \    BitReference &operator^=(const BitReference &other) {\n            if (other)\
    \ block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n            return\
    \ *this;\n        }\n\n        BitReference &flip() {\n            block[idx >>\
    \ BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n            return *this;\n \
    \       }\n\n        BitReference &operator~() {\n            block[idx >> BLOCK_SIZE_LOG]\
    \ ^= ONE << (idx & BLOCK_MASK);\n            return *this;\n        }\n\n    \
    \    bool val() const { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK))\
    \ & 1; }\n    };\n\n    BitReference operator[](int i) {\n        assert(0 <=\
    \ i && i < n);\n        return BitReference(block, i);\n    }\n\n    bool is_pinned(int\
    \ i) const {\n        assert(0 <= i && i < n);\n        return (block[i >> BLOCK_SIZE_LOG]\
    \ >> (i & BLOCK_MASK)) & 1;\n    }\n\n    T &operator=(const std::string &s) {\n\
    \        set(s);\n        return *this;\n    }\n\n    T &flip() {\n        UInt\
    \ mask = (ONE << (n & BLOCK_MASK)) - 1;\n        for (UInt &x : block) x = ~x;\n\
    \        block.back() &= mask;\n        return *this;\n    }\n\n    T &flip(int\
    \ i) {\n        assert(0 <= i && i < n);\n        block[i >> BLOCK_SIZE_LOG] ^=\
    \ ONE << (i & BLOCK_MASK);\n        return *this;\n    }\n\n    int ctz() const\
    \ {\n        int res = 0;\n        int i = 0;\n        for (; i < (n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG; ++i) {\n            if (block[i]) break;\n         \
    \   res += BLOCK_SIZE;\n        }\n        assert(i < (n + BLOCK_SIZE - 1) >>\
    \ BLOCK_SIZE_LOG);\n        res += kk2::ctz(block[i]);\n        return res;\n\
    \    }\n\n    int clz() const {\n        int res = 0;\n        int i = ((n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG);\n        for (; i--;) {\n            if (block[i])\
    \ break;\n            if (i + 1 == (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG) {\n\
    \                res += n & BLOCK_MASK;\n            } else {\n              \
    \  res += BLOCK_SIZE;\n            }\n        }\n        assert(i >= 0);\n   \
    \     if (i + 1 == (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG) {\n            res\
    \ += kk2::clz(block[i]) - (BLOCK_SIZE - (n & BLOCK_MASK));\n        } else {\n\
    \            res += kk2::clz(block[i]);\n        }\n        return res;\n    }\n\
    \n    int popcount() const {\n        int res = 0;\n        for (int i = 0; i\
    \ < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            res += kk2::popcount(block[i]);\n\
    \        }\n        return res;\n    }\n\n    T &operator~() { return flip();\
    \ }\n\n    T &operator&=(const T &other) {\n        assert(n == other.n);\n  \
    \      for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n  \
    \          block[i] &= other.block[i];\n        }\n        return *this;\n   \
    \ }\n\n    T &operator|=(const T &other) {\n        assert(n == other.n);\n  \
    \      for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n  \
    \          block[i] |= other.block[i];\n        }\n        return *this;\n   \
    \ }\n\n    T &operator^=(const T &other) {\n        assert(n == other.n);\n  \
    \      for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n  \
    \          block[i] ^= other.block[i];\n        }\n        return *this;\n   \
    \ }\n\n    friend T operator&(const T &lhs, const T &rhs) { return T(lhs) &= rhs;\
    \ }\n\n    friend T operator|(const T &lhs, const T &rhs) { return T(lhs) |= rhs;\
    \ }\n\n    friend T operator^(const T &lhs, const T &rhs) { return T(lhs) ^= rhs;\
    \ }\n\n    friend bool operator==(const T &lhs, const T &rhs) {\n        if (lhs.n\
    \ != rhs.n) return false;\n        for (int i = 0; i < (lhs.n + BLOCK_SIZE - 1)\
    \ >> BLOCK_SIZE_LOG; i++) {\n            if (lhs.block[i] != rhs.block[i]) return\
    \ false;\n        }\n        return true;\n    }\n\n    friend bool operator!=(const\
    \ T &lhs, const T &rhs) { return !(lhs == rhs); }\n\n    operator bool() const\
    \ {\n        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++)\
    \ {\n            if (block[i]) return true;\n        }\n        return false;\n\
    \    }\n\n    std::string to_string(UInt x) const {\n        return std::bitset<64>((unsigned\
    \ long long)(x >> (BLOCK_SIZE / 2))).to_string()\n               + std::bitset<64>((unsigned\
    \ long long)(x & ((ONE << (BLOCK_SIZE / 2)) - 1)))\n                     .to_string();\n\
    \    }\n\n    std::string to_string() const {\n        std::vector<std::string>\
    \ tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        for (int i = 0; i < (n\
    \ + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            tmp[i] = to_string(block[i]);\n\
    \        }\n        if (n & BLOCK_MASK) {\n            std::reverse(std::begin(tmp.back()),\
    \ std::end(tmp.back()));\n            tmp.back().resize(n & BLOCK_MASK);\n   \
    \         std::reverse(std::begin(tmp.back()), std::end(tmp.back()));\n      \
    \  }\n        std::string res;\n        for (int i = (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i--;) { res += tmp[i]; }\n        return res;\n    }\n\n    std::string to_reversed_string()\
    \ const {\n        std::vector<std::string> tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
    \            tmp[i] = to_string(block[i]);\n        }\n        if (n & BLOCK_MASK)\
    \ {\n            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));\n\
    \            tmp.back().resize(n & BLOCK_MASK);\n            std::reverse(std::begin(tmp.back()),\
    \ std::end(tmp.back()));\n        }\n        std::string res;\n        for (int\
    \ i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            std::reverse(std::begin(tmp[i]),\
    \ std::end(tmp[i]));\n            res += tmp[i];\n        }\n        return res;\n\
    \    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n  \
    \  friend OStream &operator<<(OStream &os, const T &bs) {\n        return os <<\
    \ bs.to_string();\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, T &bs) {\n       \
    \ std::string s;\n        is >> s;\n        bs.set_reversed(s);\n        return\
    \ is;\n    }\n};\n\n} // namespace kk2\n\n\n#line 13 \"matrix/matrix_F2.hpp\"\n\
    \nnamespace kk2 {\n\nstruct MatrixF2 {\n    using mat = MatrixF2;\n    int _h,\
    \ _w;\n    std::vector<DynamicBitSet> _mat;\n\n    MatrixF2() : MatrixF2(0) {}\n\
    \    MatrixF2(int n) : MatrixF2(n, n) {}\n\n    MatrixF2(int h, int w) {\n   \
    \     if (h == 0) {\n            _h = 0;\n            _w = w;\n        } else\
    \ {\n            _h = h;\n            _w = w;\n            _mat.resize(h, DynamicBitSet(w));\n\
    \        }\n    }\n\n    MatrixF2(const std::vector<DynamicBitSet> &mat_)\n  \
    \      : _h(mat_.size()),\n          _w(mat_[0].size()),\n          _mat(mat_)\
    \ {}\n\n    static mat unit(int n) {\n        mat res(n, n);\n        for (int\
    \ i = 0; i < n; i++) res[i][i] = 1;\n        return res;\n    }\n\n    inline\
    \ int get_h() const { return _h; }\n\n    inline int get_w() const { return _w;\
    \ }\n\n    class Proxy {\n        std::vector<DynamicBitSet> &bs;\n        int\
    \ i;\n\n      public:\n        Proxy(std::vector<DynamicBitSet> &bs_, int i_)\
    \ : bs(bs_), i(i_) {}\n\n        operator DynamicBitSet() const { return bs[i];\
    \ }\n\n        template <class IStream, is_istream_t<IStream> * = nullptr>\n \
    \       friend IStream &operator>>(IStream &is, Proxy p) {\n            std::string\
    \ s;\n            is >> s;\n            p = s;\n            return is;\n     \
    \   }\n\n        template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \        friend OStream &operator<<(OStream &os, Proxy p) {\n            os <<\
    \ p.to_reversed_string();\n            return os;\n        }\n\n        std::string\
    \ to_string() const { return bs[i].to_string(); }\n        std::string to_reversed_string()\
    \ const { return bs[i].to_reversed_string(); }\n\n        Proxy &operator=(const\
    \ std::string &s) {\n            bs[i].set_reversed(s);\n            return *this;\n\
    \        }\n\n        Proxy &operator=(const DynamicBitSet &x) {\n           \
    \ bs[i] = x;\n            return *this;\n        }\n\n        Proxy &operator=(const\
    \ Proxy &x) {\n            bs[i] = x.bs[x.i];\n            return *this;\n   \
    \     }\n\n        DynamicBitSet::BitReference operator[](int j) {\n         \
    \   assert(0 <= j && j < (int)bs[i].size());\n            return bs[i][j];\n \
    \       }\n\n        Proxy &operator&=(const DynamicBitSet &x) {\n           \
    \ bs[i] &= x;\n            return *this;\n        }\n\n        Proxy &operator&=(const\
    \ Proxy &x) {\n            bs[i] &= x.bs[x.i];\n            return *this;\n  \
    \      }\n\n        Proxy &operator|=(const DynamicBitSet &x) {\n            bs[i]\
    \ |= x;\n            return *this;\n        }\n\n        Proxy &operator|=(const\
    \ Proxy &x) {\n            bs[i] |= x.bs[x.i];\n            return *this;\n  \
    \      }\n\n        Proxy &flip() {\n            bs[i].flip();\n            return\
    \ *this;\n        }\n\n        Proxy &operator~() {\n            bs[i].flip();\n\
    \            return *this;\n        }\n    };\n\n    Proxy operator[](int i) {\n\
    \        assert(0 <= i && i < _h);\n        return Proxy(_mat, i);\n    }\n\n\
    \    template <class IStream, is_istream_t<IStream> * = nullptr> mat &input(IStream\
    \ &is) {\n        for (int i = 0; i < _h; i++) {\n            std::string s;\n\
    \            is >> s;\n            _mat[i].set_reversed(s);\n        }\n     \
    \   return *this;\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os) const {\n        for (int i = 0; i < _h;\
    \ i++) { os << _mat[i].to_reversed_string() << \"\\n\"; }\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream\
    \ &os) const {\n        os << \"(h, w): \" << \"(\" << _h << \", \" << _w << \"\
    ), [\\n\";\n        for (int i = 0; i < _h; i++) {\n            os << \"  [ \"\
    ;\n            for (int j = 0; j < _w; ++j) os << _mat[i].is_pinned(j) << \" \"\
    ;\n            os << \"]\\n\";\n        }\n        os << \"]\\n\";\n    }\n\n\
    \    void set(int i, int j, bool x) {\n        assert(0 <= i && i < _h);\n   \
    \     assert(0 <= j && j < _w);\n        _mat[i].set(j, x);\n    }\n\n    void\
    \ set(int i, const std::string &s) {\n        assert((int)s.size() == _w);\n \
    \       _mat[i].set(s);\n    }\n\n    void set_reversed(int i, const std::string\
    \ &s) {\n        assert((int)s.size() == _w);\n        _mat[i].set_reversed(s);\n\
    \    }\n\n    mat &operator+=(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) _mat[i] ^=\
    \ rhs._mat[i];\n        return *this;\n    }\n\n    mat &operator-=(const mat\
    \ &rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n    \
    \    for (int i = 0; i < _h; i++) _mat[i] ^= rhs._mat[i];\n        return *this;\n\
    \    }\n\n    mat &operator|=(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) _mat[i] |=\
    \ rhs._mat[i];\n        return *this;\n    }\n\n    mat &operator&=(const mat\
    \ &rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n    \
    \    for (int i = 0; i < _h; i++) _mat[i] &= rhs._mat[i];\n        return *this;\n\
    \    }\n\n    mat &operator*=(const mat &rhs) {\n        assert(_w == rhs._h);\n\
    \        std::vector<DynamicBitSet> res(_h, DynamicBitSet(rhs._w));\n        for\
    \ (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) {\n   \
    \             if (_mat[i][j]) res[i] ^= rhs._mat[j];\n            }\n        }\n\
    \        _w = rhs._w;\n        _mat = std::move(res);\n        return *this;\n\
    \    }\n\n    /**\n     * @brief \u6383\u304D\u51FA\u3057\n     * @tparam RREF\
    \ \u884C\u7C21\u7D04\u5316\u884C\u5217\u306B\u3059\u308B\u304B\u3069\u3046\u304B\
    \n     * @tparam EARLY_TERMINATE \u30D5\u30EB\u30E9\u30F3\u30AF\u3067\u306A\u3044\
    \u3053\u3068\u304C\u78BA\u5B9A\u3057\u305F\u3068\u304D\u306B\u5373\u6253\u3061\
    \u5207\u308B\u304B\u3069\u3046\u304B\n     * @param wr \u5217\u304C[0, wr)\u306E\
    \u7BC4\u56F2\u3060\u3051\u3067\u6383\u304D\u51FA\u3059\uFF0E\u6307\u5B9A\u304C\
    \u306A\u3044\u306A\u3089\u5168\u4F53\u3067\u6383\u304D\u51FA\u3059\uFF0E\n   \
    \  * @return int \u30E9\u30F3\u30AF\uFF0EEARLY_TERMINATE\u304Ctrue\u306E\u3068\
    \u304D\u306B\uFF0C\u30D5\u30EB\u30E9\u30F3\u30AF\u3067\u306A\u3044\u3053\u3068\
    \u304C\u78BA\u5B9A\u3057\u305F\u3089-1\u3092\u8FD4\u3059\n     */\n    template\
    \ <bool RREF = true, bool EARLY_TERMINATE = false> int sweep(int wr = -1) {\n\
    \        if (wr == -1) wr = _w;\n        int r = 0;\n        for (int i = 0; i\
    \ < wr; i++) {\n            if (r >= _h) break;\n            int pivot = -1;\n\
    \            for (int j = r; j < _h; j++) {\n                if (_mat[j][i]) {\n\
    \                    pivot = j;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) {\n                if constexpr (EARLY_TERMINATE)\
    \ return -1;\n                continue;\n            }\n            if (r != pivot)\
    \ std::swap(_mat[r], _mat[pivot]);\n            for (int j = RREF ? 0 : r + 1;\
    \ j < _h; j++) {\n                if (j == r) continue;\n                if (_mat[j][i])\
    \ _mat[j] ^= _mat[r];\n            }\n            r++;\n        }\n        return\
    \ r;\n    }\n\n    mat &shrink() {\n        while (_h && !bool(_mat.back())) _mat.pop_back(),\
    \ --_h;\n        return *this;\n    }\n\n    std::optional<mat> solve(const mat\
    \ &b) const {\n        assert(_h == b._h);\n        assert(b._w == 1);\n     \
    \   mat ab = combine_right(b);\n        int r = ab.sweep<true, false>();\n   \
    \     if (r and ab._mat[r - 1].ctz() == _w) return std::nullopt;\n        mat\
    \ res(1 + _w - r, _w);\n        std::vector<int> idx(_w, -1), step(r, -1);\n \
    \       for (int i = 0, j = 0, now = 0; j < _w; j++) {\n            if (i == r\
    \ or !bool(ab[i][j])) idx[j] = now, res[1 + now++][j] = 1;\n            else res[0][j]\
    \ = ab[i][_w], step[i++] = j;\n        }\n        for (int i = 0; i < r; i++)\
    \ {\n            for (int j = 0; j < _w; j++) {\n                if (idx[j] !=\
    \ -1) res[idx[j] + 1][step[i]] = ab[i][j];\n            }\n        }\n       \
    \ return res;\n    }\n\n    int rank() const { return mat(*this).sweep<false,\
    \ false>(); }\n\n    bool det() const {\n        assert(_h == _w);\n        return\
    \ mat(*this).sweep<false, true>() != -1;\n    }\n\n    std::optional<mat> inv()\
    \ const {\n        assert(_h == _w);\n        std::vector<DynamicBitSet> res(_h,\
    \ _w);\n        for (int i = 0; i < _h; i++) { res[i][i] = 1; }\n        std::vector<DynamicBitSet>\
    \ buf(_mat);\n        for (int i = 0; i < _w; i++) {\n            int pivot =\
    \ -1;\n            for (int j = i; j < _h; j++) {\n                if (buf[j][i])\
    \ {\n                    pivot = j;\n                    break;\n            \
    \    }\n            }\n            if (pivot == -1) return {};\n            std::swap(buf[i],\
    \ buf[pivot]);\n            std::swap(res[i], res[pivot]);\n            for (int\
    \ j = 0; j < _h; j++) {\n                if (j == i) continue;\n             \
    \   if (buf[j][i]) {\n                    buf[j] ^= buf[i];\n                \
    \    res[j] ^= res[i];\n                }\n            }\n        }\n        return\
    \ mat(res);\n    }\n\n    template <class T> mat pow(T n) const {\n        assert(_h\
    \ == _w);\n        assert(n >= 0);\n        mat mul(_mat), res = mat::unit(_h);\n\
    \        while (n) {\n            if (n & 1) res *= mul;\n            if (n >>=\
    \ 1) mul *= mul;\n        }\n        return res;\n    }\n\n    mat &inplace_combine_top(const\
    \ mat &rhs) {\n        assert(_w == rhs._w);\n        _mat.insert(std::begin(_mat),\
    \ std::begin(rhs._mat), std::end(rhs._mat));\n        _h += rhs._h;\n        return\
    \ *this;\n    }\n\n    mat &inplace_combine_bottom(const mat &rhs) {\n       \
    \ assert(_w == rhs._w);\n        _mat.insert(std::end(_mat), std::begin(rhs._mat),\
    \ std::end(rhs._mat));\n        _h += rhs._h;\n        return *this;\n    }\n\n\
    \    mat &inplace_combine_right(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        for (int i = 0; i < _h; i++) _mat[i].inplace_combine_top(rhs._mat[i]);\n\
    \        _w += rhs._w;\n        return *this;\n    }\n\n    mat &inplace_combine_left(const\
    \ mat &rhs) {\n        assert(_h == rhs._h);\n        for (int i = 0; i < _h;\
    \ i++) _mat[i].inplace_combine_bottom(rhs._mat[i]);\n        _w += rhs._w;\n \
    \       return *this;\n    }\n\n    mat transpose() {\n        mat res(_w, _h);\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ { res[j][i] = _mat[i][j]; }\n        }\n        return res;\n    }\n\n    mat\
    \ combine_top(const mat &rhs) const { return mat(*this).inplace_combine_top(rhs);\
    \ }\n    mat combine_bottom(const mat &rhs) const { return mat(*this).inplace_combine_bottom(rhs);\
    \ }\n    mat combine_left(const mat &rhs) const { return mat(*this).inplace_combine_left(rhs);\
    \ }\n    mat combine_right(const mat &rhs) const { return mat(*this).inplace_combine_right(rhs);\
    \ }\n    mat &inplace_transpose() { return *this = transpose(); }\n    friend\
    \ mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) += rhs; }\n\
    \    friend mat operator-(const mat &lhs, const mat &rhs) { return mat(lhs) -=\
    \ rhs; }\n    friend mat operator|(const mat &lhs, const mat &rhs) { return mat(lhs)\
    \ |= rhs; }\n    friend mat operator&(const mat &lhs, const mat &rhs) { return\
    \ mat(lhs) &= rhs; }\n    friend mat operator*(const mat &lhs, const mat &rhs)\
    \ { return mat(lhs) *= rhs; }\n    friend bool operator==(const mat &lhs, const\
    \ mat &rhs) {\n        if (lhs._h != rhs._h) return false;\n        if (lhs._w\
    \ != rhs._w) return false;\n        for (int i = 0; i < lhs._h; i++) {\n     \
    \       if (lhs._mat[i] != rhs._mat[i]) return false;\n        }\n        return\
    \ true;\n    }\n    friend bool operator!=(const mat &lhs, const mat &rhs) { return\
    \ !(lhs == rhs); }\n};\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\
    \n\n\n\n#line 5 \"template/template.hpp\"\n#include <array>\n#line 8 \"template/template.hpp\"\
    \n#include <chrono>\n#include <cmath>\n#include <deque>\n#include <functional>\n\
    #line 13 \"template/template.hpp\"\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#line 17 \"template/template.hpp\"\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#line 22 \"template/template.hpp\"\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line 26 \"template/template.hpp\"\
    \n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line 1 \"template/type_alias.hpp\"\
    \n\n\n\n#line 8 \"template/type_alias.hpp\"\n\nusing u32 = unsigned int;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
    \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\n\
    template <class T> using vc = std::vector<T>;\ntemplate <class T> using vvc =\
    \ std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
    template <class T> using vvvvc = std::vector<vvvc<T>>;\n\ntemplate <class T> using\
    \ pq = std::priority_queue<T>;\ntemplate <class T> using pqi = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\n\n#line 5 \"template/constant.hpp\"\n\n\
    template <class T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int>\
    \ = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll\
    \ << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1)\
    \ << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr\
    \ u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128 infty<u128> = infty<i128>;\n\
    template <> constexpr double infty<double> = infty<i64>;\ntemplate <> constexpr\
    \ long double infty<long double> = infty<i64>;\n\nconstexpr int mod = 998244353;\n\
    constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
    \n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#include <cstdint>\n\
    #include <cstdio>\n#include <fstream>\n#line 10 \"template/fastio.hpp\"\n\n#line\
    \ 13 \"template/fastio.hpp\"\n\nnamespace kk2 {\n\nnamespace fastio {\n\nstruct\
    \ Scanner : type_traits::istream_tag {\n  private:\n    static constexpr size_t\
    \ INPUT_BUF = 1 << 17;\n    size_t pos = 0, end = 0;\n    bool is_eof = false;\n\
    \    static char buf[INPUT_BUF];\n    FILE *fp;\n\n  public:\n    Scanner() :\
    \ fp(stdin) {}\n\n    Scanner(const char *file) : fp(fopen(file, \"r\")) {}\n\n\
    \    ~Scanner() {\n        if (fp != stdin) fclose(fp);\n    }\n\n    char now()\
    \ {\n        if (is_eof) return '\\0';\n        if (pos == end) {\n          \
    \  end = fread(buf, 1, INPUT_BUF, fp);\n            if (end != INPUT_BUF) buf[end]\
    \ = '\\0';\n            if (end == 0) is_eof = true;\n            pos = 0;\n \
    \       }\n        return buf[pos];\n    }\n\n    void skip_space() {\n      \
    \  while (isspace(now())) ++pos;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> T next_unsigned_integral() {\n        skip_space();\n        T\
    \ res{};\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    template\
    \ <class T, is_signed_t<T> * = nullptr> T next_signed_integral() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
    \ to_unsigned<T>::type>());\n        } else return (T)next_unsigned_integral<typename\
    \ to_unsigned<T>::type>();\n    }\n\n    char next_char() {\n        skip_space();\n\
    \        auto res = now();\n        ++pos;\n        return res;\n    }\n\n   \
    \ std::string next_string() {\n        skip_space();\n        std::string res;\n\
    \        while (true) {\n            char c = now();\n            if (isspace(c)\
    \ or c == '\\0') break;\n            res.push_back(now());\n            ++pos;\n\
    \        }\n        return res;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> Scanner &operator>>(T &x) {\n        x = next_unsigned_integral<T>();\n\
    \        return *this;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n        x = next_char();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(std::string &x) {\n \
    \       x = next_string();\n        return *this;\n    }\n};\n\nstruct endl_struct_t\
    \ {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n    static char\
    \ helper[10000][5];\n    static char leading_zero[10000][5];\n    constexpr static\
    \ size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos\
    \ = 0;\n    FILE *fp;\n\n    template <class T> static constexpr void div_mod(T\
    \ &a, T &b, T mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n \
    \   static void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0;\
    \ i < 10000; ++i) {\n            leading_zero[i][0] = i / 1000 + '0';\n      \
    \      leading_zero[i][1] = i / 100 % 10 + '0';\n            leading_zero[i][2]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][3] = i % 10 + '0';\n     \
    \       leading_zero[i][4] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n            if (i >= 100) helper[i][j++]\
    \ = i / 100 % 10 + '0';\n            if (i >= 10) helper[i][j++] = i / 10 % 10\
    \ + '0';\n            helper[i][j++] = i % 10 + '0';\n            helper[i][j]\
    \ = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout) { init();\
    \ }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init(); }\n\n\
    \    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n \
    \   }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos = 0;\n\
    \    }\n\n    void flush() {\n        write();\n        fflush(fp);\n    }\n\n\
    \    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n      \
    \  buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n        while\
    \ (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n        uint32_t\
    \ y;\n        if (x >= 100000000) { // 10^8\n            div_mod<uint32_t>(y,\
    \ x, 100000000);\n            put_cstr(helper[y]);\n            div_mod<uint32_t>(y,\
    \ x, 10000);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y, x,\
    \ 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
    \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n       \
    \ uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n            div_mod<uint64_t>(y,\
    \ x, 1000000000000ull);\n            put_u32(y);\n            div_mod<uint64_t>(y,\
    \ x, 100000000ull);\n            put_cstr(leading_zero[y]);\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000ull) { // 10^4\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_u32(y);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     constexpr static __uint128_t pow10_10 = 10000000000ull;\n        constexpr\
    \ static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n        __uint128_t y;\n\
    \        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y, x,\
    \ pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
    \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
    \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n    \
    \        put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x, __uint128_t(100000000ull));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
    \ __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n          \
    \  put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000)) { //\
    \ 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n        \
    \    put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n        }\
    \ else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t x) {\n    \
    \    if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n   \
    \     } else put_u128(x);\n    }\n\n    template <class T, is_unsigned_t<T> *\
    \ = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4)\
    \ put_u32(x);\n        else if constexpr (sizeof(T) <= 8) put_u64(x);\n      \
    \  else put_u128(x);\n        return *this;\n    }\n\n    template <class T, is_signed_t<T>\
    \ * = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <=\
    \ 4) put_i32(x);\n        else if constexpr (sizeof(T) <= 8) put_i64(x);\n   \
    \     else put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\
    \u30DD\u30A4\u30F3\u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\
    \n    Printer &operator<<(endl_struct_t) {\n        put_char('\\n');\n       \
    \ flush();\n        return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\n\
    char Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[10000][5];\nchar\
    \ Printer::leading_zero[10000][5];\n\n} // namespace fastio\n\n#if defined(INTERACTIVE)\
    \ || defined(USE_STDIO)\nauto &kin = std::cin;\nauto &kout = std::cout;\nauto\
    \ (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n#else\n\
    fastio::Scanner kin;\nfastio::Printer kout;\nfastio::endl_struct_t kendl;\n#endif\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\
    \n\n#line 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\
    \u30ED\u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace\
    \ impl {\n\nstruct read {\n    template <class IStream, class T> inline static\
    \ void all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream,\
    \ class T, class U>\n    inline static void all_read(IStream &is, std::pair<T,\
    \ U> &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n\
    \    }\n\n    template <class IStream, class T> inline static void all_read(IStream\
    \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\n\
    \    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
    \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n    }\n\
    };\n\nstruct write {\n    template <class OStream, class T> inline static void\
    \ all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n    template\
    \ <class OStream, class T, class U>\n    inline static void all_write(OStream\
    \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n        all_write(os,\
    \ ' ');\n        all_write(os, p.second);\n    }\n\n    template <class OStream,\
    \ class T>\n    inline static void all_write(OStream &os, const std::vector<T>\
    \ &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (i)\
    \ all_write(os, ' ');\n            all_write(os, v[i]);\n        }\n    }\n\n\
    \    template <class OStream, class T, size_t F>\n    inline static void all_write(OStream\
    \ &os, const std::array<T, F> &a) {\n        for (int i = 0; i < (int)F; ++i)\
    \ {\n            if (i) all_write(os, ' ');\n            all_write(os, a[i]);\n\
    \        }\n    }\n};\n\n} // namespace impl\n\ntemplate <class IStream, class\
    \ T, class U, kk2::is_istream_t<IStream> * = nullptr>\nIStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
    }\n\ntemplate <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>\n\
    IStream &operator>>(IStream &is, std::vector<T> &v) {\n    impl::read::all_read(is,\
    \ v);\n    return is;\n}\n\ntemplate <class IStream, class T, size_t F, kk2::is_istream_t<IStream>\
    \ * = nullptr>\nIStream &operator>>(IStream &is, std::array<T, F> &a) {\n    impl::read::all_read(is,\
    \ a);\n    return is;\n}\n\ntemplate <class OStream, class T, class U, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    impl::write::all_write(os, p);\n    return os;\n}\n\ntemplate <class OStream,\
    \ class T, kk2::is_ostream_t<OStream> * = nullptr>\nOStream &operator<<(OStream\
    \ &os, const std::vector<T> &v) {\n    impl::write::all_write(os, v);\n    return\
    \ os;\n}\n\ntemplate <class OStream, class T, size_t F, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n\
    \    impl::write::all_write(os, a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\
    \n\n\n\n#define rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define\
    \ rep2(i, a) for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a,\
    \ b) for (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for\
    \ (long long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long\
    \ i = (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
    \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32 \"\
    template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 5 \"verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, m;\n    kin >> n >> m;\n  \
    \  kk2::MatrixF2 a(n, m), b(1, n);\n    a.input(kin), b.input(kin);\n    if (const\
    \ auto res = a.solve(b.inplace_transpose())) {\n        kout << res->get_h() -\
    \ 1 << \"\\n\";\n        res->output(kout);\n    } else {\n        kout << -1\
    \ << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2\"\
    \n\n#include \"../../matrix/matrix_F2.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, m;\n    kin >> n >> m;\n  \
    \  kk2::MatrixF2 a(n, m), b(1, n);\n    a.input(kin), b.input(kin);\n    if (const\
    \ auto res = a.solve(b.inplace_transpose())) {\n        kout << res->get_h() -\
    \ 1 << \"\\n\";\n        res->output(kout);\n    } else {\n        kout << -1\
    \ << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - matrix/matrix_F2.hpp
  - data_structure/my_bitset.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - type_traits/io.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
- /verify/verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp.html
title: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
---
