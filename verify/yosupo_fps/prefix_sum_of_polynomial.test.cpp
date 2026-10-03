// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/prefix_sum_of_polynomial

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/power_sum.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"

int main() {
    using FPS = kk2::FPSNTT<kk2::mont998>;

    int n;
    kin >> n;
    FPS f(n);
    kin >> f;
    kout << kk2::prefix_sum_of_polynomial(f) << kendl;
    return 0;
}
