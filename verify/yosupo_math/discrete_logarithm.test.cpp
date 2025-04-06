#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod" 

#include "../../math_mod/log.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using mint = kk2::ModInt<0>;
    int t;
    kin >> t;
    rep (t) {
        int xx, yy, m;
        kin >> xx >> yy >> m;
        mint::setmod(m);
        mint x = xx, y = yy;
        kout << kk2::discrete_logarithm(x, y) << "\n";
    }

    return 0;
}
