---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/modint_2_61m1.hpp
    title: modint/modint_2_61m1.hpp
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
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_STRING_ROLLING_HASH_HPP\n#define KK2_STRING_ROLLING_HASH_HPP\
    \ 1\n\n#include <cassert>\n#include <string>\n#include <vector>\n\n#include \"\
    ../random/hash.hpp\"\n\nnamespace kk2 {\n\ntemplate <int NUM> struct RollingHash\
    \ {\n    using H = random::Hash<NUM>;\n    static std::vector<H> pw, pwi;\n  \
    \  std::vector<H> prefix;\n\n    RollingHash() : prefix() {}\n\n    template <class\
    \ T, is_integral_t<T> * = nullptr> RollingHash(T v) : prefix({H(v)}) {}\n\n  \
    \  RollingHash(const std::string &s) : prefix(s.size()) {\n        extend_base(s.size());\n\
    \        prefix[0] = H(s[0]);\n        for (size_t i = 1; i < s.size(); ++i) {\
    \ prefix[i] = prefix[i - 1] + H(s[i]) * pw[i]; }\n    }\n\n    template <class\
    \ T, is_integral_t<T> * = nullptr>\n    RollingHash(const std::vector<T> &v) :\
    \ prefix(v.size()) {\n        extend_base(v.size());\n        prefix[0] = H(v[0]);\n\
    \        for (size_t i = 1; i < v.size(); ++i) { prefix[i] = prefix[i - 1] + H(v[i])\
    \ * pw[i]; }\n    }\n\n    // [l, r)\n    H get(int l, int r) const {\n      \
    \  assert(0 <= l and l <= r and r <= (int)prefix.size());\n        if (l == r)\
    \ return H(0);\n        if (l == 0) return prefix[r - 1];\n        return (prefix[r\
    \ - 1] - prefix[l - 1]) * pwi[l];\n    }\n\n    static int lcp(const RollingHash\
    \ &lhs, int l1, int r1, const RollingHash &rhs, int l2, int r2) {\n        int\
    \ len = std::min(r1 - l1, r2 - l2);\n        int ok = 0, ng = len + 1;\n     \
    \   while (ng - ok > 1) {\n            int mid = (ok + ng) / 2;\n            if\
    \ (lhs.get(l1, l1 + mid) == rhs.get(l2, l2 + mid)) {\n                ok = mid;\n\
    \            } else {\n                ng = mid;\n            }\n        }\n \
    \       return ok;\n    }\n\n    static int\n    strcmp(const RollingHash &lhs,\
    \ int l1, int r1, const RollingHash &rhs, int l2, int r2) {\n        int lcp_\
    \ = lcp(lhs, l1, r1, rhs, l2, r2);\n        if (lcp_ == r1 - l1 and lcp_ == r2\
    \ - l2) return 0;\n        else if (lcp_ == r1 - l1) return -1;\n        else\
    \ if (lcp_ == r2 - l2) return 1;\n        else {\n            auto c1 = lhs.get(l1\
    \ + lcp_, l1 + lcp_ + 1)[0].val();\n            auto c2 = rhs.get(l2 + lcp_, l2\
    \ + lcp_ + 1)[0].val();\n            return c1 < c2 ? -1 : 1;\n        }\n   \
    \ }\n\n    static RollingHash merge(const RollingHash &lhs, const RollingHash\
    \ &rhs) {\n        RollingHash res;\n        extend_base(lhs.prefix.size() + rhs.prefix.size());\n\
    \        res.prefix = lhs.prefix;\n        res.prefix.insert(res.prefix.end(),\
    \ rhs.prefix.begin(), rhs.prefix.end());\n        for (size_t i = lhs.prefix.size();\
    \ i < res.prefix.size(); ++i) {\n            res.prefix[i] =\n               \
    \ res.prefix[i] * pw[lhs.prefix.size()] + res.prefix[lhs.prefix.size() - 1];\n\
    \        }\n        return res;\n    }\n\n  private:\n    static void extend_base(int\
    \ m) {\n        if (pw.size() == 0u) {\n            pw.push_back(H(1));\n    \
    \        pwi.push_back(H(1));\n            pw.push_back(H::get_base());\n    \
    \        pwi.push_back(pw[1].inv());\n        }\n\n        int n = pw.size();\n\
    \        if (n >= m) return;\n        pw.resize(m);\n        pwi.resize(m);\n\
    \        for (int i = n; i < m; ++i) {\n            pw[i] = pw[i - 1] * pw[1];\n\
    \            pwi[i] = pwi[i - 1] * pwi[1];\n        }\n    }\n};\n\ntemplate <int\
    \ NUM> std::vector<typename RollingHash<NUM>::H> RollingHash<NUM>::pw;\ntemplate\
    \ <int NUM> std::vector<typename RollingHash<NUM>::H> RollingHash<NUM>::pwi;\n\
    \nusing Roliha = RollingHash<2>;\n\n} // namespace kk2\n\n\n#endif // KK2_STRING_ROLLING_HASH_HPP\n"
  dependsOn:
  - random/hash.hpp
  - modint/modint_2_61m1.hpp
  - type_traits/type_traits.hpp
  - random/gen.hpp
  - random/seed.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2025-02-04 23:50:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
