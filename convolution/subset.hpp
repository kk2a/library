#ifndef CONVOLUTION_SUBSET
#define CONVOLUTION_SUBSET 1

#include <cassert>
#include <functional>
#include <vector>

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS convolution_subset(FPS &a, const FPS &b) {
    int n = int(size(a)); // == int(size(b)
    if (!n) return {};
    int h = __builtin_ctz(n);

    assert((n & (-n)) == n);
    std::vector<int> chi(n, 0);
    for (int i = 1; i < n; i++) chi[i] = chi[i - (i & -i)] + 1;
    std::vector<std::vector<mint>> f(n, std::vector<mint>(h + 1)), g(n, std::vector<mint>(h + 1));
    for (int i = 0; i < n; i++) {
        f[i][chi[i]] = a[i];
        g[i][chi[i]] = b[i];
    }
    auto rfzt = [&](std::vector<std::vector<mint>> &c) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j += 2 * i) {
                for (int s = j; s < j + i; s++) {
                    int t = s | i;
                    for (int d = 0; d <= h; ++d) { c[t][d] += c[s][d]; }
                }
            }
        }
    };
    auto rifzt = [&](std::vector<std::vector<mint>> &c) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j += 2 * i) {
                for (int s = j; s < j + i; s++) {
                    int t = s | i;
                    for (int d = 0; d <= h; d++) { c[t][d] -= c[s][d]; }
                }
            }
        }
    };
    rfzt(f);
    rfzt(g);
    for (int i = 0; i < n; i++) {
        for (int d = h; d >= 0; d--) {
            mint x{};
            for (int j = 0; j < d + 1; j++) { x += f[i][j] * g[i][d - j]; }
            f[i][d] = x;
        }
    }
    rifzt(f);
    for (int i = 0; i < n; i++) a[i] = f[i][chi[i]];
    return a;
}

} // namespace kk2

#endif // CONVOLUTION_SUBSET
