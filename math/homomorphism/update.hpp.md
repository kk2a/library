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
  bundledCode: "#line 1 \"math/homomorphism/update.hpp\"\n\n\n\n#include <iostream>\n\
    #include <string>\n\nnamespace kk2 {\n\nnamespace homomorphism {\n\ntemplate <class\
    \ S> struct Update {\n    S a;\n    bool id;\n\n    Update() : a(S()), id(true)\
    \ {}\n\n    Update(S a_, bool id_ = false) : a(a_), id(id_) {}\n\n    operator\
    \ S() const { return a; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Update &update) {\n        os << (update.id ? \"id\" : std::to_string(update.a));\n\
    \        return os;\n    }\n\n    Update &composition(const Update &f) {\n   \
    \     if (f.id) return *this;\n        return *this = f;\n    }\n};\n\ntemplate\
    \ <class S, class T> T UpdateMap(Update<S> f, T x) {\n    return f.id ? x : x.update(f.a);\n\
    }\n\ntemplate <class S> Update<S> UpdateComposition(Update<S> l, Update<S> r)\
    \ {\n    return r.composition(l);\n}\n\ntemplate <class S> Update<S> UpdateUnit()\
    \ {\n    return Update<S>();\n}\n\n} // namespace homomorphism\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef MATH_HOMOMORPHISM_UPDATE_HPP\n#define MATH_HOMOMORPHISM_UPDATE_HPP\
    \ 1\n\n#include <iostream>\n#include <string>\n\nnamespace kk2 {\n\nnamespace\
    \ homomorphism {\n\ntemplate <class S> struct Update {\n    S a;\n    bool id;\n\
    \n    Update() : a(S()), id(true) {}\n\n    Update(S a_, bool id_ = false) : a(a_),\
    \ id(id_) {}\n\n    operator S() const { return a; }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Update &update) {\n        os << (update.id\
    \ ? \"id\" : std::to_string(update.a));\n        return os;\n    }\n\n    Update\
    \ &composition(const Update &f) {\n        if (f.id) return *this;\n        return\
    \ *this = f;\n    }\n};\n\ntemplate <class S, class T> T UpdateMap(Update<S> f,\
    \ T x) {\n    return f.id ? x : x.update(f.a);\n}\n\ntemplate <class S> Update<S>\
    \ UpdateComposition(Update<S> l, Update<S> r) {\n    return r.composition(l);\n\
    }\n\ntemplate <class S> Update<S> UpdateUnit() {\n    return Update<S>();\n}\n\
    \n} // namespace homomorphism\n\n} // namespace kk2\n\n#endif // MATH_HOMOMORPHISM_UPDATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/homomorphism/update.hpp
  requiredBy:
  - segment_tree/utility/updatesum.hpp
  - segment_tree/utility/updatemin.hpp
  - segment_tree/utility/updatemax.hpp
  timestamp: '2024-09-10 08:16:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/homomorphism/update.hpp
layout: document
redirect_from:
- /library/math/homomorphism/update.hpp
- /library/math/homomorphism/update.hpp.html
title: math/homomorphism/update.hpp
---
