---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: ds_point_set_range_composite_large_2.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
    type: Required by
  - files:
    - filename: ds_range_affine_range_sum_large_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
    - filename: ds_static_range_inversions.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_range_inversions.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_OTHERS_COORDINATE_COMPRESSION_HPP\n#define KK2_OTHERS_COORDINATE_COMPRESSION_HPP\
      \ 1\n\n#include <algorithm>\n#include <vector>\n\nnamespace kk2 {\n\n// Coordinate\
      \ Compression\ntemplate <typename S = int> struct CC {\n    std::vector<S> xs;\n\
      \    bool initialized;\n\n    CC() : initialized(false) {}\n\n    CC(const std::vector<S>\
      \ &xs_) : xs(xs_), initialized(false) {}\n\n    void add(S x) {\n        xs.push_back(x);\n\
      \        initialized = false;\n    }\n\n    void add(const std::vector<S> &ys)\
      \ {\n        std::copy(std::begin(ys), std::end(ys), std::back_inserter(xs));\n\
      \        initialized = false;\n    }\n\n    void build() {\n        std::sort(std::begin(xs),\
      \ std::end(xs));\n        xs.erase(std::unique(std::begin(xs), std::end(xs)),\
      \ std::end(xs));\n        initialized = true;\n    }\n\n    S operator[](int\
      \ i) {\n        if (!initialized) build();\n        return xs[i];\n    }\n\n\
      \    int size() {\n        if (!initialized) build();\n        return xs.size();\n\
      \    }\n\n    int get(S x) {\n        if (!initialized) build();\n        return\
      \ std::upper_bound(std::begin(xs), std::end(xs), x) - std::begin(xs) - 1;\n\
      \    }\n\n    std::vector<int> get(const std::vector<S> &ys) {\n        std::vector<int>\
      \ ret(ys.size());\n        for (int i = 0; i < (int)ys.size(); ++i) ret[i] =\
      \ get(ys[i]);\n        return ret;\n    }\n\n    int operator()(S x) { return\
      \ get(x); }\n\n    std::vector<int> operator()(const std::vector<S> &ys) { return\
      \ get(ys); }\n\n    int lower(S x) {\n        if (!initialized) build();\n \
      \       return std::lower_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);\n\
      \    }\n\n    int upper(S x) {\n        if (!initialized) build();\n       \
      \ return std::upper_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);\n\
      \    }\n\n    bool exist(S x) {\n        if (!initialized) build();\n      \
      \  int idx = lower(x);\n        return idx < (int)xs.size() && xs[idx] == x;\n\
      \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_OTHERS_COORDINATE_COMPRESSION_HPP\n"
    name: default
  - code: "#line 1 \"others/coordinate_compression.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <vector>\n\nnamespace kk2 {\n\n// Coordinate Compression\ntemplate\
      \ <typename S = int> struct CC {\n    std::vector<S> xs;\n    bool initialized;\n\
      \n    CC() : initialized(false) {}\n\n    CC(const std::vector<S> &xs_) : xs(xs_),\
      \ initialized(false) {}\n\n    void add(S x) {\n        xs.push_back(x);\n \
      \       initialized = false;\n    }\n\n    void add(const std::vector<S> &ys)\
      \ {\n        std::copy(std::begin(ys), std::end(ys), std::back_inserter(xs));\n\
      \        initialized = false;\n    }\n\n    void build() {\n        std::sort(std::begin(xs),\
      \ std::end(xs));\n        xs.erase(std::unique(std::begin(xs), std::end(xs)),\
      \ std::end(xs));\n        initialized = true;\n    }\n\n    S operator[](int\
      \ i) {\n        if (!initialized) build();\n        return xs[i];\n    }\n\n\
      \    int size() {\n        if (!initialized) build();\n        return xs.size();\n\
      \    }\n\n    int get(S x) {\n        if (!initialized) build();\n        return\
      \ std::upper_bound(std::begin(xs), std::end(xs), x) - std::begin(xs) - 1;\n\
      \    }\n\n    std::vector<int> get(const std::vector<S> &ys) {\n        std::vector<int>\
      \ ret(ys.size());\n        for (int i = 0; i < (int)ys.size(); ++i) ret[i] =\
      \ get(ys[i]);\n        return ret;\n    }\n\n    int operator()(S x) { return\
      \ get(x); }\n\n    std::vector<int> operator()(const std::vector<S> &ys) { return\
      \ get(ys); }\n\n    int lower(S x) {\n        if (!initialized) build();\n \
      \       return std::lower_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);\n\
      \    }\n\n    int upper(S x) {\n        if (!initialized) build();\n       \
      \ return std::upper_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);\n\
      \    }\n\n    bool exist(S x) {\n        if (!initialized) build();\n      \
      \  int idx = lower(x);\n        return idx < (int)xs.size() && xs[idx] == x;\n\
      \    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: others/coordinate_compression.hpp
  pathExtension: hpp
  requiredBy:
  - verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - verify/yosupo_ds/ds_static_range_inversions.test.cpp
documentation_of: others/coordinate_compression.hpp
layout: document
---
