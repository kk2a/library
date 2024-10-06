#define PROBLEM "https://judge.yosupo.jp/problem/factorize" 

#include "../../math/prime_factorize.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int q;
    cin >> q;
    rep (q) {
        i64 a;
        cin >> a;
        int cnt = 0;
        auto f = kk2::factorize(a);
        for (auto [p, e] : f) cnt += e;
        cout << cnt << ' ';
        for (auto [p, e] : f)
            rep (e) cout << p << ' ';
        cout << '\n';
    }

    return 0;
}