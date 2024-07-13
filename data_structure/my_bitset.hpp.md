---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: matrix/matrix_F2.hpp
    title: matrix/matrix_F2.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/my_bitset.hpp\"\n\n\n\n\nstruct DynamicBitSet\
    \ {\n    using T = DynamicBitSet;\n    using u64 = unsigned long long;\n    int\
    \ n;\n    vector<u64> block;\n\n    DynamicBitSet(int n_ = 0, int x = 0) : n(n_)\
    \ {\n        assert(x == 0 || x == 1);\n        u64 val = x ? -1 : 0;\n      \
    \  block.assign((n + 63) >> 6, val);\n        if (n) block.back() >>= ((u64)block.size()\
    \ << 6) - n;\n        // fit the last block\n    }\n\n    int size() const { return\
    \ n; }\n\n    void resize(int size_) {\n        block.resize((size_ + 63) >> 6);\n\
    \        int last_size = size_ & 63;\n        if (last_size) {\n            block.back()\
    \ &= (1ULL << last_size) - 1;\n        }\n        n = size_;\n    }\n\n    void\
    \ set(int i, int x) {\n        assert(0 <= i && i < n);\n        if (x) block[i\
    \ >> 6] |= 1ULL << (i & 63);\n        else block[i >> 6] &= ~(1ULL << (i & 63));\n\
    \    }\n\n    void set(const string& s) {\n        assert((int)s.size() == n);\n\
    \        for (int i = 0; i < (n + 63) >> 6; i++) {\n            string tmp = s.substr(i\
    \ << 6, min(64, n - i));\n            reverse(begin(tmp), end(tmp));\n       \
    \     block[i] = stoull(tmp, 0, 2);\n        }\n    }\n\n    class Proxy {\n \
    \       vector<u64>& bs;\n        int i;\n      public:\n        Proxy(vector<u64>&\
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
    \ *this;\n        }\n        Proxy& operator!() {\n            bs[i >> 6] ^= 1ULL\
    \ << (i & 63);\n            return *this;\n        }\n\n        bool val() {\n\
    \            return (bs[i >> 6] >> (i & 63)) & 1;\n        }\n    };\n\n    Proxy\
    \ operator[](int i) {\n        assert(0 <= i && i < n);\n        return Proxy(block,\
    \ i);\n    }\n\n    T& operator=(const string& s) {\n        assert((int)s.size()\
    \ == n);\n        set(s);\n        return *this;\n    }\n\n    void flip() {\n\
    \        u64 mask = (1ULL << (n & 63)) - 1;\n        for (u64& x : block) x =\
    \ ~x;\n        block.back() &= mask;\n    }\n\n    void flip(int i) {\n      \
    \  assert(0 <= i && i < n);\n        block[i >> 6] ^= 1ULL << (i & 63);\n    }\n\
    \n    T& operator~() {\n        flip();\n        return *this;\n    }\n\n    T&\
    \ operator!() {\n        flip();\n        return *this;\n    }\n\n    T& operator&=(const\
    \ T& rhs) {\n        assert(n == rhs.n);\n        for (int i = 0; i < (n + 63)\
    \ >> 6; i++) {\n            block[i] &= rhs.block[i];\n        }\n        return\
    \ *this;\n    }\n\n    T& operator|=(const T& rhs) {\n        assert(n == rhs.n);\n\
    \        for (int i = 0; i < (n + 63) >> 6; i++) {\n            block[i] |= rhs.block[i];\n\
    \        }\n        return *this;\n    }\n\n    T& operator^=(const T& rhs) {\n\
    \        assert(n == rhs.n);\n        for (int i = 0; i < (n + 63) >> 6; i++)\
    \ {\n            block[i] ^= rhs.block[i];\n        }\n        return *this;\n\
    \    }\n\n    friend T operator&(const T& lhs, const T& rhs) { return T(lhs) &=\
    \ rhs; }\n    friend T operator|(const T& lhs, const T& rhs) { return T(lhs) |=\
    \ rhs; }\n    friend T operator^(const T& lhs, const T& rhs) { return T(lhs) ^=\
    \ rhs; }\n    friend bool operator==(const T& lhs, const T& rhs) {\n        assert(lhs.n\
    \ == rhs.n);\n        for (int i = 0; i < (lhs.n + 63) >> 6; i++) {\n        \
    \    if (lhs.block[i] != rhs.block[i]) return false;\n        }\n        return\
    \ true;\n    }\n    friend bool operator!=(const T& lhs, const T& rhs) { return\
    \ !(T(lhs) == rhs); }\n\n    string to_string() const {\n        string s;\n \
    \       int i = 0;\n        for (; i + 1 < (n + 63) >> 6; i++) {\n           \
    \ string tmp = bitset<64>(block[i]).to_string();\n            reverse(begin(tmp),\
    \ end(tmp));\n            s += tmp;\n        }\n        int start = 64 - n & 63;\n\
    \        int len = n & 63;\n        if (!len) start = 0, len = 64;\n        string\
    \ tmp = bitset<64>(block.back()).to_string().substr(start, len);\n        reverse(begin(tmp),\
    \ end(tmp));\n        s += tmp;\n        return s;\n    }\n\n    friend ostream&\
    \ operator<<(ostream& os, const T& bs) {\n        return os << bs.to_string();\n\
    \    }\n};\n\n\n"
  code: "#ifndef DATA_STRUCTURE_MY_BITSET_HPP\n#define DATA_STRUCTURE_MY_BITSET_HPP\
    \ 1\n\n\nstruct DynamicBitSet {\n    using T = DynamicBitSet;\n    using u64 =\
    \ unsigned long long;\n    int n;\n    vector<u64> block;\n\n    DynamicBitSet(int\
    \ n_ = 0, int x = 0) : n(n_) {\n        assert(x == 0 || x == 1);\n        u64\
    \ val = x ? -1 : 0;\n        block.assign((n + 63) >> 6, val);\n        if (n)\
    \ block.back() >>= ((u64)block.size() << 6) - n;\n        // fit the last block\n\
    \    }\n\n    int size() const { return n; }\n\n    void resize(int size_) {\n\
    \        block.resize((size_ + 63) >> 6);\n        int last_size = size_ & 63;\n\
    \        if (last_size) {\n            block.back() &= (1ULL << last_size) - 1;\n\
    \        }\n        n = size_;\n    }\n\n    void set(int i, int x) {\n      \
    \  assert(0 <= i && i < n);\n        if (x) block[i >> 6] |= 1ULL << (i & 63);\n\
    \        else block[i >> 6] &= ~(1ULL << (i & 63));\n    }\n\n    void set(const\
    \ string& s) {\n        assert((int)s.size() == n);\n        for (int i = 0; i\
    \ < (n + 63) >> 6; i++) {\n            string tmp = s.substr(i << 6, min(64, n\
    \ - i));\n            reverse(begin(tmp), end(tmp));\n            block[i] = stoull(tmp,\
    \ 0, 2);\n        }\n    }\n\n    class Proxy {\n        vector<u64>& bs;\n  \
    \      int i;\n      public:\n        Proxy(vector<u64>& bs_, int i_) : bs(bs_),\
    \ i(i_) {}\n        operator bool() const { return (bs[i >> 6] >> (i & 63)) &\
    \ 1; }\n        Proxy& operator=(bool x) {\n            if (x) bs[i >> 6] |= 1ULL\
    \ << (i & 63);\n            else bs[i >> 6] &= ~(1ULL << (i & 63));\n        \
    \    return *this;\n        }\n        Proxy& operator=(const Proxy& x) {\n  \
    \          if (x) bs[i >> 6] |= 1ULL << (i & 63);\n            else bs[i >> 6]\
    \ &= ~(1ULL << (i & 63));\n            return *this;\n        }\n\n        Proxy&\
    \ operator&=(bool x) {\n            if (!x) bs[i >> 6] &= ~(1ULL << (i & 63));\n\
    \            return *this;\n        }\n        Proxy& operator&=(const Proxy&\
    \ x) {\n            bs[i >> 6] &= x.bs[x.i >> 6] >> (x.i & 63);\n            return\
    \ *this;\n        }\n\n        Proxy& operator|=(bool x) {\n            if (x)\
    \ bs[i >> 6] |= 1ULL << (i & 63);\n            return *this;\n        }\n    \
    \    Proxy& operator|=(const Proxy& x) {\n            bs[i >> 6] |= x.bs[x.i >>\
    \ 6] >> (x.i & 63);\n            return *this;\n        }\n\n        Proxy& operator^=(bool\
    \ x) {\n            if (x) bs[i >> 6] ^= 1ULL << (i & 63);\n            return\
    \ *this;\n        }\n        Proxy& operator^=(const Proxy& x) {\n           \
    \ bs[i >> 6] ^= x.bs[x.i >> 6] >> (x.i & 63);\n            return *this;\n   \
    \     }\n\n        Proxy& flip() {\n            bs[i >> 6] ^= 1ULL << (i & 63);\n\
    \            return *this;\n        }\n        Proxy& operator~() {\n        \
    \    bs[i >> 6] ^= 1ULL << (i & 63);\n            return *this;\n        }\n \
    \       Proxy& operator!() {\n            bs[i >> 6] ^= 1ULL << (i & 63);\n  \
    \          return *this;\n        }\n\n        bool val() {\n            return\
    \ (bs[i >> 6] >> (i & 63)) & 1;\n        }\n    };\n\n    Proxy operator[](int\
    \ i) {\n        assert(0 <= i && i < n);\n        return Proxy(block, i);\n  \
    \  }\n\n    T& operator=(const string& s) {\n        assert((int)s.size() == n);\n\
    \        set(s);\n        return *this;\n    }\n\n    void flip() {\n        u64\
    \ mask = (1ULL << (n & 63)) - 1;\n        for (u64& x : block) x = ~x;\n     \
    \   block.back() &= mask;\n    }\n\n    void flip(int i) {\n        assert(0 <=\
    \ i && i < n);\n        block[i >> 6] ^= 1ULL << (i & 63);\n    }\n\n    T& operator~()\
    \ {\n        flip();\n        return *this;\n    }\n\n    T& operator!() {\n \
    \       flip();\n        return *this;\n    }\n\n    T& operator&=(const T& rhs)\
    \ {\n        assert(n == rhs.n);\n        for (int i = 0; i < (n + 63) >> 6; i++)\
    \ {\n            block[i] &= rhs.block[i];\n        }\n        return *this;\n\
    \    }\n\n    T& operator|=(const T& rhs) {\n        assert(n == rhs.n);\n   \
    \     for (int i = 0; i < (n + 63) >> 6; i++) {\n            block[i] |= rhs.block[i];\n\
    \        }\n        return *this;\n    }\n\n    T& operator^=(const T& rhs) {\n\
    \        assert(n == rhs.n);\n        for (int i = 0; i < (n + 63) >> 6; i++)\
    \ {\n            block[i] ^= rhs.block[i];\n        }\n        return *this;\n\
    \    }\n\n    friend T operator&(const T& lhs, const T& rhs) { return T(lhs) &=\
    \ rhs; }\n    friend T operator|(const T& lhs, const T& rhs) { return T(lhs) |=\
    \ rhs; }\n    friend T operator^(const T& lhs, const T& rhs) { return T(lhs) ^=\
    \ rhs; }\n    friend bool operator==(const T& lhs, const T& rhs) {\n        assert(lhs.n\
    \ == rhs.n);\n        for (int i = 0; i < (lhs.n + 63) >> 6; i++) {\n        \
    \    if (lhs.block[i] != rhs.block[i]) return false;\n        }\n        return\
    \ true;\n    }\n    friend bool operator!=(const T& lhs, const T& rhs) { return\
    \ !(T(lhs) == rhs); }\n\n    string to_string() const {\n        string s;\n \
    \       int i = 0;\n        for (; i + 1 < (n + 63) >> 6; i++) {\n           \
    \ string tmp = bitset<64>(block[i]).to_string();\n            reverse(begin(tmp),\
    \ end(tmp));\n            s += tmp;\n        }\n        int start = 64 - n & 63;\n\
    \        int len = n & 63;\n        if (!len) start = 0, len = 64;\n        string\
    \ tmp = bitset<64>(block.back()).to_string().substr(start, len);\n        reverse(begin(tmp),\
    \ end(tmp));\n        s += tmp;\n        return s;\n    }\n\n    friend ostream&\
    \ operator<<(ostream& os, const T& bs) {\n        return os << bs.to_string();\n\
    \    }\n};\n\n#endif // DATA_STRUCTURE_MY_BITSET_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/my_bitset.hpp
  requiredBy:
  - matrix/matrix_F2.hpp
  timestamp: '2024-07-13 13:02:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/my_bitset.hpp
layout: document
redirect_from:
- /library/data_structure/my_bitset.hpp
- /library/data_structure/my_bitset.hpp.html
title: data_structure/my_bitset.hpp
---
