#ifndef KK2_FPS_CHIRP_Z_HPP
#define KK2_FPS_CHIRP_Z_HPP 1

#include <algorithm>
#include <vector>

namespace kk2 {

// return f(a w ^ 0), f(a w ^ 1), ..., f(a w ^ (n - 1))
template <class FPS, class mint = typename FPS::value_type>
std::vector<mint> ChirpZ(const FPS &f_, mint w, int n = -1, mint a = 1) {
    FPS f(f_.begin(), f_.end());
    if (n == -1) n = f.size();
    if (f.empty() || n == 0) return std::vector<mint>(n, mint(0));
    int m = f.size();
    if (a != mint(1)) {
        mint x = 1;
        for (int i = 0; i < m; i++) {
            f[i] *= x;
            x *= a;
        }
    }
    if (w == mint(0)) {
        std::vector<mint> g(n, f[0]);
        for (int i = 1; i < m; i++) g[0] += f[i];
        return g;
    }
    FPS wc(n + m), iwc(std::max(n, m));
    mint ws = 1, iw = w.inv(), iws = 1;
    wc[0] = iwc[0] = 1;
    for (int i = 1; i < n + m; i++) {
        wc[i] = ws * wc[i - 1];
        ws *= w;
    }
    for (int i = 1; i < std::max(n, m); i++) {
        iwc[i] = iws * iwc[i - 1];
        iws *= iw;
    }
    for (int i = 0; i < m; i++) f[i] *= iwc[i];
    std::reverse(std::begin(f), std::end(f));
    FPS g = f * wc;
    std::vector<mint> ret{std::begin(g) + m - 1, std::begin(g) + m + n - 1};
    for (int i = 0; i < n; i++) ret[i] *= iwc[i];
    return ret;
}

} // namespace kk2

#endif // KK2_FPS_CHIRP_Z_HPP
