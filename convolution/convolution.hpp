#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP 1

#include "butterfly.hpp"

template <class FPS, class mint = typename FPS::value_type>
FPS convolution(FPS& a, FPS b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) {
        if (n < m) {
            swap(n, m);
            swap(a, b);
        }
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
    a.resize(z);
    butterfly(a);
    b.resize(z);
    butterfly(b);
    for (int i = 0; i < z; i++) a[i] *= b[i];
    butterfly_inv(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

#endif  // CONVOLUTION_HPP
