#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    i64 m;
    kin >> n >> m;
    FPS f(n);
    f.input(kin).pow(m).output(kout);

    return 0;
}
