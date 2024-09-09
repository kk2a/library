#ifndef UNIONFIND_WEIGHT_HPP
#define UNIONFIND_WEIGHT_HPP 1

#include <vector>

namespace kk2 {

// A is an abelian group
template <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)>
struct WeighedUnionFind {
  private:
    std::vector<int> d;
    std::vector<A> diff_weight;

  public:
    WeighedUnionFind(int n = 0) : d(n, -1), diff_weight(n, e()) {}

    bool unite(int x, int y, A w) {
        w = op(w, op(weight(x), inv(weight(y))));
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) {
            std::swap(x, y);
            w = inv(w);
        }
        d[x] += d[y];
        d[y] = x;
        diff_weight[y] = w;
        return true;
    }

    int find(int x) {
        if (d[x] < 0) return x;
        int r = find(d[x]);
        diff_weight[x] = op(diff_weight[x], diff_weight[d[x]]);
        return d[x] = r;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return -d[find(x)]; }

    A weight(int x) {
        find(x);
        return diff_weight[x];
    }

    A diff(int a, int b) { return op(inv(weight(a)), weight(b)); }
};

} // namespace kk2

#endif // UNIONFIND_WEIGHT_HPP
