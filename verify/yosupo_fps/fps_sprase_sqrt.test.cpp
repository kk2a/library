#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/fps_sqrt.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

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
    FPS res = kk2::sparse_sqrt(f);
    if (res.empty()) kout << -1 << "\n";
    else res.output(kout);

    return 0;
}
