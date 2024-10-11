---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/my_bitset.hpp
    title: data_structure/my_bitset.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/matrix_F2.hpp
    title: matrix/matrix_F2.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product_mod_2
    links:
    - https://judge.yosupo.jp/problem/matrix_product_mod_2
  bundledCode: "#line 1 \"verify/yosupo_linalg/matrix_product_f2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product_mod_2\"\n\n#line 1\
    \ \"matrix/matrix_F2.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <iostream>\n#include <optional>\n#include <string>\n#include <vector>\n\n#line\
    \ 1 \"data_structure/my_bitset.hpp\"\n\n\n\n#line 5 \"data_structure/my_bitset.hpp\"\
    \n#include <bitset>\n#line 8 \"data_structure/my_bitset.hpp\"\n#include <iterator>\n\
    #line 11 \"data_structure/my_bitset.hpp\"\n\n#line 1 \"bit/bitcount.hpp\"\n\n\n\
    \n#line 5 \"bit/bitcount.hpp\"\n\n#line 1 \"type_traits/type_traits.hpp\"\n\n\n\
    \n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128\
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
    \ kk2\n\n\n#line 12 \"matrix/matrix_F2.hpp\"\n\nnamespace kk2 {\n\nstruct MatrixF2\
    \ {\n    using mat = MatrixF2;\n    int _h, _w;\n    std::vector<DynamicBitSet>\
    \ _mat;\n\n    MatrixF2() : MatrixF2(0) {}\n\n    MatrixF2(int n) : MatrixF2(n,\
    \ n) {}\n\n    MatrixF2(int h, int w) {\n        if (h == 0) {\n            _h\
    \ = 0;\n            _w = w;\n        } else {\n            _h = h;\n         \
    \   _w = w;\n            _mat.resize(h, DynamicBitSet(w));\n        }\n    }\n\
    \n    MatrixF2(const std::vector<DynamicBitSet> &mat_)\n        : _h(mat_.size()),\n\
    \          _w(mat_[0].size()),\n          _mat(mat_) {}\n\n    int get_h() const\
    \ { return _h; }\n\n    int get_w() const { return _w; }\n\n    bool at(int i,\
    \ int j) {\n        assert(0 <= i && i < _h);\n        assert(0 <= j && j < _w);\n\
    \        return _mat[i][j].val();\n    }\n\n    class Proxy {\n        std::vector<DynamicBitSet>\
    \ &bs;\n        int i;\n\n      public:\n        Proxy(std::vector<DynamicBitSet>\
    \ &bs_, int i_) : bs(bs_), i(i_) {}\n\n        operator DynamicBitSet() const\
    \ { return bs[i]; }\n\n        template <class IStream>\n        friend IStream\
    \ &operator>>(IStream &is, Proxy p) {\n            std::string s;\n          \
    \  is >> s;\n            p = s;\n            return is;\n        }\n\n       \
    \ template <class OStream>\n        friend OStream &operator<<(OStream &os, Proxy\
    \ p) {\n            os << p.to_reversed_string();\n            return os;\n  \
    \      }\n\n        std::string to_string() const { return bs[i].to_string();\
    \ }\n\n        std::string to_reversed_string() const { return bs[i].to_reversed_string();\
    \ }\n\n        Proxy &operator=(const std::string &s) {\n            bs[i].set_reversed(s);\n\
    \            return *this;\n        }\n\n        Proxy &operator=(const DynamicBitSet\
    \ &x) {\n            bs[i] = x;\n            return *this;\n        }\n\n    \
    \    Proxy &operator=(const Proxy &x) {\n            bs[i] = x.bs[x.i];\n    \
    \        return *this;\n        }\n\n        DynamicBitSet::BitReference operator[](int\
    \ j) {\n            assert(0 <= j && j < (int)bs[i].size());\n            return\
    \ bs[i][j];\n        }\n\n        Proxy &operator&=(const DynamicBitSet &x) {\n\
    \            bs[i] &= x;\n            return *this;\n        }\n\n        Proxy\
    \ &operator&=(const Proxy &x) {\n            bs[i] &= x.bs[x.i];\n           \
    \ return *this;\n        }\n\n        Proxy &operator|=(const DynamicBitSet &x)\
    \ {\n            bs[i] |= x;\n            return *this;\n        }\n\n       \
    \ Proxy &operator|=(const Proxy &x) {\n            bs[i] |= x.bs[x.i];\n     \
    \       return *this;\n        }\n\n        Proxy &operator^=(const DynamicBitSet\
    \ &x) {\n            bs[i] ^= x;\n            return *this;\n        }\n\n   \
    \     Proxy &operator^=(const Proxy &x) {\n            bs[i] ^= x.bs[x.i];\n \
    \           return *this;\n        }\n\n        Proxy &flip() {\n            bs[i].flip();\n\
    \            return *this;\n        }\n\n        Proxy &operator~() {\n      \
    \      bs[i].flip();\n            return *this;\n        }\n    };\n\n    Proxy\
    \ operator[](int i) {\n        assert(0 <= i && i < _h);\n        return Proxy(_mat,\
    \ i);\n    }\n\n    void display() const {\n        for (int i = 0; i < _h; i++)\
    \ { std::cout << _mat[i].to_reversed_string() << \"\\n\"; }\n    }\n\n    template\
    \ <class IStream>\n    mat &input(IStream &is) {\n        for (int i = 0; i <\
    \ _h; i++) {\n            std::string s;\n            is >> s;\n            _mat[i].set_reversed(s);\n\
    \        }\n        return *this;\n    }\n\n    template <class OStream>\n   \
    \ void output(OStream &os) const {\n        for (int i = 0; i < _h; i++) {\n \
    \           os << _mat[i].to_reversed_string() << \"\\n\";\n        }\n    }\n\
    \n    void set(int i, int j, bool x) {\n        assert(0 <= i && i < _h);\n  \
    \      assert(0 <= j && j < _w);\n        _mat[i].set(j, x);\n    }\n\n    void\
    \ set(int i, const std::string &s) {\n        assert((int)s.size() == _w);\n \
    \       _mat[i].set(s);\n    }\n\n    void set_reversed(int i, const std::string\
    \ &s) {\n        assert((int)s.size() == _w);\n        _mat[i].set_reversed(s);\n\
    \    }\n\n    mat &operator+=(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) { _mat[i]\
    \ = _mat[i] ^ rhs._mat[i]; }\n        return *this;\n    }\n\n    mat &operator-=(const\
    \ mat &rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) { _mat[i] = _mat[i] ^ rhs._mat[i]; }\n \
    \       return *this;\n    }\n\n    mat &operator^=(const mat &rhs) {\n      \
    \  assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int i =\
    \ 0; i < _h; i++) { _mat[i] = _mat[i] ^ rhs._mat[i]; }\n        return *this;\n\
    \    }\n\n    mat &operator|=(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) { _mat[i]\
    \ = _mat[i] | rhs._mat[i]; }\n        return *this;\n    }\n\n    mat &operator&=(const\
    \ mat &rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) { _mat[i] = _mat[i] & rhs._mat[i]; }\n \
    \       return *this;\n    }\n\n    mat &operator*=(const mat &rhs) {\n      \
    \  assert(_w == rhs._h);\n        std::vector<DynamicBitSet> res(_h, DynamicBitSet(rhs._w));\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ {\n                if (_mat[i][j]) res[i] ^= rhs._mat[j];\n                //\
    \ cout << i << \" \" << j << \" \" << _mat[i][j] << \" check\" <<\n          \
    \      // endl; rep (i, 2) { cout << res[i] << endl; }\n            }\n      \
    \  }\n        _w = rhs._w;\n        _mat = res;\n        return *this;\n    }\n\
    \n    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) +=\
    \ rhs; }\n\n    friend mat operator-(const mat &lhs, const mat &rhs) { return\
    \ mat(lhs) -= rhs; }\n\n    friend mat operator^(const mat &lhs, const mat &rhs)\
    \ { return mat(lhs) ^= rhs; }\n\n    friend mat operator|(const mat &lhs, const\
    \ mat &rhs) { return mat(lhs) |= rhs; }\n\n    friend mat operator&(const mat\
    \ &lhs, const mat &rhs) { return mat(lhs) &= rhs; }\n\n    friend mat operator*(const\
    \ mat &lhs, const mat &rhs) { return mat(lhs) *= rhs; }\n\n    friend bool operator==(const\
    \ mat &lhs, const mat &rhs) {\n        assert(lhs._h == rhs._h);\n        assert(lhs._w\
    \ == rhs._w);\n        for (int i = 0; i < lhs._h; i++) {\n            if (lhs._mat[i]\
    \ != rhs._mat[i]) return false;\n        }\n        return true;\n    }\n\n  \
    \  friend bool operator!=(const mat &lhs, const mat &rhs) { return !(lhs == rhs);\
    \ }\n\n    mat &inplace_combine_top(const mat &rhs) {\n        assert(_w == rhs._w);\n\
    \        _mat.insert(std::begin(_mat), std::begin(rhs._mat), std::end(rhs._mat));\n\
    \        _h += rhs._h;\n        return *this;\n    }\n\n    mat combine_top(const\
    \ mat &rhs) const {\n        assert(_w == rhs._w);\n        return mat(_mat).inplace_combine_top(rhs);\n\
    \    }\n\n    mat &inplace_combine_bottom(const mat &rhs) {\n        assert(_w\
    \ == rhs._w);\n        _mat.insert(std::end(_mat), std::begin(rhs._mat), std::end(rhs._mat));\n\
    \        _h += rhs._h;\n        return *this;\n    }\n\n    mat combine_bottom(const\
    \ mat &rhs) const {\n        assert(_w == rhs._w);\n        return mat(_mat).inplace_combine_bottom(rhs);\n\
    \    }\n\n    mat &inplace_combine_right(const mat &rhs) {\n        assert(_h\
    \ == rhs._h);\n        for (int i = 0; i < _h; i++) _mat[i].inplace_combine_top(rhs._mat[i]);\n\
    \        _w += rhs._w;\n        return *this;\n    }\n\n    mat combine_right(const\
    \ mat &rhs) const {\n        assert(_h == rhs._h);\n        return mat(_mat).inplace_combine_right(rhs);\n\
    \    }\n\n    mat &inplace_combine_left(const mat &rhs) {\n        assert(_h ==\
    \ rhs._h);\n        for (int i = 0; i < _h; i++) _mat[i].inplace_combine_bottom(rhs._mat[i]);\n\
    \        _w += rhs._w;\n        return *this;\n    }\n\n    mat combine_left(const\
    \ mat &rhs) const {\n        assert(_h == rhs._h);\n        return mat(_mat).inplace_combine_left(rhs);\n\
    \    }\n\n    // [0, wr)\n    int sweep(int wr = -1) {\n        if (wr == -1)\
    \ wr = _w;\n        int r = 0;\n        for (int i = 0; i < wr; i++) {\n     \
    \       int pivot = -1;\n            for (int j = r; j < _h; j++) {\n        \
    \        if (_mat[j][i]) {\n                    pivot = j;\n                 \
    \   break;\n                }\n            }\n            if (pivot == -1) continue;\n\
    \            if (r != pivot) std::swap(_mat[r], _mat[pivot]);\n            for\
    \ (int j = 0; j < _h; j++) {\n                if (j == r) continue;\n        \
    \        if (_mat[j][i]) _mat[j] ^= _mat[r];\n            }\n            r++;\n\
    \        }\n        return r;\n    }\n\n    mat &shrink() {\n        while (_h\
    \ && !(bool)_mat[_h - 1]) _mat.pop_back(), --_h;\n        return *this;\n    }\n\
    \n    // it must be already swept and shrunk before calling this function\n  \
    \  mat get_solution_base() const {\n        mat res(_w - _h, _w);\n        std::vector<int>\
    \ step(_h);\n        std::vector<bool> is_step(_w, false);\n        int nowj =\
    \ 0;\n        for (int i = 0; i < _h; i++) {\n            while (!_mat[i].is_pinned(nowj))\
    \ nowj++;\n            is_step[nowj] = true;\n            step[i] = nowj;\n  \
    \      }\n        int now = 0;\n        nowj = 0;\n        while (nowj < _w) {\n\
    \            if (is_step[nowj]) {\n                nowj++;\n                continue;\n\
    \            }\n            res[now][nowj] = 1;\n            for (int i = 0; i\
    \ < _h; i++)\n                if (_mat[i].is_pinned(nowj)) res[now][step[i]] =\
    \ 1;\n            nowj++, now++;\n        }\n        return res;\n    }\n\n  \
    \  std::optional<mat> solve(const mat &b) const {\n        assert(_h == b._h);\n\
    \        assert(b._w == 1);\n        mat ab = combine_right(b);\n        ab.sweep();\n\
    \        ab.shrink();\n\n        // ab.display();\n\n        for (int i = 0; i\
    \ < ab._h; i++) {\n            for (int j = 0; j < ab._w; j++) {\n           \
    \     if (ab[i][j]) {\n                    if (j == ab._w - 1) return {};\n  \
    \                  break;\n                }\n            }\n        }\n\n   \
    \     mat res(1 + _w - ab._h, _w);\n        for (int i = 0; i < ab._h; ++i) {\n\
    \            for (int j = 0; j < ab._w; ++j) {\n                if (ab[i][j])\
    \ {\n                    res[0][j] = ab[i][ab._w - 1];\n                    break;\n\
    \                }\n            }\n        }\n\n        std::vector<int> step(ab._h);\n\
    \        std::vector<bool> is_step(ab._w - 1, false);\n        int nowj = 0;\n\
    \        for (int i = 0; i < ab._h; i++) {\n            while (!ab[i][nowj]) nowj++;\n\
    \            is_step[nowj] = true;\n            step[i] = nowj;\n        }\n \
    \       int now = 1;\n        nowj = 0;\n        while (nowj < ab._w - 1) {\n\
    \            if (is_step[nowj]) {\n                nowj++;\n                continue;\n\
    \            }\n            res[now][nowj] = 1;\n            for (int i = 0; i\
    \ < ab._h; i++)\n                if (ab[i][nowj]) res[now][step[i]] = 1;\n   \
    \         nowj++, now++;\n        }\n        return res;\n    }\n\n    int rank()\
    \ const { return mat(*this).sweep(); }\n\n    bool det() const { return rank()\
    \ == _h; }\n\n    std::optional<mat> inv() const {\n        assert(_h == _w);\n\
    \        std::vector<DynamicBitSet> res(_h, _w);\n        for (int i = 0; i <\
    \ _h; i++) { res[i][i] = 1; }\n        std::vector<DynamicBitSet> buf(_mat);\n\
    \        for (int i = 0; i < _w; i++) {\n            int pivot = -1;\n       \
    \     for (int j = i; j < _h; j++) {\n                if (buf[j][i]) {\n     \
    \               pivot = j;\n                    break;\n                }\n  \
    \          }\n            if (pivot == -1) return {};\n            std::swap(buf[i],\
    \ buf[pivot]);\n            std::swap(res[i], res[pivot]);\n            for (int\
    \ j = 0; j < _h; j++) {\n                if (j == i) continue;\n             \
    \   if (buf[j][i]) {\n                    buf[j] ^= buf[i];\n                \
    \    res[j] ^= res[i];\n                }\n            }\n        }\n        return\
    \ mat(res);\n    }\n\n    mat transpose() {\n        mat res(_w, _h);\n      \
    \  for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) {\
    \ res[j][i] = _mat[i][j]; }\n        }\n        return res;\n    }\n\n    mat\
    \ &inplace_transpose() {\n        return *this = transpose();\n    }\n};\n\n}\
    \ // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"\
    O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n#line 8 \"template/template.hpp\"\
    \n#include <array>\n#line 11 \"template/template.hpp\"\n#include <chrono>\n#include\
    \ <cmath>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#line 20 \"template/template.hpp\"\n#include\
    \ <limits>\n#include <map>\n#include <numeric>\n#line 24 \"template/template.hpp\"\
    \n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include\
    \ <stack>\n#line 30 \"template/template.hpp\"\n#include <tuple>\n#line 32 \"template/template.hpp\"\
    \n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line\
    \ 36 \"template/template.hpp\"\n\nusing u32 = unsigned int;\nusing i64 = long\
    \ long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing u128\
    \ = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
    \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\n\
    template <class T> using vc = std::vector<T>;\ntemplate <class T> using vvc =\
    \ std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
    template <class T> using vvvvc = std::vector<vvvc<T>>;\n\ntemplate <class T> using\
    \ pq = std::priority_queue<T>;\ntemplate <class T> using pqi = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate <class T> constexpr T infty =\
    \ 0;\ntemplate <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr\
    \ i64 infty<i64> = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128>\
    \ = (i128(1) << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32>\
    \ = infty<int>;\ntemplate <> constexpr u64 infty<u64> = infty<i64>;\ntemplate\
    \ <> constexpr u128 infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double>\
    \ = infty<i64>;\ntemplate <> constexpr long double infty<long double> = infty<i64>;\n\
    \nconstexpr int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long\
    \ double PI = 3.14159265358979323846;\n\nnamespace kk2 {\n\ntemplate <class T,\
    \ class... Sizes> auto make_vector(int first, Sizes... sizes) {\n    if constexpr\
    \ (sizeof...(sizes) == 0) {\n        return std::vector<T>(first);\n    } else\
    \ {\n        return std::vector<decltype(make_vector(sizes...))>(first, make_vector(sizes...));\n\
    \    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T> &v, const\
    \ U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate <class\
    \ T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x) {\n  \
    \  for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace kk2\n\ntemplate <class\
    \ T, class S> inline bool chmax(T &a, const S &b) {\n    return (a < b ? a = b,\
    \ 1 : 0);\n}\n\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid Yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid No(bool b = 1) {\n    std::cout\
    \ << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid YES(bool b = 1) {\n    std::cout\
    \ << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1) {\n    std::cout\
    \ << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n    std::cout\
    \ << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#define rep1(a) for (i64 _ = 0; _ < (i64)(a);\
    \ ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n#define rep3(i,\
    \ a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a) for (i64 i =\
    \ (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a) - 1; i >= (i64)(b);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__, repi3,\
    \ repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define all(p)\
    \ std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n    }\n} iosetup;\n\ntemplate <class\
    \ OStream, class T, class U>\nOStream &operator<<(OStream &os, const std::pair<T,\
    \ U> &p) {\n    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T, class U> IStream &operator>>(IStream &is, std::pair<T,\
    \ U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class\
    \ OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &v)\
    \ {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\n\n#line 5 \"verify/yosupo_linalg/matrix_product_f2.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, m, k;\n    cin >> n >> m >>\
    \ k;\n    kk2::MatrixF2 a(n, m), b(m, k);\n    a.input(cin), b.input(cin);\n \
    \   (a * b).output(cout);\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product_mod_2\"\n\
    \n#include \"../../matrix/matrix_F2.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, m, k;\n    cin >> n >> m >>\
    \ k;\n    kk2::MatrixF2 a(n, m), b(m, k);\n    a.input(cin), b.input(cin);\n \
    \   (a * b).output(cout);\n\n    return 0;\n}\n"
  dependsOn:
  - matrix/matrix_F2.hpp
  - data_structure/my_bitset.hpp
  - bit/bitcount.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_linalg/matrix_product_f2.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 14:10:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_linalg/matrix_product_f2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_linalg/matrix_product_f2.test.cpp
- /verify/verify/yosupo_linalg/matrix_product_f2.test.cpp.html
title: verify/yosupo_linalg/matrix_product_f2.test.cpp
---
