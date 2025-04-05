#ifndef KK2_DATA_STRUCTURE_ORDERED_SET_HPP
#define KK2_DATA_STRUCTURE_ORDERED_SET_HPP 1

#include <optional>
#include <utility>
#include <vector>

#include "../bbst/base/red_black_tree_base.hpp"

namespace kk2 {

namespace rbtree {

template <typename T, typename Compare> struct SetNode {
    using NodePtr = typename rbtree::RedBlackTreeBase<SetNode>::NodePtr;
    NodePtr left, right;
    int rank, count;
    bool is_red;

    struct Monoid {
        T mx;
        bool unit;

        Monoid() : mx(T{}), unit(true) {}

        Monoid(T x) : mx(x), unit(false) {}
    };

    Monoid val;

    SetNode(Monoid val_ = Monoid())
        : left(nullptr),
          right(nullptr),
          rank(0),
          count(1),
          is_red(false),
          val(val_) {}

    SetNode(NodePtr l, NodePtr r) : left(l), right(r), is_red(true) {}

    static Monoid MonoidOp(Monoid a, Monoid b) {
        if (a.unit or b.unit) return a.unit ? b : a;
        return Compare{}(a.mx, b.mx) ? b : a;
    }

    static Monoid MonoidUnit() { return Monoid(); }

    using Action = int;

    static Monoid Map(Action, Monoid x) { return x; }

    static Action ActionOp(Action, Action) { return 0; }

    static Action ActionUnit() { return 0; }
};

template <typename T, typename Compare> struct SetBase : RedBlackTreeBase<SetNode<T, Compare>> {
    using base = RedBlackTreeBase<SetNode<T, Compare>>;
    using base::MonoidOp;
    using base::RedBlackTreeBase;
    using base::size;
    using typename base::NodePtr;

  protected:
    NodePtr update(NodePtr t) override {
        t->count = size(t->left) + size(t->right) + (t->left == nullptr);
        t->rank = t->left ? t->left->rank + !t->left->is_red : 1;
        t->val = (t->left ? MonoidOp(t->left->val, t->right->val) : t->val);
        return t;
    }

    NodePtr push(NodePtr t) override { return t; }
};

template <typename T, typename Compare = std::less<T>> struct Set {
    using NodePtr = typename SetBase<T, Compare>::NodePtr;
    using Monoid = typename SetNode<T, Compare>::Monoid;

    static Monoid MonoidOp(Monoid a, Monoid b) { return SetNode<T, Compare>::MonoidOp(a, b); }

    SetBase<T, Compare> base;
    NodePtr root;

    Set() = delete;

    Set(int mx) : base(2 * mx), root(base.make_tree()) {}

    Set(int mx, const std::vector<T> &v)
        : base(2 * mx),
          root(base.build(std::vector<Monoid>(v.begin(), v.end()))) {}

    // valベースのsplitを実装しよう！
    void insert(T x) {
        auto [k, a, b] = base.max_right(root, 0, [&](auto t) { return t.unit or t.mx < x; });
        if (b and b->val.mx == x) return;
        base.insert(root, k, Monoid(x));
    }

    void erase(T x) {
        auto [k, a, b] = base.max_right(root, 0, [&](auto t) { return t.unit or t.mx < x; });
        if (b and b->val.mx == x) base.erase(root, k);
    }

    std::optional<T> get_kth(int k) {
        return size() <= k ? std::nullopt : std::optional<T>(base.get(root, k).mx);
    }

    int count_not_greater(T x) {
        return base.max_right(root, 0, [&](auto t) { return t.unit or t.mx <= x; }).s;
    }

    std::optional<T> max_not_greater(T x) {
        auto [k, a, b] = base.max_right(root, 0, [&](auto t) { return t.unit or t.mx <= x; });
        return a.unit ? std::nullopt : std::optional<T>(a.mx);
    }

    // maxだけでこれは捌けるのでmxだけにしましょう
    std::optional<T> min_not_less(T x) {
        auto [k, a, b] = base.max_right(root, 0, [&](auto t) { return t.unit or t.mx < x; });
        return b ? std::optional<T>(b->val.mx) : std::nullopt;
    }

    inline int size() const { return base.size(root); }
};

} // namespace rbtree

using rbtree::Set;

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_ORDERED_SET_HPP
