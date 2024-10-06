---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/matrix_field.hpp
    title: matrix/matrix_field.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"verify/yosupo_linalg/matrix_det.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\" \n\n#line 1 \"matrix/matrix_field.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <optional>\n#include <string>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class Field> struct MatrixField {\n    using value_type = Field;\n    using\
    \ mat = MatrixField;\n    int _h, _w;\n    std::vector<std::vector<Field>> _mat;\n\
    \n    MatrixField() : MatrixField(0) {}\n\n    MatrixField(int n) : MatrixField(n,\
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
    [j == _w - 1];\n        }\n    }\n\n    void set(int i, int j, Field x) {\n  \
    \      assert(0 <= i && i < _h);\n        assert(0 <= j && j < _w);\n        _mat[i][j]\
    \ = x;\n    }\n\n    mat &operator+=(const mat &rhs) {\n        assert(_h == rhs._h);\n\
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
    \ kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\n#line 5 \"modint/mont.hpp\"\n#include\
    \ <cstdint>\n#line 7 \"modint/mont.hpp\"\n#include <type_traits>\n\n#line 1 \"\
    type_traits/type_traits.hpp\"\n\n\n\n#line 5 \"type_traits/type_traits.hpp\"\n\
    \nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128 = typename\
    \ std::conditional<std::is_same<T, __int128_t>::value\n                      \
    \                                 or std::is_same<T, __int128>::value,\n     \
    \                                              std::true_type,\n             \
    \                                      std::false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T>\nusing\
    \ is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed_extended =\n\
    \    typename std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_extended\
    \ =\n    typename std::conditional<std::is_unsigned<T>::value or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n#line 10 \"modint/mont.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int p> struct LazyMontgomeryModInt {\n    using\
    \ mint = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static constexpr\
    \ u32 get_r() {\n        u32 ret = p;\n        for (int i = 0; i < 4; ++i) ret\
    \ *= 2 - p * ret;\n        return ret;\n    }\n\n    static constexpr u32 r =\
    \ get_r();\n    static constexpr u32 n2 = -u64(p) % p;\n    static_assert(r *\
    \ p == 1, \"invalid, r * p != 1\");\n    static_assert(p < (1 << 30), \"invalid,\
    \ p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"invalid, p % 2 == 0\");\n\
    \n    u32 _v;\n\n    operator int() const { return val(); }\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n\n    template <typename T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    constexpr LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p\
    \ + p) * n2)) {}\n\n    static constexpr u32 reduce(const u64 &b) { return (b\
    \ + u64(u32(b) * u32(-r)) * p) >> 32; }\n\n    constexpr mint &operator++() {\
    \ return *this += 1; }\n\n    constexpr mint &operator--() { return *this -= 1;\
    \ }\n\n    constexpr mint operator++(int) {\n        mint ret = *this;\n     \
    \   *this += 1;\n        return ret;\n    }\n\n    constexpr mint operator--(int)\
    \ {\n        mint ret = *this;\n        *this -= 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint &operator+=(const mint &b) {\n        if (i32(_v +=\
    \ b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator-=(const mint &b) {\n        if (i32(_v -= b._v) < 0) _v += 2\
    \ * p;\n        return *this;\n    }\n\n    constexpr mint &operator*=(const mint\
    \ &b) {\n        _v = reduce(u64(_v) * b._v);\n        return *this;\n    }\n\n\
    \    constexpr mint &operator/=(const mint &b) {\n        *this *= b.inv();\n\
    \        return *this;\n    }\n\n    constexpr mint operator-() const { return\
    \ mint() - mint(*this); }\n\n    constexpr bool operator==(const mint &b) const\
    \ {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);\n\
    \    }\n\n    constexpr bool operator!=(const mint &b) const {\n        return\
    \ (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n    }\n\n    friend\
    \ constexpr mint operator+(const mint &a, const mint &b) { return mint(a) += b;\
    \ }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(const mint &a, T b) {\n  \
    \      return mint(a) += mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(T a, const mint &b) {\n  \
    \      return mint(a) += b;\n    }\n\n    friend constexpr mint operator-(const\
    \ mint &a, const mint &b) { return mint(a) -= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(const mint &a, T b) {\n  \
    \      return mint(a) -= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(T a, const mint &b) {\n  \
    \      return mint(a) -= b;\n    }\n\n    friend constexpr mint operator*(const\
    \ mint &a, const mint &b) { return mint(a) *= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(const mint &a, T b) {\n  \
    \      return mint(a) *= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(T a, const mint &b) {\n  \
    \      return mint(a) *= b;\n    }\n\n    friend constexpr mint operator/(const\
    \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(const mint &a, T b) {\n  \
    \      return mint(a) /= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(T a, const mint &b) {\n  \
    \      return mint(a) /= b;\n    }\n\n    template <class T> constexpr mint pow(T\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n    \
    \        if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const { return\
    \ pow(p - 2); }\n\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ mint &x) { return os << x.val(); }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &x) {\n        i64 t;\n        is >> t;\n        x = mint(t);\n  \
    \      return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n\n    static\
    \ constexpr u32 getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
    \n\nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"\
    O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n#line 8 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\n#include\
    \ <chrono>\n#include <cmath>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#line 19 \"template/template.hpp\"\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#line\
    \ 24 \"template/template.hpp\"\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#line 30 \"template/template.hpp\"\
    \n#include <tuple>\n#line 32 \"template/template.hpp\"\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#line 36 \"template/template.hpp\"\
    \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> constexpr T infty = 0;\ntemplate\
    \ <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128> = i128(infty<i64>)\
    \ * infty<i64>;\ntemplate <> constexpr u32 infty<u32> = infty<int>;\ntemplate\
    \ <> constexpr u64 infty<u64> = infty<i64>;\ntemplate <> constexpr double infty<double>\
    \ = infty<i64>;\ntemplate <> constexpr long double infty<long double> = infty<i64>;\n\
    \nconstexpr int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long\
    \ double PI = 3.14159265358979323846;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(const T &init,\
    \ int first, Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n \
    \       return std::vector<T>(first, init);\n    } else {\n        return std::vector<decltype(make_vector(init,\
    \ sizes...))>(first,\n                                                       \
    \           make_vector(init, sizes...));\n    }\n}\n\ntemplate <class T, class\
    \ U> void fill_all(std::vector<T> &v, const U &x) {\n    std::fill(std::begin(v),\
    \ std::end(v), T(x));\n}\n\ntemplate <class T, class U> void fill_all(std::vector<std::vector<T>>\
    \ &v, const U &x) {\n    for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace\
    \ kk2\n\ntemplate <class T, class S> inline bool chmax(T &a, const S &b) {\n \
    \   return (a < b ? a = b, 1 : 0);\n}\n\ntemplate <class T, class S> inline bool\
    \ chmin(T &a, const S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\n#define\
    \ rep1(a) for (i64 _ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i =\
    \ 0; i < (i64)(a); ++i)\n#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b);\
    \ ++i)\n#define repi2(i, a) for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i,\
    \ a, b) for (i64 i = (a) - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c,\
    \ d, ...) d\n#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    #define repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n\
    #define fi first\n#define se second\n#define all(p) std::begin(p), std::end(p)\n\
    \nstruct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \    }\n} iosetup;\n\n#ifdef KK2\nstd::ifstream in(\"in.txt\");\nstd::ofstream\
    \ out(\"out.txt\");\n#else\n#define in std::cin\n#define out std::cout\n#endif\n\
    \nvoid YES(bool b = 1) {\n    std::cout << (b ? \"YES\" : \"NO\") << '\\n';\n\
    }\n\nvoid NO(bool b = 1) {\n    std::cout << (b ? \"NO\" : \"YES\") << '\\n';\n\
    }\n\nvoid Yes(bool b = 1) {\n    std::cout << (b ? \"Yes\" : \"No\") << '\\n';\n\
    }\n\nvoid No(bool b = 1) {\n    std::cout << (b ? \"No\" : \"Yes\") << '\\n';\n\
    }\n\nvoid yes(bool b = 1) {\n    std::cout << (b ? \"yes\" : \"no\") << '\\n';\n\
    }\n\nvoid no(bool b = 1) {\n    std::cout << (b ? \"no\" : \"yes\") << '\\n';\n\
    }\n\n\n#line 6 \"verify/yosupo_linalg/matrix_det.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n    int n;\n    cin >> n;\n    kk2::MatrixField<kk2::mont998>\
    \ a(n, n);\n    rep (i, n) rep (j, n) cin >> a[i][j];\n    cout << a.det() <<\
    \ \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\" \n\n#include\
    \ \"../../matrix/matrix_field.hpp\"\n#include \"../../modint/mont.hpp\"\n#include\
    \ \"../../template/template.hpp\"\nusing namespace std;\n\nint main() {\n    int\
    \ n;\n    cin >> n;\n    kk2::MatrixField<kk2::mont998> a(n, n);\n    rep (i,\
    \ n) rep (j, n) cin >> a[i][j];\n    cout << a.det() << \"\\n\";\n\n    return\
    \ 0;\n}"
  dependsOn:
  - matrix/matrix_field.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_linalg/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2024-10-06 20:03:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_linalg/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_linalg/matrix_det.test.cpp
- /verify/verify/yosupo_linalg/matrix_det.test.cpp.html
title: verify/yosupo_linalg/matrix_det.test.cpp
---
