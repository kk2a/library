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
  bundledCode: "#line 1 \"others/coordinate_compression.hpp\"\n\n\n\n\n// Coordinate\
    \ Compression\ntemplate <typename S=int>\nstruct CC {\n    vector<S> xs;\n   \
    \ bool initialized;\n    CC() : initialized(false) {}\n    CC(const vector<S>&\
    \ xs_) : xs(xs_), initialized(false) {}\n    void add(S x) {\n        xs.push_back(x);\n\
    \        initialized = false;\n    }\n    void add(const vector<S>& ys) {\n  \
    \      copy(begin(ys), end(ys), back_inserter(xs));\n        initialized = false;\n\
    \    }\n    void build() {\n        sort(begin(xs), end(xs));\n        xs.erase(unique(begin(xs),\
    \ end(xs)), end(xs));\n        initialized = true;\n    }\n    S operator[](int\
    \ i) {\n        if (!initialized) build();\n        return xs[i];\n    }\n   \
    \ int size() const {\n        return xs.size();\n    }\n\n    int get(S x) {\n\
    \        if (!initialized) build();\n        return lower_bound(begin(xs), end(xs),\
    \ x) - begin(xs);\n    }\n\n    vector<int> get(const vector<S>& ys) {\n     \
    \   vector<int> ret(ys.size());\n        for (int i = 0; i < (int)ys.size(); ++i)\
    \ ret[i] = get(ys[i]);\n        return ret;\n    }\n};\n\n\n"
  code: "#ifndef OTHERS_COORDINATE_COMPRESSION_HPP\n#define OTHERS_COORDINATE_COMPRESSION_HPP\
    \ 1\n\n\n// Coordinate Compression\ntemplate <typename S=int>\nstruct CC {\n \
    \   vector<S> xs;\n    bool initialized;\n    CC() : initialized(false) {}\n \
    \   CC(const vector<S>& xs_) : xs(xs_), initialized(false) {}\n    void add(S\
    \ x) {\n        xs.push_back(x);\n        initialized = false;\n    }\n    void\
    \ add(const vector<S>& ys) {\n        copy(begin(ys), end(ys), back_inserter(xs));\n\
    \        initialized = false;\n    }\n    void build() {\n        sort(begin(xs),\
    \ end(xs));\n        xs.erase(unique(begin(xs), end(xs)), end(xs));\n        initialized\
    \ = true;\n    }\n    S operator[](int i) {\n        if (!initialized) build();\n\
    \        return xs[i];\n    }\n    int size() const {\n        return xs.size();\n\
    \    }\n\n    int get(S x) {\n        if (!initialized) build();\n        return\
    \ lower_bound(begin(xs), end(xs), x) - begin(xs);\n    }\n\n    vector<int> get(const\
    \ vector<S>& ys) {\n        vector<int> ret(ys.size());\n        for (int i =\
    \ 0; i < (int)ys.size(); ++i) ret[i] = get(ys[i]);\n        return ret;\n    }\n\
    };\n\n#endif // OTHERS_COORDINATE_COMPRESSION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/coordinate_compression.hpp
  requiredBy: []
  timestamp: '2024-07-03 14:07:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/coordinate_compression.hpp
layout: document
redirect_from:
- /library/others/coordinate_compression.hpp
- /library/others/coordinate_compression.hpp.html
title: others/coordinate_compression.hpp
---
