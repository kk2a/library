#define PROBLEM "https://judge.yosupo.jp/problem/bell_number" 

#include "../../math_mod/bell_number.hpp"
#include "../../fps/fps_ntt_friendly.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

using FPS = kk2::FPSNTT<kk2::mont998>;

int main() {
    int n;
    kin >> n;
    kout << kk2::enumerate_bell_number<FPS>(n) << kendl;

    return 0;
}
