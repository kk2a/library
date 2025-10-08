---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: matrix/basis.hpp
    title: "\u30D9\u30AF\u30C8\u30EB\u304C\u73FE\u5728\u306E\u57FA\u5E95\u3068\u7DDA\
      \u5F62\u72EC\u7ACB\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B"
  - icon: ':question:'
    path: matrix/matrix_field.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
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
    \n#include <string>\n#line 10 \"matrix/matrix_field.hpp\"\n\n#line 1 \"type_traits/io.hpp\"\
    \n\n\n\n#include <istream>\n#include <ostream>\n#include <type_traits>\n\nnamespace\
    \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
    \ {};\n\n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
    \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n    \
    \                              || std::is_same<T, std::ifstream>::value,\n   \
    \                           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 12 \"matrix/matrix_field.hpp\"\n\nnamespace kk2 {\n\n/**\n *\
    \ @brief \u884C\u5217\n *\n * @tparam Field inv\u30E1\u30F3\u30D0\u304C\u5FC5\u8981\
    \n */\ntemplate <class Field> struct MatrixField {\n    using value_type = Field;\n\
    \    using mat = MatrixField;\n    int _h, _w;\n    std::vector<std::vector<Field>>\
    \ _mat;\n\n    MatrixField() : MatrixField(0) {}\n    MatrixField(int n) : MatrixField(n,\
    \ n) {}\n\n    MatrixField(int h, int w) {\n        if (h == 0) {\n          \
    \  _h = 0;\n            _w = w;\n        } else {\n            _h = h;\n     \
    \       _w = w;\n            _mat.resize(h, std::vector<Field>(w));\n        }\n\
    \    }\n\n    MatrixField(const std::vector<std::vector<Field>> &mat_)\n     \
    \   : _h(mat_.size()),\n          _w(mat_[0].size()),\n          _mat(mat_) {}\n\
    \n    static mat unit(int n) {\n        mat res(n, n);\n        for (int i = 0;\
    \ i < n; i++) res[i][i] = Field(1);\n        return res;\n    }\n\n    inline\
    \ int get_h() const { return _h; }\n\n    inline int get_w() const { return _w;\
    \ }\n\n    std::vector<Field> &operator[](int i) {\n        assert(0 <= i && i\
    \ < _h);\n        return _mat[i];\n    }\n\n    const std::vector<Field> &operator[](int\
    \ i) const {\n        assert(0 <= i && i < _h);\n        return _mat[i];\n   \
    \ }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr> mat &input(IStream\
    \ &is) {\n        for (int i = 0; i < _h; i++) {\n            for (int j = 0;\
    \ j < _w; j++) { is >> _mat[i][j]; }\n        }\n        return *this;\n    }\n\
    \n    template <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os) const {\n        for (int i = 0; i < _h; i++) {\n            for (int j\
    \ = 0; j < _w; j++) os << _mat[i][j] << \" \\n\"[j == _w - 1];\n        }\n  \
    \  }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    void\
    \ debug_output(OStream &os) const {\n        os << \"(h, w): \" << \"(\" << _h\
    \ << \", \" << _w << \"), [\\n\";\n        for (int i = 0; i < _h; i++) {\n  \
    \          os << \"  [ \";\n            for (int j = 0; j < _w; j++) os << _mat[i][j]\
    \ << \" \";\n            os << \"]\\n\";\n        }\n        os << \"]\\n\";\n\
    \    }\n\n    mat &operator+=(const mat &rhs) {\n        assert(_h == rhs._h);\n\
    \        assert(_w == rhs._w);\n        for (int i = 0; i < _h; i++) {\n     \
    \       for (int j = 0; j < _w; j++) { _mat[i][j] += rhs._mat[i][j]; }\n     \
    \   }\n        return *this;\n    }\n\n    mat &operator-=(const mat &rhs) {\n\
    \        assert(_h == rhs._h);\n        assert(_w == rhs._w);\n        for (int\
    \ i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++) { _mat[i][j]\
    \ -= rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\n    mat &operator*=(const\
    \ mat &rhs) {\n        assert(_w == rhs._h);\n        std::vector<std::vector<Field>>\
    \ res(_h, std::vector<Field>(rhs._w, Field()));\n        for (int i = 0; i < _h;\
    \ i++) {\n            for (int k = 0; k < _w; k++) {\n                for (int\
    \ j = 0; j < rhs._w; j++) { res[i][j] += _mat[i][k] * rhs._mat[k][j]; }\n    \
    \        }\n        }\n        _w = rhs._w;\n        _mat = std::move(res);\n\
    \        return *this;\n    }\n\n    /**\n     * @brief \u6383\u304D\u51FA\u3057\
    \n     * @tparam RREF \u884C\u7C21\u7D04\u5316\u884C\u5217\u306B\u3059\u308B\u304B\
    \u3069\u3046\u304B\n     * @tparam EARLY_TERMINATE \u30D5\u30EB\u30E9\u30F3\u30AF\
    \u3067\u306A\u3044\u3053\u3068\u304C\u78BA\u5B9A\u3057\u305F\u3068\u304D\u306B\
    \u5373\u6253\u3061\u5207\u308B\u304B\u3069\u3046\u304B\n     * @param wr \u5217\
    \u304C[0, wr)\u306E\u7BC4\u56F2\u3060\u3051\u3067\u6383\u304D\u51FA\u3059\uFF0E\
    \u6307\u5B9A\u304C\u306A\u3044\u306A\u3089\u5168\u4F53\u3067\u6383\u304D\u51FA\
    \u3059\uFF0E\n     * @return \u30E9\u30F3\u30AF\u3068\u884C\u5217\u5F0F\u3092\u8FD4\
    \u3059\uFF0E\n     */\n    template <bool RREF = true, bool EARLY_TERMINATE =\
    \ false>\n    std::pair<int, Field> sweep(int wr = -1) {\n        if (wr == -1)\
    \ wr = _w;\n        int r = 0;\n        Field det = 1;\n        for (int i = 0;\
    \ i < wr; ++i) {\n            if (r >= _h) break;\n            int pivot = r;\n\
    \            while (pivot < _h and _mat[pivot][i] == Field(0)) ++pivot;\n    \
    \        if (pivot == _h) {\n                if constexpr (EARLY_TERMINATE) return\
    \ {-1, Field(0)};\n                det = 0;\n                continue;\n     \
    \       }\n            if (r != pivot) {\n                det = -det;\n      \
    \          std::swap(_mat[r], _mat[pivot]);\n            }\n            det *=\
    \ _mat[r][i];\n            Field inv = _mat[r][i].inv();\n            for (int\
    \ j = i; j < wr; ++j) _mat[r][j] *= inv;\n            for (int j = RREF ? 0 :\
    \ r + 1; j < _h; ++j) {\n                if (j == r) continue;\n             \
    \   Field a = _mat[j][i];\n                if (a == Field(0)) continue;\n    \
    \            for (int k = i; k < wr; ++k) { _mat[j][k] -= _mat[r][k] * a; }\n\
    \            }\n            r++;\n        }\n        return {r, det};\n    }\n\
    \n    mat &to_upper_Hessenberg() {\n        assert(_h == _w);\n        int n =\
    \ _h;\n        for (int i = 0; i < n - 1; ++i) {\n            int pivot = i +\
    \ 1;\n            while (pivot < n and _mat[pivot][i] == Field(0)) ++pivot;\n\
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
    \ &rhs) { return lhs._mat != rhs._mat; }\n};\n\n} // namespace kk2\n\n\n#line\
    \ 10 \"matrix/basis.hpp\"\n\nnamespace kk2 {\n\nnamespace linear_algebra {\n\n\
    template <class Matrix, class Field> struct BasisBase {\n    struct RowBasicTransform\
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
    \    std::vector<SnapShot> snaps;\n\n    BasisBase() = default;\n\n    BasisBase(int\
    \ h_) : h(h_), rank(0) {}\n\n    Matrix &sweep(Matrix &vec) const {\n        for\
    \ (auto &&t : hist) t.transform(vec);\n        return vec;\n    }\n\n    /**\n\
    \     * @brief \u30D9\u30AF\u30C8\u30EB\u304C\u73FE\u5728\u306E\u57FA\u5E95\u3068\
    \u7DDA\u5F62\u72EC\u7ACB\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n     * @param vec \u5217\u30D9\u30AF\u30C8\u30EB\n     * @return \u7DDA\u5F62\
    \u72EC\u7ACB\u306A\u3089true\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n\
    \     */\n    bool is_linearly_independent(const Matrix &vec) const {\n      \
    \  assert(vec.get_h() == h);\n        assert(vec.get_w() == 1);\n        if (rank\
    \ == h) return false;\n\n        Matrix tmp(vec);\n        sweep(tmp);\n     \
    \   for (int i = rank; i < h; ++i) {\n            if (tmp[i][0] != Field(0)) return\
    \ true;\n        }\n        return false;\n    }\n\n    /**\n     * @brief \u30D9\
    \u30AF\u30C8\u30EB\u3092\u57FA\u5E95\u306B\u8FFD\u52A0\u3059\u308B\n     * @param\
    \ vec \u5217\u30D9\u30AF\u30C8\u30EB\n     * @return\n     * \u30D9\u30AF\u30C8\
    \u30EB\u304C\u73FE\u5728\u306E\u57FA\u5E95\u3068\u7DDA\u5F62\u72EC\u7ACB\u3067\
    \u306A\u3044\u5834\u5408\u306F\u5EA7\u6A19\u30D9\u30AF\u30C8\u30EB\u3092\u8FD4\
    \u3059\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070nullopt\u3092\u8FD4\u3059\
    \n     */\n    std::optional<Matrix> add(const Matrix &vec) {\n        assert(vec.get_h()\
    \ == h);\n        assert(vec.get_w() == 1);\n\n        Matrix tmp(vec);\n    \
    \    sweep(tmp);\n\n        int pivot = -1;\n        for (int i = rank; i < h;\
    \ ++i) {\n            if (tmp[i][0] != Field(0)) {\n                pivot = i;\n\
    \                break;\n            }\n        }\n        if (pivot == -1) return\
    \ tmp;\n\n        if (pivot != rank) {\n            std::swap(tmp[pivot], tmp[rank]);\n\
    \            hist.emplace_back(2, rank, pivot, Field(1), Field(1));\n        }\n\
    \        if (tmp[rank][0] != Field(1)) {\n            hist.emplace_back(0, rank,\
    \ -1, tmp[rank][0].inv(), tmp[rank][0]);\n            tmp[rank][0] = Field(1);\n\
    \        }\n        for (int i = 0; i < h; ++i) {\n            if (i == rank)\
    \ continue;\n            Field t = -tmp[i][0];\n            if (t == Field(0))\
    \ continue;\n            hist.emplace_back(1, rank, i, t, -t);\n        }\n  \
    \      ++rank;\n        return {};\n    }\n\n    Matrix get_coordinate(const Matrix\
    \ &vec) const {\n        assert(vec.get_h() == h);\n        assert(vec.get_w()\
    \ == 1);\n        Matrix res(vec);\n        sweep(res);\n        for (int i =\
    \ rank; i < h; ++i) assert(res[i][0] == Field(0));\n        return res;\n    }\n\
    \n    void snapshot() { snaps.emplace_back(rank, (int)hist.size()); }\n\n    void\
    \ rollback() {\n        if (snaps.empty()) return;\n        auto snap = snaps.back();\n\
    \        snaps.pop_back();\n        rank = snap.rank;\n        hist.resize(snap.hist_size);\n\
    \    }\n};\n\n} // namespace linear_algebra\n\ntemplate <class Matrix> using BasisMatrix\
    \ =\n    linear_algebra::BasisBase<Matrix, typename Matrix::value_type>;\n\n}\
    \ // namespace kk2\n\n\n#line 7 \"matrix/frobenius_form.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace linear_algebra {\n\ntemplate <class Matrix, class Poly, class\
    \ Field> struct FrobeniusForm_base {\n    Matrix mat;\n    std::vector<int> deg;\n\
    \    std::vector<Poly> poly;\n\n    // mat = P_inv frobenius P\n    // P_inv =\
    \ P^{-1}\n    Matrix frobenius, P, P_inv;\n\n    FrobeniusForm_base(const Matrix\
    \ &mat_) : mat(mat_) {\n        int n = mat.get_h();\n        assert(n == mat.get_w());\n\
    \        frobenius = P = Matrix(n, n);\n        build();\n    }\n\n    void build()\
    \ {\n        int n = mat.get_h();\n        Basis_base<Matrix, Field> basis;\n\
    \        // \u4E71\u629E\u3067\u9811\u5F35\u308B\n    }\n};\n\n} // namespace\
    \ linear_algebra\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATRIX_FROBENIUS_FORM_HPP\n#define KK2_MATRIX_FROBENIUS_FORM_HPP\
    \ 1\n\n#include <vector>\n\n#include \"basis.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ linear_algebra {\n\ntemplate <class Matrix, class Poly, class Field> struct\
    \ FrobeniusForm_base {\n    Matrix mat;\n    std::vector<int> deg;\n    std::vector<Poly>\
    \ poly;\n\n    // mat = P_inv frobenius P\n    // P_inv = P^{-1}\n    Matrix frobenius,\
    \ P, P_inv;\n\n    FrobeniusForm_base(const Matrix &mat_) : mat(mat_) {\n    \
    \    int n = mat.get_h();\n        assert(n == mat.get_w());\n        frobenius\
    \ = P = Matrix(n, n);\n        build();\n    }\n\n    void build() {\n       \
    \ int n = mat.get_h();\n        Basis_base<Matrix, Field> basis;\n        // \u4E71\
    \u629E\u3067\u9811\u5F35\u308B\n    }\n};\n\n} // namespace linear_algebra\n\n\
    } // namespace kk2\n\n#endif // KK2_MATRIX_FROBENIUS_FORM_HPP\n"
  dependsOn:
  - matrix/basis.hpp
  - matrix/matrix_field.hpp
  - type_traits/io.hpp
  isVerificationFile: false
  path: matrix/frobenius_form.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/frobenius_form.hpp
layout: document
redirect_from:
- /library/matrix/frobenius_form.hpp
- /library/matrix/frobenius_form.hpp.html
title: matrix/frobenius_form.hpp
---
