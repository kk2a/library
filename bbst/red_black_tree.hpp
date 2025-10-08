#ifndef KK2_BBST_RED_BLACK_TREE_HPP
#define KK2_BBST_RED_BLACK_TREE_HPP 1

#include <cassert>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "base/red_black_tree_base.hpp"
#include "base/red_black_tree_node.hpp"

namespace kk2 {

namespace rbtree {

template <class M> struct RedBlackTree : RedBlackTreeBase<RedBlackTree<M>, RedBlackTreeNode <M>> {
    using base = RedBlackTreeBase<RedBlackTree<M>, RedBlackTreeNode<M>>;
    using base::RedBlackTreeBase;
    using base::s_op;
    using base::size;
    using typename base::NodePtr;
    using typename base::S;

    NodePtr update(NodePtr t) {
        t->count = size(t->left) + size(t->right) + (t->left == nullptr);
        t->rank = t->left ? t->left->rank + !t->left->is_red : 1;
        t->val = (t->left ? s_op(t->left->val, t->right->val) : t->val);
        return t;
    }

    NodePtr push(NodePtr t) {
        if (t->is_rev) {
            std::swap(t->left, t->right);
            if (t->left) t->left->is_rev ^= 1;
            if (t->right) t->right->is_rev ^= 1;
            t->is_rev = false;
        }
        return t;
    }
};

} // namespace rbtree

using rbtree::RedBlackTree;

} // namespace kk2


#endif // KK2_BBST_RED_BLACK_TREE_HPP
