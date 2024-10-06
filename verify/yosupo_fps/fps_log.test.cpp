#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n;
    cin >> n;
    FPS f(n);
    cin >> f;
    cout << f.log() << endl;

    return 0;
}
