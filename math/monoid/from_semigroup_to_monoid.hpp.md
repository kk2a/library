---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/from_semigroup_to_monoid.hpp\"\n\n\n\nnamespace\
    \ kk2 {\n\nnamespace monoid {\n\ntemplate <class SM> struct FromSemigroupToMonoid\
    \ {\n    using M = FromSemigroupToMonoid;\n\n    SM a;\n    bool is_unit;\n\n\
    \    FromSemigroupToMonoid() : is_unit(true) {}\n\n    template <class... Args>\
    \ FromSemigroupToMonoid(Args... args) : a(args...), is_unit(false) {}\n\n    inline\
    \ static M op(M l, M r) {\n        if (l.is_unit or r.is_unit) return l.is_unit\
    \ ? r : l;\n        return M(SM::op(l.a, r.a));\n    }\n\n    inline static M\
    \ unit() { return M(); }\n\n    bool operator==(const M &rhs) const {\n      \
    \  return is_unit == rhs.is_unit and (is_unit or a == rhs.a);\n    }\n\n    bool\
    \ operator!=(const M &rhs) const { return !(*this == rhs); }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\n#define KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\
    \ 1\n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class SM> struct FromSemigroupToMonoid\
    \ {\n    using M = FromSemigroupToMonoid;\n\n    SM a;\n    bool is_unit;\n\n\
    \    FromSemigroupToMonoid() : is_unit(true) {}\n\n    template <class... Args>\
    \ FromSemigroupToMonoid(Args... args) : a(args...), is_unit(false) {}\n\n    inline\
    \ static M op(M l, M r) {\n        if (l.is_unit or r.is_unit) return l.is_unit\
    \ ? r : l;\n        return M(SM::op(l.a, r.a));\n    }\n\n    inline static M\
    \ unit() { return M(); }\n\n    bool operator==(const M &rhs) const {\n      \
    \  return is_unit == rhs.is_unit and (is_unit or a == rhs.a);\n    }\n\n    bool\
    \ operator!=(const M &rhs) const { return !(*this == rhs); }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/monoid/from_semigroup_to_monoid.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/from_semigroup_to_monoid.hpp
layout: document
redirect_from:
- /library/math/monoid/from_semigroup_to_monoid.hpp
- /library/math/monoid/from_semigroup_to_monoid.hpp.html
title: math/monoid/from_semigroup_to_monoid.hpp
---
