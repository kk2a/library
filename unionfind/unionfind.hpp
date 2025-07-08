#ifndef KK2_UNIONFIND_UNIONFIND_HPP
#define KK2_UNIONFIND_UNIONFIND_HPP 1

#include <utility>
#include <vector>

namespace kk2 {

struct UnionFind {
    std::vector<int> d;

    UnionFind(int n = 0) : d(n, -1) {}

    bool same(int x, int y) { return find(x) == find(y); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (-d[x] < -d[y]) std::swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    template <class F> bool unite(int x, int y, const F &f) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (-d[x] < -d[y]) std::swap(x, y);
        f(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    int size(int x) { return -d[find(x)]; }
};

} // namespace kk2

#endif // KK2_UNIONFIND_UNIONFIND_HPP
