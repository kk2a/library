struct Convolution {
  public:
    template <class mint, class T>
    static vector<mint> convolution(const vector<T>& aa, const vector<T>& bb) {
        vector<mint> a(begin(aa), end(aa)), b(begin(bb), end(bb));

        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};
        if (std::min(n, m) <= 60) {
            if (n < m) {
                swap(n, m);
                swap(a, b);
            }
            vector<mint> res(n + m - 1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[i + j] += a[i] * b[j];
                }
            }
            return res;
        }
        int z = 1;
        while (z < n + m - 1) z <<= 1;
        a.resize(z);
        butterfly(a);
        b.resize(z);
        butterfly(b);
        for (int i = 0; i < z; i++) a[i] *= b[i];
        butterfly_inv(a);
        a.resize(n + m - 1);
        mint iz = mint(z).inv();
        for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
        return a;
    }

    template <class mint, class T>
    static vector<mint> convolution_arb(const vector<T>& a,
                                        const vector<T>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};

        static constexpr int nm = 3;
        static constexpr long long MOD1 = 1107296257;  // 2^25
        static constexpr long long MOD2 = 167772161;  // 2^25
        static constexpr long long MOD3 = 469762049;  // 2^26

        auto c1 = convolution<ModInt<MOD1>>(a, b);
        auto c2 = convolution<ModInt<MOD2>>(a, b);
        auto c3 = convolution<ModInt<MOD3>>(a, b);

        static const vector<long long> p = {MOD1, MOD2, MOD3, mint::getmod()};
        vector<mint> res(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) {
            res[i] = mint(garner({c1[i].val(), c2[i].val(), c3[i].val()}, p));
        }
        return res;
    }

    template <class mint, class T>
    static vector<mint> convolution_mulcut(const vector<T>& aa, const vector<T>& bb,
                                           const vector<int>& base) {
        vector<mint> a(begin(aa), end(aa)), b(begin(bb), end(bb));

        int n = int(a.size());
        if (!n) return {};
        static const int k = size(base);
        if (!k) return convolution<mint>(a, b);

        vector<int> chi(n, 0);
        for (int i = 0; i < n; i++) {
            int x = i;
            for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);
            chi[i] %= k;
        }

        int z = 1;
        while (z < 2 * n - 1) z <<= 1;
        vector<vector<mint>> f(k, vector<mint>(z));
        vector<vector<mint>> g(k, vector<mint>(z));

        for (int i = 0; i < n; i++) f[chi[i]][i] = a[i], g[chi[i]][i] = b[i];
        for (auto& x : f) butterfly(x);
        for (auto& x : g) butterfly(x);

        vector<mint> tmp(k);
        for (int ii = 0; ii < z; ii++) {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    tmp[i + j - (i + j >= k ? k : 0)] += f[i][ii] * g[j][ii];
                }
            }
            for (int i = 0; i < k; i++) f[i][ii] = tmp[i], tmp[i] = mint{0};
        }
        for (auto& x : f) butterfly_inv(x);
        mint iz = mint(z).inv();
        for (int i = 0; i < n; i++) a[i] = f[chi[i]][i] * iz;
        return a;
    }

    template <class mint, class T>
    static vector<mint> convolution_subset(const vector<T>& aa, const vector<T>& bb) {
        vector<mint> a(begin(aa), end(aa)), b(begin(bb), end(bb));

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

    template <class mint, class T>
    static vector<mint> convolution_and(const vector<T>& aa, const vector<T>& bb) {
        vector<mint> a(begin(aa), end(aa)), b(begin(bb), end(bb));

        int n = int(size(a));  // == int(size(b)
        if (!n) return {};
        int log = 0;
        while (1ull << log < n) log++;
        n = 1 << log;
        a.resize(n, 0), b.resize(n, 0);

        auto fzt = [&](vector<mint>& a) -> void {
            for (int i = 1; i < n; i <<= 1) {
                for (int j = 0; j < n; j++) {
                    if ((i & j) == 0) a[j] += a[i ^ j];
                }
            }
        };
        auto ifzt = [&](vector<mint>& a) -> void {
            for (int i = 1; i < n; i <<= 1) {
                for (int j = 0; j < n; j++) {
                    if ((i & j) == 0) a[j] -= a[i ^ j];
                }
            }
        };

        fzt(a);
        fzt(b);
        for (int i = 0; i < n; i++) a[i] *= b[i]; 
        ifzt(a);

        return a;
    }

    template <class mint, class T>
    static vector<mint> convolution_or(const vector<T>& aa, const vector<T>& bb) {
        vector<mint> a(begin(aa), end(aa)), b(begin(bb), end(bb));

        int n = int(size(a));  // == int(size(b)
        if (!n) return {};
        int log = 0;
        while (1ull << log < n) log++;
        n = 1 << log;
        a.resize(n, 0), b.resize(n, 0);

        auto fzt = [&](vector<mint>& a) -> void {
            for (int i = 1; i < n; i <<= 1) {
                for (int j = 0; j < n; j++) {
                    if ((i & j) != 0) a[j] += a[i ^ j];
                }
            }
        };
        auto ifzt = [&](vector<mint>& a) -> void {
            for (int i = 1; i < n; i <<= 1) {
                for (int j = 0; j < n; j++) {
                    if ((i & j) != 0) a[j] -= a[i ^ j];
                }
            }
        };

        fzt(a);
        fzt(b);
        for (int i = 0; i < n; i++) a[i] *= b[i]; 
        ifzt(a);

        return a;
    }

    template <class mint, class T>
    static vector<mint> convolution_xor(const vector<T>& aa, const vector<T>& bb) {
        vector<mint> a(begin(aa), end(aa)), b(begin(bb), end(bb));

        int n = int(size(a));  // == int(size(b)
        if (!n) return {};
        int log = 0;
        while (1ull << log < n) log++;
        n = 1 << log;
        a.resize(n, 0), b.resize(n, 0);

        auto fwht = [&](vector<mint>& a) -> void {
            for (int i = 1; i < n; i <<= 1) {
                for (int j = 0; j < n; j++) {
                    if ((i & j) != 0) {
                        mint x = a[j], y = a[i ^ j];
                        a[j] = -x + y, a[i ^ j] = x + y;
                    }
                }
            }
        };
        auto ifwht = [&](vector<mint>& a) -> void {
            for (int i = 1; i < n; i <<= 1) {
                for (int j = 0; j < n; j++) {
                    if ((i & j) != 0) {
                        mint x = a[j], y = a[i ^ j];
                        a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;
                    }
                }
            }
        };

        fwht(a);
        fwht(b);
        for (int i = 0; i < n; i++) a[i] *= b[i]; 
        ifwht(a);

        return a;
    }

    // 1-indexed
    template <class mint, class T> 
    static vector<mint> convolution_gcd(const vector<T>& aa, const vector<T>& bb) {
        vector<mint> a(begin(aa), end(aa)), b(begin(bb), end(bb));

        int n = int(size(a)); // = int(size(b))
        if (!n) return {};
        n--;

        static const constexpr int mx = 1000000;
        Erato pr(mx);

        auto fmt = [&](vector<mint>& a) -> void {
            for (const auto p : pr.primes) {
                if (p > n) break;
                for (int i = n / p; i > 0; i--) a[i] += a[i * p];
            }
        };
        auto ifmt = [&](vector<mint>& a) -> void {
            for (const auto p : pr.primes) {
                if (p > n) break;
                for (int i = 1; i <= n / p; i++) a[i] -= a[i * p];
            }
        };

        fmt(a);
        fmt(b);
        for (int i = 1; i <= n; i++) a[i] *= b[i];
        ifmt(a);

        return a;
    }

    // 1-indexed
    template <class mint, class T> 
    static vector<mint> convolution_lcm(const vector<T>& aa, const vector<T>& bb) {
        vector<mint> a(begin(aa), end(aa)), b(begin(bb), end(bb));

        int n = int(size(a)); // = int(size(b))
        if (!n) return {};
        n--;

        static const constexpr int mx = 1000000;
        Erato pr(mx);

        auto fdt = [&](vector<mint>& a) -> void {
            for (const auto p : pr.primes) {
                if (p > n) break;
                for (int i = 1; i <= n / p; i++) a[i * p] += a[i];
            }
        };
        auto ifdt = [&](vector<mint>& a) -> void {
            for (const auto p : pr.primes) {
                if (p  > n) break;
                for (auto i = n / p; i > 0; i--) a[i * p] -= a[i];
            }
        };

        fdt(a);
        fdt(b);
        for (int i = 1; i <= n; i++) a[i] *= b[i];
        ifdt(a);

        return a;
    }

  private:
    static constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
        if (m == 1) return 0;
        unsigned int _m = (unsigned int)(m);
        unsigned long long r = 1;
        unsigned long long y = (x % m + m) % m;
        while (n) {
            if (n & 1) r = (r * y) % _m;
            y = (y * y) % _m;
            n >>= 1;
        }
        return r;
    }

    static constexpr int primitive_root_constexpr(int m) {
        if (m == 2) return 1;
        if (m == 167772161) return 3;
        if (m == 469762049) return 3;
        if (m == 754974721) return 11;
        if (m == 998244353) return 3;
        if (m == 1107296257) return 10;
        int divs[20] = {}; 
        divs[0] = 2;
        int cnt = 1;
        int x = (m - 1) / 2;
        while (x % 2 == 0) x /= 2;
        for (int i = 3; (long long)(i)*i <= x; i += 2) {
            if (x % i == 0) {
                divs[cnt++] = i;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            divs[cnt++] = x;
        }
        for (int g = 2;; g++) {
            bool ok = true;
            for (int i = 0; i < cnt; i++) {
                if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) return g;
        }
    }
    template <int m> static constexpr int primitive_root = primitive_root_constexpr(m);

    template <class T>
    static constexpr T mod_inversion(T a, T modulo) {
        T s = modulo, t = a;
        T m0 = 0, m1 = 1;

        while (t) {
            T u = s / t;
            s -= t * u;
            m0 -= m1 * u;  

            auto tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        if (m0 < 0) m0 += modulo / s;
        return m0;
    }

    static long long garner(const vector<long long>& d, const vector<long long>& p) {
        static int nm = d.size();
        vector<long long> kp(nm + 1, 0), rmult(nm + 1, 1);
        for (int ii = 0; ii < nm; ii++) {
            long long x = (d[ii] - kp[ii]) * mod_inversion(rmult[ii], p[ii]) % p[ii];
            x = (x + p[ii]) % p[ii];
            for (int iii = ii + 1; iii < nm + 1; iii++) {
                kp[iii] = (kp[iii] + rmult[iii] * x) % p[iii];
                rmult[iii] = (rmult[iii] * p[ii]) % p[iii];
            }
        }
        return kp[nm];
    }

    template <class mint>
    static void butterfly(vector<mint>& a) {
        static int g = primitive_root<mint::getmod()>;
        int n = int(a.size());
        int h = 0;
        while ((1U << h) < (unsigned int)(n)) h++;

        static bool first = true;
        static mint sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
        if (first) {
            first = false;
            mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
            int cnt2 = __builtin_ctz(mint::getmod() - 1);
            mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();
            for (int i = cnt2; i >= 2; i--) {
                // e^(2^i) == 1
                es[i - 2] = e;
                ies[i - 2] = ie;
                e *= e;
                ie *= ie;
            }
            mint now = 1;
            for (int i = 0; i <= cnt2 - 2; i++) {
                sum_e[i] = es[i] * now;
                now *= ies[i];
            }
        }
        for (int ph = 1; ph <= h; ph++) {
            int w = 1 << (ph - 1), p = 1 << (h - ph);
            mint now = 1;
            for (int s = 0; s < w; s++) {
                int offset = s << (h - ph + 1);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * now;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                now *= sum_e[__builtin_ctz(~(unsigned int)(s))];
            }
        }
    }

    template <class mint>
    static void butterfly_inv(vector<mint>& a) {
        static constexpr int g = primitive_root<mint::getmod()>;
        int n = int(a.size());
        int h = 0;
        while ((1U << h) < (unsigned int)(n)) h++;

        static bool first = true;
        static mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
        if (first) {
            first = false;
            mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
            int cnt2 = __builtin_ctz(mint::getmod() - 1);
            mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();
            for (int i = cnt2; i >= 2; i--) {
                // e^(2^i) == 1
                es[i - 2] = e;
                ies[i - 2] = ie;
                e *= e;
                ie *= ie;
            }
            mint now = 1;
            for (int i = 0; i <= cnt2 - 2; i++) {
                sum_ie[i] = ies[i] * now;
                now *= es[i];
            }
        }

        for (int ph = h; ph >= 1; ph--) {
            int w = 1 << (ph - 1), p = 1 << (h - ph);
            mint inow = 1;
            for (int s = 0; s < w; s++) {
                int offset = s << (h - ph + 1);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] =
                        (unsigned long long)(mint::getmod() + l.val() - r.val()) *
                        inow.val();
                }
                inow *= sum_ie[__builtin_ctz(~(unsigned int)(s))];
            }
        }
    }
} convo;  // convolution