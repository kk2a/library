#ifndef GRAPH_WARSHALL_FLOYD_HPP
#define GRAPH_WARSHALL_FLOYD_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

namespace kk2 {

namespace shortest_path_impl {

template <typename T> struct edge {
    T len;
    bool is_valid;
};

template <typename WG, typename T = typename WG::value_type>
std::vector<std::vector<edge<T>>> warshall_froyd(const WG &g) {
    static_assert(WG::weighted::value, "warshall_froyd requires weighted graph");
    static_assert(WG::adjacency_matrix::value, "warshall_froyd requires adjacency matrix");

    int n = g.size();
    std::vector<std::vector<edge<T>>> res(n, std::vector<edge<T>>(n, {0, false}));
    for (int i = 0; i < n; ++i) res[i][i] = {0, true};
    for (auto &&e : g.edges) {
        {
            auto &[len, valid] = res[e.from][e.to];
            if (valid) len = std::min(len, e.cost);
            else {
                len = e.cost;
                valid = true;
            }
        }
        if constexpr (!WG::directed::value) {
            auto &[len, valid] = res[e.to][e.from];
            if (valid) len = std::min(len, e.cost);
            else {
                len = e.cost;
                valid = true;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!res[i][k].is_valid or !res[k][j].is_valid) continue;
                if (res[i][j].is_valid)
                    res[i][j].len = std::min(res[i][j].len, res[i][k].len + res[k][j].len);
                else {
                    res[i][j].len = res[i][k].len + res[k][j].len;
                    res[i][j].is_valid = true;
                }
            }
        }
    }

    return res;
}

} // namespace shortest_path_impl

using shortest_path_impl::warshall_froyd;

} // namespace kk2

#endif // GRAPH_WARSHALL_FLOYD_HPP
