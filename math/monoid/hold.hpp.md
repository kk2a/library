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
  - files: []
    type: Required by
  - files:
    - filename: monoid.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/monoid/monoid.test.cpp
    - filename: ds_ordered_set_max_right.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MONOID_HOLD_HPP\n#define KK2_MATH_MONOID_HOLD_HPP 1\n\n\
      #include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
      \ {\n\n/**\n * @brief \u5E38\u306B\u53F3\u5074\u3092\u4FDD\u6301\u3059\u308B\
      \u30E2\u30CE\u30A4\u30C9\n */\ntemplate <class S> struct Hold {\n    static\
      \ constexpr bool commutative = true;\n    using M = Hold;\n\n    S a;\n    bool\
      \ is_unit;\n\n    Hold() : is_unit(true) {}\n    Hold(S a_) : a(a_), is_unit(false)\
      \ {}\n    operator S() const { return a; }\n    inline static M op(M l, M r)\
      \ { return r.is_unit ? l : r; }\n    inline static M unit() { return M(); }\n\
      \n    bool operator==(const M &rhs) const {\n        return is_unit == rhs.is_unit\
      \ and (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const\
      \ {\n        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n \
      \   }\n\n    template <OutputStream OStream>\n    friend OStream &operator<<(OStream\
      \ &os, const M &x) {\n        if (x.is_unit) os << \"unit\";\n        else os\
      \ << x.a;\n        return os;\n    }\n\n    template <InputStream IStream>\n\
      \    friend IStream &operator>>(IStream &is, M &x) {\n        is >> x.a;\n \
      \       x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
      \ monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_HOLD_HPP\n"
    name: default
  - code: "#line 1 \"math/monoid/hold.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\n\
      \n\n\n#include <concepts>\n#include <fstream>\n#include <istream>\n#include\
      \ <ostream>\n#include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits\
      \ {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
      \ntemplate <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
      \ std::istream>::value\n                                  || std::is_same<T,\
      \ std::ifstream>::value,\n                              std::true_type,\n  \
      \                            std::false_type>::type;\ntemplate <typename T>\
      \ using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
      \ std::ostream>::value\n                                  || std::is_same<T,\
      \ std::ofstream>::value,\n                              std::true_type,\n  \
      \                            std::false_type>::type;\ntemplate <typename T>\
      \ using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
      \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
      \n} // namespace kk2\n\n\n#line 5 \"math/monoid/hold.hpp\"\n\nnamespace kk2\
      \ {\n\nnamespace monoid {\n\n/**\n * @brief \u5E38\u306B\u53F3\u5074\u3092\u4FDD\
      \u6301\u3059\u308B\u30E2\u30CE\u30A4\u30C9\n */\ntemplate <class S> struct Hold\
      \ {\n    static constexpr bool commutative = true;\n    using M = Hold;\n\n\
      \    S a;\n    bool is_unit;\n\n    Hold() : is_unit(true) {}\n    Hold(S a_)\
      \ : a(a_), is_unit(false) {}\n    operator S() const { return a; }\n    inline\
      \ static M op(M l, M r) { return r.is_unit ? l : r; }\n    inline static M unit()\
      \ { return M(); }\n\n    bool operator==(const M &rhs) const {\n        return\
      \ is_unit == rhs.is_unit and (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const\
      \ M &rhs) const {\n        return is_unit != rhs.is_unit or (!is_unit and a\
      \ != rhs.a);\n    }\n\n    template <OutputStream OStream>\n    friend OStream\
      \ &operator<<(OStream &os, const M &x) {\n        if (x.is_unit) os << \"unit\"\
      ;\n        else os << x.a;\n        return os;\n    }\n\n    template <InputStream\
      \ IStream>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is\
      \ >> x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} //\
      \ namespace monoid\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/monoid/hold.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/monoid/monoid.test.cpp
  - verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
documentation_of: math/monoid/hold.hpp
layout: document
---
