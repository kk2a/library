#ifndef FPS_CHIRP_Z_HPP
#define FPS_CHIRP_Z_HPP 1

// return f(a w ^ 0), f(a w ^ 1), ..., f(a w ^ (n - 1))
template <class FPS, class mint = FPS::value_type>
vector<mint> ChirpZ(FPS f, mint w, int n = -1, mint a = 1) {
    if (n == -1) n = f.size();
    if (f.empty() || n == 0) return vector<mint>(n, mint(0));
    int m = f.size();
    if (a != 1) {
        mint x = 1;
        for (int i = 0; i < m; i++) {
            f[i] *= x;
            x *= a;
        }
    }
    if (w == 0) {
        vector<mint> g(n, f[0]);
        for (int i = 1; i < m; i++) g[0] += f[i];
        return g;
    }
    FPS wc(n + m), iwc(max(n, m));
    mint ws = 1, iw = w.inv(), iws = 1;
    wc[0] = iwc[0] = 1;
    for (int i = 1; i < n + m; i++) {
        wc[i] = ws * wc[i - 1];
        ws *= w;
    }
    for (int i = 1; i < max(n, m); i++) {
        iwc[i] = iws * iwc[i - 1];
        iws *= iw;
    }
    for (int i = 0; i < m; i++) f[i] *= iwc[i];
    reverse(begin(f), end(f));
    FPS g = f * wc;
    vector<mint> ret{begin(g) + m - 1, begin(g) + m + n - 1};
    for (int i = 0; i < n; i++) ret[i] *= iwc[i];
    return ret; 
}

#endif  // FPS_CHIRP_Z_HPP
