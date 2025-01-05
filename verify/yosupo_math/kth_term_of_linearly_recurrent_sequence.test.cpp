#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence" 

#include "../../fps/ntt_friendly.hpp"
#include "../../fps/bostan_mori.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int d;
    i64 k;
    kin >> d >> k;
    FPS a(d), c(d);
    kin >> a >> c;
    kout << kk2::kth_term_of_linearly_recurrent_sequence(a, c, k) << kendl;

    return 0;
}
