struct LowLink {
    struct Edge {
        int to, id;
        Edge() {}
        Edge(int to, int id = -1) : to(to), id(id) {}
    };
    int n, m;
    vector<vector<Edge>> g;
    LowLink(int n_) : n(n_), m(0), g(n_) {}

    void add_edge(int a, int b) {
        g[a].emplace_back(b, m);
        g[b].emplace_back(a, m++);
    }

    vector<int> ord, low, par; 
    void init() {
        ord = low = par = vector<int>(n, -1);
        int k = 0;
        auto dfs = [&](auto self, int v, int ei = -1) -> int {
            low[v] = ord[v] = k++;
            for (auto ch : g[v]) {
                if (ch.id == ei) continue;
                if (ord[ch.to] == -1) {
                    par[ch.to] = v;
                    low[v] = min(low[v], self(self, ch.to, ch.id));
                }
                else if (ord[ch.to] < ord[v]) {
                    low[v] = min(low[v], ord[ch.to]);
                }
            }
            return low[v];
        };
        for (int v = 0; v < n; v++) if (ord[v] == -1) dfs(dfs, v);
    }

    vector<vector<int>> bc;
    vector<int> bc_id;
    void bcc() {
        bc_id = vector<int>(m, -1);
        auto add = [&](int ei, int k) {
            bc[k].emplace_back(ei);
            bc_id[ei] = k;
        };
        auto dfs = [&](auto self, int v, int k = -1) -> void {
            for (auto e : g[v]) if (e.to != par[v]) {
                if (par[e.to] == v) {
                    int nk = k;
                    if (low[e.to] >= ord[v]) nk = bc.size(), bc.emplace_back();
                    add(e.id, nk);
                    self(self, e.to, nk);
                }
                else if (ord[e.to] < ord[v]) {
                    add(e.id, k);
                }
            }
        };
        for (int v = 0; v < n; v++) if (par[v] == -1) dfs(dfs, v);
    }
};

