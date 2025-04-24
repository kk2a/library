---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/action/add_max.hpp
    title: math/action/add_max.hpp
  - icon: ':warning:'
    path: math/action/add_max_min_sumwithsize.hpp
    title: math/action/add_max_min_sumwithsize.hpp
  - icon: ':warning:'
    path: math/action/add_min.hpp
    title: math/action/add_min.hpp
  - icon: ':warning:'
    path: math/action/add_sumwithsize.hpp
    title: math/action/add_sumwithsize.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_GROUP_ADD_HPP\n#define KK2_MATH_GROUP_ADD_HPP 1\n\n#include\
    \ \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace group {\n\ntemplate\
    \ <class S> struct Add {\n    static constexpr bool commutative = true;\n    using\
    \ M = Add;\n    S a;\n\n    Add() : a(S()) {}\n    Add(S a_) : a(a_) {}\n    operator\
    \ S() const { return a; }\n    inline static M op(M l, M r) { return M(l.a + r.a);\
    \ }\n    inline static M inv(M x) { return M(-x.a); }\n    inline static M unit()\
    \ { return M(); }\n    bool operator==(const M &rhs) const { return a == rhs.a;\
    \ }\n    bool operator!=(const M &rhs) const { return a != rhs.a; }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        return os << x.a;\n    }\n\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        return is >> x.a;\n    }\n};\n\n} // namespace group\n\
    \n} // namespace kk2\n\n#endif // KK2_MATH_GROUP_ADD_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/group/add.hpp
  requiredBy:
  - math/action/add_min.hpp
  - math/action/add_max_min_sumwithsize.hpp
  - math/action/add_max.hpp
  - math/action/add_sumwithsize.hpp
  timestamp: '2025-04-06 13:01:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/group/add.hpp
layout: document
redirect_from:
- /library/math/group/add.hpp
- /library/math/group/add.hpp.html
title: math/group/add.hpp
---
