#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../../convolution/bitor1.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    vc<kk2::mont998> a(1 << n), b(1 << n);
    rep (i, 1 << n) cin >> a[~i & ((1 << n) - 1)];
    rep (i, 1 << n) cin >> b[~i & ((1 << n) - 1)];
    kk2::convolution_or(a, b);
    vc<kk2::mont998> c(1 << n);
    rep (i, 1 << n) c[~i & ((1 << n) - 1)] = a[i];
    cout << c << endl;

    return 0;
}
