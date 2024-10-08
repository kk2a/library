#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n;
    i64 m;
    cin >> n >> m;
    FPS f(n);
    f.input(cin).pow(m).output(cout);

    return 0;
}
