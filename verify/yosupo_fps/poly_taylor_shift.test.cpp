#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/poly_taylor_shift.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kk2::mont998 c;
    kin >> n >> c;
    FPS f(n);
    kin >> f;
    kout << kk2::taylor_shift(f, c) << kendl;

    return 0;
}
