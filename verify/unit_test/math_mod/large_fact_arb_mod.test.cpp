#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../modint/modint.hpp"
#include "../../../math_mod/comb_large.hpp"
#include "../../../math_mod/comb.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    kk2::Comb<kk2::mint107>::set_upper(1e7);
    int up = 2000001, lw = 1e7;
    int t = 2;
    rep (t) {
        int n = kk2::random::rng(up, lw);
        auto a = kk2::Comb<kk2::mint107>::fact(n);
        auto b = kk2::CombLarge<kk2::mint107>::fact(n);
        // 壊れているのでfalseを返す
        // assert(a == b);
    }

    return 0;
}
