#ifndef SEGMENT_TREE_DYNAMIC_HPP
#define SEGMENT_TREE_DYNAMIC_HPP 1

template <class S, S (*op)(S, S), S (*e)(),
          class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct DynamicLazySegTree {
    using i64 = long long;
    struct Node {
        i64 idx;
        Node *l, *r;
        S sum;
        F laz;
        Node(i64 idx = -1) : l(nullptr), r(nullptr), sum(e()), laz(id()), idx(idx) {}
    };

    Node* root;
    i64 Rmx;
    DynamicLazySegTree(i64 n_ = 0) {
        Rmx = 2;
        while (Rmx < n_) Rmx <<= 1;
        root = new_node(1);
    }

    S get(i64 p) {
        i64 l = 0, r = Rmx;
        Node* now = root;
        while (r - l > 1) {
            push(now);
            i64 m = (l + r) >> 1;
            if (p < m) {
                if (!now->l) return e();
                now = now->l;
                r = m;
            }
            else {
                if (!now->r) return e();
                now = now->r;
                l = m;
            }
        }
        return now->sum;
    }

    void set(i64 i, const T& x) {
        _set(root, 0, Rmx, i, x);
    }
    void apply(i64 l, i64 r, const F& f) {
        _apply(root, 0, Rmx, l, r, f);
    }
    S prod(i64 l, i64 r) {
        return _prod(root, 0, Rmx, l, r);
    }
    void merge(DynamicLazySegTree& dst) {
        root = _merge(root, dst.root);
    }

    template <bool (*g)(S)> i64 max_right(i64 l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> i64 max_right(i64 l, const G& g) {
        assert(0 <= l && l <= Rmx);
        assert(g(e()));
        return _max_right(root, l, g);
    }

    template <bool (*g)(S)> i64 min_left(i64 r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> i64 min_left(i64 r, const G& g) {
        assert(0 <= r && r <= Rmx);
        assert(g(e()));
        return _min_left(root, r, g);
    }

  private:
    DynamicLazySegTree(Node* root, i64 Rmx) : root(root), Rmx(Rmx) {}
    Node* new_node(int idx) { return new Node(idx); }
    void del_node(Node* node) { delete node; }

    void action(Node* now, const F& f) {
        assert(now && f != id());
        now->sum = mapping(f, now->sum);
        now->laz = composition(f, now->laz);
    }
    void push(Node* now) {
        assert(now);
        if (now->lazy == id()) return;
        if (!now->l) now->l = new_node(now.idx << 1 | 0);
        if (!now->r) now->r = new_node(now.idx << 1 | 1);
        action(now->l, now->lazy);
        action(now->r, now->lazy);
        now->lazy = id();
    }
    void update(Node* now) {
        assert(now->laz == id());
        now->sum = op(now->l ? now->l->sum : e(),
                      now->r ? now->r->sum : e());
    }

    void _set(Node* now, i64 l, i64 r, i64 i, const S& x) {
        assert(l <= i && i < r && now);
        if (l + 1  == r) {
            now->sum = x;
            return;
        }
        i64 m = (l + r) >> 1;
        push(now);
        if (i < m) {
            if (!now->l) now->l = new_node(now.idx << 1 | 0);
            _set(now->l, l, m, i, x);
        }
        else {
            if (!now->r) now->r = new_node(now.idx << 1 | 1);
            _set(now->r, m, r, i, x);
        }
        update(now);
    }

    void apply(Node* now, i64 l, i64 r, i64 a, i64 b, const F& f) {
        assert(a <= b && a < r && l < b && now);
        if (l == a && r == b) {
            action(now, f);
            if (l + 1 == r) now->lazy = id();
            return;
        }
        i64 m = (l + r) >> 1;
        push(now);
        if (a < m) {
            if (!now->l) now->l = new_node(now.idx << 1 | 0);
            _apply(now->l, l, m, a, min(m, b), f);
        }
        if (m < b) {
            if (!now->r) now->r = new_node(now.idx << 1 | 1);
            _apply(now->r, m, r, max(a, m), b, f);
        }
        update(now);
    }

    S prod(Node* now, i64 l, i64 r, i64 a, i64 b) {
        assert(a <= b && a < r && l < b && now);
        if (l == a && r == b) return now->sum;
        i64 m = (l + r) >> 1;
        push(now);
        S res = e();
        if (a < m && now->l) res = op(_prod(now->l, l, m, a, min(m, b)), res);
        if (m < b && now->r) res = op(res, _prod(now->r, m, r, max(a, m), b));
        return res;
    }

    Node* _merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        assert(a->laz == id() && b->laz == id());
        a->l = merge(a->l, b->l);
        a->r = merge(a->r, b->r);
        update(a);
        del_node(b);
        return a;
    }

    template <class G>
    i64 _max_right(Node* now, i64 l, const G& g) {
        
    }
};

namespace DynamicSegImpl {

template <class S>
S mapping(S l, bool) { return l; }
bool composition(bool, bool) { return false; }
bool id() { return false; }

template <class S, S (*op)(S, S), S (*e)()>
using DynamicSegTree =
    DynamicLazySegTree<S, op, e, bool, mapping, composition, id>;

} // namespace DynamicSegImpl
using DynamicSegImpl::DynamicSegTree;

#endif // SEGMENT_TREE_DYNAMIC_HPP
