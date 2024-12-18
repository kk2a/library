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
  bundledCode: "#line 1 \"data_structure/w_ary_tree.hpp\"\n\n\n\n#include <vector>\n\
    \nnamespace kk2 {\n\nstruct w_ary_tree {\n    using Uint = unsigned long long;\n\
    \    constexpr static int W = 64;\n    std::vector<std::vector<Uint>> d;\n\n \
    \   w_ary_tree() : d(1) {}\n\n    w_ary_tree(const std::vector<bool> &a) {\n \
    \       for (int n = a.size(); n != 1; n = (n + W - 1) / W) {\n            std::vector<Uint>\
    \ v((n + W - 1) / W);\n            for (int i = 0; i < (n + W - 1) / W; ++i) {\n\
    \                Uint x = 0;\n                for (int j = 0; j < W && i * W +\
    \ j < n; ++j) {\n                    if (n == a.size()) x |= (Uint(a[i * W + j])\
    \ << j);\n                    else x |= (Uint(d.back()[i * W + j]) << j);\n  \
    \              }\n                v[i] = x;\n            }\n            d.push_back(v);\n\
    \        }\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef DATA_STRUCTURE_W_ARY_TREE_HPP\n#define DATA_STRUCTURE_W_ARY_TREE_HPP\
    \ 1\n\n#include <vector>\n\nnamespace kk2 {\n\nstruct w_ary_tree {\n    using\
    \ Uint = unsigned long long;\n    constexpr static int W = 64;\n    std::vector<std::vector<Uint>>\
    \ d;\n\n    w_ary_tree() : d(1) {}\n\n    w_ary_tree(const std::vector<bool> &a)\
    \ {\n        for (int n = a.size(); n != 1; n = (n + W - 1) / W) {\n         \
    \   std::vector<Uint> v((n + W - 1) / W);\n            for (int i = 0; i < (n\
    \ + W - 1) / W; ++i) {\n                Uint x = 0;\n                for (int\
    \ j = 0; j < W && i * W + j < n; ++j) {\n                    if (n == a.size())\
    \ x |= (Uint(a[i * W + j]) << j);\n                    else x |= (Uint(d.back()[i\
    \ * W + j]) << j);\n                }\n                v[i] = x;\n           \
    \ }\n            d.push_back(v);\n        }\n    }\n};\n\n} // namespace kk2\n\
    \n#endif // DATA_STRUCTURE_W_ARY_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/w_ary_tree.hpp
  requiredBy: []
  timestamp: '2024-12-18 11:39:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/w_ary_tree.hpp
layout: document
redirect_from:
- /library/data_structure/w_ary_tree.hpp
- /library/data_structure/w_ary_tree.hpp.html
title: data_structure/w_ary_tree.hpp
---
