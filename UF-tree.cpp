struct UnionFind {
    vector<int> d;
    UnionFind(int n = 0) : d(n, -1) {}
    bool same(int x, int y) { return find(x) == find(y); }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
    }
    int find(int x) {
        if (d[x] < 0) return x; 
        return d[x] = find(d[x]);
    }
    int size(int x) { return -d[find(x)]; }
};

struct UnionFind_rollback {
    vector<int> d;
    vector<pair<int, int>> hist;
    vector<int> snaps;
    UnionFind_rollback(int n = 0) : d(n, -1) {}
    bool same(int x, int y) { return find(x) == find(y); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        hist.emplace_back(x, d[x]); d[x] += d[y];
        hist.emplace_back(y ,d[y]); d[y] = x;
        return true;
    }
    int find(int x) {
        if (d[x] < 0) return x; 
        return find(d[x]);
    }
    int treesize(int x) { return -d[find(x)]; }

    void snapshot() {
        snaps.push_back(size(hist));
    }
    void rollback() {
        while (int(size(hist)) > snaps.back()) {
            auto [i, x] = hist.back(); hist.pop_back();
            d[i] = x;
        }
        snaps.pop_back();
    }
};

// A is an abelian group
template <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)>
struct UnionFind_weight {
  private:
    vector<int> d;
    vector<A> diff_weight;
  public:
    UnionFind_weight(int n = 0) : d(n, -1), diff_weight(n, e()) {}
    bool unite(int x, int y, A w) {
        w = op(w, op(weight(x), inv(weight(y))));
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) { swap(x, y); w = inv(w); }
        d[x] += d[y];
        d[y] = x;
        diff_weight[y] = w;
        return true;
    }
    int find(int x) {
        if (d[x] < 0) return x;
        int r = find(d[x]);
        diff_weight[x] = op(diff_weight[x], diff_weight[d[x]]);
        return d[x] = r;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }

    A weight(int x) {
        find(x);
        return diff_weight[x];
    }
    A diff(int a, int b) {
        return op(inv(weight(a)), weight(b));
    }
};


int main() {
    
    return 0;
}