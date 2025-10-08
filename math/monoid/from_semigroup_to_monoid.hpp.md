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
    links: []
  bundledCode: "#line 1 \"math/monoid/from_semigroup_to_monoid.hpp\"\n\n\n\n#line\
    \ 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n#include\
    \ <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag\
    \ {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename\
    \ T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
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
    \ kk2\n\n\n#line 5 \"math/monoid/from_semigroup_to_monoid.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace monoid {\n\ntemplate <class SM> struct FromSemigroupToMonoid\
    \ {\n    static constexpr bool commutative = SM::commutative;\n    using M = FromSemigroupToMonoid;\n\
    \    SM a;\n    bool is_unit;\n\n    FromSemigroupToMonoid() : is_unit(true) {}\n\
    \    template <class... Args> FromSemigroupToMonoid(Args... args) : a(args...),\
    \ is_unit(false) {}\n\n    inline static M op(M l, M r) {\n        if (l.is_unit\
    \ or r.is_unit) return l.is_unit ? r : l;\n        return M(SM::op(l.a, r.a));\n\
    \    }\n\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
    \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
    \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) return os << \"unit\";\n        return\
    \ os << x.a;\n    }\n\n    template <class IStream, is_istream_t<IStream> * =\
    \ nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is >>\
    \ x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\n#define KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\
    \ 1\n\n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\ntemplate <class SM> struct FromSemigroupToMonoid {\n    static constexpr\
    \ bool commutative = SM::commutative;\n    using M = FromSemigroupToMonoid;\n\
    \    SM a;\n    bool is_unit;\n\n    FromSemigroupToMonoid() : is_unit(true) {}\n\
    \    template <class... Args> FromSemigroupToMonoid(Args... args) : a(args...),\
    \ is_unit(false) {}\n\n    inline static M op(M l, M r) {\n        if (l.is_unit\
    \ or r.is_unit) return l.is_unit ? r : l;\n        return M(SM::op(l.a, r.a));\n\
    \    }\n\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
    \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
    \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) return os << \"unit\";\n        return\
    \ os << x.a;\n    }\n\n    template <class IStream, is_istream_t<IStream> * =\
    \ nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is >>\
    \ x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/monoid/from_semigroup_to_monoid.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/from_semigroup_to_monoid.hpp
layout: document
redirect_from:
- /library/math/monoid/from_semigroup_to_monoid.hpp
- /library/math/monoid/from_semigroup_to_monoid.hpp.html
title: math/monoid/from_semigroup_to_monoid.hpp
---
