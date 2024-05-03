#ifndef CONVOLUTION_SUBSET
#define CONVOLUTION_SUBSET 1

template <class mint, class FPS>
FPS convolution_subset(FPS& a, FPS b) {
    int n = int(size(a));  // == int(size(b)
    if (!n) return {};
    int h = 0;
    while (1 << h < n) h++;
    n = 1 << h;
    a.resize(n, 0), b.resize(n, 0);
    vector<int> chi(n, 0);
    for (int i = 1; i < n; i++) chi[i] = chi[i - (i & -i)] + 1;
    vector<vector<mint>> f(n, vector<mint>(h + 1)), g(n, vector<mint>(h + 1));
    for (int i = 0; i < n; i++) {
        f[i][chi[i]] = a[i];
        g[i][chi[i]] = b[i];
    }
    auto rfzt = [&] (vector<vector<mint>>& c) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j += 2 * i) {
                for (int s = j; s < j + i; s++) {
                    int t = s | i;
                    for (int d = 0; d <= h; ++d) {
                        c[t][d] += c[s][d];
                    }
                }
            }
        }
    };
    auto rifzt = [&] (vector<vector<mint>>& c) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j += 2 * i) {
                for (int s = j; s < j + i; s++) {
                    int t = s | i;
                    for (int d = 0; d <= h; d++) {
                        c[t][d] -= c[s][d];
                    }
                }
            }
            
        }
    };
    rfzt(f);
    rfzt(g);
    for (int i = 0; i < n; i++) {
        for (int d = h; d >= 0; d--) {
            mint x;
            for (int j = 0; j < d + 1; j++) {
                x += f[i][j] * g[i][d - j];
            }
            f[i][d] = x;
        }
    }
    rifzt(f);
    for (int i = 0; i < n; i++) a[i] = f[i][chi[i]];
    return a;
}

#endif // CONVOLUTION_SUBSET
