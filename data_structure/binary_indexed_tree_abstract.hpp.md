---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_DATA_STRUCTURE_BINARY_INDEXED_TREE_ABSTRACT_HPP\n#define KK2_DATA_STRUCTURE_BINARY_INDEXED_TREE_ABSTRACT_HPP\
      \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
      \ <class A> struct BinaryIndexedTreeAbstract {\n    BinaryIndexedTreeAbstract()\
      \ : _n(0) {}\n    BinaryIndexedTreeAbstract(int n) : _n(n), data(n, A::unit())\
      \ {}\n\n    void add(int p, A x) {\n        assert(0 <= p && p < _n);\n    \
      \    for (p++; p <= _n; p += p & -p) data[p - 1] = A::op(data[p - 1], x);\n\
      \    }\n\n    A sum(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
      \ _n);\n        return A::op(A::inv(sum(l)), sum(r));\n    }\n\n    A get(int\
      \ p) {\n        assert(0 <= p && p < _n);\n        return A::op(sum(p + 1),\
      \ A::inv(sum(p)));\n    }\n\n  private:\n    int _n;\n    std::vector<A> data;\n\
      \n    A sum(int r) {\n        A s = A::unit();\n        for (; r > 0; r -= r\
      \ & -r) s = A::op(s, data[r - 1]);\n        return s;\n    }\n};\n\n} // namespace\
      \ kk2\n\n#endif // KK2_DATA_STRUCTURE_BINARY_INDEXED_TREE_ABSTRACT_HPP\n"
    name: default
  - code: "#line 1 \"data_structure/binary_indexed_tree_abstract.hpp\"\n\n\n\n#include\
      \ <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class A> struct\
      \ BinaryIndexedTreeAbstract {\n    BinaryIndexedTreeAbstract() : _n(0) {}\n\
      \    BinaryIndexedTreeAbstract(int n) : _n(n), data(n, A::unit()) {}\n\n   \
      \ void add(int p, A x) {\n        assert(0 <= p && p < _n);\n        for (p++;\
      \ p <= _n; p += p & -p) data[p - 1] = A::op(data[p - 1], x);\n    }\n\n    A\
      \ sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n      \
      \  return A::op(A::inv(sum(l)), sum(r));\n    }\n\n    A get(int p) {\n    \
      \    assert(0 <= p && p < _n);\n        return A::op(sum(p + 1), A::inv(sum(p)));\n\
      \    }\n\n  private:\n    int _n;\n    std::vector<A> data;\n\n    A sum(int\
      \ r) {\n        A s = A::unit();\n        for (; r > 0; r -= r & -r) s = A::op(s,\
      \ data[r - 1]);\n        return s;\n    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: data_structure/binary_indexed_tree_abstract.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_indexed_tree_abstract.hpp
layout: document
---
