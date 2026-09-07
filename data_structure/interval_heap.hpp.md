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
  - code: "#ifndef KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP\n#define KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP\
      \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
      \ <vector>\n\nnamespace kk2 {\n\ntemplate <class T, class Compare = std::less<T>>\
      \ struct IntervalHeap {\n    std::vector<T> v;\n\n    IntervalHeap() = default;\n\
      \    IntervalHeap(const std::vector<T> &a) : v(a) { make_heap(); }\n\n    void\
      \ make_heap() {}\n\n  private:\n    static bool op(T x, T y) { return Compare{}(x,\
      \ y); }\n};\n\n} // namespace kk2\n\n#endif // KK2_DATA_STRUCTURE_INTERVAL_HEAP_HPP\n"
    name: default
  - code: "#line 1 \"data_structure/interval_heap.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace kk2\
      \ {\n\ntemplate <class T, class Compare = std::less<T>> struct IntervalHeap\
      \ {\n    std::vector<T> v;\n\n    IntervalHeap() = default;\n    IntervalHeap(const\
      \ std::vector<T> &a) : v(a) { make_heap(); }\n\n    void make_heap() {}\n\n\
      \  private:\n    static bool op(T x, T y) { return Compare{}(x, y); }\n};\n\n\
      } // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: data_structure/interval_heap.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/interval_heap.hpp
layout: document
---
