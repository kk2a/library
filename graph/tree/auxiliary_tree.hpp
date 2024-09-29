#ifndef GRAPH_TREE_AUXILIARY_TREE_HPP
#define GRAPH_TREE_AUXILIARY_TREE_HPP 1

#include <algorithm>
#include <functional>
#include <stack>
#include <utility>
#include <vector>

#include "heavy_light_decomposition.hpp"

namespace kk2 {

template <typename G> struct AuxiliaryTree {
    G g;
    HeavyLightDecomposition<G> hld;

    AuxiliaryTree(const G &g_, int root_ = 0) : g(g_), hld(g, root_) {}

    std::pair<std::vector<std::vector<int>>, std::vector<int>> get(std::vector<int> ps) {
        if (ps.empty()) return {};
        std::sort(
            std::begin(ps), std::end(ps), [&](int i, int j) { return hld.in[i] < hld.in[j]; });
        for (int i = 0, ps_size = ps.size(); i < ps_size - 1; i++) {
            ps.push_back(hld.lca(ps[i], ps[i + 1]));
        }
        std::sort(
            std::begin(ps), std::end(ps), [&](int i, int j) { return hld.in[i] < hld.in[j]; });
        ps.erase(std::unique(std::begin(ps), std::end(ps)), std::end(ps));

        std::vector<std::vector<int>> aux(ps.size());
        std::stack<int> st;
        st.emplace(0);
        for (int i = 1; i < (int)ps.size(); i++) {
            int l = hld.lca(ps[i], ps[st.top()]);
            while (ps[st.top()] != l) st.pop();
            aux[st.top()].emplace_back(i);
            st.emplace(i);
        }
        return std::make_pair(aux, ps);
    }
};

} // namespace kk2

#endif // GRAPH_TREE_AUXILIARY_TREE_HPP
