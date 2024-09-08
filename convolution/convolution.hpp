#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP 1

#include <vector>
#include <algorithm>
#include "butterfly.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS convolution(FPS& a, const FPS& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) {
        FPS res(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i + j] += a[i] * b[j];
            }
        }
        a = res;
        return a;
    }
    int z = 1;
    while (z < n + m - 1) z <<= 1;
    if (a == b) {
        a.resize(z);
        butterfly(a);
        for (int i = 0; i < z; i++) a[i] *= a[i];
    }
    else {
        a.resize(z);
        butterfly(a);
        FPS t(b.begin(), b.end());
        t.resize(z);
        butterfly(t);
        for (int i = 0; i < z; i++) a[i] *= t[i];
    }
    butterfly_inv(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

} // namespace kk2

#endif  // CONVOLUTION_HPP
