---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/action/update_affine.hpp
    title: math/action/update_affine.hpp
  - icon: ':warning:'
    path: math/action/update_max.hpp
    title: math/action/update_max.hpp
  - icon: ':warning:'
    path: math/action/update_max_min_sumwithsize.hpp
    title: math/action/update_max_min_sumwithsize.hpp
  - icon: ':warning:'
    path: math/action/update_min.hpp
    title: math/action/update_min.hpp
  - icon: ':warning:'
    path: math/action/update_sumwithsize.hpp
    title: math/action/update_sumwithsize.hpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MONOID_UPDATE_HPP\n#define KK2_MATH_MONOID_UPDATE_HPP 1\n\
    \n#include \"../../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class S>\nstruct Update {\n    static constexpr bool commutative\
    \ = true;\n    S a;\n    bool is_unit;\n\n    Update() : is_unit(true) {}\n\n\
    \    Update(S a_) : a(a_), is_unit(false) {}\n\n    operator S() const { return\
    \ a; }\n\n    inline static Update op(Update l, Update r) { return l.is_unit ?\
    \ r : l; }\n\n    inline static Update unit() { return Update(); }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const Update &update) {\n        if (update.is_unit) os << \"unit\";\n\
    \        else os << update.a;\n        return os;\n    }\n\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, Update &update) {\n        is >> update.a;\n        update.is_unit = false;\n\
    \        return is;\n    }\n\n    bool operator==(const Update &rhs) const {\n\
    \        return is_unit == rhs.is_unit and (is_unit or a == rhs.a);\n    }\n\n\
    \    bool operator!=(const Update &rhs) const { return !(*this == rhs); }\n};\n\
    \n} // namespace monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_UPDATE_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math/monoid/update.hpp
  requiredBy:
  - math/action/update_sumwithsize.hpp
  - math/action/update_max_min_sumwithsize.hpp
  - math/action/update_min.hpp
  - math/action/update_max.hpp
  - math/action/update_affine.hpp
  timestamp: '2025-03-27 00:23:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/update.hpp
layout: document
redirect_from:
- /library/math/monoid/update.hpp
- /library/math/monoid/update.hpp.html
title: math/monoid/update.hpp
---
