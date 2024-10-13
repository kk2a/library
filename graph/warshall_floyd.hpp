#ifndef GRAPH_WARSHALL_FLOYD_HPP
#define GRAPH_WARSHALL_FLOYD_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

namespace kk2 {

namespace shortest_path {

template <typename T> struct edge {
    T len;
    bool is_valid;
};

template <typename WG, typename T = typename WG::value_type>
std::vector<std::vector<edge<T>>> WarshallFroyd(const WG &g) {
    int n = g.size();
    std::vector<std::vector<edge<T>>> res(n, std::vector<edge<T>>(n, {0, false}));
    for (int i = 0; i < n; ++i) res[i][i] = {0, true};
    for (auto &&e : g.edges) {
        res[e.from][e.to] = {e.cost, true};
        if constexpr (!WG::directed()) res[e.to][e.from] = {e.cost, true};
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

} // namespace shortest_path

using shortest_path::WarshallFroyd;

} // namespace kk2

#endif // GRAPH_WARSHALL_FLOYD_HPP
