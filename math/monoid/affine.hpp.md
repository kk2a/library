---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
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
  timestamp: '2025-04-06 13:01:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/action/action.test.cpp
  - verify/unit_test/math/monoid/monoid.test.cpp
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
documentation_of: math/monoid/affine.hpp
layout: document
redirect_from:
- /library/math/monoid/affine.hpp
- /library/math/monoid/affine.hpp.html
title: math/monoid/affine.hpp
---
