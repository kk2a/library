#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../../math/is_prime.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int q;
    cin >> q;
    rep (q) {
        u64 n;
        cin >> n;
        Yes(kk2::is_prime(n));
    }

    return 0;
}
