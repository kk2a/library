#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../data_structure/prefix_sum.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<i64> a(n);
    kin >> a;
    kk2::PrefixSum<i64> ps(a);

    rep (q) {
        int l, r;
        kin >> l >> r;
        kout << ps.sum(l, r) << "\n";
    }

    return 0;
}
