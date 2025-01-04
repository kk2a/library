#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial" 

#include "../../fps/ntt_friendly.hpp"
#include "../../fps/poly_sample_point_shift.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n, m;
    kk2::mont998 c;
    kin >> n >> m >> c;
    vc<kk2::mont998> a(n);
    kin >> a;
    kout << kk2::sample_point_shift<FPS>(a, c, m) << kendl;

    return 0;
}
