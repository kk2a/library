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
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_det_f2.test.cpp
    title: verify/yosupo_linalg/matrix_det_f2.test.cpp
  - icon: ':x:'
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef MATRIX_MATRIX_F2_HPP\n#define MATRIX_MATRIX_F2_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <optional>\n\
    #include <string>\n#include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n#include \"../data_structure/my_bitset.hpp\"\n\nnamespace kk2 {\n\nstruct MatrixF2\
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
    \ { return bs[i]; }\n\n        template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n        friend IStream &operator>>(IStream &is, Proxy p) {\n \
    \           std::string s;\n            is >> s;\n            p = s;\n       \
    \     return is;\n        }\n\n        template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n        friend OStream &operator<<(OStream &os, Proxy p) {\n \
    \           os << p.to_reversed_string();\n            return os;\n        }\n\
    \n        std::string to_string() const { return bs[i].to_string(); }\n\n    \
    \    std::string to_reversed_string() const { return bs[i].to_reversed_string();\
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
    \ i);\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n\
    \    mat &input(IStream &is) {\n        for (int i = 0; i < _h; i++) {\n     \
    \       std::string s;\n            is >> s;\n            _mat[i].set_reversed(s);\n\
    \        }\n        return *this;\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void output(OStream &os) const {\n        for (int i = 0;\
    \ i < _h; i++) {\n            os << _mat[i].to_reversed_string() << \"\\n\";\n\
    \        }\n    }\n\n    void set(int i, int j, bool x) {\n        assert(0 <=\
    \ i && i < _h);\n        assert(0 <= j && j < _w);\n        _mat[i].set(j, x);\n\
    \    }\n\n    void set(int i, const std::string &s) {\n        assert((int)s.size()\
    \ == _w);\n        _mat[i].set(s);\n    }\n\n    void set_reversed(int i, const\
    \ std::string &s) {\n        assert((int)s.size() == _w);\n        _mat[i].set_reversed(s);\n\
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
    \ // namespace kk2\n\n#endif // MATRIX_MATRIX_F2_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  - data_structure/my_bitset.hpp
  - bit/bitcount.hpp
  isVerificationFile: false
  path: matrix/matrix_F2.hpp
  requiredBy: []
  timestamp: '2025-01-02 03:12:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_linalg/matrix_det_f2.test.cpp
  - verify/yosupo_linalg/matrix_product_f2.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  - verify/yosupo_linalg/matrix_inv_f2.test.cpp
documentation_of: matrix/matrix_F2.hpp
layout: document
redirect_from:
- /library/matrix/matrix_F2.hpp
- /library/matrix/matrix_F2.hpp.html
title: matrix/matrix_F2.hpp
---
