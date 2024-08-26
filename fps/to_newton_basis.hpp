#ifndef FPS_TO_NEWTON_BASIS_HPP
#define FPS_TO_NEWTON_BASIS_HPP 1

namespace kk2 {

// return b s.t. f(X) = \sum_{i = 0} ^ {n - 1} b_i \prod_{j = 0} ^ {i - 1} (X - p_j)
template <class FPS, class mint = typename FPS::value_type>
vector<mint> convert_to_newton_basis(FPS f, vector<mint> p) {
    int n = (int)f.size();
    assert(n == (int)p.size());

    int m = 1;
    while (m < n) m <<= 1;

    vector<FPS> buf(m << 1);
    for (int i = 0; i < n; i++) {
        buf[m + i] = {-p[i], 1};
    }
    for (int i = m - 1; i > 0; i--) {
        if (((i + 1) & -(i + 1)) == i + 1) continue;
        if (buf[i << 1 | 1].empty()) {
            buf[i] = buf[i << 1 | 0];
        }
        else {
            buf[i] = buf[i << 1 | 0] * buf[i << 1 | 1];
        }
    }
    buf[1] = f;
    for (int i = 1; i < m; i++) {
        if (buf[i].empty()) continue;
        buf[i << 1 | 1] = buf[i] / buf[i << 1 | 0];
        buf[i << 1 | 0] = buf[i] % buf[i << 1 | 0];
    }
    vector<mint> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = buf[m + i].eval(0);
    }
    return b;
}

} // namespace kk2

#endif  // FPS_TO_NEWTON_BASIS_HPP
