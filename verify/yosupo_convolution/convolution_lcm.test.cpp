#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution" 

#include "../../convolution/lcm1.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    vc<kk2::mont998> a(n + 1), b(n + 1);
    rep (i, n) cin >> a[i + 1];
    rep (i, n) cin >> b[i + 1];
    kk2::convolution_lcm(a, b);
    rep (i, n) cout << a[i + 1] << " \n"[i == n - 1];

    return 0;
}