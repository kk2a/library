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

template <class G, std::enable_if_t<!G::directed()> * = nullptr>
std::optional<result> cycle_detection(const G &g) {
    std::vector<int> edges;
    std::vector<int> vertices;
    std::vector<bool> used(g.num_vertices());
    edges.resize(g.num_vertices());
    vertices.resize(g.num_vertices());
    auto dfs = [&](auto self, int now, int ei, int idx) -> bool {
        used[now] = true;
        vertices[idx] = now;
        for (auto &&e : g[now]) {
            if (e.id == ei) continue;
            edges[idx] = e.id;
            if (used[e.to]) {
                int start = std::find(vertices.begin(), vertices.end(), e.to) - vertices.begin();
                vertices = std::vector<int>(vertices.begin() + start, vertices.begin() + idx + 1);
                edges = std::vector<int>(edges.begin() + start, edges.begin() + idx + 1);
                return true;
            }

            if (self(self, e.to, e.id, idx + 1)) return true;
        }
        return false;
    };

    for (int i = 0; i < g.num_vertices(); ++i) {
        if (used[i]) continue;
        if (dfs(dfs, i, -1, 0)) return result{edges, vertices};
    }

    return {};
}

template <class G, std::enable_if_t<G::directed()> * = nullptr>
std::optional<result> cycle_detection(const G &g) {
    std::vector<int> edges;
    std::vector<int> vertices;
    // bad[i] が true なら i は閉路に含まれない
    std::vector<bool> bad(g.num_vertices()), now_use(g.num_vertices());
    edges.resize(g.num_vertices());
    vertices.resize(g.num_vertices());

    auto dfs = [&](auto self, int now, int idx) -> bool {
        now_use[now] = true;
        vertices[idx] = now;
        for (auto &&e : g[now]) {
            if (bad[e.to]) continue;
            edges[idx] = e.id;
            if (now_use[e.to]) {
                int start = std::find(vertices.begin(), vertices.end(), e.to) - vertices.begin();
                vertices = std::vector<int>(vertices.begin() + start, vertices.begin() + idx + 1);
                edges = std::vector<int>(edges.begin() + start, edges.begin() + idx + 1);
                return true;
            }
            if (self(self, e.to, idx + 1)) return true;
        }
        now_use[now] = false;
        bad[now] = true;
        return false;
    };

    for (int i = 0; i < g.num_vertices(); ++i) {
        if (bad[i]) continue;
        if (dfs(dfs, i, 0)) return result{edges, vertices};
    }

    return {};
}

} // namespace cycle_detection_impl

using cycle_detection_impl::cycle_detection;

} // namespace kk2

#endif // KK2_GRAPH_CYCLE_DETECTION_HPP
