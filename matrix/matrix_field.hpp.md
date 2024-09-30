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
  bundledCode: "#line 1 \"matrix/matrix_field.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <string>\n#include <vector>\n\
    \nnamespace kk2 {\n\ntemplate <class Field> struct MatrixField {\n    using mat\
    \ = MatrixField;\n\n    MatrixField() : MatrixField(0) {}\n\n    MatrixField(int\
    \ n) : MatrixField(n, n) {}\n\n    MatrixField(int h, int w)\n        : MatrixField(std::vector<std::vector<Field>>(h,\
    \ std::vector<Field>(w, Field()))) {}\n\n    MatrixField(const std::vector<std::vector<Field>>\
    \ &mat_)\n        : _h(mat_.size()),\n          _w(mat_[0].size()),\n        \
    \  _mat(mat_) {}\n\n    int get_h() const { return _h; }\n\n    int get_w() const\
    \ { return _w; }\n\n    Field at(int i, int j) const {\n        assert(0 <= i\
    \ && i < _h);\n        assert(0 <= j && j < _w);\n        return _mat[i][j];\n\
    \    }\n\n    std::vector<Field> &operator[](int i) {\n        assert(0 <= i &&\
    \ i < _h);\n        return _mat[i];\n    }\n\n    void display() const {\n   \
    \     for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ std::cout << _mat[i][j] << \" \";\n            std::cout << \"\\n\";\n     \
    \   }\n    }\n\n    void set(int i, int j, Field x) {\n        assert(0 <= i &&\
    \ i < _h);\n        assert(0 <= j && j < _w);\n        _mat[i][j] = x;\n    }\n\
    \n    mat &operator+=(const mat &rhs) {\n        assert(_h == rhs._h);\n     \
    \   assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n          \
    \  for (int j = 0; j < _w; j++) { _mat[i][j] += rhs._mat[i][j]; }\n        }\n\
    \        return *this;\n    }\n\n    mat &operator-=(const mat &rhs) {\n     \
    \   assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int i =\
    \ 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) { _mat[i][j] -=\
    \ rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\n    mat &operator*=(const\
    \ mat &rhs) {\n        assert(_w == rhs._h);\n        std::vector<std::vector<Field>>\
    \ res(_h, std::vector<Field>(rhs._w, Field()));\n        for (int i = 0; i < _h;\
    \ i++) {\n            for (int j = 0; j < rhs._w; j++) {\n                for\
    \ (int k = 0; k < _w; k++) { res[i][j] += _mat[i][k] * rhs._mat[k][j]; }\n   \
    \         }\n        }\n        _w = rhs._w;\n        _mat.swap(res);\n      \
    \  return *this;\n    }\n\n    Field det(Field product_e = Field(1)) const {\n\
    \        assert(_h == _w);\n        int n = _h;\n        std::vector<std::vector<Field>>\
    \ a(_mat);\n        Field res = 1;\n        for (int i = 0; i < n; i++) {\n  \
    \          int pivot = -1;\n            for (int j = i; j < n; j++) {\n      \
    \          if (a[j][i] != Field(0)) {\n                    pivot = j;\n      \
    \              break;\n                }\n            }\n            if (pivot\
    \ == -1) return Field(0);\n            if (i != pivot) {\n                std::swap(a[i],\
    \ a[pivot]);\n                res = -res;\n            }\n            res *= a[i][i];\n\
    \            Field inv = product_e / a[i][i];\n            for (int j = i + 1;\
    \ j < n; j++) { a[i][j] *= inv; }\n            for (int j = 0; j < n; j++) {\n\
    \                if (i == j) continue;\n                Field r = a[j][i];\n \
    \               for (int k = i; k < n; k++) { a[j][k] -= a[i][k] * r; }\n    \
    \        }\n        }\n        return res;\n    }\n\n    mat inv(Field product_e\
    \ = Field(1)) const {\n        assert(_h == _w);\n        int n = _h;\n      \
    \  std::vector<std::vector<Field>> res(n, std::vector<Field>(n, Field()));\n \
    \       for (int i = 0; i < n; i++) res[i][i] = 1;\n        mat a(_mat);\n   \
    \     for (int i = 0; i < n; i++) {\n            int pivot = -1;\n           \
    \ for (int j = i; j < n; j++) {\n                if (a._mat[j][i] != Field(0))\
    \ {\n                    pivot = j;\n                    break;\n            \
    \    }\n            }\n            if (pivot == -1) { return mat(n); }\n     \
    \       std::swap(a._mat[i], a._mat[pivot]);\n            std::swap(res[i], res[pivot]);\n\
    \            Field inv = product_e / a._mat[i][i];\n            for (int j = 0;\
    \ j < n; j++) {\n                a._mat[i][j] *= inv;\n                res[i][j]\
    \ *= inv;\n            }\n            for (int j = 0; j < n; j++) {\n        \
    \        if (i == j) continue;\n                Field r = a._mat[j][i];\n    \
    \            for (int k = 0; k < n; k++) {\n                    a._mat[j][k] -=\
    \ a._mat[i][k] * r;\n                    res[j][k] -= res[i][k] * r;\n       \
    \         }\n            }\n        }\n        return mat(res);\n    }\n\n   \
    \ template <class T> mat pow(T n) const {\n        assert(_h == _w);\n       \
    \ mat mul(_mat);\n        mat res(_h);\n        for (int i = 0; i < _h; i++) res._mat[i][i]\
    \ = 1;\n        while (n) {\n            if (n & 1) res *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return res;\n    }\n\n   \
    \ int rank(Field product_e = Field(1)) const {\n        int n = _h, m = _w;\n\
    \        std::vector<std::vector<Field>> a(_mat);\n        int res = 0;\n    \
    \    for (int i = 0; i < m; i++) {\n            int pivot = -1;\n            for\
    \ (int j = res; j < n; j++) {\n                if (a[j][i] != 0) {\n         \
    \           pivot = j;\n                    break;\n                }\n      \
    \      }\n            if (pivot == -1) continue;\n            std::swap(a[res],\
    \ a[pivot]);\n            Field inv = product_e / a[res][i];\n            for\
    \ (int j = i; j < m; j++) { a[res][j] *= inv; }\n            for (int j = res\
    \ + 1; j < n; j++) {\n                Field r = a[j][i];\n                for\
    \ (int k = i; k < m; k++) { a[j][k] -= a[res][k] * r; }\n            }\n     \
    \       res++;\n        }\n        return res;\n    }\n\n    mat &inplace_combine_top(const\
    \ mat &rhs) {\n        assert(_w == rhs._w);\n        this->_mat.insert(std::begin(this->_mat),\
    \ std::begin(rhs._mat), std::end(rhs._mat));\n        this->_h += rhs._h;\n  \
    \      return *this;\n    }\n\n    mat combine_top(const mat &rhs) const {\n \
    \       assert(_w == rhs._w);\n        mat res(this->_mat);\n        return res.inplace_combine_top(rhs);\n\
    \    }\n\n    mat &inplace_combine_bottom(const mat &rhs) {\n        assert(_w\
    \ == rhs._w);\n        this->_mat.insert(std::end(this->_mat), std::begin(rhs._mat),\
    \ std::end(rhs._mat));\n        this->_h += rhs._h;\n        return *this;\n \
    \   }\n\n    mat combine_bottom(const mat &rhs) const {\n        assert(_w ==\
    \ rhs._w);\n        mat res(this->_mat);\n        return res.inplace_combine_bottom(rhs);\n\
    \    }\n\n    mat &inplace_combine_left(const mat &rhs) {\n        assert(_h ==\
    \ rhs._h);\n        for (int i = 0; i < _h; i++) {\n            this->_mat[i].insert(\n\
    \                std::begin(this->_mat[i]), std::begin(rhs._mat[i]), std::end(rhs._mat[i]));\n\
    \        }\n        this->_w += rhs._w;\n        return *this;\n    }\n\n    mat\
    \ combine_left(const mat &rhs) const {\n        assert(_h == rhs._h);\n      \
    \  mat res(this->_mat);\n        return res.inplace_combine_left(rhs);\n    }\n\
    \n    mat &inplace_combine_right(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        for (int i = 0; i < _h; i++) {\n            this->_mat[i].insert(\n \
    \               std::end(this->_mat[i]), std::begin(rhs._mat[i]), std::end(rhs._mat[i]));\n\
    \        }\n        this->_w += rhs._w;\n        return *this;\n    }\n\n    mat\
    \ combine_right(const mat &rhs) const {\n        assert(_h == rhs._h);\n     \
    \   mat res(this->_mat);\n        return res.inplace_combine_right(rhs);\n   \
    \ }\n\n    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs)\
    \ += rhs; }\n\n    friend mat operator-(const mat &lhs, const mat &rhs) { return\
    \ mat(lhs) -= rhs; }\n\n    friend mat operator*(const mat &lhs, const mat &rhs)\
    \ { return mat(lhs) *= rhs; }\n\n    friend bool operator==(const mat &lhs, const\
    \ mat &rhs) { return lhs._mat == rhs._mat; }\n\n    friend bool operator!=(const\
    \ mat &lhs, const mat &rhs) { return lhs._mat != rhs._mat; }\n\n\n  private:\n\
    \    int _h, _w;\n    std::vector<std::vector<Field>> _mat;\n};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef MATRIX_MATRIX_FIELD_HPP\n#define MATRIX_MATRIX_FIELD_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <string>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\ntemplate <class Field> struct MatrixField {\n\
    \    using mat = MatrixField;\n\n    MatrixField() : MatrixField(0) {}\n\n   \
    \ MatrixField(int n) : MatrixField(n, n) {}\n\n    MatrixField(int h, int w)\n\
    \        : MatrixField(std::vector<std::vector<Field>>(h, std::vector<Field>(w,\
    \ Field()))) {}\n\n    MatrixField(const std::vector<std::vector<Field>> &mat_)\n\
    \        : _h(mat_.size()),\n          _w(mat_[0].size()),\n          _mat(mat_)\
    \ {}\n\n    int get_h() const { return _h; }\n\n    int get_w() const { return\
    \ _w; }\n\n    Field at(int i, int j) const {\n        assert(0 <= i && i < _h);\n\
    \        assert(0 <= j && j < _w);\n        return _mat[i][j];\n    }\n\n    std::vector<Field>\
    \ &operator[](int i) {\n        assert(0 <= i && i < _h);\n        return _mat[i];\n\
    \    }\n\n    void display() const {\n        for (int i = 0; i < _h; i++) {\n\
    \            for (int j = 0; j < _w; j++) std::cout << _mat[i][j] << \" \";\n\
    \            std::cout << \"\\n\";\n        }\n    }\n\n    void set(int i, int\
    \ j, Field x) {\n        assert(0 <= i && i < _h);\n        assert(0 <= j && j\
    \ < _w);\n        _mat[i][j] = x;\n    }\n\n    mat &operator+=(const mat &rhs)\
    \ {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for\
    \ (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) { _mat[i][j]\
    \ += rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\n    mat &operator-=(const\
    \ mat &rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ { _mat[i][j] -= rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\
    \n    mat &operator*=(const mat &rhs) {\n        assert(_w == rhs._h);\n     \
    \   std::vector<std::vector<Field>> res(_h, std::vector<Field>(rhs._w, Field()));\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < rhs._w;\
    \ j++) {\n                for (int k = 0; k < _w; k++) { res[i][j] += _mat[i][k]\
    \ * rhs._mat[k][j]; }\n            }\n        }\n        _w = rhs._w;\n      \
    \  _mat.swap(res);\n        return *this;\n    }\n\n    Field det(Field product_e\
    \ = Field(1)) const {\n        assert(_h == _w);\n        int n = _h;\n      \
    \  std::vector<std::vector<Field>> a(_mat);\n        Field res = 1;\n        for\
    \ (int i = 0; i < n; i++) {\n            int pivot = -1;\n            for (int\
    \ j = i; j < n; j++) {\n                if (a[j][i] != Field(0)) {\n         \
    \           pivot = j;\n                    break;\n                }\n      \
    \      }\n            if (pivot == -1) return Field(0);\n            if (i !=\
    \ pivot) {\n                std::swap(a[i], a[pivot]);\n                res =\
    \ -res;\n            }\n            res *= a[i][i];\n            Field inv = product_e\
    \ / a[i][i];\n            for (int j = i + 1; j < n; j++) { a[i][j] *= inv; }\n\
    \            for (int j = 0; j < n; j++) {\n                if (i == j) continue;\n\
    \                Field r = a[j][i];\n                for (int k = i; k < n; k++)\
    \ { a[j][k] -= a[i][k] * r; }\n            }\n        }\n        return res;\n\
    \    }\n\n    mat inv(Field product_e = Field(1)) const {\n        assert(_h ==\
    \ _w);\n        int n = _h;\n        std::vector<std::vector<Field>> res(n, std::vector<Field>(n,\
    \ Field()));\n        for (int i = 0; i < n; i++) res[i][i] = 1;\n        mat\
    \ a(_mat);\n        for (int i = 0; i < n; i++) {\n            int pivot = -1;\n\
    \            for (int j = i; j < n; j++) {\n                if (a._mat[j][i] !=\
    \ Field(0)) {\n                    pivot = j;\n                    break;\n  \
    \              }\n            }\n            if (pivot == -1) { return mat(n);\
    \ }\n            std::swap(a._mat[i], a._mat[pivot]);\n            std::swap(res[i],\
    \ res[pivot]);\n            Field inv = product_e / a._mat[i][i];\n          \
    \  for (int j = 0; j < n; j++) {\n                a._mat[i][j] *= inv;\n     \
    \           res[i][j] *= inv;\n            }\n            for (int j = 0; j <\
    \ n; j++) {\n                if (i == j) continue;\n                Field r =\
    \ a._mat[j][i];\n                for (int k = 0; k < n; k++) {\n             \
    \       a._mat[j][k] -= a._mat[i][k] * r;\n                    res[j][k] -= res[i][k]\
    \ * r;\n                }\n            }\n        }\n        return mat(res);\n\
    \    }\n\n    template <class T> mat pow(T n) const {\n        assert(_h == _w);\n\
    \        mat mul(_mat);\n        mat res(_h);\n        for (int i = 0; i < _h;\
    \ i++) res._mat[i][i] = 1;\n        while (n) {\n            if (n & 1) res *=\
    \ mul;\n            mul *= mul;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    int rank(Field product_e = Field(1)) const {\n        int\
    \ n = _h, m = _w;\n        std::vector<std::vector<Field>> a(_mat);\n        int\
    \ res = 0;\n        for (int i = 0; i < m; i++) {\n            int pivot = -1;\n\
    \            for (int j = res; j < n; j++) {\n                if (a[j][i] != 0)\
    \ {\n                    pivot = j;\n                    break;\n            \
    \    }\n            }\n            if (pivot == -1) continue;\n            std::swap(a[res],\
    \ a[pivot]);\n            Field inv = product_e / a[res][i];\n            for\
    \ (int j = i; j < m; j++) { a[res][j] *= inv; }\n            for (int j = res\
    \ + 1; j < n; j++) {\n                Field r = a[j][i];\n                for\
    \ (int k = i; k < m; k++) { a[j][k] -= a[res][k] * r; }\n            }\n     \
    \       res++;\n        }\n        return res;\n    }\n\n    mat &inplace_combine_top(const\
    \ mat &rhs) {\n        assert(_w == rhs._w);\n        this->_mat.insert(std::begin(this->_mat),\
    \ std::begin(rhs._mat), std::end(rhs._mat));\n        this->_h += rhs._h;\n  \
    \      return *this;\n    }\n\n    mat combine_top(const mat &rhs) const {\n \
    \       assert(_w == rhs._w);\n        mat res(this->_mat);\n        return res.inplace_combine_top(rhs);\n\
    \    }\n\n    mat &inplace_combine_bottom(const mat &rhs) {\n        assert(_w\
    \ == rhs._w);\n        this->_mat.insert(std::end(this->_mat), std::begin(rhs._mat),\
    \ std::end(rhs._mat));\n        this->_h += rhs._h;\n        return *this;\n \
    \   }\n\n    mat combine_bottom(const mat &rhs) const {\n        assert(_w ==\
    \ rhs._w);\n        mat res(this->_mat);\n        return res.inplace_combine_bottom(rhs);\n\
    \    }\n\n    mat &inplace_combine_left(const mat &rhs) {\n        assert(_h ==\
    \ rhs._h);\n        for (int i = 0; i < _h; i++) {\n            this->_mat[i].insert(\n\
    \                std::begin(this->_mat[i]), std::begin(rhs._mat[i]), std::end(rhs._mat[i]));\n\
    \        }\n        this->_w += rhs._w;\n        return *this;\n    }\n\n    mat\
    \ combine_left(const mat &rhs) const {\n        assert(_h == rhs._h);\n      \
    \  mat res(this->_mat);\n        return res.inplace_combine_left(rhs);\n    }\n\
    \n    mat &inplace_combine_right(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        for (int i = 0; i < _h; i++) {\n            this->_mat[i].insert(\n \
    \               std::end(this->_mat[i]), std::begin(rhs._mat[i]), std::end(rhs._mat[i]));\n\
    \        }\n        this->_w += rhs._w;\n        return *this;\n    }\n\n    mat\
    \ combine_right(const mat &rhs) const {\n        assert(_h == rhs._h);\n     \
    \   mat res(this->_mat);\n        return res.inplace_combine_right(rhs);\n   \
    \ }\n\n    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs)\
    \ += rhs; }\n\n    friend mat operator-(const mat &lhs, const mat &rhs) { return\
    \ mat(lhs) -= rhs; }\n\n    friend mat operator*(const mat &lhs, const mat &rhs)\
    \ { return mat(lhs) *= rhs; }\n\n    friend bool operator==(const mat &lhs, const\
    \ mat &rhs) { return lhs._mat == rhs._mat; }\n\n    friend bool operator!=(const\
    \ mat &lhs, const mat &rhs) { return lhs._mat != rhs._mat; }\n\n\n  private:\n\
    \    int _h, _w;\n    std::vector<std::vector<Field>> _mat;\n};\n\n} // namespace\
    \ kk2\n\n#endif // MATRIX_MATRIX_FIELD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix_field.hpp
  requiredBy: []
  timestamp: '2024-10-01 04:13:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix_field.hpp
layout: document
redirect_from:
- /library/matrix/matrix_field.hpp
- /library/matrix/matrix_field.hpp.html
title: matrix/matrix_field.hpp
---
