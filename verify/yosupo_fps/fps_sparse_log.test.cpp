#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse" 

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n, k;
    kin >> n >> k;
    FPS f(n);
    rep (k) {
        int i;
        kk2::mont998 a;
        kin >> i >> a;
        f[i] = a;
    }
    f.sparse_log().output(kout);

    return 0;
}
