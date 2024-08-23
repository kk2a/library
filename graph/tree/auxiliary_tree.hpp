#ifndef GRAPH_TREE_AUXILIARY_TREE_HPP
#define GRAPH_TREE_AUXILIARY_TREE_HPP 1

#include "heavy_light_decomposition.hpp"

template <typename G>
struct AuxiliaryTree {
    G g;
    HeavyLightDecomposition<G> hld;
    AuxiliaryTree(const G& g_, int root_ = 0) : g(g_), hld(g, root_) {}

    pair<vector<vector<int>>, vector<int>> get(vector<int> ps) {
        if (ps.empty()) return {};
        sort(begin(ps), end(ps), [&](int i, int j){
            return hld.in[i] < hld.in[j]; });
        for (int i = 0, ps_size = ps.size(); i < ps_size - 1; i++) {
            ps.push_back(hld.lca(ps[i], ps[i + 1]));
        }
        sort(begin(ps), end(ps), [&](int i, int j){
            return hld.in[i] < hld.in[j]; });
        ps.erase(unique(begin(ps), end(ps)), end(ps));

        vector<vector<int>> aux(ps.size());
        stack<int> st;
        st.emplace(0);
        for (int i = 1; i < (int)ps.size(); i++) {
            int l = hld.lca(ps[i], ps[st.top()]);
            while (ps[st.top()] != l) st.pop();
            aux[st.top()].emplace_back(i);
            st.emplace(i);
        }
        return make_pair(aux, ps);
    }
}; 

#endif // GRAPH_TREE_AUXILIARY_TREE_HPP
