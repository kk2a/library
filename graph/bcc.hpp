#ifndef KK2_GRAPH_BCC_HPP
#define KK2_GRAPH_BCC_HPP 1

#include <functional>
#include <vector>

#include "lowlink.hpp"

namespace kk2 {

template <class G> struct BCC : LowLink<G> {
    BCC(const G &g_) : LowLink<G>(g_) { init_bcc(); }

    std::vector<std::vector<int>> group_e;
    std::vector<int> comp_e;

  private:
    void init_bcc() {
        comp_e = std::vector<int>(this->m, -1);
        auto add = [&](int ei, int k) {
            group_e[k].emplace_back(ei);
            comp_e[ei] = k;
        };
        auto dfs = [&](auto self, int u, int k = -1, int ei = -1) -> void {
            for (auto &e : this->g[u]) {
                if (e.id == ei) continue;
                if (this->used_on_dfs_tree[e.id]) {
                    int nk = k;
                    if (this->low[e.to] >= this->ord[u])
                        nk = group_e.size(), group_e.emplace_back();
                    add(e.id, nk);
                    self(self, e.to, nk, e.id);
                }
                // back edge
                else if (this->ord[e.to] < this->ord[u]) {
                    add(e.id, k);
                }
            }
        };
        for (int u = 0; u < this->n; u++)
            if (this->root[u]) { dfs(dfs, u); }
    }

  public:
    std::vector<std::vector<int>> get_bcc_vertices() {
        std::vector<bool> buf1(this->n), buf2(this->n);
        std::vector<std::vector<int>> res;
        res.reserve(group_e.size());
        for (auto &bc : group_e) {
            if (bc.empty()) continue;
            int k = (int)res.size();
            res.emplace_back();
            for (auto &ei : bc) {
                auto e = this->g.edges[ei];
                int fr = e.from, to = e.to;
                if (!buf2[fr]) {
                    res[k].emplace_back(fr);
                    buf2[fr] = true;
                }
                if (!buf2[to]) {
                    res[k].emplace_back(to);
                    buf2[to] = true;
                }
                buf1[fr] = buf1[to] = true;
            }
            for (auto &ei : bc) {
                auto e = this->g.edges[ei];
                int fr = e.from, to = e.to;
                buf2[fr] = buf2[to] = false;
            }
        }
        for (int i = 0; i < this->n; i++)
            if (!buf1[i]) {
                int k = (int)res.size();
                res.emplace_back();
                res[k].emplace_back(i);
            }
        return res;
    }
};

} // namespace kk2

#endif // KK2_GRAPH_BCC_HPP
