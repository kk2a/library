#ifndef KK2_BBST_PERSISTENT_LAZY_RED_BLACK_TREE_HPP
#define KK2_BBST_PERSISTENT_LAZY_RED_BLACK_TREE_HPP 1

#include "base/lazy_red_black_tree_node.hpp"
#include "base/red_black_tree_base.hpp"

namespace kk2 {

namespace rbtree {

template <class A_> struct PersistentLazyRedBlackTree
    : RedBlackTreeBase<PersistentLazyRedBlackTree<A_>, LazyRedBlackTreeNode<A_>> {
    using base = RedBlackTreeBase<PersistentLazyRedBlackTree<A_>, LazyRedBlackTreeNode<A_>>;
    using base::a_op;
    using base::a_unit;
    using base::alloc;
    using base::merge;
    using base::RedBlackTreeBase;
    using base::s_op;
    using base::sa_act;
    using base::size;
    using base::split;
    using base::split3;
    using typename base::A;
    using typename base::NodePtr;
    using typename base::S;

    template <class... Args> void apply(NodePtr &t, int l, int r, Args... args) {
        assert(0 <= l and l <= r and r <= size(t));
        auto [t1, t2, t3] = split3(t, l, r);
        all_apply(t2, A(args...));
        t = merge(merge(t1, t2), t3);
    }

    NodePtr update(NodePtr t) {
        t->count = size(t->left) + size(t->right) + (t->left == nullptr);
        t->rank = t->left ? t->left->rank + !t->left->is_red : 1;
        t->val = (t->left ? s_op(t->left->val, t->right->val) : t->val);
        return t;
    }

    void all_apply(NodePtr &t, A f) {
        if (!t) return;
        t = alloc(*t);
        t->val = sa_act(f, t->val);
        if (t->left) t->lazy = a_op(f, t->lazy);
    }

    NodePtr push(NodePtr t) {
        t = alloc(*t);
        if (t->is_rev) {
            std::swap(t->left, t->right);
            // ここで子供を複製しないといけない．
            if (t->left) t->left->is_rev ^= 1;
            if (t->right) t->right->is_rev ^= 1;
            t->is_rev = false;
        }

        if (t->lazy != a_unit()) {
            all_apply(t->left, t->lazy);
            all_apply(t->right, t->lazy);
            t->lazy = a_unit();
        }
        return t;
    }
};

} // namespace rbtree

using rbtree::PersistentLazyRedBlackTree;

} // namespace kk2

#endif // KK2_BBST_PERSISTENT_LAZY_RED_BLACK_TREE_HPP
