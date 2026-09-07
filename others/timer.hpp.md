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
  - code: "#ifndef KK2_OTHERS_TIMER_HPP\n#define KK2_OTHERS_TIMER_HPP 1\n\n#include\
      \ <chrono>\n\nnamespace kk2 {\n\nstruct Timer {\n    using clock = std::chrono::high_resolution_clock;\n\
      \    using time_point = clock::time_point;\n\n    clock::time_point start;\n\
      \n    Timer() : start(clock::now()) {}\n\n    void reset() { start = clock::now();\
      \ }\n\n    /**\n     * @brief \u6642\u9593\u3092\u8A08\u6E2C\u3059\u308B\n \
      \    * @return \u7D4C\u904E\u6642\u9593 (ms)\n     */\n    double elapsed()\
      \ const {\n        auto end = clock::now();\n        return std::chrono::duration_cast<std::chrono::nanoseconds>(end\
      \ - start).count() * 1e-6;\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_OTHERS_TIMER_HPP\n"
    name: default
  - code: "#line 1 \"others/timer.hpp\"\n\n\n\n#include <chrono>\n\nnamespace kk2\
      \ {\n\nstruct Timer {\n    using clock = std::chrono::high_resolution_clock;\n\
      \    using time_point = clock::time_point;\n\n    clock::time_point start;\n\
      \n    Timer() : start(clock::now()) {}\n\n    void reset() { start = clock::now();\
      \ }\n\n    /**\n     * @brief \u6642\u9593\u3092\u8A08\u6E2C\u3059\u308B\n \
      \    * @return \u7D4C\u904E\u6642\u9593 (ms)\n     */\n    double elapsed()\
      \ const {\n        auto end = clock::now();\n        return std::chrono::duration_cast<std::chrono::nanoseconds>(end\
      \ - start).count() * 1e-6;\n    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: others/timer.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/timer.hpp
layout: document
---
