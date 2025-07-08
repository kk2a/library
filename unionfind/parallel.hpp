#ifndef KK2_UNIONFIND_PARALLEL_HPP
#define KK2_UNIONFIND_PARALLEL_HPP 1

#include <numeric>

#include "../string/dynamic_rolling_hash.hpp"

namespace kk2 {

struct ParallelUnionFind {
    using DR = DynamicRollingHash<1>;
    std::vector<int> d, nxt;
    DR roots;

    ParallelUnionFind() = default;
    ParallelUnionFind(int n) : d(n, -1), nxt(n), roots(n) {
        for (int i = 0; i < n; ++i) {
            nxt[i] = i;
            roots.init_set(i, i ^ (1 << 30));
        }
        roots.build();
    }

    bool unite(int a, int b, int k) {
        int c = DR::lcp(roots, a, a + k, roots, b, b + k);
        if (c == k) return false;
        while (c != k) {
            int ll = a + c, rr = b + c;
            ll = roots.get(ll)[0].val() ^ (1 << 30);
            rr = roots.get(rr)[0].val() ^ (1 << 30);
            if (-d[ll] < -d[rr]) std::swap(ll, rr);
            d[ll] += d[rr];
            d[rr] = ll;
            roots.set(rr, ll ^ (1 << 30));
            for (int x = nxt[rr]; x != rr; x = nxt[x]) roots.set(x, ll ^ (1 << 30));

            std::swap(nxt[ll], nxt[rr]);
            c = DR::lcp(roots, a, a + k, roots, b, b + k);
        }
        return true;
    }

    int count = 0;
    double time = 0;

    template <class F> bool unite(int a, int b, int k, const F &f) {
        int c = DR::lcp(roots, a, a + k, roots, b, b + k);
        if (c == k) return false;
        while (c != k) {
            int ll = a + c, rr = b + c;
            ll = roots.get(ll)[0].val() ^ (1 << 30);
            rr = roots.get(rr)[0].val() ^ (1 << 30);
            if (-d[ll] < -d[rr]) std::swap(ll, rr);
            d[ll] += d[rr];
            d[rr] = ll;
            roots.set(rr, ll ^ (1 << 30));
            for (int x = nxt[rr]; x != rr; x = nxt[x]) roots.set(x, ll ^ (1 << 30));
            f(ll, rr);
            std::swap(nxt[ll], nxt[rr]);
            c = DR::lcp(roots, a, a + k, roots, b, b + k);
        }
        return true;
    }

    inline bool same(int a, int b) { return roots.get(a) == roots.get(b); }
    inline int find(int a) { return roots.get(a)[0].val() ^ (1 << 30); }
    inline int size(int a) { return -d[find(a)]; }
    inline std::vector<int> enumerate(int a) {
        std::vector<int> res{a};
        for (int j = nxt[a]; j != a; j = nxt[j]) res.push_back(j);
        return res;
    }
};

} // namespace kk2

#endif // KK2_UNIONFIND_PARALLEL_HPP
