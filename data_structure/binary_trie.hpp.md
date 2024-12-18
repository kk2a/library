---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
    title: verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
  - icon: ':x:'
    path: verify/yosupo_ds/ds_set_xor_min.test.cpp
    title: verify/yosupo_ds/ds_set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_trie.hpp\"\n\n\n\n#include <cassert>\n\
    #include <optional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> struct BinaryTrieNode {\n    int nxt[2];\n    // \u30CE\u30FC\u30C9\u306B\
    \u5BFE\u5FDC\u3059\u308Bprefix\u3092\u3082\u3064\u8981\u7D20\u306E\u6570\n   \
    \ // \u81EA\u5206\u81EA\u8EAB\u3082\u542B\u3080\n    int count;\n\n    BinaryTrieNode()\
    \ : count(0) { nxt[0] = nxt[1] = -1; }\n\n    template <typename U> friend U &operator<<(U\
    \ &os, const BinaryTrieNode &node) {\n        os << \"count: \" << node.count\
    \ << \" \";\n        os << \"nxt: \";\n        for (int i = 0; i < 2; ++i) os\
    \ << node.nxt[i] << \" \";\n        return os;\n    }\n};\n\ntemplate <typename\
    \ T, int MAX_LOG> struct BinaryTrie {\n    using Node = BinaryTrieNode<T>;\n\n\
    \    T lazy;\n    std::vector<Node> nodes;\n    constexpr static int root = 0;\n\
    \n    BinaryTrie() : lazy(T()) { nodes.emplace_back(); }\n\n    BinaryTrie(int\
    \ Num) : lazy(T()) {\n        nodes.reserve(Num);\n        nodes.emplace_back();\n\
    \    }\n\n    int push_node() {\n        nodes.emplace_back();\n        return\
    \ nodes.size() - 1;\n    }\n\n    template <bool isadd> void update_direct(int\
    \ node) {\n        if constexpr (isadd) ++nodes[node].count;\n        else --nodes[node].count;\n\
    \    }\n\n    template <bool isadd> void update_child(int node) {\n        if\
    \ constexpr (isadd) ++nodes[node].count;\n        else --nodes[node].count;\n\
    \    }\n\n    void insert(T x) {\n        x ^= lazy;\n        int now = root;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x\
    \ >> i) & 1;\n            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();\n\
    \            update_child<true>(now);\n            now = nodes[now].nxt[d];\n\
    \        }\n        update_direct<true>(now);\n    }\n\n    void erase(T x) {\n\
    \        x ^= lazy;\n        int now = root;\n        int st[MAX_LOG];\n     \
    \   for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x >>\
    \ i) & 1;\n            if (nodes[now].nxt[d] == -1) return;\n            st[i]\
    \ = now;\n            now = nodes[now].nxt[d];\n        }\n        update_direct<false>(now);\n\
    \        for (int i = 0; i < MAX_LOG; ++i) {\n            update_child<false>(st[i]);\n\
    \            if (!nodes[now].count) nodes[st[i]].nxt[(x >> i) & 1] = -1;\n   \
    \         now = st[i];\n        }\n    }\n\n    void operate_xor(T x) { lazy ^=\
    \ x; }\n\n    std::optional<T> get_kth(int k) const {\n        if (k >= nodes[root].count)\
    \ return std::nullopt;\n        int now = root, less = 0;\n        T res = 0;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (lazy\
    \ >> i) & 1;\n            if (nodes[now].nxt[d] == -1 or less + nodes[nodes[now].nxt[d]].count\
    \ <= k) {\n                if (nodes[now].nxt[d] != -1) less += nodes[nodes[now].nxt[d]].count;\n\
    \                res |= (T(1) << i);\n                now = nodes[now].nxt[d ^\
    \ 1];\n            } else {\n                now = nodes[now].nxt[d];\n      \
    \      }\n        }\n        return res;\n    }\n\n    int count_not_greater(T\
    \ x) const {\n        x ^= lazy;\n        int now = root, res = nodes[root].count;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x\
    \ >> i) & 1;\n            if (d == 0 and nodes[now].nxt[d ^ 1] != -1) res -= nodes[nodes[now].nxt[d\
    \ ^ 1]].count;\n            now = nodes[now].nxt[d];\n            if (now == -1)\
    \ break;\n        }\n        return res;\n    }\n\n    int count_not_less(T x)\
    \ const {\n        x ^= lazy;\n        int now = root, res = nodes[root].count;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x\
    \ >> i) & 1;\n            if (d == 1 and nodes[now].nxt[d ^ 1] != -1) res -= nodes[nodes[now].nxt[d\
    \ ^ 1]].count;\n            now = nodes[now].nxt[d];\n            if (now == -1)\
    \ break;\n        }\n        return res;\n    }\n\n    int count(T x) const {\n\
    \        x ^= lazy;\n        int now = root;\n        for (int i= MAX_LOG - 1;\
    \ i >= 0; --i) {\n            const int d = (x >> i) & 1;\n            if (nodes[now].nxt[d]\
    \ == -1) return 0;\n            now = nodes[now].nxt[d];\n        }\n        return\
    \ nodes[now].count;\n    }\n\n    std::optional<T> max_not_greater(T x) const\
    \ {\n        if (size() == 0) return std::nullopt;\n        x ^= lazy;\n     \
    \   int now = root;\n        T res = 0;\n        bool same = true;\n        int\
    \ st[MAX_LOG];\n        int i = MAX_LOG - 1;\n        for (;; --i) {\n       \
    \     const int d = (x >> i) & 1;\n            st[i] = now;\n            if (same)\
    \ {\n                if (d == 0 and nodes[now].nxt[d] != -1) now = nodes[now].nxt[d];\n\
    \                else if (d == 0 and nodes[now].nxt[d] == -1) break;\n       \
    \         else if (d == 1 and nodes[now].nxt[d] != -1) {\n                   \
    \ res |= (T(1) << i);\n                    now = nodes[now].nxt[d];\n        \
    \        } else {\n                    assert(nodes[now].nxt[d ^ 1] != -1);\n\
    \                    now = nodes[now].nxt[d ^ 1];\n                    same =\
    \ false;\n                }\n            } else {\n                if (nodes[now].nxt[1]\
    \ != -1) {\n                    res |= (T(1) << i);\n                    now =\
    \ nodes[now].nxt[1];\n                } else {\n                    now = nodes[now].nxt[0];\n\
    \                }\n            }\n            if (i == 0) return res;\n     \
    \   }\n\n        ++i;\n        for (;; ++i) {\n            if (i == MAX_LOG) return\
    \ std::nullopt;\n            const int d = (x >> i) & 1;\n            res &= ~(T(1)\
    \ << i);\n            now = st[i];\n            if (d == 1 and nodes[now].nxt[d\
    \ ^ 1] != -1) {\n                now = nodes[now].nxt[d ^ 1];\n              \
    \  break;\n            }\n        }\n\n        --i;\n        for (; i >= 0; --i)\
    \ {\n            if (nodes[now].nxt[1] != -1) {\n                res |= (T(1)\
    \ << i);\n                now = nodes[now].nxt[1];\n            } else {\n   \
    \             now = nodes[now].nxt[0];\n            }\n        }\n        return\
    \ res;\n    }\n\n    std::optional<T> min_not_less(T x) const {\n        if (size()\
    \ == 0) return std::nullopt;\n        x ^= lazy;\n        int now = root;\n  \
    \      T res = 0;\n        bool same = true;\n        int st[MAX_LOG];\n     \
    \   int i = MAX_LOG - 1;\n        for (;; --i) {\n            const int d = (x\
    \ >> i) & 1;\n            st[i] = now;\n            if (same) {\n            \
    \    if (d == 1 and nodes[now].nxt[d] != -1) {\n                    res |= (T(1)\
    \ << i);\n                    now = nodes[now].nxt[d];\n                }\n  \
    \              else if (d == 1 and nodes[now].nxt[d] == -1) break;\n         \
    \       else if (d == 0 and nodes[now].nxt[d] != -1) now = nodes[now].nxt[d];\n\
    \                else {\n                    assert(nodes[now].nxt[d ^ 1] != -1);\n\
    \                    res |= (T(1) << i);\n                    now = nodes[now].nxt[d\
    \ ^ 1];\n                    same = false;\n                }\n            } else\
    \ {\n                if (nodes[now].nxt[0] != -1) {\n                    now =\
    \ nodes[now].nxt[0];\n                } else {\n                    res |= (T(1)\
    \ << i);\n                    now = nodes[now].nxt[1];\n                }\n  \
    \          }\n            if (i == 0) return res;\n        }\n\n        ++i;\n\
    \        for (;; ++i) {\n            if (i == MAX_LOG) return std::nullopt;\n\
    \            const int d = (x >> i) & 1;\n            res &= ~(T(1) << i);\n \
    \           now = st[i];\n            if (d == 0 and nodes[now].nxt[d ^ 1] !=\
    \ -1) {\n                res |= (T(1) << i);\n                now = nodes[now].nxt[d\
    \ ^ 1];\n                break;\n            }\n        }\n\n        --i;\n  \
    \      for (; i >= 0; --i) {\n            if (nodes[now].nxt[0] != -1) {\n   \
    \             now = nodes[now].nxt[0];\n            } else {\n               \
    \ res |= (T(1) << i);\n                now = nodes[now].nxt[1];\n            }\n\
    \        }\n        return res;\n    }\n\n    int size() const { return nodes[root].count;\
    \ }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef DATA_STRUCTURE_BINARY_TRIE_HPP\n#define DATA_STRUCTURE_BINARY_TRIE_HPP\
    \ 1\n\n#include <cassert>\n#include <optional>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\ntemplate <typename T> struct BinaryTrieNode {\n    int nxt[2];\n  \
    \  // \u30CE\u30FC\u30C9\u306B\u5BFE\u5FDC\u3059\u308Bprefix\u3092\u3082\u3064\
    \u8981\u7D20\u306E\u6570\n    // \u81EA\u5206\u81EA\u8EAB\u3082\u542B\u3080\n\
    \    int count;\n\n    BinaryTrieNode() : count(0) { nxt[0] = nxt[1] = -1; }\n\
    \n    template <typename U> friend U &operator<<(U &os, const BinaryTrieNode &node)\
    \ {\n        os << \"count: \" << node.count << \" \";\n        os << \"nxt: \"\
    ;\n        for (int i = 0; i < 2; ++i) os << node.nxt[i] << \" \";\n        return\
    \ os;\n    }\n};\n\ntemplate <typename T, int MAX_LOG> struct BinaryTrie {\n \
    \   using Node = BinaryTrieNode<T>;\n\n    T lazy;\n    std::vector<Node> nodes;\n\
    \    constexpr static int root = 0;\n\n    BinaryTrie() : lazy(T()) { nodes.emplace_back();\
    \ }\n\n    BinaryTrie(int Num) : lazy(T()) {\n        nodes.reserve(Num);\n  \
    \      nodes.emplace_back();\n    }\n\n    int push_node() {\n        nodes.emplace_back();\n\
    \        return nodes.size() - 1;\n    }\n\n    template <bool isadd> void update_direct(int\
    \ node) {\n        if constexpr (isadd) ++nodes[node].count;\n        else --nodes[node].count;\n\
    \    }\n\n    template <bool isadd> void update_child(int node) {\n        if\
    \ constexpr (isadd) ++nodes[node].count;\n        else --nodes[node].count;\n\
    \    }\n\n    void insert(T x) {\n        x ^= lazy;\n        int now = root;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x\
    \ >> i) & 1;\n            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();\n\
    \            update_child<true>(now);\n            now = nodes[now].nxt[d];\n\
    \        }\n        update_direct<true>(now);\n    }\n\n    void erase(T x) {\n\
    \        x ^= lazy;\n        int now = root;\n        int st[MAX_LOG];\n     \
    \   for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x >>\
    \ i) & 1;\n            if (nodes[now].nxt[d] == -1) return;\n            st[i]\
    \ = now;\n            now = nodes[now].nxt[d];\n        }\n        update_direct<false>(now);\n\
    \        for (int i = 0; i < MAX_LOG; ++i) {\n            update_child<false>(st[i]);\n\
    \            if (!nodes[now].count) nodes[st[i]].nxt[(x >> i) & 1] = -1;\n   \
    \         now = st[i];\n        }\n    }\n\n    void operate_xor(T x) { lazy ^=\
    \ x; }\n\n    std::optional<T> get_kth(int k) const {\n        if (k >= nodes[root].count)\
    \ return std::nullopt;\n        int now = root, less = 0;\n        T res = 0;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (lazy\
    \ >> i) & 1;\n            if (nodes[now].nxt[d] == -1 or less + nodes[nodes[now].nxt[d]].count\
    \ <= k) {\n                if (nodes[now].nxt[d] != -1) less += nodes[nodes[now].nxt[d]].count;\n\
    \                res |= (T(1) << i);\n                now = nodes[now].nxt[d ^\
    \ 1];\n            } else {\n                now = nodes[now].nxt[d];\n      \
    \      }\n        }\n        return res;\n    }\n\n    int count_not_greater(T\
    \ x) const {\n        x ^= lazy;\n        int now = root, res = nodes[root].count;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x\
    \ >> i) & 1;\n            if (d == 0 and nodes[now].nxt[d ^ 1] != -1) res -= nodes[nodes[now].nxt[d\
    \ ^ 1]].count;\n            now = nodes[now].nxt[d];\n            if (now == -1)\
    \ break;\n        }\n        return res;\n    }\n\n    int count_not_less(T x)\
    \ const {\n        x ^= lazy;\n        int now = root, res = nodes[root].count;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x\
    \ >> i) & 1;\n            if (d == 1 and nodes[now].nxt[d ^ 1] != -1) res -= nodes[nodes[now].nxt[d\
    \ ^ 1]].count;\n            now = nodes[now].nxt[d];\n            if (now == -1)\
    \ break;\n        }\n        return res;\n    }\n\n    int count(T x) const {\n\
    \        x ^= lazy;\n        int now = root;\n        for (int i= MAX_LOG - 1;\
    \ i >= 0; --i) {\n            const int d = (x >> i) & 1;\n            if (nodes[now].nxt[d]\
    \ == -1) return 0;\n            now = nodes[now].nxt[d];\n        }\n        return\
    \ nodes[now].count;\n    }\n\n    std::optional<T> max_not_greater(T x) const\
    \ {\n        if (size() == 0) return std::nullopt;\n        x ^= lazy;\n     \
    \   int now = root;\n        T res = 0;\n        bool same = true;\n        int\
    \ st[MAX_LOG];\n        int i = MAX_LOG - 1;\n        for (;; --i) {\n       \
    \     const int d = (x >> i) & 1;\n            st[i] = now;\n            if (same)\
    \ {\n                if (d == 0 and nodes[now].nxt[d] != -1) now = nodes[now].nxt[d];\n\
    \                else if (d == 0 and nodes[now].nxt[d] == -1) break;\n       \
    \         else if (d == 1 and nodes[now].nxt[d] != -1) {\n                   \
    \ res |= (T(1) << i);\n                    now = nodes[now].nxt[d];\n        \
    \        } else {\n                    assert(nodes[now].nxt[d ^ 1] != -1);\n\
    \                    now = nodes[now].nxt[d ^ 1];\n                    same =\
    \ false;\n                }\n            } else {\n                if (nodes[now].nxt[1]\
    \ != -1) {\n                    res |= (T(1) << i);\n                    now =\
    \ nodes[now].nxt[1];\n                } else {\n                    now = nodes[now].nxt[0];\n\
    \                }\n            }\n            if (i == 0) return res;\n     \
    \   }\n\n        ++i;\n        for (;; ++i) {\n            if (i == MAX_LOG) return\
    \ std::nullopt;\n            const int d = (x >> i) & 1;\n            res &= ~(T(1)\
    \ << i);\n            now = st[i];\n            if (d == 1 and nodes[now].nxt[d\
    \ ^ 1] != -1) {\n                now = nodes[now].nxt[d ^ 1];\n              \
    \  break;\n            }\n        }\n\n        --i;\n        for (; i >= 0; --i)\
    \ {\n            if (nodes[now].nxt[1] != -1) {\n                res |= (T(1)\
    \ << i);\n                now = nodes[now].nxt[1];\n            } else {\n   \
    \             now = nodes[now].nxt[0];\n            }\n        }\n        return\
    \ res;\n    }\n\n    std::optional<T> min_not_less(T x) const {\n        if (size()\
    \ == 0) return std::nullopt;\n        x ^= lazy;\n        int now = root;\n  \
    \      T res = 0;\n        bool same = true;\n        int st[MAX_LOG];\n     \
    \   int i = MAX_LOG - 1;\n        for (;; --i) {\n            const int d = (x\
    \ >> i) & 1;\n            st[i] = now;\n            if (same) {\n            \
    \    if (d == 1 and nodes[now].nxt[d] != -1) {\n                    res |= (T(1)\
    \ << i);\n                    now = nodes[now].nxt[d];\n                }\n  \
    \              else if (d == 1 and nodes[now].nxt[d] == -1) break;\n         \
    \       else if (d == 0 and nodes[now].nxt[d] != -1) now = nodes[now].nxt[d];\n\
    \                else {\n                    assert(nodes[now].nxt[d ^ 1] != -1);\n\
    \                    res |= (T(1) << i);\n                    now = nodes[now].nxt[d\
    \ ^ 1];\n                    same = false;\n                }\n            } else\
    \ {\n                if (nodes[now].nxt[0] != -1) {\n                    now =\
    \ nodes[now].nxt[0];\n                } else {\n                    res |= (T(1)\
    \ << i);\n                    now = nodes[now].nxt[1];\n                }\n  \
    \          }\n            if (i == 0) return res;\n        }\n\n        ++i;\n\
    \        for (;; ++i) {\n            if (i == MAX_LOG) return std::nullopt;\n\
    \            const int d = (x >> i) & 1;\n            res &= ~(T(1) << i);\n \
    \           now = st[i];\n            if (d == 0 and nodes[now].nxt[d ^ 1] !=\
    \ -1) {\n                res |= (T(1) << i);\n                now = nodes[now].nxt[d\
    \ ^ 1];\n                break;\n            }\n        }\n\n        --i;\n  \
    \      for (; i >= 0; --i) {\n            if (nodes[now].nxt[0] != -1) {\n   \
    \             now = nodes[now].nxt[0];\n            } else {\n               \
    \ res |= (T(1) << i);\n                now = nodes[now].nxt[1];\n            }\n\
    \        }\n        return res;\n    }\n\n    int size() const { return nodes[root].count;\
    \ }\n};\n\n} // namespace kk2\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2024-12-16 22:37:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
  - verify/yosupo_ds/ds_set_xor_min.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.hpp
- /library/data_structure/binary_trie.hpp.html
title: data_structure/binary_trie.hpp
---
