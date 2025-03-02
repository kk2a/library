#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/poly_multi_eval.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n, m;
    kin >> n >> m;
    FPS f(n);
    vc<kk2::mont998> p(m);
    kin >> f >> p;
    kout << kk2::MultiEval(p, f) << kendl;

    return 0;
}
