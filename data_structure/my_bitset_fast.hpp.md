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
  bundledCode: "#line 1 \"data_structure/my_bitset_fast.hpp\"\n\n\n\n\nstruct DynamicBitSetFast\
    \ {\n    using T = DynamicBitSetFast;\n    using u128 = __uint128_t;\n    constexpr\
    \ static int BLOCK_SIZE_LOG = 7;\n    constexpr static int BLOCK_SIZE = 1 << BLOCK_SIZE_LOG;\n\
    \    constexpr static int BLOCK_MASK = BLOCK_SIZE - 1;\n    constexpr static u128\
    \ ONE = 1;\n    int n;\n    vector<u128> block;\n\n    DynamicBitSetFast(int n_\
    \ = 0, bool x = 0) : n(n_) {\n        u128 val = x ? -1 : 0;\n        block.assign((n\
    \ + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG, val);\n        if (n & BLOCK_MASK) block.back()\
    \ >>= BLOCK_SIZE - (n & BLOCK_MASK);\n        // fit the last block\n    }\n\n\
    \    // Note that the string needs to be reversed.\n    // For example, if the\
    \ input is \"1010\",\n    // the character at index 0 in the string is '1',\n\
    \    // but in the bitset it will be considered as index 0.\n    DynamicBitSetFast(const\
    \ string& s) : n(s.size()) {\n        block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        set(s);\n    }\n\n    int size() const { return n; }\n\n    T& inplace_combine_bottom(const\
    \ T& rhs) {\n        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        if (!(n & BLOCK_MASK)) {\n            copy(begin(rhs.block), end(rhs.block),\
    \ begin(block) + (n >> BLOCK_SIZE_LOG));\n            n += rhs.n;\n          \
    \  return *this;\n        }\n        int start = BLOCK_SIZE - (n & BLOCK_MASK);\n\
    \        u128 start_mask = (ONE << start) - 1;\n        u128 end_mask = ~start_mask;\n\
    \        for (int i = 0; i < (rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++)\
    \ {\n            u128 x = rhs.block[i];\n            block[i + (n >> BLOCK_SIZE_LOG)]\
    \ |= (x & start_mask) << (BLOCK_SIZE - start);\n            if (i + (n >> BLOCK_SIZE_LOG)\
    \ + 1 < (n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)\n                block[i\
    \ + (n >> BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;\n        }\n      \
    \  n += rhs.n;\n        return *this;\n    }\n\n    T combine_bottom(const T&\
    \ rhs) const {\n        return T(*this).inplace_combine_bottom(rhs);\n    }\n\n\
    \    T& inplace_combine_top(const T& rhs) {\n        block.resize((n + rhs.n +\
    \ BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        if (!(rhs.n & BLOCK_MASK)) {\n\
    \            copy(begin(block), end(block), begin(block) + (rhs.n >> BLOCK_SIZE_LOG));\n\
    \            copy(begin(rhs.block), end(rhs.block), begin(block));\n         \
    \   n += rhs.n;\n            return *this;\n        }\n        int start = BLOCK_SIZE\
    \ - (rhs.n & BLOCK_MASK);\n        u128 start_mask = (ONE << start) - 1;\n   \
    \     u128 end_mask = ~start_mask;\n        for (int i = ((n + BLOCK_SIZE - 1)\
    \ >> BLOCK_SIZE_LOG) - 1; i >= 0; --i) {\n            u128 x = block[i];\n   \
    \         block[i + (rhs.n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE\
    \ - start);\n            if (i + (rhs.n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n +\
    \ BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)\n                block[i + (rhs.n >> BLOCK_SIZE_LOG)\
    \ + 1] |= (x & end_mask) >> start;\n        }\n        block[(rhs.n >> BLOCK_SIZE_LOG)]\
    \ = ((block[0] & start_mask) << (BLOCK_SIZE - start)) | rhs.block.back();\n  \
    \      copy(begin(rhs.block), end(rhs.block), begin(block));\n        n += rhs.n;\n\
    \        return *this;\n    }\n\n    T combine_top(const T& rhs) const {\n   \
    \     return T(*this).inplace_combine_top(rhs);\n    }\n\n    void set(int i,\
    \ int x) {\n        assert(0 <= i && i < n);\n        if (x) block[i >> BLOCK_SIZE_LOG]\
    \ |= ONE << (i & BLOCK_MASK);\n        else block[i >> BLOCK_SIZE_LOG] &= ~(ONE\
    \ << (i & BLOCK_MASK));\n    }\n\n    void set(const string& s) {\n        assert((int)s.size()\
    \ == n);\n        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i++) {\n            int r = n - (i << BLOCK_SIZE_LOG), l = max(0, r - BLOCK_SIZE);\n\
    \            u128 val = 0;\n            for (int j = l; j < r; ++j) {\n      \
    \          val = (val << 1) | (s[j] - '0');\n            }\n            block[i]\
    \ = val;\n        }\n    }\n\n    class BitReference {\n        vector<u128>&\
    \ block;\n        int idx;\n      public:\n        BitReference(vector<u128>&\
    \ block_, int idx_) : block(block_), idx(idx_) {}\n        operator bool() const\
    \ { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }\n\n   \
    \     BitReference& operator=(bool x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG]\
    \ |= ONE << (idx & BLOCK_MASK);\n            else block[idx >> BLOCK_SIZE_LOG]\
    \ &= ~(ONE << (idx & BLOCK_MASK));\n            return *this;\n        }\n\n \
    \       BitReference& operator=(const BitReference& other) {\n            if (other)\
    \ block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n            else\
    \ block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n            return\
    \ *this;\n        }\n\n        BitReference& operator&=(bool x) {\n          \
    \  if (!x) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n   \
    \         return *this;\n        }\n\n        BitReference& operator&=(const BitReference&\
    \ other) {\n            if (!other) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx\
    \ & BLOCK_MASK));\n            return *this;\n        }\n\n        BitReference&\
    \ operator|=(bool x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE\
    \ << (idx & BLOCK_MASK);\n            return *this;\n        }\n\n        BitReference&\
    \ operator|=(const BitReference& other) {\n            if (other) block[idx >>\
    \ BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n            return *this;\n \
    \       }\n\n        BitReference& operator^=(bool x) {\n            if (x) block[idx\
    \ >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n            return *this;\n\
    \        }\n\n        BitReference& operator^=(const BitReference& other) {\n\
    \            if (other) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n\
    \            return *this;\n        }\n\n        BitReference& flip() {\n    \
    \        block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n        \
    \    return *this;\n        }\n\n        BitReference& operator~() {\n       \
    \     block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n           \
    \ return *this;\n        }\n\n        bool val() const {\n            return (block[idx\
    \ >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1;\n        }\n    };\n\n    BitReference\
    \ operator[](int i) {\n        assert(0 <= i && i < n);\n        return BitReference(block,\
    \ i);\n    }\n\n    bool is_pinned(int i) const {\n        assert(0 <= i && i\
    \ < n);\n        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) & 1;\n\
    \    }\n\n    T& operator=(const string& s) {\n        set(s);\n        return\
    \ *this;\n    }\n\n    T& flip() {\n        u128 mask = (ONE << (n & BLOCK_MASK))\
    \ - 1;\n        for (u128& x : block) x = ~x;\n        block.back() &= mask;\n\
    \        return *this;\n    }\n\n    T& flip(int i) {\n        assert(0 <= i &&\
    \ i < n);\n        block[i >> BLOCK_SIZE_LOG] ^= ONE << (i & BLOCK_MASK);\n  \
    \      return *this;\n    }\n\n    T& operator~() {\n        return flip();\n\
    \    }\n\n    T& operator&=(const T& other) {\n        assert(n == other.n);\n\
    \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
    \            block[i] &= other.block[i];\n        }\n        return *this;\n \
    \   }\n\n    T& operator|=(const T& other) {\n        assert(n == other.n);\n\
    \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
    \            block[i] |= other.block[i];\n        }\n        return *this;\n \
    \   }\n\n    T& operator^=(const T& other) {\n        assert(n == other.n);\n\
    \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
    \            block[i] ^= other.block[i];\n        }\n        return *this;\n \
    \   }\n\n    friend T operator&(const T& lhs, const T& rhs) {\n        return\
    \ T(lhs) &= rhs;\n    }\n    friend T operator|(const T& lhs, const T& rhs) {\n\
    \        return T(lhs) |= rhs;\n    }\n    friend T operator^(const T& lhs, const\
    \ T& rhs) {\n        return T(lhs) ^= rhs;\n    }\n    friend bool operator==(const\
    \ T& lhs, const T& rhs) {\n        if (lhs.n != rhs.n) return false;\n       \
    \ for (int i = 0; i < (lhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n   \
    \         if (lhs.block[i] != rhs.block[i]) return false;\n        }\n       \
    \ return true;\n    }\n    friend bool operator!=(const T& lhs, const T& rhs)\
    \ {\n        return !(lhs == rhs);\n    }\n\n    operator bool() const {\n   \
    \     for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n   \
    \         if (block[i]) return true;\n        }\n        return false;\n    }\n\
    \n    string to_string(u128 x) const {\n        return bitset<64>((u64)(x >> (BLOCK_SIZE\
    \ / 2))).to_string() \n             + bitset<64>((u64)(x & ((ONE << (BLOCK_SIZE\
    \ / 2)) - 1))).to_string();\n    }\n\n    string to_string() const {\n       \
    \ vector<string> tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        for (int\
    \ i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            tmp[i]\
    \ = to_string(block[i]);\n        }\n        if (n & BLOCK_MASK) {\n         \
    \   reverse(begin(tmp.back()), end(tmp.back()));\n            tmp.back().resize(n\
    \ & BLOCK_MASK);\n            reverse(begin(tmp.back()), end(tmp.back()));\n \
    \       }\n        string res;\n        for (int i = (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i--;) {\n            res += tmp[i];\n        }\n        return res;\n    }\n\
    \n    friend ostream& operator<<(ostream& os, const T& bs) {\n        return os\
    \ << bs.to_string();\n    }\n};\n\n\n"
  code: "#ifndef DATA_STRUCTURE_MY_BITSET_FAST_HPP\n#define DATA_STRUCTURE_MY_BITSET_FAST_HPP\
    \ 1\n\n\nstruct DynamicBitSetFast {\n    using T = DynamicBitSetFast;\n    using\
    \ u128 = __uint128_t;\n    constexpr static int BLOCK_SIZE_LOG = 7;\n    constexpr\
    \ static int BLOCK_SIZE = 1 << BLOCK_SIZE_LOG;\n    constexpr static int BLOCK_MASK\
    \ = BLOCK_SIZE - 1;\n    constexpr static u128 ONE = 1;\n    int n;\n    vector<u128>\
    \ block;\n\n    DynamicBitSetFast(int n_ = 0, bool x = 0) : n(n_) {\n        u128\
    \ val = x ? -1 : 0;\n        block.assign((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG,\
    \ val);\n        if (n & BLOCK_MASK) block.back() >>= BLOCK_SIZE - (n & BLOCK_MASK);\n\
    \        // fit the last block\n    }\n\n    // Note that the string needs to\
    \ be reversed.\n    // For example, if the input is \"1010\",\n    // the character\
    \ at index 0 in the string is '1',\n    // but in the bitset it will be considered\
    \ as index 0.\n    DynamicBitSetFast(const string& s) : n(s.size()) {\n      \
    \  block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        set(s);\n  \
    \  }\n\n    int size() const { return n; }\n\n    T& inplace_combine_bottom(const\
    \ T& rhs) {\n        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        if (!(n & BLOCK_MASK)) {\n            copy(begin(rhs.block), end(rhs.block),\
    \ begin(block) + (n >> BLOCK_SIZE_LOG));\n            n += rhs.n;\n          \
    \  return *this;\n        }\n        int start = BLOCK_SIZE - (n & BLOCK_MASK);\n\
    \        u128 start_mask = (ONE << start) - 1;\n        u128 end_mask = ~start_mask;\n\
    \        for (int i = 0; i < (rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++)\
    \ {\n            u128 x = rhs.block[i];\n            block[i + (n >> BLOCK_SIZE_LOG)]\
    \ |= (x & start_mask) << (BLOCK_SIZE - start);\n            if (i + (n >> BLOCK_SIZE_LOG)\
    \ + 1 < (n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)\n                block[i\
    \ + (n >> BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;\n        }\n      \
    \  n += rhs.n;\n        return *this;\n    }\n\n    T combine_bottom(const T&\
    \ rhs) const {\n        return T(*this).inplace_combine_bottom(rhs);\n    }\n\n\
    \    T& inplace_combine_top(const T& rhs) {\n        block.resize((n + rhs.n +\
    \ BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        if (!(rhs.n & BLOCK_MASK)) {\n\
    \            copy(begin(block), end(block), begin(block) + (rhs.n >> BLOCK_SIZE_LOG));\n\
    \            copy(begin(rhs.block), end(rhs.block), begin(block));\n         \
    \   n += rhs.n;\n            return *this;\n        }\n        int start = BLOCK_SIZE\
    \ - (rhs.n & BLOCK_MASK);\n        u128 start_mask = (ONE << start) - 1;\n   \
    \     u128 end_mask = ~start_mask;\n        for (int i = ((n + BLOCK_SIZE - 1)\
    \ >> BLOCK_SIZE_LOG) - 1; i >= 0; --i) {\n            u128 x = block[i];\n   \
    \         block[i + (rhs.n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE\
    \ - start);\n            if (i + (rhs.n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n +\
    \ BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)\n                block[i + (rhs.n >> BLOCK_SIZE_LOG)\
    \ + 1] |= (x & end_mask) >> start;\n        }\n        block[(rhs.n >> BLOCK_SIZE_LOG)]\
    \ = ((block[0] & start_mask) << (BLOCK_SIZE - start)) | rhs.block.back();\n  \
    \      copy(begin(rhs.block), end(rhs.block), begin(block));\n        n += rhs.n;\n\
    \        return *this;\n    }\n\n    T combine_top(const T& rhs) const {\n   \
    \     return T(*this).inplace_combine_top(rhs);\n    }\n\n    void set(int i,\
    \ int x) {\n        assert(0 <= i && i < n);\n        if (x) block[i >> BLOCK_SIZE_LOG]\
    \ |= ONE << (i & BLOCK_MASK);\n        else block[i >> BLOCK_SIZE_LOG] &= ~(ONE\
    \ << (i & BLOCK_MASK));\n    }\n\n    void set(const string& s) {\n        assert((int)s.size()\
    \ == n);\n        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i++) {\n            int r = n - (i << BLOCK_SIZE_LOG), l = max(0, r - BLOCK_SIZE);\n\
    \            u128 val = 0;\n            for (int j = l; j < r; ++j) {\n      \
    \          val = (val << 1) | (s[j] - '0');\n            }\n            block[i]\
    \ = val;\n        }\n    }\n\n    class BitReference {\n        vector<u128>&\
    \ block;\n        int idx;\n      public:\n        BitReference(vector<u128>&\
    \ block_, int idx_) : block(block_), idx(idx_) {}\n        operator bool() const\
    \ { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }\n\n   \
    \     BitReference& operator=(bool x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG]\
    \ |= ONE << (idx & BLOCK_MASK);\n            else block[idx >> BLOCK_SIZE_LOG]\
    \ &= ~(ONE << (idx & BLOCK_MASK));\n            return *this;\n        }\n\n \
    \       BitReference& operator=(const BitReference& other) {\n            if (other)\
    \ block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n            else\
    \ block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n            return\
    \ *this;\n        }\n\n        BitReference& operator&=(bool x) {\n          \
    \  if (!x) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n   \
    \         return *this;\n        }\n\n        BitReference& operator&=(const BitReference&\
    \ other) {\n            if (!other) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx\
    \ & BLOCK_MASK));\n            return *this;\n        }\n\n        BitReference&\
    \ operator|=(bool x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE\
    \ << (idx & BLOCK_MASK);\n            return *this;\n        }\n\n        BitReference&\
    \ operator|=(const BitReference& other) {\n            if (other) block[idx >>\
    \ BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n            return *this;\n \
    \       }\n\n        BitReference& operator^=(bool x) {\n            if (x) block[idx\
    \ >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n            return *this;\n\
    \        }\n\n        BitReference& operator^=(const BitReference& other) {\n\
    \            if (other) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n\
    \            return *this;\n        }\n\n        BitReference& flip() {\n    \
    \        block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n        \
    \    return *this;\n        }\n\n        BitReference& operator~() {\n       \
    \     block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n           \
    \ return *this;\n        }\n\n        bool val() const {\n            return (block[idx\
    \ >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1;\n        }\n    };\n\n    BitReference\
    \ operator[](int i) {\n        assert(0 <= i && i < n);\n        return BitReference(block,\
    \ i);\n    }\n\n    bool is_pinned(int i) const {\n        assert(0 <= i && i\
    \ < n);\n        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) & 1;\n\
    \    }\n\n    T& operator=(const string& s) {\n        set(s);\n        return\
    \ *this;\n    }\n\n    T& flip() {\n        u128 mask = (ONE << (n & BLOCK_MASK))\
    \ - 1;\n        for (u128& x : block) x = ~x;\n        block.back() &= mask;\n\
    \        return *this;\n    }\n\n    T& flip(int i) {\n        assert(0 <= i &&\
    \ i < n);\n        block[i >> BLOCK_SIZE_LOG] ^= ONE << (i & BLOCK_MASK);\n  \
    \      return *this;\n    }\n\n    T& operator~() {\n        return flip();\n\
    \    }\n\n    T& operator&=(const T& other) {\n        assert(n == other.n);\n\
    \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
    \            block[i] &= other.block[i];\n        }\n        return *this;\n \
    \   }\n\n    T& operator|=(const T& other) {\n        assert(n == other.n);\n\
    \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
    \            block[i] |= other.block[i];\n        }\n        return *this;\n \
    \   }\n\n    T& operator^=(const T& other) {\n        assert(n == other.n);\n\
    \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
    \            block[i] ^= other.block[i];\n        }\n        return *this;\n \
    \   }\n\n    friend T operator&(const T& lhs, const T& rhs) {\n        return\
    \ T(lhs) &= rhs;\n    }\n    friend T operator|(const T& lhs, const T& rhs) {\n\
    \        return T(lhs) |= rhs;\n    }\n    friend T operator^(const T& lhs, const\
    \ T& rhs) {\n        return T(lhs) ^= rhs;\n    }\n    friend bool operator==(const\
    \ T& lhs, const T& rhs) {\n        if (lhs.n != rhs.n) return false;\n       \
    \ for (int i = 0; i < (lhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n   \
    \         if (lhs.block[i] != rhs.block[i]) return false;\n        }\n       \
    \ return true;\n    }\n    friend bool operator!=(const T& lhs, const T& rhs)\
    \ {\n        return !(lhs == rhs);\n    }\n\n    operator bool() const {\n   \
    \     for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n   \
    \         if (block[i]) return true;\n        }\n        return false;\n    }\n\
    \n    string to_string(u128 x) const {\n        return bitset<64>((u64)(x >> (BLOCK_SIZE\
    \ / 2))).to_string() \n             + bitset<64>((u64)(x & ((ONE << (BLOCK_SIZE\
    \ / 2)) - 1))).to_string();\n    }\n\n    string to_string() const {\n       \
    \ vector<string> tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        for (int\
    \ i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            tmp[i]\
    \ = to_string(block[i]);\n        }\n        if (n & BLOCK_MASK) {\n         \
    \   reverse(begin(tmp.back()), end(tmp.back()));\n            tmp.back().resize(n\
    \ & BLOCK_MASK);\n            reverse(begin(tmp.back()), end(tmp.back()));\n \
    \       }\n        string res;\n        for (int i = (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i--;) {\n            res += tmp[i];\n        }\n        return res;\n    }\n\
    \n    friend ostream& operator<<(ostream& os, const T& bs) {\n        return os\
    \ << bs.to_string();\n    }\n};\n\n#endif // DATA_STRUCTURE_MY_BITSET_FAST_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/my_bitset_fast.hpp
  requiredBy: []
  timestamp: '2024-08-11 23:58:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/my_bitset_fast.hpp
layout: document
redirect_from:
- /library/data_structure/my_bitset_fast.hpp
- /library/data_structure/my_bitset_fast.hpp.html
title: data_structure/my_bitset_fast.hpp
---
