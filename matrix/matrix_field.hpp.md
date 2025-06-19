---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: matrix/basis.hpp
    title: "\u30D9\u30AF\u30C8\u30EB\u304C\u73FE\u5728\u306E\u57FA\u5E95\u3068\u7DDA\
      \u5F62\u72EC\u7ACB\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B"
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
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_product.test.cpp
    title: verify/yosupo_linalg/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_rank.test.cpp
    title: verify/yosupo_linalg/matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
    title: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u884C\u5217"
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATRIX_MATRIX_FIELD_HPP\n#define KK2_MATRIX_MATRIX_FIELD_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <optional>\n#include <string>\n#include <vector>\n\n#include \"../type_traits/io.hpp\"\
    \n\nnamespace kk2 {\n\n/**\n * @brief \u884C\u5217\n *\n * @tparam Field inv\u30E1\
    \u30F3\u30D0\u304C\u5FC5\u8981\n */\ntemplate <class Field> struct MatrixField\
    \ {\n    using value_type = Field;\n    using mat = MatrixField;\n    int _h,\
    \ _w;\n    std::vector<std::vector<Field>> _mat;\n\n    MatrixField() : MatrixField(0)\
    \ {}\n    MatrixField(int n) : MatrixField(n, n) {}\n\n    MatrixField(int h,\
    \ int w) {\n        if (h == 0) {\n            _h = 0;\n            _w = w;\n\
    \        } else {\n            _h = h;\n            _w = w;\n            _mat.resize(h,\
    \ std::vector<Field>(w));\n        }\n    }\n\n    MatrixField(const std::vector<std::vector<Field>>\
    \ &mat_)\n        : _h(mat_.size()),\n          _w(mat_[0].size()),\n        \
    \  _mat(mat_) {}\n\n    static mat unit(int n) {\n        mat res(n, n);\n   \
    \     for (int i = 0; i < n; i++) res[i][i] = Field(1);\n        return res;\n\
    \    }\n\n    inline int get_h() const { return _h; }\n\n    inline int get_w()\
    \ const { return _w; }\n\n    std::vector<Field> &operator[](int i) {\n      \
    \  assert(0 <= i && i < _h);\n        return _mat[i];\n    }\n\n    const std::vector<Field>\
    \ &operator[](int i) const {\n        assert(0 <= i && i < _h);\n        return\
    \ _mat[i];\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\
    \ mat &input(IStream &is) {\n        for (int i = 0; i < _h; i++) {\n        \
    \    for (int j = 0; j < _w; j++) { is >> _mat[i][j]; }\n        }\n        return\
    \ *this;\n    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &os) const {\n        for (int i = 0; i < _h; i++) {\n \
    \           for (int j = 0; j < _w; j++) os << _mat[i][j] << \" \\n\"[j == _w\
    \ - 1];\n        }\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"(h,\
    \ w): \" << \"(\" << _h << \", \" << _w << \"), [\\n\";\n        for (int i =\
    \ 0; i < _h; i++) {\n            os << \"  [ \";\n            for (int j = 0;\
    \ j < _w; j++) os << _mat[i][j] << \" \";\n            os << \"]\\n\";\n     \
    \   }\n        os << \"]\\n\";\n    }\n\n    mat &operator+=(const mat &rhs) {\n\
    \        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int\
    \ i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) { _mat[i][j]\
    \ += rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\n    mat &operator-=(const\
    \ mat &rhs) {\n        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ { _mat[i][j] -= rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\
    \n    mat &operator*=(const mat &rhs) {\n        assert(_w == rhs._h);\n     \
    \   std::vector<std::vector<Field>> res(_h, std::vector<Field>(rhs._w, Field()));\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int k = 0; k < _w; k++)\
    \ {\n                for (int j = 0; j < rhs._w; j++) { res[i][j] += _mat[i][k]\
    \ * rhs._mat[k][j]; }\n            }\n        }\n        _w = rhs._w;\n      \
    \  _mat = std::move(res);\n        return *this;\n    }\n\n    /**\n     * @brief\
    \ \u6383\u304D\u51FA\u3057\n     * @tparam RREF \u884C\u7C21\u7D04\u5316\u884C\
    \u5217\u306B\u3059\u308B\u304B\u3069\u3046\u304B\n     * @tparam EARLY_TERMINATE\
    \ \u30D5\u30EB\u30E9\u30F3\u30AF\u3067\u306A\u3044\u3053\u3068\u304C\u78BA\u5B9A\
    \u3057\u305F\u3068\u304D\u306B\u5373\u6253\u3061\u5207\u308B\u304B\u3069\u3046\
    \u304B\n     * @param wr \u5217\u304C[0, wr)\u306E\u7BC4\u56F2\u3060\u3051\u3067\
    \u6383\u304D\u51FA\u3059\uFF0E\u6307\u5B9A\u304C\u306A\u3044\u306A\u3089\u5168\
    \u4F53\u3067\u6383\u304D\u51FA\u3059\uFF0E\n     * @return \u30E9\u30F3\u30AF\u3068\
    \u884C\u5217\u5F0F\u3092\u8FD4\u3059\uFF0E\n     */\n    template <bool RREF =\
    \ true, bool EARLY_TERMINATE = false>\n    std::pair<int, Field> sweep(int wr\
    \ = -1) {\n        if (wr == -1) wr = _w;\n        int r = 0;\n        Field det\
    \ = 1;\n        for (int i = 0; i < wr; ++i) {\n            if (r >= _h) break;\n\
    \            int pivot = r;\n            while (pivot < _h and _mat[pivot][i]\
    \ == Field(0)) ++pivot;\n            if (pivot == _h) {\n                if constexpr\
    \ (EARLY_TERMINATE) return {-1, Field(0)};\n                det = 0;\n       \
    \         continue;\n            }\n            if (r != pivot) {\n          \
    \      det = -det;\n                std::swap(_mat[r], _mat[pivot]);\n       \
    \     }\n            det *= _mat[r][i];\n            Field inv = _mat[r][i].inv();\n\
    \            for (int j = i; j < wr; ++j) _mat[r][j] *= inv;\n            for\
    \ (int j = RREF ? 0 : r + 1; j < _h; ++j) {\n                if (j == r) continue;\n\
    \                Field a = _mat[j][i];\n                if (a == Field(0)) continue;\n\
    \                for (int k = i; k < wr; ++k) { _mat[j][k] -= _mat[r][k] * a;\
    \ }\n            }\n            r++;\n        }\n        return {r, det};\n  \
    \  }\n\n    mat &to_upper_Hessenberg() {\n        assert(_h == _w);\n        int\
    \ n = _h;\n        for (int i = 0; i < n - 1; ++i) {\n            int pivot =\
    \ i + 1;\n            while (pivot < n and _mat[pivot][i] == Field(0)) ++pivot;\n\
    \            if (pivot == n) continue;\n            if (pivot != i + 1) {\n  \
    \              std::swap(_mat[pivot], _mat[i + 1]);\n                for (int\
    \ j = 0; j < n; ++j) std::swap(_mat[j][i + 1], _mat[j][pivot]);\n            }\n\
    \            if (_mat[i + 1][i] != Field(1)) {\n                Field a = _mat[i\
    \ + 1][i], iv = a.inv();\n                for (int j = i; j < n; ++j) _mat[i +\
    \ 1][j] *= iv;\n                for (int j = 0; j < n; ++j) _mat[j][i + 1] *=\
    \ a;\n            }\n            for (int j = i + 2; j < n; ++j) {\n         \
    \       Field a = _mat[j][i];\n                if (a == Field(0)) continue;\n\
    \                for (int k = i; k < n; ++k) _mat[j][k] -= _mat[i + 1][k] * a;\n\
    \                for (int k = 0; k < n; ++k) _mat[k][i + 1] += _mat[k][j] * a;\n\
    \            }\n        }\n        return *this;\n    }\n\n    Field det() const\
    \ {\n        assert(_h == _w);\n        return mat(*this).sweep<false, true>().second;\n\
    \    }\n\n    std::optional<mat> inv() const {\n        assert(_h == _w);\n  \
    \      int n = _h;\n        mat res(*this);\n        res.inplace_combine_right(mat::unit(n));\n\
    \        int r = res.sweep<true, true>().first;\n        if (r != n) return std::nullopt;\n\
    \        for (int i = 0; i < n; i++) res._mat[i].erase(res[i].begin(), res[i].begin()\
    \ + n);\n        res._w = n;\n        return res;\n    }\n\n    int rank() const\
    \ { return mat(*this).sweep<false, false>().first; }\n\n    mat &shrink() {\n\
    \        while (_h and _mat.back() == std::vector<Field>(_w, Field())) _mat.pop_back(),\
    \ _h--;\n        return *this;\n    }\n\n    template <class T> mat pow(T n) const\
    \ {\n        assert(_h == _w);\n        assert(n >= 0);\n        mat mul(_mat),\
    \ res = mat::unit(_h);\n        while (n) {\n            if (n & 1) res *= mul;\n\
    \            if (n >>= 1) mul *= mul;\n        }\n        return res;\n    }\n\
    \n    std::optional<mat> solve(const mat &b) const {\n        assert(_h == b._h);\n\
    \        assert(b._w == 1);\n        mat ab = combine_right(b);\n        int r\
    \ = ab.sweep<true, false>().first;\n        if ([&]() {\n                if (!r)\
    \ return false;\n                for (int i = 0; i < _w; i++)\n              \
    \      if (ab[r - 1][i] != Field()) return false;\n                return true;\n\
    \            }()) {\n            return std::nullopt;\n        }\n        mat\
    \ res(1 + _w - r, _w);\n        std::vector<int> idx(_w, -1), step(r, -1);\n \
    \       for (int i = 0, j = 0, now = 0; j < _w; j++) {\n            if (i == r\
    \ or ab[i][j] == Field(0)) idx[j] = now, res[1 + now++][j] = 1;\n            else\
    \ res[0][j] = ab[i].back(), step[i++] = j;\n        }\n        for (int i = 0;\
    \ i < r; i++) {\n            for (int j = 0; j < _w; j++) {\n                if\
    \ (idx[j] != -1) res[idx[j] + 1][step[i]] = -ab[i][j];\n            }\n      \
    \  }\n        return res;\n    }\n\n    mat &inplace_combine_top(const mat &rhs)\
    \ {\n        assert(_w == rhs._w);\n        _mat.insert(_mat.begin(), rhs._mat.begin(),\
    \ rhs._mat.end());\n        _h += rhs._h;\n        return *this;\n    }\n\n  \
    \  mat &inplace_combine_bottom(const mat &rhs) {\n        assert(_w == rhs._w);\n\
    \        _mat.insert(_mat.end(), rhs._mat.begin(), rhs._mat.end());\n        _h\
    \ += rhs._h;\n        return *this;\n    }\n\n    mat &inplace_combine_left(const\
    \ mat &rhs) {\n        assert(_h == rhs._h);\n        for (int i = 0; i < _h;\
    \ i++) _mat[i].insert(_mat[i].begin(), rhs[i].begin(), rhs[i].end());\n      \
    \  _w += rhs._w;\n        return *this;\n    }\n\n    mat &inplace_combine_right(const\
    \ mat &rhs) {\n        assert(_h == rhs._h);\n        for (int i = 0; i < _h;\
    \ i++) _mat[i].insert(_mat[i].end(), rhs[i].begin(), rhs[i].end());\n        _w\
    \ += rhs._w;\n        return *this;\n    }\n\n    mat transpose() const {\n  \
    \      mat res(_w, _h);\n        for (int i = 0; i < _h; i++) {\n            for\
    \ (int j = 0; j < _w; j++) { res[j][i] = _mat[i][j]; }\n        }\n        return\
    \ res;\n    }\n\n    mat combine_top(const mat &rhs) const { return mat(*this).inplace_combine_top(rhs);\
    \ }\n    mat combine_bottom(const mat &rhs) const { return mat(*this).inplace_combine_bottom(rhs);\
    \ }\n    mat combine_left(const mat &rhs) const { return mat(*this).inplace_combine_left(rhs);\
    \ }\n    mat combine_right(const mat &rhs) const { return mat(*this).inplace_combine_right(rhs);\
    \ }\n    mat &inplace_transpose() { return *this = transpose(); }\n    friend\
    \ mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) += rhs; }\n\
    \    friend mat operator-(const mat &lhs, const mat &rhs) { return mat(lhs) -=\
    \ rhs; }\n    friend mat operator*(const mat &lhs, const mat &rhs) { return mat(lhs)\
    \ *= rhs; }\n    friend bool operator==(const mat &lhs, const mat &rhs) { return\
    \ lhs._mat == rhs._mat; }\n    friend bool operator!=(const mat &lhs, const mat\
    \ &rhs) { return lhs._mat != rhs._mat; }\n};\n\n} // namespace kk2\n\n#endif //\
    \ KK2_MATRIX_MATRIX_FIELD_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: matrix/matrix_field.hpp
  requiredBy:
  - matrix/frobenius_form.hpp
  - matrix/basis.hpp
  timestamp: '2025-06-06 17:43:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_linalg/matrix_product.test.cpp
  - verify/yosupo_linalg/matrix_rank.test.cpp
  - verify/yosupo_linalg/matrix_inv.test.cpp
  - verify/yosupo_linalg/matrix_det.test.cpp
  - verify/yosupo_linalg/matrix_pow.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations.test.cpp
documentation_of: matrix/matrix_field.hpp
layout: document
redirect_from:
- /library/matrix/matrix_field.hpp
- /library/matrix/matrix_field.hpp.html
title: "\u884C\u5217"
---
