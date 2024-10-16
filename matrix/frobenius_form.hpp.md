---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: matrix/basis.hpp
    title: matrix/basis.hpp
  - icon: ':question:'
    path: matrix/matrix_field.hpp
    title: matrix/matrix_field.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matrix/frobenius_form.hpp\"\n\n\n\n#include <vector>\n\n\
    #line 1 \"matrix/basis.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <optional>\n#line 8 \"matrix/basis.hpp\"\n\n#line 1 \"matrix/matrix_field.hpp\"\
    \n\n\n\n#line 6 \"matrix/matrix_field.hpp\"\n#include <iostream>\n#line 8 \"matrix/matrix_field.hpp\"\
    \n#include <string>\n#line 10 \"matrix/matrix_field.hpp\"\n\nnamespace kk2 {\n\
    \ntemplate <class Field> struct MatrixField {\n    using value_type = Field;\n\
    \    using mat = MatrixField;\n    int _h, _w;\n    std::vector<std::vector<Field>>\
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
    \    }\n\n    void display() const {\n        for (int i = 0; i < _h; i++) {\n\
    \            for (int j = 0; j < _w; j++) std::cout << _mat[i][j] << \" \\n\"\
    [j == _w - 1];\n        }\n    }\n\n    template <class IStream>\n    mat &input(IStream\
    \ &is) {\n        for (int i = 0; i < _h; i++) {\n            for (int j = 0;\
    \ j < _w; j++) { is >> _mat[i][j]; }\n        }\n        return *this;\n    }\n\
    \n    template <class OStream>\n    void output(OStream &os) const {\n       \
    \ for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) os\
    \ << _mat[i][j] << \" \\n\"[j == _w - 1];\n        }\n    }\n\n    void set(int\
    \ i, int j, Field x) {\n        assert(0 <= i && i < _h);\n        assert(0 <=\
    \ j && j < _w);\n        _mat[i][j] = x;\n    }\n\n    mat &operator+=(const mat\
    \ &rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n    \
    \    for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ { _mat[i][j] += rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\
    \n    mat &operator-=(const mat &rhs) {\n        assert(_h == rhs._h);\n     \
    \   assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n          \
    \  for (int j = 0; j < _w; j++) { _mat[i][j] -= rhs._mat[i][j]; }\n        }\n\
    \        return *this;\n    }\n\n    mat &operator*=(const mat &rhs) {\n     \
    \   assert(_w == rhs._h);\n        std::vector<std::vector<Field>> res(_h, std::vector<Field>(rhs._w,\
    \ Field()));\n        for (int i = 0; i < _h; i++) {\n            for (int j =\
    \ 0; j < rhs._w; j++) {\n                for (int k = 0; k < _w; k++) { res[i][j]\
    \ += _mat[i][k] * rhs._mat[k][j]; }\n            }\n        }\n        _w = rhs._w;\n\
    \        _mat.swap(res);\n        return *this;\n    }\n\n    Field det() const\
    \ {\n        assert(_h == _w);\n        int n = _h;\n        std::vector<std::vector<Field>>\
    \ a(_mat);\n        Field res = 1;\n        for (int i = 0; i < n; i++) {\n  \
    \          int pivot = -1;\n            for (int j = i; j < n; j++) {\n      \
    \          if (a[j][i] != Field(0)) {\n                    pivot = j;\n      \
    \              break;\n                }\n            }\n            if (pivot\
    \ == -1) return Field(0);\n            if (i != pivot) {\n                std::swap(a[i],\
    \ a[pivot]);\n                res = -res;\n            }\n            res *= a[i][i];\n\
    \            Field inv = a[i][i].inv();\n            for (int j = i + 1; j < n;\
    \ j++) { a[i][j] *= inv; }\n            for (int j = 0; j < n; j++) {\n      \
    \          if (i == j) continue;\n                Field r = a[j][i];\n       \
    \         for (int k = i; k < n; k++) { a[j][k] -= a[i][k] * r; }\n          \
    \  }\n        }\n        return res;\n    }\n\n    std::optional<mat> inv() const\
    \ {\n        assert(_h == _w);\n        int n = _h;\n        std::vector<std::vector<Field>>\
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
    \ kk2\n\n\n#line 10 \"matrix/basis.hpp\"\n\nnamespace kk2 {\n\nnamespace linear_algebra\
    \ {\n\ntemplate <class Matrix, class Field> struct Basis_base {\n    struct RowBasicTransform\
    \ {\n        int type;\n        int i, j;\n        Field t, t_inv;\n\n       \
    \ RowBasicTransform() = default;\n\n        // type = 0: row(i) <- row(i) * t\n\
    \        //           t_inv = 1 / t\n        // type = 1: row(j) <- row(j) + row(i)\
    \ * t\n        //           t_inv = -t\n        // type = 2: swap(row(i), row(j))\n\
    \        //           t_inv = unused\n        RowBasicTransform(int type_, int\
    \ i_, int j_, Field t_, Field t_inv_)\n            : type(type_),\n          \
    \    i(i_),\n              j(j_),\n              t(t_),\n              t_inv(t_inv_)\
    \ {}\n\n        void transform(Matrix &mat, bool inv = false) const {\n      \
    \      if (type == 0) {\n                if (inv) {\n                    mat[i][0]\
    \ *= t_inv;\n                } else {\n                    mat[i][0] *= t;\n \
    \               }\n            } else if (type == 1) {\n                if (inv)\
    \ {\n                    mat[j][0] += mat[i][0] * t_inv;\n                } else\
    \ {\n                    mat[j][0] += mat[i][0] * t;\n                }\n    \
    \        } else if (type == 2) {\n                std::swap(mat[i], mat[j]);\n\
    \            }\n        }\n    };\n\n    int h, rank;\n\n    struct SnapShot {\n\
    \        int rank, hist_size;\n    };\n\n    std::vector<RowBasicTransform> hist;\n\
    \    std::vector<SnapShot> snaps;\n\n    BasisField() = default;\n\n    BasisField(int\
    \ h_) : h(h_), rank(0) {}\n\n    Matrix &sweep(Matrix &vec) const {\n        for\
    \ (auto &&t : hist) t.transform(vec);\n        return vec;\n    }\n\n    // vec\
    \ is column vector\n    bool is_linearly_independent(const Matrix &vec) const\
    \ {\n        assert(vec.get_h() == h);\n        assert(vec.get_w() == 1);\n  \
    \      if (rank == h) return false;\n\n        Matrix tmp(vec);\n        sweep(tmp);\n\
    \        for (int i = rank; i < h; ++i) {\n            if (tmp[i][0] != Field(0))\
    \ return true;\n        }\n        return false;\n    }\n\n    // vec is column\
    \ vector\n    // if vec is not linearly independent with current basis, return\
    \ coordinate vector\n    // else return std::nullopt\n    std::optional<Matrix>\
    \ add(const Matrix &vec) {\n        assert(vec.get_h() == h);\n        assert(vec.get_w()\
    \ == 1);\n\n        Matrix tmp(vec);\n        sweep(tmp);\n\n        int pivot\
    \ = -1;\n        for (int i = rank; i < h; ++i) {\n            if (tmp[i][0] !=\
    \ Field(0)) {\n                pivot = i;\n                break;\n          \
    \  }\n        }\n        if (pivot == -1) return tmp;\n\n        if (pivot !=\
    \ rank) {\n            std::swap(tmp[pivot], tmp[rank]);\n            hist.emplace_back(2,\
    \ rank, pivot, Field(1), Field(1));\n        }\n        if (tmp[rank][0] != Field(1))\
    \ {\n            hist.emplace_back(0, rank, -1, tmp[rank][0].inv(), tmp[rank][0]);\n\
    \            tmp[rank][0] = Field(1);\n        }\n        for (int i = 0; i <\
    \ h; ++i) {\n            if (i == rank) continue;\n            Field t = -tmp[i][0];\n\
    \            if (t == Field(0)) continue;\n            hist.emplace_back(1, rank,\
    \ i, t, -t);\n        }\n        ++rank;\n        return {};\n    }\n\n    Matrix\
    \ get_coordinate(const Matrix &vec) const {\n        assert(vec.get_h() == h);\n\
    \        assert(vec.get_w() == 1);\n        Matrix tmp(vec);\n        sweep(tmp);\n\
    \        for (int i = rank; i < h; ++i) assert(tmp[i][0] == Field(0));\n     \
    \   return res;\n    }\n\n    void snapshot() { snaps.emplace_back(rank, (int)hist.size());\
    \ }\n\n    void rollback() {\n        if (snaps.empty()) return;\n        auto\
    \ snap = snaps.back();\n        snaps.pop_back();\n        rank = snap.rank;\n\
    \        hist.resize(snap.hist_size);\n    }\n};\n\n} // namespace linear_algebra\n\
    \ntemplate <class Matrix>\nusing BasisMatrix = linear_algebra::Basis_base<Matrix,\
    \ typename Matrix::value_type>;\n\n} // namespace kk2\n\n\n#line 7 \"matrix/frobenius_form.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace linear_algebra {\n\ntemplate <class Matrix, class\
    \ Poly, class Field>\nstruct FrobeniusForm_base {\n    Matrix mat;\n    std::vector<int>\
    \ deg;\n    std::vector<Poly> poly;\n\n    // mat = P_inv frobenius P\n    //\
    \ P_inv = P^{-1}\n    Matrix frobenius, P, P_inv;\n\n    FrobeniusForm_base(const\
    \ Matrix &mat_) : mat(mat_) {\n        int n = mat.get_h();\n        assert(n\
    \ == mat.get_w());\n        frobenius = P = Matrix(n, n);\n        build();\n\
    \    }\n\n    void build() {\n        int n = mat.get_h();\n        Basis_base<Matrix,\
    \ Field> basis;\n        // \u4E71\u629E\u3067\u9811\u5F35\u308B\n    }\n};\n\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATRIX_FROBENIUS_FORM_HPP\n#define MATRIX_FROBENIUS_FORM_HPP 1\n\n\
    #include <vector>\n\n#include \"basis.hpp\"\n\nnamespace kk2 {\n\nnamespace linear_algebra\
    \ {\n\ntemplate <class Matrix, class Poly, class Field>\nstruct FrobeniusForm_base\
    \ {\n    Matrix mat;\n    std::vector<int> deg;\n    std::vector<Poly> poly;\n\
    \n    // mat = P_inv frobenius P\n    // P_inv = P^{-1}\n    Matrix frobenius,\
    \ P, P_inv;\n\n    FrobeniusForm_base(const Matrix &mat_) : mat(mat_) {\n    \
    \    int n = mat.get_h();\n        assert(n == mat.get_w());\n        frobenius\
    \ = P = Matrix(n, n);\n        build();\n    }\n\n    void build() {\n       \
    \ int n = mat.get_h();\n        Basis_base<Matrix, Field> basis;\n        // \u4E71\
    \u629E\u3067\u9811\u5F35\u308B\n    }\n};\n\n}\n\n} // namespace kk2\n\n#endif\
    \ // MATRIX_FROBENIUS_FORM_HPP\n"
  dependsOn:
  - matrix/basis.hpp
  - matrix/matrix_field.hpp
  isVerificationFile: false
  path: matrix/frobenius_form.hpp
  requiredBy: []
  timestamp: '2024-10-08 15:42:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/frobenius_form.hpp
layout: document
redirect_from:
- /library/matrix/frobenius_form.hpp
- /library/matrix/frobenius_form.hpp.html
title: matrix/frobenius_form.hpp
---
