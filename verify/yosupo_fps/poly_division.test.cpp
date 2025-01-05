#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials" 

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;

int main() {
    int n, m;
    kin >> n >> m;
    FPS f(n), g(m);
    kin >> f >> g;
    FPS q = (f / g).shrink();
    FPS r = (f - q * g).shrink();

    kout << q.size() << " " << r.size() << kendl;
    kout << q << kendl;
    kout << r << kendl;

    return 0;
}
