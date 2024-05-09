#ifndef FPS_COMPOSITION_HPP
#define FPS_COMPOSITION_HPP 1

#include "fps.hpp"

// calculate (g \circ f) (X)
template <class mint>
FormalPowerSeries<mint> composition(FormalPowerSeries<mint> f,
                                    FormalPowerSeries<mint> g,
                                    int deg = -1) {
    if (f.empty() || g.empty()) return {};
    
    auto rec = [&](auto self, FormalPowerSeries<mint> q,
                   int n, int h, int k) -> FormalPowerSeries<mint> {
        if (n == 0) {
            FormalPowerSeries<mint> t(begin(q), begin(q) + k);
            t.push_back(1);
            FormalPowerSeries<mint> u = g * t.rev().inv().rev();
            FormalPowerSeries<mint> p(h * k);
            for (int i = 0; i < (int)size(g); i++) {
                p[k - 1 - i] = u[i + k];
            }
            return p;
        }
        FormalPowerSeries<mint> nq(4 * h * k), nr(2 * h * k);
        for (int i = 0; i < k; i++) {
            copy(begin(q) + i * h, begin(q) + i * h + n + 1,
                 begin(nq) + i * 2 * h);
        }
        nq[k * 2 * h] += 1;
        int z = 1;
        while (z < 2 * h * k) z <<= 1;
        mint invz = mint(z).inv(), invz2 = invz * mint(2).inv();
        nq.resize(z << 1);
        nq.but();
        for (int i = 0; i < 4 * h * k; i += 2) swap(nq[i], nq[i + 1]);
        for (int i = 0; i < 2 * h * k; i++) {
            nr[i] = nq[i * 2] * nq[i * 2 + 1];
        }
        nr.resize(z);
        nr.ibut();
        for (int i = 0; i < 2 * h * k; i++) nr[i] *= invz;
        nr[0] -= 1;
        q.assign(h * k, 0);
        for (int i = 0; i < 2 * k; i++) {
            for (int j = 0; j <= n / 2; j++) {
                q[i * h / 2 + j] = nr[i * h + j];
            }
        }
        auto p = self(self, q, n / 2, h / 2, k * 2);
        FormalPowerSeries<mint> np(4 * h * k);
        for (int i = 0; i < 2 * k; i++) {
            for (int j = 0; j <= n / 2; j++) {
                np[i * 2 * h + j * 2 + n % 2] = p[i * h / 2 + j];
            }
        }
        np.resize(z << 1);
        np.but();
        for (int i = 1; i < 4 * h * k; i <<= 1) {
            reverse(begin(nq) + i, begin(nq) + i * 2);
        }
        for (int i = 0; i < 4 * h * k; i++) {
            np[i] *= nq[i];
        }
        np.ibut();
        for (int i = 0; i < 4 * h * k; i++) np[i] *= invz2;
        p.assign(h * k, 0);
        for (int i = 0; i < k; i++) {
            copy(begin(np) + i * 2 * h, begin(np) + i * 2 * h + n + 1,
                 begin(p) + i * h);
        }
        return p;
    }; 

    if (deg == -1) deg = max(size(f), size(g));
    f.resize(deg), g.resize(deg);
    int n = int(size(f)) - 1, k = 1;
    int h = 1;
    while (h < n + 1) h <<= 1;
    FormalPowerSeries<mint> q(h * k);
    for (int i = 0; i <= n; i++) q[i] = -f[i];
    FormalPowerSeries<mint> p = rec(rec, q, n, h, k);
    return p.pre(n + 1).rev();
}


#endif /* FPS_COMPOSITION_HPP */