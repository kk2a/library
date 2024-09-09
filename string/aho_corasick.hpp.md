---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/trie.hpp
    title: data_structure/trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/aho_corasick.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <queue>\n#include <string>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <vector>\n\n#line 1 \"data_structure/trie.hpp\"\n\n\n\n#include <cstring>\n\
    #include <functional>\n#line 8 \"data_structure/trie.hpp\"\n\nnamespace kk2 {\n\
    \ntemplate <int char_size> struct TrieNode {\n    int nxt[char_size];\n    int\
    \ exist;\n    std::vector<int> accept;\n\n    TrieNode() : exist(0) { memset(nxt,\
    \ -1, sizeof(nxt)); }\n};\n\ntemplate <int char_size, int margin> struct Trie\
    \ {\n    using Node = TrieNode<char_size>;\n\n    std::vector<Node> nodes;\n \
    \   constexpr static int root = 0;\n\n    Trie() { nodes.emplace_back(); }\n\n\
    \    int push_node() {\n        nodes.emplace_back();\n        return (int)nodes.size()\
    \ - 1;\n    }\n\n    void update_direct(int node, int id) { nodes[node].accept.push_back(id);\
    \ }\n\n    void update_child(int node) { ++nodes[node].exist; }\n\n    void add(const\
    \ std::string &str) {\n        const int id = nodes[root].exist;\n        auto\
    \ rec = [&](auto self, int now, int idx) -> void {\n            if (idx == (int)str.size())\
    \ {\n                update_direct(now, id);\n                return;\n      \
    \      }\n            const int d = str[idx] - margin;\n            if (nodes[now].nxt[d]\
    \ == -1) nodes[now].nxt[d] = push_node();\n            self(self, nodes[now].nxt[d],\
    \ idx + 1);\n            update_child(now);\n        };\n        rec(rec, root,\
    \ 0);\n    }\n\n    template <void (*f)(int)> void query(const std::string &str)\
    \ {\n        query(str, [](int idx) { f(idx); });\n    }\n\n    template <class\
    \ F> void query(const std::string &str, const F &f) {\n        int now = root;\n\
    \        for (char c : str) {\n            for (int &idx : nodes[now].accept)\
    \ f(idx);\n            const int d = c - margin;\n            now = nodes[now].nxt[d];\n\
    \            if (now == -1) return;\n        }\n        for (int idx : nodes[now].accept)\
    \ f(idx);\n    }\n\n    int count() const { return (int)nodes[0].exist; }\n\n\
    \    int size() const { return (int)nodes.size(); }\n\n    // return the number\
    \ of strings which have the prefix\n    // corresponding to the node_id\n    int\
    \ size(int node_idx) const {\n        return (int)nodes[node_idx].accept.size()\
    \ + nodes[node_idx].exist;\n    }\n};\n\n} // namespace kk2\n\n\n#line 12 \"string/aho_corasick.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int char_size, int margin, bool heavy = true>\n\
    struct AhoCorasick : Trie<char_size + 1, margin> {\n    using Trie<char_size +\
    \ 1, margin>::Trie;\n\n    constexpr static int FAIL = char_size;\n    std::vector<int>\
    \ correct;\n\n    void build() {\n        correct.resize(this->size());\n    \
    \    for (int i = 0; i < (int)this->size(); ++i) {\n            std::sort(std::begin(this->nodes[i].accept),\n\
    \                      std::end(this->nodes[i].accept));\n            correct[i]\
    \ = (int)this->nodes[i].accept.size();\n        }\n        std::queue<int> que;\n\
    \        for (int i = 0; i <= char_size; ++i) {\n            if (this->nodes[this->root].nxt[i]\
    \ == -1) {\n                this->nodes[this->root].nxt[i] = this->root;\n   \
    \         } else {\n                this->nodes[this->nodes[this->root].nxt[i]].nxt[FAIL]\
    \ =\n                    this->root;\n                que.emplace(this->nodes[this->root].nxt[i]);\n\
    \            }\n        }\n        while (!que.empty()) {\n            auto &now\
    \ = this->nodes[que.front()];\n            int fail = now.nxt[FAIL];\n       \
    \     correct[que.front()] += correct[fail];\n            que.pop();\n       \
    \     for (int i = 0; i < char_size; ++i) {\n                if (now.nxt[i] ==\
    \ -1) {\n                    now.nxt[i] = this->nodes[fail].nxt[i];\n        \
    \        } else {\n                    this->nodes[now.nxt[i]].nxt[FAIL] =\n \
    \                       this->nodes[fail].nxt[i];\n                    if (heavy)\
    \ {\n                        auto &u = this->nodes[now.nxt[i]].accept;\n     \
    \                   auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;\n\
    \                        std::vector<int> accept;\n                        std::set_union(std::begin(u),\n\
    \                                       std::end(u),\n                       \
    \                std::begin(v),\n                                       std::end(v),\n\
    \                                       std::back_inserter(accept));\n       \
    \                 u = accept;\n                    }\n                    que.emplace(now.nxt[i]);\n\
    \                }\n            }\n        }\n    }\n\n    std::conditional_t<heavy,\
    \ std::unordered_map<int, long long>, long long>\n    match(const std::string\
    \ &str, int now_ = 0) {\n        std::unordered_map<int, int> visit_cnt;\n   \
    \     for (char c : str) {\n            now_ = this->nodes[now_].nxt[c - margin];\n\
    \            visit_cnt[now_]++;\n        }\n        std::conditional_t<heavy,\
    \ std::unordered_map<int, long long>, long long>\n            res{};\n       \
    \ for (auto &&[now, cnt] : visit_cnt) {\n            if constexpr (heavy) {\n\
    \                for (int idx : this->nodes[now].accept) res[idx] += cnt;\n  \
    \          } else {\n                res += (long long)correct[now] * cnt;\n \
    \           }\n        }\n        return res;\n    }\n\n    int move(int now,\
    \ char c) { return this->nodes[now].nxt[c - margin]; }\n\n    int count(int node)\
    \ const { return correct[node]; }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef STRING_AHO_CORASICK_HPP\n#define STRING_AHO_CORASICK_HPP 1\n\n#include\
    \ <algorithm>\n#include <queue>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <vector>\n\n#include \"../data_structure/trie.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int char_size, int margin, bool heavy = true>\n\
    struct AhoCorasick : Trie<char_size + 1, margin> {\n    using Trie<char_size +\
    \ 1, margin>::Trie;\n\n    constexpr static int FAIL = char_size;\n    std::vector<int>\
    \ correct;\n\n    void build() {\n        correct.resize(this->size());\n    \
    \    for (int i = 0; i < (int)this->size(); ++i) {\n            std::sort(std::begin(this->nodes[i].accept),\n\
    \                      std::end(this->nodes[i].accept));\n            correct[i]\
    \ = (int)this->nodes[i].accept.size();\n        }\n        std::queue<int> que;\n\
    \        for (int i = 0; i <= char_size; ++i) {\n            if (this->nodes[this->root].nxt[i]\
    \ == -1) {\n                this->nodes[this->root].nxt[i] = this->root;\n   \
    \         } else {\n                this->nodes[this->nodes[this->root].nxt[i]].nxt[FAIL]\
    \ =\n                    this->root;\n                que.emplace(this->nodes[this->root].nxt[i]);\n\
    \            }\n        }\n        while (!que.empty()) {\n            auto &now\
    \ = this->nodes[que.front()];\n            int fail = now.nxt[FAIL];\n       \
    \     correct[que.front()] += correct[fail];\n            que.pop();\n       \
    \     for (int i = 0; i < char_size; ++i) {\n                if (now.nxt[i] ==\
    \ -1) {\n                    now.nxt[i] = this->nodes[fail].nxt[i];\n        \
    \        } else {\n                    this->nodes[now.nxt[i]].nxt[FAIL] =\n \
    \                       this->nodes[fail].nxt[i];\n                    if (heavy)\
    \ {\n                        auto &u = this->nodes[now.nxt[i]].accept;\n     \
    \                   auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;\n\
    \                        std::vector<int> accept;\n                        std::set_union(std::begin(u),\n\
    \                                       std::end(u),\n                       \
    \                std::begin(v),\n                                       std::end(v),\n\
    \                                       std::back_inserter(accept));\n       \
    \                 u = accept;\n                    }\n                    que.emplace(now.nxt[i]);\n\
    \                }\n            }\n        }\n    }\n\n    std::conditional_t<heavy,\
    \ std::unordered_map<int, long long>, long long>\n    match(const std::string\
    \ &str, int now_ = 0) {\n        std::unordered_map<int, int> visit_cnt;\n   \
    \     for (char c : str) {\n            now_ = this->nodes[now_].nxt[c - margin];\n\
    \            visit_cnt[now_]++;\n        }\n        std::conditional_t<heavy,\
    \ std::unordered_map<int, long long>, long long>\n            res{};\n       \
    \ for (auto &&[now, cnt] : visit_cnt) {\n            if constexpr (heavy) {\n\
    \                for (int idx : this->nodes[now].accept) res[idx] += cnt;\n  \
    \          } else {\n                res += (long long)correct[now] * cnt;\n \
    \           }\n        }\n        return res;\n    }\n\n    int move(int now,\
    \ char c) { return this->nodes[now].nxt[c - margin]; }\n\n    int count(int node)\
    \ const { return correct[node]; }\n};\n\n} // namespace kk2\n\n#endif // STRING_AHO_CORASICK_HPP\n"
  dependsOn:
  - data_structure/trie.hpp
  isVerificationFile: false
  path: string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2024-09-10 08:16:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/aho_corasick.hpp
layout: document
redirect_from:
- /library/string/aho_corasick.hpp
- /library/string/aho_corasick.hpp.html
title: string/aho_corasick.hpp
---
