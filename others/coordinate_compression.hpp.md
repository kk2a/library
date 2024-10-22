---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_ds/ds_static_range_inversions.test.cpp
    title: verify/yosupo_ds/ds_static_range_inversions.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/coordinate_compression.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace kk2 {\n\n// Coordinate Compression\ntemplate <typename\
    \ S = int> struct CC {\n    std::vector<S> xs;\n    bool initialized;\n\n    CC()\
    \ : initialized(false) {}\n\n    CC(const std::vector<S> &xs_) : xs(xs_), initialized(false)\
    \ {}\n\n    void add(S x) {\n        xs.push_back(x);\n        initialized = false;\n\
    \    }\n\n    void add(const std::vector<S> &ys) {\n        std::copy(std::begin(ys),\
    \ std::end(ys), std::back_inserter(xs));\n        initialized = false;\n    }\n\
    \n    void build() {\n        std::sort(std::begin(xs), std::end(xs));\n     \
    \   xs.erase(std::unique(std::begin(xs), std::end(xs)), std::end(xs));\n     \
    \   initialized = true;\n    }\n\n    S operator[](int i) {\n        if (!initialized)\
    \ build();\n        return xs[i];\n    }\n\n    int size() {\n        if (!initialized)\
    \ build();\n        return xs.size();\n    }\n\n    int get(S x) {\n        if\
    \ (!initialized) build();\n        return std::upper_bound(std::begin(xs), std::end(xs),\
    \ x) - std::begin(xs) - 1;\n    }\n\n    std::vector<int> get(const std::vector<S>\
    \ &ys) {\n        std::vector<int> ret(ys.size());\n        for (int i = 0; i\
    \ < (int)ys.size(); ++i) ret[i] = get(ys[i]);\n        return ret;\n    }\n\n\
    \    int operator()(S x) { return get(x); }\n\n    std::vector<int> operator()(const\
    \ std::vector<S> &ys) { return get(ys); }\n\n    int lower(S x) {\n        if\
    \ (!initialized) build();\n        return std::lower_bound(std::begin(xs), std::end(xs),\
    \ x) - std::begin(xs);\n    }\n\n    int upper(S x) {\n        if (!initialized)\
    \ build();\n        return std::upper_bound(std::begin(xs), std::end(xs), x) -\
    \ std::begin(xs);\n    }\n\n    bool exist(S x) {\n        if (!initialized) build();\n\
    \        int idx = lower(x);\n        return idx < (int)xs.size() && xs[idx] ==\
    \ x;\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef OTHERS_COORDINATE_COMPRESSION_HPP\n#define OTHERS_COORDINATE_COMPRESSION_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\nnamespace kk2 {\n\n// Coordinate\
    \ Compression\ntemplate <typename S = int> struct CC {\n    std::vector<S> xs;\n\
    \    bool initialized;\n\n    CC() : initialized(false) {}\n\n    CC(const std::vector<S>\
    \ &xs_) : xs(xs_), initialized(false) {}\n\n    void add(S x) {\n        xs.push_back(x);\n\
    \        initialized = false;\n    }\n\n    void add(const std::vector<S> &ys)\
    \ {\n        std::copy(std::begin(ys), std::end(ys), std::back_inserter(xs));\n\
    \        initialized = false;\n    }\n\n    void build() {\n        std::sort(std::begin(xs),\
    \ std::end(xs));\n        xs.erase(std::unique(std::begin(xs), std::end(xs)),\
    \ std::end(xs));\n        initialized = true;\n    }\n\n    S operator[](int i)\
    \ {\n        if (!initialized) build();\n        return xs[i];\n    }\n\n    int\
    \ size() {\n        if (!initialized) build();\n        return xs.size();\n  \
    \  }\n\n    int get(S x) {\n        if (!initialized) build();\n        return\
    \ std::upper_bound(std::begin(xs), std::end(xs), x) - std::begin(xs) - 1;\n  \
    \  }\n\n    std::vector<int> get(const std::vector<S> &ys) {\n        std::vector<int>\
    \ ret(ys.size());\n        for (int i = 0; i < (int)ys.size(); ++i) ret[i] = get(ys[i]);\n\
    \        return ret;\n    }\n\n    int operator()(S x) { return get(x); }\n\n\
    \    std::vector<int> operator()(const std::vector<S> &ys) { return get(ys); }\n\
    \n    int lower(S x) {\n        if (!initialized) build();\n        return std::lower_bound(std::begin(xs),\
    \ std::end(xs), x) - std::begin(xs);\n    }\n\n    int upper(S x) {\n        if\
    \ (!initialized) build();\n        return std::upper_bound(std::begin(xs), std::end(xs),\
    \ x) - std::begin(xs);\n    }\n\n    bool exist(S x) {\n        if (!initialized)\
    \ build();\n        int idx = lower(x);\n        return idx < (int)xs.size() &&\
    \ xs[idx] == x;\n    }\n};\n\n} // namespace kk2\n\n#endif // OTHERS_COORDINATE_COMPRESSION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/coordinate_compression.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_ds/ds_static_range_inversions.test.cpp
documentation_of: others/coordinate_compression.hpp
layout: document
redirect_from:
- /library/others/coordinate_compression.hpp
- /library/others/coordinate_compression.hpp.html
title: others/coordinate_compression.hpp
---
