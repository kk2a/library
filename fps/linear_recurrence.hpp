#ifndef LINEAR_RECURRENCE_HPP
#define LINEAR_RECURRENCE_HPP 1

namespace kk2 {

// a_{i + k} = \sum_{j = 0}^{k - 1} c_{j} a_{i + k - j - 1}
// return P of P / Q = a_0 + a_1 x + a_2 x^2 + ...
template <class FPS, class mint = typename FPS::value_type>
FPS linear_rec(const FPS& a, const FPS& c) {
    int k = int(a.size());
    return (a * (-(c << 1) + mint(1))).pre(k);
}

template <class FPS, class mint = typename FPS::value_type>
mint BostanMori(const FPS& p, const FPS& q, long long n) {
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
    for (int i = 0; i < qsz - 1; i++) {
        pp[i] = (n & 1) ? p2[2 * i + 1] : p2[2 * i];
    }
    for (int i = 0; i < qsz; i++) {
        qq[i] = q2[2 * i];
    }
    return BostanMori(pp, qq, n >> 1);
}

} // namespace kk2

#endif // LINEAR_RECURRENCE_HPP
