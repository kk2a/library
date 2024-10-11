#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../data_structure/static_rmq.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    auto a = kk2::GetVecMin<int>(n);
    cin >> a;
    kk2::StaticRMQ<int> rmq(a);

    rep (q) {
        int l, r;
        cin >> l >> r;
        cout << rmq.prod(l, r) << "\n";
    }

    return 0;
}
