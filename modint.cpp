template <int p> struct ModInt {
    using mint = ModInt;

  public:
    static int Mod;
    constexpr static int getmod() { 
        if (p > 0) return p;
        else return Mod;
    }
    static void setmod(int Mod_) {
        assert(1 <= Mod_);
        Mod = Mod_;
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    ModInt() : _v(0) {}
    ModInt(long long v) {
        v %= getmod();
        v += getmod();
        v %= getmod();
        _v = v;
    } 
    ModInt(unsigned long long v) : _v(v % getmod()) {}

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == getmod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = getmod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= getmod()) _v -= getmod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += getmod() - rhs._v;
        if (_v >= getmod()) _v -= getmod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        z %= getmod();
        _v = z;
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        long long s = getmod(), t = _v;
        long long m0 = 0, m1 = 1;

        while (t) {
            long long u = s / t;
            s -= t * u;
            m0 -= m1 * u;  

            auto tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        if (m0 < 0) m0 += getmod() / s;
        return m0;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
};

using mint = ModInt<998244353>;
