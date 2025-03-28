---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/action/add_sumwithsize.hpp
    title: math/action/add_sumwithsize.hpp
  - icon: ':question:'
    path: math/action/affine_sumwithsize.hpp
    title: math/action/affine_sumwithsize.hpp
  - icon: ':warning:'
    path: math/action/update_sumwithsize.hpp
    title: math/action/update_sumwithsize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  code: "#ifndef KK2_MATH_GROUP_SUM_WITH_SIZE_HPP\n#define KK2_MATH_GROUP_SUM_WITH_SIZE_HPP\
    \ 1\n\n#include \"../../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ group {\n\ntemplate <class S, class T = S>\nstruct SumWithSize {\n    static\
    \ constexpr bool commutative = true;\n    using M = SumWithSize;\n\n    S a;\n\
    \    T size;\n\n    SumWithSize() : a(S{}), size(0) {}\n\n    SumWithSize(S a_,\
    \ S size_ = T(1)) : a(a_), size(size_) {}\n\n    operator S() const { return a;\
    \ }\n\n    inline static M op(M l, M r) { return M(l.a + r.a, l.size + r.size);\
    \ }\n\n    inline static M inv(M x) { return M(-x.a, -x.size); }\n\n    inline\
    \ static M unit() { return M(); }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const M &sum) {\n\
    \        os << sum.a;\n        return os;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ M &sum) {\n        is >> sum.a;\n        sum.size = T(1);\n        return is;\n\
    \    }\n\n    bool operator==(const M &rhs) const { return a == rhs.a and size\
    \ == rhs.size; }\n\n    bool operator!=(const M &rhs) const { return !(*this ==\
    \ rhs); }\n};\n\n} // namespace group\n\n} // namespace kk2\n\n#endif // KK2_MATH_GROUP_SUM_WITH_SIZE_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math/group/sum_with_size.hpp
  requiredBy:
  - math/action/update_sumwithsize.hpp
  - math/action/affine_sumwithsize.hpp
  - math/action/add_sumwithsize.hpp
  timestamp: '2025-03-27 00:23:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
documentation_of: math/group/sum_with_size.hpp
layout: document
redirect_from:
- /library/math/group/sum_with_size.hpp
- /library/math/group/sum_with_size.hpp.html
title: math/group/sum_with_size.hpp
---
