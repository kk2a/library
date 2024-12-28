---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/cross_point_line_line.hpp
    title: geometry/cross_point_line_line.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  code: "#ifndef MATH_RATIONAL_HPP\n#define MATH_RATIONAL_HPP 1\n\n#include <numeric>\n\
    \n#include \"../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ rational {\n\ntemplate <typename T, typename Compare> struct RationalBase {\n\
    \    T a, b;\n\n    // a / b\n\n    RationalBase() : a(0), b(1) {}\n\n    RationalBase(T\
    \ a_) : a(a_), b(1) {}\n\n    RationalBase(T a_, T b_) : a(a_), b(b_) {\n    \
    \    assert(b);\n        if (b < 0) a = -a, b = -b;\n        T g = std::gcd(a,\
    \ b);\n        a /= g, b /= g;\n    }\n\n    static RationalBase raw(T a_, T b_)\
    \ {\n        T res;\n        res.a = a_, res.b = b_;\n        return res;\n  \
    \  }\n\n    operator bool() const { return a; }\n\n    double to_double() const\
    \ { return (double)a / b; }\n\n    long double to_ldouble() const { return (long\
    \ double)a / b; }\n\n    friend RationalBase operator+(const RationalBase &lhs,\
    \ const RationalBase &rhs) {\n        if (lhs.b == rhs.b) return RationalBase(lhs.a\
    \ + rhs.a, lhs.b);\n        return RationalBase(lhs.a * rhs.b + rhs.a * lhs.b,\
    \ lhs.b * rhs.b);\n    }\n\n    friend RationalBase operator-(const RationalBase\
    \ &lhs, const RationalBase &rhs) {\n        if (lhs.b == rhs.b) return RationalBase(lhs.a\
    \ - rhs.a, lhs.b);\n        return RationalBase(lhs.a * rhs.b - rhs.a * lhs.b,\
    \ lhs.b * rhs.b);\n    }\n\n    friend RationalBase operator*(const RationalBase\
    \ &lhs, const RationalBase &rhs) {\n        return RationalBase(lhs.a * rhs.a,\
    \ lhs.b * rhs.b);\n    }\n\n    friend RationalBase operator/(const RationalBase\
    \ &lhs, const RationalBase &rhs) {\n        return RationalBase(lhs.a * rhs.b,\
    \ lhs.b * rhs.a);\n    }\n\n    RationalBase &operator+=(const RationalBase &rhs)\
    \ { return (*this) = (*this) + rhs; }\n\n    RationalBase &operator-=(const RationalBase\
    \ &rhs) { return (*this) = (*this) - rhs; }\n\n    RationalBase &operator*=(const\
    \ RationalBase &rhs) { return (*this) = (*this) * rhs; }\n\n    RationalBase &operator/=(const\
    \ RationalBase &rhs) { return (*this) = (*this) / rhs; }\n\n    RationalBase operator-()\
    \ const { return raw(-a, b); }\n\n    RationalBase operator+() const { return\
    \ *this; }\n\n    RationalBase inv() const { return a < 0 ? raw(-b, -a) : raw(b,\
    \ a); }\n\n    RationalBase abs() const { return a < 0 ? raw(-a, b) : *this; }\n\
    \n    RationalBase pow(long long k) const {\n        RationalBase res(1), base\
    \ = *this;\n        while (k) {\n            if (k & 1) res *= base;\n       \
    \     base *= base;\n            k >>= 1;\n        }\n        return res;\n  \
    \  }\n\n    friend bool operator==(const RationalBase &lhs, const RationalBase\
    \ &rhs) {\n        return lhs.a == rhs.a and lhs.b == rhs.b;\n    }\n\n    friend\
    \ bool operator!=(const RationalBase &lhs, const RationalBase &rhs) {\n      \
    \  return !(lhs == rhs);\n    }\n\n    friend bool operator<(const RationalBase\
    \ &lhs, const RationalBase &rhs) {\n        return Compare{lhs.a} * rhs.b < Compare{rhs.a}\
    \ * lhs.b;\n    }\n\n    friend bool operator>(const RationalBase &lhs, const\
    \ RationalBase &rhs) {\n        return Compare{lhs.a} * rhs.b > Compare{rhs.a}\
    \ * lhs.b;\n    }\n\n    friend bool operator<=(const RationalBase &lhs, const\
    \ RationalBase &rhs) {\n        return lhs == rhs or lhs < rhs;\n    }\n\n   \
    \ friend bool operator>=(const RationalBase &lhs, const RationalBase &rhs) {\n\
    \        return lhs == rhs or lhs > rhs;\n    }\n\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream &os,\
    \ const RationalBase &rhs) {\n        return os << rhs.a << \" / \" << rhs.b;\n\
    \    }\n};\n\n} // namespace rational\n\ntemplate <typename T> using Rational\
    \ = rational::RationalBase<T, T>;\nusing RationalInt = rational::RationalBase<int,\
    \ long long>;\nusing RationalI64 = rational::RationalBase<long long, __int128>;\n\
    \n} // namespace kk2\n\n#endif // MATH_RATIONAL_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math/rational.hpp
  requiredBy:
  - geometry/cross_point_line_line.hpp
  timestamp: '2024-12-28 13:04:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/rational.hpp
layout: document
redirect_from:
- /library/math/rational.hpp
- /library/math/rational.hpp.html
title: math/rational.hpp
---
