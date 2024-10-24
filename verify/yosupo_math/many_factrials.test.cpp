#define PROBLEM "https://judge.yosupo.jp/problem/many_factorials"

#include "../../math_mod/comb_large.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int t;
    kin >> t;
    rep (t) {
        int n;
        kin >> n;
        kout << kk2::CombLarge<kk2::mont998>::fact(n) << "\n";
    }

    return 0;
}
