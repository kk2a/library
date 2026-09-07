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
    - filename: ds_point_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    - filename: ds_point_set_range_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    - filename: ds_point_set_range_composite_large_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
    - filename: tree_vertex_set_path_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MONOID_REV_OP_HPP\n#define KK2_MATH_MONOID_REV_OP_HPP\
      \ 1\n\n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace\
      \ monoid {\n\ntemplate <class T> struct ReverseOp : public T {\n    static constexpr\
      \ bool commutative = T::commutative;\n    using M = ReverseOp;\n    using base\
      \ = T;\n    using T::T;\n    ReverseOp(const T &t) : T(t) {}\n    inline static\
      \ M op(M l, M r) {\n        return static_cast<M>(T::op(static_cast<T>(r), static_cast<T>(l)));\n\
      \    }\n    inline static M unit() { return static_cast<M>(T::unit()); }\n\n\
      \    bool operator==(const M &rhs) const { return static_cast<T>(*this) == static_cast<T>(rhs);\
      \ }\n    bool operator!=(const M &rhs) const { return static_cast<T>(*this)\
      \ != static_cast<T>(rhs); }\n    template <OutputStream OStream>\n    friend\
      \ OStream &operator<<(OStream &os, const M &x) {\n        os << static_cast<T>(x);\n\
      \        return os;\n    }\n    template <InputStream IStream>\n    friend IStream\
      \ &operator>>(IStream &is, M &x) {\n        is >> static_cast<T &>(x);\n   \
      \     return is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\
      \n#endif // KK2_MATH_MONOID_REV_OP_HPP\n"
    name: default
  - code: "#line 1 \"math/monoid/rev_op.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\
      \n\n\n\n#include <concepts>\n#include <fstream>\n#include <istream>\n#include\
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
      \n} // namespace kk2\n\n\n#line 5 \"math/monoid/rev_op.hpp\"\n\nnamespace kk2\
      \ {\n\nnamespace monoid {\n\ntemplate <class T> struct ReverseOp : public T\
      \ {\n    static constexpr bool commutative = T::commutative;\n    using M =\
      \ ReverseOp;\n    using base = T;\n    using T::T;\n    ReverseOp(const T &t)\
      \ : T(t) {}\n    inline static M op(M l, M r) {\n        return static_cast<M>(T::op(static_cast<T>(r),\
      \ static_cast<T>(l)));\n    }\n    inline static M unit() { return static_cast<M>(T::unit());\
      \ }\n\n    bool operator==(const M &rhs) const { return static_cast<T>(*this)\
      \ == static_cast<T>(rhs); }\n    bool operator!=(const M &rhs) const { return\
      \ static_cast<T>(*this) != static_cast<T>(rhs); }\n    template <OutputStream\
      \ OStream>\n    friend OStream &operator<<(OStream &os, const M &x) {\n    \
      \    os << static_cast<T>(x);\n        return os;\n    }\n    template <InputStream\
      \ IStream>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is\
      \ >> static_cast<T &>(x);\n        return is;\n    }\n};\n\n} // namespace monoid\n\
      \n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/monoid/rev_op.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
documentation_of: math/monoid/rev_op.hpp
layout: document
---
