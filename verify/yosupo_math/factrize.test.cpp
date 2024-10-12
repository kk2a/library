#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../math/prime_factorize.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int q;
    kin >> q;
    rep (q) {
        i64 a;
        kin >> a;
        int cnt = 0;
        auto f = kk2::factorize(a);
        for (auto [p, e] : f) cnt += e;
        kout << cnt << ' ';
        for (auto [p, e] : f)
            rep (e) kout << p << ' ';
        kout << '\n';
    }

    return 0;
}
