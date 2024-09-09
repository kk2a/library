#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"

using mint = kk2::Mont<mod>;
using FPS = kk2::FormalPowerSeries<mint>;

int main() {
    int n;
    cin >> n;
    FPS f(n);
    rep (i, n) cin >> f[i];
    auto g = f.exp();
    for (auto v : g) cout << v << " ";
    cout << endl;

    return 0;
}