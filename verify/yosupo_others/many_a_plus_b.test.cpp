#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb" 

#include "../../template/fastio.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int t;
    kin >> t;
    rep (t) {
        i64 a, b;
        kin >> a >> b;
        kout << a + b << "\n";
    }

    return 0;
}
