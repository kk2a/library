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
  bundledCode: "#line 1 \"matrix/matrix_F2.hpp\"\n\n\n\n#line 1 \"data_structure/my_bitset.hpp\"\
    \n\n\n\n\nstruct DynamicBitSet {\n    using T = DynamicBitSet;\n    using u64\
    \ = uint64_t;\n    int n;\n    vector<u64> block;\n\n    DynamicBitSet(int n_\
    \ = 0, int x = 0) : n(n_) {\n        assert(x == 0 || x == 1);\n        u64 val\
    \ = x ? -1 : 0;\n        block.assign((n + 63) >> 6, val);\n        if (n) block.back()\
    \ >>= ((u64)block.size() << 6) - n;\n        // fit the last block\n    }\n  \
    \  DynamicBitSet(const string& s) : n(s.size()) {\n        block.resize((n + 63)\
    \ >> 6);\n        set(s);\n    }\n\n    int size() const { return n; }\n\n   \
    \ T& inplace_combine_bottom(const T& rhs) {\n        block.resize((n + rhs.n +\
    \ 63) >> 6);\n        if (!(n & 63)) {\n            copy(begin(rhs.block), end(rhs.block),\
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
    \ true;\n        }\n        return false;\n    }\n};\n\n\n#line 5 \"matrix/matrix_F2.hpp\"\
    \n\nstruct MatrixF2 {\n    using mat = MatrixF2;\n    int _h, _w;\n    vector<DynamicBitSet>\
    \ _mat;\n\n    MatrixF2() : MatrixF2(0) {}\n    MatrixF2(int n) : MatrixF2(n,\
    \ n) {}\n    MatrixF2(int h, int w) {\n        if (h == 0) {\n            _h =\
    \ 0;\n            _w = w;\n        }\n        else {\n            _h = h;\n  \
    \          _w = w;\n            _mat.resize(h, DynamicBitSet(w));\n        }\n\
    \    }\n    MatrixF2(const vector<DynamicBitSet>& mat_) : _h(mat_.size()), _w(mat_[0].size()),\
    \ _mat(mat_) {}\n\n    int get_h() const { return _h; }\n    int get_w() const\
    \ { return _w; }\n    \n    bool at(int i, int j) {\n        assert(0 <= i &&\
    \ i < _h);\n        assert(0 <= j && j < _w);\n        return _mat[i][j].val();\n\
    \    }\n\n    class Proxy {\n        vector<DynamicBitSet>& bs;\n        int i;\n\
    \      public:\n        Proxy(vector<DynamicBitSet>& bs_, int i_) : bs(bs_), i(i_)\
    \ {}\n        operator DynamicBitSet() const { return bs[i]; }\n        Proxy&\
    \ operator=(string s) {\n            bs[i] = s;\n            return *this;\n \
    \       }\n        Proxy& operator=(DynamicBitSet x) {\n            bs[i] = x;\n\
    \            return *this;\n        }\n        Proxy& operator=(Proxy x) {\n \
    \           bs[i] = x.bs[x.i];\n            return *this;\n        }\n\n     \
    \   DynamicBitSet::Proxy operator[](int j) {\n            assert(0 <= j && j <\
    \ (int)bs[i].size());\n            return bs[i][j];\n        }\n\n        Proxy&\
    \ operator&=(DynamicBitSet x) {\n            bs[i] &= x;\n            return *this;\n\
    \        }\n        Proxy& operator&=(Proxy x) {\n            bs[i] &= x.bs[x.i];\n\
    \            return *this;\n        }\n\n        Proxy& operator|=(DynamicBitSet\
    \ x) {\n            bs[i] |= x;\n            return *this;\n        }\n      \
    \  Proxy& operator|=(Proxy x) {\n            bs[i] |= x.bs[x.i];\n           \
    \ return *this;\n        }\n\n        Proxy& operator^=(DynamicBitSet x) {\n \
    \           bs[i] ^= x;\n            return *this;\n        }\n        Proxy&\
    \ operator^=(Proxy x) {\n            bs[i] ^= x.bs[x.i];\n            return *this;\n\
    \        }\n\n        Proxy& flip() {\n            bs[i].flip();\n           \
    \ return *this;\n        }\n        Proxy& operator~() {\n            bs[i].flip();\n\
    \            return *this;\n        }\n    };\n\n    Proxy operator[](int i) {\n\
    \        assert(0 <= i && i < _h);\n        return Proxy(_mat, i);\n    }\n\n\
    \    void display() const {\n        for (int i = 0; i < _h; i++) {\n        \
    \    cout << _mat[i] << \"\\n\";\n        }\n    }\n\n    void set(int i, int\
    \ j, bool x) {\n        assert(0 <= i && i < _h);\n        assert(0 <= j && j\
    \ < _w);\n        _mat[i].set(j, x);\n    }\n\n    void set(int i, string s) {\n\
    \        assert((int)s.size() == _w);\n        _mat[i].set(s);\n    }\n\n    mat&\
    \ operator+=(const mat& rhs) {\n        assert(_h == rhs._h);\n        assert(_w\
    \ == rhs._w);\n        for (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i]\
    \ ^ rhs._mat[i];\n        }\n        return *this;\n    }\n\n    mat& operator-=(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] ^ rhs._mat[i];\n\
    \        }\n        return *this;\n    }\n\n    mat& operator^=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] ^ rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator|=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] | rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator&=(const mat& rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            _mat[i] = _mat[i] & rhs._mat[i];\n \
    \       }\n        return *this;\n    }\n\n    mat& operator*=(const mat& rhs)\
    \ {\n        assert(_w == rhs._h);\n        vector<DynamicBitSet> res(_h, DynamicBitSet(rhs._w));\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ {\n                if (_mat[i][j]) res[i] ^= rhs._mat[j];\n                //\
    \ cout << i << \" \" << j << \" \" << _mat[i][j] << \" check\" << endl;\n    \
    \            // rep (i, 2) { cout << res[i] << endl; }\n            }\n      \
    \  }\n        _w = rhs._w;\n        _mat = res;\n        return *this;\n    }\n\
    \n    friend mat operator+(const mat& lhs, const mat& rhs) { return mat(lhs) +=\
    \ rhs; }\n    friend mat operator-(const mat& lhs, const mat& rhs) { return mat(lhs)\
    \ -= rhs; }\n    friend mat operator^(const mat& lhs, const mat& rhs) { return\
    \ mat(lhs) ^= rhs; }\n    friend mat operator|(const mat& lhs, const mat& rhs)\
    \ { return mat(lhs) |= rhs; }\n    friend mat operator&(const mat& lhs, const\
    \ mat& rhs) { return mat(lhs) &= rhs; }\n    friend mat operator*(const mat& lhs,\
    \ const mat& rhs) { return mat(lhs) *= rhs; }\n    friend bool operator==(const\
    \ mat& lhs, const mat& rhs) {\n        assert(lhs._h == rhs._h);\n        assert(lhs._w\
    \ == rhs._w);\n        for (int i = 0; i < lhs._h; i++) {\n            if (lhs._mat[i]\
    \ != rhs._mat[i]) return false;\n        }\n        return true;\n    }\n    friend\
    \ bool operator!=(const mat& lhs, const mat& rhs) {\n        return !(lhs == rhs);\n\
    \    }\n\n    mat& inplace_combine_top(const mat& rhs) {\n        assert(_w ==\
    \ rhs._w);\n        _mat.insert(begin(_mat), begin(rhs._mat), end(rhs._mat));\n\
    \        _h += rhs._h;\n        return *this;\n    }\n\n    mat combine_top(const\
    \ mat& rhs) const {\n        assert(_w == rhs._w);\n        mat res(_mat);\n \
    \       return res.inplace_combine_top(rhs);\n    }\n\n    mat& inplace_combine_bottom(const\
    \ mat& rhs) {\n        assert(_w == rhs._w);\n        _mat.insert(end(_mat), begin(rhs._mat),\
    \ end(rhs._mat));\n        _h += rhs._h;\n        return *this;\n    }\n\n   \
    \ mat combine_bottom(const mat& rhs) const {\n        assert(_w == rhs._w);\n\
    \        mat res(_mat);\n        return res.inplace_combine_bottom(rhs);\n   \
    \ }\n\n    // [0, wr)\n    int sweep(int wr = -1) {\n        if (wr == -1) wr\
    \ = _w;\n        int r = 0;\n        for (int i = 0; i < wr; i++) {\n        \
    \    int pivot = -1;\n            for (int j = r; j < _h; j++) {\n           \
    \     if (_mat[j][i]) {\n                    pivot = j;\n                    break;\n\
    \                }\n            }\n            if (pivot == -1) continue;\n  \
    \          if (r != pivot) swap(_mat[r], _mat[pivot]);\n            for (int j\
    \ = 0; j < _h; j++) {\n                if (j == r) continue;\n               \
    \ if (_mat[j][i]) _mat[j] ^= _mat[r];\n            }\n            r++;\n     \
    \   }\n        return r;\n    }\n\n    void shrink() {\n        while (_h && !(bool)_mat[_h\
    \ - 1]) _mat.pop_back(), --_h;\n    }\n\n    // it must be already swept and shrunk\
    \ before calling this function\n    vector<DynamicBitSet> get_solution_base()\
    \ const {\n        vector<DynamicBitSet> res(_w - _h, DynamicBitSet(_w));\n  \
    \      vector<int> step(_h);\n        vector<bool> is_step(_w, false);\n     \
    \   int nowj = 0;\n        rep (i, _h) {\n            while (!_mat[i].is_pinned(nowj))\
    \ nowj++;\n            is_step[nowj] = true;\n            step[i] = nowj;\n  \
    \      }\n        int now = 0;\n        nowj = 0;\n        while (nowj < _w) {\n\
    \            if (is_step[nowj]) {\n                nowj++;\n                continue;\n\
    \            }\n            res[now][nowj] = 1;\n            rep (i, _h) if (_mat[i].is_pinned(nowj))\
    \ res[now][step[i]] = 1;\n            nowj++, now++;\n        }\n        return\
    \ res;\n    }\n\n    int rank() const {\n        return mat(*this).sweep();\n\
    \    }\n\n    bool det() const {\n        return rank() == _h;\n    }\n\n    mat\
    \ inv() const {\n        assert(_h == _w);\n        vector<DynamicBitSet> res(_h,\
    \ _w);\n        for (int i = 0; i < _h; i++) {\n            res[i][i] = 1;\n \
    \       }\n        vector<DynamicBitSet> buf(_mat);\n        for (int i = 0; i\
    \ < _w; i++) {\n            int pivot = -1;\n            for (int j = i; j < _h;\
    \ j++) {\n                if (buf[j][i]) {\n                    pivot = j;\n \
    \                   break;\n                }\n            }\n            if (pivot\
    \ == -1) continue;\n            swap(buf[i], buf[pivot]);\n            swap(res[i],\
    \ res[pivot]);\n            for (int j = 0; j < _h; j++) {\n                if\
    \ (j == i) continue;\n                if (buf[j][i]) {\n                    buf[j]\
    \ ^= buf[i];\n                    res[j] ^= res[i];\n                }\n     \
    \       }\n        }\n        return mat(res);\n    }\n};\n\n\n"
  code: "#ifndef MATRIX_MATRIX_F2_HPP\n#define MATRIX_MATRIX_F2_HPP 1\n\n#include\
    \ \"../data_structure/my_bitset.hpp\"\n\nstruct MatrixF2 {\n    using mat = MatrixF2;\n\
    \    int _h, _w;\n    vector<DynamicBitSet> _mat;\n\n    MatrixF2() : MatrixF2(0)\
    \ {}\n    MatrixF2(int n) : MatrixF2(n, n) {}\n    MatrixF2(int h, int w) {\n\
    \        if (h == 0) {\n            _h = 0;\n            _w = w;\n        }\n\
    \        else {\n            _h = h;\n            _w = w;\n            _mat.resize(h,\
    \ DynamicBitSet(w));\n        }\n    }\n    MatrixF2(const vector<DynamicBitSet>&\
    \ mat_) : _h(mat_.size()), _w(mat_[0].size()), _mat(mat_) {}\n\n    int get_h()\
    \ const { return _h; }\n    int get_w() const { return _w; }\n    \n    bool at(int\
    \ i, int j) {\n        assert(0 <= i && i < _h);\n        assert(0 <= j && j <\
    \ _w);\n        return _mat[i][j].val();\n    }\n\n    class Proxy {\n       \
    \ vector<DynamicBitSet>& bs;\n        int i;\n      public:\n        Proxy(vector<DynamicBitSet>&\
    \ bs_, int i_) : bs(bs_), i(i_) {}\n        operator DynamicBitSet() const { return\
    \ bs[i]; }\n        Proxy& operator=(string s) {\n            bs[i] = s;\n   \
    \         return *this;\n        }\n        Proxy& operator=(DynamicBitSet x)\
    \ {\n            bs[i] = x;\n            return *this;\n        }\n        Proxy&\
    \ operator=(Proxy x) {\n            bs[i] = x.bs[x.i];\n            return *this;\n\
    \        }\n\n        DynamicBitSet::Proxy operator[](int j) {\n            assert(0\
    \ <= j && j < (int)bs[i].size());\n            return bs[i][j];\n        }\n\n\
    \        Proxy& operator&=(DynamicBitSet x) {\n            bs[i] &= x;\n     \
    \       return *this;\n        }\n        Proxy& operator&=(Proxy x) {\n     \
    \       bs[i] &= x.bs[x.i];\n            return *this;\n        }\n\n        Proxy&\
    \ operator|=(DynamicBitSet x) {\n            bs[i] |= x;\n            return *this;\n\
    \        }\n        Proxy& operator|=(Proxy x) {\n            bs[i] |= x.bs[x.i];\n\
    \            return *this;\n        }\n\n        Proxy& operator^=(DynamicBitSet\
    \ x) {\n            bs[i] ^= x;\n            return *this;\n        }\n      \
    \  Proxy& operator^=(Proxy x) {\n            bs[i] ^= x.bs[x.i];\n           \
    \ return *this;\n        }\n\n        Proxy& flip() {\n            bs[i].flip();\n\
    \            return *this;\n        }\n        Proxy& operator~() {\n        \
    \    bs[i].flip();\n            return *this;\n        }\n    };\n\n    Proxy\
    \ operator[](int i) {\n        assert(0 <= i && i < _h);\n        return Proxy(_mat,\
    \ i);\n    }\n\n    void display() const {\n        for (int i = 0; i < _h; i++)\
    \ {\n            cout << _mat[i] << \"\\n\";\n        }\n    }\n\n    void set(int\
    \ i, int j, bool x) {\n        assert(0 <= i && i < _h);\n        assert(0 <=\
    \ j && j < _w);\n        _mat[i].set(j, x);\n    }\n\n    void set(int i, string\
    \ s) {\n        assert((int)s.size() == _w);\n        _mat[i].set(s);\n    }\n\
    \n    mat& operator+=(const mat& rhs) {\n        assert(_h == rhs._h);\n     \
    \   assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n          \
    \  _mat[i] = _mat[i] ^ rhs._mat[i];\n        }\n        return *this;\n    }\n\
    \n    mat& operator-=(const mat& rhs) {\n        assert(_h == rhs._h);\n     \
    \   assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n          \
    \  _mat[i] = _mat[i] ^ rhs._mat[i];\n        }\n        return *this;\n    }\n\
    \n    mat& operator^=(const mat& rhs) {\n        assert(_h == rhs._h);\n     \
    \   assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n          \
    \  _mat[i] = _mat[i] ^ rhs._mat[i];\n        }\n        return *this;\n    }\n\
    \n    mat& operator|=(const mat& rhs) {\n        assert(_h == rhs._h);\n     \
    \   assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n          \
    \  _mat[i] = _mat[i] | rhs._mat[i];\n        }\n        return *this;\n    }\n\
    \n    mat& operator&=(const mat& rhs) {\n        assert(_h == rhs._h);\n     \
    \   assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n          \
    \  _mat[i] = _mat[i] & rhs._mat[i];\n        }\n        return *this;\n    }\n\
    \n    mat& operator*=(const mat& rhs) {\n        assert(_w == rhs._h);\n     \
    \   vector<DynamicBitSet> res(_h, DynamicBitSet(rhs._w));\n        for (int i\
    \ = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) {\n          \
    \      if (_mat[i][j]) res[i] ^= rhs._mat[j];\n                // cout << i <<\
    \ \" \" << j << \" \" << _mat[i][j] << \" check\" << endl;\n                //\
    \ rep (i, 2) { cout << res[i] << endl; }\n            }\n        }\n        _w\
    \ = rhs._w;\n        _mat = res;\n        return *this;\n    }\n\n    friend mat\
    \ operator+(const mat& lhs, const mat& rhs) { return mat(lhs) += rhs; }\n    friend\
    \ mat operator-(const mat& lhs, const mat& rhs) { return mat(lhs) -= rhs; }\n\
    \    friend mat operator^(const mat& lhs, const mat& rhs) { return mat(lhs) ^=\
    \ rhs; }\n    friend mat operator|(const mat& lhs, const mat& rhs) { return mat(lhs)\
    \ |= rhs; }\n    friend mat operator&(const mat& lhs, const mat& rhs) { return\
    \ mat(lhs) &= rhs; }\n    friend mat operator*(const mat& lhs, const mat& rhs)\
    \ { return mat(lhs) *= rhs; }\n    friend bool operator==(const mat& lhs, const\
    \ mat& rhs) {\n        assert(lhs._h == rhs._h);\n        assert(lhs._w == rhs._w);\n\
    \        for (int i = 0; i < lhs._h; i++) {\n            if (lhs._mat[i] != rhs._mat[i])\
    \ return false;\n        }\n        return true;\n    }\n    friend bool operator!=(const\
    \ mat& lhs, const mat& rhs) {\n        return !(lhs == rhs);\n    }\n\n    mat&\
    \ inplace_combine_top(const mat& rhs) {\n        assert(_w == rhs._w);\n     \
    \   _mat.insert(begin(_mat), begin(rhs._mat), end(rhs._mat));\n        _h += rhs._h;\n\
    \        return *this;\n    }\n\n    mat combine_top(const mat& rhs) const {\n\
    \        assert(_w == rhs._w);\n        mat res(_mat);\n        return res.inplace_combine_top(rhs);\n\
    \    }\n\n    mat& inplace_combine_bottom(const mat& rhs) {\n        assert(_w\
    \ == rhs._w);\n        _mat.insert(end(_mat), begin(rhs._mat), end(rhs._mat));\n\
    \        _h += rhs._h;\n        return *this;\n    }\n\n    mat combine_bottom(const\
    \ mat& rhs) const {\n        assert(_w == rhs._w);\n        mat res(_mat);\n \
    \       return res.inplace_combine_bottom(rhs);\n    }\n\n    // [0, wr)\n   \
    \ int sweep(int wr = -1) {\n        if (wr == -1) wr = _w;\n        int r = 0;\n\
    \        for (int i = 0; i < wr; i++) {\n            int pivot = -1;\n       \
    \     for (int j = r; j < _h; j++) {\n                if (_mat[j][i]) {\n    \
    \                pivot = j;\n                    break;\n                }\n \
    \           }\n            if (pivot == -1) continue;\n            if (r != pivot)\
    \ swap(_mat[r], _mat[pivot]);\n            for (int j = 0; j < _h; j++) {\n  \
    \              if (j == r) continue;\n                if (_mat[j][i]) _mat[j]\
    \ ^= _mat[r];\n            }\n            r++;\n        }\n        return r;\n\
    \    }\n\n    void shrink() {\n        while (_h && !(bool)_mat[_h - 1]) _mat.pop_back(),\
    \ --_h;\n    }\n\n    // it must be already swept and shrunk before calling this\
    \ function\n    vector<DynamicBitSet> get_solution_base() const {\n        vector<DynamicBitSet>\
    \ res(_w - _h, DynamicBitSet(_w));\n        vector<int> step(_h);\n        vector<bool>\
    \ is_step(_w, false);\n        int nowj = 0;\n        rep (i, _h) {\n        \
    \    while (!_mat[i].is_pinned(nowj)) nowj++;\n            is_step[nowj] = true;\n\
    \            step[i] = nowj;\n        }\n        int now = 0;\n        nowj =\
    \ 0;\n        while (nowj < _w) {\n            if (is_step[nowj]) {\n        \
    \        nowj++;\n                continue;\n            }\n            res[now][nowj]\
    \ = 1;\n            rep (i, _h) if (_mat[i].is_pinned(nowj)) res[now][step[i]]\
    \ = 1;\n            nowj++, now++;\n        }\n        return res;\n    }\n\n\
    \    int rank() const {\n        return mat(*this).sweep();\n    }\n\n    bool\
    \ det() const {\n        return rank() == _h;\n    }\n\n    mat inv() const {\n\
    \        assert(_h == _w);\n        vector<DynamicBitSet> res(_h, _w);\n     \
    \   for (int i = 0; i < _h; i++) {\n            res[i][i] = 1;\n        }\n  \
    \      vector<DynamicBitSet> buf(_mat);\n        for (int i = 0; i < _w; i++)\
    \ {\n            int pivot = -1;\n            for (int j = i; j < _h; j++) {\n\
    \                if (buf[j][i]) {\n                    pivot = j;\n          \
    \          break;\n                }\n            }\n            if (pivot ==\
    \ -1) continue;\n            swap(buf[i], buf[pivot]);\n            swap(res[i],\
    \ res[pivot]);\n            for (int j = 0; j < _h; j++) {\n                if\
    \ (j == i) continue;\n                if (buf[j][i]) {\n                    buf[j]\
    \ ^= buf[i];\n                    res[j] ^= res[i];\n                }\n     \
    \       }\n        }\n        return mat(res);\n    }\n};\n\n#endif // MATRIX_MATRIX_F2_HPP\n"
  dependsOn:
  - data_structure/my_bitset.hpp
  isVerificationFile: false
  path: matrix/matrix_F2.hpp
  requiredBy: []
  timestamp: '2024-08-12 00:00:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix_F2.hpp
layout: document
redirect_from:
- /library/matrix/matrix_F2.hpp
- /library/matrix/matrix_F2.hpp.html
title: matrix/matrix_F2.hpp
---
