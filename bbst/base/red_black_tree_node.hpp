#ifndef KK2_BBST_BASE_RED_BLACK_TREE_NODE_HPP
#define KK2_BBST_BASE_RED_BLACK_TREE_NODE_HPP 1

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace rbtree {

template <class M> struct RedBlackTreeNode {
    using RedBlackTreeNode_t = RedBlackTreeNode<M>;
    using NodePtr = RedBlackTreeNode_t *;
    using action_type = void;
    using S = M;
    using A = int;
    static S s_op(S a, S b) { return S::op(a, b); }
    static S s_unit() { return S::unit(); }
    static S sa_act(A, S) { return S(); }
    static A a_op(A, A) { return 0; }
    static A a_unit() { return 0; }

    NodePtr left, right;
    int rank, count;
    bool is_red, is_rev;
    S val;

    RedBlackTreeNode(S val_ = s_unit())
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
        os << "[\n";

        // BFS用のキュー：(ノード, 深度)のペア
        std::vector<std::pair<NodePtr, int>> queue;
        queue.emplace_back(NodePtr(const_cast<RedBlackTreeNode *>(this)), 0);

        int current_depth = -1;

        for (size_t i = 0; i < queue.size(); i++) {
            auto [node, depth] = queue[i];

            // 新しい深度に入ったらレベル情報を出力
            if (depth != current_depth) {
                if (current_depth >= 0) os << "\n";
                os << "  Level " << depth << ": ";
                current_depth = depth;
            } else {
                os << " | ";
            }

            if (!node) {
                // nullptrの場合
                os << "(null)";
            } else {
                // ノード情報の出力
                os << (node->is_red ? "(R" : "(B");
                os << " val:";
                if constexpr (requires { os << node->val; }) {
                    os << node->val;
                } else {
                    os << "[unprintable]";
                }
                os << " is_rev:" << (node->is_rev ? "T" : "F");
                os << " rank:" << node->rank;
                os << " cnt:" << node->count;
                os << ")";

                // 子ノードをキューに追加（nullptrも含める）
                queue.emplace_back(node->left, depth + 1);
                queue.emplace_back(node->right, depth + 1);
            }
        }

        os << "\n]\n";
    }
};

} // namespace rbtree

} // namespace kk2

#endif // KK2_BBST_BASE_RED_BLACK_TREE_NODE_HPP
