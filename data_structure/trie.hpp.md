---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/aho_corasick.hpp
    title: string/aho_corasick.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/trie.hpp\"\n\n\n\ntemplate <int char_size>\n\
    struct TrieNode {\n    int nxt[char_size];\n    int exist;\n    vector<int> accept;\n\
    \    TrieNode() : exist(0) { memset(nxt, -1, sizeof(nxt)); }\n};\n\ntemplate <int\
    \ char_size, int margin>\nstruct Trie {\n    using Node = TrieNode<char_size>;\n\
    \n    vector<Node> nodes;\n    constexpr static int root = 0;\n\n    Trie() {\
    \ nodes.emplace_back(); }\n\n    int push_node() {\n        nodes.emplace_back();\n\
    \        return (int)nodes.size() - 1;\n    }\n\n    void update_direct(int node,\
    \ int id) { nodes[node].accept.push_back(id); }\n\n    void update_child(int node)\
    \ { ++nodes[node].exist; }\n\n    void add(const string& str) {\n        const\
    \ int id = nodes[root].exist;\n        auto rec = [&](auto self, int now, int\
    \ idx) -> void {\n            if (idx == (int)str.size()) {\n                update_direct(now,\
    \ id);\n                return;\n            }\n            const int d = str[idx]\
    \ - margin;\n            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();\n\
    \            self(self, nodes[now].nxt[d], idx + 1);\n            update_child(now);\n\
    \        };\n        rec(rec, root, 0);\n    }\n\n    template <void (*f)(int)>\n\
    \    void query(const string& str) {\n        query(str, [](int idx) { f(idx);\
    \ });\n    }\n\n    template <class F>\n    void query(const string& str, const\
    \ F& f) {\n        int now = root;\n        for (char c : str) {\n           \
    \ for (int& idx : nodes[now].accept) f(idx);\n            const int d = c - margin;\n\
    \            now = nodes[now].nxt[d];\n            if (now == -1) return;\n  \
    \      }\n        for (int idx : nodes[now].accept) f(idx);\n    }\n\n    int\
    \ count() const { return (int)nodes[0].exist; }\n\n    int size() const { return\
    \ (int)nodes.size(); }\n\n    // return the number of strings which have the prefix\n\
    \    // corresponding to the node_id\n    int size(int node_idx) const {\n   \
    \     return (int)nodes[node_idx].accept.size() + nodes[node_idx].exist;\n   \
    \ }\n};\n\n\n"
  code: "#ifndef DATA_STRUCTURE_TRIE_HPP\n#define DATA_STRUCTURE_TRIE_HPP 1\n\ntemplate\
    \ <int char_size>\nstruct TrieNode {\n    int nxt[char_size];\n    int exist;\n\
    \    vector<int> accept;\n    TrieNode() : exist(0) { memset(nxt, -1, sizeof(nxt));\
    \ }\n};\n\ntemplate <int char_size, int margin>\nstruct Trie {\n    using Node\
    \ = TrieNode<char_size>;\n\n    vector<Node> nodes;\n    constexpr static int\
    \ root = 0;\n\n    Trie() { nodes.emplace_back(); }\n\n    int push_node() {\n\
    \        nodes.emplace_back();\n        return (int)nodes.size() - 1;\n    }\n\
    \n    void update_direct(int node, int id) { nodes[node].accept.push_back(id);\
    \ }\n\n    void update_child(int node) { ++nodes[node].exist; }\n\n    void add(const\
    \ string& str) {\n        const int id = nodes[root].exist;\n        auto rec\
    \ = [&](auto self, int now, int idx) -> void {\n            if (idx == (int)str.size())\
    \ {\n                update_direct(now, id);\n                return;\n      \
    \      }\n            const int d = str[idx] - margin;\n            if (nodes[now].nxt[d]\
    \ == -1) nodes[now].nxt[d] = push_node();\n            self(self, nodes[now].nxt[d],\
    \ idx + 1);\n            update_child(now);\n        };\n        rec(rec, root,\
    \ 0);\n    }\n\n    template <void (*f)(int)>\n    void query(const string& str)\
    \ {\n        query(str, [](int idx) { f(idx); });\n    }\n\n    template <class\
    \ F>\n    void query(const string& str, const F& f) {\n        int now = root;\n\
    \        for (char c : str) {\n            for (int& idx : nodes[now].accept)\
    \ f(idx);\n            const int d = c - margin;\n            now = nodes[now].nxt[d];\n\
    \            if (now == -1) return;\n        }\n        for (int idx : nodes[now].accept)\
    \ f(idx);\n    }\n\n    int count() const { return (int)nodes[0].exist; }\n\n\
    \    int size() const { return (int)nodes.size(); }\n\n    // return the number\
    \ of strings which have the prefix\n    // corresponding to the node_id\n    int\
    \ size(int node_idx) const {\n        return (int)nodes[node_idx].accept.size()\
    \ + nodes[node_idx].exist;\n    }\n};\n\n#endif // DATA_STRUCTURE_TRIE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/trie.hpp
  requiredBy:
  - string/aho_corasick.hpp
  timestamp: '2024-08-23 01:28:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/trie.hpp
layout: document
redirect_from:
- /library/data_structure/trie.hpp
- /library/data_structure/trie.hpp.html
title: data_structure/trie.hpp
---
