#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../data_structure/binary_indexed_tree.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    kk2::BinaryIndexedTree<i64> bit(n);
    rep (i, n) {
        i64 a;
        kin >> a;
        bit.add(i, a);
    }

    rep (q) {
        int t;
        kin >> t;
        if (t == 0) {
            int p, x;
            kin >> p >> x;
            bit.add(p, x);
        }
        if (t == 1) {
            int l, r;
            kin >> l >> r;
            kout << bit.sum(l, r) << "\n";
        }
    }

    return 0;
}
