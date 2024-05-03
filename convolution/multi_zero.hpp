#ifndef CONVOLUTION_MULTI_ZERO
#define CONVOLUTION_MULTI_ZERO 1

#include <kk2/convolution/butterfly.hpp>
#include <kk2/convolution/convolution.hpp>


template <class mint, class FPS>
FPS convolution_mulcut(FPS& a, FPS b, const vector<int>& base) {
    int n = int(a.size());
    if (!n) return {};
    static const int k = size(base);
    if (!k) return convolution<mint>(a, b);
    vector<int> chi(n, 0);
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);
        chi[i] %= k;
    }
    int z = 1;
    while (z < 2 * n - 1) z <<= 1;
    vector<vector<mint>> f(k, vector<mint>(z));
    vector<vector<mint>> g(k, vector<mint>(z));
    for (int i = 0; i < n; i++) f[chi[i]][i] = a[i], g[chi[i]][i] = b[i];
    for (auto& x : f) butterfly(x);
    for (auto& x : g) butterfly(x);
    vector<mint> tmp(k);
    for (int ii = 0; ii < z; ii++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                tmp[i + j - (i + j >= k ? k : 0)] += f[i][ii] * g[j][ii];
            }
        }
        for (int i = 0; i < k; i++) f[i][ii] = tmp[i], tmp[i] = mint{0};
    }
    for (auto& x : f) butterfly_inv(x);
    mint iz = mint(z).inv();
    for (int i = 0; i < n; i++) a[i] = f[chi[i]][i] * iz;
    return a;
}

#endif // CONVOLUTION_MULTI_ZERO
