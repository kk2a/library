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
  bundledCode: "#line 1 \"matrix/matrix_field.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate\
    \ <class Field>\nstruct MatrixField {\n    using mat = MatrixField;\n    MatrixField()\
    \ : MatrixField(0) {}\n    MatrixField(int n) : MatrixField(n, n) {}\n    MatrixField(int\
    \ h, int w) : MatrixField(vector<vector<Field>>(h, vector<Field>(w, Field())))\
    \ {}\n    MatrixField(const vector<vector<Field>>& mat_) : _h(mat_.size()), _w(mat_[0].size()),\
    \ _mat(mat_) {}\n    \n    int get_h() const { return _h; }\n    int get_w() const\
    \ { return _w; }\n\n    Field at(int i, int j) const {\n        assert(0 <= i\
    \ && i < _h);\n        assert(0 <= j && j < _w);\n        return _mat[i][j];\n\
    \    }\n\n    vector<vector<Field>> get_mat() const {\n        return _mat;\n\
    \    }\n\n    vector<Field>& operator[](int i) {\n        assert(0 <= i && i <\
    \ _h);\n        return _mat[i];\n    }\n\n    void display() const {\n       \
    \ for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) cout\
    \ << _mat[i][j] << \" \";\n            cout << \"\\n\";\n        }\n    }\n\n\
    \    void set(int i, int j, Field x) {\n        assert(0 <= i && i < _h);\n  \
    \      assert(0 <= j && j < _w);\n        _mat[i][j] = x;\n    }\n\n    mat& operator+=(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ {\n                _mat[i][j] += rhs._mat[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n    mat& operator-=(const mat& rhs) {\n       \
    \ assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int i = 0;\
    \ i < _h; i++) {\n            for (int j = 0; j < _w; j++) {\n               \
    \ _mat[i][j] -= rhs._mat[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n    mat& operator*=(const mat& rhs) {\n        assert(_w == rhs._h);\n\
    \        vector<vector<Field>> res(_h, vector<Field>(rhs._w, Field()));\n    \
    \    for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < rhs._w; j++)\
    \ {\n                for (int k = 0; k < _w; k++) {\n                    res[i][j]\
    \ += _mat[i][k] * rhs._mat[k][j];\n                }\n            }\n        }\n\
    \        _w = rhs._w;\n        _mat.swap(res);\n        return *this;\n    }\n\
    \n    Field det(Field product_e = Field(1)) const {\n        assert(_h == _w);\n\
    \        int n = _h;\n        vector<vector<Field>> a(_mat);\n        Field res\
    \ = 1;\n        for (int i = 0; i < n; i++) {\n            int pivot = -1;\n \
    \           for (int j = i; j < n; j++) {\n                if (a[j][i] != 0) {\n\
    \                    pivot = j;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) return Field(0);\n            if\
    \ (i != pivot) {\n                swap(a[i], a[pivot]);\n                res =\
    \ -res;\n            }\n            res *= a[i][i];\n            Field inv = product_e\
    \ / a[i][i];\n            for (int j = i + 1; j < n; j++) {\n                a[i][j]\
    \ *= inv;\n            }\n            for (int j = 0; j < n; j++) {\n        \
    \        if (i == j) continue;\n                Field r = a[j][i];\n         \
    \       for (int k = i; k < n; k++) {\n                    a[j][k] -= a[i][k]\
    \ * r;\n                }\n            }\n        }\n        return res;\n   \
    \ }\n\n    mat inv(Field product_e = Field(1)) const {\n        assert(_h == _w);\n\
    \        int n = _h;\n        vector<vector<Field>> res(n, vector<Field>(n, Field()));\n\
    \        for (int i = 0; i < n; i++) res[i][i] = 1;\n        mat a(_mat);\n  \
    \      for (int i = 0; i < n; i++) {\n            int pivot = -1;\n          \
    \  for (int j = i; j < n; j++) {\n                if (a._mat[j][i] != 0) {\n \
    \                   pivot = j;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) {\n                return mat(n);\n\
    \            }\n            swap(a._mat[i], a._mat[pivot]);\n            swap(res[i],\
    \ res[pivot]);\n            Field inv = product_e / a._mat[i][i];\n          \
    \  for (int j = 0; j < n; j++) {\n                a._mat[i][j] *= inv;\n     \
    \           res[i][j] *= inv;\n            }\n            for (int j = 0; j <\
    \ n; j++) {\n                if (i == j) continue;\n                Field r =\
    \ a._mat[j][i];\n                for (int k = 0; k < n; k++) {\n             \
    \       a._mat[j][k] -= a._mat[i][k] * r;\n                    res[j][k] -= res[i][k]\
    \ * r;\n                }\n            }\n        }\n        return mat(res);\n\
    \    }\n\n    template <class T>\n    mat pow(T n) const {\n        assert(_h\
    \ == _w);\n        mat mul(_mat);\n        mat res(_h);\n        for (int i =\
    \ 0; i < _h; i++) res._mat[i][i] = 1;\n        while (n) {\n            if (n\
    \ & 1) res *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return res;\n    }\n\n    int rank(Field product_e = Field(1)) const\
    \ {\n        int n = _h, m = _w;\n        vector<vector<Field>> a(_mat);\n   \
    \     int res = 0;\n        for (int i = 0; i < m; i++) {\n            int pivot\
    \ = -1;\n            for (int j = res; j < n; j++) {\n                if (a[j][i]\
    \ != 0) {\n                    pivot = j;\n                    break;\n      \
    \          }\n            }\n            if (pivot == -1) continue;\n        \
    \    swap(a[res], a[pivot]);\n            Field inv = product_e / a[res][i];\n\
    \            for (int j = i; j < m; j++) {\n                a[res][j] *= inv;\n\
    \            }\n            for (int j = res + 1; j < n; j++) {\n            \
    \    Field r = a[j][i];\n                for (int k = i; k < m; k++) {\n     \
    \               a[j][k] -= a[res][k] * r;\n                }\n            }\n\
    \            res++;\n        }\n        return res;\n    }\n\n    mat& inplace_combine_top(const\
    \ mat& rhs) {\n        assert(_w == rhs._w);\n        this->_mat.insert(begin(this->_mat),\n\
    \            begin(rhs._mat), end(rhs._mat));\n        this->_h += rhs._h;\n \
    \       return *this;\n    }\n\n    mat combine_top(const mat& rhs) const {\n\
    \        assert(_w == rhs._w);\n        mat res(this->_mat);\n        return res.inplace_combine_top(rhs);\n\
    \    }\n\n    mat& inplace_combine_bottom(const mat& rhs) {\n        assert(_w\
    \ == rhs._w);\n        this->_mat.insert(end(this->_mat),\n            begin(rhs._mat),\
    \ end(rhs._mat));\n        this->_h += rhs._h;\n        return *this;\n    }\n\
    \n    mat combine_bottom(const mat& rhs) const {\n        assert(_w == rhs._w);\n\
    \        mat res(this->_mat);\n        return res.inplace_combine_bottom(rhs);\n\
    \    }\n\n    mat& inplace_combine_left(const mat& rhs) {\n        assert(_h ==\
    \ rhs._h);\n        for (int i = 0; i < _h; i++) {\n            this->_mat[i].insert(begin(this->_mat[i]),\n\
    \                begin(rhs._mat[i]), end(rhs._mat[i]));\n        }\n        this->_w\
    \ += rhs._w;\n        return *this;\n    }\n\n    mat combine_left(const mat&\
    \ rhs) const {\n        assert(_h == rhs._h);\n        mat res(this->_mat);\n\
    \        return res.inplace_combine_left(rhs);\n    }\n\n    mat& inplace_combine_right(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        for (int i = 0; i < _h;\
    \ i++) {\n            this->_mat[i].insert(end(this->_mat[i]),\n             \
    \   begin(rhs._mat[i]), end(rhs._mat[i]));\n        }\n        this->_w += rhs._w;\n\
    \        return *this;\n    }\n\n    mat combine_right(const mat& rhs) const {\n\
    \        assert(_h == rhs._h);\n        mat res(this->_mat);\n        return res.inplace_combine_right(rhs);\n\
    \    }\n\n    friend mat operator+(const mat& lhs, const mat& rhs) {\n       \
    \ return mat(lhs) += rhs;\n    }\n    friend mat operator-(const mat& lhs, const\
    \ mat& rhs) {\n        return mat(lhs) -= rhs;\n    }\n    friend mat operator*(const\
    \ mat& lhs, const mat& rhs) {\n        return mat(lhs) *= rhs;\n    }\n    friend\
    \ bool operator==(const mat& lhs, const mat& rhs) {\n        return lhs._mat ==\
    \ rhs._mat;\n    }\n    friend bool operator!=(const mat& lhs, const mat& rhs)\
    \ {\n        return lhs._mat != rhs._mat;\n    }\n\n\n  private:\n    int _h,\
    \ _w;\n    vector<vector<Field>> _mat;\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATRIX_HPP\n#define MATRIX_HPP 1\n\nnamespace kk2 {\n\ntemplate <class\
    \ Field>\nstruct MatrixField {\n    using mat = MatrixField;\n    MatrixField()\
    \ : MatrixField(0) {}\n    MatrixField(int n) : MatrixField(n, n) {}\n    MatrixField(int\
    \ h, int w) : MatrixField(vector<vector<Field>>(h, vector<Field>(w, Field())))\
    \ {}\n    MatrixField(const vector<vector<Field>>& mat_) : _h(mat_.size()), _w(mat_[0].size()),\
    \ _mat(mat_) {}\n    \n    int get_h() const { return _h; }\n    int get_w() const\
    \ { return _w; }\n\n    Field at(int i, int j) const {\n        assert(0 <= i\
    \ && i < _h);\n        assert(0 <= j && j < _w);\n        return _mat[i][j];\n\
    \    }\n\n    vector<vector<Field>> get_mat() const {\n        return _mat;\n\
    \    }\n\n    vector<Field>& operator[](int i) {\n        assert(0 <= i && i <\
    \ _h);\n        return _mat[i];\n    }\n\n    void display() const {\n       \
    \ for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) cout\
    \ << _mat[i][j] << \" \";\n            cout << \"\\n\";\n        }\n    }\n\n\
    \    void set(int i, int j, Field x) {\n        assert(0 <= i && i < _h);\n  \
    \      assert(0 <= j && j < _w);\n        _mat[i][j] = x;\n    }\n\n    mat& operator+=(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ {\n                _mat[i][j] += rhs._mat[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n    mat& operator-=(const mat& rhs) {\n       \
    \ assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int i = 0;\
    \ i < _h; i++) {\n            for (int j = 0; j < _w; j++) {\n               \
    \ _mat[i][j] -= rhs._mat[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n    mat& operator*=(const mat& rhs) {\n        assert(_w == rhs._h);\n\
    \        vector<vector<Field>> res(_h, vector<Field>(rhs._w, Field()));\n    \
    \    for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < rhs._w; j++)\
    \ {\n                for (int k = 0; k < _w; k++) {\n                    res[i][j]\
    \ += _mat[i][k] * rhs._mat[k][j];\n                }\n            }\n        }\n\
    \        _w = rhs._w;\n        _mat.swap(res);\n        return *this;\n    }\n\
    \n    Field det(Field product_e = Field(1)) const {\n        assert(_h == _w);\n\
    \        int n = _h;\n        vector<vector<Field>> a(_mat);\n        Field res\
    \ = 1;\n        for (int i = 0; i < n; i++) {\n            int pivot = -1;\n \
    \           for (int j = i; j < n; j++) {\n                if (a[j][i] != 0) {\n\
    \                    pivot = j;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) return Field(0);\n            if\
    \ (i != pivot) {\n                swap(a[i], a[pivot]);\n                res =\
    \ -res;\n            }\n            res *= a[i][i];\n            Field inv = product_e\
    \ / a[i][i];\n            for (int j = i + 1; j < n; j++) {\n                a[i][j]\
    \ *= inv;\n            }\n            for (int j = 0; j < n; j++) {\n        \
    \        if (i == j) continue;\n                Field r = a[j][i];\n         \
    \       for (int k = i; k < n; k++) {\n                    a[j][k] -= a[i][k]\
    \ * r;\n                }\n            }\n        }\n        return res;\n   \
    \ }\n\n    mat inv(Field product_e = Field(1)) const {\n        assert(_h == _w);\n\
    \        int n = _h;\n        vector<vector<Field>> res(n, vector<Field>(n, Field()));\n\
    \        for (int i = 0; i < n; i++) res[i][i] = 1;\n        mat a(_mat);\n  \
    \      for (int i = 0; i < n; i++) {\n            int pivot = -1;\n          \
    \  for (int j = i; j < n; j++) {\n                if (a._mat[j][i] != 0) {\n \
    \                   pivot = j;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) {\n                return mat(n);\n\
    \            }\n            swap(a._mat[i], a._mat[pivot]);\n            swap(res[i],\
    \ res[pivot]);\n            Field inv = product_e / a._mat[i][i];\n          \
    \  for (int j = 0; j < n; j++) {\n                a._mat[i][j] *= inv;\n     \
    \           res[i][j] *= inv;\n            }\n            for (int j = 0; j <\
    \ n; j++) {\n                if (i == j) continue;\n                Field r =\
    \ a._mat[j][i];\n                for (int k = 0; k < n; k++) {\n             \
    \       a._mat[j][k] -= a._mat[i][k] * r;\n                    res[j][k] -= res[i][k]\
    \ * r;\n                }\n            }\n        }\n        return mat(res);\n\
    \    }\n\n    template <class T>\n    mat pow(T n) const {\n        assert(_h\
    \ == _w);\n        mat mul(_mat);\n        mat res(_h);\n        for (int i =\
    \ 0; i < _h; i++) res._mat[i][i] = 1;\n        while (n) {\n            if (n\
    \ & 1) res *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return res;\n    }\n\n    int rank(Field product_e = Field(1)) const\
    \ {\n        int n = _h, m = _w;\n        vector<vector<Field>> a(_mat);\n   \
    \     int res = 0;\n        for (int i = 0; i < m; i++) {\n            int pivot\
    \ = -1;\n            for (int j = res; j < n; j++) {\n                if (a[j][i]\
    \ != 0) {\n                    pivot = j;\n                    break;\n      \
    \          }\n            }\n            if (pivot == -1) continue;\n        \
    \    swap(a[res], a[pivot]);\n            Field inv = product_e / a[res][i];\n\
    \            for (int j = i; j < m; j++) {\n                a[res][j] *= inv;\n\
    \            }\n            for (int j = res + 1; j < n; j++) {\n            \
    \    Field r = a[j][i];\n                for (int k = i; k < m; k++) {\n     \
    \               a[j][k] -= a[res][k] * r;\n                }\n            }\n\
    \            res++;\n        }\n        return res;\n    }\n\n    mat& inplace_combine_top(const\
    \ mat& rhs) {\n        assert(_w == rhs._w);\n        this->_mat.insert(begin(this->_mat),\n\
    \            begin(rhs._mat), end(rhs._mat));\n        this->_h += rhs._h;\n \
    \       return *this;\n    }\n\n    mat combine_top(const mat& rhs) const {\n\
    \        assert(_w == rhs._w);\n        mat res(this->_mat);\n        return res.inplace_combine_top(rhs);\n\
    \    }\n\n    mat& inplace_combine_bottom(const mat& rhs) {\n        assert(_w\
    \ == rhs._w);\n        this->_mat.insert(end(this->_mat),\n            begin(rhs._mat),\
    \ end(rhs._mat));\n        this->_h += rhs._h;\n        return *this;\n    }\n\
    \n    mat combine_bottom(const mat& rhs) const {\n        assert(_w == rhs._w);\n\
    \        mat res(this->_mat);\n        return res.inplace_combine_bottom(rhs);\n\
    \    }\n\n    mat& inplace_combine_left(const mat& rhs) {\n        assert(_h ==\
    \ rhs._h);\n        for (int i = 0; i < _h; i++) {\n            this->_mat[i].insert(begin(this->_mat[i]),\n\
    \                begin(rhs._mat[i]), end(rhs._mat[i]));\n        }\n        this->_w\
    \ += rhs._w;\n        return *this;\n    }\n\n    mat combine_left(const mat&\
    \ rhs) const {\n        assert(_h == rhs._h);\n        mat res(this->_mat);\n\
    \        return res.inplace_combine_left(rhs);\n    }\n\n    mat& inplace_combine_right(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        for (int i = 0; i < _h;\
    \ i++) {\n            this->_mat[i].insert(end(this->_mat[i]),\n             \
    \   begin(rhs._mat[i]), end(rhs._mat[i]));\n        }\n        this->_w += rhs._w;\n\
    \        return *this;\n    }\n\n    mat combine_right(const mat& rhs) const {\n\
    \        assert(_h == rhs._h);\n        mat res(this->_mat);\n        return res.inplace_combine_right(rhs);\n\
    \    }\n\n    friend mat operator+(const mat& lhs, const mat& rhs) {\n       \
    \ return mat(lhs) += rhs;\n    }\n    friend mat operator-(const mat& lhs, const\
    \ mat& rhs) {\n        return mat(lhs) -= rhs;\n    }\n    friend mat operator*(const\
    \ mat& lhs, const mat& rhs) {\n        return mat(lhs) *= rhs;\n    }\n    friend\
    \ bool operator==(const mat& lhs, const mat& rhs) {\n        return lhs._mat ==\
    \ rhs._mat;\n    }\n    friend bool operator!=(const mat& lhs, const mat& rhs)\
    \ {\n        return lhs._mat != rhs._mat;\n    }\n\n\n  private:\n    int _h,\
    \ _w;\n    vector<vector<Field>> _mat;\n};\n\n} // namespace kk2\n\n#endif //\
    \ MATRIX_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix_field.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix_field.hpp
layout: document
redirect_from:
- /library/matrix/matrix_field.hpp
- /library/matrix/matrix_field.hpp.html
title: matrix/matrix_field.hpp
---
