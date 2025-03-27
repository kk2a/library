---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/action/add_max_min_sumwithsize.hpp
    title: math/action/add_max_min_sumwithsize.hpp
  - icon: ':warning:'
    path: math/action/update_max_min_sumwithsize.hpp
    title: math/action/update_max_min_sumwithsize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/monoid.test.cpp
    title: verify/unit_test/monoid.test.cpp
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
  code: "#ifndef KK2_MATH_MONOID_MAX_MIN_SUMWITHSUM_HPP\n#define KK2_MATH_MONOID_MAX_MIN_SUMWITHSUM_HPP\
    \ 1\n\n#include <functional>\n\n#include \"../../type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class T, class\
    \ Compare = std::less<S>>\nstruct MaxMinSumWithSize {\n    static constexpr bool\
    \ commutative = true;\n    using M = MaxMinSumWithSize;\n\n    S max, min, sum;\n\
    \    T size;\n    bool is_unit;\n\n    MaxMinSumWithSize() : is_unit(true) {}\n\
    \n    MaxMinSumWithSize(S a) : max(a), min(a), sum(a), size(1), is_unit(false)\
    \ {}\n\n    MaxMinSumWithSize(S max_, S min_, S sum_, T size_)\n        : max(max_),\n\
    \          min(min_),\n          sum(sum_),\n          size(size_),\n        \
    \  is_unit(false) {}\n\n    inline static M op(M l, M r) {\n        if (l.is_unit\
    \ or r.is_unit) return l.is_unit ? r : l;\n        return M(Compare{}(l.max, r.max)\
    \ ? r.max : l.max,\n                 Compare{}(l.min, r.min) ? l.min : r.min,\n\
    \                 l.sum + r.sum,\n                 l.size + r.size);\n    }\n\n\
    \    inline static M unit() { return M(); }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const M &x) {\n  \
    \      if (x.is_unit) os << \"(unit)\";\n        else\n            os << \"(max:\"\
    \ << x.max << \", min:\" << x.min << \", sum:\" << x.sum << \", size:\" << x.size\n\
    \               << \")\";\n        return os;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ M &x) {\n        S a;\n        is >> a;\n        x = M(a);\n        return is;\n\
    \    }\n\n    bool operator==(const M &rhs) const {\n        return is_unit ==\
    \ rhs.is_unit\n               and (is_unit\n                    or (max == rhs.max\
    \ and min == rhs.min and sum == rhs.sum and size == rhs.size));\n    }\n\n   \
    \ bool operator!=(const M &rhs) const { return !(*this == rhs); }\n};\n\n} //\
    \ namespace monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_MAX_MIN_SUMWITHSUM_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math/monoid/max_min_sumwithsize.hpp
  requiredBy:
  - math/action/add_max_min_sumwithsize.hpp
  - math/action/update_max_min_sumwithsize.hpp
  timestamp: '2025-03-27 00:23:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/monoid.test.cpp
documentation_of: math/monoid/max_min_sumwithsize.hpp
layout: document
redirect_from:
- /library/math/monoid/max_min_sumwithsize.hpp
- /library/math/monoid/max_min_sumwithsize.hpp.html
title: math/monoid/max_min_sumwithsize.hpp
---
