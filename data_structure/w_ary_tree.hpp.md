---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_predecessor_problem.test.cpp
    title: verify/yosupo_ds/ds_predecessor_problem.test.cpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_DATA_STRUCTURE_W_ARY_TREE_HPP\n#define KK2_DATA_STRUCTURE_W_ARY_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <optional>\n#include\
    \ <vector>\n\n#include \"../bit/bitcount.hpp\"\n\nnamespace kk2 {\n\nstruct w_ary_tree\
    \ {\n    using Uint = unsigned long long;\n    constexpr static int W = 64;\n\
    \    int _n;\n    std::vector<std::vector<Uint>> d;\n\n    w_ary_tree() : d(1)\
    \ {}\n\n    w_ary_tree(const std::vector<bool> &a) : _n(a.size()) {\n        if\
    \ (_n == 0) return;\n        if (_n == 1) {\n            d = {{Uint(a[0])}};\n\
    \            return;\n        }\n        for (int n = _n; n != 1; n = (n + W -\
    \ 1) / W) {\n            std::vector<Uint> v((n + W - 1) / W);\n            for\
    \ (int i = 0; i < (n + W - 1) / W; ++i) {\n                Uint x = 0;\n     \
    \           for (int j = 0; j < W && i * W + j < n; ++j) {\n                 \
    \   if (n == _n) x |= (Uint(a[i * W + j]) << j);\n                    else x |=\
    \ ((d.back()[i * W + j] ? Uint(1) : Uint(0)) << j);\n                }\n     \
    \           v[i] = x;\n            }\n            d.push_back(v);\n        }\n\
    \        std::reverse(d.begin(), d.end());\n    }\n\n    w_ary_tree(const std::string\
    \ &s) : _n(s.size()) {\n        if (_n == 0) return;\n        if (_n == 1) {\n\
    \            d = {{Uint(s[0] - '0')}};\n            return;\n        }\n     \
    \   for (int n = _n; n != 1; n = (n + W - 1) / W) {\n            std::vector<Uint>\
    \ v((n + W - 1) / W);\n            for (int i = 0; i < (n + W - 1) / W; ++i) {\n\
    \                Uint x = 0;\n                for (int j = 0; j < W && i * W +\
    \ j < n; ++j) {\n                    if (n == _n) x |= (Uint(s[i * W + j] - '0')\
    \ << j);\n                    else x |= ((d.back()[i * W + j] ? Uint(1) : Uint(0))\
    \ << j);\n                }\n                v[i] = x;\n            }\n      \
    \      d.push_back(v);\n        }\n        std::reverse(d.begin(), d.end());\n\
    \    }\n\n    int count(int x) const {\n        assert(0 <= x && x < _n);\n  \
    \      return d.back()[x / W] >> (x % W) & 1;\n    }\n\n    void insert(int x)\
    \ {\n        assert(0 <= x && x < _n);\n        for (int dep = (int)d.size() -\
    \ 1; dep >= 0; --dep, x /= W) {\n            if (d[dep][x / W] >> (x % W) & 1)\
    \ break;\n            d[dep][x / W] |= Uint(1) << (x % W);\n        }\n    }\n\
    \n    void erase(int x) {\n        assert(0 <= x && x < _n);\n        for (int\
    \ dep = (int)d.size() - 1; dep >= 0; --dep, x /= W) {\n            if (dep ==\
    \ (int)d.size() - 1) {\n                if (~d[dep][x / W] >> (x % W) & 1) break;\n\
    \                d[dep][x / W] ^= Uint(1) << (x % W);\n            } else {\n\
    \                if (d[dep + 1][x]) break;\n                if (~d[dep][x / W]\
    \ >> (x % W) & 1) break;\n                d[dep][x / W] ^= Uint(1) << (x % W);\n\
    \            }\n        }\n    }\n\n    // return max y s.t. count(y) == 1 &&\
    \ y <= x\n    std::optional<int> predecessor(int x) const {\n        if (x < 0)\
    \ return std::nullopt;\n        if (x >= _n) x = _n - 1;\n        int dep = (int)d.size()\
    \ - 1;\n        for (;; --dep, x /= W) {\n            Uint mask = up_mask(d[dep][x\
    \ / W], x % W);\n            if (dep != (int)d.size() - 1) mask &= ~(Uint(1) <<\
    \ (x % W));\n            int next = _msb(mask);\n            if (next != -1) {\n\
    \                ++dep;\n                x = (x / W) * W + next;\n           \
    \     break;\n            }\n            if (dep == 0) return std::nullopt;\n\
    \        }\n\n        for (; dep < (int)d.size(); x = x * W + _msb(d[dep][x]),\
    \ ++dep) {}\n        return x;\n    }\n\n    // return min y s.t. count(y) ==\
    \ 1 && y >= x\n    std::optional<int> successor(int x) const {\n        if (x\
    \ >= _n) return std::nullopt;\n        if (x < 0) x = 0;\n        int dep = (int)d.size()\
    \ - 1;\n        for (;; --dep, x /= W) {\n            Uint mask = dw_mask(d[dep][x\
    \ / W], x % W);\n            if (dep != (int)d.size() - 1) mask &= ~(Uint(1) <<\
    \ (x % W));\n            int next = _lsb(mask);\n            if (next != -1) {\n\
    \                ++dep;\n                x = (x / W) * W + next;\n           \
    \     break;\n            }\n            if (dep == 0) return std::nullopt;\n\
    \        }\n\n\n        for (; dep < (int)d.size(); x = x * W + _lsb(d[dep][x]),\
    \ ++dep) {}\n        return x;\n    }\n\n  private:\n    static int _msb(Uint\
    \ x) { return x ? msb<Uint>(x) : -1; }\n\n    static int _lsb(Uint x) { return\
    \ x ? lsb<Uint>(x) : -1; }\n\n    static Uint up_mask(Uint x, int i) { return\
    \ x & (((Uint(1) << i) - 1) | (Uint(1) << i)); }\n\n    static Uint dw_mask(Uint\
    \ x, int i) { return x & ~((Uint(1) << i) - 1); }\n};\n\n} // namespace kk2\n\n\
    #endif // KK2_DATA_STRUCTURE_W_ARY_TREE_HPP"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: data_structure/w_ary_tree.hpp
  requiredBy: []
  timestamp: '2025-01-06 00:03:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_predecessor_problem.test.cpp
documentation_of: data_structure/w_ary_tree.hpp
layout: document
redirect_from:
- /library/data_structure/w_ary_tree.hpp
- /library/data_structure/w_ary_tree.hpp.html
title: data_structure/w_ary_tree.hpp
---
