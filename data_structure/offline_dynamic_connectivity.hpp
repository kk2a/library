#ifndef KK2_DATA_STRUCTURE_OFFLINE_DYNAMIC_CONNECTIVITY_HPP
#define KK2_DATA_STRUCTURE_OFFLINE_DYNAMIC_CONNECTIVITY_HPP 1

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../unionfind/rollback.hpp"

namespace kk2 {

struct OfflineDynamicConnectivity {
  private:
    int n, q, sz;

    using E = std::pair<int, int>;
    std::vector<std::pair<E, int>> es;
    std::vector<E> seg;
    std::vector<int> siz;

    void apply(int l, int r, E e) {
        l += sz, r += sz;
        while (l < r) {
            if (l & 1) seg[siz[l++]++] = e;
            if (r & 1) seg[siz[--r]++] = e;
            l >>= 1, r >>= 1;
        }
    }

    void apply_pre(int l, int r) {
        l += sz, r += sz;
        while (l < r) {
            if (l & 1) siz[l++]++;
            if (r & 1) siz[--r]++;
            l >>= 1, r >>= 1;
        }
    }

    void seg_build() {
        for (int i = 1; i < 2 * sz - 1; i++) siz[i + 1] += siz[i];
        seg.resize(siz[2 * sz - 1]);
        for (int i = 2 * sz - 1; i; --i) siz[i] = siz[i - 1];
    }

  public:
    RollbackableUnionFind uf;

    OfflineDynamicConnectivity(int n_, int q_) : n(n_), q(q_), sz(1), uf(n) {
        while (sz < n) sz <<= 1;
        siz.resize(2 * sz, 0);
    }

    void add_edge(int t, int a, int b) {
        es.push_back({
            {a, b},
            2 * t
        });
    }

    void del_edge(int t, int a, int b) {
        es.push_back({
            {a, b},
            2 * t + 1
        });
    }

    void build(bool is_sorted = false) {
        if (!is_sorted) std::sort(es.begin(), es.end());
        E pree = {-1, -1};
        int pret = -1;
        for (auto [e, t] : es) {
            if (pree != e) {
                if (pret != -1) apply_pre(pret, q);
                pree = e;
                pret = -1;
            }
            if (t & 1 and pret != -1) {
                apply_pre(pret, t / 2);
                pret = -1;
            } else if (~t & 1 and pret == -1) {
                pret = t / 2;
            }
        }
        if (pret != -1) apply_pre(pret, q);

        seg_build();
        pree = {-1, -1};
        pret = -1;
        for (auto [e, t] : es) {
            if (pree != e) {
                if (pret != -1) apply(pret, q, pree);
                pree = e;
                pret = -1;
            }
            if (t & 1 and pret != -1) {
                apply(pret, t / 2, e);
                pret = -1;
            } else if (~t & 1 and pret == -1) {
                pret = t / 2;
            }
        }
        if (pret != -1) apply(pret, q, pree);
    }

    template <class Query> void run(const Query &query) {
        auto dfs = [&](auto self, int now) -> void {
            if (now - sz >= q) return;
            uf.snapshot();
            for (int i = siz[now - 1]; i < siz[now]; i++) uf.unite(seg[i].first, seg[i].second);
            if (now >= sz) {
                query(now - sz);
            } else {
                self(self, now * 2);
                self(self, now * 2 + 1);
            }
            uf.rollback();
        };
        dfs(dfs, 1);
    }
};


} // namespace kk2

#endif // KK2_DATA_STRUCTURE_OFFLINE_DYNAMIC_CONNECTIVITY_HPP
