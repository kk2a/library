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
// S val;

/**
 * @brief 赤黒木の基本クラス
 *
 */
template <typename Derived, typename Node> struct RedBlackTreeBase {
    using NodePtr = Node::NodePtr;
    using action_type = typename Node::action_type;
    using S = typename Node::S;
    using A = typename Node::A;
    static S s_op(S a, S b) { return Node::s_op(a, b); }
    static S s_unit() { return Node::s_unit(); }
    static S sa_act(A f, S x) { return Node::sa_act(f, x); }
    static A a_op(A f, A g) { return Node::a_op(f, g); }
    static A a_unit() { return Node::a_unit(); }

    VectorPool<Node> pool;

    RedBlackTreeBase() : pool() {}
    RedBlackTreeBase(int sz) : pool(sz) {}

    template <typename... Args> NodePtr alloc(Args... args) {
        NodePtr t = &(*pool.alloc() = Node(args...));
        return static_cast<Derived *>(this)->update(t);
    }

    NodePtr make_tree() { return nullptr; }

    void free(NodePtr t) { pool.free(t); }

    void clear(NodePtr t) {
        if (!t) return;
        clear(t->left);
        clear(t->right);
        free(t);
    }

    NodePtr build(const std::vector<S> &v) {
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
        t = static_cast<Derived *>(this)->push(t);
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
        assert(0 <= a and a <= b and b <= size(t));
        auto [x, y] = split(t, a);
        auto [y1, z] = split(y, b - a);
        return {x, y1, z};
    }

    template <typename... Args> void insert(NodePtr &t, int k, Args... args) {
        assert(0 <= k and k <= size(t));
        auto [l, r] = split(t, k);
        t = merge(merge(l, alloc(S(args...))), r);
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
                now->val = S(args...);
                return;
            }
            now = static_cast<Derived *>(this)->push(now);
            if (size(now->left) > k) self(self, now->left, k);
            else self(self, now->right, k - size(now->left));
            now = static_cast<Derived *>(this)->update(now);
        };
        dfs(dfs, now, k);
    }

    S get(NodePtr t, int k) {
        assert(0 <= k and k < size(t));
        NodePtr now = t;
        while (now->left) {
            now = static_cast<Derived *>(this)->push(now);
            if (size(now->left) > k) now = now->left;
            else {
                k -= size(now->left);
                now = now->right;
            }
        }
        return now->val;
    }

    S prod(NodePtr &t, int l, int r) {
        assert(0 <= l and l <= r and r <= size(t));
        auto [t1, t2, t3] = split3(t, l, r);
        S res = (t2 ? t2->val : s_unit());
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
        t = merge(alloc(S(args...)), t);
    }

    template <typename... Args> void push_back(NodePtr &t, Args... args) {
        t = merge(t, alloc(S(args...)));
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
        S prod;
        NodePtr t;
    };

    /**
     * @brief 二分探索（右方向）
     *
     * 条件を満たす最大のkを求める二分探索を行います。
     *
     * 以下の条件を満たすkを返します：
     *
     * - k = l または (k ≠ l かつ g(prod(l, k)) = true)
     *
     * - k = size(t) または (k ≠ size(t) かつ g(prod(l, k+1)) = false)
     *
     * @tparam G 述語関数の型。bool operator()(S)を持つ必要があります
     * @param t 探索対象の木（参照渡し、操作後に復元されます）
     * @param l 探索開始位置（0-indexed）
     * @param g 判定関数。Sを受け取りboolを返す関数オブジェクト
     * @return bb_result 構造体
     *
     *         - s: 条件を満たす最大のk
     *
     *         - prod: prod(l, k)の値
     *
     *         - t: k番目のノードへのポインタ（存在しない場合はnullptr）
     *
     * @pre 0 <= l <= size(t)
     * @pre g(s_unit()) == true
     */
    template <class G> bb_result max_right(NodePtr &t, int l, const G &g) {
        assert(0 <= l and l <= size(t));
        assert(g(s_unit()));
        auto [t1, t2] = split(t, l);
        if (!t2) {
            t = merge(t1, t2);
            return {l, s_unit(), nullptr};
        }
        if (g(t2->val)) {
            t = merge(t1, t2);
            return {size(t), t2->val, nullptr};
        }

        int k = l;
        S x = s_unit();
        NodePtr now = t2;

        while (now->left) {
            now = static_cast<Derived *>(this)->push(now);
            S y = s_op(x, now->left->val);
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

    /**
     * @brief 二分探索（左方向）
     *
     * 条件を満たす最小のkを求める二分探索を行います。
     *
     * 以下の条件を満たすkを返します：
     *
     * - k = r または (k ≠ r かつ g(prod(k, r)) = true)
     *
     * - k = 0 または (k ≠ 0 かつ g(prod(k-1, r)) = false)
     *
     * @tparam G 述語関数の型。bool operator()(S)を持つ必要があります
     * @param t 探索対象の木（参照渡し、操作後に復元されます）
     * @param r 探索終了位置（0-indexed）
     * @param g 判定関数。Sを受け取りboolを返す関数オブジェクト
     * @return bb_result 構造体
     *
     *         - s: 条件を満たす最小のk
     *
     *         - prod: prod(k, r)の値
     *
     *         - t: k-1番目のノードへのポインタ（存在しない場合はnullptr）
     *
     * @pre 0 <= r <= size(t)
     * @pre g(s_unit()) == true
     */
    template <class G> bb_result min_left(NodePtr &t, int r, const G &g) {
        assert(0 <= r and r <= size(t));
        assert(g(s_unit()));
        auto [t1, t2] = split(t, r);
        if (!t1) {
            t = merge(t1, t2);
            return {r, s_unit(), nullptr};
        }
        if (g(t1->val)) {
            t = merge(t1, t2);
            return {0, t1->val, nullptr};
        }

        int k = r;
        S x = s_unit();
        NodePtr now = t1;

        while (now->right) {
            now = static_cast<Derived *>(this)->push(now);
            S y = s_op(now->right->val, x);
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
        t = static_cast<Derived *>(this)->push(t);
        NodePtr s;
        if (left) {
            s = static_cast<Derived *>(this)->push(t->left);
            t->left = s->right;
            s->right = t;
        } else {
            s = static_cast<Derived *>(this)->push(t->right);
            t->right = s->left;
            s->left = t;
        }
        static_cast<Derived *>(this)->update(t);
        return static_cast<Derived *>(this)->update(s);
    }

    NodePtr submerge(NodePtr l, NodePtr r) {
        if (l->rank < r->rank) {
            r = static_cast<Derived *>(this)->push(r);
            NodePtr c = submerge(l, r->left);
            r->left = c;
            if (c->is_red and c->left->is_red) {
                c->is_red = 0, r->is_red = 1;
                if (!r->right->is_red) return rotate(r, true);
                r->right->is_red = 0;
            }
            return static_cast<Derived *>(this)->update(r);
        } else if (l->rank > r->rank) {
            l = static_cast<Derived *>(this)->push(l);
            NodePtr c = submerge(l->right, r);
            l->right = c;
            if (c->is_red and c->right->is_red) {
                c->is_red = 0, l->is_red = 1;
                if (!l->left->is_red) return rotate(l, false);
                l->left->is_red = 0;
            }
            return static_cast<Derived *>(this)->update(l);
        } else {
            return alloc(l, r);
        }
    }

    NodePtr as_root(NodePtr t) {
        if (!t) return t;
        t->is_red = false;
        return t;
    }
};

} // namespace rbtree

} // namespace kk2

#endif // KK2_BBST_BASE_RED_BLACK_TREE_BASE_HPP
