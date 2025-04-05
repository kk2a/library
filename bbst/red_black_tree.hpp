#ifndef KK2_BBST_RED_BLACK_TREE_HPP
#define KK2_BBST_RED_BLACK_TREE_HPP 1

#include <cassert>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "../type_traits/io.hpp"
#include "base/red_black_tree_base.hpp"

namespace kk2 {

namespace rbtree {

template <class S, S (*op)(S, S), S (*e)()> struct RedBlackTreeNode {
    using NodePtr = typename RedBlackTreeBase<RedBlackTreeNode>::NodePtr;
    NodePtr left, right;
    int rank, count;
    bool is_red, is_rev;
    S val;

    RedBlackTreeNode(S val_ = e())
        : left(nullptr),
          right(nullptr),
          rank(0),
          count(1),
          is_red(false),
          is_rev(false),
          val(val_) {}

    RedBlackTreeNode(NodePtr l, NodePtr r) : left(l), right(r), is_red(true), is_rev(false) {}

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        std::vector<std::string> a;
        a.push_back("[");
        auto dfs = [&](auto self, NodePtr t, int dep) -> void {
            if (!t) return;
            if ((int)a.size() <= dep + 1) a.resize(dep + 2);
            a[dep + 1] += (t->is_red ? "(R" : "(B");
            a[dep + 1] += " val:" + std::to_string(t->val);
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

    using Monoid = S;

    static Monoid MonoidOp(Monoid a, Monoid b) { return op(a, b); }

    static Monoid MonoidUnit() { return e(); }

    using Action = int;

    static Monoid Map(Action, Monoid x) { return x; }

    static Action ActionOp(Action, Action) { return 0; }

    static Action ActionUnit() { return 0; }
};

template <class S, S (*op)(S, S), S (*e)()> struct RedBlackTree
    : RedBlackTreeBase<RedBlackTreeNode<S, op, e>> {
    using base = RedBlackTreeBase<RedBlackTreeNode<S, op, e>>;
    using base::RedBlackTreeBase;
    using base::size;
    using typename base::NodePtr;

  protected:
    NodePtr update(NodePtr t) override {
        t->count = size(t->left) + size(t->right) + (t->left == nullptr);
        t->rank = t->left ? t->left->rank + !t->left->is_red : 1;
        t->val = (t->left ? op(t->left->val, t->right->val) : t->val);
        return t;
    }

    NodePtr push(NodePtr t) override {
        if (t->is_rev) {
            std::swap(t->left, t->right);
            if (t->left) t->left->is_rev ^= 1;
            if (t->right) t->right->is_rev ^= 1;
            t->is_rev = false;
        }
        return t;
    }
};

template <class M> using RedBlackTreeS = RedBlackTree<M, M::op, M::unit>;

} // namespace rbtree

using rbtree::RedBlackTree;
using rbtree::RedBlackTreeS;

} // namespace kk2


#endif // KK2_BBST_RED_BLACK_TREE_HPP
