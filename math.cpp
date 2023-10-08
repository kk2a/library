// totient
long long euler_phi(long long a) {
    long long res = a, now = a;
    for (long long i = 2; i * i <= a; i++) {
        if (now % i == 0) {
            res /= i;
            res *= i - 1;
            while (now % i == 0) now /= i;
        }
    }
    if (now > 1) {
        res /= now;
        res *= now - 1;
    }
    return res;
}


// long long floor
long long fracfloor(long long a, long long b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    
    if (a >= 0) return a / b;
    return -((-a) / b) - 1;
} 


// long long ceil
long long fracceil(long long a, long long b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    
    if (a >= 0) return a / b + 1;
    return -((-a) / b);
}


// modpow
long long modpow(long long p, long long ex, long long modulo) {
    p = (p % modulo + modulo) % modulo;
    if (!ex) return 1;
    long long Q = modpow(p, ex / 2, modulo);
    if (ex % 2 == 1) return Q * Q % modulo * p % modulo;
    return Q * Q % modulo;
}


// mod_inversion
// only if gcd(a, mod) = 1
// yield x s.t. ax = 1 and 0 <= x < mod 
long long mod_inversion(long long a, long long modulo) {
    long long s = modulo, t = a;
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
    if (m0 < 0) m0 += modulo / s;
    return m0;
}