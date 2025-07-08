---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
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
  code: "#ifndef KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\n#define KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\
    \ 1\n\n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\ntemplate <class SM> struct FromSemigroupToMonoid {\n    static constexpr\
    \ bool commutative = SM::commutative;\n    using M = FromSemigroupToMonoid;\n\
    \    SM a;\n    bool is_unit;\n\n    FromSemigroupToMonoid() : is_unit(true) {}\n\
    \    template <class... Args> FromSemigroupToMonoid(Args... args) : a(args...),\
    \ is_unit(false) {}\n\n    inline static M op(M l, M r) {\n        if (l.is_unit\
    \ or r.is_unit) return l.is_unit ? r : l;\n        return M(SM::op(l.a, r.a));\n\
    \    }\n\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
    \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
    \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) return os << \"unit\";\n        return\
    \ os << x.a;\n    }\n\n    template <class IStream, is_istream_t<IStream> * =\
    \ nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is >>\
    \ x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/monoid/from_semigroup_to_monoid.hpp
  requiredBy: []
  timestamp: '2025-04-06 13:01:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/from_semigroup_to_monoid.hpp
layout: document
redirect_from:
- /library/math/monoid/from_semigroup_to_monoid.hpp
- /library/math/monoid/from_semigroup_to_monoid.hpp.html
title: math/monoid/from_semigroup_to_monoid.hpp
---
