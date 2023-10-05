#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

# define rep(i, k, l) for (i64 i = (k); i < (l); ++i)
# define repi(i, k, l) for (i64 i = (k); i >= (l); --i)

constexpr i64 mod = 998244353;
constexpr i64 inf_64 = 3343343343343343343;
constexpr int inf_32 = 1334334334;

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


int main() {
    
    return 0;
}