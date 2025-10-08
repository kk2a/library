---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/action/affine_sumwithsize.hpp
    title: math/action/affine_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_affine.hpp
    title: math/action/update_affine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/action/action.test.cpp
    title: verify/unit_test/math/action/action.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/monoid/monoid.test.cpp
    title: verify/unit_test/math/monoid/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    title: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/affine.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\
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
    \ kk2\n\n\n#line 5 \"math/monoid/affine.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class S> struct Affine {\n    static constexpr bool commutative\
    \ = false;\n    using M = Affine;\n    S a, b; // x \\mapsto ax + b\n\n    Affine()\
    \ : a(S(1)), b(S(0)) {};\n    Affine(S a, S b) : a(a), b(b) {}\n    inline S eval(S\
    \ x) const { return a * x + b; }\n    // l \\circ r\n    inline static M op(M\
    \ l, M r) { return M(l.a * r.a, l.a * r.b + l.b); }\n    inline static M unit()\
    \ { return M(); }\n    inline static M inv(M f) { return M(S(1) / f.a, -f.b /\
    \ f.a); }\n    bool operator==(const M &rhs) const { return a == rhs.a and b ==\
    \ rhs.b; }\n    bool operator!=(const M &rhs) const { return a != rhs.a or b !=\
    \ rhs.b; }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    friend OStream &operator<<(OStream &os, const M &x) {\n        return os\
    \ << x.a << \" \" << x.b;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        return\
    \ is >> x.a >> x.b;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef KK2_MATH_MONOID_AFFINE_HPP\n#define KK2_MATH_MONOID_AFFINE_HPP 1\n\
    \n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\ntemplate <class S> struct Affine {\n    static constexpr bool commutative\
    \ = false;\n    using M = Affine;\n    S a, b; // x \\mapsto ax + b\n\n    Affine()\
    \ : a(S(1)), b(S(0)) {};\n    Affine(S a, S b) : a(a), b(b) {}\n    inline S eval(S\
    \ x) const { return a * x + b; }\n    // l \\circ r\n    inline static M op(M\
    \ l, M r) { return M(l.a * r.a, l.a * r.b + l.b); }\n    inline static M unit()\
    \ { return M(); }\n    inline static M inv(M f) { return M(S(1) / f.a, -f.b /\
    \ f.a); }\n    bool operator==(const M &rhs) const { return a == rhs.a and b ==\
    \ rhs.b; }\n    bool operator!=(const M &rhs) const { return a != rhs.a or b !=\
    \ rhs.b; }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    friend OStream &operator<<(OStream &os, const M &x) {\n        return os\
    \ << x.a << \" \" << x.b;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        return\
    \ is >> x.a >> x.b;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\
    \n#endif // KK2_MATH_MONOID_AFFINE_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/monoid/affine.hpp
  requiredBy:
  - math/action/update_affine.hpp
  - math/action/affine_sumwithsize.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  - verify/unit_test/math/monoid/monoid.test.cpp
  - verify/unit_test/math/action/action.test.cpp
documentation_of: math/monoid/affine.hpp
layout: document
redirect_from:
- /library/math/monoid/affine.hpp
- /library/math/monoid/affine.hpp.html
title: math/monoid/affine.hpp
---
