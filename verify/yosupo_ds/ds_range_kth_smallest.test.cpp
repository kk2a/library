#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest" 

#include "../../data_structure/wavelet_matrix.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<int> a(n);
    kin >> a;
    kk2::WaveletMatrix wm(a);
    rep (q) {
        int l, r, k;
        kin >> l >> r >> k;
        kout << wm.kth_smallest(l, r, k) << "\n";
    }

    return 0;
}
