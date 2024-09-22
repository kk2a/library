#ifndef FPS_COMPOSITION_HPP
#define FPS_COMPOSITION_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>

namespace kk2 {

// calculate (g \circ f) (X)
template <class FPS, class mint = typename FPS::value_type>
FPS composition(const FPS &f_, const FPS &g_, int deg = -1) {
    if (f_.empty() || g_.empty()) return {};
    if (deg == -1) deg = std::max(size(f_), size(g_));
    FPS f(f_.begin(), f_.end()), g(g_.begin(), g_.end());
    f.resize(deg), g.resize(deg);

    auto rec = [&](auto self, FPS q, int n, int h, int k) -> FPS {
        if (n == 0) {
            FPS t(std::begin(q), std::begin(q) + k);
            t.push_back(1);
            FPS u = g * t.rev().inv().rev();
            FPS p(h * k);
            for (int i = 0; i < (int)size(g); i++) { p[k - 1 - i] = u[i + k]; }
            return p;
        }
        FPS nq(4 * h * k), nr(2 * h * k);
        for (int i = 0; i < k; i++) {
            std::copy(std::begin(q) + i * h,
                      std::begin(q) + i * h + n + 1,
                      std::begin(nq) + i * 2 * h);
        }
        nq[k * 2 * h] += 1;
        nq.but();
        for (int i = 0; i < 4 * h * k; i += 2) std::swap(nq[i], nq[i + 1]);
        for (int i = 0; i < 2 * h * k; i++) {
            nr[i] = nq[i * 2] * nq[i * 2 + 1];
        }
        nr.ibut();
        nr[0] -= 1;
        q.assign(h * k, 0);
        for (int i = 0; i < 2 * k; i++) {
            for (int j = 0; j <= n / 2; j++) {
                q[i * h / 2 + j] = nr[i * h + j];
            }
        }
        auto p = self(self, q, n / 2, h / 2, k * 2);
        FPS np(4 * h * k);
        for (int i = 0; i < 2 * k; i++) {
            for (int j = 0; j <= n / 2; j++) {
                np[i * 2 * h + j * 2 + n % 2] = p[i * h / 2 + j];
            }
        }
        np.but();
        for (int i = 1; i < 4 * h * k; i <<= 1) {
            std::reverse(std::begin(nq) + i, std::begin(nq) + i * 2);
        }
        for (int i = 0; i < 4 * h * k; i++) { np[i] *= nq[i]; }
        np.ibut();
        p.assign(h * k, 0);
        for (int i = 0; i < k; i++) {
            std::copy(std::begin(np) + i * 2 * h,
                      std::begin(np) + i * 2 * h + n + 1,
                      std::begin(p) + i * h);
        }
        return p;
    };

    int n = int(size(f)) - 1, k = 1;
    int h = 1;
    while (h < n + 1) h <<= 1;
    FPS q(h * k);
    for (int i = 0; i <= n; i++) q[i] = -f[i];
    FPS p = rec(rec, q, n, h, k);
    return p.pre(n + 1).rev();
}

} // namespace kk2

#endif /* FPS_COMPOSITION_HPP */
