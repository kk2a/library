#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind" 

#include "../../fps/fps_ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../math_mod/stirling_number.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    kout << kk2::enumerate_stirling_number_of_the_first_kind<FPS>(n) << kendl;

    return 0;
}
