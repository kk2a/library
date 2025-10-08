---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/action/update_affine.hpp
    title: math/action/update_affine.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_max.hpp
    title: math/action/update_max.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_max_min_sumwithsize.hpp
    title: math/action/update_max_min_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_min.hpp
    title: math/action/update_min.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_sumwithsize.hpp
    title: math/action/update_sumwithsize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/action/action.test.cpp
    title: verify/unit_test/math/action/action.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/monoid/monoid.test.cpp
    title: verify/unit_test/math/monoid/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
    title: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\
      \u30A4\u30C9"
    links: []
  bundledCode: "#line 1 \"math/monoid/update.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\
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
    \ kk2\n\n\n#line 5 \"math/monoid/update.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\n/**\n * @brief \u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\
    \u30E2\u30CE\u30A4\u30C9\n */\ntemplate <class S> struct Update {\n    static\
    \ constexpr bool commutative = true;\n    using M = Update;\n    S a;\n    bool\
    \ is_unit;\n\n    Update() : is_unit(true) {}\n    Update(S a_) : a(a_), is_unit(false)\
    \ {}\n    operator S() const { return a; }\n    inline static M op(M l, M r) {\
    \ return l.is_unit ? r : l; }\n    inline static M unit() { return M(); }\n\n\
    \    bool operator==(const M &rhs) const {\n        return is_unit == rhs.is_unit\
    \ and (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const\
    \ {\n        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n   \
    \ }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend\
    \ OStream &operator<<(OStream &os, const M &x) {\n        if (x.is_unit) os <<\
    \ \"unit\";\n        else os << x.a;\n        return os;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return\
    \ is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MONOID_UPDATE_HPP\n#define KK2_MATH_MONOID_UPDATE_HPP 1\n\
    \n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\n/**\n * @brief \u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\
    \u30CE\u30A4\u30C9\n */\ntemplate <class S> struct Update {\n    static constexpr\
    \ bool commutative = true;\n    using M = Update;\n    S a;\n    bool is_unit;\n\
    \n    Update() : is_unit(true) {}\n    Update(S a_) : a(a_), is_unit(false) {}\n\
    \    operator S() const { return a; }\n    inline static M op(M l, M r) { return\
    \ l.is_unit ? r : l; }\n    inline static M unit() { return M(); }\n\n    bool\
    \ operator==(const M &rhs) const {\n        return is_unit == rhs.is_unit and\
    \ (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n\
    \        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n\
    \    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream\
    \ &operator<<(OStream &os, const M &x) {\n        if (x.is_unit) os << \"unit\"\
    ;\n        else os << x.a;\n        return os;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return is;\n\
    \    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_UPDATE_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/monoid/update.hpp
  requiredBy:
  - math/action/update_min.hpp
  - math/action/update_sumwithsize.hpp
  - math/action/update_affine.hpp
  - math/action/update_max_min_sumwithsize.hpp
  - math/action/update_max.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
  - verify/unit_test/math/monoid/monoid.test.cpp
  - verify/unit_test/math/action/action.test.cpp
documentation_of: math/monoid/update.hpp
layout: document
redirect_from:
- /library/math/monoid/update.hpp
- /library/math/monoid/update.hpp.html
title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\u30C9"
---
