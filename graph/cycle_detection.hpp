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
    edges.reserve(g.num_vertices());
    vertices.reserve(g.num_vertices());
    std::vector<bool> used(g.num_vertices());
    auto dfs = [&](auto self, int now, int ei) -> bool {
        for (auto &&e : g[now]) {
            if (e.id == ei) continue;
            if (used[e.to]) {
                edges.emplace_back(e.id);
                int idx = std::find(vertices.begin(), vertices.end(), e.to) - vertices.begin();
                vertices = std::vector<int>(vertices.begin() + idx, vertices.end());
                edges = std::vector<int>(edges.begin() + idx, edges.end());
                return true;
            }

            vertices.emplace_back(e.to);
            edges.emplace_back(e.id);
            used[e.to] = true;

            if (self(self, e.to, e.id)) return true;

            vertices.pop_back();
            edges.pop_back();
        }
        return false;
    };

    for (int i = 0; i < g.num_vertices(); ++i) {
        if (used[i]) continue;
        vertices.emplace_back(i);
        if (dfs(dfs, i, -1)) return result{edges, vertices};
        vertices.pop_back();
    }

    return {};
}

template <class G, std::enable_if_t<G::directed()> * = nullptr>
std::optional<result> cycle_detection(const G &g) {
    std::vector<int> edges;
    std::vector<int> vertices;
    std::vector<bool> used(g.num_vertices()), now_use(g.num_vertices());
    edges.reserve(g.num_vertices());
    vertices.reserve(g.num_vertices());

    auto dfs = [&](auto self, int now) -> bool {
        used[now] = true;
        for (auto &&e : g[now]) {
            if (used[e.to]) {
                if (!now_use[e.to]) return false;
                edges.emplace_back(e.id);
                int idx = std::find(vertices.begin(), vertices.end(), e.to) - vertices.begin();
                vertices = std::vector<int>(vertices.begin() + idx, vertices.end());
                edges = std::vector<int>(edges.begin() + idx, edges.end());
                return true;
            }

            vertices.emplace_back(e.to);
            edges.emplace_back(e.id);
            used[e.to] = true;
            now_use[e.to] = true;

            if (self(self, e.to)) return true;

            vertices.pop_back();
            edges.pop_back();
            now_use[e.to] = false;
        }
        return false;
    };

    for (int i = 0; i < g.num_vertices(); ++i) {
        if (used[i]) continue;
        vertices.emplace_back(i);
        now_use[i] = true;
        if (dfs(dfs, i)) return result{edges, vertices};
        vertices.pop_back();
        now_use[i] = false;
    }

    return {};
}

} // namespace cycle_detection_impl

using cycle_detection_impl::cycle_detection;

} // namespace kk2

#endif // KK2_GRAPH_CYCLE_DETECTION_HPP
