#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007" 

#include "../../convolution/convolution_arb.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vc<kk2::mont107> a(n), b(m);
    rep (i, n) cin >> a[i];
    rep (i, m) cin >> b[i];
    kk2::convolution_arb(a, b, modu);
    rep (i, n + m - 1) cout << a[i] << " \n"[i == n + m - 2];

    return 0;
}