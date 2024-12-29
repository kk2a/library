#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse" 

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n, k;
    i64 m;
    kin >> n >> k >> m;
    FPS f(n);
    rep (k) {
        int i;
        kk2::mont998 a;
        kin >> i >> a;
        f[i] = a;
    }
    f.sparse_pow(m).output(kout);

    return 0;
}
