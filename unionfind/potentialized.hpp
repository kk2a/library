#ifndef KK2_UNIONFIND_POTENTIALIZED_HPP
#define KK2_UNIONFIND_POTENTIALIZED_HPP 1

#include <vector>

namespace kk2 {

template <class A, bool right = true> struct PotentializedUnionFind {
  private:
    std::vector<int> d;
    std::vector<A> par_diff;

  public:
    PotentializedUnionFind(int n, A e_ = A()) : d(n, -1), par_diff(n, e_) {}

    // x -> y : w
    // right: a[y]a[x]^-1 = w
    // !right: a[x]^-1a[y] = w
    bool unite(int x, int y, A w) {
        if constexpr (right) w = -potential(y) + w + potential(x);
        else w = potential(x) + w - potential(y);
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) {
            std::swap(x, y);
            w = -w;
        }
        d[x] += d[y];
        d[y] = x;
        par_diff[y] = w;
        return true;
    }

    int find(int x) {
        if (d[x] < 0) return x;
        int r = find(d[x]);
        if constexpr (right) par_diff[x] = par_diff[x] + par_diff[d[x]];
        else par_diff[x] = par_diff[d[x]] + par_diff[x];
        return d[x] = r;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return -d[find(x)]; }

    // root_x -> x
    A potential(int x) {
        find(x);
        return par_diff[x];
    }

    // x -> y
    A diff(int x, int y) {
        if constexpr (right) return potential(y) - potential(x);
        else return -potential(x) + potential(y);
    }
};

template <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)> struct EasyGroup {
    A val;

    EasyGroup() : val(e()) {}

    template <class... Args> EasyGroup(Args... args) : val(args...) {}

    EasyGroup operator+(const EasyGroup &rhs) const { return EasyGroup(op(val, rhs.val)); }

    EasyGroup operator-(const EasyGroup &rhs) const { return EasyGroup(op(val, inv(rhs.val))); }

    EasyGroup operator-() const { return EasyGroup(inv(val)); }
};

} // namespace kk2

#endif // KK2_UNIONFIND_POTENTIALIZED_HPP
