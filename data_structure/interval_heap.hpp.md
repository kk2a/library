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
  bundledCode: "#line 1 \"data_structure/interval_heap.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace kk2\
    \ {\n\ntemplate <class T, class Compare = std::less<T>> struct IntervalHeap {\n\
    \    std::vector<T> v;\n\n    IntervalHeap() = default;\n    IntervalHeap(const\
    \ std::vector<T> &a) : v(a) { make_heap(); }\n\n    void make_heap() {}\n\n  private:\n\
    \    static bool op(T x, T y) { return Compare{}(x, y); }\n};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP\n#define KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\ntemplate <class T, class Compare = std::less<T>>\
    \ struct IntervalHeap {\n    std::vector<T> v;\n\n    IntervalHeap() = default;\n\
    \    IntervalHeap(const std::vector<T> &a) : v(a) { make_heap(); }\n\n    void\
    \ make_heap() {}\n\n  private:\n    static bool op(T x, T y) { return Compare{}(x,\
    \ y); }\n};\n\n} // namespace kk2\n\n#endif // KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/interval_heap.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/interval_heap.hpp
layout: document
redirect_from:
- /library/data_structure/interval_heap.hpp
- /library/data_structure/interval_heap.hpp.html
title: data_structure/interval_heap.hpp
---
