#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series" 

#include "../../fps/ntt_friendly.hpp"
#include "../../fps/fps_sqrt.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    FPS f(n);
    FPS res = kk2::sqrt(f.input(kin));
    if (res.empty()) {
        kout << -1 << '\n';
    } else {
        res.output(kout);
    }

    return 0;
}
