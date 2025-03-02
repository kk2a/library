#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../fps/fps_arb.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSArb<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    FPS f(n);
    f.input(kin).inv().output(kout);

    return 0;
}
