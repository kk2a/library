#define PROBLEM "https://judge.yosupo.jp/problem/conversion_from_monomial_basis_to_newton_basis" 

#include "../../fps/ntt_friendly.hpp"
#include "../../fps/poly_to_newton_basis.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    FPS f(n);
    vc<kk2::mont998> p(n);
    kin >> f >> p;
    kout << kk2::convert_to_newton_basis(f, p) << kendl;

    return 0;
}
