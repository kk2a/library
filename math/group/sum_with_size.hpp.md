---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/action/add_sumwithsize.hpp
    title: math/action/add_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/affine_sumwithsize.hpp
    title: math/action/affine_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/update_sumwithsize.hpp
    title: math/action/update_sumwithsize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/action/action.test.cpp
    title: verify/unit_test/math/action/action.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/group/group.test.cpp
    title: verify/unit_test/math/group/group.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/group/sum_with_size.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\
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
    \ kk2\n\n\n#line 5 \"math/group/sum_with_size.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ group {\n\ntemplate <class S, class T = S> struct SumWithSize {\n    static\
    \ constexpr bool commutative = true;\n    using M = SumWithSize;\n    S a;\n \
    \   T size;\n\n    SumWithSize() : a(S()), size(0) {}\n    SumWithSize(S a_, S\
    \ size_ = T(1)) : a(a_), size(size_) {}\n    operator S() const { return a; }\n\
    \    inline static M op(M l, M r) { return M(l.a + r.a, l.size + r.size); }\n\
    \    inline static M inv(M x) { return M(-x.a, -x.size); }\n    inline static\
    \ M unit() { return M(); }\n    bool operator==(const M &rhs) const { return a\
    \ == rhs.a and size == rhs.size; }\n    bool operator!=(const M &rhs) const {\
    \ return a != rhs.a or size != rhs.size; }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const M &x) {\n  \
    \      return os << x.a << \" \" << x.size;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ M &x) {\n        is >> x.a;\n        x.size = T(1);\n        return is;\n  \
    \  }\n};\n\n} // namespace group\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_GROUP_SUM_WITH_SIZE_HPP\n#define KK2_MATH_GROUP_SUM_WITH_SIZE_HPP\
    \ 1\n\n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace group\
    \ {\n\ntemplate <class S, class T = S> struct SumWithSize {\n    static constexpr\
    \ bool commutative = true;\n    using M = SumWithSize;\n    S a;\n    T size;\n\
    \n    SumWithSize() : a(S()), size(0) {}\n    SumWithSize(S a_, S size_ = T(1))\
    \ : a(a_), size(size_) {}\n    operator S() const { return a; }\n    inline static\
    \ M op(M l, M r) { return M(l.a + r.a, l.size + r.size); }\n    inline static\
    \ M inv(M x) { return M(-x.a, -x.size); }\n    inline static M unit() { return\
    \ M(); }\n    bool operator==(const M &rhs) const { return a == rhs.a and size\
    \ == rhs.size; }\n    bool operator!=(const M &rhs) const { return a != rhs.a\
    \ or size != rhs.size; }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const M &x) {\n  \
    \      return os << x.a << \" \" << x.size;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ M &x) {\n        is >> x.a;\n        x.size = T(1);\n        return is;\n  \
    \  }\n};\n\n} // namespace group\n\n} // namespace kk2\n\n#endif // KK2_MATH_GROUP_SUM_WITH_SIZE_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/group/sum_with_size.hpp
  requiredBy:
  - math/action/add_sumwithsize.hpp
  - math/action/update_sumwithsize.hpp
  - math/action/affine_sumwithsize.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/unit_test/math/group/group.test.cpp
  - verify/unit_test/math/action/action.test.cpp
documentation_of: math/group/sum_with_size.hpp
layout: document
redirect_from:
- /library/math/group/sum_with_size.hpp
- /library/math/group/sum_with_size.hpp.html
title: math/group/sum_with_size.hpp
---
