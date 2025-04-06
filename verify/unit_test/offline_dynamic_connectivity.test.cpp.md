---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_dynamic_connectivity.hpp
    title: data_structure/offline_dynamic_connectivity.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':heavy_check_mark:'
    path: unionfind/rollback.hpp
    title: unionfind/rollback.hpp
  - icon: ':heavy_check_mark:'
    path: unionfind/unionfind.hpp
    title: unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
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
  dependsOn:
  - data_structure/offline_dynamic_connectivity.hpp
  - unionfind/rollback.hpp
  - unionfind/unionfind.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/offline_dynamic_connectivity.test.cpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/offline_dynamic_connectivity.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/offline_dynamic_connectivity.test.cpp
- /verify/verify/unit_test/offline_dynamic_connectivity.test.cpp.html
title: verify/unit_test/offline_dynamic_connectivity.test.cpp
---
