---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment_tree/beats_utility.hpp
    title: segment_tree/beats_utility.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/beats.hpp\"\n\n\n\n\nnamespace kk2 {\n\ntemplate\
    \ <class S,\n          S (*op)(S, S),\n          S (*e)(),\n          class F,\n\
    \          S (*mapping)(F, S),\n          F (*composition)(F, F),\n          F\
    \ (*id)(),\n          bool (*fail)(S)>\nstruct SegTreeBeats {};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_SEGMENT_TREE_BEATS_HPP\n#define KK2_SEGMENT_TREE_BEATS_HPP 1\n\
    \n\nnamespace kk2 {\n\ntemplate <class S,\n          S (*op)(S, S),\n        \
    \  S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F),\n          F (*id)(),\n          bool (*fail)(S)>\nstruct SegTreeBeats {};\n\
    \n} // namespace kk2\n\n#endif // KK2_SEGMENT_TREE_BEATS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/beats.hpp
  requiredBy:
  - segment_tree/beats_utility.hpp
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/beats.hpp
layout: document
redirect_from:
- /library/segment_tree/beats.hpp
- /library/segment_tree/beats.hpp.html
title: segment_tree/beats.hpp
---
