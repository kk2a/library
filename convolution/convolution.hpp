#ifndef KK2_CONVOLUTION_CONVOLUTION_HPP
#define KK2_CONVOLUTION_CONVOLUTION_HPP 1

#include <algorithm>
#include <vector>

#include "../fps/fps_sparsity_detector.hpp"
#include "../math_mod/butterfly.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type> FPS convolution(FPS &a, const FPS &b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) {
        a.clear();
        return a;
    }
    if (is_sparse_operation(FPSOperation::CONVOLUTION, 1, a, b)) {
        std::vector<int> nza(n), nzb(m);
        int ai = 0, bi = 0;
        for (int i = 0; i < n; i++)
            if (a[i] != mint(0)) nza[ai++] = i;
        for (int i = 0; i < m; i++)
            if (b[i] != mint(0)) nzb[bi++] = i;
        nza.resize(ai), nzb.resize(bi);
        FPS res(n + m - 1);
        for (int i : nza)
            for (int j : nzb) res[i + j] += a[i] * b[j];
        return a = res;
    }

    int z = 1;
    while (z < n + m - 1) z <<= 1;
    if (a == b) {
        a.resize(z);
        butterfly(a);
        for (int i = 0; i < z; i++) a[i] *= a[i];
    } else {
        a.resize(z);
        butterfly(a);
        FPS t(b.begin(), b.end());
        t.resize(z);
        butterfly(t);
        for (int i = 0; i < z; i++) a[i] *= t[i];
    }
    butterfly_inv(a);
    a.resize(n + m - 1);
    return a;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_HPP
