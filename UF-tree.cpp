struct UnionFind {
    vector<int> size, parents;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        size.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        size[x] = 1;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return;
        if (size[x] > size[y]) {
            parents[y] = x;
            size[x] += size[y];
        } else {
            parents[x] = y;
            size[y] += size[x];
        }
    }
    int findRoot(int x) {
        if (x != parents[x]) {
            parents[x] = findRoot(parents[x]);
        }
        return parents[x];
    }
    int treeSize(int x) { return size[findRoot(x)]; }
};

struct UnionFind_2D {
    using pi = pair<int, int>;
    vector<vector<int>> siz;
    vector<vector<pi>> parents;

    UnionFind_2D() {}
    UnionFind_2D(int h, int w) {
        siz.resize(h, vector<int>(w, 0));
        parents.resize(h, vector<pi>(w, {0, 0}));
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
            makeTree( {i, j} );
        }
    }
    void makeTree(pi x) {
        parents[x.first][x.second] = x;
        siz[x.first][x.second] = 1;
    }
    bool is_same(pi x, pi y) { return findroot(x) == findroot(y); }

    void unite(pi x, pi y) {
        x = findroot(x);
        y = findroot(y);
        if (x == y) return;
        else if (siz[x.first][x.second] > siz[y.first][y.second]) {
            parents[y.first][y.second] = x;
            siz[x.first][x.second] += siz[y.first][y.second];
        }
        else {
            parents[x.first][x.second] = y;
            siz[y.first][y.second] += siz[x.first][x.second];
        }
    }

    pi findroot(pi x) {
        if (x != parents[x.first][x.second]) {
            parents[x.first][x.second] = findroot(parents[x.first][x.second]);
        }
        return parents[x.first][x.second];
    }
    int treesize(pi x) {
        pi tmp = findroot(x);
        return siz[tmp.first][tmp.second];
    }
};


int main() {
    
    return 0;
}