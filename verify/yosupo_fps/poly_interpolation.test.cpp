#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/poly_interpolation.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    vc<kk2::mont998> x(n), y(n);
    kin >> x >> y;
    kout << kk2::poly_interpolation<FPS>(x, y) << kendl;

    return 0;
}
