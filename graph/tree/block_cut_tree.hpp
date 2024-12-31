#ifndef GRAPH_TREE_BLOCK_CUT_TREE_HPP
#define GRAPH_TREE_BLOCK_CUT_TREE_HPP 1

#include <vector>

#include "../bcc.hpp"

namespace kk2 {

template <class G> struct BlockCutTree : BCC<G> {
    std::vector<int> comp_v;
    std::vector<std::vector<int>> group_v;
    G forest;
    int off;

    BlockCutTree(const G &g_) : BCC<G>(g_) { init_bct(); }

    int size() const { return group_v.size(); }

    bool is_articulation(int v) const { return comp_v[v] >= off; }

  private:
    void init_bct() {
        comp_v.resize(this->n, -1);
        auto bcc_v = this->get_bcc_vertices();
        off = bcc_v.size();
        group_v.resize(bcc_v.size() + this->articulations.size());
        forest = G(group_v.size());
        for (int i = 0; i < (int)this->articulations.size(); ++i) {
            comp_v[this->articulations[i]] = i + off;
            group_v[i + off].emplace_back(this->articulations[i]);
        }

        std::vector<int> buf(this->articulations.size(), -1);

        for (int i = 0; i < (int)bcc_v.size(); ++i) {
            for (auto &v : bcc_v[i]) {
                group_v[i].emplace_back(v);
                if (comp_v[v] == -1) comp_v[v] = i;
                else if (buf[comp_v[v] - off] != i) {
                    forest.add_edge(i, comp_v[v]);
                    buf[comp_v[v] - off] = i;
                }
            }
        }
    }
};

} // namespace kk2

#endif // GRAPH_TREE_BLOCK_CUT_TREE_HPP
