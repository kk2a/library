#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP 1

#include "../unionfind/unionfind.hpp"

namespace kk2 {

struct Kruskal {
    using i64 = long long;
  private:
    struct Edge {
        i64 cost;
        int from, to;
        bool operator<(const Edge &e) const {
            return cost < e.cost;
        }
    };
    vector<Edge> edges;
    int _n, _m;
  public:
    Kruskal(int n = 0) : _n(n), _m(0) {}

    void add_edge(int from, int to, i64 cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        _m++;
        edges.eb(cost, from, to);
    }

    i64 query() {
        sort(begin(edges), end(edges));
        UnionFind uf(_n);
        i64 res = 0;
        for (int i = 0; i < _m; i++) {
            if (uf.same(edges[i].from, edges[i].to)) continue;
            uf.unite(edges[i].from, edges[i].to);
            res += edges[i].cost;
        }
        if (uf.size(0) != _n) return -1;
        return res;
    }
};

} // namespace kk2

#endif // KRUSKAL_HPP
