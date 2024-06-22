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

template <class T>
struct WeightedGraph : vector<Edges<T>> {
    WeightedGraph(int n_ = 0) :
                  vector<Edges<T>>(n_), n(n_), m(0),
                  is_one_indexed(true),
                  is_directed(false) {}

    WeightedGraph(int n_, int m_, bool is_one_indexed_ = true,
                  bool is_directed_ = false) :
                  vector<Edges<T>>(n_), n(n_), m(m_),
                  is_one_indexed(is_one_indexed_),
                  is_directed(is_directed_) {
        input();
    }

    WeightedGraph(int n_, vector<Edges<T>> g_,
                  bool is_one_indexed_ = true,
                  bool is_directed_ = false) :
                  vector<Edges<T>>(n_), n(n_), m(0),
                  is_one_indexed(is_one_indexed_),
                  is_directed(is_directed_) {
        for (int i = 0; i < n; i++) {
            for (auto &e : g_[i]) {
                _add_edge(i, e.to, e.cost, m++);
            }
        }
    }

    int n, m;
    Edges<T> edges;
    bool is_one_indexed, is_directed;

    void one_indexed() { is_one_indexed = true; }
    void zero_indexed() { is_one_indexed = false; }
    void directed() { is_directed = true; }
    void undirected() { is_directed = false; }

    int num_vertices() const { return n; }
    int num_edges() const { return m; }

    void clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    WeightedGraph inplace_rev() {
        assert(is_directed);
        Edges<T> rev(m);
        for (int i = 0; i < m; i++) {
            rev[i] = edges[i].rev();
        }
        clear();
        for (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);
        return *this;
    }

    WeightedGraph rev() const {
        assert(is_directed);
        WeightedGraph res(n);
        res.is_directed = is_directed;
        res.is_one_indexed = is_one_indexed;
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

  private:
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from].emplace_back(to, cost, from, id);
        if (!is_directed) (*this)[to].emplace_back(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }
};
template <class T>
using WGraph = WeightedGraph<T>;

struct UnWeightedGraph : vector<Edges<bool>> {
    UnWeightedGraph(int n_ = 0) :
                    vector<Edges<bool>>(n_), n(n_), m(0),
                    is_one_indexed(true),
                    is_directed(false),
                    is_functional(false) {}

    UnWeightedGraph(int n_, int m_, bool is_one_indexed_ = true,
                    bool is_directed_ = false,
                    bool is_functional_ = false) :
                    vector<Edges<bool>>(n_), n(n_), m(m_),
                    is_one_indexed(is_one_indexed_),
                    is_directed(is_directed_),
                    is_functional(is_functional_) {
        input();
    }

    UnWeightedGraph(int n_, vector<Edges<bool>> g_,
                    bool is_one_indexed_ = true,
                    bool is_directed_ = false,
                    bool is_functional_ = false) :
                    vector<Edges<bool>>(n_), n(n_), m(0),
                    is_one_indexed(is_one_indexed_),
                    is_directed(is_directed_),
                    is_functional(is_functional_) {
        for (int i = 0; i < n; i++) {
            for (auto &e : g_[i]) {
                _add_edge(i, e.to, m++);
            }
        }
    }

    int n, m;
    Edges<bool> edges;
    bool is_one_indexed, is_directed, is_functional;

    void one_indexed() { is_one_indexed = true; }
    void zero_indexed() { is_one_indexed = false; }
    void directed() { is_directed = true; }
    void undirected() { is_directed = false; }
    void functional() { is_functional = true; }
    void non_functional() { is_functional = false; }

    int num_vertices() const { return n; }
    int num_edges() const { return m; }

    void clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    UnWeightedGraph inplace_rev() {
        assert(is_directed);
        vector<pair<int, int>> rev(m);
        for (int i = 0; i < m; i++) {
            rev[i] = {edges[i].to, edges[i].from};
        }
        clear();
        for (auto &&[u, v] : rev) _add_edge(u, v, m++);
        return *this;
    }

    UnWeightedGraph rev() const {
        assert(is_directed);
        UnWeightedGraph res(n);
        res.is_directed = is_directed;
        res.is_one_indexed = is_one_indexed;
        res.is_functional = is_functional;
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
        assert(is_directed);
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

  private:
    void _add_edge(int from, int to, int id) {
        (*this)[from].emplace_back(to, 0, from, id);
        if (!is_directed) (*this)[to].emplace_back(from, 0, to, id);
        edges.emplace_back(to, 0, from, id);
    }
};
using Graph = UnWeightedGraph;


#endif // GRAPH_GRAPH_TEMPLATE_HPP
