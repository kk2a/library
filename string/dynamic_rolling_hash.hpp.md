---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_root_64bit.hpp
    title: math_mod/primitive_root_64bit.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint_2_61m1.hpp
    title: modint/modint_2_61m1.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash.hpp
    title: random/hash.hpp
  - icon: ':heavy_check_mark:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/container_traits.hpp
    title: type_traits/container_traits.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\
      \u5B57\u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\
      \u30B0\u30CF\u30C3\u30B7\u30E5"
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_STRING_DYNAMIC_ROLLING_HASH_HPP\n#define KK2_STRING_DYNAMIC_ROLLING_HASH_HPP\n\
    \n#include <cassert>\n#include <vector>\n\n#include \"../bit/bitcount.hpp\"\n\
    #include \"../random/hash.hpp\"\n#include \"../type_traits/container_traits.hpp\"\
    \n\nnamespace kk2 {\n\n/**\n * @brief \u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\
    \u304C\u53EF\u80FD\u6587\u5B57\u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\
    \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * @tparam NUM\n */\n\
    template <int NUM> struct DynamicRollingHash {\n    using H = random::Hash<NUM>;\n\
    \    int _n, lg, siz;\n    std::vector<H> d;\n    bool is_built = false;\n\n \
    \   DynamicRollingHash() {}\n    DynamicRollingHash(int n) : _n(n) {\n       \
    \ lg = 0;\n        while ((1 << lg) < _n) lg++;\n        extend_base(lg + 1);\n\
    \        siz = 1 << lg;\n        d.resize(2 * siz);\n    }\n    template <class\
    \ C, is_container_t<C> * = nullptr> DynamicRollingHash(const C &c) {\n       \
    \ _n = c.size();\n        lg = 0;\n        extend_base(_n + 1);\n        while\
    \ ((1 << lg) < _n) lg++;\n        siz = 1 << lg;\n        d.resize(2 * siz);\n\
    \        for (int i = 0; i < _n; i++) d[siz + i] = H(c[i]);\n        build();\n\
    \    }\n\n    inline int size() const { return _n; }\n\n    void build() {\n \
    \       assert(!is_built);\n        is_built = true;\n        for (int i = siz\
    \ - 1; i >= 1; i--) update(i);\n    }\n\n    template <class T> void init_set(int\
    \ p, T x) {\n        assert(0 <= p && p < _n);\n        assert(!is_built);\n \
    \       d[siz + p] = H(x);\n    }\n\n    template <class T> void set(int p, T\
    \ x) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n       \
    \ p += siz;\n        d[p] = H(x);\n        for (int i = 1; i <= lg; i++) update(p\
    \ >> i);\n    }\n\n    H get(int i) const {\n        assert(0 <= i && i < _n);\n\
    \        assert(is_built);\n        return d[siz + i];\n    }\n\n    /**\n   \
    \  * @brief `[l, r)`\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF: `O(log(r - l))`\n     *\n\
    \     * @return `[l, r)`\u306E\u30CF\u30C3\u30B7\u30E5\u5024\n     */\n    H get(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n\
    \        H sml = H(0), smr = H(0);\n        l += siz, r += siz;\n        int l_siz\
    \ = 0;\n\n        while (l < r) {\n            if (l & 1) sml = sml + d[l] * pw[l_siz],\
    \ l++, l_siz += inner_size(l);\n            if (r & 1) --r, smr = d[r] + smr *\
    \ pw[inner_size(r)];\n            l >>= 1, r >>= 1;\n        }\n        return\
    \ sml + smr * pwi[l_siz];\n    }\n\n    H all_prod() const {\n        assert(is_built);\n\
    \        return d[1];\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217`lhs[l1,\
    \ r1)`\u3068`rhs[l2, r2)`\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u3092\
    \u6C42\u3081\u308B\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF: `O(log^2(min(r1\
    \ - l1, r2 - l2)))`\n     * @param lhs \u6587\u5B57\u5217`lhs`\u306E\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param l1 `lhs`\u306E\u958B\
    \u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param r1 `lhs`\u306E\u7D42\
    \u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param rhs \u6587\u5B57\u5217\
    `rhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param\
    \ l2 `rhs`\u306E\u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param\
    \ r2 `rhs`\u306E\u7D42\u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ `lhs[l1, l1 + lcp)`\u3068`rhs[l2, l2 + lcp)`\u306E\u6700\u9577\u5171\u901A\u63A5\
    \u982D\u8F9E\u306E\u9577\u3055\n     */\n    static int lcp(const DynamicRollingHash\
    \ &lhs,\n                   int l1,\n                   int r1,\n            \
    \       const DynamicRollingHash &rhs,\n                   int l2,\n         \
    \          int r2) {\n        int len = std::min(r1 - l1, r2 - l2);\n        int\
    \ ok = 0, ng = len + 1;\n        while (ng - ok > 1) {\n            int mid =\
    \ (ok + ng) / 2;\n            if (lhs.get(l1, l1 + mid) == rhs.get(l2, l2 + mid))\
    \ {\n                ok = mid;\n            } else {\n                ng = mid;\n\
    \            }\n        }\n        return ok;\n    }\n\n    /**\n     * @brief\
    \ \u6587\u5B57\u5217`lhs[l1, r1)`\u3068`rhs[l2, r2)`\u306E\u8F9E\u66F8\u9806\u6BD4\
    \u8F03\u3092\u884C\u3046\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF: `O(log^2(min(r1\
    \ - l1, r2 - l2)))`\n     * @param lhs \u6587\u5B57\u5217`lhs`\u306E\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param l1 `lhs`\u306E\u958B\
    \u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param r1 `lhs`\u306E\u7D42\
    \u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param rhs \u6587\u5B57\u5217\
    `rhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param\
    \ l2 `rhs`\u306E\u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     *  @param\
    \ r2 `rhs`\u306E\u7D42\u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ `-1: lhs < rhs, 0: lhs == rhs, 1: lhs > rhs`\n     */\n    static int strcmp(const\
    \ DynamicRollingHash &lhs,\n                      int l1,\n                  \
    \    int r1,\n                      const DynamicRollingHash &rhs,\n         \
    \             int l2,\n                      int r2) {\n        int lcp_ = lcp(lhs,\
    \ l1, r1, rhs, l2, r2);\n        if (lcp_ == r1 - l1 and lcp_ == r2 - l2) return\
    \ 0;\n        else if (lcp_ == r1 - l1) return -1;\n        else if (lcp_ == r2\
    \ - l2) return 1;\n        else {\n            auto c1 = lhs.get(l1 + lcp_, l1\
    \ + lcp_ + 1)[0].val();\n            auto c2 = rhs.get(l2 + lcp_, l2 + lcp_ +\
    \ 1)[0].val();\n            return c1 < c2 ? -1 : 1;\n        }\n    }\n\n   \
    \ /**\n     * @brief \u6587\u5B57\u5217`lhs`\u3068`rhs`\u3092\u7D50\u5408\u3057\
    \u3066\u65B0\u3057\u3044\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\
    \u3092\u4F5C\u6210\u3059\u308B\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF\
    : `O(n + m)` (n: lhs\u306E\u9577\u3055, m: rhs\u306E\u9577\u3055)\n     * @param\
    \ lhs \u6587\u5B57\u5217`lhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
    \u30E5\n     * @param rhs \u6587\u5B57\u5217`rhs`\u306E\u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\n     * @return \u7D50\u5408\u5F8C\u306E\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     */\n    static DynamicRollingHash\
    \ merge(const DynamicRollingHash &lhs, const DynamicRollingHash &rhs) {\n    \
    \    DynamicRollingHash res(lhs._n + rhs._n);\n        for (int i = 0; i < lhs._n;\
    \ i++) res.init_set(i, lhs.get(i));\n        for (int i = 0; i < rhs._n; i++)\
    \ res.init_set(lhs._n + i, rhs.get(i));\n        res.build();\n        return\
    \ res;\n    }\n\n  private:\n    static inline std::vector<H> pw, pwi;\n    static\
    \ void extend_base(int m) {\n        if (pw.size() == 0u) pw = {H(1), H::get_base()},\
    \ pwi = {H(1), pw[1].inv()};\n\n        int n = pwpw.size();\n        if (n >\
    \ m) return;\n        pw.resize(m + 1), pwi.resize(m + 1);\n        for (int i\
    \ = n; i <= m; ++i) pw[i] = pw[i - 1] * pw[1], pwi[i] = pwi[i - 1] * pwi[1];\n\
    \    }\n\n    inline int inner_size(int k) const { return 1 << (lg - msb(k));\
    \ }\n    inline void update(int k) { d[k] = d[2 * k] + d[2 * k + 1] * inner_size(2\
    \ * k); }\n};\n\nusing DRoliha = DynamicRollingHash<2>;\n\n} // namespace kk2\n\
    \n#endif // KK2_STRING_DYNAMIC_ROLLING_HASH_HPP\n"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - random/hash.hpp
  - math_mod/primitive_root_64bit.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
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
  path: string/dynamic_rolling_hash.hpp
  requiredBy: []
  timestamp: '2025-06-19 22:00:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/dynamic_rolling_hash.hpp
layout: document
redirect_from:
- /library/string/dynamic_rolling_hash.hpp
- /library/string/dynamic_rolling_hash.hpp.html
title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\u5217\
  \u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\
  \u30B7\u30E5"
---
