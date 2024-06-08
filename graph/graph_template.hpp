#ifndef GRAPH_GRAPH_TEMPLATE_HPP
#define GRAPH_GRAPH_TEMPLATE_HPP 1


template <class T>
struct Edge {
    int from, to, id;
    T cost;

    Edge(int to_, T cost_, int from_ = -1, int id_ = -1) :
        from(from_), to(to_), id(id_), cost(cost_) {}

    Edge& operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};
template <class T>
using Edges = vector<Edge<T>>;

template <class T>
struct WeightedGraph : vector<Edges<T>> {
    int n, m;
    bool is_one_indexed, is_directed;
    Edges<T> edges;
    WeightedGraph(int n_ = 0) : n(n_), vector<Edges<T>>(n_) {}
    WeightedGraph(int n_, int m_, bool is_one_indexed_ = true,
                  bool is_directed_ = false) :
                  n(n_), m(m_), vector<Edges<T>>(n_),
                  is_one_indexed(is_one_indexed_),
                  is_directed(is_directed_) {
        edges.reserve(m);
        input();
    }
    WeightedGraph(int n_, vector<Edges<T>> g_,
                  bool is_one_indexed_ = true,
                  bool is_directed_ = false) :
                  n(n_), m(0), vector<Edges<T>>(n_),
                  is_one_indexed(is_one_indexed_),
                  is_directed(is_directed_) {
        for (int i = 0; i < n; i++) {
            for (auto &e : g_[i]) {
                _add_edge(i, e.to, e.cost, m++);
            }
        }
    }

    void one_indexed() { is_one_indexed = true; }
    void zero_indexed() { is_one_indexed = false; }
    void directed() { is_directed = true; }
    void undirected() { is_directed = false; }

    void input() {
        for (int i = 0; i < m; i++) {
            int u, v;
            T w;
            cin >> u >> v >> w;
            if (is_one_indexed) { u--; v--; }
            _add_edge(u, v, w, i);
        }
    }

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
    int n, m;
    bool is_one_indexed, is_directed;
    Edges<bool> edges;
    UnWeightedGraph(int n_ = 0) : n(n_) {
        this->resize(n);
    }
    UnWeightedGraph(int n_, int m_, bool is_one_indexed_ = true,
                    bool is_directed_ = false) :
                    n(n_), m(m_), vector<Edges<bool>>(n_),
                    is_one_indexed(is_one_indexed_),
                    is_directed(is_directed_) {
        input();
    }
    UnWeightedGraph(int n_, vector<Edges<bool>> g_,
                    bool is_one_indexed_ = true,
                    bool is_directed_ = false) :
                    n(n_), m(0), vector<Edges<bool>>(n_),
                    is_one_indexed(is_one_indexed_),
                    is_directed(is_directed_) {
        for (int i = 0; i < n; i++) {
            for (auto &e : g_[i]) {
                _add_edge(i, e.to, m++);
            }
        }
    }


    void one_indexed() { is_one_indexed = true; }
    void zero_indexed() { is_one_indexed = false; }
    void directed() { is_directed = true; }
    void undirected() { is_directed = false; }

    void input() {
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (is_one_indexed) { u--; v--; }
            _add_edge(u, v, i);
        }
    }

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
