#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../data_structure/prefix_sum.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vc<i64> a(n);
    cin >> a;
    kk2::PrefixSum<i64> ps(a);

    rep (q) {
        int l, r;
        cin >> l >> r;
        cout << ps.sum(l, r) << "\n";
    }

    return 0;
}
