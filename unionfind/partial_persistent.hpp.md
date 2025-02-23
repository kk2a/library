---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/partial_persitent_unionfind.test.cpp
    title: verify/unit_test/partial_persitent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"unionfind/partial_persistent.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <numeric>\n#include <utility>\n#include <vector>\n\
    \nnamespace kk2 {\n\nstruct PartialPersistentUnionFind {\n    struct par_time\
    \ {\n        int par, time;\n        par_time() = default;\n\n        par_time(int\
    \ par_, int time_) : par(par_), time(time_) {}\n    };\n\n    struct size_time\
    \ {\n        int size, time;\n        size_time() = default;\n\n        size_time(int\
    \ size_, int time_) : size(size_), time(time_) {}\n\n        bool operator<(const\
    \ size_time &a) const { return time < a.time; }\n    };\n\n    int last_time;\n\
    \    std::vector<par_time> par;\n    std::vector<std::vector<size_time>> size_hist;\n\
    \n    PartialPersistentUnionFind(int n)\n        : last_time(std::numeric_limits<int>::min()),\n\
    \          par(n),\n          size_hist(n) {\n        for (int i = 0; i < n; ++i)\
    \ {\n            par[i] = par_time(-1, std::numeric_limits<int>::max());\n   \
    \         size_hist[i].emplace_back(1, last_time);\n        }\n    }\n\n    bool\
    \ same(int x, int y, int time) { return find(x, time) == find(y, time); }\n\n\
    \    bool unite(int x, int y, int time) {\n        assert(last_time <= time);\n\
    \        last_time = time;\n        x = find(x, time), y = find(y, time);\n  \
    \      if (x == y) return false;\n        if (size_hist[x].back().size < size_hist[y].back().size)\
    \ std::swap(x, y);\n        par[y] = par_time(x, time);\n        if (size_hist[x].back().time\
    \ < time)\n            size_hist[x].emplace_back(size_hist[x].back().size, time);\n\
    \        size_hist[x].back().size += size_hist[y].back().size;\n        return\
    \ true;\n    }\n\n    int find(int x, int time) {\n        while (par[x].time\
    \ <= time) x = par[x].par;\n        return x;\n    }\n\n    int size(int x, int\
    \ time) {\n        x = find(x, time);\n        auto it = std::upper_bound(size_hist[x].begin(),\
    \ size_hist[x].end(), size_time(0, time));\n        return prev(it)->size;\n \
    \   }\n};\n\n} // namespace kk2\n\n\n\n"
  code: "#ifndef KK2_UNIONFIND_PARTIAL_PERSISTENT_HPP\n#define KK2_UNIONFIND_PARTIAL_PERSISTENT_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace kk2 {\n\nstruct PartialPersistentUnionFind\
    \ {\n    struct par_time {\n        int par, time;\n        par_time() = default;\n\
    \n        par_time(int par_, int time_) : par(par_), time(time_) {}\n    };\n\n\
    \    struct size_time {\n        int size, time;\n        size_time() = default;\n\
    \n        size_time(int size_, int time_) : size(size_), time(time_) {}\n\n  \
    \      bool operator<(const size_time &a) const { return time < a.time; }\n  \
    \  };\n\n    int last_time;\n    std::vector<par_time> par;\n    std::vector<std::vector<size_time>>\
    \ size_hist;\n\n    PartialPersistentUnionFind(int n)\n        : last_time(std::numeric_limits<int>::min()),\n\
    \          par(n),\n          size_hist(n) {\n        for (int i = 0; i < n; ++i)\
    \ {\n            par[i] = par_time(-1, std::numeric_limits<int>::max());\n   \
    \         size_hist[i].emplace_back(1, last_time);\n        }\n    }\n\n    bool\
    \ same(int x, int y, int time) { return find(x, time) == find(y, time); }\n\n\
    \    bool unite(int x, int y, int time) {\n        assert(last_time <= time);\n\
    \        last_time = time;\n        x = find(x, time), y = find(y, time);\n  \
    \      if (x == y) return false;\n        if (size_hist[x].back().size < size_hist[y].back().size)\
    \ std::swap(x, y);\n        par[y] = par_time(x, time);\n        if (size_hist[x].back().time\
    \ < time)\n            size_hist[x].emplace_back(size_hist[x].back().size, time);\n\
    \        size_hist[x].back().size += size_hist[y].back().size;\n        return\
    \ true;\n    }\n\n    int find(int x, int time) {\n        while (par[x].time\
    \ <= time) x = par[x].par;\n        return x;\n    }\n\n    int size(int x, int\
    \ time) {\n        x = find(x, time);\n        auto it = std::upper_bound(size_hist[x].begin(),\
    \ size_hist[x].end(), size_time(0, time));\n        return prev(it)->size;\n \
    \   }\n};\n\n} // namespace kk2\n\n\n#endif // KK2_UNIONFIND_PARTIAL_PERSISTENT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: unionfind/partial_persistent.hpp
  requiredBy: []
  timestamp: '2025-02-23 19:24:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/partial_persitent_unionfind.test.cpp
documentation_of: unionfind/partial_persistent.hpp
layout: document
redirect_from:
- /library/unionfind/partial_persistent.hpp
- /library/unionfind/partial_persistent.hpp.html
title: unionfind/partial_persistent.hpp
---
