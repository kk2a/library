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
    cin >> f;
    cout << f.pow(m) << endl;

    return 0;
}