#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution" 

#include "../../convolution/multi_convolution_truncated.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int k;
    cin >> k;
    vc<int> base(k);
    rep (i, k) cin >> base[i];
    int n = 1;
    rep (i, k) n *= base[i];
    vc<kk2::mont998> a(n), b(n);
    rep (i, n) cin >> a[i];
    rep (i, n) cin >> b[i];
    kk2::multi_convolution_truncated(a, b, base);
    rep (i, n) cout << a[i] << " \n"[i == n - 1];

    return 0;
}