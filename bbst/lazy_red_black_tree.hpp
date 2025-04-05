#ifndef KK2_BBST_LAZY_RED_BLACK_TREE_HPP
#define KK2_BBST_LAZY_RED_BLACK_TREE_HPP 1

#include <cassert>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "../type_traits/io.hpp"
#include "base/red_black_tree_base.hpp"

namespace kk2 {

namespace rbtree {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct LazyRedBlackTreeNode {
    using NodePtr = typename RedBlackTreeBase<LazyRedBlackTreeNode>::NodePtr;
    using Monoid = S;

    static Monoid MonoidOp(Monoid a, Monoid b) { return op(a, b); }

    static Monoid MonoidUnit() { return e(); }

    using Action = F;

    static Monoid Map(Action f, Monoid x) { return mapping(f, x); }

    static Action ActionOp(Action f, Action g) { return composition(f, g); }

    static Action ActionUnit() { return id(); }

    NodePtr left, right;
    int rank, count;
    bool is_red, is_rev;
    S val;
    F lazy;

    LazyRedBlackTreeNode(S val_ = e(), F lazy_ = id())
        : left(nullptr),
          right(nullptr),
          rank(0),
          count(1),
          is_red(false),
          is_rev(false),
          val(val_),
          lazy(lazy_) {}

    LazyRedBlackTreeNode(NodePtr l, NodePtr r) : left(l), right(r), is_red(true), is_rev(false) {}

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        std::vector<std::string> a;
        a.push_back("[");
        auto dfs = [&](auto self, NodePtr t, int dep) -> void {
            if (!t) return;
            if ((int)a.size() <= dep + 1) a.resize(dep + 2);
            a[dep + 1] += (t->is_red ? "(R" : "(B");
            a[dep + 1] += " val:" + std::to_string(t->val);
            a[dep + 1] += " lazy:" + std::to_string(t->lazy);
            a[dep + 1] += " is_rev:" + std::to_string(t->is_rev);
            a[dep + 1] += " rank:" + std::to_string(t->rank);
            a[dep + 1] += " cnt:" + std::to_string(t->count);
            a[dep + 1] += ") ";
            self(self, t->left, dep + 1);
            self(self, t->right, dep + 1);
        };
        dfs(dfs, NodePtr(this), 0);
        for (auto &s : a) s.push_back('\n');
        a.push_back("]");
        for (auto &s : a) os << s;
    }
};

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct LazyRedBlackTree
    : RedBlackTreeBase<LazyRedBlackTreeNode<S, op, e, F, mapping, composition, id>> {
    using base = RedBlackTreeBase<LazyRedBlackTreeNode<S, op, e, F, mapping, composition, id>>;
    using base::ActionOp;
    using base::Map;
    using base::merge;
    using base::RedBlackTreeBase;
    using base::size;
    using base::split;
    using base::split3;
    using typename base::NodePtr;

    template <class... Args>
    void apply(NodePtr &t, int l, int r, Args... args) {
        assert(0 <= l and l <= r and r <= size(t));
        auto [t1, t2, t3] = split3(t, l, r);
        all_apply(t2, F(args...));
        t = merge(merge(t1, t2), t3);
    }

  protected:
    NodePtr update(NodePtr t) override {
        t->count = size(t->left) + size(t->right) + (t->left == nullptr);
        t->rank = t->left ? t->left->rank + !t->left->is_red : 1;
        t->val = (t->left ? op(t->left->val, t->right->val) : t->val);
        return t;
    }

    void all_apply(NodePtr &t, F f) {
        if (!t) return;
        t->val = Map(f, t->val);
        if (t->left) t->lazy = ActionOp(f, t->lazy);
    }

    NodePtr push(NodePtr t) override {
        if (t->is_rev) {
            std::swap(t->left, t->right);
            if (t->left) t->left->is_rev ^= 1;
            if (t->right) t->right->is_rev ^= 1;
            t->is_rev = false;
        }

        if (t->lazy != id()) {
            all_apply(t->left, t->lazy);
            all_apply(t->right, t->lazy);
            t->lazy = id();
        }
        return t;
    }
};

template <class A>
using LazyRedBlackTreeS = LazyRedBlackTree<typename A::S,
                                           A::S::op,
                                           A::S::unit,
                                           typename A::A,
                                           A::act,
                                           A::A::op,
                                           A::A::unit>;

} // namespace rbtree

using rbtree::LazyRedBlackTree;
using rbtree::LazyRedBlackTreeS;

} // namespace kk2

#endif // KK2_BBST_LAZY_RED_BLACK_TREE_HPP
