#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E" 

#include "../../math/inv_gcd.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    auto [g, x1] = kk2::inv_gcd(a, b);
    a /= g, b /= g;
    i64 y1 = (1ll - x1 * a) / b;
    i64 sum1 = x1 + abs(y1);
    i64 y2 = y1 % a;
    if (y2 < 0) y2 += a;
    i64 x2 = (1ll - y2 * b) / a;
    i64 sum2 = abs(x2) + y2;
    if (sum2 > sum1) kout << x1 << " " << y1 << kendl;
    else if (sum2 < sum1) kout << x2 << " " << y2 << kendl;
    else {
        if (x1 <= y1) kout << x1 << " " << y1 << kendl;
        else kout << x2 << " " << y2 << kendl;
    }

    return 0;
}
