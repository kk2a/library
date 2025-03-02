#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_polynomials" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/poly_gcd.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n, m;
    kin >> n >> m;
    FPS f(n), g(m);
    kin >> f >> g;
    if (const auto [ok, h] = kk2::poly_inv(f, g); ok) {
        kout << h.size() << kendl;
        kout << h << kendl;
    } else {
        kout << -1 << kendl;
    }

    return 0;
}
