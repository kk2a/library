---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bbst/base/red_black_tree_base.hpp
    title: "\u8D64\u9ED2\u6728\u306E\u57FA\u672C\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: bbst/lazy_red_black_tree.hpp
    title: bbst/lazy_red_black_tree.hpp
  - icon: ':warning:'
    path: bbst/persistent_lazy_red_black_tree.hpp
    title: bbst/persistent_lazy_red_black_tree.hpp
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
    path: verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
    title: verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
    title: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/vector_pool.hpp\"\n\n\n\n#include <memory>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\ntemplate <typename T> struct VectorPool {\n \
    \ private:\n    static constexpr size_t CHUNK_SIZE = 1 << 11;\n    std::vector<std::unique_ptr<T[]>>\
    \ chunks; // \u56FA\u5B9A\u30B5\u30A4\u30BA\u914D\u5217\u306E\u30DD\u30A4\u30F3\
    \u30BF\n    std::vector<T *> free_ptrs;\n    size_t pos = 0;\n\n  public:\n  \
    \  VectorPool() = default;\n    VectorPool(int n) { reserve(n); }\n\n    inline\
    \ T *alloc() {\n        if (pos >= free_ptrs.size()) { expand(); }\n        return\
    \ free_ptrs[pos++];\n    }\n\n    inline void free(T *ptr) { free_ptrs[--pos]\
    \ = ptr; }\n\n    void clear() {\n        pos = 0;\n        size_t idx = 0;\n\
    \        for (auto &chunk : chunks) {\n            for (size_t i = 0; i < CHUNK_SIZE;\
    \ i++) { free_ptrs[idx++] = &chunk[i]; }\n        }\n    }\n\n    void reserve(int\
    \ n) {\n        size_t needed_chunks = (n + CHUNK_SIZE - 1) / CHUNK_SIZE;\n  \
    \      size_t current_chunks = chunks.size();\n\n        if (needed_chunks <=\
    \ current_chunks) return;\n\n        chunks.reserve(needed_chunks);\n        free_ptrs.reserve(n);\n\
    \n        // \u4E00\u5EA6\u306B\u5FC5\u8981\u306A\u5206\u306E\u30C1\u30E3\u30F3\
    \u30AF\u3092\u78BA\u4FDD\n        size_t old_free_size = free_ptrs.size();\n \
    \       size_t new_chunks_count = needed_chunks - current_chunks;\n        free_ptrs.resize(old_free_size\
    \ + new_chunks_count * CHUNK_SIZE);\n\n        for (size_t chunk_idx = 0; chunk_idx\
    \ < new_chunks_count; ++chunk_idx) {\n            auto new_chunk = std::make_unique<T[]>(CHUNK_SIZE);\n\
    \            T *chunk_ptr = new_chunk.get();\n            chunks.push_back(std::move(new_chunk));\n\
    \n            size_t base_idx = old_free_size + chunk_idx * CHUNK_SIZE;\n    \
    \        for (size_t i = 0; i < CHUNK_SIZE; ++i) { free_ptrs[base_idx + i] = &chunk_ptr[i];\
    \ }\n        }\n    }\n\n  private:\n    void expand() { add_chunk(); }\n\n  \
    \  void add_chunk() {\n        auto new_chunk = std::make_unique<T[]>(CHUNK_SIZE);\n\
    \        T *chunk_ptr = new_chunk.get();\n        chunks.push_back(std::move(new_chunk));\n\
    \n        size_t old_size = free_ptrs.size();\n        free_ptrs.resize(old_size\
    \ + CHUNK_SIZE);\n\n        for (size_t i = 0; i < CHUNK_SIZE; i++) { free_ptrs[old_size\
    \ + i] = &chunk_ptr[i]; }\n    }\n\n  public:\n    size_t size() const { return\
    \ chunks.size() * CHUNK_SIZE; }\n\n    size_t available() const { return free_ptrs.size()\
    \ - pos; }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_OHTERS_VECTOR_POOL_HPP\n#define KK2_OHTERS_VECTOR_POOL_HPP 1\n\
    \n#include <memory>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> struct VectorPool {\n  private:\n    static constexpr size_t CHUNK_SIZE =\
    \ 1 << 11;\n    std::vector<std::unique_ptr<T[]>> chunks; // \u56FA\u5B9A\u30B5\
    \u30A4\u30BA\u914D\u5217\u306E\u30DD\u30A4\u30F3\u30BF\n    std::vector<T *> free_ptrs;\n\
    \    size_t pos = 0;\n\n  public:\n    VectorPool() = default;\n    VectorPool(int\
    \ n) { reserve(n); }\n\n    inline T *alloc() {\n        if (pos >= free_ptrs.size())\
    \ { expand(); }\n        return free_ptrs[pos++];\n    }\n\n    inline void free(T\
    \ *ptr) { free_ptrs[--pos] = ptr; }\n\n    void clear() {\n        pos = 0;\n\
    \        size_t idx = 0;\n        for (auto &chunk : chunks) {\n            for\
    \ (size_t i = 0; i < CHUNK_SIZE; i++) { free_ptrs[idx++] = &chunk[i]; }\n    \
    \    }\n    }\n\n    void reserve(int n) {\n        size_t needed_chunks = (n\
    \ + CHUNK_SIZE - 1) / CHUNK_SIZE;\n        size_t current_chunks = chunks.size();\n\
    \n        if (needed_chunks <= current_chunks) return;\n\n        chunks.reserve(needed_chunks);\n\
    \        free_ptrs.reserve(n);\n\n        // \u4E00\u5EA6\u306B\u5FC5\u8981\u306A\
    \u5206\u306E\u30C1\u30E3\u30F3\u30AF\u3092\u78BA\u4FDD\n        size_t old_free_size\
    \ = free_ptrs.size();\n        size_t new_chunks_count = needed_chunks - current_chunks;\n\
    \        free_ptrs.resize(old_free_size + new_chunks_count * CHUNK_SIZE);\n\n\
    \        for (size_t chunk_idx = 0; chunk_idx < new_chunks_count; ++chunk_idx)\
    \ {\n            auto new_chunk = std::make_unique<T[]>(CHUNK_SIZE);\n       \
    \     T *chunk_ptr = new_chunk.get();\n            chunks.push_back(std::move(new_chunk));\n\
    \n            size_t base_idx = old_free_size + chunk_idx * CHUNK_SIZE;\n    \
    \        for (size_t i = 0; i < CHUNK_SIZE; ++i) { free_ptrs[base_idx + i] = &chunk_ptr[i];\
    \ }\n        }\n    }\n\n  private:\n    void expand() { add_chunk(); }\n\n  \
    \  void add_chunk() {\n        auto new_chunk = std::make_unique<T[]>(CHUNK_SIZE);\n\
    \        T *chunk_ptr = new_chunk.get();\n        chunks.push_back(std::move(new_chunk));\n\
    \n        size_t old_size = free_ptrs.size();\n        free_ptrs.resize(old_size\
    \ + CHUNK_SIZE);\n\n        for (size_t i = 0; i < CHUNK_SIZE; i++) { free_ptrs[old_size\
    \ + i] = &chunk_ptr[i]; }\n    }\n\n  public:\n    size_t size() const { return\
    \ chunks.size() * CHUNK_SIZE; }\n\n    size_t available() const { return free_ptrs.size()\
    \ - pos; }\n};\n\n} // namespace kk2\n\n#endif // KK2_OHTERS_VECTOR_POOL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/vector_pool.hpp
  requiredBy:
  - data_structure/ordered_set.hpp
  - bbst/red_black_tree.hpp
  - bbst/base/red_black_tree_base.hpp
  - bbst/lazy_red_black_tree.hpp
  - bbst/persistent_lazy_red_black_tree.hpp
  timestamp: '2025-10-08 11:14:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
  - verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
documentation_of: others/vector_pool.hpp
layout: document
redirect_from:
- /library/others/vector_pool.hpp
- /library/others/vector_pool.hpp.html
title: others/vector_pool.hpp
---
