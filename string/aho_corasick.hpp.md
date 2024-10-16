---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/trie.hpp
    title: data_structure/trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yuki/yuki_0430.test.cpp
    title: verify/yuki/yuki_0430.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki/yuki_0430_2.test.cpp
    title: verify/yuki/yuki_0430_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/aho_corasick.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <queue>\n#include <string>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <vector>\n\n#line 1 \"data_structure/trie.hpp\"\n\n\n\n#include <cassert>\n\
    #include <cstring>\n#include <functional>\n#line 9 \"data_structure/trie.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int char_size> struct TrieNode {\n    int nxt[char_size];\n\
    \    int exist;\n    std::vector<int> accept;\n\n    TrieNode() : exist(0) { memset(nxt,\
    \ -1, sizeof(nxt)); }\n};\n\ntemplate <int char_size, int margin> struct Trie\
    \ {\n    using Node = TrieNode<char_size>;\n\n    std::vector<Node> nodes;\n \
    \   constexpr static int root = 0;\n\n    Trie() { nodes.emplace_back(); }\n\n\
    \    int push_node() {\n        nodes.emplace_back();\n        return (int)nodes.size()\
    \ - 1;\n    }\n\n    void update_direct(int node, int id) { nodes[node].accept.push_back(id);\
    \ }\n\n    void update_child(int node) { ++nodes[node].exist; }\n\n    void add(const\
    \ std::string &str) {\n        assert(!str.empty());\n        const int id = nodes[root].exist;\n\
    \        auto rec = [&](auto self, int now, int idx) -> void {\n            if\
    \ (idx == (int)str.size()) {\n                update_direct(now, id);\n      \
    \          return;\n            }\n            const int d = str[idx] - margin;\n\
    \            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();\n \
    \           self(self, nodes[now].nxt[d], idx + 1);\n            update_child(now);\n\
    \        };\n        rec(rec, root, 0);\n    }\n\n    template <void (*f)(int)>\
    \ void query(const std::string &str) {\n        query(str, [](int idx) { f(idx);\
    \ });\n    }\n\n    template <class F> void query(const std::string &str, const\
    \ F &f) {\n        int now = root;\n        for (char c : str) {\n           \
    \ for (int &idx : nodes[now].accept) f(idx);\n            const int d = c - margin;\n\
    \            now = nodes[now].nxt[d];\n            if (now == -1) return;\n  \
    \      }\n        for (int idx : nodes[now].accept) f(idx);\n    }\n\n    int\
    \ count() const { return (int)nodes[0].exist; }\n\n    int size() const { return\
    \ (int)nodes.size(); }\n\n    // return the number of strings which have the prefix\n\
    \    // corresponding to the node_id\n    int size(int node_idx) const {\n   \
    \     return (int)nodes[node_idx].accept.size() + nodes[node_idx].exist;\n   \
    \ }\n};\n\n} // namespace kk2\n\n\n#line 12 \"string/aho_corasick.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <int char_size, int margin> struct AhoCorasick : Trie<char_size\
    \ + 1, margin> {\n    using Trie<char_size + 1, margin>::Trie;\n    using Trie<char_size\
    \ + 1, margin>::count;\n\n    constexpr static int FAIL = char_size;\n    std::vector<int>\
    \ correct, perm;\n\n    void build() {\n        correct.resize(this->size());\n\
    \        int now = 0;\n        perm.resize(this->size());\n        perm[now++]\
    \ = this->root;\n        for (int i = 0; i < (int)this->size(); ++i) {\n     \
    \       correct[i] = (int)this->nodes[i].accept.size();\n        }\n        std::queue<int>\
    \ que;\n        for (int i = 0; i <= char_size; ++i) {\n            if (this->nodes[this->root].nxt[i]\
    \ == -1) {\n                this->nodes[this->root].nxt[i] = this->root;\n   \
    \         } else {\n                this->nodes[this->nodes[this->root].nxt[i]].nxt[FAIL]\
    \ = this->root;\n                que.emplace(this->nodes[this->root].nxt[i]);\n\
    \            }\n        }\n        while (!que.empty()) {\n            perm[now++]\
    \ = que.front();\n            auto &now = this->nodes[que.front()];\n        \
    \    int fail = now.nxt[FAIL];\n            correct[que.front()] += correct[fail];\n\
    \            que.pop();\n            for (int i = 0; i < char_size; ++i) {\n \
    \               if (now.nxt[i] == -1) {\n                    now.nxt[i] = this->nodes[fail].nxt[i];\n\
    \                } else {\n                    this->nodes[now.nxt[i]].nxt[FAIL]\
    \ = this->nodes[fail].nxt[i];\n                    que.emplace(now.nxt[i]);\n\
    \                }\n            }\n        }\n    }\n\n    long long all_match(const\
    \ std::string &str, int now_ = 0) {\n        std::unordered_map<int, int> visit_cnt;\n\
    \        for (char c : str) {\n            now_ = this->nodes[now_].nxt[c - margin];\n\
    \            visit_cnt[now_]++;\n        }\n        long long res{};\n       \
    \ for (auto &&[now, cnt] : visit_cnt) { res += (long long)correct[now] * cnt;\
    \ }\n        return res;\n    }\n\n    std::vector<long long> each_match(const\
    \ std::string &str, int now_ = 0) {\n        std::vector<int> visit_cnt(this->size());\n\
    \        for (char c : str) {\n            now_ = this->nodes[now_].nxt[c - margin];\n\
    \            visit_cnt[now_]++;\n        }\n        std::vector<long long> res(this->count());\n\
    \        for (int i = this->size() - 1; i > 0; --i) {\n            int now = perm[i];\n\
    \            visit_cnt[this->nodes[now].nxt[FAIL]] += visit_cnt[now];\n      \
    \      for (int idx : this->nodes[now].accept) { res[idx] += visit_cnt[now]; }\n\
    \        }\n        return res;\n    }\n\n    int move(int now, char c) { return\
    \ this->nodes[now].nxt[c - margin]; }\n\n    int count(int node) const { return\
    \ correct[node]; }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef STRING_AHO_CORASICK_HPP\n#define STRING_AHO_CORASICK_HPP 1\n\n#include\
    \ <algorithm>\n#include <queue>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <vector>\n\n#include \"../data_structure/trie.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int char_size, int margin> struct AhoCorasick\
    \ : Trie<char_size + 1, margin> {\n    using Trie<char_size + 1, margin>::Trie;\n\
    \    using Trie<char_size + 1, margin>::count;\n\n    constexpr static int FAIL\
    \ = char_size;\n    std::vector<int> correct, perm;\n\n    void build() {\n  \
    \      correct.resize(this->size());\n        int now = 0;\n        perm.resize(this->size());\n\
    \        perm[now++] = this->root;\n        for (int i = 0; i < (int)this->size();\
    \ ++i) {\n            correct[i] = (int)this->nodes[i].accept.size();\n      \
    \  }\n        std::queue<int> que;\n        for (int i = 0; i <= char_size; ++i)\
    \ {\n            if (this->nodes[this->root].nxt[i] == -1) {\n               \
    \ this->nodes[this->root].nxt[i] = this->root;\n            } else {\n       \
    \         this->nodes[this->nodes[this->root].nxt[i]].nxt[FAIL] = this->root;\n\
    \                que.emplace(this->nodes[this->root].nxt[i]);\n            }\n\
    \        }\n        while (!que.empty()) {\n            perm[now++] = que.front();\n\
    \            auto &now = this->nodes[que.front()];\n            int fail = now.nxt[FAIL];\n\
    \            correct[que.front()] += correct[fail];\n            que.pop();\n\
    \            for (int i = 0; i < char_size; ++i) {\n                if (now.nxt[i]\
    \ == -1) {\n                    now.nxt[i] = this->nodes[fail].nxt[i];\n     \
    \           } else {\n                    this->nodes[now.nxt[i]].nxt[FAIL] =\
    \ this->nodes[fail].nxt[i];\n                    que.emplace(now.nxt[i]);\n  \
    \              }\n            }\n        }\n    }\n\n    long long all_match(const\
    \ std::string &str, int now_ = 0) {\n        std::unordered_map<int, int> visit_cnt;\n\
    \        for (char c : str) {\n            now_ = this->nodes[now_].nxt[c - margin];\n\
    \            visit_cnt[now_]++;\n        }\n        long long res{};\n       \
    \ for (auto &&[now, cnt] : visit_cnt) { res += (long long)correct[now] * cnt;\
    \ }\n        return res;\n    }\n\n    std::vector<long long> each_match(const\
    \ std::string &str, int now_ = 0) {\n        std::vector<int> visit_cnt(this->size());\n\
    \        for (char c : str) {\n            now_ = this->nodes[now_].nxt[c - margin];\n\
    \            visit_cnt[now_]++;\n        }\n        std::vector<long long> res(this->count());\n\
    \        for (int i = this->size() - 1; i > 0; --i) {\n            int now = perm[i];\n\
    \            visit_cnt[this->nodes[now].nxt[FAIL]] += visit_cnt[now];\n      \
    \      for (int idx : this->nodes[now].accept) { res[idx] += visit_cnt[now]; }\n\
    \        }\n        return res;\n    }\n\n    int move(int now, char c) { return\
    \ this->nodes[now].nxt[c - margin]; }\n\n    int count(int node) const { return\
    \ correct[node]; }\n};\n\n} // namespace kk2\n\n#endif // STRING_AHO_CORASICK_HPP\n"
  dependsOn:
  - data_structure/trie.hpp
  isVerificationFile: false
  path: string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2024-10-13 04:52:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki/yuki_0430.test.cpp
  - verify/yuki/yuki_0430_2.test.cpp
documentation_of: string/aho_corasick.hpp
layout: document
redirect_from:
- /library/string/aho_corasick.hpp
- /library/string/aho_corasick.hpp.html
title: string/aho_corasick.hpp
---
