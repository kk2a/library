---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: matrix/matrix_F2.hpp
    title: matrix/matrix_F2.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_det_f2.test.cpp
    title: verify/yosupo_linalg/matrix_det_f2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_inv_f2.test.cpp
    title: verify/yosupo_linalg/matrix_inv_f2.test.cpp
  - icon: ':x:'
    path: verify/yosupo_linalg/matrix_product_f2.test.cpp
    title: verify/yosupo_linalg/matrix_product_f2.test.cpp
  - icon: ':x:'
    path: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
    title: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/my_bitset.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <bitset>\n#include <cassert>\n#include <iostream>\n#include <iterator>\n\
    #include <string>\n#include <vector>\n\n#line 1 \"bit/bitcount.hpp\"\n\n\n\n#line\
    \ 5 \"bit/bitcount.hpp\"\n\n#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n#include\
    \ <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128\
    \ = typename std::conditional<std::is_same<T, __int128_t>::value\n           \
    \                                            or std::is_same<T, __int128>::value,\n\
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
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n#line 7 \"bit/bitcount.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T> int ctz(T x) {\n    static_assert(is_integral_extended<T>::value);\n\
    \    assert(x != T(0));\n\n    if constexpr (sizeof(T) <= 4) {\n        return\
    \ __builtin_ctz(x);\n    } else if constexpr (sizeof(T) <= 8) {\n        return\
    \ __builtin_ctzll(x);\n    } else {\n        if (x & 0xffffffffffffffff)\n   \
    \         return __builtin_ctzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \        return 64 + __builtin_ctzll((unsigned long long)(x >> 64));\n    }\n\
    }\n\ntemplate <typename T> int clz(T x) {\n    static_assert(is_integral_extended<T>::value);\n\
    \    assert(x != T(0));\n\n    if constexpr (sizeof(T) <= 4) {\n        return\
    \ __builtin_clz(x);\n    } else if constexpr (sizeof(T) <= 8) {\n        return\
    \ __builtin_clzll(x);\n    } else {\n        if (x >> 64) return __builtin_clzll((unsigned\
    \ long long)(x >> 64));\n        return 64 + __builtin_clzll((unsigned long long)(x\
    \ & 0xffffffffffffffff));\n    }\n}\n\ntemplate <typename T> int popcount(T x)\
    \ {\n    static_assert(is_integral_extended<T>::value);\n\n    if constexpr (sizeof(T)\
    \ <= 4) {\n        return __builtin_popcount(x);\n    } else if constexpr (sizeof(T)\
    \ <= 8) {\n        return __builtin_popcountll(x);\n    } else {\n        return\
    \ __builtin_popcountll((unsigned long long)(x >> 64))\n               + __builtin_popcountll((unsigned\
    \ long long)(x & 0xffffffffffffffff));\n    }\n}\n\n}; // namespace kk2\n\n\n\
    #line 13 \"data_structure/my_bitset.hpp\"\n\nnamespace kk2 {\n\nstruct DynamicBitSet\
    \ {\n    using T = DynamicBitSet;\n    using UInt = __uint128_t;\n    constexpr\
    \ static int BLOCK_SIZE = sizeof(UInt) * 8;\n    constexpr static int BLOCK_SIZE_LOG\
    \ = __builtin_ctz(BLOCK_SIZE);\n    constexpr static int BLOCK_MASK = BLOCK_SIZE\
    \ - 1;\n    constexpr static UInt ONE = 1;\n    int n;\n    std::vector<UInt>\
    \ block;\n\n    DynamicBitSet(int n_ = 0, bool x = 0) : n(n_) {\n        UInt\
    \ val = x ? -1 : 0;\n        block.assign((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG,\
    \ val);\n        if (n & BLOCK_MASK) block.back() >>= BLOCK_SIZE - (n & BLOCK_MASK);\n\
    \        // fit the last block\n    }\n\n    // Note that the string needs to\
    \ be reversed.\n    // For example, if the input is \"1010\",\n    // the character\
    \ at index 0 in the string is '1',\n    // but in the bitset it will be considered\
    \ as index 0.\n    DynamicBitSet(const std::string &s) : n(s.size()) {\n     \
    \   block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        set(s);\n \
    \   }\n\n    template <class IStream> friend IStream &operator>>(IStream &is,\
    \ T &bs) {\n        std::string s;\n        is >> s;\n        bs.set_reversed(s);\n\
    \        return is;\n    }\n\n    int size() const { return n; }\n\n    T &inplace_combine_top(const\
    \ T &rhs) {\n        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        if (!(n & BLOCK_MASK)) {\n            std::copy(std::begin(rhs.block),\n\
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
    \        if (!(rhs.n & BLOCK_MASK)) {\n            std::copy(\n              \
    \  std::begin(block), std::end(block), std::begin(block) + (rhs.n >> BLOCK_SIZE_LOG));\n\
    \            std::copy(std::begin(rhs.block), std::end(rhs.block), std::begin(block));\n\
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
    \ = (block[i] << 1) | (s[j] - '0');\n        }\n    }\n\n    class BitReference\
    \ {\n        std::vector<UInt> &block;\n        int idx;\n\n      public:\n  \
    \      BitReference(std::vector<UInt> &block_, int idx_) : block(block_), idx(idx_)\
    \ {}\n\n        operator bool() const { return (block[idx >> BLOCK_SIZE_LOG] >>\
    \ (idx & BLOCK_MASK)) & 1; }\n\n        friend std::istream &operator>>(std::istream\
    \ &is, BitReference a) {\n            bool c;\n            is >> c;\n        \
    \    a = c;\n            return is;\n        }\n\n        BitReference &operator=(bool\
    \ x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n\
    \            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n\
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
    \    }\n\n    template <class OStream> friend OStream &operator<<(OStream &os,\
    \ const T &bs) {\n        return os << bs.to_string();\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef DATA_STRUCTURE_MY_BITSET_HPP\n#define DATA_STRUCTURE_MY_BITSET_HPP\
    \ 1\n\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n#include <iostream>\n\
    #include <iterator>\n#include <string>\n#include <vector>\n\n#include \"../bit/bitcount.hpp\"\
    \n\nnamespace kk2 {\n\nstruct DynamicBitSet {\n    using T = DynamicBitSet;\n\
    \    using UInt = __uint128_t;\n    constexpr static int BLOCK_SIZE = sizeof(UInt)\
    \ * 8;\n    constexpr static int BLOCK_SIZE_LOG = __builtin_ctz(BLOCK_SIZE);\n\
    \    constexpr static int BLOCK_MASK = BLOCK_SIZE - 1;\n    constexpr static UInt\
    \ ONE = 1;\n    int n;\n    std::vector<UInt> block;\n\n    DynamicBitSet(int\
    \ n_ = 0, bool x = 0) : n(n_) {\n        UInt val = x ? -1 : 0;\n        block.assign((n\
    \ + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG, val);\n        if (n & BLOCK_MASK) block.back()\
    \ >>= BLOCK_SIZE - (n & BLOCK_MASK);\n        // fit the last block\n    }\n\n\
    \    // Note that the string needs to be reversed.\n    // For example, if the\
    \ input is \"1010\",\n    // the character at index 0 in the string is '1',\n\
    \    // but in the bitset it will be considered as index 0.\n    DynamicBitSet(const\
    \ std::string &s) : n(s.size()) {\n        block.resize((n + BLOCK_SIZE - 1) >>\
    \ BLOCK_SIZE_LOG);\n        set(s);\n    }\n\n    template <class IStream> friend\
    \ IStream &operator>>(IStream &is, T &bs) {\n        std::string s;\n        is\
    \ >> s;\n        bs.set_reversed(s);\n        return is;\n    }\n\n    int size()\
    \ const { return n; }\n\n    T &inplace_combine_top(const T &rhs) {\n        block.resize((n\
    \ + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        if (!(n & BLOCK_MASK))\
    \ {\n            std::copy(std::begin(rhs.block),\n                      std::end(rhs.block),\n\
    \                      std::begin(block) + (n >> BLOCK_SIZE_LOG));\n         \
    \   n += rhs.n;\n            return *this;\n        }\n        int start = BLOCK_SIZE\
    \ - (n & BLOCK_MASK);\n        UInt start_mask = (ONE << start) - 1;\n       \
    \ UInt end_mask = ~start_mask;\n        for (int i = 0; i < (rhs.n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG; i++) {\n            UInt x = rhs.block[i];\n       \
    \     block[i + (n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE - start);\n\
    \            if (i + (n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n + BLOCK_SIZE - 1)\
    \ >> BLOCK_SIZE_LOG)\n                block[i + (n >> BLOCK_SIZE_LOG) + 1] |=\
    \ (x & end_mask) >> start;\n        }\n        n += rhs.n;\n        return *this;\n\
    \    }\n\n    T combine_top(const T &rhs) const { return T(*this).inplace_combine_top(rhs);\
    \ }\n\n    T &inplace_combine_bottom(const T &rhs) {\n        block.resize((n\
    \ + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        if (!(rhs.n & BLOCK_MASK))\
    \ {\n            std::copy(\n                std::begin(block), std::end(block),\
    \ std::begin(block) + (rhs.n >> BLOCK_SIZE_LOG));\n            std::copy(std::begin(rhs.block),\
    \ std::end(rhs.block), std::begin(block));\n            n += rhs.n;\n        \
    \    return *this;\n        }\n        int start = BLOCK_SIZE - (rhs.n & BLOCK_MASK);\n\
    \        UInt start_mask = (ONE << start) - 1;\n        UInt end_mask = ~start_mask;\n\
    \        for (int i = ((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG) - 1; i >= 0; --i)\
    \ {\n            UInt x = block[i];\n            block[i + (rhs.n >> BLOCK_SIZE_LOG)]\
    \ |= (x & start_mask) << (BLOCK_SIZE - start);\n            if (i + (rhs.n >>\
    \ BLOCK_SIZE_LOG) + 1 < (n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)\n    \
    \            block[i + (rhs.n >> BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;\n\
    \        }\n        block[(rhs.n >> BLOCK_SIZE_LOG)] =\n            ((block[0]\
    \ & start_mask) << (BLOCK_SIZE - start)) | rhs.block.back();\n        std::copy(std::begin(rhs.block),\
    \ std::prev(std::end(rhs.block)), std::begin(block));\n        n += rhs.n;\n \
    \       return *this;\n    }\n\n    T combine_bottom(const T &rhs) const { return\
    \ T(*this).inplace_combine_bottom(rhs); }\n\n    void set(int i, int x) {\n  \
    \      assert(0 <= i && i < n);\n        if (x) block[i >> BLOCK_SIZE_LOG] |=\
    \ ONE << (i & BLOCK_MASK);\n        else block[i >> BLOCK_SIZE_LOG] &= ~(ONE <<\
    \ (i & BLOCK_MASK));\n    }\n\n    void set(const std::string &s) {\n        assert((int)s.size()\
    \ == n);\n        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i++) {\n            int r = n - (i << BLOCK_SIZE_LOG), l = std::max(0, r - BLOCK_SIZE);\n\
    \            block[i] = 0;\n            for (int j = l; j < r; j++) block[i] =\
    \ (block[i] << 1) | (s[j] - '0');\n        }\n    }\n\n    void set_reversed(const\
    \ std::string &s) {\n        assert((int)s.size() == n);\n        for (int i =\
    \ 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            int l = i\
    \ << BLOCK_SIZE_LOG, r = std::min(n, l + BLOCK_SIZE);\n            block[i] =\
    \ 0;\n            for (int j = r - 1; j >= l; --j) block[i] = (block[i] << 1)\
    \ | (s[j] - '0');\n        }\n    }\n\n    class BitReference {\n        std::vector<UInt>\
    \ &block;\n        int idx;\n\n      public:\n        BitReference(std::vector<UInt>\
    \ &block_, int idx_) : block(block_), idx(idx_) {}\n\n        operator bool()\
    \ const { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }\n\
    \n        friend std::istream &operator>>(std::istream &is, BitReference a) {\n\
    \            bool c;\n            is >> c;\n            a = c;\n            return\
    \ is;\n        }\n\n        BitReference &operator=(bool x) {\n            if\
    \ (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n           \
    \ else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n       \
    \     return *this;\n        }\n\n        BitReference &operator=(const BitReference\
    \ &other) {\n            if (other) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx\
    \ & BLOCK_MASK);\n            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx\
    \ & BLOCK_MASK));\n            return *this;\n        }\n\n        BitReference\
    \ &operator&=(bool x) {\n            if (!x) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE\
    \ << (idx & BLOCK_MASK));\n            return *this;\n        }\n\n        BitReference\
    \ &operator&=(const BitReference &other) {\n            if (!other) block[idx\
    \ >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n            return *this;\n\
    \        }\n\n        BitReference &operator|=(bool x) {\n            if (x) block[idx\
    \ >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n            return *this;\n\
    \        }\n\n        BitReference &operator|=(const BitReference &other) {\n\
    \            if (other) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n\
    \            return *this;\n        }\n\n        BitReference &operator^=(bool\
    \ x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n\
    \            return *this;\n        }\n\n        BitReference &operator^=(const\
    \ BitReference &other) {\n            if (other) block[idx >> BLOCK_SIZE_LOG]\
    \ ^= ONE << (idx & BLOCK_MASK);\n            return *this;\n        }\n\n    \
    \    BitReference &flip() {\n            block[idx >> BLOCK_SIZE_LOG] ^= ONE <<\
    \ (idx & BLOCK_MASK);\n            return *this;\n        }\n\n        BitReference\
    \ &operator~() {\n            block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n\
    \            return *this;\n        }\n\n        bool val() const { return (block[idx\
    \ >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }\n    };\n\n    BitReference\
    \ operator[](int i) {\n        assert(0 <= i && i < n);\n        return BitReference(block,\
    \ i);\n    }\n\n    bool is_pinned(int i) const {\n        assert(0 <= i && i\
    \ < n);\n        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) & 1;\n\
    \    }\n\n    T &operator=(const std::string &s) {\n        set(s);\n        return\
    \ *this;\n    }\n\n    T &flip() {\n        UInt mask = (ONE << (n & BLOCK_MASK))\
    \ - 1;\n        for (UInt &x : block) x = ~x;\n        block.back() &= mask;\n\
    \        return *this;\n    }\n\n    T &flip(int i) {\n        assert(0 <= i &&\
    \ i < n);\n        block[i >> BLOCK_SIZE_LOG] ^= ONE << (i & BLOCK_MASK);\n  \
    \      return *this;\n    }\n\n    int ctz() const {\n        int res = 0;\n \
    \       int i = 0;\n        for (; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ ++i) {\n            if (block[i]) break;\n            res += BLOCK_SIZE;\n \
    \       }\n        assert(i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n     \
    \   res += kk2::ctz(block[i]);\n        return res;\n    }\n\n    int clz() const\
    \ {\n        int res = 0;\n        int i = ((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        for (; i--;) {\n            if (block[i]) break;\n            if (i +\
    \ 1 == (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG) {\n                res += n & BLOCK_MASK;\n\
    \            } else {\n                res += BLOCK_SIZE;\n            }\n   \
    \     }\n        assert(i >= 0);\n        if (i + 1 == (n + BLOCK_SIZE - 1) >>\
    \ BLOCK_SIZE_LOG) {\n            res += kk2::clz(block[i]) - (BLOCK_SIZE - (n\
    \ & BLOCK_MASK));\n        } else {\n            res += kk2::clz(block[i]);\n\
    \        }\n        return res;\n    }\n\n    int popcount() const {\n       \
    \ int res = 0;\n        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i++) {\n            res += kk2::popcount(block[i]);\n        }\n        return\
    \ res;\n    }\n\n    T &operator~() { return flip(); }\n\n    T &operator&=(const\
    \ T &other) {\n        assert(n == other.n);\n        for (int i = 0; i < (n +\
    \ BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            block[i] &= other.block[i];\n\
    \        }\n        return *this;\n    }\n\n    T &operator|=(const T &other)\
    \ {\n        assert(n == other.n);\n        for (int i = 0; i < (n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG; i++) {\n            block[i] |= other.block[i];\n  \
    \      }\n        return *this;\n    }\n\n    T &operator^=(const T &other) {\n\
    \        assert(n == other.n);\n        for (int i = 0; i < (n + BLOCK_SIZE -\
    \ 1) >> BLOCK_SIZE_LOG; i++) {\n            block[i] ^= other.block[i];\n    \
    \    }\n        return *this;\n    }\n\n    friend T operator&(const T &lhs, const\
    \ T &rhs) { return T(lhs) &= rhs; }\n\n    friend T operator|(const T &lhs, const\
    \ T &rhs) { return T(lhs) |= rhs; }\n\n    friend T operator^(const T &lhs, const\
    \ T &rhs) { return T(lhs) ^= rhs; }\n\n    friend bool operator==(const T &lhs,\
    \ const T &rhs) {\n        if (lhs.n != rhs.n) return false;\n        for (int\
    \ i = 0; i < (lhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            if\
    \ (lhs.block[i] != rhs.block[i]) return false;\n        }\n        return true;\n\
    \    }\n\n    friend bool operator!=(const T &lhs, const T &rhs) { return !(lhs\
    \ == rhs); }\n\n    operator bool() const {\n        for (int i = 0; i < (n +\
    \ BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            if (block[i]) return\
    \ true;\n        }\n        return false;\n    }\n\n    std::string to_string(UInt\
    \ x) const {\n        return std::bitset<64>((unsigned long long)(x >> (BLOCK_SIZE\
    \ / 2))).to_string()\n               + std::bitset<64>((unsigned long long)(x\
    \ & ((ONE << (BLOCK_SIZE / 2)) - 1)))\n                     .to_string();\n  \
    \  }\n\n    std::string to_string() const {\n        std::vector<std::string>\
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
    \    }\n\n    template <class OStream> friend OStream &operator<<(OStream &os,\
    \ const T &bs) {\n        return os << bs.to_string();\n    }\n};\n\n} // namespace\
    \ kk2\n\n#endif // DATA_STRUCTURE_MY_BITSET_HPP\n"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: data_structure/my_bitset.hpp
  requiredBy:
  - matrix/matrix_F2.hpp
  timestamp: '2024-10-09 14:51:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_linalg/matrix_det_f2.test.cpp
  - verify/yosupo_linalg/matrix_product_f2.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  - verify/yosupo_linalg/matrix_inv_f2.test.cpp
documentation_of: data_structure/my_bitset.hpp
layout: document
redirect_from:
- /library/data_structure/my_bitset.hpp
- /library/data_structure/my_bitset.hpp.html
title: data_structure/my_bitset.hpp
---
