---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: bbst/base/red_black_tree_base.hpp
    title: bbst/base/red_black_tree_base.hpp
  - icon: ':x:'
    path: others/vector_pool.hpp
    title: others/vector_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/ordered_set.hpp\"\n\n\n\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\n#line 1 \"bbst/base/red_black_tree_base.hpp\"\
    \n\n\n\n#include <cassert>\n#include <memory>\n#include <string>\n#line 9 \"bbst/base/red_black_tree_base.hpp\"\
    \n\n#line 1 \"others/vector_pool.hpp\"\n\n\n\n#line 5 \"others/vector_pool.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T>\nstruct VectorPool {\n    std::vector<T>\
    \ pool;\n    std::vector<T *> ptrs;\n    int pos = 0;\n\n    VectorPool() = default;\n\
    \n    VectorPool(int n) : pool(n), ptrs(n) {}\n\n    inline T *alloc() { return\
    \ ptrs[pos++]; }\n\n    inline void free(T *ptr) { ptrs[--pos] = ptr; }\n\n  \
    \  void clear() {\n        for (size_t i = 0; i < pool.size(); i++) ptrs[i] =\
    \ &pool[i]; \n        pos = 0;\n    }\n\n    T &operator[](int i) { return pool[i];\
    \ }\n};\n\n} // namespace kk2\n\n\n#line 11 \"bbst/base/red_black_tree_base.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace rbtree {\n\n// base\u306B\u5FC5\u8981\u306A\u30E1\
    \u30F3\u30D0\n// NodePtr left, right;\n// int rank, count;\n// bool is_red;\n\
    // Monoid val;\n\ntemplate <typename Node>\nstruct RedBlackTreeBase {\n    VectorPool<Node>\
    \ pool;\n    using NodePtr = Node *;\n    using Monoid = typename Node::Monoid;\n\
    \n    static auto MonoidOp(Monoid a, Monoid b) { return Node::MonoidOp(a, b);\
    \ }\n\n    static auto MonoidUnit() { return Node::MonoidUnit(); }\n\n    using\
    \ Action = typename Node::Action;\n\n    static auto Map(Action a, Monoid x) {\
    \ return Node::Map(a, x); }\n\n    static auto ActionOp(Action a, Action b) {\
    \ return Node::ActionOp(a, b); }\n\n    static auto ActionUnit() { return Node::ActionUnit();\
    \ }\n\n    RedBlackTreeBase(int sz) : pool(sz) { pool.clear(); }\n\n    template\
    \ <typename... Args>\n    NodePtr alloc(Args... args) {\n        NodePtr t = &(*pool.alloc()\
    \ = Node(args...));\n        return update(t);\n    }\n\n    NodePtr make_tree()\
    \ { return nullptr; }\n\n    void free(NodePtr t) { pool.free(t); }\n\n    void\
    \ clear(NodePtr t) {\n        if (!t) return;\n        clear(t->left);\n     \
    \   clear(t->right);\n        free(t);\n    }\n\n    NodePtr build(const std::vector<Monoid>\
    \ &v) {\n        auto dfs = [&](auto self, int l, int r) -> NodePtr {\n      \
    \      if (l == r) return nullptr;\n            if (l + 1 == r) return alloc(v[l]);\n\
    \            int m = (l + r) / 2;\n            return merge(self(self, l, m),\
    \ self(self, m, r));\n        };\n        return dfs(dfs, 0, (int)v.size());\n\
    \    }\n\n    NodePtr merge(NodePtr l, NodePtr r) {\n        if (!l or !r) return\
    \ l ? l : r;\n        NodePtr c = submerge(l, r);\n        c->is_red = false;\n\
    \        return c;\n    }\n\n    std::pair<NodePtr, NodePtr> split(NodePtr t,\
    \ int k) {\n        assert(0 <= k and k <= size(t));\n        if (!t) return {nullptr,\
    \ nullptr};\n        if (k == 0) return {nullptr, as_root(t)};\n        if (k\
    \ == size(t)) return {as_root(t), nullptr};\n        t = push(t);\n        NodePtr\
    \ l = as_root(t->left), r = as_root(t->right);\n        free(t);\n        if (k\
    \ < size(l)) {\n            auto [ll, rr] = split(l, k);\n            return {ll,\
    \ merge(rr, r)};\n        }\n        if (k > size(l)) {\n            auto [ll,\
    \ rr] = split(r, k - size(l));\n            return {merge(l, ll), rr};\n     \
    \   }\n        return {l, r};\n    }\n\n    struct NodePtr3 {\n        NodePtr\
    \ x, y, z;\n    };\n\n    NodePtr3 split3(NodePtr t, int a, int b) {\n       \
    \ // assert\u3057\u306A\u304F\u3066\u3082\u52D5\u304F\u3051\u3069\uFF0C\u5206\u304B\
    \u308A\u306B\u304F\u3044\n        assert(0 <= a and a <= b and b <= size(t));\n\
    \        auto [x, y] = split(t, a);\n        auto [y1, z] = split(y, b - a);\n\
    \        return {x, y1, z};\n    }\n\n    template <typename... Args>\n    void\
    \ insert(NodePtr &t, int k, Args... args) {\n        assert(0 <= k and k <= size(t));\n\
    \        auto [l, r] = split(t, k);\n        t = merge(merge(l, alloc(Monoid(args...))),\
    \ r);\n    }\n\n    void erase(NodePtr &t, int k) {\n        assert(0 <= k and\
    \ k < size(t));\n        auto [l, r] = split(t, k);\n        auto [ll, rr] = split(r,\
    \ 1);\n        free(ll);\n        t = merge(l, rr);\n    }\n\n    template <typename...\
    \ Args>\n    void set(NodePtr t, int k, Args... args) {\n        assert(0 <= k\
    \ and k < size(t));\n        NodePtr now = t;\n        auto dfs = [&](auto self,\
    \ NodePtr now, int k) -> void {\n            if (!now->left) {\n             \
    \   now->val = Monoid(args...);\n                return;\n            }\n    \
    \        now = push(now);\n            if (size(now->left) > k) self(self, now->left,\
    \ k);\n            else self(self, now->right, k - size(now->left));\n       \
    \     now = update(now);\n        };\n        dfs(dfs, now, k);\n    }\n\n   \
    \ Monoid get(NodePtr t, int k) {\n        assert(0 <= k and k < size(t));\n  \
    \      NodePtr now = t;\n        while (now->left) {\n            now = push(now);\n\
    \            if (size(now->left) > k) now = now->left;\n            else {\n \
    \               k -= size(now->left);\n                now = now->right;\n   \
    \         }\n        }\n        return now->val;\n    }\n\n    Monoid prod(NodePtr\
    \ &t, int l, int r) {\n        assert(0 <= l and l <= r and r <= size(t));\n \
    \       auto [t1, t2, t3] = split3(t, l, r);\n        Monoid res = (t2 ? t2->val\
    \ : MonoidUnit());\n        t = merge(merge(t1, t2), t3);\n        return res;\n\
    \    }\n\n    void reverse(NodePtr &t, int l, int r) {\n        assert(0 <= l\
    \ and l <= r and r <= size(t));\n        auto [t1, t2, t3] = split3(t, l, r);\n\
    \        if (t2) t2->is_rev ^= 1;\n        t = merge(merge(t1, t2), t3);\n   \
    \ }\n\n    template <typename... Args>\n    void push_front(NodePtr &t, Args...\
    \ args) {\n        t = merge(alloc(Monoid(args...)), t);\n    }\n\n    template\
    \ <typename... Args>\n    void push_back(NodePtr &t, Args... args) {\n       \
    \ t = merge(t, alloc(Monoid(args...)));\n    }\n\n    void pop_front(NodePtr &t)\
    \ {\n        auto [l, r] = split(t, 1);\n        t = r;\n    }\n\n    void pop_back(NodePtr\
    \ &t) {\n        auto [l, r] = split(t, size(t) - 1);\n        t = l;\n    }\n\
    \n    struct bb_result {\n        int s;\n        Monoid prod;\n        NodePtr\
    \ t;\n    };\n\n    template <class G>\n    bb_result max_right(NodePtr &t, int\
    \ l, const G &g) {\n        assert(0 <= l and l <= size(t));\n        assert(g(MonoidUnit()));\n\
    \        auto [t1, t2] = split(t, l);\n        if (!t2) {\n            t = merge(t1,\
    \ t2);\n            return {l, MonoidUnit(), nullptr};\n        }\n        if\
    \ (g(t2->val)) {\n            t = merge(t1, t2);\n            return {l + size(t2),\
    \ t2->val, nullptr};\n        }\n\n        int k = l;\n        Monoid x = MonoidUnit();\n\
    \        NodePtr now = t2;\n\n        while (now->left) {\n            now = push(now);\n\
    \            Monoid y = MonoidOp(x, now->left->val);\n            if (g(y)) {\n\
    \                x = y;\n                k += size(now->left);\n             \
    \   now = now->right;\n            } else {\n                now = now->left;\n\
    \            }\n        }\n        t = merge(t1, t2);\n        return {k, x, now};\n\
    \    }\n\n    template <class G>\n    bb_result min_left(NodePtr &t, int r, const\
    \ G &g) {\n        assert(0 <= r and r <= size(t));\n        assert(g(MonoidUnit()));\n\
    \        auto [t1, t2] = split(t, r);\n        if (!t1) {\n            t = merge(t1,\
    \ t2);\n            return {r, MonoidUnit(), nullptr};\n        }\n        if\
    \ (g(t1->val)) {\n            t = merge(t1, t2);\n            return {0, t1->val,\
    \ nullptr};\n        }\n\n        int k = r;\n        Monoid x = MonoidUnit();\n\
    \        NodePtr now = t1;\n\n        while (now->right) {\n            now =\
    \ push(now);\n            Monoid y = MonoidOp(now->right->val, x);\n         \
    \   if (g(y)) {\n                x = y;\n                k -= size(now->right);\n\
    \                now = now->left;\n            } else {\n                now =\
    \ now->right;\n            }\n        }\n        t = merge(t1, t2);\n        return\
    \ {k, x, now};\n    }\n\n    inline int size(NodePtr t) const { return t ? t->count\
    \ : 0; }\n\n  protected:\n    NodePtr rotate(NodePtr t, bool left) {\n       \
    \ t = push(t);\n        NodePtr s;\n        if (left) {\n            s = push(t->left);\n\
    \            t->left = s->right;\n            s->right = t;\n        } else {\n\
    \            s = push(t->right);\n            t->right = s->left;\n          \
    \  s->left = t;\n        }\n        update(t);\n        return update(s);\n  \
    \  }\n\n    NodePtr submerge(NodePtr l, NodePtr r) {\n        if (l->rank < r->rank)\
    \ {\n            r = push(r);\n            NodePtr c = submerge(l, r->left);\n\
    \            r->left = c;\n            if (c->is_red and c->left->is_red) {\n\
    \                c->is_red = 0, r->is_red = 1;\n                if (!r->right->is_red)\
    \ return rotate(r, true);\n                r->right->is_red = 0;\n           \
    \ }\n            return update(r);\n        } else if (l->rank > r->rank) {\n\
    \            l = push(l);\n            NodePtr c = submerge(l->right, r);\n  \
    \          l->right = c;\n            if (c->is_red and c->right->is_red) {\n\
    \                c->is_red = 0, l->is_red = 1;\n                if (!l->left->is_red)\
    \ return rotate(l, false);\n                l->left->is_red = 0;\n           \
    \ }\n            return update(l);\n        } else {\n            return alloc(l,\
    \ r);\n        }\n    }\n\n    NodePtr as_root(NodePtr t) {\n        if (!t) return\
    \ t;\n        t->is_red = false;\n        return t;\n    }\n\n    virtual NodePtr\
    \ update(NodePtr t) = 0;\n\n    virtual NodePtr push(NodePtr t) = 0;\n};\n\n}\
    \ // namespace rbtree\n\n} // namespace kk2\n\n\n#line 9 \"data_structure/ordered_set.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace rbtree {\n\ntemplate <typename T, typename Compare>\n\
    struct SetNode {\n    using NodePtr = typename rbtree::RedBlackTreeBase<SetNode>::NodePtr;\n\
    \    NodePtr left, right;\n    int rank, count;\n    bool is_red;\n\n    struct\
    \ Monoid {\n        T mx;\n        bool unit;\n\n        Monoid() : mx(T{}), unit(true)\
    \ {}\n\n        Monoid(T x) : mx(x), unit(false) {}\n    };\n\n    Monoid val;\n\
    \n    SetNode(Monoid val_ = Monoid())\n        : left(nullptr),\n          right(nullptr),\n\
    \          rank(0),\n          count(1),\n          is_red(false),\n         \
    \ val(val_) {}\n\n    SetNode(NodePtr l, NodePtr r) : left(l), right(r), is_red(true)\
    \ {}\n\n    static Monoid MonoidOp(Monoid a, Monoid b) {\n        if (a.unit or\
    \ b.unit) return a.unit ? b : a;\n        return Compare{}(a.mx, b.mx) ? b : a;\n\
    \    }\n\n    static Monoid MonoidUnit() { return Monoid(); }\n\n    using Action\
    \ = int;\n\n    static Monoid Map(Action, Monoid x) { return x; }\n\n    static\
    \ Action ActionOp(Action, Action) { return 0; }\n\n    static Action ActionUnit()\
    \ { return 0; }\n};\n\ntemplate <typename T, typename Compare>\nstruct SetBase\
    \ : RedBlackTreeBase<SetNode<T, Compare>> {\n    using base = RedBlackTreeBase<SetNode<T,\
    \ Compare>>;\n    using base::MonoidOp;\n    using base::RedBlackTreeBase;\n \
    \   using base::size;\n    using typename base::NodePtr;\n\n  protected:\n   \
    \ NodePtr update(NodePtr t) override {\n        t->count = size(t->left) + size(t->right)\
    \ + (t->left == nullptr);\n        t->rank = t->left ? t->left->rank + !t->left->is_red\
    \ : 1;\n        t->val = (t->left ? MonoidOp(t->left->val, t->right->val) : t->val);\n\
    \        return t;\n    }\n\n    NodePtr push(NodePtr t) override { return t;\
    \ }\n};\n\ntemplate <typename T, typename Compare = std::less<T>>\nstruct Set\
    \ {\n    using NodePtr = typename SetBase<T, Compare>::NodePtr;\n    using Monoid\
    \ = typename SetNode<T, Compare>::Monoid;\n\n    static Monoid MonoidOp(Monoid\
    \ a, Monoid b) { return SetNode<T, Compare>::MonoidOp(a, b); }\n\n    SetBase<T,\
    \ Compare> base;\n    NodePtr root;\n\n    Set() = delete;\n\n    Set(int mx)\
    \ : base(2 * mx), root(base.make_tree()) {}\n\n    Set(int mx, const std::vector<T>\
    \ &v)\n        : base(2 * mx),\n          root(base.build(std::vector<Monoid>(v.begin(),\
    \ v.end()))) {}\n\n    // val\u30D9\u30FC\u30B9\u306Esplit\u3092\u5B9F\u88C5\u3057\
    \u3088\u3046\uFF01\n    void insert(T x) {\n        auto [k, a, b] = base.max_right(root,\
    \ 0, [&](auto t) { return t.unit or t.mx < x; });\n        if (b and b->val.mx\
    \ == x) return;\n        base.insert(root, k, Monoid(x));\n    }\n\n    void erase(T\
    \ x) {\n        auto [k, a, b] = base.max_right(root, 0, [&](auto t) { return\
    \ t.unit or t.mx < x; });\n        if (b and b->val.mx == x) base.erase(root,\
    \ k);\n    }\n\n    std::optional<T> get_kth(int k) {\n        return size() <=\
    \ k ? std::nullopt : std::optional<T>(base.get(root, k).mx);\n    }\n\n    int\
    \ count_not_greater(T x) {\n        return base.max_right(root, 0, [&](auto t)\
    \ { return t.unit or t.mx <= x; }).s;\n    }\n\n    std::optional<T> max_not_greater(T\
    \ x) {\n        auto [k, a, b] = base.max_right(root, 0, [&](auto t) { return\
    \ t.unit or t.mx <= x; });\n        return a.unit ? std::nullopt : std::optional<T>(a.mx);\n\
    \    }\n\n    // max\u3060\u3051\u3067\u3053\u308C\u306F\u634C\u3051\u308B\u306E\
    \u3067mx\u3060\u3051\u306B\u3057\u307E\u3057\u3087\u3046\n    std::optional<T>\
    \ min_not_less(T x) {\n        auto [k, a, b] = base.max_right(root, 0, [&](auto\
    \ t) { return t.unit or t.mx < x; });\n        return b ? std::optional<T>(b->val.mx)\
    \ : std::nullopt;\n    }\n\n    inline int size() const { return base.size(root);\
    \ }\n};\n\n} // namespace rbtree\n\nusing rbtree::Set;\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_ORDERED_SET_HPP\n#define KK2_DATA_STRUCTURE_ORDERED_SET_HPP\
    \ 1\n\n#include <optional>\n#include <utility>\n#include <vector>\n\n#include\
    \ \"../bbst/base/red_black_tree_base.hpp\"\n\nnamespace kk2 {\n\nnamespace rbtree\
    \ {\n\ntemplate <typename T, typename Compare>\nstruct SetNode {\n    using NodePtr\
    \ = typename rbtree::RedBlackTreeBase<SetNode>::NodePtr;\n    NodePtr left, right;\n\
    \    int rank, count;\n    bool is_red;\n\n    struct Monoid {\n        T mx;\n\
    \        bool unit;\n\n        Monoid() : mx(T{}), unit(true) {}\n\n        Monoid(T\
    \ x) : mx(x), unit(false) {}\n    };\n\n    Monoid val;\n\n    SetNode(Monoid\
    \ val_ = Monoid())\n        : left(nullptr),\n          right(nullptr),\n    \
    \      rank(0),\n          count(1),\n          is_red(false),\n          val(val_)\
    \ {}\n\n    SetNode(NodePtr l, NodePtr r) : left(l), right(r), is_red(true) {}\n\
    \n    static Monoid MonoidOp(Monoid a, Monoid b) {\n        if (a.unit or b.unit)\
    \ return a.unit ? b : a;\n        return Compare{}(a.mx, b.mx) ? b : a;\n    }\n\
    \n    static Monoid MonoidUnit() { return Monoid(); }\n\n    using Action = int;\n\
    \n    static Monoid Map(Action, Monoid x) { return x; }\n\n    static Action ActionOp(Action,\
    \ Action) { return 0; }\n\n    static Action ActionUnit() { return 0; }\n};\n\n\
    template <typename T, typename Compare>\nstruct SetBase : RedBlackTreeBase<SetNode<T,\
    \ Compare>> {\n    using base = RedBlackTreeBase<SetNode<T, Compare>>;\n    using\
    \ base::MonoidOp;\n    using base::RedBlackTreeBase;\n    using base::size;\n\
    \    using typename base::NodePtr;\n\n  protected:\n    NodePtr update(NodePtr\
    \ t) override {\n        t->count = size(t->left) + size(t->right) + (t->left\
    \ == nullptr);\n        t->rank = t->left ? t->left->rank + !t->left->is_red :\
    \ 1;\n        t->val = (t->left ? MonoidOp(t->left->val, t->right->val) : t->val);\n\
    \        return t;\n    }\n\n    NodePtr push(NodePtr t) override { return t;\
    \ }\n};\n\ntemplate <typename T, typename Compare = std::less<T>>\nstruct Set\
    \ {\n    using NodePtr = typename SetBase<T, Compare>::NodePtr;\n    using Monoid\
    \ = typename SetNode<T, Compare>::Monoid;\n\n    static Monoid MonoidOp(Monoid\
    \ a, Monoid b) { return SetNode<T, Compare>::MonoidOp(a, b); }\n\n    SetBase<T,\
    \ Compare> base;\n    NodePtr root;\n\n    Set() = delete;\n\n    Set(int mx)\
    \ : base(2 * mx), root(base.make_tree()) {}\n\n    Set(int mx, const std::vector<T>\
    \ &v)\n        : base(2 * mx),\n          root(base.build(std::vector<Monoid>(v.begin(),\
    \ v.end()))) {}\n\n    // val\u30D9\u30FC\u30B9\u306Esplit\u3092\u5B9F\u88C5\u3057\
    \u3088\u3046\uFF01\n    void insert(T x) {\n        auto [k, a, b] = base.max_right(root,\
    \ 0, [&](auto t) { return t.unit or t.mx < x; });\n        if (b and b->val.mx\
    \ == x) return;\n        base.insert(root, k, Monoid(x));\n    }\n\n    void erase(T\
    \ x) {\n        auto [k, a, b] = base.max_right(root, 0, [&](auto t) { return\
    \ t.unit or t.mx < x; });\n        if (b and b->val.mx == x) base.erase(root,\
    \ k);\n    }\n\n    std::optional<T> get_kth(int k) {\n        return size() <=\
    \ k ? std::nullopt : std::optional<T>(base.get(root, k).mx);\n    }\n\n    int\
    \ count_not_greater(T x) {\n        return base.max_right(root, 0, [&](auto t)\
    \ { return t.unit or t.mx <= x; }).s;\n    }\n\n    std::optional<T> max_not_greater(T\
    \ x) {\n        auto [k, a, b] = base.max_right(root, 0, [&](auto t) { return\
    \ t.unit or t.mx <= x; });\n        return a.unit ? std::nullopt : std::optional<T>(a.mx);\n\
    \    }\n\n    // max\u3060\u3051\u3067\u3053\u308C\u306F\u634C\u3051\u308B\u306E\
    \u3067mx\u3060\u3051\u306B\u3057\u307E\u3057\u3087\u3046\n    std::optional<T>\
    \ min_not_less(T x) {\n        auto [k, a, b] = base.max_right(root, 0, [&](auto\
    \ t) { return t.unit or t.mx < x; });\n        return b ? std::optional<T>(b->val.mx)\
    \ : std::nullopt;\n    }\n\n    inline int size() const { return base.size(root);\
    \ }\n};\n\n} // namespace rbtree\n\nusing rbtree::Set;\n\n} // namespace kk2\n\
    \n#endif // KK2_DATA_STRUCTURE_ORDERED_SET_HPP\n"
  dependsOn:
  - bbst/base/red_black_tree_base.hpp
  - others/vector_pool.hpp
  isVerificationFile: false
  path: data_structure/ordered_set.hpp
  requiredBy: []
  timestamp: '2025-03-27 00:23:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/ordered_set.hpp
layout: document
redirect_from:
- /library/data_structure/ordered_set.hpp
- /library/data_structure/ordered_set.hpp.html
title: data_structure/ordered_set.hpp
---
