---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bbst/base/red_black_tree_base.hpp
    title: bbst/base/red_black_tree_base.hpp
  - icon: ':heavy_check_mark:'
    path: bbst/lazy_red_black_tree.hpp
    title: bbst/lazy_red_black_tree.hpp
  - icon: ':heavy_check_mark:'
    path: bbst/red_black_tree.hpp
    title: bbst/red_black_tree.hpp
  - icon: ':warning:'
    path: data_structure/ordered_set.hpp
    title: data_structure/ordered_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/vector_pool.hpp\"\n\n\n\n#include <vector>\n\nnamespace\
    \ kk2 {\n\ntemplate <typename T> struct VectorPool {\n    std::vector<T> pool;\n\
    \    std::vector<T *> ptrs;\n    int pos = 0;\n\n    VectorPool() = default;\n\
    \n    VectorPool(int n) : pool(n), ptrs(n) {}\n\n    inline T *alloc() { return\
    \ ptrs[pos++]; }\n\n    inline void free(T *ptr) { ptrs[--pos] = ptr; }\n\n  \
    \  void clear() {\n        for (size_t i = 0; i < pool.size(); i++) ptrs[i] =\
    \ &pool[i];\n        pos = 0;\n    }\n\n    T &operator[](int i) { return pool[i];\
    \ }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_OHTERS_VECTOR_POOL_HPP\n#define KK2_OHTERS_VECTOR_POOL_HPP 1\n\
    \n#include <vector>\n\nnamespace kk2 {\n\ntemplate <typename T> struct VectorPool\
    \ {\n    std::vector<T> pool;\n    std::vector<T *> ptrs;\n    int pos = 0;\n\n\
    \    VectorPool() = default;\n\n    VectorPool(int n) : pool(n), ptrs(n) {}\n\n\
    \    inline T *alloc() { return ptrs[pos++]; }\n\n    inline void free(T *ptr)\
    \ { ptrs[--pos] = ptr; }\n\n    void clear() {\n        for (size_t i = 0; i <\
    \ pool.size(); i++) ptrs[i] = &pool[i];\n        pos = 0;\n    }\n\n    T &operator[](int\
    \ i) { return pool[i]; }\n};\n\n} // namespace kk2\n\n#endif // KK2_OHTERS_VECTOR_POOL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/vector_pool.hpp
  requiredBy:
  - data_structure/ordered_set.hpp
  - bbst/lazy_red_black_tree.hpp
  - bbst/red_black_tree.hpp
  - bbst/base/red_black_tree_base.hpp
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: others/vector_pool.hpp
layout: document
redirect_from:
- /library/others/vector_pool.hpp
- /library/others/vector_pool.hpp.html
title: others/vector_pool.hpp
---
