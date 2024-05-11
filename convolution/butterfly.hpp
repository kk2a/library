#ifndef BUTTERFLY_HPP
#define BUTTERFLY_HPP 1

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
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

constexpr int primitive_root_constexpr(int m) {
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

template <class T, class U>
constexpr long long mod_inversion(T a, U modulo) {
    long long s = modulo, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {
        long long u = s / t;
        swap(s -= t * u, t);
        swap(m0 -= m1 * u, m1);
    }
    if (m0 < 0) m0 += modulo / s;
    return m0;
}

long long garner(const vector<long long>& d, const vector<long long>& p) {
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

template <class mint, class FPS>
void butterfly(FPS& a) {
    static int g = primitive_root<mint::getmod()>;
    int n = int(a.size());
    int h = 0;
    while ((1U << h) < (unsigned int)(n)) h++;
    static bool first = true;
    static mint sum_e2[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
    static mint sum_e3[30];
    static mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
    if (first) {
        first = false;
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
            sum_e2[i] = es[i] * now;
            now *= ies[i];
        }
        now = 1;
        for (int i = 0; i <= cnt2 - 3; i++) {
            sum_e3[i] = es[i + 1] * now;
            now *= ies[i + 1];
        }
    }

    int len = 0;
    while (len < h) {
        if (h - len == 1) {
            int p = 1 << (h - len - 1);
            mint rot = 1;
            for (int s = 0; s < (1 << len); s++) {
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * rot;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                if (s + 1 != (1 << len)) 
                    rot *= sum_e2[__builtin_ctz(~(unsigned int)(s))];
            }
            len++;
        }
        else {
            int p = 1 << (h - len - 2);
            mint rot = 1, imag = es[0];
            for (int s = 0; s < (1 << len); s++) {
                mint rot2 = rot * rot;
                mint rot3 = rot2 * rot;
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto a0 = a[i + offset];
                    auto a1 = a[i + offset + p] * rot;
                    auto a2 = a[i + offset + p * 2] * rot2;
                    auto a3 = a[i + offset + p * 3] * rot3;
                    auto a1na3imag = (a1 - a3) * imag;
                    a[i + offset] = a0 + a2 + a1 + a3;
                    a[i + offset + p] = a0 + a2 - a1 - a3;
                    a[i + offset + p * 2] = a0 - a2 + a1na3imag;
                    a[i + offset + p * 3] = a0 - a2 - a1na3imag;
                }
                if (s + 1 != (1 << len))
                rot *= sum_e3[__builtin_ctz(~(unsigned int)(s))];
            }
            len += 2;
        }
    }
}

template <class mint, class FPS>
void butterfly_inv(FPS& a) {
    static constexpr int g = primitive_root<mint::getmod()>;
    int n = int(a.size());
    int h = 0;
    while ((1U << h) < (unsigned int)(n)) h++;
    static bool first = true;
    static mint sum_ie2[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
    static mint sum_ie3[30];
    static mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
    if (first) {
        first = false;
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
            sum_ie2[i] = ies[i] * now;
            now *= es[i];
        }
        now = 1;
        for (int i = 0; i <= cnt2 - 3; i++) {
            sum_ie3[i] = ies[i + 1] * now;
            now *= es[i + 1];
        }
    }
    int len = h;
    while (len) {
        if (len == 1) {
            int p = 1 << (h - len);
            mint irot = 1;
            for (int s = 0; s < (1 << (len - 1)); s++) {
                int offset = s << (h - len +  1);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] = (l - r) * irot;
                }
                if (s + 1 != (1 << (len - 1)))
                    irot *= sum_ie2[__builtin_ctz(~(unsigned int)(s))];
            }
            len--;
        }
        else {
            int p = 1 << (h - len);
            mint irot = 1, iimag = ies[0];
            for (int s = 0; s < (1 << ((len - 2))); s++) {
                mint irot2 = irot * irot;
                mint irot3 = irot2 * irot;
                int offset = s << (h - len + 2);
                for (int i = 0; i < p; i++) {
                    auto a0 = a[i + offset];
                    auto a1 = a[i + offset + p];
                    auto a2 = a[i + offset + p * 2];
                    auto a3 = a[i + offset + p * 3];
                    auto a2na3iimag = (a2 - a3) * iimag;
                    
                    a[i + offset] = a0 + a1 + a2 + a3;
                    a[i + offset + p] = (a0 - a1 + a2na3iimag) * irot;
                    a[i + offset + p * 2] = (a0 + a1 - a2 - a3) * irot2;
                    a[i + offset + p * 3] = (a0 - a1 - a2na3iimag) * irot3;
                }
                if (s + 1 != (1 << (len - 2)))
                    irot *= sum_ie3[__builtin_ctz(~(unsigned int)(s))];
            }
            len -= 2;
        }
    }
}

template <class mint, class FPS>
void doubling(FPS &a) {
    int n = a.size();
    auto b = a;
    int z = 1;
    while (z < n) z <<= 1;
    mint invz = mint(z).inv();
    butterfly_inv<mint>(b); b *= invz;
    mint r = 1, zeta = mint(primitive_root<mint::getmod()>).
                       pow((mint::getmod() - 1) / (n << 1));
    for (int i = 0; i < n; i++) {
        b[i] *= r;
        r *= zeta;
    }
    butterfly<mint>(b);
    copy(begin(b), end(b), back_inserter(a));
}

#endif  // BUTTERFLY_HPP
