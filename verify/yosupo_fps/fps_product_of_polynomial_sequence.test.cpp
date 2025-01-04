#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence" 

#include "../../fps/ntt_friendly.hpp"
#include "../../fps/product.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    vc<FPS> a(n);
    rep (i, n) {
        int d;
        kin >> d;
        a[i].resize(d + 1);
        kin >> a[i];
    }
    kout << kk2::all_prod(a) << kendl;

    return 0;
}
