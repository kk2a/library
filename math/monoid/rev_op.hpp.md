---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    title: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/rev_op.hpp\"\n\n\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class T> struct ReverseOp : public T {\n    static constexpr\
    \ bool commutative = T::commutative;\n    using M = ReverseOp;\n    using base\
    \ = T;\n    using T::T;\n    ReverseOp(const T &t) : T(t) {}\n    inline static\
    \ M op(M l, M r) {\n        return static_cast<M>(T::op(static_cast<T>(r), static_cast<T>(l)));\n\
    \    }\n    inline static M unit() { return static_cast<M>(T::unit()); }\n\n \
    \   bool operator==(const M &rhs) const { return static_cast<T>(*this) == static_cast<T>(rhs);\
    \ }\n    bool operator!=(const M &rhs) const { return static_cast<T>(*this) !=\
    \ static_cast<T>(rhs); }\n    template <class OStream, is_ostream_t<OStream> *\
    \ = nullptr>\n    friend OStream &operator<<(OStream &os, const M &x) {\n    \
    \    os << static_cast<T>(x);\n        return os;\n    }\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        is >> static_cast<T &>(x);\n        return is;\n    }\n\
    };\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MONOID_REV_OP_HPP\n#define KK2_MATH_MONOID_REV_OP_HPP 1\n\
    \nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class T> struct ReverseOp\
    \ : public T {\n    static constexpr bool commutative = T::commutative;\n    using\
    \ M = ReverseOp;\n    using base = T;\n    using T::T;\n    ReverseOp(const T\
    \ &t) : T(t) {}\n    inline static M op(M l, M r) {\n        return static_cast<M>(T::op(static_cast<T>(r),\
    \ static_cast<T>(l)));\n    }\n    inline static M unit() { return static_cast<M>(T::unit());\
    \ }\n\n    bool operator==(const M &rhs) const { return static_cast<T>(*this)\
    \ == static_cast<T>(rhs); }\n    bool operator!=(const M &rhs) const { return\
    \ static_cast<T>(*this) != static_cast<T>(rhs); }\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream &os,\
    \ const M &x) {\n        os << static_cast<T>(x);\n        return os;\n    }\n\
    \    template <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream\
    \ &operator>>(IStream &is, M &x) {\n        is >> static_cast<T &>(x);\n     \
    \   return is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n#endif\
    \ // KK2_MATH_MONOID_REV_OP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/monoid/rev_op.hpp
  requiredBy: []
  timestamp: '2025-08-01 16:41:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
documentation_of: math/monoid/rev_op.hpp
layout: document
redirect_from:
- /library/math/monoid/rev_op.hpp
- /library/math/monoid/rev_op.hpp.html
title: math/monoid/rev_op.hpp
---
