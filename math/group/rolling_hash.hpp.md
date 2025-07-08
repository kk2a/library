---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':question:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root_64bit.hpp
    title: math_mod/primitive_root_64bit.hpp
  - icon: ':question:'
    path: modint/modint_2_61m1.hpp
    title: modint/modint_2_61m1.hpp
  - icon: ':question:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/hash.hpp
    title: random/hash.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: type_traits/container_traits.hpp
    title: type_traits/container_traits.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/group/group.test.cpp
    title: verify/unit_test/math/group/group.test.cpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_GROUP_ROLLING_HASH_HPP\n#define KK2_MATH_GROUP_ROLLING_HASH_HPP\
    \ 1\n\n#include <vector>\n\n#include \"../../random/hash.hpp\"\n#include \"../../type_traits/container_traits.hpp\"\
    \n#include \"../../type_traits/integral.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ group {\n\ntemplate <int Num> struct RollingHash {\n    static constexpr bool\
    \ commutative = false;\n    using mint = ModInt2_61m1;\n    using M = RollingHash;\n\
    \    using H = random::Hash<Num>;\n\n    inline static H base = H::get_base(),\
    \ inv_base = base.inv();\n\n    H a, pw, ipw;\n    RollingHash() : a(0), pw(1),\
    \ ipw(1) {}\n    RollingHash(H a_, H pw_, H ipw_) : a(a_), pw(pw_), ipw(ipw_)\
    \ {}\n    template <class T, is_integral_t<T> * = nullptr> RollingHash(T x)\n\
    \        : a(x),\n          pw(base),\n          ipw(inv_base) {}\n\n    // s[0]\
    \ * base^0 + s[1] * base^1 + ... + s[n-1] * base^(n-1)\n    template <class C,\
    \ is_container_t<C> * = nullptr> RollingHash(const C &s)\n        : a(0),\n  \
    \        pw(1),\n          ipw(inv_base.pow(s.size())) {\n        for (auto x\
    \ : s) {\n            a += pw * H(x);\n            pw *= base;\n        }\n  \
    \  }\n    operator H() const { return a; }\n    inline static M op(M l, M r) {\
    \ return M(l.a + r.a * l.pw, l.pw * r.pw, l.ipw * r.ipw); }\n    inline static\
    \ M inv(M x) { return M(-x.ipw * x.a, x.ipw, x.pw); }\n    inline static M unit()\
    \ { return M(); }\n    bool operator==(const M &rhs) const { return a == rhs.a\
    \ and pw == rhs.pw and ipw == rhs.ipw; }\n    bool operator!=(const M &rhs) const\
    \ { return a != rhs.a or pw != rhs.pw or ipw != rhs.ipw; }\n\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream &os)\
    \ const {\n        os << \"(\" << a << \", \" << pw << \", \" << ipw << \")\"\
    ;\n    }\n};\n\n} // namespace group\n\n} // namespace kk2\n\n#endif // KK2_MATH_GROUP_ROLLING_HASH_HPP\n"
  dependsOn:
  - random/hash.hpp
  - math_mod/primitive_root_64bit.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  - random/gen.hpp
  - math_mod/pow_mod.hpp
  - modint/modint_2_61m1.hpp
  - random/gen.hpp
  - type_traits/container_traits.hpp
  isVerificationFile: false
  path: math/group/rolling_hash.hpp
  requiredBy: []
  timestamp: '2025-07-08 15:02:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/group/group.test.cpp
documentation_of: math/group/rolling_hash.hpp
layout: document
redirect_from:
- /library/math/group/rolling_hash.hpp
- /library/math/group/rolling_hash.hpp.html
title: math/group/rolling_hash.hpp
---
