#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/compositional_inv.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    FPS f(n);
    f.input(kin);
    kk2::compositional_inv(f).output(kout);

    return 0;
}
