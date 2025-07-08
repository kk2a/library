---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data_structure/offline_dynamic_connectivity.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../data_structure/offline_dynamic_connectivity.hpp\"\n#include \"../../unionfind/unionfind.hpp\"\
    \n#include \"../../random/gen.hpp\"\n#include \"../../template/template.hpp\"\n\
    using namespace std;\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout\
    \ << a + b << kendl;\n\n    rep (200) {\n        int n = 10000;\n        int q\
    \ = 1000;\n        vc<array<int, 3>> query(q);\n        vc<pi> insert_query;\n\
    \        rep (i, q) {\n            int t = kk2::random::rng(0, 4);\n         \
    \   query[i][0] = t;\n            if (t == 0) {\n                int a = kk2::random::rng(0,\
    \ n - 1);\n                int b = kk2::random::rng(a, n);\n                query[i][1]\
    \ = a;\n                query[i][2] = b;\n                insert_query.emplace_back(a,\
    \ b);\n            } else if (t == 1) {\n                if (insert_query.empty()\
    \ or kk2::random::rng(0, 2)) {\n                    int a = kk2::random::rng(0,\
    \ n - 1);\n                    int b = kk2::random::rng(a, n);\n             \
    \       query[i][1] = a;\n                    query[i][2] = b;\n             \
    \   } else {\n                    int idx = kk2::random::rng(0, (int)insert_query.size());\n\
    \                    query[i][1] = insert_query[idx].first;\n                \
    \    query[i][2] = insert_query[idx].second;\n                }\n            }\
    \ else if (t == 2) {\n                int a = kk2::random::rng(0, n);\n      \
    \          query[i][1] = a;\n            } else if (t == 3) {\n              \
    \  int a = kk2::random::rng(0, n - 1);\n                int b = kk2::random::rng(a,\
    \ n);\n                query[i][1] = a;\n                query[i][2] = b;\n  \
    \          }\n        }\n    \n        vc<int> res(q);\n        kk2::OfflineDynamicConnectivity\
    \ odc(n, q);\n        rep (i, q) {\n            if (query[i][0] == 0) odc.add_edge(i,\
    \ query[i][1], query[i][2]);\n            if (query[i][0] == 1) odc.del_edge(i,\
    \ query[i][1], query[i][2]);\n        }\n        odc.build();\n        odc.run([&](int\
    \ i) {\n            if (query[i][0] == 2) res[i] = odc.uf.size(query[i][1]);\n\
    \            if (query[i][0] == 3) res[i] = odc.uf.same(query[i][1], query[i][2]);\n\
    \        });\n    \n        std::set<pi> edges;\n        vc<int> res2(q);\n  \
    \      rep (i, q) {\n            if (query[i][0] == 0) {\n                edges.emplace(query[i][1],\
    \ query[i][2]);\n            } else if (query[i][0] == 1) {\n                edges.erase(pi(query[i][1],\
    \ query[i][2]));\n            } else if (query[i][0] == 2) {\n               \
    \ kk2::UnionFind uf(n);\n                for (auto [a, b] : edges) {\n       \
    \             uf.unite(a, b);\n                }\n                res2[i] = uf.size(query[i][1]);\n\
    \            } else {\n                kk2::UnionFind uf(n);\n               \
    \ for (auto [a, b] : edges) {\n                    uf.unite(a, b);\n         \
    \       }\n                res2[i] = uf.same(query[i][1], query[i][2]);\n    \
    \        }\n        }\n        assert(res == res2);\n    }\n\n    return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
- /verify/verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp.html
title: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
---
