#ifndef KK2_GRAPH_ENUMERATE_TRIANGLE_HPP
#define KK2_GRAPH_ENUMERATE_TRIANGLE_HPP 1

#include <utility>
#include <vector>

namespace kk2 {

template <class G, class H, class F> void enumerate_triangle(const G &g, const F &f) {
    static_assert(!G::directed, "enumerate_triangle requires undirected graph");
    static_assert(H::directed, "enumerate_triangle requires directed graph");

    H h(g.num_vertices());
    for (auto &&e : g.edges) {
        int u = e.from, v = e.to;
        if ((g[u].size() == g[v].size() and u > v) or g[u].size() > g[v].size()) std::swap(u, v);
        h.add_edge(u, v);
    }
    if constexpr (H::static_graph) h.build();
    std::vector<int> buf(g.num_vertices(), -1);
    for (int i = 0; i < g.num_vertices(); i++) {
        for (auto &&e1 : h[i]) buf[e1.to] = i;
        for (auto &&e1 : h[i])
            for (auto &&e2 : h[e1.to])
                if (buf[e2.to] == i) f(i, e1.to, e2.to);
    }
}

} // namespace kk2

#endif // KK2_GRAPH_ENUMERATE_TRIANGLE_HPP
