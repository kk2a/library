#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <"../../template/template.hpp">
#include <"../../modint/mont.hpp">
#include <"../../fps/fps.hpp">
#include <"../../convolution/butterfly.hpp">
#include <"../../convolution/convolution.hpp">
#include <"../../fps/ntt_friendly.hpp">

using mint = Mont<mod>;
using FPS = FormalPowerSeries<mint>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    FPS a(n);
    rep (i, n) cin >> a[i];
    auto b = a.inv();
    rep (i, n) cout << b[i] << " "; cout << endl;
    return 0;
}
