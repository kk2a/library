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
    path: string/dynamic_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\
      \u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\
      \u30CF\u30C3\u30B7\u30E5"
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    title: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
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
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_UNIONFIND_PARALLEL_HPP\n#define KK2_UNIONFIND_PARALLEL_HPP 1\n\
    \n#include <numeric>\n\n#include \"../string/dynamic_rolling_hash.hpp\"\n\nnamespace\
    \ kk2 {\n\nstruct ParallelUnionFind {\n    using DR = DynamicRollingHash<1>;\n\
    \    std::vector<int> d, nxt;\n    DR roots;\n\n    ParallelUnionFind() = default;\n\
    \    ParallelUnionFind(int n) : d(n, -1), nxt(n), roots(n) {\n        for (int\
    \ i = 0; i < n; ++i) {\n            nxt[i] = i;\n            roots.init_set(i,\
    \ i ^ (1 << 30));\n        }\n        roots.build();\n    }\n\n    bool unite(int\
    \ a, int b, int k) {\n        int c = DR::lcp(roots, a, a + k, roots, b, b + k);\n\
    \        if (c == k) return false;\n        while (c != k) {\n            int\
    \ ll = a + c, rr = b + c;\n            ll = roots.get(ll)[0].val() ^ (1 << 30);\n\
    \            rr = roots.get(rr)[0].val() ^ (1 << 30);\n            if (-d[ll]\
    \ < -d[rr]) std::swap(ll, rr);\n            d[ll] += d[rr];\n            d[rr]\
    \ = ll;\n            roots.set(rr, ll ^ (1 << 30));\n            for (int x =\
    \ nxt[rr]; x != rr; x = nxt[x]) roots.set(x, ll ^ (1 << 30));\n\n            std::swap(nxt[ll],\
    \ nxt[rr]);\n            c = DR::lcp(roots, a, a + k, roots, b, b + k);\n    \
    \    }\n        return true;\n    }\n\n    int count = 0;\n    double time = 0;\n\
    \n    template <class F> bool unite(int a, int b, int k, const F &f) {\n     \
    \   int c = DR::lcp(roots, a, a + k, roots, b, b + k);\n        if (c == k) return\
    \ false;\n        while (c != k) {\n            int ll = a + c, rr = b + c;\n\
    \            ll = roots.get(ll)[0].val() ^ (1 << 30);\n            rr = roots.get(rr)[0].val()\
    \ ^ (1 << 30);\n            if (-d[ll] < -d[rr]) std::swap(ll, rr);\n        \
    \    d[ll] += d[rr];\n            d[rr] = ll;\n            roots.set(rr, ll ^\
    \ (1 << 30));\n            for (int x = nxt[rr]; x != rr; x = nxt[x]) roots.set(x,\
    \ ll ^ (1 << 30));\n            f(ll, rr);\n            std::swap(nxt[ll], nxt[rr]);\n\
    \            c = DR::lcp(roots, a, a + k, roots, b, b + k);\n        }\n     \
    \   return true;\n    }\n\n    inline bool same(int a, int b) { return roots.get(a)\
    \ == roots.get(b); }\n    inline int find(int a) { return roots.get(a)[0].val()\
    \ ^ (1 << 30); }\n    inline int size(int a) { return -d[find(a)]; }\n    inline\
    \ std::vector<int> enumerate(int a) {\n        std::vector<int> res{a};\n    \
    \    for (int j = nxt[a]; j != a; j = nxt[j]) res.push_back(j);\n        return\
    \ res;\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_UNIONFIND_PARALLEL_HPP\n"
  dependsOn:
  - string/dynamic_rolling_hash.hpp
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
  path: unionfind/parallel.hpp
  requiredBy: []
  timestamp: '2025-07-08 15:40:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
documentation_of: unionfind/parallel.hpp
layout: document
redirect_from:
- /library/unionfind/parallel.hpp
- /library/unionfind/parallel.hpp.html
title: unionfind/parallel.hpp
---
