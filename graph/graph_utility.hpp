#ifndef GRAPH_UTILITY_HPP
#define GRAPH_UTILITY_HPP 1

template <class G>
vector<int> get_degree_sequence(const G &g) {
    vector<int> degree(g.num_vertices());
    for (int i = 0; i < g.num_vertices(); i++) {
        degree[i] = g[i].size();
    }
    return degree;
}

#endif // GRAPH_UTILITY_HPP
