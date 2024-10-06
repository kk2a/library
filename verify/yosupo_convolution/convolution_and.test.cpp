#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../../convolution/bitand1.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    vc<kk2::mont998> a(1 << n), b(1 << n);
    cin >> a >> b;
    cout << kk2::convolution_and(a, b) << endl;

    return 0;
}
