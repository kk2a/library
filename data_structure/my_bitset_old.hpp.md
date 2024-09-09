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
  bundledCode: "#line 1 \"data_structure/my_bitset_old.hpp\"\n\n\n\nnamespace kk2\
    \ {\n\n// old version\nstruct DynamicBitSet {\n    using T = DynamicBitSet;\n\
    \    using u64 = uint64_t;\n    int n;\n    vector<u64> block;\n\n    DynamicBitSet(int\
    \ n_ = 0, int x = 0) : n(n_) {\n        assert(x == 0 || x == 1);\n        u64\
    \ val = x ? -1 : 0;\n        block.assign((n + 63) >> 6, val);\n        if (n)\
    \ block.back() >>= ((u64)block.size() << 6) - n;\n        // fit the last block\n\
    \    }\n    DynamicBitSet(const string& s) : n(s.size()) {\n        block.resize((n\
    \ + 63) >> 6);\n        set(s);\n    }\n\n    int size() const { return n; }\n\
    \n    T& inplace_combine_bottom(const T& rhs) {\n        block.resize((n + rhs.n\
    \ + 63) >> 6);\n        if (!(n & 63)) {\n            copy(begin(rhs.block), end(rhs.block),\
    \ begin(block) + (n >> 6));\n            n += rhs.n;\n            return *this;\n\
    \        }\n        int start = 64 - (n & 63);\n        u64 start_mask = (1ULL\
    \ << start) - 1;\n        u64 end_mask = ~start_mask;\n        for (int i = 0;\
    \ i < (rhs.n + 63) >> 6; i++) {\n            u64 x = rhs.block[i];\n         \
    \   block[i + (n >> 6)] |= (x & start_mask) << (64 - start);\n            if (i\
    \ + (n >> 6) + 1 < (n + rhs.n + 63) >> 6)\n                block[i + (n >> 6)\
    \ + 1] |= (x & end_mask) >> start;\n        }\n        n += rhs.n;\n        return\
    \ *this;\n    }\n\n    T combine_bottom(const T& rhs) const {\n        return\
    \ T(*this).inplace_combine_bottom(rhs);\n    }\n\n    T& inplace_combine_top(const\
    \ T& rhs) {\n        block.resize((n + rhs.n + 63) >> 6);\n        if (!(rhs.n\
    \ & 63)) {\n            copy(begin(block), end(block), begin(block) + (rhs.n >>\
    \ 6));\n            copy(begin(rhs.block), end(rhs.block), begin(block));\n  \
    \          n += rhs.n;\n            return *this;\n        }\n        int start\
    \ = 64 - (rhs.n & 63);\n        u64 start_mask = (1ULL << start) - 1;\n      \
    \  u64 end_mask = ~start_mask;\n        for (int i = ((n + 63) >> 6) - 1; i >=\
    \ 0; --i) {\n            u64 x = block[i];\n            block[i + (rhs.n >> 6)]\
    \ |= (x & start_mask) << (64 - start);\n            if (i + (rhs.n >> 6) + 1 <\
    \ (n + rhs.n + 63) >> 6)\n                block[i + (rhs.n >> 6) + 1] |= (x &\
    \ end_mask) >> start;\n        }\n        block[(rhs.n >> 6)] = ((block[0] & start_mask)\
    \ << (64 - start)) | rhs.block.back();\n        copy(begin(rhs.block), prev(end(rhs.block)),\
    \ begin(block));\n        n += rhs.n;\n        return *this;\n    }\n\n    T combine_top(const\
    \ T& rhs) const {\n        return T(*this).inplace_combine_top(rhs);\n    }\n\n\
    \    void set(int i, int x) {\n        assert(0 <= i && i < n);\n        if (x)\
    \ block[i >> 6] |= 1ULL << (i & 63);\n        else block[i >> 6] &= ~(1ULL <<\
    \ (i & 63));\n    }\n\n    void set(const string& s) {\n        assert((int)s.size()\
    \ == n);\n        for (int i = 0; i < (n + 63) >> 6; i++) {\n            string\
    \ tmp = s.substr(i << 6, min(64, n - i));\n            reverse(begin(tmp), end(tmp));\n\
    \            block[i] = stoull(tmp, 0, 2);\n        }\n    }\n\n    class Proxy\
    \ {\n        vector<u64>& bs;\n        int i;\n      public:\n        Proxy(vector<u64>&\
    \ bs_, int i_) : bs(bs_), i(i_) {}\n        operator bool() const { return (bs[i\
    \ >> 6] >> (i & 63)) & 1; }\n        Proxy& operator=(bool x) {\n            if\
    \ (x) bs[i >> 6] |= 1ULL << (i & 63);\n            else bs[i >> 6] &= ~(1ULL <<\
    \ (i & 63));\n            return *this;\n        }\n        Proxy& operator=(const\
    \ Proxy& x) {\n            if (x) bs[i >> 6] |= 1ULL << (i & 63);\n          \
    \  else bs[i >> 6] &= ~(1ULL << (i & 63));\n            return *this;\n      \
    \  }\n\n        Proxy& operator&=(bool x) {\n            if (!x) bs[i >> 6] &=\
    \ ~(1ULL << (i & 63));\n            return *this;\n        }\n        Proxy& operator&=(const\
    \ Proxy& x) {\n            bs[i >> 6] &= x.bs[x.i >> 6] >> (x.i & 63);\n     \
    \       return *this;\n        }\n\n        Proxy& operator|=(bool x) {\n    \
    \        if (x) bs[i >> 6] |= 1ULL << (i & 63);\n            return *this;\n \
    \       }\n        Proxy& operator|=(const Proxy& x) {\n            bs[i >> 6]\
    \ |= x.bs[x.i >> 6] >> (x.i & 63);\n            return *this;\n        }\n\n \
    \       Proxy& operator^=(bool x) {\n            if (x) bs[i >> 6] ^= 1ULL <<\
    \ (i & 63);\n            return *this;\n        }\n        Proxy& operator^=(const\
    \ Proxy& x) {\n            bs[i >> 6] ^= x.bs[x.i >> 6] >> (x.i & 63);\n     \
    \       return *this;\n        }\n\n        Proxy& flip() {\n            bs[i\
    \ >> 6] ^= 1ULL << (i & 63);\n            return *this;\n        }\n        Proxy&\
    \ operator~() {\n            bs[i >> 6] ^= 1ULL << (i & 63);\n            return\
    \ *this;\n        }\n\n        bool val() {\n            return (bs[i >> 6] >>\
    \ (i & 63)) & 1;\n        }\n    };\n\n    Proxy operator[](int i) {\n       \
    \ assert(0 <= i && i < n);\n        return Proxy(block, i);\n    }\n\n    bool\
    \ is_pinned(int i) const {\n        assert(0 <= i && i < n);\n        return (block[i\
    \ >> 6] >> (i & 63)) & 1;\n    }\n\n    T& operator=(const string& s) {\n    \
    \    assert((int)s.size() == n);\n        set(s);\n        return *this;\n   \
    \ }\n\n    void flip() {\n        u64 mask = (1ULL << (n & 63)) - 1;\n       \
    \ for (u64& x : block) x = ~x;\n        block.back() &= mask;\n    }\n\n    void\
    \ flip(int i) {\n        assert(0 <= i && i < n);\n        block[i >> 6] ^= 1ULL\
    \ << (i & 63);\n    }\n\n    T& operator~() {\n        flip();\n        return\
    \ *this;\n    }\n\n    T& operator&=(const T& rhs) {\n        assert(n == rhs.n);\n\
    \        for (int i = 0; i < (n + 63) >> 6; i++) {\n            block[i] &= rhs.block[i];\n\
    \        }\n        return *this;\n    }\n\n    T& operator|=(const T& rhs) {\n\
    \        assert(n == rhs.n);\n        for (int i = 0; i < (n + 63) >> 6; i++)\
    \ {\n            block[i] |= rhs.block[i];\n        }\n        return *this;\n\
    \    }\n\n    T& operator^=(const T& rhs) {\n        assert(n == rhs.n);\n   \
    \     for (int i = 0; i < (n + 63) >> 6; i++) {\n            block[i] ^= rhs.block[i];\n\
    \        }\n        return *this;\n    }\n\n    friend T operator&(const T& lhs,\
    \ const T& rhs) { return T(lhs) &= rhs; }\n    friend T operator|(const T& lhs,\
    \ const T& rhs) { return T(lhs) |= rhs; }\n    friend T operator^(const T& lhs,\
    \ const T& rhs) { return T(lhs) ^= rhs; }\n    friend bool operator==(const T&\
    \ lhs, const T& rhs) {\n        assert(lhs.n == rhs.n);\n        for (int i =\
    \ 0; i < (lhs.n + 63) >> 6; i++) {\n            if (lhs.block[i] != rhs.block[i])\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ T& lhs, const T& rhs) { return !(T(lhs) == rhs); }\n\n    string to_string()\
    \ const {\n        string s;\n        int i = 0;\n        for (; i + 1 < (n +\
    \ 63) >> 6; i++) {\n            string tmp = bitset<64>(block[i]).to_string();\n\
    \            reverse(begin(tmp), end(tmp));\n            s += tmp;\n        }\n\
    \        int start = 64 - (n & 63);\n        int len = n & 63;\n        if (!len)\
    \ start = 0, len = 64;\n        string tmp = bitset<64>(block.back()).to_string().substr(start,\
    \ len);\n        reverse(begin(tmp), end(tmp));\n        s += tmp;\n        return\
    \ s;\n    }\n\n    friend ostream& operator<<(ostream& os, const T& bs) {\n  \
    \      return os << bs.to_string();\n    }\n\n    operator bool() const {\n  \
    \      for (int i = 0; i < (n + 63) >> 6; i++) {\n            if (block[i]) return\
    \ true;\n        }\n        return false;\n    }\n};\n\n} // namespace kk2\n\n\
    \n"
  code: "#ifndef DATA_STRUCTURE_MY_BITSET_HPP\n#define DATA_STRUCTURE_MY_BITSET_HPP\
    \ 1\n\nnamespace kk2 {\n\n// old version\nstruct DynamicBitSet {\n    using T\
    \ = DynamicBitSet;\n    using u64 = uint64_t;\n    int n;\n    vector<u64> block;\n\
    \n    DynamicBitSet(int n_ = 0, int x = 0) : n(n_) {\n        assert(x == 0 ||\
    \ x == 1);\n        u64 val = x ? -1 : 0;\n        block.assign((n + 63) >> 6,\
    \ val);\n        if (n) block.back() >>= ((u64)block.size() << 6) - n;\n     \
    \   // fit the last block\n    }\n    DynamicBitSet(const string& s) : n(s.size())\
    \ {\n        block.resize((n + 63) >> 6);\n        set(s);\n    }\n\n    int size()\
    \ const { return n; }\n\n    T& inplace_combine_bottom(const T& rhs) {\n     \
    \   block.resize((n + rhs.n + 63) >> 6);\n        if (!(n & 63)) {\n         \
    \   copy(begin(rhs.block), end(rhs.block), begin(block) + (n >> 6));\n       \
    \     n += rhs.n;\n            return *this;\n        }\n        int start = 64\
    \ - (n & 63);\n        u64 start_mask = (1ULL << start) - 1;\n        u64 end_mask\
    \ = ~start_mask;\n        for (int i = 0; i < (rhs.n + 63) >> 6; i++) {\n    \
    \        u64 x = rhs.block[i];\n            block[i + (n >> 6)] |= (x & start_mask)\
    \ << (64 - start);\n            if (i + (n >> 6) + 1 < (n + rhs.n + 63) >> 6)\n\
    \                block[i + (n >> 6) + 1] |= (x & end_mask) >> start;\n       \
    \ }\n        n += rhs.n;\n        return *this;\n    }\n\n    T combine_bottom(const\
    \ T& rhs) const {\n        return T(*this).inplace_combine_bottom(rhs);\n    }\n\
    \n    T& inplace_combine_top(const T& rhs) {\n        block.resize((n + rhs.n\
    \ + 63) >> 6);\n        if (!(rhs.n & 63)) {\n            copy(begin(block), end(block),\
    \ begin(block) + (rhs.n >> 6));\n            copy(begin(rhs.block), end(rhs.block),\
    \ begin(block));\n            n += rhs.n;\n            return *this;\n       \
    \ }\n        int start = 64 - (rhs.n & 63);\n        u64 start_mask = (1ULL <<\
    \ start) - 1;\n        u64 end_mask = ~start_mask;\n        for (int i = ((n +\
    \ 63) >> 6) - 1; i >= 0; --i) {\n            u64 x = block[i];\n            block[i\
    \ + (rhs.n >> 6)] |= (x & start_mask) << (64 - start);\n            if (i + (rhs.n\
    \ >> 6) + 1 < (n + rhs.n + 63) >> 6)\n                block[i + (rhs.n >> 6) +\
    \ 1] |= (x & end_mask) >> start;\n        }\n        block[(rhs.n >> 6)] = ((block[0]\
    \ & start_mask) << (64 - start)) | rhs.block.back();\n        copy(begin(rhs.block),\
    \ prev(end(rhs.block)), begin(block));\n        n += rhs.n;\n        return *this;\n\
    \    }\n\n    T combine_top(const T& rhs) const {\n        return T(*this).inplace_combine_top(rhs);\n\
    \    }\n\n    void set(int i, int x) {\n        assert(0 <= i && i < n);\n   \
    \     if (x) block[i >> 6] |= 1ULL << (i & 63);\n        else block[i >> 6] &=\
    \ ~(1ULL << (i & 63));\n    }\n\n    void set(const string& s) {\n        assert((int)s.size()\
    \ == n);\n        for (int i = 0; i < (n + 63) >> 6; i++) {\n            string\
    \ tmp = s.substr(i << 6, min(64, n - i));\n            reverse(begin(tmp), end(tmp));\n\
    \            block[i] = stoull(tmp, 0, 2);\n        }\n    }\n\n    class Proxy\
    \ {\n        vector<u64>& bs;\n        int i;\n      public:\n        Proxy(vector<u64>&\
    \ bs_, int i_) : bs(bs_), i(i_) {}\n        operator bool() const { return (bs[i\
    \ >> 6] >> (i & 63)) & 1; }\n        Proxy& operator=(bool x) {\n            if\
    \ (x) bs[i >> 6] |= 1ULL << (i & 63);\n            else bs[i >> 6] &= ~(1ULL <<\
    \ (i & 63));\n            return *this;\n        }\n        Proxy& operator=(const\
    \ Proxy& x) {\n            if (x) bs[i >> 6] |= 1ULL << (i & 63);\n          \
    \  else bs[i >> 6] &= ~(1ULL << (i & 63));\n            return *this;\n      \
    \  }\n\n        Proxy& operator&=(bool x) {\n            if (!x) bs[i >> 6] &=\
    \ ~(1ULL << (i & 63));\n            return *this;\n        }\n        Proxy& operator&=(const\
    \ Proxy& x) {\n            bs[i >> 6] &= x.bs[x.i >> 6] >> (x.i & 63);\n     \
    \       return *this;\n        }\n\n        Proxy& operator|=(bool x) {\n    \
    \        if (x) bs[i >> 6] |= 1ULL << (i & 63);\n            return *this;\n \
    \       }\n        Proxy& operator|=(const Proxy& x) {\n            bs[i >> 6]\
    \ |= x.bs[x.i >> 6] >> (x.i & 63);\n            return *this;\n        }\n\n \
    \       Proxy& operator^=(bool x) {\n            if (x) bs[i >> 6] ^= 1ULL <<\
    \ (i & 63);\n            return *this;\n        }\n        Proxy& operator^=(const\
    \ Proxy& x) {\n            bs[i >> 6] ^= x.bs[x.i >> 6] >> (x.i & 63);\n     \
    \       return *this;\n        }\n\n        Proxy& flip() {\n            bs[i\
    \ >> 6] ^= 1ULL << (i & 63);\n            return *this;\n        }\n        Proxy&\
    \ operator~() {\n            bs[i >> 6] ^= 1ULL << (i & 63);\n            return\
    \ *this;\n        }\n\n        bool val() {\n            return (bs[i >> 6] >>\
    \ (i & 63)) & 1;\n        }\n    };\n\n    Proxy operator[](int i) {\n       \
    \ assert(0 <= i && i < n);\n        return Proxy(block, i);\n    }\n\n    bool\
    \ is_pinned(int i) const {\n        assert(0 <= i && i < n);\n        return (block[i\
    \ >> 6] >> (i & 63)) & 1;\n    }\n\n    T& operator=(const string& s) {\n    \
    \    assert((int)s.size() == n);\n        set(s);\n        return *this;\n   \
    \ }\n\n    void flip() {\n        u64 mask = (1ULL << (n & 63)) - 1;\n       \
    \ for (u64& x : block) x = ~x;\n        block.back() &= mask;\n    }\n\n    void\
    \ flip(int i) {\n        assert(0 <= i && i < n);\n        block[i >> 6] ^= 1ULL\
    \ << (i & 63);\n    }\n\n    T& operator~() {\n        flip();\n        return\
    \ *this;\n    }\n\n    T& operator&=(const T& rhs) {\n        assert(n == rhs.n);\n\
    \        for (int i = 0; i < (n + 63) >> 6; i++) {\n            block[i] &= rhs.block[i];\n\
    \        }\n        return *this;\n    }\n\n    T& operator|=(const T& rhs) {\n\
    \        assert(n == rhs.n);\n        for (int i = 0; i < (n + 63) >> 6; i++)\
    \ {\n            block[i] |= rhs.block[i];\n        }\n        return *this;\n\
    \    }\n\n    T& operator^=(const T& rhs) {\n        assert(n == rhs.n);\n   \
    \     for (int i = 0; i < (n + 63) >> 6; i++) {\n            block[i] ^= rhs.block[i];\n\
    \        }\n        return *this;\n    }\n\n    friend T operator&(const T& lhs,\
    \ const T& rhs) { return T(lhs) &= rhs; }\n    friend T operator|(const T& lhs,\
    \ const T& rhs) { return T(lhs) |= rhs; }\n    friend T operator^(const T& lhs,\
    \ const T& rhs) { return T(lhs) ^= rhs; }\n    friend bool operator==(const T&\
    \ lhs, const T& rhs) {\n        assert(lhs.n == rhs.n);\n        for (int i =\
    \ 0; i < (lhs.n + 63) >> 6; i++) {\n            if (lhs.block[i] != rhs.block[i])\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ T& lhs, const T& rhs) { return !(T(lhs) == rhs); }\n\n    string to_string()\
    \ const {\n        string s;\n        int i = 0;\n        for (; i + 1 < (n +\
    \ 63) >> 6; i++) {\n            string tmp = bitset<64>(block[i]).to_string();\n\
    \            reverse(begin(tmp), end(tmp));\n            s += tmp;\n        }\n\
    \        int start = 64 - (n & 63);\n        int len = n & 63;\n        if (!len)\
    \ start = 0, len = 64;\n        string tmp = bitset<64>(block.back()).to_string().substr(start,\
    \ len);\n        reverse(begin(tmp), end(tmp));\n        s += tmp;\n        return\
    \ s;\n    }\n\n    friend ostream& operator<<(ostream& os, const T& bs) {\n  \
    \      return os << bs.to_string();\n    }\n\n    operator bool() const {\n  \
    \      for (int i = 0; i < (n + 63) >> 6; i++) {\n            if (block[i]) return\
    \ true;\n        }\n        return false;\n    }\n};\n\n} // namespace kk2\n\n\
    #endif // DATA_STRUCTURE_MY_BITSET_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/my_bitset_old.hpp
  requiredBy: []
  timestamp: '2024-09-08 23:31:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/my_bitset_old.hpp
layout: document
redirect_from:
- /library/data_structure/my_bitset_old.hpp
- /library/data_structure/my_bitset_old.hpp.html
title: data_structure/my_bitset_old.hpp
---
