#ifndef KK2_UNIONFIND_WITH_MONOID_HPP
#define KK2_UNIONFIND_WITH_MONOID_HPP 1

#include <utility>
#include <vector>

namespace kk2 {

template <class M, M (*op)(M, M), M (*e)()> struct UnionFindWithMonoid {
  public:
    UnionFindWithMonoid() : UnionFindWithMonoid(0) {}

    UnionFindWithMonoid(int n) : _n(n), d(n, -1), _monoid(n, e()) {}

    bool same(int x, int y) { return find(x) == find(y); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        M m = op(_monoid[x], _monoid[y]);
        if (d[x] > d[y]) std::swap(x, y);
        d[x] += d[y];
        d[y] = x;
        _monoid[x] = m;
        return true;
    }

    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    M get(int x) { return _monoid[find(x)]; }

    void set_to_root(int x, M m) { _monoid[find(x)] = m; }

    int size(int x) { return -d[find(x)]; }

  private:
    int _n;
    std::vector<int> d;
    std::vector<M> _monoid;
};

}; // namespace kk2

#endif // KK2_UNIONFIND_WITH_MONOID_HPP
