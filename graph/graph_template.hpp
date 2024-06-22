#ifndef GRAPH_GRAPH_TEMPLATE_HPP
#define GRAPH_GRAPH_TEMPLATE_HPP 1


template <class T>
struct Edge {
    int from, to, id;
    T cost;

    Edge(int to_, T cost_, int from_ = -1, int id_ = -1) :
        from(from_), to(to_), id(id_), cost(cost_) {}

    Edge() : from(-1), to(-1), id(-1), cost(0) {}

    Edge& operator=(const Edge &e) {
        from = e.from;
        to = e.to;
        id = e.id;
        cost = e.cost;
        return *this;
    }

    operator int() const { return to; }

    Edge rev() const { return Edge(from, cost, to, id); }

    friend ostream& operator<<(ostream &os, const Edge &e) {
        if (is_same_v<T, bool>) return os << e.from << "->" << e.to;
        return os << e.from << "->" << e.to << ":" << e.cost;
    }
};
template <class T>
using Edges = vector<Edge<T>>;

// template <class T>
// using EdgePtr = shared_ptr<Edge<T>>;

// template <class T>
// inline EdgePtr<T> new_edge(int to = -1, T cost = 0, int from = -1, int id = -1) {
//     return make_shared<Edge<T>>(to, cost, from, id);
// }

template <class T, bool is_one_indexed = true, bool is_directed = false>
struct WeightedGraph : vector<Edges<T>> {
    WeightedGraph(int n_ = 0) :
                  vector<Edges<T>>(n_), n(n_), m(0) {}

    WeightedGraph(int n_, int m_) :
                  vector<Edges<T>>(n_), n(n_), m(m_) { input(); }

    WeightedGraph(int n_, vector<Edges<T>> g_) :
                  vector<Edges<T>>(n_), n(n_), m(0) {
        for (int i = 0; i < n; i++) {
            for (auto &e : g_[i]) {
                _add_edge(i, e.to, e.cost, m++);
            }
        }
    }

    using value_type = T;
    constexpr static bool oneindexed() { return is_one_indexed; }
    constexpr static bool directed() { return is_directed; }

    int n, m;
    Edges<T> edges;

    int num_vertices() const { return n; }
    int num_edges() const { return m; }

    void clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    WeightedGraph inplace_rev() {
        static_assert(is_directed);
        Edges<T> rev(m);
        for (int i = 0; i < m; i++) {
            rev[i] = edges[i].rev();
        }
        clear();
        for (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);
        return *this;
    }

    WeightedGraph rev() const {
        static_assert(is_directed);
        WeightedGraph res(n);
        res.m = m;
        for (int i = 0; i < m; i++) {
            res._add_edge(edges[i].to, edges[i].from, edges[i].cost, i);
        }
        return res;
    }

  private:
    void input() {
        for (int i = 0; i < m; i++) {
            int u, v;
            T w;
            cin >> u >> v >> w;
            if (is_one_indexed) { u--; v--; }
            _add_edge(u, v, w, i);
        }
    }

  public:
    void add_edge(int from, int to, T cost) {
        if (is_one_indexed) { from--; to--; }
        _add_edge(from, to, cost, m++);
    }

    void add_edge_naive(int from, int to, T cost) { _add_edge(from, to, cost, m++); }

  private:
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from].emplace_back(to, cost, from, id);
        if (!is_directed) (*this)[to].emplace_back(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }
};
template <class T, bool is_one_indexed = true, bool is_directed = false>
using WGraph = WeightedGraph<T, is_one_indexed, is_directed>;

template <bool is_one_indexed = true, bool is_directed = false,
          bool is_functional = false>
struct UnWeightedGraph : vector<Edges<bool>> {
    UnWeightedGraph(int n_ = 0) :
                    vector<Edges<bool>>(n_), n(n_), m(0) {}

    UnWeightedGraph(int n_, int m_) :
                    vector<Edges<bool>>(n_), n(n_), m(m_) { input(); }

    UnWeightedGraph(int n_, vector<Edges<bool>> g_) :
                    vector<Edges<bool>>(n_), n(n_), m(0) {
        for (int i = 0; i < n; i++) {
            for (auto &e : g_[i]) {
                _add_edge(i, e.to, m++);
            }
        }
    }

    constexpr static bool oneindexed() { return is_one_indexed; }
    constexpr static bool directed() { return is_directed; }
    constexpr static bool functional() { return is_functional; }

    int n, m;
    Edges<bool> edges;

    int num_vertices() const { return n; }
    int num_edges() const { return m; }

    void clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    UnWeightedGraph inplace_rev() {
        static_assert(is_directed);
        vector<pair<int, int>> rev(m);
        for (int i = 0; i < m; i++) {
            rev[i] = {edges[i].to, edges[i].from};
        }
        clear();
        for (auto &&[u, v] : rev) _add_edge(u, v, m++);
        return *this;
    }

    UnWeightedGraph rev() const {
        static_assert(is_directed);
        UnWeightedGraph res(n);
        res.m = m;
        for (int i = 0; i < m; i++) {
            res._add_edge(edges[i].to, edges[i].from, i);
        }
        return res;
    }

  private:
    void input() {
        if (is_functional) { functional_graph(); return; }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (is_one_indexed) { u--; v--; }
            _add_edge(u, v, i);
        }
    }

    void functional_graph() {
        static_assert(is_directed);
        assert(n == m);
        for (int i = 0; i < n; i++) {
            int u;
            cin >> u;
            if (is_one_indexed) u--;
            _add_edge(i, u, i);
        }
    }

  public:
    void add_edge(int from, int to) {
        if (is_one_indexed) { from--; to--; }
        _add_edge(from, to, m++);
    }

    void add_edge_naive(int from, int to) { _add_edge(from, to, m++); }

  private:
    void _add_edge(int from, int to, int id) {
        (*this)[from].emplace_back(to, 0, from, id);
        if (!is_directed) (*this)[to].emplace_back(from, 0, to, id);
        edges.emplace_back(to, 0, from, id);
    }
};
template <bool is_one_indexed = true, bool is_directed = false,
          bool is_functional = false>
using Graph = UnWeightedGraph<is_one_indexed, is_directed, is_functional>;


#endif // GRAPH_GRAPH_TEMPLATE_HPP
