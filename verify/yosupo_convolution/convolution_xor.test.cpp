#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution" 

#include "../../convolution/bitxor1.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    vc<kk2::mont998> a(1 << n), b(1 << n);
    cin >> a >> b;
    cout << kk2::convolution_xor(a, b) << endl;

    return 0;
}