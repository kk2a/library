// #define PROBLEM "https://yukicoder.me/problems/no/1510" 
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../fps/ntt_friendly.hpp"
#include "../../fps/bbb.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FormalPowerSeries<kk2::mont998>;


// \int_{-infty}^{infty} (x^2 + A^2)^-n dx
// = pi / A^{2n-1} * binom(2n-2, n-1) * 2^{-2n+2}
// 
// binom(2n-2, n-1) * 2^{-2n+2} = (2n-3)!! / (2n-2)!! (n > 1) 
int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    return 0;
}
