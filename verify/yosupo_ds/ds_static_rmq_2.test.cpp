#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../data_structure/disjoint_sparse_table.hpp"
#include "../../template/template.hpp"
using namespace std;

using S = int;

S op(S a, S b) {
    return min(a, b);
}

S e() {
    return 1e9 + 1;
}

int main() {
    int n, q;
    kin >> n >> q;
    vc<int> a(n);
    kin >> a;
    kk2::DisjointSparseTable<S, op, e> dst(a);

    rep (q) {
        int l, r;
        kin >> l >> r;
        kout << rmq.prod(l, r) << "\n";
    }

    return 0;
}
