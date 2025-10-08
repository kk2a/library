#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles" 

#include "../../graph/static_graph.hpp"
#include "../../graph/enumerate_triangle.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using mint = kk2::mont998;

    int n, m;
    kin >> n >> m;
    vc<mint> x(n);
    kin >> x;
    kk2::SAdjList g(n, m);
    g.input(kin);
    mint res = 0;
    kk2::enumerate_triangle<kk2::SAdjList, kk2::SDAdjList>(g, [&](int u, int v, int w) {
        res += x[u] * x[v] * x[w];
    });
    kout << res << kendl;

    return 0;
}
