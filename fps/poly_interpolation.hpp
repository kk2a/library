#ifndef FPS_POLYNOMIAL_INTERPOLATION_HPP
#define FPS_POLYNOMIAL_INTERPOLATION_HPP 1

#include "multi_eval.hpp"
#include "chirp_Z.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS PolyInterpolation(const vector<mint> &x,
                      const vector<mint> &y) {
    assert(x.size() == y.size());
    MultiPointEvaluation<FPS> mpe(x);
    FPS gp = mpe.pr[1].diff();
    vector<mint> vs = mpe.query(gp);
    auto rec = [&](auto self, int idx) -> FPS {
        if (idx >= mpe.size) {  
            if (idx - mpe.size < (int)y.size()) {
                return {y[idx - mpe.size] / vs[idx - mpe.size]};
            }
            else return {mint(1)};
        }
        if (mpe.pr[idx << 1 | 0].empty()) return {};
        else if (mpe.pr[idx << 1 | 1].empty())
            return self(self, idx << 1 | 0);
        return self(self, idx << 1 | 0) * mpe.pr[idx << 1 | 1] +
               self(self, idx << 1 | 1) * mpe.pr[idx << 1 | 0];
    };
    return rec(rec, 1);
}

// reference:
// https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric#fn:Bostan
template <class FPS, class mint = typename FPS::value_type>
FPS PolyInterpolationGeo(const mint &a, const mint &r,
                         const vector<mint> &y) {
    if (y.empty()) return {};
    if (y.size() == 1) return FPS{y[0]};
    assert(a != mint(0) && r != mint(0) && r != mint(1));

    int n = (int)y.size();
    // https://yukicoder.me/wiki/%E9%80%86%E5%85%83
    vector<mint> s(n + 1), invs(n), pre(n + 1);
    s[0] = pre[0] = invs[0] = 1;
    mint q = r;
    for (int i = 1; i < n + 1; i++) {
        s[i] = s[i - 1] * (-q + 1);
        pre[i] = pre[i - 1] * s[i];
        q *= r;
    }
    mint inv = pre[n - 1].inv();
    for (int i = n - 1; i >= 1; i--) {
        invs[i] = inv * pre[i - 1];
        inv *= s[i];
    }

    vector<mint> w(n);
    q = 1;
    int idx1 = n - 1, idx2 = 0;
    w[n - 1] = r.pow(1ll * (n - 1) * (n - 2) / 2).inv() * invs[idx1] * invs[idx2];
    if ((n - 1) & 1) w[n - 1] *= -1;
    for (int i = n - 1; i > 0; i--) {
        w[i - 1] = w[i] * q * (-1) * 
                   s[idx1] * invs[idx1 - 1] *
                   s[idx2] * invs[idx2 + 1];
        q *= r;
        idx1--; idx2++;
    }
    for (int i = 0; i < n; i++) w[i] *= y[i];

    FPS g{begin(w), end(w)};
    vector<mint> tmp = ChirpZ(g, r, n);
    FPS gq{begin(tmp), end(tmp)};
    FPS prod(n);
    q = 1;
    mint plus = r;
    prod[0] = 1;
    for (int i = 1; i < n; i++) {
        prod[i] = s[n] * invs[i] * invs[n - i] * q;
        if (i & 1) prod[i] *= -1;
        q *= plus;
        plus *= r;
    }

    FPS ret = (prod * gq).pre(n).rev();
    if (a != mint(1)) {
        mint x = 1, inva = a.inv();
        for (int i = 0; i < n; i++) {
            ret[i] *= x;
            x *= inva;
        }
    }
    return ret;
}

} // namespace kk2

#endif // FPS_POLYNOMIAL_INTERPOLATION_HPP
