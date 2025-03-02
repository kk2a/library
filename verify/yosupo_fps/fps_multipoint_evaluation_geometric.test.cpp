#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../fps/chirp_Z.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n, m;
    kk2::mont998 a, r;
    kin >> n >> m >> a >> r;
    FPS f(n);
    kin >> f;
    kout << kk2::ChirpZ(f, r, m, a) << kendl;

    return 0;
}
