template <int p>
struct LazyMontgomeryModInt {
    using mint = LazyMontgomeryModInt;
    using i32 = int32_t;
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    static constexpr u32 get_r() {
        u32 ret = p;
        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;
        return ret;
    }

    static constexpr u32 r = get_r();
    static constexpr u32 n2 = -u64(p) % p;
    static_assert(r * p == 1, "invalid, r * p != 1");
    static_assert(p < (1 << 30), "invalid, p >= 2 ^ 30");
    static_assert((p & 1) == 1, "invalid, p % 2 == 0");
    
    u32 _v;

    constexpr LazyMontgomeryModInt() : _v(0) {}
    constexpr LazyMontgomeryModInt(const i64& b)
         : _v(reduce(u64(b % p + p) * n2)) {}

    static constexpr u32 reduce(const u64& b) {
        return (b + u64(u32(b) * u32(-r)) * p) >> 32;
    }
    constexpr mint& operator+=(const mint& b) {
        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;
        return *this;
    }
    constexpr mint& operator-=(const mint& b) {
        if (i32(_v -= b._v) < 0) _v += 2 * p;
        return *this;
    }
    constexpr mint& operator*=(const mint& b) {
        _v = reduce(u64(_v) * b._v);
        return *this;
    }
    constexpr mint& operator/=(const mint& b) {
        *this *= b.inv();
        return *this;
    }

    constexpr mint operator+(const mint& b) const { return mint(*this) += b; }
    constexpr mint operator-(const mint& b) const { return mint(*this) -= b; }
    constexpr mint operator-() const { return mint() - mint(*this); }
    constexpr mint operator*(const mint& b) const { return mint(*this) *= b; }
    constexpr mint operator/(const mint& b) const { return mint(*this) /= b; }
    constexpr bool operator==(const mint &b) const {
        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);
    }
    constexpr bool operator!=(const mint &b) const {
        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);
    }

    template <class T>
    constexpr mint pow(T n) const {
        mint ret(1), mul(*this);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    constexpr mint inv() const { return pow(p - 2); }

    friend ostream& operator<<(ostream& os, const mint& x) {
        return os << x.get();
    }
    friend istream& operator>>(istream& is, mint& x) {
        i64 t; is >> t; x = mint(t);
        return (is);
    }

    constexpr u32 get() const {
        u32 ret = reduce(_v);
        return ret >= p ? ret - p : ret;
    }
    static constexpr u32 mod() { return p; }
};


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
template <class T>
constexpr T mod_inversion(T a, T modulo) {
    T s = modulo, t = a;
    T m0 = 0, m1 = 1;
    while (t) {
        T u = s / t;
        swap(s -= t * u, t);
        swap(m0 -= m1 * u, m1);
    }
    if (m0 < 0) m0 += modulo / s;
    return m0;
}
template <class mint>
void butterfly(vector<mint>& a) {
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
void butterfly_inv(vector<mint>& a) {
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


template <class mint, class T>
vector<mint> convolution(const vector<T>& aa, const vector<T>& bb) {
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

