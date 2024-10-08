#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n;
    cin >> n;
    FPS f(n);
    f.input(cin).inv().output(cout);

    return 0;
}
