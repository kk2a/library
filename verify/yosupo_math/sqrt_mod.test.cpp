#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod" 

#include "../../math_mod/mod_sqrt.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int t;
    kin >> t;
    rep (t) {
        int y, p;
        kin >> y >> p;
        kout << kk2::mod_sqrt(y, p) << "\n";
    }

    return 0;
}
