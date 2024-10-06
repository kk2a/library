#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution" 

#include "../../convolution/bitxor1.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    vc<kk2::mont998> a(1 << n), b(1 << n);
    rep (i, 1 << n) cin >> a[i];
    rep (i, 1 << n) cin >> b[i];
    kk2::convolution_xor(a, b);
    rep (i, 1 << n) cout << a[i] << " \n"[i == (1 << n) - 1];

    return 0;
}