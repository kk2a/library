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
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/static_rolling_hash.test.cpp
    title: verify/unit_test/string/static_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\u306A\u3044\
      \u6587\u5B57\u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\u30FC\u30EA\
      \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
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
  code: "#ifndef KK2_STRING_ROLLING_HASH_HPP\n#define KK2_STRING_ROLLING_HASH_HPP\
    \ 1\n\n#include <cassert>\n#include <string>\n#include <vector>\n\n#include \"\
    ../random/hash.hpp\"\n#include \"../type_traits/container_traits.hpp\"\n\nnamespace\
    \ kk2 {\n\n/**\n * @brief \u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\
    \u306A\u3044\u6587\u5B57\u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\
    \u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * @tparam NUM\n */\ntemplate\
    \ <int NUM> struct StaticRollingHash {\n    using H = random::Hash<NUM>;\n   \
    \ static inline std::vector<H> pw, pwi;\n    std::vector<H> prefix;\n\n    StaticRollingHash()\
    \ {}\n    template <class T, is_integral_t<T> * = nullptr> StaticRollingHash(T\
    \ v) : prefix({H(v)}) {}\n    template <class C, is_container_t<C> * = nullptr>\
    \ StaticRollingHash(const C &c) {\n        if (c.empty()) return;\n        extend_base(c.size());\n\
    \        prefix.resize(c.size());\n        prefix[0] = H(c[0]);\n        for (size_t\
    \ i = 1; i < c.size(); ++i) prefix[i] = prefix[i - 1] + H(c[i]) * pw[i];\n   \
    \ }\n\n    inline int size() const { return prefix.size(); }\n\n    // `i`\u756A\
    \u76EE\u306E\u6587\u5B57\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\n    H get(int i) const {\n        assert(0 <= i and i < (int)prefix.size());\n\
    \        if (i == 0) return prefix[i];\n        return (prefix[i] - prefix[i -\
    \ 1]) * pwi[i];\n    }\n\n    // `[l, r)`\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\
    \u53D6\u5F97\u3059\u308B\n    H get(int l, int r) const {\n        assert(0 <=\
    \ l and l <= r and r <= (int)prefix.size());\n        if (l == r) return H(0);\n\
    \        if (l == 0) return prefix[r - 1];\n        return (prefix[r - 1] - prefix[l\
    \ - 1]) * pwi[l];\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217`lhs[l1,\
    \ r1)`\u3068`rhs[l2, r2)`\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u3092\
    \u6C42\u3081\u308B\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF: `O(log(min(r1\
    \ - l1, r2 - l2)))`\n     * @param lhs \u6587\u5B57\u5217`lhs`\u306E\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param l1 `lhs`\u306E\u958B\
    \u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param r1 `lhs`\u306E\u7D42\
    \u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param rhs \u6587\u5B57\u5217\
    `rhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param\
    \ l2 `rhs`\u306E\u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param\
    \ r2 `rhs`\u306E\u7D42\u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ `lhs[l1, l1 + lcp)`\u3068`rhs[l2, l2 + lcp)`\u306E\u6700\u9577\u5171\u901A\u63A5\
    \u982D\u8F9E\u306E\u9577\u3055\n     */\n    static int lcp(const StaticRollingHash\
    \ &lhs,\n                   int l1,\n                   int r1,\n            \
    \       const StaticRollingHash &rhs,\n                   int l2,\n          \
    \         int r2) {\n        int len = std::min(r1 - l1, r2 - l2);\n        int\
    \ ok = 0, ng = len + 1;\n        while (ng - ok > 1) {\n            int mid =\
    \ (ok + ng) / 2;\n            if (lhs.get(l1, l1 + mid) == rhs.get(l2, l2 + mid))\
    \ {\n                ok = mid;\n            } else {\n                ng = mid;\n\
    \            }\n        }\n        return ok;\n    }\n\n    /**\n     * @brief\
    \ \u6587\u5B57\u5217`lhs[l1, r1)`\u3068`rhs[l2, r2)`\u306E\u8F9E\u66F8\u9806\u6BD4\
    \u8F03\u3092\u884C\u3046\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF: `O(log(min(r1\
    \ - l1, r2 - l2)))`\n     * @param lhs \u6587\u5B57\u5217`lhs`\u306E\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param l1 `lhs`\u306E\u958B\
    \u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param r1 `lhs`\u306E\u7D42\
    \u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param rhs \u6587\u5B57\u5217\
    `rhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param\
    \ l2 `rhs`\u306E\u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param\
    \ r2 `rhs`\u306E\u7D42\u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ `-1: lhs < rhs, 0: lhs == rhs, 1: lhs > rhs`\n     */\n    static int strcmp(const\
    \ StaticRollingHash &lhs,\n                      int l1,\n                   \
    \   int r1,\n                      const StaticRollingHash &rhs,\n           \
    \           int l2,\n                      int r2) {\n        int lcp_ = lcp(lhs,\
    \ l1, r1, rhs, l2, r2);\n        if (lcp_ == r1 - l1 and lcp_ == r2 - l2) return\
    \ 0;\n        else if (lcp_ == r1 - l1) return -1;\n        else if (lcp_ == r2\
    \ - l2) return 1;\n        else {\n            auto c1 = lhs.get(l1 + lcp_)[0].val();\n\
    \            auto c2 = rhs.get(l2 + lcp_)[0].val();\n            return c1 < c2\
    \ ? -1 : 1;\n        }\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217`lhs`\u3068\
    `rhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3092\u7D50\u5408\
    \u3059\u308B\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF: `O(lhs.size() + rhs.size())`\n\
    \     *\n     * @param lhs \u6587\u5B57\u5217`lhs`\u306E\u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param rhs \u6587\u5B57\u5217`rhs`\u306E\
    \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @return \u7D50\u5408\
    \u3055\u308C\u305F\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n   \
    \  */\n    static StaticRollingHash merge(const StaticRollingHash &lhs, const\
    \ StaticRollingHash &rhs) {\n        if (lhs.prefix.empty()) return rhs;\n   \
    \     if (rhs.prefix.empty()) return lhs;\n        StaticRollingHash res;\n  \
    \      int n = lhs.prefix.size(), m = rhs.prefix.size();\n        extend_base(n\
    \ + m);\n        res.prefix.resize(n + m);\n        for (int i = 0; i < n; ++i)\
    \ res.prefix[i] = lhs.prefix[i];\n        for (int i = n; i < n + m; ++i)\n  \
    \          res.prefix[i] = res.prefix[n - 1] + rhs.prefix[i - n] * pw[n];\n  \
    \      return res;\n    }\n\n  private:\n    static void extend_base(int m) {\n\
    \        if (pw.size() == 0u) pw = {H(1), H::get_base()}, pwi = {H(1), pw[1].inv()};\n\
    \n        int n = pw.size();\n        if (n > m) return;\n        pw.resize(m\
    \ + 1), pwi.resize(m + 1);\n        for (int i = n; i <= m; ++i) pw[i] = pw[i\
    \ - 1] * pw[1], pwi[i] = pwi[i - 1] * pwi[1];\n    }\n};\n\nusing SRoliha = StaticRollingHash<2>;\n\
    \n} // namespace kk2\n\n\n#endif // KK2_STRING_ROLLING_HASH_HPP\n"
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
  path: string/static_rolling_hash.hpp
  requiredBy: []
  timestamp: '2025-07-08 15:02:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
documentation_of: string/static_rolling_hash.hpp
layout: document
redirect_from:
- /library/string/static_rolling_hash.hpp
- /library/string/static_rolling_hash.hpp.html
title: "\u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\u306A\u3044\u6587\u5B57\
  \u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\
  \u30C3\u30B7\u30E5"
---
