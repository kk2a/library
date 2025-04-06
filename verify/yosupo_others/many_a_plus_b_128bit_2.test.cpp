#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit" 

#include "../../template/procon.hpp"
using namespace std;

int main() {
    int t;
    kin >> t;
    rep (t) {
        i128 a, b;
        kin >> a >> b;
        kout << a + b << "\n";
    }

    return 0;
}
