#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../convolution/convolution.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vc<kk2::mont998> a(n), b(m);
    cin >> a >> b;
    cout << kk2::convolution(a, b) << endl;

    return 0;
}
