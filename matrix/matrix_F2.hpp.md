---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/my_bitset.hpp
    title: data_structure/my_bitset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matrix/matrix_F2.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n#include <string>\n#include <vector>\n#line\
    \ 1 \"data_structure/my_bitset.hpp\"\n\n\n\n#line 5 \"data_structure/my_bitset.hpp\"\
    \n#include <bitset>\n#line 7 \"data_structure/my_bitset.hpp\"\n#include <iterator>\n\
    #line 11 \"data_structure/my_bitset.hpp\"\n\nnamespace kk2 {\n\nstruct DynamicBitSet\
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
    \ as index 0.\n    DynamicBitSet(const std::string& s) : n(s.size()) {\n     \
    \   block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        set(s);\n \
    \   }\n\n    int size() const { return n; }\n\n    T& inplace_combine_top(const\
    \ T& rhs) {\n        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
    \        if (!(n & BLOCK_MASK)) {\n            std::copy(std::begin(rhs.block),\
    \ std::end(rhs.block), std::begin(block) + (n >> BLOCK_SIZE_LOG));\n         \
    \   n += rhs.n;\n            return *this;\n        }\n        int start = BLOCK_SIZE\
    \ - (n & BLOCK_MASK);\n        UInt start_mask = (ONE << start) - 1;\n       \
    \ UInt end_mask = ~start_mask;\n        for (int i = 0; i < (rhs.n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG; i++) {\n            UInt x = rhs.block[i];\n       \
    \     block[i + (n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE - start);\n\
    \            if (i + (n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n + BLOCK_SIZE - 1)\
    \ >> BLOCK_SIZE_LOG)\n                block[i + (n >> BLOCK_SIZE_LOG) + 1] |=\
    \ (x & end_mask) >> start;\n        }\n        n += rhs.n;\n        return *this;\n\
    \    }\n\n    T combine_top(const T& rhs) const {\n        return T(*this).inplace_combine_top(rhs);\n\
    \    }\n\n    T& inplace_combine_bottom(const T& rhs) {\n        block.resize((n\
    \ + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        if (!(rhs.n & BLOCK_MASK))\
    \ {\n            std::copy(std::begin(block), std::end(block), std::begin(block)\
    \ + (rhs.n >> BLOCK_SIZE_LOG));\n            std::copy(std::begin(rhs.block),\
    \ std::end(rhs.block), std::begin(block));\n            n += rhs.n;\n        \
    \    return *this;\n        }\n        int start = BLOCK_SIZE - (rhs.n & BLOCK_MASK);\n\
    \        UInt start_mask = (ONE << start) - 1;\n        UInt end_mask = ~start_mask;\n\
    \        for (int i = ((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG) - 1; i >= 0; --i)\
    \ {\n            UInt x = block[i];\n            block[i + (rhs.n >> BLOCK_SIZE_LOG)]\
    \ |= (x & start_mask) << (BLOCK_SIZE - start);\n            if (i + (rhs.n >>\
    \ BLOCK_SIZE_LOG) + 1 < (n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)\n    \
    \            block[i + (rhs.n >> BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;\n\
    \        }\n        block[(rhs.n >> BLOCK_SIZE_LOG)] = ((block[0] & start_mask)\
    \ << (BLOCK_SIZE - start)) | rhs.block.back();\n        std::copy(std::begin(rhs.block),\
    \ std::prev(std::end(rhs.block)), std::begin(block));\n        n += rhs.n;\n \
    \       return *this;\n    }\n\n    T combine_bottom(const T& rhs) const {\n \
    \       return T(*this).inplace_combine_bottom(rhs);\n    }\n\n    void set(int\
    \ i, int x) {\n        assert(0 <= i && i < n);\n        if (x) block[i >> BLOCK_SIZE_LOG]\
    \ |= ONE << (i & BLOCK_MASK);\n        else block[i >> BLOCK_SIZE_LOG] &= ~(ONE\
    \ << (i & BLOCK_MASK));\n    }\n\n    void set(const std::string& s) {\n     \
    \   assert((int)s.size() == n);\n        for (int i = 0; i < (n + BLOCK_SIZE -\
    \ 1) >> BLOCK_SIZE_LOG; i++) {\n            int r = n - (i << BLOCK_SIZE_LOG),\
    \ l = std::max(0, r - BLOCK_SIZE);\n            block[i] = 0;\n            for\
    \ (int j = l; j < r; j++)\n                block[i] = (block[i] << 1) | (s[j]\
    \ - '0');\n        }\n    }\n\n    void set_reversed(const std::string& s) {\n\
    \        assert((int)s.size() == n);\n        for (int i = 0; i < (n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG; i++) {\n            int l = i << BLOCK_SIZE_LOG, r =\
    \ std::min(n, l + BLOCK_SIZE);\n            block[i] = 0;\n            for (int\
    \ j = r - 1; j >= l; --j)\n                block[i] = (block[i] << 1) | (s[j]\
    \ - '0');\n        }\n    }\n\n    class BitReference {\n        std::vector<UInt>&\
    \ block;\n        int idx;\n      public:\n        BitReference(std::vector<UInt>&\
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
    \    }\n\n    T& operator=(const std::string& s) {\n        set(s);\n        return\
    \ *this;\n    }\n\n    T& flip() {\n        UInt mask = (ONE << (n & BLOCK_MASK))\
    \ - 1;\n        for (UInt& x : block) x = ~x;\n        block.back() &= mask;\n\
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
    \n    std::string to_string(UInt x) const {\n        return std::bitset<64>((unsigned\
    \ long long)(x >> (BLOCK_SIZE / 2))).to_string() \n             + std::bitset<64>((unsigned\
    \ long long)(x & ((ONE << (BLOCK_SIZE / 2)) - 1))).to_string();\n    }\n\n   \
    \ std::string to_string() const {\n        std::vector<std::string> tmp((n + BLOCK_SIZE\
    \ - 1) >> BLOCK_SIZE_LOG);\n        for (int i = 0; i < (n + BLOCK_SIZE - 1) >>\
    \ BLOCK_SIZE_LOG; i++) {\n            tmp[i] = to_string(block[i]);\n        }\n\
    \        if (n & BLOCK_MASK) {\n            std::reverse(std::begin(tmp.back()),\
    \ std::end(tmp.back()));\n            tmp.back().resize(n & BLOCK_MASK);\n   \
    \         std::reverse(std::begin(tmp.back()), std::end(tmp.back()));\n      \
    \  }\n        std::string res;\n        for (int i = (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG;\
    \ i--;) {\n            res += tmp[i];\n        }\n        return res;\n    }\n\
    \n    std::string to_reversed_string() const {\n        std::vector<std::string>\
    \ tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        for (int i = 0; i < (n\
    \ + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            tmp[i] = to_string(block[i]);\n\
    \        }\n        if (n & BLOCK_MASK) {\n            std::reverse(std::begin(tmp.back()),\
    \ std::end(tmp.back()));\n            tmp.back().resize(n & BLOCK_MASK);\n   \
    \         std::reverse(std::begin(tmp.back()), std::end(tmp.back()));\n      \
    \  }\n        std::string res;\n        for (int i = 0; i < (n + BLOCK_SIZE -\
    \ 1) >> BLOCK_SIZE_LOG; i++) {\n            std::reverse(std::begin(tmp[i]), std::end(tmp[i]));\n\
    \            res += tmp[i];\n        }\n        return res;\n    }\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const T& bs) {\n        return os\
    \ << bs.to_string();\n    }\n};\n\n} // namespace kk2\n\n\n#line 10 \"matrix/matrix_F2.hpp\"\
    \n\nnamespace kk2 {\n\nstruct MatrixF2 {\n    using mat = MatrixF2;\n    int _h,\
    \ _w;\n    std::vector<DynamicBitSet> _mat;\n\n    MatrixF2() : MatrixF2(0) {}\n\
    \    MatrixF2(int n) : MatrixF2(n, n) {}\n    MatrixF2(int h, int w) {\n     \
    \   if (h == 0) {\n            _h = 0;\n            _w = w;\n        }\n     \
    \   else {\n            _h = h;\n            _w = w;\n            _mat.resize(h,\
    \ DynamicBitSet(w));\n        }\n    }\n    MatrixF2(const std::vector<DynamicBitSet>&\
    \ mat_) : _h(mat_.size()), _w(mat_[0].size()), _mat(mat_) {}\n\n    int get_h()\
    \ const { return _h; }\n    int get_w() const { return _w; }\n    \n    bool at(int\
    \ i, int j) {\n        assert(0 <= i && i < _h);\n        assert(0 <= j && j <\
    \ _w);\n        return _mat[i][j].val();\n    }\n\n    class Proxy {\n       \
    \ std::vector<DynamicBitSet>& bs;\n        int i;\n      public:\n        Proxy(std::vector<DynamicBitSet>&\
    \ bs_, int i_) : bs(bs_), i(i_) {}\n        operator DynamicBitSet() const { return\
    \ bs[i]; }\n\n        std::string to_string() const {\n            return bs[i].to_string();\n\
    \        }\n        std::string to_reversed_string() const {\n            return\
    \ bs[i].to_reversed_string();\n        }\n\n        Proxy& operator=(const std::string&\
    \ s) {\n            bs[i].set_reversed(s);\n            return *this;\n      \
    \  }\n        Proxy& operator=(const DynamicBitSet& x) {\n            bs[i] =\
    \ x;\n            return *this;\n        }\n        Proxy& operator=(const Proxy&\
    \ x) {\n            bs[i] = x.bs[x.i];\n            return *this;\n        }\n\
    \n        DynamicBitSet::BitReference operator[](int j) {\n            assert(0\
    \ <= j && j < (int)bs[i].size());\n            return bs[i][j];\n        }\n\n\
    \        Proxy& operator&=(const DynamicBitSet& x) {\n            bs[i] &= x;\n\
    \            return *this;\n        }\n        Proxy& operator&=(const Proxy&\
    \ x) {\n            bs[i] &= x.bs[x.i];\n            return *this;\n        }\n\
    \n        Proxy& operator|=(const DynamicBitSet& x) {\n            bs[i] |= x;\n\
    \            return *this;\n        }\n        Proxy& operator|=(const Proxy&\
    \ x) {\n            bs[i] |= x.bs[x.i];\n            return *this;\n        }\n\
    \n        Proxy& operator^=(const DynamicBitSet& x) {\n            bs[i] ^= x;\n\
    \            return *this;\n        }\n        Proxy& operator^=(const Proxy&\
    \ x) {\n            bs[i] ^= x.bs[x.i];\n            return *this;\n        }\n\
    \n        Proxy& flip() {\n            bs[i].flip();\n            return *this;\n\
    \        }\n        Proxy& operator~() {\n            bs[i].flip();\n        \
    \    return *this;\n        }\n    };\n\n    Proxy operator[](int i) {\n     \
    \   assert(0 <= i && i < _h);\n        return Proxy(_mat, i);\n    }\n\n    void\
    \ display() const {\n        for (int i = 0; i < _h; i++) {\n            std::cout\
    \ << _mat[i].to_reversed_string() << \"\\n\";\n        }\n    }\n\n    void set(int\
    \ i, int j, bool x) {\n        assert(0 <= i && i < _h);\n        assert(0 <=\
    \ j && j < _w);\n        _mat[i].set(j, x);\n    }\n\n    void set(int i, const\
    \ std::string& s) {\n        assert((int)s.size() == _w);\n        _mat[i].set(s);\n\
    \    }\n\n    void set_reversed(int i, const std::string& s) {\n        assert((int)s.size()\
    \ == _w);\n        _mat[i].set_reversed(s);\n    }\n\n    mat& operator+=(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] ^ rhs._mat[i];\n\
    \        }\n        return *this;\n    }\n\n    mat& operator-=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] ^ rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator^=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] ^ rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator|=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] | rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator&=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] & rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator*=(const mat& rhs)\
    \ {\n        assert(_w == rhs._h);\n        std::vector<DynamicBitSet> res(_h,\
    \ DynamicBitSet(rhs._w));\n        for (int i = 0; i < _h; i++) {\n          \
    \  for (int j = 0; j < _w; j++) {\n                if (_mat[i][j]) res[i] ^= rhs._mat[j];\n\
    \                // cout << i << \" \" << j << \" \" << _mat[i][j] << \" check\"\
    \ << endl;\n                // rep (i, 2) { cout << res[i] << endl; }\n      \
    \      }\n        }\n        _w = rhs._w;\n        _mat = res;\n        return\
    \ *this;\n    }\n\n    friend mat operator+(const mat& lhs, const mat& rhs) {\
    \ return mat(lhs) += rhs; }\n    friend mat operator-(const mat& lhs, const mat&\
    \ rhs) { return mat(lhs) -= rhs; }\n    friend mat operator^(const mat& lhs, const\
    \ mat& rhs) { return mat(lhs) ^= rhs; }\n    friend mat operator|(const mat& lhs,\
    \ const mat& rhs) { return mat(lhs) |= rhs; }\n    friend mat operator&(const\
    \ mat& lhs, const mat& rhs) { return mat(lhs) &= rhs; }\n    friend mat operator*(const\
    \ mat& lhs, const mat& rhs) { return mat(lhs) *= rhs; }\n    friend bool operator==(const\
    \ mat& lhs, const mat& rhs) {\n        assert(lhs._h == rhs._h);\n        assert(lhs._w\
    \ == rhs._w);\n        for (int i = 0; i < lhs._h; i++) {\n            if (lhs._mat[i]\
    \ != rhs._mat[i]) return false;\n        }\n        return true;\n    }\n    friend\
    \ bool operator!=(const mat& lhs, const mat& rhs) {\n        return !(lhs == rhs);\n\
    \    }\n\n    mat& inplace_combine_top(const mat& rhs) {\n        assert(_w ==\
    \ rhs._w);\n        _mat.insert(std::begin(_mat), std::begin(rhs._mat), std::end(rhs._mat));\n\
    \        _h += rhs._h;\n        return *this;\n    }\n\n    mat combine_top(const\
    \ mat& rhs) const {\n        assert(_w == rhs._w);\n        return mat(_mat).inplace_combine_top(rhs);\n\
    \    }\n\n    mat& inplace_combine_bottom(const mat& rhs) {\n        assert(_w\
    \ == rhs._w);\n        _mat.insert(std::end(_mat), std::begin(rhs._mat), std::end(rhs._mat));\n\
    \        _h += rhs._h;\n        return *this;\n    }\n\n    mat combine_bottom(const\
    \ mat& rhs) const {\n        assert(_w == rhs._w);\n        return mat(_mat).inplace_combine_bottom(rhs);\n\
    \    }\n\n    mat& inplace_combine_right(const mat& rhs) {\n        assert(_h\
    \ == rhs._h);\n        for (int i = 0; i < _h; i++) \n            _mat[i].inplace_combine_top(rhs._mat[i]);\n\
    \        _w += rhs._w;\n        return *this;\n    }\n\n    mat combine_right(const\
    \ mat& rhs) const {\n        assert(_h == rhs._h);\n        return mat(_mat).inplace_combine_right(rhs);\n\
    \    }\n\n    mat& inplace_combine_left(const mat& rhs) {\n        assert(_h ==\
    \ rhs._h);\n        for (int i = 0; i < _h; i++) \n            _mat[i].inplace_combine_bottom(rhs._mat[i]);\n\
    \        _w += rhs._w;\n        return *this;\n    }\n\n    mat combine_left(const\
    \ mat& rhs) const {\n        assert(_h == rhs._h);\n        return mat(_mat).inplace_combine_left(rhs);\n\
    \    }\n\n    // [0, wr)\n    int sweep(int wr = -1) {\n        if (wr == -1)\
    \ wr = _w;\n        int r = 0;\n        for (int i = 0; i < wr; i++) {\n     \
    \       int pivot = -1;\n            for (int j = r; j < _h; j++) {\n        \
    \        if (_mat[j][i]) {\n                    pivot = j;\n                 \
    \   break;\n                }\n            }\n            if (pivot == -1) continue;\n\
    \            if (r != pivot) std::swap(_mat[r], _mat[pivot]);\n            for\
    \ (int j = 0; j < _h; j++) {\n                if (j == r) continue;\n        \
    \        if (_mat[j][i]) _mat[j] ^= _mat[r];\n            }\n            r++;\n\
    \        }\n        return r;\n    }\n\n    void shrink() {\n        while (_h\
    \ && !(bool)_mat[_h - 1]) _mat.pop_back(), --_h;\n    }\n\n    // it must be already\
    \ swept and shrunk before calling this function\n    std::vector<DynamicBitSet>\
    \ get_solution_base() const {\n        std::vector<DynamicBitSet> res(_w - _h,\
    \ DynamicBitSet(_w));\n        std::vector<int> step(_h);\n        std::vector<bool>\
    \ is_step(_w, false);\n        int nowj = 0;\n        for (int i = 0; i < _h;\
    \ i++) {\n            while (!_mat[i].is_pinned(nowj)) nowj++;\n            is_step[nowj]\
    \ = true;\n            step[i] = nowj;\n        }\n        int now = 0;\n    \
    \    nowj = 0;\n        while (nowj < _w) {\n            if (is_step[nowj]) {\n\
    \                nowj++;\n                continue;\n            }\n         \
    \   res[now][nowj] = 1;\n            for (int i = 0; i < _h; i++) if (_mat[i].is_pinned(nowj))\
    \ res[now][step[i]] = 1;\n            nowj++, now++;\n        }\n        return\
    \ res;\n    }\n\n    int rank() const {\n        return mat(*this).sweep();\n\
    \    }\n\n    bool det() const {\n        return rank() == _h;\n    }\n\n    mat\
    \ inv() const {\n        assert(_h == _w);\n        std::vector<DynamicBitSet>\
    \ res(_h, _w);\n        for (int i = 0; i < _h; i++) {\n            res[i][i]\
    \ = 1;\n        }\n        std::vector<DynamicBitSet> buf(_mat);\n        for\
    \ (int i = 0; i < _w; i++) {\n            int pivot = -1;\n            for (int\
    \ j = i; j < _h; j++) {\n                if (buf[j][i]) {\n                  \
    \  pivot = j;\n                    break;\n                }\n            }\n\
    \            if (pivot == -1) continue;\n            std::swap(buf[i], buf[pivot]);\n\
    \            std::swap(res[i], res[pivot]);\n            for (int j = 0; j < _h;\
    \ j++) {\n                if (j == i) continue;\n                if (buf[j][i])\
    \ {\n                    buf[j] ^= buf[i];\n                    res[j] ^= res[i];\n\
    \                }\n            }\n        }\n        return mat(res);\n    }\n\
    };\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATRIX_MATRIX_F2_HPP\n#define MATRIX_MATRIX_F2_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <string>\n#include\
    \ <vector>\n#include \"../data_structure/my_bitset.hpp\"\n\nnamespace kk2 {\n\n\
    struct MatrixF2 {\n    using mat = MatrixF2;\n    int _h, _w;\n    std::vector<DynamicBitSet>\
    \ _mat;\n\n    MatrixF2() : MatrixF2(0) {}\n    MatrixF2(int n) : MatrixF2(n,\
    \ n) {}\n    MatrixF2(int h, int w) {\n        if (h == 0) {\n            _h =\
    \ 0;\n            _w = w;\n        }\n        else {\n            _h = h;\n  \
    \          _w = w;\n            _mat.resize(h, DynamicBitSet(w));\n        }\n\
    \    }\n    MatrixF2(const std::vector<DynamicBitSet>& mat_) : _h(mat_.size()),\
    \ _w(mat_[0].size()), _mat(mat_) {}\n\n    int get_h() const { return _h; }\n\
    \    int get_w() const { return _w; }\n    \n    bool at(int i, int j) {\n   \
    \     assert(0 <= i && i < _h);\n        assert(0 <= j && j < _w);\n        return\
    \ _mat[i][j].val();\n    }\n\n    class Proxy {\n        std::vector<DynamicBitSet>&\
    \ bs;\n        int i;\n      public:\n        Proxy(std::vector<DynamicBitSet>&\
    \ bs_, int i_) : bs(bs_), i(i_) {}\n        operator DynamicBitSet() const { return\
    \ bs[i]; }\n\n        std::string to_string() const {\n            return bs[i].to_string();\n\
    \        }\n        std::string to_reversed_string() const {\n            return\
    \ bs[i].to_reversed_string();\n        }\n\n        Proxy& operator=(const std::string&\
    \ s) {\n            bs[i].set_reversed(s);\n            return *this;\n      \
    \  }\n        Proxy& operator=(const DynamicBitSet& x) {\n            bs[i] =\
    \ x;\n            return *this;\n        }\n        Proxy& operator=(const Proxy&\
    \ x) {\n            bs[i] = x.bs[x.i];\n            return *this;\n        }\n\
    \n        DynamicBitSet::BitReference operator[](int j) {\n            assert(0\
    \ <= j && j < (int)bs[i].size());\n            return bs[i][j];\n        }\n\n\
    \        Proxy& operator&=(const DynamicBitSet& x) {\n            bs[i] &= x;\n\
    \            return *this;\n        }\n        Proxy& operator&=(const Proxy&\
    \ x) {\n            bs[i] &= x.bs[x.i];\n            return *this;\n        }\n\
    \n        Proxy& operator|=(const DynamicBitSet& x) {\n            bs[i] |= x;\n\
    \            return *this;\n        }\n        Proxy& operator|=(const Proxy&\
    \ x) {\n            bs[i] |= x.bs[x.i];\n            return *this;\n        }\n\
    \n        Proxy& operator^=(const DynamicBitSet& x) {\n            bs[i] ^= x;\n\
    \            return *this;\n        }\n        Proxy& operator^=(const Proxy&\
    \ x) {\n            bs[i] ^= x.bs[x.i];\n            return *this;\n        }\n\
    \n        Proxy& flip() {\n            bs[i].flip();\n            return *this;\n\
    \        }\n        Proxy& operator~() {\n            bs[i].flip();\n        \
    \    return *this;\n        }\n    };\n\n    Proxy operator[](int i) {\n     \
    \   assert(0 <= i && i < _h);\n        return Proxy(_mat, i);\n    }\n\n    void\
    \ display() const {\n        for (int i = 0; i < _h; i++) {\n            std::cout\
    \ << _mat[i].to_reversed_string() << \"\\n\";\n        }\n    }\n\n    void set(int\
    \ i, int j, bool x) {\n        assert(0 <= i && i < _h);\n        assert(0 <=\
    \ j && j < _w);\n        _mat[i].set(j, x);\n    }\n\n    void set(int i, const\
    \ std::string& s) {\n        assert((int)s.size() == _w);\n        _mat[i].set(s);\n\
    \    }\n\n    void set_reversed(int i, const std::string& s) {\n        assert((int)s.size()\
    \ == _w);\n        _mat[i].set_reversed(s);\n    }\n\n    mat& operator+=(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] ^ rhs._mat[i];\n\
    \        }\n        return *this;\n    }\n\n    mat& operator-=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] ^ rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator^=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] ^ rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator|=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] | rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator&=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] & rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator*=(const mat& rhs)\
    \ {\n        assert(_w == rhs._h);\n        std::vector<DynamicBitSet> res(_h,\
    \ DynamicBitSet(rhs._w));\n        for (int i = 0; i < _h; i++) {\n          \
    \  for (int j = 0; j < _w; j++) {\n                if (_mat[i][j]) res[i] ^= rhs._mat[j];\n\
    \                // cout << i << \" \" << j << \" \" << _mat[i][j] << \" check\"\
    \ << endl;\n                // rep (i, 2) { cout << res[i] << endl; }\n      \
    \      }\n        }\n        _w = rhs._w;\n        _mat = res;\n        return\
    \ *this;\n    }\n\n    friend mat operator+(const mat& lhs, const mat& rhs) {\
    \ return mat(lhs) += rhs; }\n    friend mat operator-(const mat& lhs, const mat&\
    \ rhs) { return mat(lhs) -= rhs; }\n    friend mat operator^(const mat& lhs, const\
    \ mat& rhs) { return mat(lhs) ^= rhs; }\n    friend mat operator|(const mat& lhs,\
    \ const mat& rhs) { return mat(lhs) |= rhs; }\n    friend mat operator&(const\
    \ mat& lhs, const mat& rhs) { return mat(lhs) &= rhs; }\n    friend mat operator*(const\
    \ mat& lhs, const mat& rhs) { return mat(lhs) *= rhs; }\n    friend bool operator==(const\
    \ mat& lhs, const mat& rhs) {\n        assert(lhs._h == rhs._h);\n        assert(lhs._w\
    \ == rhs._w);\n        for (int i = 0; i < lhs._h; i++) {\n            if (lhs._mat[i]\
    \ != rhs._mat[i]) return false;\n        }\n        return true;\n    }\n    friend\
    \ bool operator!=(const mat& lhs, const mat& rhs) {\n        return !(lhs == rhs);\n\
    \    }\n\n    mat& inplace_combine_top(const mat& rhs) {\n        assert(_w ==\
    \ rhs._w);\n        _mat.insert(std::begin(_mat), std::begin(rhs._mat), std::end(rhs._mat));\n\
    \        _h += rhs._h;\n        return *this;\n    }\n\n    mat combine_top(const\
    \ mat& rhs) const {\n        assert(_w == rhs._w);\n        return mat(_mat).inplace_combine_top(rhs);\n\
    \    }\n\n    mat& inplace_combine_bottom(const mat& rhs) {\n        assert(_w\
    \ == rhs._w);\n        _mat.insert(std::end(_mat), std::begin(rhs._mat), std::end(rhs._mat));\n\
    \        _h += rhs._h;\n        return *this;\n    }\n\n    mat combine_bottom(const\
    \ mat& rhs) const {\n        assert(_w == rhs._w);\n        return mat(_mat).inplace_combine_bottom(rhs);\n\
    \    }\n\n    mat& inplace_combine_right(const mat& rhs) {\n        assert(_h\
    \ == rhs._h);\n        for (int i = 0; i < _h; i++) \n            _mat[i].inplace_combine_top(rhs._mat[i]);\n\
    \        _w += rhs._w;\n        return *this;\n    }\n\n    mat combine_right(const\
    \ mat& rhs) const {\n        assert(_h == rhs._h);\n        return mat(_mat).inplace_combine_right(rhs);\n\
    \    }\n\n    mat& inplace_combine_left(const mat& rhs) {\n        assert(_h ==\
    \ rhs._h);\n        for (int i = 0; i < _h; i++) \n            _mat[i].inplace_combine_bottom(rhs._mat[i]);\n\
    \        _w += rhs._w;\n        return *this;\n    }\n\n    mat combine_left(const\
    \ mat& rhs) const {\n        assert(_h == rhs._h);\n        return mat(_mat).inplace_combine_left(rhs);\n\
    \    }\n\n    // [0, wr)\n    int sweep(int wr = -1) {\n        if (wr == -1)\
    \ wr = _w;\n        int r = 0;\n        for (int i = 0; i < wr; i++) {\n     \
    \       int pivot = -1;\n            for (int j = r; j < _h; j++) {\n        \
    \        if (_mat[j][i]) {\n                    pivot = j;\n                 \
    \   break;\n                }\n            }\n            if (pivot == -1) continue;\n\
    \            if (r != pivot) std::swap(_mat[r], _mat[pivot]);\n            for\
    \ (int j = 0; j < _h; j++) {\n                if (j == r) continue;\n        \
    \        if (_mat[j][i]) _mat[j] ^= _mat[r];\n            }\n            r++;\n\
    \        }\n        return r;\n    }\n\n    void shrink() {\n        while (_h\
    \ && !(bool)_mat[_h - 1]) _mat.pop_back(), --_h;\n    }\n\n    // it must be already\
    \ swept and shrunk before calling this function\n    std::vector<DynamicBitSet>\
    \ get_solution_base() const {\n        std::vector<DynamicBitSet> res(_w - _h,\
    \ DynamicBitSet(_w));\n        std::vector<int> step(_h);\n        std::vector<bool>\
    \ is_step(_w, false);\n        int nowj = 0;\n        for (int i = 0; i < _h;\
    \ i++) {\n            while (!_mat[i].is_pinned(nowj)) nowj++;\n            is_step[nowj]\
    \ = true;\n            step[i] = nowj;\n        }\n        int now = 0;\n    \
    \    nowj = 0;\n        while (nowj < _w) {\n            if (is_step[nowj]) {\n\
    \                nowj++;\n                continue;\n            }\n         \
    \   res[now][nowj] = 1;\n            for (int i = 0; i < _h; i++) if (_mat[i].is_pinned(nowj))\
    \ res[now][step[i]] = 1;\n            nowj++, now++;\n        }\n        return\
    \ res;\n    }\n\n    int rank() const {\n        return mat(*this).sweep();\n\
    \    }\n\n    bool det() const {\n        return rank() == _h;\n    }\n\n    mat\
    \ inv() const {\n        assert(_h == _w);\n        std::vector<DynamicBitSet>\
    \ res(_h, _w);\n        for (int i = 0; i < _h; i++) {\n            res[i][i]\
    \ = 1;\n        }\n        std::vector<DynamicBitSet> buf(_mat);\n        for\
    \ (int i = 0; i < _w; i++) {\n            int pivot = -1;\n            for (int\
    \ j = i; j < _h; j++) {\n                if (buf[j][i]) {\n                  \
    \  pivot = j;\n                    break;\n                }\n            }\n\
    \            if (pivot == -1) continue;\n            std::swap(buf[i], buf[pivot]);\n\
    \            std::swap(res[i], res[pivot]);\n            for (int j = 0; j < _h;\
    \ j++) {\n                if (j == i) continue;\n                if (buf[j][i])\
    \ {\n                    buf[j] ^= buf[i];\n                    res[j] ^= res[i];\n\
    \                }\n            }\n        }\n        return mat(res);\n    }\n\
    };\n\n} // namespace kk2\n\n#endif // MATRIX_MATRIX_F2_HPP\n"
  dependsOn:
  - data_structure/my_bitset.hpp
  isVerificationFile: false
  path: matrix/matrix_F2.hpp
  requiredBy: []
  timestamp: '2024-09-10 07:56:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix_F2.hpp
layout: document
redirect_from:
- /library/matrix/matrix_F2.hpp
- /library/matrix/matrix_F2.hpp.html
title: matrix/matrix_F2.hpp
---
