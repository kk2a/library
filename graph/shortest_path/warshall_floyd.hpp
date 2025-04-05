#ifndef KK2_GRAPH_WARSHALL_FLOYD_HPP
#define KK2_GRAPH_WARSHALL_FLOYD_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace shortest_path_impl {

template <typename T>
struct wf_len {
    T len;
    bool inf, minf;

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        if (minf) os << "MINF";
        else if (inf) os << "INF";
        else os << len;
    }
};

template <typename WG, typename T = typename WG::value_type>
std::vector<std::vector<wf_len<T>>> warshall_froyd(const WG &g) {
    static_assert(WG::weighted, "warshall_froyd requires weighted graph");

    int n = g.size();
    std::vector<std::vector<wf_len<T>>> res(n, std::vector<wf_len<T>>(n, {0, true, false}));
    for (int i = 0; i < n; ++i) res[i][i] = {0, false, false};
    for (auto &&e : g.edges) {
        {
            auto &[len, inf, minf] = res[e.from][e.to];
            if (inf or len > e.cost) {
                len = e.cost;
                inf = false;
            }
        }
        if constexpr (!WG::directed) {
            auto &[len, inf, minf] = res[e.to][e.from];
            if (inf or len > e.cost) {
                len = e.cost;
                inf = false;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (res[i][k].inf or res[k][j].inf) continue;
                if (res[i][j].inf or res[i][j].len > res[i][k].len + res[k][j].len) {
                    res[i][j].len = res[i][k].len + res[k][j].len;
                    res[i][j].inf = false;
                }
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        if (res[k][k].len >= 0) continue;
        res[k][k].minf = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (res[i][k].inf or res[k][j].inf) continue;
                res[i][j].minf = true;
            }
        }
    }

    return res;
}

} // namespace shortest_path_impl

using shortest_path_impl::warshall_froyd;

} // namespace kk2

#endif // KK2_GRAPH_WARSHALL_FLOYD_HPP
