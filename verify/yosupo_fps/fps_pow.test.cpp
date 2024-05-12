#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../template/template.hpp"
#include "../../modint/mont.hpp"
#include "../../fps/ntt_friendly.hpp"

using mint = Mont<mod>;
using FPS = FormalPowerSeries<mint>;

int main () {
    int n;
    long long m;
    cin >> n >> m;
    FPS f(n);
    rep (i, n) cin >> f[i];
    auto g = f.pow(m);
    for (auto v : g) cout << v << " ";
    cout << endl;

    return 0;
}