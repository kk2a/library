---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_static_range_inversions.test.cpp
    title: verify/yosupo_ds/ds_static_range_inversions.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/mo.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <functional>\n#include <numeric>\n#include <vector>\n\
    \nnamespace kk2 {\n\nstruct Mo {\n    Mo(int n_, int q_) : n(n_), q(q_), ord(q)\
    \ {\n        word_size = std::max<int>(1, n / std::max(1.0, std::sqrt(q * 2.0\
    \ / 3.0)));\n        std::iota(ord.begin(), ord.end(), 0);\n        queries.reserve(q);\n\
    \    }\n\n    Mo(int n_, const std::vector<std::pair<int, int>> &queries_)\n \
    \       : n(n_),\n          q(queries_.size()),\n          ord(q),\n         \
    \ queries(queries_) {\n        word_size = std::max<int>(1, n / std::max(1.0,\
    \ std::sqrt(q * 2.0 / 3.0)));\n        std::iota(ord.begin(), ord.end(), 0);\n\
    \    }\n\n    void add_query(int l, int r) {\n        assert(0 <= l and l < r\
    \ and r <= n);\n        queries.emplace_back(l, r);\n    }\n\n    void add_query(const\
    \ std::pair<int, int> &p) { add_query(p.first, p.second); }\n\n    template <typename\
    \ IL, typename IR, typename EL, typename ER, typename F>\n    void calculate(const\
    \ IL &insert_left,\n                   const IR &insert_right,\n             \
    \      const EL &erase_left,\n                   const ER &erase_right,\n    \
    \               const F &f) {\n        assert((int)queries.size() == q);\n   \
    \     std::vector<int> block_id(n);\n        for (int i = 0, cnt = 0, b = 0; i\
    \ < n; i++) {\n            block_id[i] = b;\n            if (++cnt == word_size)\
    \ {\n                b++;\n                cnt = 0;\n            }\n        }\n\
    \        std::sort(ord.begin(), ord.end(), [&](int l, int r) {\n            int\
    \ l_b = block_id[queries[l].first];\n            int r_b = block_id[queries[r].first];\n\
    \            if (l_b != r_b) return l_b < r_b;\n            if (l_b & 1) return\
    \ queries[l].second < queries[r].second;\n            return queries[l].second\
    \ > queries[r].second;\n        });\n\n        int nowl = 0, nowr = 0;\n     \
    \   for (int i : ord) {\n            while (nowl > queries[i].first) insert_left(--nowl);\n\
    \            while (nowr < queries[i].second) insert_right(nowr++);\n        \
    \    while (nowl < queries[i].first) erase_left(nowl++);\n            while (nowr\
    \ > queries[i].second) erase_right(--nowr);\n            f(i);\n        }\n  \
    \  }\n\n    template <typename I, typename E, typename F>\n    void calculate(const\
    \ I &insert, const E &erase, const F &f) {\n        calculate(insert, insert,\
    \ erase, erase, f);\n    }\n\n  private:\n    int n, q, word_size;\n    std::vector<int>\
    \ ord;\n    std::vector<std::pair<int, int>> queries;\n};\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef KK2_OTHERS_MO_HPP\n#define KK2_OTHERS_MO_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <functional>\n#include <numeric>\n\
    #include <vector>\n\nnamespace kk2 {\n\nstruct Mo {\n    Mo(int n_, int q_) :\
    \ n(n_), q(q_), ord(q) {\n        word_size = std::max<int>(1, n / std::max(1.0,\
    \ std::sqrt(q * 2.0 / 3.0)));\n        std::iota(ord.begin(), ord.end(), 0);\n\
    \        queries.reserve(q);\n    }\n\n    Mo(int n_, const std::vector<std::pair<int,\
    \ int>> &queries_)\n        : n(n_),\n          q(queries_.size()),\n        \
    \  ord(q),\n          queries(queries_) {\n        word_size = std::max<int>(1,\
    \ n / std::max(1.0, std::sqrt(q * 2.0 / 3.0)));\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n    }\n\n    void add_query(int l, int r) {\n        assert(0\
    \ <= l and l < r and r <= n);\n        queries.emplace_back(l, r);\n    }\n\n\
    \    void add_query(const std::pair<int, int> &p) { add_query(p.first, p.second);\
    \ }\n\n    template <typename IL, typename IR, typename EL, typename ER, typename\
    \ F>\n    void calculate(const IL &insert_left,\n                   const IR &insert_right,\n\
    \                   const EL &erase_left,\n                   const ER &erase_right,\n\
    \                   const F &f) {\n        assert((int)queries.size() == q);\n\
    \        std::vector<int> block_id(n);\n        for (int i = 0, cnt = 0, b = 0;\
    \ i < n; i++) {\n            block_id[i] = b;\n            if (++cnt == word_size)\
    \ {\n                b++;\n                cnt = 0;\n            }\n        }\n\
    \        std::sort(ord.begin(), ord.end(), [&](int l, int r) {\n            int\
    \ l_b = block_id[queries[l].first];\n            int r_b = block_id[queries[r].first];\n\
    \            if (l_b != r_b) return l_b < r_b;\n            if (l_b & 1) return\
    \ queries[l].second < queries[r].second;\n            return queries[l].second\
    \ > queries[r].second;\n        });\n\n        int nowl = 0, nowr = 0;\n     \
    \   for (int i : ord) {\n            while (nowl > queries[i].first) insert_left(--nowl);\n\
    \            while (nowr < queries[i].second) insert_right(nowr++);\n        \
    \    while (nowl < queries[i].first) erase_left(nowl++);\n            while (nowr\
    \ > queries[i].second) erase_right(--nowr);\n            f(i);\n        }\n  \
    \  }\n\n    template <typename I, typename E, typename F>\n    void calculate(const\
    \ I &insert, const E &erase, const F &f) {\n        calculate(insert, insert,\
    \ erase, erase, f);\n    }\n\n  private:\n    int n, q, word_size;\n    std::vector<int>\
    \ ord;\n    std::vector<std::pair<int, int>> queries;\n};\n\n} // namespace kk2\n\
    \n#endif // KK2_OTHERS_MO_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/mo.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_static_range_inversions.test.cpp
documentation_of: others/mo.hpp
layout: document
redirect_from:
- /library/others/mo.hpp
- /library/others/mo.hpp.html
title: others/mo.hpp
---
