---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_c.test.cpp
    title: verify/aoj/aoj_grl_1_c.test.cpp
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
  code: "#ifndef KK2_GRAPH_WARSHALL_FLOYD_HPP\n#define KK2_GRAPH_WARSHALL_FLOYD_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \n#include \"../../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ shortest_path_impl {\n\ntemplate <typename T>\nstruct wf_len {\n    T len;\n\
    \    bool inf, minf;\n\n    template <class OStream, is_ostream_t<OStream> * =\
    \ nullptr>\n    void debug_output(OStream &os) const {\n        if (minf) os <<\
    \ \"MINF\";\n        else if (inf) os << \"INF\";\n        else os << len;\n \
    \   }\n};\n\ntemplate <typename WG, typename T = typename WG::value_type>\nstd::vector<std::vector<wf_len<T>>>\
    \ warshall_froyd(const WG &g) {\n    static_assert(WG::weighted, \"warshall_froyd\
    \ requires weighted graph\");\n\n    int n = g.size();\n    std::vector<std::vector<wf_len<T>>>\
    \ res(n, std::vector<wf_len<T>>(n, {0, true, false}));\n    for (int i = 0; i\
    \ < n; ++i) res[i][i] = {0, false, false};\n    for (auto &&e : g.edges) {\n \
    \       {\n            auto &[len, inf, minf] = res[e.from][e.to];\n         \
    \   if (inf or len > e.cost) {\n                len = e.cost;\n              \
    \  inf = false;\n            }\n        }\n        if constexpr (!WG::directed)\
    \ {\n            auto &[len, inf, minf] = res[e.to][e.from];\n            if (inf\
    \ or len > e.cost) {\n                len = e.cost;\n                inf = false;\n\
    \            }\n        }\n    }\n\n    for (int k = 0; k < n; ++k) {\n      \
    \  for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < n; ++j) {\n\
    \                if (res[i][k].inf or res[k][j].inf) continue;\n             \
    \   if (res[i][j].inf or res[i][j].len > res[i][k].len + res[k][j].len) {\n  \
    \                  res[i][j].len = res[i][k].len + res[k][j].len;\n          \
    \          res[i][j].inf = false;\n                }\n            }\n        }\n\
    \    }\n\n    for (int k = 0; k < n; ++k) {\n        if (res[k][k].len >= 0) continue;\n\
    \        res[k][k].minf = true;\n        for (int i = 0; i < n; ++i) {\n     \
    \       for (int j = 0; j < n; ++j) {\n                if (res[i][k].inf or res[k][j].inf)\
    \ continue;\n                res[i][j].minf = true;\n            }\n        }\n\
    \    }\n\n    return res;\n}\n\n} // namespace shortest_path_impl\n\nusing shortest_path_impl::warshall_froyd;\n\
    \n} // namespace kk2\n\n#endif // KK2_GRAPH_WARSHALL_FLOYD_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: graph/shortest_path/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2025-03-28 03:08:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
documentation_of: graph/shortest_path/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/warshall_floyd.hpp
- /library/graph/shortest_path/warshall_floyd.hpp.html
title: graph/shortest_path/warshall_floyd.hpp
---
