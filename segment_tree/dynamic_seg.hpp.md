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
  bundledCode: "#line 1 \"segment_tree/dynamic_seg.hpp\"\n\n\n\nnamespace kk2 {\n\n\
    template <class S, S (*op)(S, S), S (*e)(),\n          class F, S (*mapping)(F,\
    \ S),\n          F (*composition)(F, F), F (*id)()>\nstruct DynamicLazySegTree\
    \ {\n    using i64 = long long;\n    struct Node {\n        i64 idx;\n       \
    \ Node *l, *r;\n        S sum;\n        F laz;\n        Node(i64 idx = -1) : l(nullptr),\
    \ r(nullptr), sum(e()), laz(id()), idx(idx) {}\n    };\n\n    Node* root;\n  \
    \  i64 Rmx;\n    DynamicLazySegTree(i64 n_ = 0) {\n        Rmx = 2;\n        while\
    \ (Rmx < n_) Rmx <<= 1;\n        root = new_node(1);\n    }\n\n    S get(i64 p)\
    \ {\n        i64 l = 0, r = Rmx;\n        Node* now = root;\n        while (r\
    \ - l > 1) {\n            push(now);\n            i64 m = (l + r) >> 1;\n    \
    \        if (p < m) {\n                if (!now->l) return e();\n            \
    \    now = now->l;\n                r = m;\n            }\n            else {\n\
    \                if (!now->r) return e();\n                now = now->r;\n   \
    \             l = m;\n            }\n        }\n        return now->sum;\n   \
    \ }\n\n    void set(i64 i, const T& x) {\n        _set(root, 0, Rmx, i, x);\n\
    \    }\n    void apply(i64 l, i64 r, const F& f) {\n        _apply(root, 0, Rmx,\
    \ l, r, f);\n    }\n    S prod(i64 l, i64 r) {\n        return _prod(root, 0,\
    \ Rmx, l, r);\n    }\n    void merge(DynamicLazySegTree& dst) {\n        root\
    \ = _merge(root, dst.root);\n    }\n\n    template <bool (*g)(S)> i64 max_right(i64\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> i64 max_right(i64 l, const G& g) {\n        assert(0 <= l && l <=\
    \ Rmx);\n        assert(g(e()));\n        return _max_right(root, l, g);\n   \
    \ }\n\n    template <bool (*g)(S)> i64 min_left(i64 r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> i64 min_left(i64 r,\
    \ const G& g) {\n        assert(0 <= r && r <= Rmx);\n        assert(g(e()));\n\
    \        return _min_left(root, r, g);\n    }\n\n  private:\n    DynamicLazySegTree(Node*\
    \ root, i64 Rmx) : root(root), Rmx(Rmx) {}\n    Node* new_node(int idx) { return\
    \ new Node(idx); }\n    void del_node(Node* node) { delete node; }\n\n    void\
    \ action(Node* now, const F& f) {\n        assert(now && f != id());\n       \
    \ now->sum = mapping(f, now->sum);\n        now->laz = composition(f, now->laz);\n\
    \    }\n    void push(Node* now) {\n        assert(now);\n        if (now->lazy\
    \ == id()) return;\n        if (!now->l) now->l = new_node(now.idx << 1 | 0);\n\
    \        if (!now->r) now->r = new_node(now.idx << 1 | 1);\n        action(now->l,\
    \ now->lazy);\n        action(now->r, now->lazy);\n        now->lazy = id();\n\
    \    }\n    void update(Node* now) {\n        assert(now->laz == id());\n    \
    \    now->sum = op(now->l ? now->l->sum : e(),\n                      now->r ?\
    \ now->r->sum : e());\n    }\n\n    void _set(Node* now, i64 l, i64 r, i64 i,\
    \ const S& x) {\n        assert(l <= i && i < r && now);\n        if (l + 1  ==\
    \ r) {\n            now->sum = x;\n            return;\n        }\n        i64\
    \ m = (l + r) >> 1;\n        push(now);\n        if (i < m) {\n            if\
    \ (!now->l) now->l = new_node(now.idx << 1 | 0);\n            _set(now->l, l,\
    \ m, i, x);\n        }\n        else {\n            if (!now->r) now->r = new_node(now.idx\
    \ << 1 | 1);\n            _set(now->r, m, r, i, x);\n        }\n        update(now);\n\
    \    }\n\n    void apply(Node* now, i64 l, i64 r, i64 a, i64 b, const F& f) {\n\
    \        assert(a <= b && a < r && l < b && now);\n        if (l == a && r ==\
    \ b) {\n            action(now, f);\n            if (l + 1 == r) now->lazy = id();\n\
    \            return;\n        }\n        i64 m = (l + r) >> 1;\n        push(now);\n\
    \        if (a < m) {\n            if (!now->l) now->l = new_node(now.idx << 1\
    \ | 0);\n            _apply(now->l, l, m, a, min(m, b), f);\n        }\n     \
    \   if (m < b) {\n            if (!now->r) now->r = new_node(now.idx << 1 | 1);\n\
    \            _apply(now->r, m, r, max(a, m), b, f);\n        }\n        update(now);\n\
    \    }\n\n    S prod(Node* now, i64 l, i64 r, i64 a, i64 b) {\n        assert(a\
    \ <= b && a < r && l < b && now);\n        if (l == a && r == b) return now->sum;\n\
    \        i64 m = (l + r) >> 1;\n        push(now);\n        S res = e();\n   \
    \     if (a < m && now->l) res = op(_prod(now->l, l, m, a, min(m, b)), res);\n\
    \        if (m < b && now->r) res = op(res, _prod(now->r, m, r, max(a, m), b));\n\
    \        return res;\n    }\n\n    Node* _merge(Node* a, Node* b) {\n        if\
    \ (!a) return b;\n        if (!b) return a;\n        assert(a->laz == id() &&\
    \ b->laz == id());\n        a->l = merge(a->l, b->l);\n        a->r = merge(a->r,\
    \ b->r);\n        update(a);\n        del_node(b);\n        return a;\n    }\n\
    \n    template <class G>\n    i64 _max_right(Node* now, i64 l, const G& g) {\n\
    \        \n    }\n};\n\nnamespace DynamicSegImpl {\n\ntemplate <class S>\nS mapping(S\
    \ l, bool) { return l; }\nbool composition(bool, bool) { return false; }\nbool\
    \ id() { return false; }\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nusing\
    \ DynamicSegTree =\n    DynamicLazySegTree<S, op, e, bool, mapping, composition,\
    \ id>;\n\n} // namespace DynamicSegImpl\nusing DynamicSegImpl::DynamicSegTree;\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_SEGMENT_TREE_DYNAMIC_SEG_HPP\n#define KK2_SEGMENT_TREE_DYNAMIC_SEG_HPP\
    \ 1\n\nnamespace kk2 {\n\ntemplate <class S, S (*op)(S, S), S (*e)(),\n      \
    \    class F, S (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\n\
    struct DynamicLazySegTree {\n    using i64 = long long;\n    struct Node {\n \
    \       i64 idx;\n        Node *l, *r;\n        S sum;\n        F laz;\n     \
    \   Node(i64 idx = -1) : l(nullptr), r(nullptr), sum(e()), laz(id()), idx(idx)\
    \ {}\n    };\n\n    Node* root;\n    i64 Rmx;\n    DynamicLazySegTree(i64 n_ =\
    \ 0) {\n        Rmx = 2;\n        while (Rmx < n_) Rmx <<= 1;\n        root =\
    \ new_node(1);\n    }\n\n    S get(i64 p) {\n        i64 l = 0, r = Rmx;\n   \
    \     Node* now = root;\n        while (r - l > 1) {\n            push(now);\n\
    \            i64 m = (l + r) >> 1;\n            if (p < m) {\n               \
    \ if (!now->l) return e();\n                now = now->l;\n                r =\
    \ m;\n            }\n            else {\n                if (!now->r) return e();\n\
    \                now = now->r;\n                l = m;\n            }\n      \
    \  }\n        return now->sum;\n    }\n\n    void set(i64 i, const T& x) {\n \
    \       _set(root, 0, Rmx, i, x);\n    }\n    void apply(i64 l, i64 r, const F&\
    \ f) {\n        _apply(root, 0, Rmx, l, r, f);\n    }\n    S prod(i64 l, i64 r)\
    \ {\n        return _prod(root, 0, Rmx, l, r);\n    }\n    void merge(DynamicLazySegTree&\
    \ dst) {\n        root = _merge(root, dst.root);\n    }\n\n    template <bool\
    \ (*g)(S)> i64 max_right(i64 l) {\n        return max_right(l, [](S x) { return\
    \ g(x); });\n    }\n    template <class G> i64 max_right(i64 l, const G& g) {\n\
    \        assert(0 <= l && l <= Rmx);\n        assert(g(e()));\n        return\
    \ _max_right(root, l, g);\n    }\n\n    template <bool (*g)(S)> i64 min_left(i64\
    \ r) {\n        return min_left(r, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> i64 min_left(i64 r, const G& g) {\n        assert(0 <= r && r <= Rmx);\n\
    \        assert(g(e()));\n        return _min_left(root, r, g);\n    }\n\n  private:\n\
    \    DynamicLazySegTree(Node* root, i64 Rmx) : root(root), Rmx(Rmx) {}\n    Node*\
    \ new_node(int idx) { return new Node(idx); }\n    void del_node(Node* node) {\
    \ delete node; }\n\n    void action(Node* now, const F& f) {\n        assert(now\
    \ && f != id());\n        now->sum = mapping(f, now->sum);\n        now->laz =\
    \ composition(f, now->laz);\n    }\n    void push(Node* now) {\n        assert(now);\n\
    \        if (now->lazy == id()) return;\n        if (!now->l) now->l = new_node(now.idx\
    \ << 1 | 0);\n        if (!now->r) now->r = new_node(now.idx << 1 | 1);\n    \
    \    action(now->l, now->lazy);\n        action(now->r, now->lazy);\n        now->lazy\
    \ = id();\n    }\n    void update(Node* now) {\n        assert(now->laz == id());\n\
    \        now->sum = op(now->l ? now->l->sum : e(),\n                      now->r\
    \ ? now->r->sum : e());\n    }\n\n    void _set(Node* now, i64 l, i64 r, i64 i,\
    \ const S& x) {\n        assert(l <= i && i < r && now);\n        if (l + 1  ==\
    \ r) {\n            now->sum = x;\n            return;\n        }\n        i64\
    \ m = (l + r) >> 1;\n        push(now);\n        if (i < m) {\n            if\
    \ (!now->l) now->l = new_node(now.idx << 1 | 0);\n            _set(now->l, l,\
    \ m, i, x);\n        }\n        else {\n            if (!now->r) now->r = new_node(now.idx\
    \ << 1 | 1);\n            _set(now->r, m, r, i, x);\n        }\n        update(now);\n\
    \    }\n\n    void apply(Node* now, i64 l, i64 r, i64 a, i64 b, const F& f) {\n\
    \        assert(a <= b && a < r && l < b && now);\n        if (l == a && r ==\
    \ b) {\n            action(now, f);\n            if (l + 1 == r) now->lazy = id();\n\
    \            return;\n        }\n        i64 m = (l + r) >> 1;\n        push(now);\n\
    \        if (a < m) {\n            if (!now->l) now->l = new_node(now.idx << 1\
    \ | 0);\n            _apply(now->l, l, m, a, min(m, b), f);\n        }\n     \
    \   if (m < b) {\n            if (!now->r) now->r = new_node(now.idx << 1 | 1);\n\
    \            _apply(now->r, m, r, max(a, m), b, f);\n        }\n        update(now);\n\
    \    }\n\n    S prod(Node* now, i64 l, i64 r, i64 a, i64 b) {\n        assert(a\
    \ <= b && a < r && l < b && now);\n        if (l == a && r == b) return now->sum;\n\
    \        i64 m = (l + r) >> 1;\n        push(now);\n        S res = e();\n   \
    \     if (a < m && now->l) res = op(_prod(now->l, l, m, a, min(m, b)), res);\n\
    \        if (m < b && now->r) res = op(res, _prod(now->r, m, r, max(a, m), b));\n\
    \        return res;\n    }\n\n    Node* _merge(Node* a, Node* b) {\n        if\
    \ (!a) return b;\n        if (!b) return a;\n        assert(a->laz == id() &&\
    \ b->laz == id());\n        a->l = merge(a->l, b->l);\n        a->r = merge(a->r,\
    \ b->r);\n        update(a);\n        del_node(b);\n        return a;\n    }\n\
    \n    template <class G>\n    i64 _max_right(Node* now, i64 l, const G& g) {\n\
    \        \n    }\n};\n\nnamespace DynamicSegImpl {\n\ntemplate <class S>\nS mapping(S\
    \ l, bool) { return l; }\nbool composition(bool, bool) { return false; }\nbool\
    \ id() { return false; }\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nusing\
    \ DynamicSegTree =\n    DynamicLazySegTree<S, op, e, bool, mapping, composition,\
    \ id>;\n\n} // namespace DynamicSegImpl\nusing DynamicSegImpl::DynamicSegTree;\n\
    \n} // namespace kk2\n\n#endif // KK2_SEGMENT_TREE_DYNAMIC_SEG_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/dynamic_seg.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/dynamic_seg.hpp
layout: document
redirect_from:
- /library/segment_tree/dynamic_seg.hpp
- /library/segment_tree/dynamic_seg.hpp.html
title: segment_tree/dynamic_seg.hpp
---
