#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/composition.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    FPS f(n), g(n);
    f.input(kin), g.input(kin);
    kk2::composition(g, f).output(kout);
    return 0;
}
