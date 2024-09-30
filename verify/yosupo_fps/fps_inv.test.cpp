#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

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
    auto g = f.inv();
    rep (i, g.size()) cout << g[i] << " \n"[i == g.size() - 1];

    return 0;
}