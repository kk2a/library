---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: beats.hpp
      icon: LIBRARY_NO_TESTS
      path: segment_tree/beats.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - segment_tree/beats.hpp
  embedded:
  - code: '#ifndef KK2_SEGMENT_TREE_BEATS_UTILITY_HPP

      #define KK2_SEGMENT_TREE_BEATS_UTILITY_HPP 1


      #include "beats.hpp"


      namespace kk2 {


      namespace beats_utility {


      // hogehoge


      } // namespace beats_utility


      } // namespace kk2


      #endif // KK2_SEGMENT_TREE_BEATS_UTILITY_HPP

      '
    name: default
  - code: "#line 1 \"segment_tree/beats_utility.hpp\"\n\n\n\n#line 1 \"segment_tree/beats.hpp\"\
      \n\n\n\n\nnamespace kk2 {\n\ntemplate <class S,\n          S (*op)(S, S),\n\
      \          S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n  \
      \        F (*composition)(F, F),\n          F (*id)(),\n          bool (*fail)(S)>\n\
      struct SegTreeBeats {};\n\n} // namespace kk2\n\n\n#line 5 \"segment_tree/beats_utility.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace beats_utility {\n\n// hogehoge\n\n} // namespace\
      \ beats_utility\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: segment_tree/beats_utility.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/beats_utility.hpp
layout: document
---
