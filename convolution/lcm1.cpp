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


struct Erato {
    vector<bool> isprime;
    vector<int> minfactor;
    vector<int> mobius;
    vector<int> primes;

    Erato(int N) : isprime(N + 1, true), minfactor(N + 1, -1),
                   mobius(N + 1, 1) {
        isprime[1] = false;
        minfactor[1] = 1;

        for (int p = 2; p <= N; ++p) {
            if (!isprime[p]) continue;

            minfactor[p] = p;
            mobius[p] = -1;
            primes.emplace_back(p);
            
            for (int q = p * 2; q <= N; q += p) {
                isprime[q] = false;
                
                if (minfactor[q] == -1) minfactor[q] = p;
                if ((q / p) % p == 0) mobius[q] = 0;
                else mobius[q] = -mobius[q];
            }
        }
    }

    vector<pair<int, int>> factorize(int n) {
        vector<pair<int, int>> res;
        while (n > 1) {
            int p = minfactor[n];
            int exp = 0;

            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }  

    vector<int> divisors(int n) {
        vector<int> res({1});
        auto pf = factorize(n);

        for (auto p : pf) {
            int s = (int)res.size();
            for (int i = 0; i < s; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};


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

