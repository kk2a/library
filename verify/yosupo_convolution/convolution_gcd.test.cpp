#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../convolution/convolution_gcd.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    vc<kk2::mont998> a(n + 1), b(n + 1);
    rep (i, n) kin >> a[i + 1];
    rep (i, n) kin >> b[i + 1];
    kk2::convolution_gcd(a, b);
    rep (i, n) kout << a[i + 1] << " \n"[i == n - 1];

    return 0;
}
