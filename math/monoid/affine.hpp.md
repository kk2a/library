---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/action/affine_sumwithsize.hpp
    title: math/action/affine_sumwithsize.hpp
  - icon: ':warning:'
    path: math/action/update_affine.hpp
    title: math/action/update_affine.hpp
  _extendedVerifiedWith:
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
    path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MONOID_AFFINE_HPP\n#define KK2_MATH_MONOID_AFFINE_HPP 1\n\
    \n#include \"../../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class S>\nstruct Affine {\n    static constexpr bool commutative\
    \ = false;\n\n    S a, b; // x \\mapsto ax + b\n    Affine() : a(S(1)), b(S(0))\
    \ {};\n\n    Affine(S a, S b) : a(a), b(b) {}\n\n    inline S eval(S x) const\
    \ { return a * x + b; }\n\n    // l \\circ r\n    inline static Affine op(Affine\
    \ l, Affine r) { return Affine(l.a * r.a, l.a * r.b + l.b); }\n\n    inline static\
    \ Affine unit() { return Affine(); }\n\n    inline static Affine inv(Affine f)\
    \ { return Affine(S(1) / f.a, -f.b / f.a); }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const Affine &aff)\
    \ {\n        return os << aff.a << \" \" << aff.b;\n    }\n\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, Affine &aff) {\n        return is >> aff.a >> aff.b;\n    }\n\n    bool\
    \ operator==(const Affine &rhs) const { return a == rhs.a and b == rhs.b; }\n\n\
    \    bool operator!=(const Affine &rhs) const { return not(*this == rhs); }\n\
    };\n\n} // namespace monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_AFFINE_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math/monoid/affine.hpp
  requiredBy:
  - math/action/affine_sumwithsize.hpp
  - math/action/update_affine.hpp
  timestamp: '2025-03-27 00:23:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
documentation_of: math/monoid/affine.hpp
layout: document
redirect_from:
- /library/math/monoid/affine.hpp
- /library/math/monoid/affine.hpp.html
title: math/monoid/affine.hpp
---
