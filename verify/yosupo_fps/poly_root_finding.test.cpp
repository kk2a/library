#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_root_finding" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/poly_find_root.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    FPS f(n + 1);
    kin >> f;
    auto res = kk2::find_root(f);
    kout << res.size() << kendl;
    kout << res << kendl;

    return 0;
}
