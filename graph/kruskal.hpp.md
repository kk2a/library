---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../unionfind/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef KRUSKAL_HPP\n#define KRUSKAL_HPP 1\n\n#include \"../unionfind/unionfind.hpp\"\
    \n\nnamespace kk2 {\n\nstruct Kruskal {\n    using i64 = long long;\n  private:\n\
    \    struct Edge {\n        i64 cost;\n        int from, to;\n        bool operator<(const\
    \ Edge &e) const {\n            return cost < e.cost;\n        }\n    };\n   \
    \ vector<Edge> edges;\n    int _n, _m;\n  public:\n    Kruskal(int n = 0) : _n(n),\
    \ _m(0) {}\n\n    void add_edge(int from, int to, i64 cost) {\n        assert(0\
    \ <= from && from < _n);\n        assert(0 <= to && to < _n);\n        _m++;\n\
    \        edges.eb(cost, from, to);\n    }\n\n    i64 query() {\n        sort(begin(edges),\
    \ end(edges));\n        UnionFind uf(_n);\n        i64 res = 0;\n        for (int\
    \ i = 0; i < _m; i++) {\n            if (uf.same(edges[i].from, edges[i].to))\
    \ continue;\n            uf.unite(edges[i].from, edges[i].to);\n            res\
    \ += edges[i].cost;\n        }\n        if (uf.size(0) != _n) return -1;\n   \
    \     return res;\n    }\n};\n\n} // namespace kk2\n\n#endif // KRUSKAL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: graph/kruskal.hpp
---
