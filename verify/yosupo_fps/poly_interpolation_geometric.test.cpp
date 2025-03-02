#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/poly_interpolation.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kk2::mont998 a, r;
    kin >> n >> a >> r;
    vc<kk2::mont998> y(n);
    kin >> y;
    kout << kk2::poly_interpolation_geo<FPS>(a, r, y) << kendl;

    return 0;
}
