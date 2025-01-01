---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: matrix/basis.hpp
    title: matrix/basis.hpp
  - icon: ':warning:'
    path: matrix/frobenius_form.hpp
    title: matrix/frobenius_form.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_det.test.cpp
    title: verify/yosupo_linalg/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_inv.test.cpp
    title: verify/yosupo_linalg/matrix_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_pow.test.cpp
    title: verify/yosupo_linalg/matrix_pow.test.cpp
  - icon: ':x:'
    path: verify/yosupo_linalg/matrix_product.test.cpp
    title: verify/yosupo_linalg/matrix_product.test.cpp
  - icon: ':x:'
    path: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
    title: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
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
  code: "#ifndef MATRIX_MATRIX_FIELD_HPP\n#define MATRIX_MATRIX_FIELD_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <optional>\n\
    #include <string>\n#include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class Field> struct MatrixField {\n    using\
    \ value_type = Field;\n    using mat = MatrixField;\n    int _h, _w;\n    std::vector<std::vector<Field>>\
    \ _mat;\n\n    MatrixField() : MatrixField(0) {}\n\n    MatrixField(int n) : MatrixField(n,\
    \ n) {}\n\n    MatrixField(int h, int w) {\n        if (h == 0) {\n          \
    \  _h = 0;\n            _w = w;\n        } else {\n            _h = h;\n     \
    \       _w = w;\n            _mat.resize(h, std::vector<Field>(w, Field()));\n\
    \        }\n    }\n\n    MatrixField(const std::vector<std::vector<Field>> &mat_)\n\
    \        : _h(mat_.size()),\n          _w(mat_[0].size()),\n          _mat(mat_)\
    \ {}\n\n    int get_h() const { return _h; }\n\n    int get_w() const { return\
    \ _w; }\n\n    Field &at(int i, int j) const {\n        assert(0 <= i && i < _h);\n\
    \        assert(0 <= j && j < _w);\n        return _mat[i][j];\n    }\n\n    std::vector<Field>\
    \ &operator[](int i) {\n        assert(0 <= i && i < _h);\n        return _mat[i];\n\
    \    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n  \
    \  mat &input(IStream &is) {\n        for (int i = 0; i < _h; i++) {\n       \
    \     for (int j = 0; j < _w; j++) { is >> _mat[i][j]; }\n        }\n        return\
    \ *this;\n    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    void output(OStream &os) const {\n        for (int i = 0; i < _h; i++) {\n\
    \            for (int j = 0; j < _w; j++) os << _mat[i][j] << \" \\n\"[j == _w\
    \ - 1];\n        }\n    }\n\n    void set(int i, int j, Field x) {\n        assert(0\
    \ <= i && i < _h);\n        assert(0 <= j && j < _w);\n        _mat[i][j] = x;\n\
    \    }\n\n    mat &operator+=(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n     \
    \       for (int j = 0; j < _w; j++) { _mat[i][j] += rhs._mat[i][j]; }\n     \
    \   }\n        return *this;\n    }\n\n    mat &operator-=(const mat &rhs) {\n\
    \        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int\
    \ i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) { _mat[i][j]\
    \ -= rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\n    mat &operator*=(const\
    \ mat &rhs) {\n        assert(_w == rhs._h);\n        std::vector<std::vector<Field>>\
    \ res(_h, std::vector<Field>(rhs._w, Field()));\n        for (int i = 0; i < _h;\
    \ i++) {\n            for (int j = 0; j < rhs._w; j++) {\n                for\
    \ (int k = 0; k < _w; k++) { res[i][j] += _mat[i][k] * rhs._mat[k][j]; }\n   \
    \         }\n        }\n        _w = rhs._w;\n        _mat.swap(res);\n      \
    \  return *this;\n    }\n\n    Field det() const {\n        assert(_h == _w);\n\
    \        int n = _h;\n        std::vector<std::vector<Field>> a(_mat);\n     \
    \   Field res = 1;\n        for (int i = 0; i < n; i++) {\n            int pivot\
    \ = -1;\n            for (int j = i; j < n; j++) {\n                if (a[j][i]\
    \ != Field(0)) {\n                    pivot = j;\n                    break;\n\
    \                }\n            }\n            if (pivot == -1) return Field(0);\n\
    \            if (i != pivot) {\n                std::swap(a[i], a[pivot]);\n \
    \               res = -res;\n            }\n            res *= a[i][i];\n    \
    \        Field inv = a[i][i].inv();\n            for (int j = i + 1; j < n; j++)\
    \ { a[i][j] *= inv; }\n            for (int j = 0; j < n; j++) {\n           \
    \     if (i == j) continue;\n                Field r = a[j][i];\n            \
    \    for (int k = i; k < n; k++) { a[j][k] -= a[i][k] * r; }\n            }\n\
    \        }\n        return res;\n    }\n\n    std::optional<mat> inv() const {\n\
    \        assert(_h == _w);\n        int n = _h;\n        std::vector<std::vector<Field>>\
    \ res(n, std::vector<Field>(n, Field()));\n        for (int i = 0; i < n; i++)\
    \ res[i][i] = 1;\n        mat a(_mat);\n        for (int i = 0; i < n; i++) {\n\
    \            int pivot = -1;\n            for (int j = i; j < n; j++) {\n    \
    \            if (a._mat[j][i] != Field(0)) {\n                    pivot = j;\n\
    \                    break;\n                }\n            }\n            if\
    \ (pivot == -1) { return {}; }\n            std::swap(a._mat[i], a._mat[pivot]);\n\
    \            std::swap(res[i], res[pivot]);\n            Field inv = a._mat[i][i].inv();\n\
    \            for (int j = 0; j < n; j++) {\n                a._mat[i][j] *= inv;\n\
    \                res[i][j] *= inv;\n            }\n            for (int j = 0;\
    \ j < n; j++) {\n                if (i == j) continue;\n                Field\
    \ r = a._mat[j][i];\n                for (int k = 0; k < n; k++) {\n         \
    \           a._mat[j][k] -= a._mat[i][k] * r;\n                    res[j][k] -=\
    \ res[i][k] * r;\n                }\n            }\n        }\n        return\
    \ mat(res);\n    }\n\n    int rank() const {\n        int n = _h, m = _w;\n  \
    \      std::vector<std::vector<Field>> a(_mat);\n        int res = 0;\n      \
    \  for (int i = 0; i < m; i++) {\n            int pivot = -1;\n            for\
    \ (int j = res; j < n; j++) {\n                if (a[j][i] != 0) {\n         \
    \           pivot = j;\n                    break;\n                }\n      \
    \      }\n            if (pivot == -1) continue;\n            std::swap(a[res],\
    \ a[pivot]);\n            Field inv = a[res][i].inv();\n            for (int j\
    \ = i; j < m; j++) { a[res][j] *= inv; }\n            for (int j = res + 1; j\
    \ < n; j++) {\n                Field r = a[j][i];\n                for (int k\
    \ = i; k < m; k++) { a[j][k] -= a[res][k] * r; }\n            }\n            res++;\n\
    \        }\n        return res;\n    }\n\n    // [0, wr)\n    int sweep(int wr\
    \ = -1) {\n        if (wr == -1) wr = _w;\n        int r = 0;\n        for (int\
    \ i = 0; i < wr; ++i) {\n            int pivot = -1;\n            for (int j =\
    \ r; j < _h; ++j) {\n                if (_mat[j][i] != Field(0)) {\n         \
    \           pivot = j;\n                    break;\n                }\n      \
    \      }\n\n            if (pivot == -1) continue;\n            if (r != pivot)\
    \ std::swap(_mat[r], _mat[pivot]);\n            Field inv = _mat[r][i].inv();\n\
    \            for (int j = 0; j < wr; ++j) { _mat[r][j] *= inv; }\n           \
    \ for (int j = 0; j < _h; ++j) {\n                if (j == r) continue;\n    \
    \            Field a = _mat[j][i];\n                if (a == Field(0)) continue;\n\
    \                for (int k = 0; k < wr; ++k) { _mat[j][k] -= _mat[r][k] * a;\
    \ }\n            }\n            r++;\n        }\n        return r;\n    }\n\n\
    \    mat &shrink() {\n        while (_h and _mat.back() == std::vector<Field>(_w,\
    \ Field())) {\n            _mat.pop_back();\n            _h--;\n        }\n  \
    \      return *this;\n    }\n\n    template <class T> mat pow(T n) const {\n \
    \       assert(_h == _w);\n        mat mul(_mat);\n        mat res(_h);\n    \
    \    for (int i = 0; i < _h; i++) res._mat[i][i] = 1;\n        while (n) {\n \
    \           if (n & 1) res *= mul;\n            mul *= mul;\n            n >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    mat solve(const mat &b) const\
    \ {\n        assert(_h == b._h);\n        assert(b._w == 1);\n        mat ab =\
    \ combine_right(b);\n        ab.sweep();\n        ab.shrink();\n\n        for\
    \ (int i = 0; i < ab._h; ++i) {\n            for (int j = 0; j < ab._w; ++j) {\n\
    \                if (ab[i][j] != Field(0)) {\n                    if (j == ab._w\
    \ - 1) return mat();\n                    break;\n                }\n        \
    \    }\n        }\n\n        mat res(1 + _w - ab._h, _w);\n        for (int i\
    \ = 0; i < ab._h; ++i) {\n            for (int j = 0; j < ab._w; ++j) {\n    \
    \            if (ab[i][j] != Field(0)) {\n                    res[0][j] = ab[i][ab._w\
    \ - 1];\n                    break;\n                }\n            }\n      \
    \  }\n\n        std::vector<int> step(ab._h);\n        std::vector<bool> is_step(ab._w\
    \ - 1, false);\n        int nowj = 0;\n        for (int i = 0; i < ab._h; i++)\
    \ {\n            while (ab[i][nowj] == Field(0)) nowj++;\n            is_step[nowj]\
    \ = true;\n            step[i] = nowj;\n        }\n        int now = 1;\n    \
    \    nowj = 0;\n        while (nowj < ab._w - 1) {\n            if (is_step[nowj])\
    \ {\n                nowj++;\n                continue;\n            }\n     \
    \       res[now][nowj] = 1;\n            for (int i = 0; i < ab._h; i++)\n   \
    \             if (ab[i][nowj] != Field(0)) res[now][step[i]] = -ab[i][nowj];\n\
    \            nowj++, now++;\n        }\n        return res;\n    }\n\n    mat\
    \ &inplace_combine_top(const mat &rhs) {\n        assert(_w == rhs._w);\n    \
    \    _mat.insert(_mat.begin(), rhs._mat.begin(), rhs._mat.end());\n        _h\
    \ += rhs._h;\n        return *this;\n    }\n\n    mat combine_top(const mat &rhs)\
    \ const { return mat(*this).inplace_combine_top(rhs); }\n\n    mat &inplace_combine_bottom(const\
    \ mat &rhs) {\n        assert(_w == rhs._w);\n        _mat.insert(_mat.end(),\
    \ rhs._mat.begin(), rhs._mat.end());\n        _h += rhs._h;\n        return *this;\n\
    \    }\n\n    mat combine_bottom(const mat &rhs) const { return mat(*this).inplace_combine_bottom(rhs);\
    \ }\n\n    mat &inplace_combine_left(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        for (int i = 0; i < _h; i++) {\n            _mat[i].insert(_mat[i].begin(),\
    \ rhs._mat[i].begin(), rhs._mat[i].end());\n        }\n        _w += rhs._w;\n\
    \        return *this;\n    }\n\n    mat combine_left(const mat &rhs) const {\
    \ return mat(*this).inplace_combine_left(rhs); }\n\n    mat &inplace_combine_right(const\
    \ mat &rhs) {\n        assert(_h == rhs._h);\n        for (int i = 0; i < _h;\
    \ i++) {\n            _mat[i].insert(_mat[i].end(), rhs._mat[i].begin(), rhs._mat[i].end());\n\
    \        }\n        _w += rhs._w;\n        return *this;\n    }\n\n    mat combine_right(const\
    \ mat &rhs) const { return mat(*this).inplace_combine_right(rhs); }\n\n    mat\
    \ &inplace_transpose() {\n        std::vector<std::vector<Field>> res(_w, std::vector<Field>(_h));\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ { res[j][i] = _mat[i][j]; }\n        }\n        _mat.swap(res);\n        std::swap(_h,\
    \ _w);\n        return *this;\n    }\n\n    mat transpose() const { return mat(*this).inplace_transpose();\
    \ }\n\n    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs)\
    \ += rhs; }\n\n    friend mat operator-(const mat &lhs, const mat &rhs) { return\
    \ mat(lhs) -= rhs; }\n\n    friend mat operator*(const mat &lhs, const mat &rhs)\
    \ { return mat(lhs) *= rhs; }\n\n    friend bool operator==(const mat &lhs, const\
    \ mat &rhs) { return lhs._mat == rhs._mat; }\n\n    friend bool operator!=(const\
    \ mat &lhs, const mat &rhs) { return lhs._mat != rhs._mat; }\n};\n\n} // namespace\
    \ kk2\n\n#endif // MATRIX_MATRIX_FIELD_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: matrix/matrix_field.hpp
  requiredBy:
  - matrix/frobenius_form.hpp
  - matrix/basis.hpp
  timestamp: '2024-12-28 13:04:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_linalg/matrix_inv.test.cpp
  - verify/yosupo_linalg/matrix_product.test.cpp
  - verify/yosupo_linalg/matrix_pow.test.cpp
  - verify/yosupo_linalg/matrix_det.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations.test.cpp
documentation_of: matrix/matrix_field.hpp
layout: document
redirect_from:
- /library/matrix/matrix_field.hpp
- /library/matrix/matrix_field.hpp.html
title: matrix/matrix_field.hpp
---
