---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: matrix/matrix_field.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#line 1 \"verify/yosupo_linalg/solution_of_linear_equations.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n#line 1 \"matrix/matrix_field.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n#include <optional>\n#include <string>\n#include\
    \ <vector>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include\
    \ <ostream>\n#include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits\
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
    \ 1 \"modint/mont.hpp\"\n\n\n\n#line 5 \"modint/mont.hpp\"\n#include <cstdint>\n\
    #line 8 \"modint/mont.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line\
    \ 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
    \ <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value\n         \
    \                         or std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_signed =\n    typename\
    \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n \
    \                             std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename T>\
    \ using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
    \                              make_unsigned_int128<T>,\n                    \
    \          typename std::conditional<std::is_signed<T>::value,\n             \
    \                                           std::make_unsigned<T>,\n         \
    \                                               std::common_type<T>>::type>::type;\n\
    \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
    template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
    template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
    template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
    \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
    template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\n\
    template <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return\
    \ ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32\
    \ n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n\
    \    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
    \ & 1) == 1, \"invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n\n    template <typename T, is_integral_t<T> * = nullptr> constexpr\
    \ LazyMontgomeryModInt(T b)\n        : _v(reduce(u64(b % p + p) * n2)) {}\n\n\
    \    static constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r))\
    \ * p) >> 32; }\n    constexpr mint &operator++() { return *this += 1; }\n   \
    \ constexpr mint &operator--() { return *this -= 1; }\n\n    constexpr mint operator++(int)\
    \ {\n        mint ret = *this;\n        *this += 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint operator--(int) {\n        mint ret = *this;\n     \
    \   *this -= 1;\n        return ret;\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &b) {\n        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if\
    \ (i32(_v -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n  \
    \      return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n\
    \        *this *= b.inv();\n        return *this;\n    }\n\n\n    constexpr bool\
    \ operator==(const mint &b) const {\n        return (_v >= p ? _v - p : _v) ==\
    \ (b._v >= p ? b._v - p : b._v);\n    }\n\n    constexpr bool operator!=(const\
    \ mint &b) const {\n        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v\
    \ - p : b._v);\n    }\n\n    constexpr mint operator-() const { return mint()\
    \ - mint(*this); }\n    constexpr mint operator+() const { return mint(*this);\
    \ }\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
    \ mint(a) += b; }\n    friend constexpr mint operator-(const mint &a, const mint\
    \ &b) { return mint(a) -= b; }\n    friend constexpr mint operator*(const mint\
    \ &a, const mint &b) { return mint(a) *= b; }\n    friend constexpr mint operator/(const\
    \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T> constexpr\
    \ mint pow(T n) const {\n        mint ret(1), mul(*this);\n        while (n >\
    \ 0) {\n            if (n & 1) ret *= mul;\n            if (n >>= 1) mul *= mul;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const {\n \
    \       assert(*this != mint(0));\n        return pow(p - 2);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, mint &x) {\n        i64 t;\n        is >> t;\n        x = mint(t);\n  \
    \      return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n\n    static\
    \ constexpr u32 getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
    \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 8 \"template/template.hpp\"\n#include\
    \ <chrono>\n#include <cmath>\n#include <deque>\n#include <functional>\n#include\
    \ <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#line 17\
    \ \"template/template.hpp\"\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#line 22 \"template/template.hpp\"\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#line 26 \"template/template.hpp\"\
    \n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line 1 \"template/type_alias.hpp\"\
    \n\n\n\n#line 8 \"template/type_alias.hpp\"\n\nusing u32 = unsigned int;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
    \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\n\
    template <class T> using vc = std::vector<T>;\ntemplate <class T> using vvc =\
    \ std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
    template <class T> using vvvvc = std::vector<vvvc<T>>;\n\ntemplate <class T> using\
    \ pq = std::priority_queue<T>;\ntemplate <class T> using pqi = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\n\n#line 5 \"template/constant.hpp\"\n\n\
    template <class T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int>\
    \ = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll\
    \ << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1)\
    \ << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr\
    \ u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128 infty<u128> = infty<i128>;\n\
    template <> constexpr double infty<double> = infty<i64>;\ntemplate <> constexpr\
    \ long double infty<long double> = infty<i64>;\n\nconstexpr int mod = 998244353;\n\
    constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
    \n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#line 6 \"template/fastio.hpp\"\
    \n#include <cstdio>\n#include <fstream>\n#line 10 \"template/fastio.hpp\"\n\n\
    #line 13 \"template/fastio.hpp\"\n\nnamespace kk2 {\n\nnamespace fastio {\n\n\
    struct Scanner : type_traits::istream_tag {\n  private:\n    static constexpr\
    \ size_t INPUT_BUF = 1 << 17;\n    size_t pos = 0, end = 0;\n    bool is_eof =\
    \ false;\n    static char buf[INPUT_BUF];\n    FILE *fp;\n\n  public:\n    Scanner()\
    \ : fp(stdin) {}\n\n    Scanner(const char *file) : fp(fopen(file, \"r\")) {}\n\
    \n    ~Scanner() {\n        if (fp != stdin) fclose(fp);\n    }\n\n    char now()\
    \ {\n        if (is_eof) return '\\0';\n        if (pos == end) {\n          \
    \  end = fread(buf, 1, INPUT_BUF, fp);\n            if (end != INPUT_BUF) buf[end]\
    \ = '\\0';\n            if (end == 0) is_eof = true;\n            pos = 0;\n \
    \       }\n        return buf[pos];\n    }\n\n    void skip_space() {\n      \
    \  while (isspace(now())) ++pos;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> T next_unsigned_integral() {\n        skip_space();\n        T\
    \ res{};\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    template\
    \ <class T, is_signed_t<T> * = nullptr> T next_signed_integral() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
    \ to_unsigned<T>::type>());\n        } else return (T)next_unsigned_integral<typename\
    \ to_unsigned<T>::type>();\n    }\n\n    char next_char() {\n        skip_space();\n\
    \        auto res = now();\n        ++pos;\n        return res;\n    }\n\n   \
    \ std::string next_string() {\n        skip_space();\n        std::string res;\n\
    \        while (true) {\n            char c = now();\n            if (isspace(c)\
    \ or c == '\\0') break;\n            res.push_back(now());\n            ++pos;\n\
    \        }\n        return res;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> Scanner &operator>>(T &x) {\n        x = next_unsigned_integral<T>();\n\
    \        return *this;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n        x = next_char();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(std::string &x) {\n \
    \       x = next_string();\n        return *this;\n    }\n};\n\nstruct endl_struct_t\
    \ {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n    static char\
    \ helper[10000][5];\n    static char leading_zero[10000][5];\n    constexpr static\
    \ size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos\
    \ = 0;\n    FILE *fp;\n\n    template <class T> static constexpr void div_mod(T\
    \ &a, T &b, T mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n \
    \   static void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0;\
    \ i < 10000; ++i) {\n            leading_zero[i][0] = i / 1000 + '0';\n      \
    \      leading_zero[i][1] = i / 100 % 10 + '0';\n            leading_zero[i][2]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][3] = i % 10 + '0';\n     \
    \       leading_zero[i][4] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n            if (i >= 100) helper[i][j++]\
    \ = i / 100 % 10 + '0';\n            if (i >= 10) helper[i][j++] = i / 10 % 10\
    \ + '0';\n            helper[i][j++] = i % 10 + '0';\n            helper[i][j]\
    \ = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout) { init();\
    \ }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init(); }\n\n\
    \    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n \
    \   }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos = 0;\n\
    \    }\n\n    void flush() {\n        write();\n        fflush(fp);\n    }\n\n\
    \    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n      \
    \  buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n        while\
    \ (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n        uint32_t\
    \ y;\n        if (x >= 100000000) { // 10^8\n            div_mod<uint32_t>(y,\
    \ x, 100000000);\n            put_cstr(helper[y]);\n            div_mod<uint32_t>(y,\
    \ x, 10000);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y, x,\
    \ 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
    \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n       \
    \ uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n            div_mod<uint64_t>(y,\
    \ x, 1000000000000ull);\n            put_u32(y);\n            div_mod<uint64_t>(y,\
    \ x, 100000000ull);\n            put_cstr(leading_zero[y]);\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000ull) { // 10^4\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_u32(y);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     constexpr static __uint128_t pow10_10 = 10000000000ull;\n        constexpr\
    \ static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n        __uint128_t y;\n\
    \        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y, x,\
    \ pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
    \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
    \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n    \
    \        put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x, __uint128_t(100000000ull));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
    \ __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n          \
    \  put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000)) { //\
    \ 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n        \
    \    put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n        }\
    \ else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t x) {\n    \
    \    if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n   \
    \     } else put_u128(x);\n    }\n\n    template <class T, is_unsigned_t<T> *\
    \ = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4)\
    \ put_u32(x);\n        else if constexpr (sizeof(T) <= 8) put_u64(x);\n      \
    \  else put_u128(x);\n        return *this;\n    }\n\n    template <class T, is_signed_t<T>\
    \ * = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <=\
    \ 4) put_i32(x);\n        else if constexpr (sizeof(T) <= 8) put_i64(x);\n   \
    \     else put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\
    \u30DD\u30A4\u30F3\u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\
    \n    Printer &operator<<(endl_struct_t) {\n        put_char('\\n');\n       \
    \ flush();\n        return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\n\
    char Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[10000][5];\nchar\
    \ Printer::leading_zero[10000][5];\n\n} // namespace fastio\n\n#if defined(INTERACTIVE)\
    \ || defined(USE_STDIO)\nauto &kin = std::cin;\nauto &kout = std::cout;\nauto\
    \ (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n#else\n\
    fastio::Scanner kin;\nfastio::Printer kout;\nfastio::endl_struct_t kendl;\n#endif\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\
    \n\n#line 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\
    \u30ED\u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace\
    \ impl {\n\nstruct read {\n    template <class IStream, class T> inline static\
    \ void all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream,\
    \ class T, class U>\n    inline static void all_read(IStream &is, std::pair<T,\
    \ U> &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n\
    \    }\n\n    template <class IStream, class T> inline static void all_read(IStream\
    \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\n\
    \    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
    \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n    }\n\
    };\n\nstruct write {\n    template <class OStream, class T> inline static void\
    \ all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n    template\
    \ <class OStream, class T, class U>\n    inline static void all_write(OStream\
    \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n        all_write(os,\
    \ ' ');\n        all_write(os, p.second);\n    }\n\n    template <class OStream,\
    \ class T>\n    inline static void all_write(OStream &os, const std::vector<T>\
    \ &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (i)\
    \ all_write(os, ' ');\n            all_write(os, v[i]);\n        }\n    }\n\n\
    \    template <class OStream, class T, size_t F>\n    inline static void all_write(OStream\
    \ &os, const std::array<T, F> &a) {\n        for (int i = 0; i < (int)F; ++i)\
    \ {\n            if (i) all_write(os, ' ');\n            all_write(os, a[i]);\n\
    \        }\n    }\n};\n\n} // namespace impl\n\ntemplate <class IStream, class\
    \ T, class U, kk2::is_istream_t<IStream> * = nullptr>\nIStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
    }\n\ntemplate <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>\n\
    IStream &operator>>(IStream &is, std::vector<T> &v) {\n    impl::read::all_read(is,\
    \ v);\n    return is;\n}\n\ntemplate <class IStream, class T, size_t F, kk2::is_istream_t<IStream>\
    \ * = nullptr>\nIStream &operator>>(IStream &is, std::array<T, F> &a) {\n    impl::read::all_read(is,\
    \ a);\n    return is;\n}\n\ntemplate <class OStream, class T, class U, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    impl::write::all_write(os, p);\n    return os;\n}\n\ntemplate <class OStream,\
    \ class T, kk2::is_ostream_t<OStream> * = nullptr>\nOStream &operator<<(OStream\
    \ &os, const std::vector<T> &v) {\n    impl::write::all_write(os, v);\n    return\
    \ os;\n}\n\ntemplate <class OStream, class T, size_t F, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n\
    \    impl::write::all_write(os, a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\
    \n\n\n\n#define rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define\
    \ rep2(i, a) for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a,\
    \ b) for (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for\
    \ (long long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long\
    \ i = (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
    \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32 \"\
    template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 6 \"verify/yosupo_linalg/solution_of_linear_equations.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, m;\n    kin >> n >> m;\n  \
    \  kk2::MatrixField<kk2::mont998> a(n, m), b(n, 1);\n    a.input(kin), b.input(kin);\n\
    \    if (const auto res = a.solve(b); !res) kout << -1 << \"\\n\";\n    else {\n\
    \        kout << res->get_h() - 1 << \"\\n\";\n        res->output(kout);\n  \
    \  }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n#include \"../../matrix/matrix_field.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, m;\n    kin >> n >> m;\n    kk2::MatrixField<kk2::mont998> a(n,\
    \ m), b(n, 1);\n    a.input(kin), b.input(kin);\n    if (const auto res = a.solve(b);\
    \ !res) kout << -1 << \"\\n\";\n    else {\n        kout << res->get_h() - 1 <<\
    \ \"\\n\";\n        res->output(kout);\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - matrix/matrix_field.hpp
  - type_traits/io.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_linalg/solution_of_linear_equations.test.cpp
- /verify/verify/yosupo_linalg/solution_of_linear_equations.test.cpp.html
title: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
---
