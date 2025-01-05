---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment_tree/utility/update_max_min_sum.hpp
    title: segment_tree/utility/update_max_min_sum.hpp
  - icon: ':warning:'
    path: segment_tree/utility/updatemax.hpp
    title: segment_tree/utility/updatemax.hpp
  - icon: ':warning:'
    path: segment_tree/utility/updatemin.hpp
    title: segment_tree/utility/updatemin.hpp
  - icon: ':warning:'
    path: segment_tree/utility/updatesum.hpp
    title: segment_tree/utility/updatesum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/homomorphism/update.hpp\"\n\n\n\n#include <iostream>\n\
    \nnamespace kk2 {\n\nnamespace homomorphism {\n\ntemplate <class S> struct Update\
    \ {\n    S a;\n    bool id;\n\n    constexpr Update() : a(S()), id(true) {}\n\n\
    \    constexpr Update(S a_, bool id_ = false) : a(a_), id(id_) {}\n\n    operator\
    \ S() const { return a; }\n\n    template <class OStream>\n    friend OStream\
    \ &operator<<(OStream &os, const Update &update) {\n        if (update.id) os\
    \ << \"id\";\n        else os << update.a;\n        return os;\n    }\n};\n\n\
    template <class S, class T> constexpr T UpdateMap(Update<S> f, T x) {\n    return\
    \ f.id ? x : x.update(f.a);\n}\n\ntemplate <class S> constexpr Update<S> UpdateComposition(Update<S>\
    \ l, Update<S> r) {\n    if (l.id) return r;\n    return l;\n}\n\ntemplate <class\
    \ S> Update<S> UpdateUnit() {\n    constexpr static Update<S> e = Update<S>();\n\
    \    return e;\n}\n\n} // namespace homomorphism\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_HOMOMORPHISM_UPDATE_HPP\n#define KK2_MATH_HOMOMORPHISM_UPDATE_HPP\
    \ 1\n\n#include <iostream>\n\nnamespace kk2 {\n\nnamespace homomorphism {\n\n\
    template <class S> struct Update {\n    S a;\n    bool id;\n\n    constexpr Update()\
    \ : a(S()), id(true) {}\n\n    constexpr Update(S a_, bool id_ = false) : a(a_),\
    \ id(id_) {}\n\n    operator S() const { return a; }\n\n    template <class OStream>\n\
    \    friend OStream &operator<<(OStream &os, const Update &update) {\n       \
    \ if (update.id) os << \"id\";\n        else os << update.a;\n        return os;\n\
    \    }\n};\n\ntemplate <class S, class T> constexpr T UpdateMap(Update<S> f, T\
    \ x) {\n    return f.id ? x : x.update(f.a);\n}\n\ntemplate <class S> constexpr\
    \ Update<S> UpdateComposition(Update<S> l, Update<S> r) {\n    if (l.id) return\
    \ r;\n    return l;\n}\n\ntemplate <class S> Update<S> UpdateUnit() {\n    constexpr\
    \ static Update<S> e = Update<S>();\n    return e;\n}\n\n} // namespace homomorphism\n\
    \n} // namespace kk2\n\n#endif // KK2_MATH_HOMOMORPHISM_UPDATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/homomorphism/update.hpp
  requiredBy:
  - segment_tree/utility/updatemax.hpp
  - segment_tree/utility/updatesum.hpp
  - segment_tree/utility/updatemin.hpp
  - segment_tree/utility/update_max_min_sum.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/homomorphism/update.hpp
layout: document
redirect_from:
- /library/math/homomorphism/update.hpp
- /library/math/homomorphism/update.hpp.html
title: math/homomorphism/update.hpp
---
