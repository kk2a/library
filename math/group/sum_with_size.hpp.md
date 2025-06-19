---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    path: verify/unit_test/action.test.cpp
    title: verify/unit_test/action.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/monoid.test.cpp
    title: verify/unit_test/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
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
  - math/action/affine_sumwithsize.hpp
  - math/action/update_sumwithsize.hpp
  - math/action/add_sumwithsize.hpp
  timestamp: '2025-04-06 13:01:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/unit_test/monoid.test.cpp
  - verify/unit_test/action.test.cpp
documentation_of: math/group/sum_with_size.hpp
layout: document
redirect_from:
- /library/math/group/sum_with_size.hpp
- /library/math/group/sum_with_size.hpp.html
title: math/group/sum_with_size.hpp
---
