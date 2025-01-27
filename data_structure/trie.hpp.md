---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/aho_corasick.hpp
    title: string/aho_corasick.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yuki/yuki_0430.test.cpp
    title: verify/yuki/yuki_0430.test.cpp
  - icon: ':x:'
    path: verify/yuki/yuki_0430_2.test.cpp
    title: verify/yuki/yuki_0430_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/trie.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <cstring>\n#include <functional>\n#include <string>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\ntemplate <int char_size> struct TrieNode {\n    int nxt[char_size];\n\
    \    // \u901A\u904E\u3057\u305F\u56DE\u6570\uFF0C\u7D42\u70B9\u306F\u542B\u307E\
    \u306A\u3044\n    int passing;\n    // \u3053\u306E\u30CE\u30FC\u30C9\u304C\u7D42\
    \u70B9\u306Eid\u305F\u3061\n    std::vector<int> accept;\n\n    TrieNode() : passing(0)\
    \ { std::fill(nxt, nxt + char_size, -1); }\n};\n\ntemplate <int char_size, int\
    \ margin> struct Trie {\n    using Node = TrieNode<char_size>;\n\n    std::vector<Node>\
    \ nodes;\n    constexpr static int root = 0;\n\n    Trie() { nodes.emplace_back();\
    \ }\n\n    Trie(int Num) {\n        nodes.reserve(Num);\n        nodes.emplace_back();\n\
    \    }\n\n    int push_node() {\n        nodes.emplace_back();\n        return\
    \ (int)nodes.size() - 1;\n    }\n\n    void update_direct(int node, int id) {\
    \ nodes[node].accept.push_back(id); }\n\n    void update_child(int node) { ++nodes[node].passing;\
    \ }\n\n    void add(const std::string &str) {\n        assert(!str.empty());\n\
    \        const int id = nodes[root].passing;\n        int now = root;\n      \
    \  for (int i = 0; i < (int)str.size(); ++i) {\n            const int d = str[i]\
    \ - margin;\n            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();\n\
    \            update_child(now);\n            now = nodes[now].nxt[d];\n      \
    \  }\n        update_direct(now, id);\n    }\n\n    template <void (*f)(int)>\
    \ void query(const std::string &str) {\n        query(str, [](int idx) { f(idx);\
    \ });\n    }\n\n    template <class F> void query(const std::string &str, const\
    \ F &f) {\n        int now = root;\n        for (char c : str) {\n           \
    \ for (int &idx : nodes[now].accept) f(idx);\n            const int d = c - margin;\n\
    \            now = nodes[now].nxt[d];\n            if (now == -1) return;\n  \
    \      }\n        for (int idx : nodes[now].accept) f(idx);\n    }\n\n    int\
    \ count() const { return nodes[0].passing; }\n\n    int size() const { return\
    \ (int)nodes.size(); }\n\n    // return the number of strings which have the prefix\
    \ corresponding to the node_id\n    int size(int node_idx) const {\n        return\
    \ (int)nodes[node_idx].accept.size() + nodes[node_idx].passing;\n    }\n};\n\n\
    } // namespace kk2\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_TRIE_HPP\n#define KK2_DATA_STRUCTURE_TRIE_HPP\
    \ 1\n\n#include <cassert>\n#include <cstring>\n#include <functional>\n#include\
    \ <string>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <int char_size> struct\
    \ TrieNode {\n    int nxt[char_size];\n    // \u901A\u904E\u3057\u305F\u56DE\u6570\
    \uFF0C\u7D42\u70B9\u306F\u542B\u307E\u306A\u3044\n    int passing;\n    // \u3053\
    \u306E\u30CE\u30FC\u30C9\u304C\u7D42\u70B9\u306Eid\u305F\u3061\n    std::vector<int>\
    \ accept;\n\n    TrieNode() : passing(0) { std::fill(nxt, nxt + char_size, -1);\
    \ }\n};\n\ntemplate <int char_size, int margin> struct Trie {\n    using Node\
    \ = TrieNode<char_size>;\n\n    std::vector<Node> nodes;\n    constexpr static\
    \ int root = 0;\n\n    Trie() { nodes.emplace_back(); }\n\n    Trie(int Num) {\n\
    \        nodes.reserve(Num);\n        nodes.emplace_back();\n    }\n\n    int\
    \ push_node() {\n        nodes.emplace_back();\n        return (int)nodes.size()\
    \ - 1;\n    }\n\n    void update_direct(int node, int id) { nodes[node].accept.push_back(id);\
    \ }\n\n    void update_child(int node) { ++nodes[node].passing; }\n\n    void\
    \ add(const std::string &str) {\n        assert(!str.empty());\n        const\
    \ int id = nodes[root].passing;\n        int now = root;\n        for (int i =\
    \ 0; i < (int)str.size(); ++i) {\n            const int d = str[i] - margin;\n\
    \            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();\n \
    \           update_child(now);\n            now = nodes[now].nxt[d];\n       \
    \ }\n        update_direct(now, id);\n    }\n\n    template <void (*f)(int)> void\
    \ query(const std::string &str) {\n        query(str, [](int idx) { f(idx); });\n\
    \    }\n\n    template <class F> void query(const std::string &str, const F &f)\
    \ {\n        int now = root;\n        for (char c : str) {\n            for (int\
    \ &idx : nodes[now].accept) f(idx);\n            const int d = c - margin;\n \
    \           now = nodes[now].nxt[d];\n            if (now == -1) return;\n   \
    \     }\n        for (int idx : nodes[now].accept) f(idx);\n    }\n\n    int count()\
    \ const { return nodes[0].passing; }\n\n    int size() const { return (int)nodes.size();\
    \ }\n\n    // return the number of strings which have the prefix corresponding\
    \ to the node_id\n    int size(int node_idx) const {\n        return (int)nodes[node_idx].accept.size()\
    \ + nodes[node_idx].passing;\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_DATA_STRUCTURE_TRIE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/trie.hpp
  requiredBy:
  - string/aho_corasick.hpp
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yuki/yuki_0430_2.test.cpp
  - verify/yuki/yuki_0430.test.cpp
documentation_of: data_structure/trie.hpp
layout: document
redirect_from:
- /library/data_structure/trie.hpp
- /library/data_structure/trie.hpp.html
title: data_structure/trie.hpp
---
