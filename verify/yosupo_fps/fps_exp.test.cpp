#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    FPS f(n);
    f.input(kin).exp().output(kout);

    return 0;
}
