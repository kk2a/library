#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind" 

#include "../../unionfind/parallel.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using mint = kk2::mont998;
    int n, q;
    kin >> n >> q;
    vc<mint> x(n);
    kin >> x;
    kk2::ParallelUnionFind uf(n);
    mint now = 0;
    auto f = [&](int l, int r) {
        now += x[l] * x[r];
        x[l] += x[r];
    };

    rep (q) {
        int k, a, b;
        kin >> k >> a >> b;
        uf.unite(a, b, k, f);
        kout << now << "\n";
    }

    return 0;
}
