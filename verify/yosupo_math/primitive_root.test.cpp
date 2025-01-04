#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root" 

#include "../../math_mod/primitive_root_64bit.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int q;
    kin >> q;
    rep (q) {
        i64 p;
        kin >> p;
        kout << kk2::primitive_root_64bit(p) << "\n";
    }

    return 0;
}
