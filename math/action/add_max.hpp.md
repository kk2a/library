---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/group/add.hpp
    title: math/group/add.hpp
  - icon: ':question:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/action/action.test.cpp
    title: verify/unit_test/math/action/action.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/action/add_max.hpp\"\n\n\n\n#line 1 \"math/group/add.hpp\"\
    \n\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n\
    #include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct\
    \ istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\ntemplate\
    \ <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
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
    \ kk2\n\n\n#line 5 \"math/group/add.hpp\"\n\nnamespace kk2 {\n\nnamespace group\
    \ {\n\ntemplate <class S> struct Add {\n    static constexpr bool commutative\
    \ = true;\n    using M = Add;\n    S a;\n\n    Add() : a(S()) {}\n    Add(S a_)\
    \ : a(a_) {}\n    operator S() const { return a; }\n    inline static M op(M l,\
    \ M r) { return M(l.a + r.a); }\n    inline static M inv(M x) { return M(-x.a);\
    \ }\n    inline static M unit() { return M(); }\n    bool operator==(const M &rhs)\
    \ const { return a == rhs.a; }\n    bool operator!=(const M &rhs) const { return\
    \ a != rhs.a; }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    friend OStream &operator<<(OStream &os, const M &x) {\n        return os\
    \ << x.a;\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n\
    \    friend IStream &operator>>(IStream &is, M &x) {\n        return is >> x.a;\n\
    \    }\n};\n\n} // namespace group\n\n} // namespace kk2\n\n\n#line 1 \"math/monoid/max.hpp\"\
    \n\n\n\n#include <functional>\n\n#line 7 \"math/monoid/max.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class Compare = std::less<S>>\
    \ struct Max {\n    static constexpr bool commutative = true;\n    using M = Max;\n\
    \    S a;\n    bool is_unit;\n\n    Max() : a(S()), is_unit(true) {}\n    Max(S\
    \ a_) : a(a_), is_unit(false) {}\n    operator S() const { return a; }\n\n   \
    \ inline static M op(M l, M r) {\n        if (l.is_unit or r.is_unit) return l.is_unit\
    \ ? r : l;\n        return Compare{}(l.a, r.a) ? r : l;\n    }\n\n    inline static\
    \ M unit() { return M(); }\n\n    bool operator==(const M &rhs) const {\n    \
    \    return is_unit == rhs.is_unit and (is_unit or a == rhs.a);\n    }\n\n   \
    \ bool operator!=(const M &rhs) const {\n        return is_unit != rhs.is_unit\
    \ or (!is_unit and a != rhs.a);\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const M &x) {\n  \
    \      if (x.is_unit) os << \"-inf\";\n        else os << x.a;\n        return\
    \ os;\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n\
    \    friend IStream &operator>>(IStream &is, M &x) {\n        is >> x.a;\n   \
    \     x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace monoid\n\
    \n} // namespace kk2\n\n\n#line 6 \"math/action/add_max.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace action {\n\ntemplate <class T, class Compare = std::less<T>>\
    \ struct AddMax {\n    using A = group::Add<T>;\n    using S = monoid::Max<T,\
    \ Compare>;\n\n    inline static S act(A f, S x) { return x.is_unit ? x : S(x.a\
    \ + f.a); }\n};\n\n} // namespace action\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_ACTION_ADD_MAX_HPP\n#define KK2_MATH_ACTION_ADD_MAX_HPP\
    \ 1\n\n#include \"../group/add.hpp\"\n#include \"../monoid/max.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace action {\n\ntemplate <class T, class Compare = std::less<T>>\
    \ struct AddMax {\n    using A = group::Add<T>;\n    using S = monoid::Max<T,\
    \ Compare>;\n\n    inline static S act(A f, S x) { return x.is_unit ? x : S(x.a\
    \ + f.a); }\n};\n\n} // namespace action\n\n} // namespace kk2\n\n#endif // KK2_MATH_ACTION_ADD_MAX_HPP\n"
  dependsOn:
  - math/group/add.hpp
  - type_traits/io.hpp
  - math/monoid/max.hpp
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/action/add_max.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/action/action.test.cpp
documentation_of: math/action/add_max.hpp
layout: document
redirect_from:
- /library/math/action/add_max.hpp
- /library/math/action/add_max.hpp.html
title: math/action/add_max.hpp
---
