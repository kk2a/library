#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n;
    cin >> n;
    FPS f(n);
    rep (i, n) cin >> f[i];
    auto g = f.exp();
    rep (i, g.size()) cout << g[i] << " \n"[i == n - 1];

    return 0;
}