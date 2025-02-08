#define PROBLEM "https://judge.yosupo.jp/problem/bell_number" 

#include "../../math_mod/bell_number.hpp"
#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    kout << kk2::enumerate_bell_number<kk2::FormalPowerSeries<kk2::mont998>>(n) << kendl;

    return 0;
}
