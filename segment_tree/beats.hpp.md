---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: beats_utility.hpp
      icon: LIBRARY_NO_TESTS
      path: segment_tree/beats_utility.hpp
    type: Required by
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_SEGMENT_TREE_BEATS_HPP\n#define KK2_SEGMENT_TREE_BEATS_HPP\
      \ 1\n\n\nnamespace kk2 {\n\ntemplate <class S,\n          S (*op)(S, S),\n \
      \         S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n   \
      \       F (*composition)(F, F),\n          F (*id)(),\n          bool (*fail)(S)>\n\
      struct SegTreeBeats {};\n\n} // namespace kk2\n\n#endif // KK2_SEGMENT_TREE_BEATS_HPP\n"
    name: default
  - code: "#line 1 \"segment_tree/beats.hpp\"\n\n\n\n\nnamespace kk2 {\n\ntemplate\
      \ <class S,\n          S (*op)(S, S),\n          S (*e)(),\n          class\
      \ F,\n          S (*mapping)(F, S),\n          F (*composition)(F, F),\n   \
      \       F (*id)(),\n          bool (*fail)(S)>\nstruct SegTreeBeats {};\n\n\
      } // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: segment_tree/beats.hpp
  pathExtension: hpp
  requiredBy:
  - segment_tree/beats_utility.hpp
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/beats.hpp
layout: document
---
