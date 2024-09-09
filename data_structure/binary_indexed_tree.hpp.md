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
  bundledCode: "#line 1 \"data_structure/binary_indexed_tree.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <typename T>\nstruct\
    \ BinaryIndexedTree {\n    BinaryIndexedTree() : _n(0) {}\n    BinaryIndexedTree(int\
    \ n) : _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p\
    \ && p < _n);\n        for (p++; p <= _n; p += p & -p) data[p - 1] += x;\n   \
    \ }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n\
    \        return sum(r) - sum(l);\n    }\n\n    T get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        return sum(p + 1) - sum(p);\n    }\n\n  private:\n\
    \    int _n;\n    std::vector<T> data;\n\n    T sum(int r) {\n        T s{};\n\
    \        for (; r > 0; r -= r & -r) s += data[r - 1];\n        return s;\n   \
    \ }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef DATA_STRUCTURE_BINARY_INDEXED_TREE_HPP\n#define DATA_STRUCTURE_BINARY_INDEXED_TREE_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T>\nstruct BinaryIndexedTree {\n    BinaryIndexedTree() : _n(0) {}\n    BinaryIndexedTree(int\
    \ n) : _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p\
    \ && p < _n);\n        for (p++; p <= _n; p += p & -p) data[p - 1] += x;\n   \
    \ }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n\
    \        return sum(r) - sum(l);\n    }\n\n    T get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        return sum(p + 1) - sum(p);\n    }\n\n  private:\n\
    \    int _n;\n    std::vector<T> data;\n\n    T sum(int r) {\n        T s{};\n\
    \        for (; r > 0; r -= r & -r) s += data[r - 1];\n        return s;\n   \
    \ }\n};\n\n} // namespace kk2\n\n#endif // #ifndef DATA_STRUCTURE_BINARY_INDEXED_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2024-09-08 23:48:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/data_structure/binary_indexed_tree.hpp
- /library/data_structure/binary_indexed_tree.hpp.html
title: data_structure/binary_indexed_tree.hpp
---
