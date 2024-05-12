#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../template/template.hpp"
#include "../../modint/mont.hpp"
#include "../../fps/ntt_friendly.hpp"

using mint = Mont<mod>;
using FPS = FormalPowerSeries<mint>;

int main () {
    int n;
    cin >> n;
    FPS f(n);
    rep (i, n) cin >> f[i];
    auto g = f.inv();
    for (auto v : g) cout << v << " ";
    cout << endl;

    return 0;
}