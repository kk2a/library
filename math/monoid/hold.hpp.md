---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/monoid.test.cpp
    title: verify/unit_test/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
    title: verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5E38\u306B\u53F3\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\
      \u30A4\u30C9"
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
  code: "#ifndef KK2_MATH_MONOID_HOLD_HPP\n#define KK2_MATH_MONOID_HOLD_HPP 1\n\n\
    #include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid {\n\
    \n/**\n * @brief \u5E38\u306B\u53F3\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\
    \u30A4\u30C9\n */\ntemplate <class S> struct Hold {\n    static constexpr bool\
    \ commutative = true;\n    using M = Hold;\n\n    S a;\n    bool is_unit;\n\n\
    \    Hold() : is_unit(true) {}\n    Hold(S a_) : a(a_), is_unit(false) {}\n  \
    \  operator S() const { return a; }\n    inline static M op(M l, M r) { return\
    \ r.is_unit ? l : r; }\n    inline static M unit() { return M(); }\n\n    bool\
    \ operator==(const M &rhs) const {\n        return is_unit == rhs.is_unit and\
    \ (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n\
    \        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n\
    \    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream\
    \ &operator<<(OStream &os, const M &x) {\n        if (x.is_unit) os << \"unit\"\
    ;\n        else os << x.a;\n        return os;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return is;\n\
    \    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_HOLD_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/monoid/hold.hpp
  requiredBy: []
  timestamp: '2025-06-06 16:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
  - verify/unit_test/monoid.test.cpp
documentation_of: math/monoid/hold.hpp
layout: document
redirect_from:
- /library/math/monoid/hold.hpp
- /library/math/monoid/hold.hpp.html
title: "\u5E38\u306B\u53F3\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\u30C9"
---
