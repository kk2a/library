#ifndef KK2_UNIONFIND_ROLLBACK_HPP
#define KK2_UNIONFIND_ROLLBACK_HPP 1

#include <utility>
#include <vector>

namespace kk2 {

struct RollbackableUnionFind {
    std::vector<int> d;
    std::vector<std::pair<int, int>> hist;
    std::vector<int> snaps;

    RollbackableUnionFind(int n = 0) : d(n, -1) {}

    bool same(int x, int y) { return find(x) == find(y); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) std::swap(x, y);
        hist.emplace_back(x, d[x]);
        d[x] += d[y];
        hist.emplace_back(y, d[y]);
        d[y] = x;
        return true;
    }

    int find(int x) {
        if (d[x] < 0) return x;
        return find(d[x]);
    }

    int treesize(int x) { return -d[find(x)]; }

    void snapshot() { snaps.push_back(size(hist)); }

    void rollback() {
        while (int(size(hist)) > snaps.back()) {
            auto [i, x] = hist.back();
            hist.pop_back();
            d[i] = x;
        }
        snaps.pop_back();
    }
};

} // namespace kk2

#endif // KK2_UNIONFIND_ROLLBACK_HPP
