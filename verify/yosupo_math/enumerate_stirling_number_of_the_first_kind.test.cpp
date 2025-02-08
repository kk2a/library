#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind" 

#include "../../fps/ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../math_mod/stirling_number.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    kout << kk2::enumerate_stirling_number_of_the_first_kind<kk2::FormalPowerSeries<kk2::mont998>>(n) << kendl;

    return 0;
}
