#ifndef KK2_BBST_BASE_RED_BLACK_TREE_BASE_HPP
#define KK2_BBST_BASE_RED_BLACK_TREE_BASE_HPP 1

#include <cassert>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "../../others/vector_pool.hpp"

namespace kk2 {

namespace rbtree {

// baseに必要なメンバ
// NodePtr left, right;
// int rank, count;
// bool is_red;
// Monoid val;

template <typename Node> struct RedBlackTreeBase {
    VectorPool<Node> pool;
    using NodePtr = Node *;
    using Monoid = typename Node::Monoid;

    static auto MonoidOp(Monoid a, Monoid b) { return Node::MonoidOp(a, b); }

    static auto MonoidUnit() { return Node::MonoidUnit(); }

    using Action = typename Node::Action;

    static auto Map(Action a, Monoid x) { return Node::Map(a, x); }

    static auto ActionOp(Action a, Action b) { return Node::ActionOp(a, b); }

    static auto ActionUnit() { return Node::ActionUnit(); }

    RedBlackTreeBase(int sz) : pool(sz) { pool.clear(); }

    template <typename... Args> NodePtr alloc(Args... args) {
        NodePtr t = &(*pool.alloc() = Node(args...));
        return update(t);
    }

    NodePtr make_tree() { return nullptr; }

    void free(NodePtr t) { pool.free(t); }

    void clear(NodePtr t) {
        if (!t) return;
        clear(t->left);
        clear(t->right);
        free(t);
    }

    NodePtr build(const std::vector<Monoid> &v) {
        auto dfs = [&](auto self, int l, int r) -> NodePtr {
            if (l == r) return nullptr;
            if (l + 1 == r) return alloc(v[l]);
            int m = (l + r) / 2;
            return merge(self(self, l, m), self(self, m, r));
        };
        return dfs(dfs, 0, (int)v.size());
    }

    NodePtr merge(NodePtr l, NodePtr r) {
        if (!l or !r) return l ? l : r;
        NodePtr c = submerge(l, r);
        c->is_red = false;
        return c;
    }

    std::pair<NodePtr, NodePtr> split(NodePtr t, int k) {
        assert(0 <= k and k <= size(t));
        if (!t) return {nullptr, nullptr};
        if (k == 0) return {nullptr, as_root(t)};
        if (k == size(t)) return {as_root(t), nullptr};
        t = push(t);
        NodePtr l = as_root(t->left), r = as_root(t->right);
        free(t);
        if (k < size(l)) {
            auto [ll, rr] = split(l, k);
            return {ll, merge(rr, r)};
        }
        if (k > size(l)) {
            auto [ll, rr] = split(r, k - size(l));
            return {merge(l, ll), rr};
        }
        return {l, r};
    }

    struct NodePtr3 {
        NodePtr x, y, z;
    };

    NodePtr3 split3(NodePtr t, int a, int b) {
        // assertしなくても動くけど，分かりにくい
        assert(0 <= a and a <= b and b <= size(t));
        auto [x, y] = split(t, a);
        auto [y1, z] = split(y, b - a);
        return {x, y1, z};
    }

    template <typename... Args> void insert(NodePtr &t, int k, Args... args) {
        assert(0 <= k and k <= size(t));
        auto [l, r] = split(t, k);
        t = merge(merge(l, alloc(Monoid(args...))), r);
    }

    void erase(NodePtr &t, int k) {
        assert(0 <= k and k < size(t));
        auto [l, r] = split(t, k);
        auto [ll, rr] = split(r, 1);
        free(ll);
        t = merge(l, rr);
    }

    template <typename... Args> void set(NodePtr t, int k, Args... args) {
        assert(0 <= k and k < size(t));
        NodePtr now = t;
        auto dfs = [&](auto self, NodePtr now, int k) -> void {
            if (!now->left) {
                now->val = Monoid(args...);
                return;
            }
            now = push(now);
            if (size(now->left) > k) self(self, now->left, k);
            else self(self, now->right, k - size(now->left));
            now = update(now);
        };
        dfs(dfs, now, k);
    }

    Monoid get(NodePtr t, int k) {
        assert(0 <= k and k < size(t));
        NodePtr now = t;
        while (now->left) {
            now = push(now);
            if (size(now->left) > k) now = now->left;
            else {
                k -= size(now->left);
                now = now->right;
            }
        }
        return now->val;
    }

    Monoid prod(NodePtr &t, int l, int r) {
        assert(0 <= l and l <= r and r <= size(t));
        auto [t1, t2, t3] = split3(t, l, r);
        Monoid res = (t2 ? t2->val : MonoidUnit());
        t = merge(merge(t1, t2), t3);
        return res;
    }

    void reverse(NodePtr &t, int l, int r) {
        assert(0 <= l and l <= r and r <= size(t));
        auto [t1, t2, t3] = split3(t, l, r);
        if (t2) t2->is_rev ^= 1;
        t = merge(merge(t1, t2), t3);
    }

    template <typename... Args> void push_front(NodePtr &t, Args... args) {
        t = merge(alloc(Monoid(args...)), t);
    }

    template <typename... Args> void push_back(NodePtr &t, Args... args) {
        t = merge(t, alloc(Monoid(args...)));
    }

    void pop_front(NodePtr &t) {
        auto [l, r] = split(t, 1);
        t = r;
    }

    void pop_back(NodePtr &t) {
        auto [l, r] = split(t, size(t) - 1);
        t = l;
    }

    struct bb_result {
        int s;
        Monoid prod;
        NodePtr t;
    };

    template <class G> bb_result max_right(NodePtr &t, int l, const G &g) {
        assert(0 <= l and l <= size(t));
        assert(g(MonoidUnit()));
        auto [t1, t2] = split(t, l);
        if (!t2) {
            t = merge(t1, t2);
            return {l, MonoidUnit(), nullptr};
        }
        if (g(t2->val)) {
            t = merge(t1, t2);
            return {l + size(t2), t2->val, nullptr};
        }

        int k = l;
        Monoid x = MonoidUnit();
        NodePtr now = t2;

        while (now->left) {
            now = push(now);
            Monoid y = MonoidOp(x, now->left->val);
            if (g(y)) {
                x = y;
                k += size(now->left);
                now = now->right;
            } else {
                now = now->left;
            }
        }
        t = merge(t1, t2);
        return {k, x, now};
    }

    template <class G> bb_result min_left(NodePtr &t, int r, const G &g) {
        assert(0 <= r and r <= size(t));
        assert(g(MonoidUnit()));
        auto [t1, t2] = split(t, r);
        if (!t1) {
            t = merge(t1, t2);
            return {r, MonoidUnit(), nullptr};
        }
        if (g(t1->val)) {
            t = merge(t1, t2);
            return {0, t1->val, nullptr};
        }

        int k = r;
        Monoid x = MonoidUnit();
        NodePtr now = t1;

        while (now->right) {
            now = push(now);
            Monoid y = MonoidOp(now->right->val, x);
            if (g(y)) {
                x = y;
                k -= size(now->right);
                now = now->left;
            } else {
                now = now->right;
            }
        }
        t = merge(t1, t2);
        return {k, x, now};
    }

    inline int size(NodePtr t) const { return t ? t->count : 0; }

  protected:
    NodePtr rotate(NodePtr t, bool left) {
        t = push(t);
        NodePtr s;
        if (left) {
            s = push(t->left);
            t->left = s->right;
            s->right = t;
        } else {
            s = push(t->right);
            t->right = s->left;
            s->left = t;
        }
        update(t);
        return update(s);
    }

    NodePtr submerge(NodePtr l, NodePtr r) {
        if (l->rank < r->rank) {
            r = push(r);
            NodePtr c = submerge(l, r->left);
            r->left = c;
            if (c->is_red and c->left->is_red) {
                c->is_red = 0, r->is_red = 1;
                if (!r->right->is_red) return rotate(r, true);
                r->right->is_red = 0;
            }
            return update(r);
        } else if (l->rank > r->rank) {
            l = push(l);
            NodePtr c = submerge(l->right, r);
            l->right = c;
            if (c->is_red and c->right->is_red) {
                c->is_red = 0, l->is_red = 1;
                if (!l->left->is_red) return rotate(l, false);
                l->left->is_red = 0;
            }
            return update(l);
        } else {
            return alloc(l, r);
        }
    }

    NodePtr as_root(NodePtr t) {
        if (!t) return t;
        t->is_red = false;
        return t;
    }

    virtual NodePtr update(NodePtr t) = 0;

    virtual NodePtr push(NodePtr t) = 0;
};

} // namespace rbtree

} // namespace kk2

#endif // KK2_BBST_BASE_RED_BLACK_TREE_BASE_HPP
