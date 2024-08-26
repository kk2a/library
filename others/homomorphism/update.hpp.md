---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  bundledCode: "#line 1 \"others/homomorphism/update.hpp\"\n\n\n\nnamespace kk2 {\n\
    \nnamespace homomorphism {\n\ntemplate <class S>\nstruct Update {\n    S a;\n\
    \    bool id;\n    Update() : a(0), id(true) {}\n    Update(S a_, bool id_ = false)\
    \ : a(a_), id(id_) {}\n    operator S() const { return a; }\n    friend ostream&\
    \ operator<<(ostream& os, const Update& update) {\n        os << (update.id ?\
    \ \"id\" : to_string(update.a));\n        return os;\n    }\n\n    Update& composition(const\
    \ Update& rhs) {\n        if (rhs.id) return *this;\n        return *this = rhs;\n\
    \    }\n};\n\ntemplate <class S, class T>\nT UpdateMap(Update<S> f, T x) { return\
    \ f.id ? x : x.update(f.a); }\n\ntemplate <class S>\nUpdate<S> UpdateComposition(Update<S>\
    \ l, Update<S> r) { return l.composition(r); }\n\ntemplate <class S>\nUpdate<S>\
    \ UpdateUnit() { return Update<S>(); }\n\n} // namespace homomorphism\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef OTHERS_HOMOMORPHISM_UPDATE_HPP\n#define OTHERS_HOMOMORPHISM_UPDATE_HPP\
    \ 1\n\nnamespace kk2 {\n\nnamespace homomorphism {\n\ntemplate <class S>\nstruct\
    \ Update {\n    S a;\n    bool id;\n    Update() : a(0), id(true) {}\n    Update(S\
    \ a_, bool id_ = false) : a(a_), id(id_) {}\n    operator S() const { return a;\
    \ }\n    friend ostream& operator<<(ostream& os, const Update& update) {\n   \
    \     os << (update.id ? \"id\" : to_string(update.a));\n        return os;\n\
    \    }\n\n    Update& composition(const Update& rhs) {\n        if (rhs.id) return\
    \ *this;\n        return *this = rhs;\n    }\n};\n\ntemplate <class S, class T>\n\
    T UpdateMap(Update<S> f, T x) { return f.id ? x : x.update(f.a); }\n\ntemplate\
    \ <class S>\nUpdate<S> UpdateComposition(Update<S> l, Update<S> r) { return l.composition(r);\
    \ }\n\ntemplate <class S>\nUpdate<S> UpdateUnit() { return Update<S>(); }\n\n\
    } // namespace homomorphism\n\n} // namespace kk2\n\n#endif // OTHERS_HOMOMORPHISM_UPDATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/homomorphism/update.hpp
  requiredBy:
  - segment_tree/utility/updatesum.hpp
  - segment_tree/utility/updatemax.hpp
  - segment_tree/utility/updatemin.hpp
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/homomorphism/update.hpp
layout: document
redirect_from:
- /library/others/homomorphism/update.hpp
- /library/others/homomorphism/update.hpp.html
title: others/homomorphism/update.hpp
---
