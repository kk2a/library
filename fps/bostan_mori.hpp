#ifndef KK2_FPS_BOSTAN_MORI_HPP
#define KK2_FPS_BOSTAN_MORI_HPP 1

#include <cassert>

namespace kk2 {

// return [x^n] (p(x) / q(x))
template <class FPS, class mint = typename FPS::value_type>
mint bostan_mori(const FPS &p, const FPS &q, long long n) {
    assert(!p.empty() && !q.empty());
    if (n == 0) return p[0] / q[0];

    int qsz = q.size();
    FPS mq(q);
    for (int i = 1; i < qsz; i += 2) mq[i] = -mq[i];
    FPS p2(p);
    p2.resize(qsz - 1);
    p2 *= mq;
    FPS q2 = q * mq;
    FPS pp(qsz - 1), qq(qsz);
    for (int i = 0; i < qsz - 1; i++) { pp[i] = (n & 1) ? p2[2 * i + 1] : p2[2 * i]; }
    for (int i = 0; i < qsz; i++) { qq[i] = q2[2 * i]; }
    return bostan_mori(pp, qq, n >> 1);
}

// a_i = \sum_{j=0}^{d-1} c_ja_{i-j-1} (i >= d)
// return a_k
template <class FPS, class mint = typename FPS::value_type>
mint kth_term_of_linearly_recurrent_sequence(const FPS &a, const FPS &c, long long k) {
    if (k < (long long)a.size()) return a[k];
    return bostan_mori((a * (-(c << 1) + mint(1))).pre(a.size()), -(c << 1) + mint(1), k);
}

} // namespace kk2

#endif // KK2_FPS_BOSTAN_MORI_HPP
