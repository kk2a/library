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
  bundledCode: "#line 1 \"matrix/matrix.hpp\"\n\n\n\ntemplate <class Field>\nstruct\
    \ matrix {\n    using mat = matrix;\n    matrix() : matrix(0) {}\n    matrix(int\
    \ n) : matrix(n, n) {}\n    matrix(int h, int w) : matrix(vector<vector<Field>>(h,\
    \ vector<Field>(w, Field()))) {}\n    matrix(const vector<vector<Field>>& mat)\
    \ : _h(mat.size()), _w(mat[0].size()), mat_(mat) {}\n    \n    int get_h() const\
    \ { return _h; }\n    int get_w() const { return _w; }\n\n    Field at(int i,\
    \ int j) const {\n        assert(0 <= i && i < _h);\n        assert(0 <= j &&\
    \ j < _w);\n        return mat_[i][j];\n    }\n\n    void display() const {\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ cout << mat_[i][j] << \" \";\n            cout << endl;\n        }\n    }\n\n\
    \    void set(int i, int j, Field x) {\n        assert(0 <= i && i < _h);\n  \
    \      assert(0 <= j && j < _w);\n        mat_[i][j] = x;\n    }\n\n    mat& operator+=(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ {\n                mat_[i][j] += rhs.mat_[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n    mat& operator-=(const mat& rhs) {\n       \
    \ assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int i = 0;\
    \ i < _h; i++) {\n            for (int j = 0; j < _w; j++) {\n               \
    \ mat_[i][j] -= rhs.mat_[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n    mat& operator*=(const mat& rhs) {\n        assert(_w == rhs._h);\n\
    \        vector<vector<Field>> res(_h, vector<Field>(rhs._w, Field()));\n    \
    \    for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < rhs._w; j++)\
    \ {\n                for (int k = 0; k < _w; k++) {\n                    res[i][j]\
    \ += mat_[i][k] * rhs.mat_[k][j];\n                }\n            }\n        }\n\
    \        _w = rhs._w;\n        mat_ = res;\n        return *this;\n    }\n\n \
    \   Field det(Field product_e) const {\n        assert(_h == _w);\n        int\
    \ n = _h;\n        vector<vector<Field>> a(mat_);\n        Field res = 1;\n  \
    \      for (int i = 0; i < n; i++) {\n            int pivot = -1;\n          \
    \  for (int j = i; j < n; j++) {\n                if (a[j][i] != 0) {\n      \
    \              pivot = j;\n                    break;\n                }\n   \
    \         }\n            if (pivot == -1) return Field();\n            if (i !=\
    \ pivot) {\n                swap(a[i], a[pivot]);\n                res = -res;\n\
    \            }\n            res *= a[i][i];\n            Field inv = product_e\
    \ / a[i][i];\n            for (int j = i + 1; j < n; j++) {\n                a[i][j]\
    \ *= inv;\n            }\n            for (int j = 0; j < n; j++) {\n        \
    \        if (i == j) continue;\n                Field r = a[j][i];\n         \
    \       for (int k = i; k < n; k++) {\n                    a[j][k] -= a[i][k]\
    \ * r;\n                }\n            }\n        }\n        return res;\n   \
    \ }\n\n    mat inv(Field product_e) const {\n        assert(_h == _w);\n     \
    \   int n = _h;\n        vector<vector<Field>> res(n, vector<Field>(n, Field()));\n\
    \        for (int i = 0; i < n; i++) res[i][i] = 1;\n        mat a(mat_);\n  \
    \      for (int i = 0; i < n; i++) {\n            int pivot = -1;\n          \
    \  for (int j = i; j < n; j++) {\n                if (a.mat_[j][i] != 0) {\n \
    \                   pivot = j;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) {\n                return mat(n);\n\
    \            }\n            swap(a.mat_[i], a.mat_[pivot]);\n            swap(res[i],\
    \ res[pivot]);\n            Field inv = product_e / a.mat_[i][i];\n          \
    \  for (int j = 0; j < n; j++) {\n                a.mat_[i][j] *= inv;\n     \
    \           res[i][j] *= inv;\n            }\n            for (int j = 0; j <\
    \ n; j++) {\n                if (i == j) continue;\n                Field r =\
    \ a.mat_[j][i];\n                for (int k = 0; k < n; k++) {\n             \
    \       a.mat_[j][k] -= a.mat_[i][k] * r;\n                    res[j][k] -= res[i][k]\
    \ * r;\n                }\n            }\n        }\n        return mat(res);\n\
    \    }\n\n    template <class T>\n    mat pow(T n) const {\n        assert(_h\
    \ == _w);\n        mat x(mat_);\n        mat res(_h);\n        for (int i = 0;\
    \ i < _h; i++) res.mat_[i][i] = 1;\n        for (int i = 1; i <= n; i <<= 1) {\n\
    \            if (n & i) res *= x;\n            x *= x;\n        }\n        return\
    \ res;\n    }\n\n    friend mat operator+(const mat& lhs, const mat& rhs) {\n\
    \        return mat(lhs) += rhs;\n    }\n    friend mat operator-(const mat& lhs,\
    \ const mat& rhs) {\n        return mat(lhs) -= rhs;\n    }\n    friend mat operator*(const\
    \ mat& lhs, const mat& rhs) {\n        return mat(lhs) *= rhs;\n    }\n    friend\
    \ bool operator==(const mat& lhs, const mat& rhs) {\n        return lhs.mat_ ==\
    \ rhs.mat_;\n    }\n    friend bool operator!=(const mat& lhs, const mat& rhs)\
    \ {\n        return lhs.mat_ != rhs.mat_;\n    }\n\n\n  private:\n    int _h,\
    \ _w;\n    vector<vector<Field>> mat_;\n};\n\n\n"
  code: "#ifndef MATRIX_HPP\n#define MATRIX_HPP 1\n\ntemplate <class Field>\nstruct\
    \ matrix {\n    using mat = matrix;\n    matrix() : matrix(0) {}\n    matrix(int\
    \ n) : matrix(n, n) {}\n    matrix(int h, int w) : matrix(vector<vector<Field>>(h,\
    \ vector<Field>(w, Field()))) {}\n    matrix(const vector<vector<Field>>& mat)\
    \ : _h(mat.size()), _w(mat[0].size()), mat_(mat) {}\n    \n    int get_h() const\
    \ { return _h; }\n    int get_w() const { return _w; }\n\n    Field at(int i,\
    \ int j) const {\n        assert(0 <= i && i < _h);\n        assert(0 <= j &&\
    \ j < _w);\n        return mat_[i][j];\n    }\n\n    void display() const {\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ cout << mat_[i][j] << \" \";\n            cout << endl;\n        }\n    }\n\n\
    \    void set(int i, int j, Field x) {\n        assert(0 <= i && i < _h);\n  \
    \      assert(0 <= j && j < _w);\n        mat_[i][j] = x;\n    }\n\n    mat& operator+=(const\
    \ mat& rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ {\n                mat_[i][j] += rhs.mat_[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n    mat& operator-=(const mat& rhs) {\n       \
    \ assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int i = 0;\
    \ i < _h; i++) {\n            for (int j = 0; j < _w; j++) {\n               \
    \ mat_[i][j] -= rhs.mat_[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n    mat& operator*=(const mat& rhs) {\n        assert(_w == rhs._h);\n\
    \        vector<vector<Field>> res(_h, vector<Field>(rhs._w, Field()));\n    \
    \    for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < rhs._w; j++)\
    \ {\n                for (int k = 0; k < _w; k++) {\n                    res[i][j]\
    \ += mat_[i][k] * rhs.mat_[k][j];\n                }\n            }\n        }\n\
    \        _w = rhs._w;\n        mat_ = res;\n        return *this;\n    }\n\n \
    \   Field det(Field product_e) const {\n        assert(_h == _w);\n        int\
    \ n = _h;\n        vector<vector<Field>> a(mat_);\n        Field res = 1;\n  \
    \      for (int i = 0; i < n; i++) {\n            int pivot = -1;\n          \
    \  for (int j = i; j < n; j++) {\n                if (a[j][i] != 0) {\n      \
    \              pivot = j;\n                    break;\n                }\n   \
    \         }\n            if (pivot == -1) return Field();\n            if (i !=\
    \ pivot) {\n                swap(a[i], a[pivot]);\n                res = -res;\n\
    \            }\n            res *= a[i][i];\n            Field inv = product_e\
    \ / a[i][i];\n            for (int j = i + 1; j < n; j++) {\n                a[i][j]\
    \ *= inv;\n            }\n            for (int j = 0; j < n; j++) {\n        \
    \        if (i == j) continue;\n                Field r = a[j][i];\n         \
    \       for (int k = i; k < n; k++) {\n                    a[j][k] -= a[i][k]\
    \ * r;\n                }\n            }\n        }\n        return res;\n   \
    \ }\n\n    mat inv(Field product_e) const {\n        assert(_h == _w);\n     \
    \   int n = _h;\n        vector<vector<Field>> res(n, vector<Field>(n, Field()));\n\
    \        for (int i = 0; i < n; i++) res[i][i] = 1;\n        mat a(mat_);\n  \
    \      for (int i = 0; i < n; i++) {\n            int pivot = -1;\n          \
    \  for (int j = i; j < n; j++) {\n                if (a.mat_[j][i] != 0) {\n \
    \                   pivot = j;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) {\n                return mat(n);\n\
    \            }\n            swap(a.mat_[i], a.mat_[pivot]);\n            swap(res[i],\
    \ res[pivot]);\n            Field inv = product_e / a.mat_[i][i];\n          \
    \  for (int j = 0; j < n; j++) {\n                a.mat_[i][j] *= inv;\n     \
    \           res[i][j] *= inv;\n            }\n            for (int j = 0; j <\
    \ n; j++) {\n                if (i == j) continue;\n                Field r =\
    \ a.mat_[j][i];\n                for (int k = 0; k < n; k++) {\n             \
    \       a.mat_[j][k] -= a.mat_[i][k] * r;\n                    res[j][k] -= res[i][k]\
    \ * r;\n                }\n            }\n        }\n        return mat(res);\n\
    \    }\n\n    template <class T>\n    mat pow(T n) const {\n        assert(_h\
    \ == _w);\n        mat x(mat_);\n        mat res(_h);\n        for (int i = 0;\
    \ i < _h; i++) res.mat_[i][i] = 1;\n        for (int i = 1; i <= n; i <<= 1) {\n\
    \            if (n & i) res *= x;\n            x *= x;\n        }\n        return\
    \ res;\n    }\n\n    friend mat operator+(const mat& lhs, const mat& rhs) {\n\
    \        return mat(lhs) += rhs;\n    }\n    friend mat operator-(const mat& lhs,\
    \ const mat& rhs) {\n        return mat(lhs) -= rhs;\n    }\n    friend mat operator*(const\
    \ mat& lhs, const mat& rhs) {\n        return mat(lhs) *= rhs;\n    }\n    friend\
    \ bool operator==(const mat& lhs, const mat& rhs) {\n        return lhs.mat_ ==\
    \ rhs.mat_;\n    }\n    friend bool operator!=(const mat& lhs, const mat& rhs)\
    \ {\n        return lhs.mat_ != rhs.mat_;\n    }\n\n\n  private:\n    int _h,\
    \ _w;\n    vector<vector<Field>> mat_;\n};\n\n#endif // MATRIX_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix.hpp
  requiredBy: []
  timestamp: '2024-05-03 16:15:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix.hpp
layout: document
redirect_from:
- /library/matrix/matrix.hpp
- /library/matrix/matrix.hpp.html
title: matrix/matrix.hpp
---
