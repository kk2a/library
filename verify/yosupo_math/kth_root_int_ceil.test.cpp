#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "../../math/kth_root_floor.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int t;
    kin >> t;
    rep (t) {
        u64 a, k;
        kin >> a >> k;
        u64 cl = kk2::kth_root_ceil(a, k), fr = kk2::kth_root_floor(a, k);
        if (fr < cl) --cl;
        kout << cl << "\n";
    }

    return 0;
}
