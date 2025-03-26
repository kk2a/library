#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../data_structure/static_rmq.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    kk2::StaticRMQ<int> rmq(n);
    rep (i, n) {
        int a;
        kin >> a;
        rmq.init_set(i, a);
    }
    rmq.build();

    rep (q) {
        int l, r;
        kin >> l >> r;
        kout << rmq.prod(l, r) << "\n";
    }

    return 0;
}
