#ifndef KK2_GRAPH_CYCLE_DETECTION_HPP
#define KK2_GRAPH_CYCLE_DETECTION_HPP 1

#include <algorithm>
#include <optional>
#include <type_traits>
#include <vector>

namespace kk2 {

namespace cycle_detection_impl {

struct result {
    std::vector<int> edges;
    std::vector<int> vertices;

    int size() const { return edges.size(); }
};

template <class G, std::enable_if_t<!G::directed::value> * = nullptr>
std::optional<result> cycle_detection(const G &g) {
    std::vector<int> edges, vertices;
    std::vector<int> buf(g.num_vertices(), -1);
    auto dfs = [&](auto self, int now, int ei, int dep) -> int {
        buf[now] = dep;
        for (auto &&e : g[now]) {
            if (e.id == ei) continue;
            if (buf[e.to] >= 0) {
                edges.resize(dep - buf[e.to] + 1);
                vertices.resize(dep - buf[e.to] + 1);
                edges.back() = e.id;
                vertices.back() = now;
                return buf[e.to];
            }

            int r = self(self, e.to, e.id, dep + 1);
            if (r >= 0) {
                if (dep < r) return r;
                edges[dep - r] = e.id;
                vertices[dep - r] = now;
                return r;
            }
        }

        return -1;
    };

    for (int i = 0; i < g.num_vertices(); ++i) {
        if (buf[i] != -1) continue;
        if (dfs(dfs, i, -1, 0) >= 0) return result{edges, vertices};
    }

    return {};
}

template <class G, std::enable_if_t<G::directed::value> * = nullptr>
std::optional<result> cycle_detection(const G &g) {
    std::vector<int> edges, vertices;

    // buf[i] = x
    // x >= 0 : 今見られている頂点dfsの深さはx
    // x = -1 : 未訪問
    // x = -2 : 訪問済み．閉路に含まれない
    std::vector<int> buf(g.num_vertices(), -1);

    // 返り値 x
    // x = -1 : 閉路なし
    // x >= 0 : 閉路あり，かつ，その閉路の始点の深さ
    auto dfs = [&](auto self, int now, int dep) -> int {
        buf[now] = dep;
        for (auto &&e : g[now]) {
            if (buf[e.to] == -2) continue;
            if (buf[e.to] >= 0) {
                edges.resize(dep - buf[e.to] + 1);
                vertices.resize(dep - buf[e.to] + 1);
                edges.back() = e.id;
                vertices.back() = now;
                return buf[e.to];
            }

            int r = self(self, e.to, dep + 1);
            if (r >= 0) {
                if (dep < r) return r;
                edges[dep - r] = e.id;
                vertices[dep - r] = now;
                return r;
            }
        }
        buf[now] = -2;
        return -1;
    };

    for (int i = 0; i < g.num_vertices(); ++i) {
        if (buf[i] == -2) continue;
        if (dfs(dfs, i, 0) >= 0) return result{edges, vertices};
    }

    return {};
}

} // namespace cycle_detection_impl

using cycle_detection_impl::cycle_detection;

} // namespace kk2

#endif // KK2_GRAPH_CYCLE_DETECTION_HPP
