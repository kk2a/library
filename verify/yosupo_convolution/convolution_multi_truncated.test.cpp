#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution" 

#include "../../convolution/multi_convolution_truncated.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int k;
    cin >> k;
    vc<int> base(k);
    cin >> base;
    int n = 1;
    rep (i, k) n *= base[i];
    vc<kk2::mont998> a(n), b(n);
    cin >> a >> b;
    cout << kk2::multi_convolution_truncated(a, b, base) << endl;

    return 0;
}