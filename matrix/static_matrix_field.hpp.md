---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5F62\u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u6C7A\u307E\
      \u3063\u3066\u3044\u308B\u884C\u5217"
    links: []
  bundledCode: "#line 1 \"matrix/static_matrix_field.hpp\"\n\n\n\n#include <array>\n\
    #include <cassert>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n\
    #include <ostream>\n#include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits\
    \ {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
    \ntemplate <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
    \ std::istream>::value\n                                  || std::is_same<T, std::ifstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_standard_ostream =\n\
    \    typename std::conditional<std::is_same<T, std::ostream>::value\n        \
    \                          || std::is_same<T, std::ofstream>::value,\n       \
    \                       std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
    \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
    \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 8 \"matrix/static_matrix_field.hpp\"\n\nnamespace kk2 {\n\n\n\
    /**\n * @brief \u5F62\u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u6C7A\u307E\
    \u3063\u3066\u3044\u308B\u884C\u5217\n *\n *\n * @tparam H\n * @tparam W\n * @tparam\
    \ Field inv\u30E1\u30F3\u30D0\u304C\u5FC5\u8981\n */\ntemplate <int _H, int _W,\
    \ class Field> struct StaticMatrixFiled {\n    using value_type = Field;\n   \
    \ using mat = StaticMatrixFiled;\n    static constexpr int _h = _H, _w = _W;\n\
    \    std::array<std::array<Field, _W>, _H> _mat;\n    StaticMatrixFiled() { _mat.fill(std::array<Field,\
    \ _W>()); }\n    StaticMatrixFiled(const std::array<std::array<Field, _W>, _H>\
    \ &mat_) : _mat(mat_) {}\n\n    inline int get_h() const { return _h; }\n    inline\
    \ int get_w() const { return _w; }\n\n    std::array<Field, _W> &operator[](int\
    \ i) {\n        assert(0 <= i && i < _h);\n        return _mat[i];\n    }\n  \
    \  const std::array<Field, _W> &operator[](int i) const {\n        assert(0 <=\
    \ i && i < _h);\n        return _mat[i];\n    }\n\n    static mat unit() {\n \
    \       static_assert(_h == _w, \"unit matrix must be square\");\n        mat\
    \ res;\n        for (int i = 0; i < _h; i++) res[i][i] = Field(1);\n        return\
    \ res;\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\
    \ mat &input(IStream &is) {\n        for (int i = 0; i < _h; i++) {\n        \
    \    for (int j = 0; j < _w; j++) { is >> _mat[i][j]; }\n        }\n        return\
    \ *this;\n    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &os) const {\n        for (int i = 0; i < _h; i++) {\n \
    \           for (int j = 0; j < _w; j++) os << _mat[i][j] << \" \\n\"[j + 1 ==\
    \ _w];\n        }\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"(h,\
    \ w): \" << \"(\" << _h << \", \" << _w << \"), [\\n\";\n        for (int i =\
    \ 0; i < _h; i++) {\n            os << \"  [ \";\n            for (int j = 0;\
    \ j < _w; j++) os << _mat[i][j] << \" \";\n            os << \"]\\n\";\n     \
    \   }\n        os << \"]\\n\";\n    }\n\n    mat &operator+=(const mat &rhs) {\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ { _mat[i][j] += rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\
    \n    mat &operator-=(const mat &rhs) {\n        for (int i = 0; i < _h; i++)\
    \ {\n            for (int j = 0; j < _w; j++) { _mat[i][j] -= rhs._mat[i][j];\
    \ }\n        }\n        return *this;\n    }\n\n    mat &operator*=(const mat\
    \ &rhs) {\n        static_assert(_w == rhs._h, \"matrix multiplication dimension\
    \ mismatch\");\n        std::array<std::array<Field, rhs._w>, _h> res{};\n   \
    \     for (int i = 0; i < _h; i++) {\n            for (int k = 0; k < _w; k++)\
    \ {\n                for (int j = 0; j < rhs._w; j++) { res[i][j] += _mat[i][k]\
    \ * rhs._mat[k][j]; }\n            }\n        }\n        *this = mat(res);\n \
    \       return *this;\n    }\n\n    /**\n     * @brief \u6383\u304D\u51FA\u3057\
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
    \n    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) +=\
    \ rhs; }\n    friend mat operator-(const mat &lhs, const mat &rhs) { return mat(lhs)\
    \ -= rhs; }\n    friend mat operator*(const mat &lhs, const mat &rhs) { return\
    \ mat(lhs) *= rhs; }\n    friend bool operator==(const mat &lhs, const mat &rhs)\
    \ { return lhs._mat == rhs._mat; }\n    friend bool operator!=(const mat &lhs,\
    \ const mat &rhs) { return lhs._mat != rhs._mat; }\n};\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef KK2_MATRIX_STATIC_MATRIX_FIELD_HPP\n#define KK2_MATRIX_STATIC_MATRIX_FIELD_HPP\
    \ 1\n\n#include <array>\n#include <cassert>\n\n#include \"../type_traits/io.hpp\"\
    \n\nnamespace kk2 {\n\n\n/**\n * @brief \u5F62\u304C\u30B3\u30F3\u30D1\u30A4\u30EB\
    \u6642\u306B\u6C7A\u307E\u3063\u3066\u3044\u308B\u884C\u5217\n *\n *\n * @tparam\
    \ H\n * @tparam W\n * @tparam Field inv\u30E1\u30F3\u30D0\u304C\u5FC5\u8981\n\
    \ */\ntemplate <int _H, int _W, class Field> struct StaticMatrixFiled {\n    using\
    \ value_type = Field;\n    using mat = StaticMatrixFiled;\n    static constexpr\
    \ int _h = _H, _w = _W;\n    std::array<std::array<Field, _W>, _H> _mat;\n   \
    \ StaticMatrixFiled() { _mat.fill(std::array<Field, _W>()); }\n    StaticMatrixFiled(const\
    \ std::array<std::array<Field, _W>, _H> &mat_) : _mat(mat_) {}\n\n    inline int\
    \ get_h() const { return _h; }\n    inline int get_w() const { return _w; }\n\n\
    \    std::array<Field, _W> &operator[](int i) {\n        assert(0 <= i && i <\
    \ _h);\n        return _mat[i];\n    }\n    const std::array<Field, _W> &operator[](int\
    \ i) const {\n        assert(0 <= i && i < _h);\n        return _mat[i];\n   \
    \ }\n\n    static mat unit() {\n        static_assert(_h == _w, \"unit matrix\
    \ must be square\");\n        mat res;\n        for (int i = 0; i < _h; i++) res[i][i]\
    \ = Field(1);\n        return res;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr> mat &input(IStream &is) {\n        for (int i = 0; i < _h; i++)\
    \ {\n            for (int j = 0; j < _w; j++) { is >> _mat[i][j]; }\n        }\n\
    \        return *this;\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os) const {\n        for (int i = 0; i < _h;\
    \ i++) {\n            for (int j = 0; j < _w; j++) os << _mat[i][j] << \" \\n\"\
    [j + 1 == _w];\n        }\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"(h,\
    \ w): \" << \"(\" << _h << \", \" << _w << \"), [\\n\";\n        for (int i =\
    \ 0; i < _h; i++) {\n            os << \"  [ \";\n            for (int j = 0;\
    \ j < _w; j++) os << _mat[i][j] << \" \";\n            os << \"]\\n\";\n     \
    \   }\n        os << \"]\\n\";\n    }\n\n    mat &operator+=(const mat &rhs) {\n\
    \        for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ { _mat[i][j] += rhs._mat[i][j]; }\n        }\n        return *this;\n    }\n\
    \n    mat &operator-=(const mat &rhs) {\n        for (int i = 0; i < _h; i++)\
    \ {\n            for (int j = 0; j < _w; j++) { _mat[i][j] -= rhs._mat[i][j];\
    \ }\n        }\n        return *this;\n    }\n\n    mat &operator*=(const mat\
    \ &rhs) {\n        static_assert(_w == rhs._h, \"matrix multiplication dimension\
    \ mismatch\");\n        std::array<std::array<Field, rhs._w>, _h> res{};\n   \
    \     for (int i = 0; i < _h; i++) {\n            for (int k = 0; k < _w; k++)\
    \ {\n                for (int j = 0; j < rhs._w; j++) { res[i][j] += _mat[i][k]\
    \ * rhs._mat[k][j]; }\n            }\n        }\n        *this = mat(res);\n \
    \       return *this;\n    }\n\n    /**\n     * @brief \u6383\u304D\u51FA\u3057\
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
    \n    friend mat operator+(const mat &lhs, const mat &rhs) { return mat(lhs) +=\
    \ rhs; }\n    friend mat operator-(const mat &lhs, const mat &rhs) { return mat(lhs)\
    \ -= rhs; }\n    friend mat operator*(const mat &lhs, const mat &rhs) { return\
    \ mat(lhs) *= rhs; }\n    friend bool operator==(const mat &lhs, const mat &rhs)\
    \ { return lhs._mat == rhs._mat; }\n    friend bool operator!=(const mat &lhs,\
    \ const mat &rhs) { return lhs._mat != rhs._mat; }\n};\n\n} // namespace kk2\n\
    \n#endif // KK2_MATRIX_STATIC_MATRIX_FIELD_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: matrix/static_matrix_field.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/static_matrix_field.hpp
layout: document
redirect_from:
- /library/matrix/static_matrix_field.hpp
- /library/matrix/static_matrix_field.hpp.html
title: "\u5F62\u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u6C7A\u307E\u3063\u3066\
  \u3044\u308B\u884C\u5217"
---
