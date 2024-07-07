---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment_tree/utility/affinesum.hpp
    title: segment_tree/utility/affinesum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/homomorphism/affine.hpp\"\n\n\n\nnamespace homomorphism\
    \ {\n\ntemplate <class S>\nstruct Affine {\n    S a, b; // x \\mapsto ax + b\n\
    \    Affine() : a(1), b(0) {};\n    Affine(S a, S b) : a(a), b(b) {}\n    friend\
    \ ostream& operator<<(ostream& os, const Affine& aff) {\n        os << aff.a <<\
    \ \" \" << aff.b;\n        return os;\n    }\n\n    Affine& composition(const\
    \ Affine& rhs) {\n        return *this = Affine(a * rhs.a, a * rhs.b + b);\n \
    \   }\n};\n\ntemplate <class S, class T>\nT AffineMap(Affine<S> f, T x) { return\
    \ x.multiply(f.a).add(f.b); }\n\ntemplate <class S>\nAffine<S> AffineComposition(Affine<S>\
    \ l, Affine<S> r) { return l.composition(r); }\n\ntemplate <class S>\nAffine<S>\
    \ AffineUnit() { return Affine<S>(); }\n\n} // namespace homomorphism\n\n\n"
  code: "#ifndef OTHERS_HOMOMORPHISM_AFFINE_HPP\n#define OTHERS_HOMOMORPHISM_AFFINE_HPP\
    \ 1\n\nnamespace homomorphism {\n\ntemplate <class S>\nstruct Affine {\n    S\
    \ a, b; // x \\mapsto ax + b\n    Affine() : a(1), b(0) {};\n    Affine(S a, S\
    \ b) : a(a), b(b) {}\n    friend ostream& operator<<(ostream& os, const Affine&\
    \ aff) {\n        os << aff.a << \" \" << aff.b;\n        return os;\n    }\n\n\
    \    Affine& composition(const Affine& rhs) {\n        return *this = Affine(a\
    \ * rhs.a, a * rhs.b + b);\n    }\n};\n\ntemplate <class S, class T>\nT AffineMap(Affine<S>\
    \ f, T x) { return x.multiply(f.a).add(f.b); }\n\ntemplate <class S>\nAffine<S>\
    \ AffineComposition(Affine<S> l, Affine<S> r) { return l.composition(r); }\n\n\
    template <class S>\nAffine<S> AffineUnit() { return Affine<S>(); }\n\n} // namespace\
    \ homomorphism\n\n#endif // OTHERS_HOMOMORPHISM_AFFINE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/homomorphism/affine.hpp
  requiredBy:
  - segment_tree/utility/affinesum.hpp
  timestamp: '2024-07-07 19:16:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/homomorphism/affine.hpp
layout: document
redirect_from:
- /library/others/homomorphism/affine.hpp
- /library/others/homomorphism/affine.hpp.html
title: others/homomorphism/affine.hpp
---
