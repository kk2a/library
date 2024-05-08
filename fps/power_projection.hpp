#ifndef POWER_PROJECTION_HPP
#define POWER_PROJECTION_HPP 1

#ifdef KK2
#include "fps.hpp"
#endif

// [X ^ n] f(X) ^ i g(X)  enumerate for i = 0, ... , m 
// n = \deg f - 1
template <class mint>
FormalPowerSeries<mint> power_projection(FormalPowerSeries<mint> f,
                                        FormalPowerSeries<mint> g = {1},
                                        int m = -1) {
    if (f.empty() || g.empty()) return {};
    int n = int(size(f)) - 1, k = 1;
    g.resize(n + 1);
    if (m == -1) m = n;
    int h = 1;
    while (h < n + 1) h <<= 1;
    FormalPowerSeries<mint> p((n + 1) * k), q((n + 1) * k),
        np, nq, buf, buf2;
    for (int i = 0; i <= n; i++) p[i * k] = g[i];
    for (int i = 0; i <= n; i++) q[i * k] = -f[i];
    q[0] += 1;
    mint inv2 = mint(2).inv();
    mint invk = mint(k).inv();
    mint invh = mint(h).inv();
    while (n) {
        mint w = mint(FormalPowerSeries<mint>::but_pr()).
            pow((mint::getmod() - 1) / (k << 1));
        mint invw = w.inv();

        buf2.resize(k);
        auto db = [&]() -> void {
            copy(begin(buf), end(buf), begin(buf2));
            buf2.ibut();
            for (int i = 0; i < k; i++) buf2[i] *= invk;
            mint r = 1;
            for (int i = 0; i < k; i++) {
                buf2[i] *= r;
                r *= w;
            }
            buf2.but();
            copy(begin(buf2), end(buf2), back_inserter(buf));
        };

        np.clear(), nq.clear();
        for (int i = 0; i <= n; i++) {
            buf.resize(k);
            copy(begin(p) + i * k, begin(p) + (i + 1) * k, begin(buf));
            db();
            copy(begin(buf), end(buf), back_inserter(np));

            buf.resize(k);
            copy(begin(q) + i * k, begin(q) + (i + 1) * k, begin(buf));
            if (i == 0) {
                for (int j = 0; j < k; j++) buf[j] -= 1;
                db();
                for (int j = 0; j < k; j++) buf[j] += 1;
                for (int j = 0; j < k; j++) buf[k + j] -= 1; 
            }
            else db();

            copy(begin(buf), end(buf), back_inserter(nq));
        }

        np.resize(2 * h * 2 * k);
        nq.resize(2 * h * 2 * k);
        FormalPowerSeries<mint> p1(2 * h), q1(2 * h);

        w = mint(FormalPowerSeries<mint>::but_pr()).
            pow((mint::getmod() - 1) / (h << 1));
        invw = w.inv();
        vector<int> btr;
        if (n & 1) {
            btr.resize(h);
            for (int i = 0, lg = __builtin_ctz(h); i < h; i++) {
                btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (lg - 1));
            }
        }

        for (int j = 0; j < 2 * k; j++) {
            p1.assign(2 * h, 0);
            q1.assign(2 * h, 0);
            for (int i = 0; i < h; i++) {
                p1[i] = np[i * 2 * k + j];
                q1[i] = nq[i * 2 * k + j];
            }
            p1.but(); q1.but();
            for (int i = 0; i < 2 * h; i += 2) swap(q1[i], q1[i + 1]);
            for (int i = 0; i < 2 * h; i++) p1[i] *= q1[i];
            for (int i = 0; i < h; i++) q1[i] = q1[i * 2] * q1[i * 2 + 1];
            if (n & 1) {
                mint c = inv2;
                buf.resize(h);
                for (int i : btr) {
                    buf[i] = (p1[i * 2] - p1[i * 2 + 1]) * c;
                    c *= invw;
                }
                swap(p1, buf);
            }
            else {
                for (int i = 0; i < h; i++) p1[i] =
                    (p1[i * 2] + p1[i * 2 + 1]) * inv2;
            }
            p1.resize(h); q1.resize(h);
            p1.ibut(); q1.ibut();
            for (int i = 0; i < h; i++) { p1[i] *= invh; q1[i] *= invh; }
            for (int i = 0; i < h; i++) {
                np[i * 2 * k + j] = p1[i];
                nq[i * 2 * k + j] = q1[i];
            }
        }

        np.resize((n / 2 + 1) * 2 * k);
        nq.resize((n / 2 + 1) * 2 * k);
        swap(p, np); swap(q, nq);
        n >>= 1, h >>= 1, k <<= 1;
        invh *= 2, invk *= inv2;
    }

    FormalPowerSeries<mint> s(begin(p), begin(p) + k);
    FormalPowerSeries<mint> t(begin(q), begin(q) + k);
    s.ibut(); t.ibut();
    for (int i = 0; i < k; i++) { s[i] *= invk; t[i] *= invk; }
    t[0] -= 1;
    if (f[0] == mint(0)) return s.rev().pre(m + 1);
    return (s.rev() * (t + (FormalPowerSeries<mint>{1} << k)).
           rev().inv(m + 1)).pre(m + 1);
}

#endif // POWER_PROJECTION_HPP
