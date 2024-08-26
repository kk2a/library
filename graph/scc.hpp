#ifndef GRAPH_SCC_HPP
#define GRAPH_SCC_HPP 1

namespace kk2 {

template <class G>
struct SCC {
    int n, m;
    const G &g;
    vector<vector<int>> revg;
    vector<int> ord, scc_id;
    vector<bool> used;
    vector<vector<int>> blng, dag;
    
    SCC(const G &g_) : n(g_.n), m(g_.m), g(g_) { init(); }

    int operator[](int k) const { return scc_id[k]; }
    vector<int> same_scc(int u) const { return blng[u]; }

  private:
    void init() {
        auto dfs = [&](auto self, int u) -> void {
            if (used[u]) return;
            used[u] = true;
            for (auto &e : g[u]) self(self, e.to);
            ord.emplace_back(u);
        };
        auto rdfs = [&](auto self, int u, int k) -> void {
            if (scc_id[u] != -1) return;
            scc_id[u] = k;
            for (auto &e : revg[u]) self(self, e, k);
        };

        used.resize(n, false);
        ord.reserve(n);
        for (int u = 0; u < n; u++) dfs(dfs, u);
        reverse(begin(ord), end(ord));

        scc_id.resize(n, -1);
        revg.resize(n);
        for (int u = 0; u < n; u++) for (auto &e : g[u]) {
            revg[e.to].emplace_back(u);
        }
        int k = 0;
        for (auto &u : ord) if (scc_id[u] == -1) rdfs(rdfs, u, k++);

        dag.resize(k);
        blng.resize(k);
        for (int u = 0; u < n; u++) {
            blng[scc_id[u]].emplace_back(u);
            for (auto &e : g[u]) {
                int v = e.to;
                if (scc_id[u] == scc_id[v]) continue;
                dag[scc_id[u]].emplace_back(scc_id[v]);
            }
        }
    }
};

} // namespace kk2

#endif // GRAPH_SCC_HPP
