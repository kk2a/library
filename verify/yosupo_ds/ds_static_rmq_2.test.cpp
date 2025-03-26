#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../data_structure/disjoint_sparse_table.hpp"
#include "../../math/monoid/min.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using M = kk2::monoid::Min<int>;
    int n, q;
    kin >> n >> q;
    vc<M> a(n);
    kin >> a;
    kk2::DisjointSparseTableS<M> dst(a);

    rep (q) {
        int l, r;
        kin >> l >> r;
        kout << dst.prod(l, r) << "\n";
    }

    return 0;
}
