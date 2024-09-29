#ifndef UNIONFIND_POTENTIALIZED_HPP
#define UNIONFIND_POTENTIALIZED_HPP 1

#include <vector>

namespace kk2 {

// require:
// A is an abelian group
// A must have operator+ and operator-
// A() must return unit element
template <class A>
struct PotentializedUnionfind {
  private:
    std::vector<int> d;
    std::vector<A> diff_weight;

  public:
    PotentializedUnionfind(int n = 0) : d(n, -1), diff_weight(n, A()) {}

    // x -> y : w
    bool unite(int x, int y, A w) {
        w = w + weight(x) - weight(y);
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) {
            std::swap(x, y);
            w = -w;
        }
        d[x] += d[y];
        d[y] = x;
        diff_weight[y] = w;
        return true;
    }

    int find(int x) {
        if (d[x] < 0) return x;
        int r = find(d[x]);
        diff_weight[x] = diff_weight[x] + diff_weight[d[x]];
        return d[x] = r;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return -d[find(x)]; }

    // root -> x
    A weight(int x) {
        find(x);
        return diff_weight[x];
    }

    // a -> b
    A diff(int a, int b) { return -weight(a) + weight(b); }
};

template <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)>
struct EasyAbelianGroup {
    A val;
    EasyAbelianGroup() : val(e()) {}

    template <class... Args>
    EasyAbelianGroup(Args... args) : val(args...) {}

    EasyAbelianGroup operator+(const EasyAbelianGroup &rhs) const {
        return EasyAbelianGroup(op(val, rhs.val));
    }

    EasyAbelianGroup operator-(const EasyAbelianGroup &rhs) const {
        return EasyAbelianGroup(op(val, inv(rhs.val)));
    }

    EasyAbelianGroup operator-() const { return EasyAbelianGroup(inv(val)); }
};

} // namespace kk2

#endif // UNIONFIND_POTENTIALIZED_HPP
