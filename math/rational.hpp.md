---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files:
    - filename: cross_point_line_line.hpp
      icon: LIBRARY_NO_TESTS
      path: geometry/cross_point_line_line.hpp
    type: Required by
  - files:
    - filename: rational.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/rational.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MATH_RATIONAL_HPP\n#define KK2_MATH_RATIONAL_HPP 1\n\n#include\
      \ <cassert>\n#include <numeric>\n\n#include \"../type_traits/io.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace rational {\n\ntemplate <typename T, typename Compare> struct\
      \ RationalBase {\n    using B = RationalBase;\n    T a, b;\n    // a / b\n \
      \   RationalBase() : a(0), b(1) {}\n    RationalBase(T a_) : a(a_), b(1) {}\n\
      \    RationalBase(T a_, T b_) : a(a_), b(b_) {\n        assert(b);\n       \
      \ if (b < 0) a = -a, b = -b;\n        T g = std::gcd(a, b);\n        a /= g,\
      \ b /= g;\n    }\n\n    static B raw(T a_, T b_) {\n        B res;\n       \
      \ res.a = a_, res.b = b_;\n        return res;\n    }\n\n    operator bool()\
      \ const { return a; }\n    double to_double() const { return (double)a / b;\
      \ }\n    long double to_ldouble() const { return (long double)a / b; }\n\n \
      \   friend B operator+(const B &lhs, const B &rhs) {\n        if (lhs.b == rhs.b)\
      \ return B(lhs.a + rhs.a, lhs.b);\n        return B(lhs.a * rhs.b + rhs.a *\
      \ lhs.b, lhs.b * rhs.b);\n    }\n\n    friend B operator-(const B &lhs, const\
      \ B &rhs) {\n        if (lhs.b == rhs.b) return B(lhs.a - rhs.a, lhs.b);\n \
      \       return B(lhs.a * rhs.b - rhs.a * lhs.b, lhs.b * rhs.b);\n    }\n\n \
      \   friend B operator*(const B &lhs, const B &rhs) { return B(lhs.a * rhs.a,\
      \ lhs.b * rhs.b); }\n    friend B operator/(const B &lhs, const B &rhs) { return\
      \ B(lhs.a * rhs.b, lhs.b * rhs.a); }\n    B &operator+=(const B &rhs) { return\
      \ (*this) = (*this) + rhs; }\n    B &operator-=(const B &rhs) { return (*this)\
      \ = (*this) - rhs; }\n    B &operator*=(const B &rhs) { return (*this) = (*this)\
      \ * rhs; }\n    B &operator/=(const B &rhs) { return (*this) = (*this) / rhs;\
      \ }\n    B operator-() const { return raw(-a, b); }\n    B operator+() const\
      \ { return *this; }\n    B inv() const { return a < 0 ? raw(-b, -a) : raw(b,\
      \ a); }\n    B abs() const { return a < 0 ? raw(-a, b) : *this; }\n    friend\
      \ bool operator==(const B &lhs, const B &rhs) { return lhs.a == rhs.a and lhs.b\
      \ == rhs.b; }\n    friend bool operator!=(const B &lhs, const B &rhs) { return\
      \ !(lhs == rhs); }\n    friend bool operator<(const B &lhs, const B &rhs) {\n\
      \        return Compare{lhs.a} * rhs.b < Compare{rhs.a} * lhs.b;\n    }\n  \
      \  friend bool operator>(const B &lhs, const B &rhs) {\n        return Compare{lhs.a}\
      \ * rhs.b > Compare{rhs.a} * lhs.b;\n    }\n    friend bool operator<=(const\
      \ B &lhs, const B &rhs) { return lhs == rhs or lhs < rhs; }\n    friend bool\
      \ operator>=(const B &lhs, const B &rhs) { return lhs == rhs or lhs > rhs; }\n\
      \    template <OutputStream OStream>\n    friend OStream &operator<<(OStream\
      \ &os, const B &rhs) {\n        return os << rhs.a << \" / \" << rhs.b;\n  \
      \  }\n};\n\n} // namespace rational\n\ntemplate <typename T> using Rational\
      \ = rational::RationalBase<T, T>;\nusing RationalInt = rational::RationalBase<int,\
      \ long long>;\nusing RationalI64 = rational::RationalBase<long long, __int128>;\n\
      \n} // namespace kk2\n\n#endif // KK2_MATH_RATIONAL_HPP\n"
    name: default
  - code: "#line 1 \"math/rational.hpp\"\n\n\n\n#include <cassert>\n#include <numeric>\n\
      \n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include <fstream>\n\
      #include <istream>\n#include <ostream>\n#include <type_traits>\n\nnamespace\
      \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
      \ {};\n\n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
      \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n  \
      \                                || std::is_same<T, std::ifstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_standard_ostream\
      \ =\n    typename std::conditional<std::is_same<T, std::ostream>::value\n  \
      \                                || std::is_same<T, std::ofstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 8 \"math/rational.hpp\"\n\nnamespace kk2 {\n\
      \nnamespace rational {\n\ntemplate <typename T, typename Compare> struct RationalBase\
      \ {\n    using B = RationalBase;\n    T a, b;\n    // a / b\n    RationalBase()\
      \ : a(0), b(1) {}\n    RationalBase(T a_) : a(a_), b(1) {}\n    RationalBase(T\
      \ a_, T b_) : a(a_), b(b_) {\n        assert(b);\n        if (b < 0) a = -a,\
      \ b = -b;\n        T g = std::gcd(a, b);\n        a /= g, b /= g;\n    }\n\n\
      \    static B raw(T a_, T b_) {\n        B res;\n        res.a = a_, res.b =\
      \ b_;\n        return res;\n    }\n\n    operator bool() const { return a; }\n\
      \    double to_double() const { return (double)a / b; }\n    long double to_ldouble()\
      \ const { return (long double)a / b; }\n\n    friend B operator+(const B &lhs,\
      \ const B &rhs) {\n        if (lhs.b == rhs.b) return B(lhs.a + rhs.a, lhs.b);\n\
      \        return B(lhs.a * rhs.b + rhs.a * lhs.b, lhs.b * rhs.b);\n    }\n\n\
      \    friend B operator-(const B &lhs, const B &rhs) {\n        if (lhs.b ==\
      \ rhs.b) return B(lhs.a - rhs.a, lhs.b);\n        return B(lhs.a * rhs.b - rhs.a\
      \ * lhs.b, lhs.b * rhs.b);\n    }\n\n    friend B operator*(const B &lhs, const\
      \ B &rhs) { return B(lhs.a * rhs.a, lhs.b * rhs.b); }\n    friend B operator/(const\
      \ B &lhs, const B &rhs) { return B(lhs.a * rhs.b, lhs.b * rhs.a); }\n    B &operator+=(const\
      \ B &rhs) { return (*this) = (*this) + rhs; }\n    B &operator-=(const B &rhs)\
      \ { return (*this) = (*this) - rhs; }\n    B &operator*=(const B &rhs) { return\
      \ (*this) = (*this) * rhs; }\n    B &operator/=(const B &rhs) { return (*this)\
      \ = (*this) / rhs; }\n    B operator-() const { return raw(-a, b); }\n    B\
      \ operator+() const { return *this; }\n    B inv() const { return a < 0 ? raw(-b,\
      \ -a) : raw(b, a); }\n    B abs() const { return a < 0 ? raw(-a, b) : *this;\
      \ }\n    friend bool operator==(const B &lhs, const B &rhs) { return lhs.a ==\
      \ rhs.a and lhs.b == rhs.b; }\n    friend bool operator!=(const B &lhs, const\
      \ B &rhs) { return !(lhs == rhs); }\n    friend bool operator<(const B &lhs,\
      \ const B &rhs) {\n        return Compare{lhs.a} * rhs.b < Compare{rhs.a} *\
      \ lhs.b;\n    }\n    friend bool operator>(const B &lhs, const B &rhs) {\n \
      \       return Compare{lhs.a} * rhs.b > Compare{rhs.a} * lhs.b;\n    }\n   \
      \ friend bool operator<=(const B &lhs, const B &rhs) { return lhs == rhs or\
      \ lhs < rhs; }\n    friend bool operator>=(const B &lhs, const B &rhs) { return\
      \ lhs == rhs or lhs > rhs; }\n    template <OutputStream OStream>\n    friend\
      \ OStream &operator<<(OStream &os, const B &rhs) {\n        return os << rhs.a\
      \ << \" / \" << rhs.b;\n    }\n};\n\n} // namespace rational\n\ntemplate <typename\
      \ T> using Rational = rational::RationalBase<T, T>;\nusing RationalInt = rational::RationalBase<int,\
      \ long long>;\nusing RationalI64 = rational::RationalBase<long long, __int128>;\n\
      \n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/rational.hpp
  pathExtension: hpp
  requiredBy:
  - geometry/cross_point_line_line.hpp
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/rational.test.cpp
documentation_of: math/rational.hpp
layout: document
---
