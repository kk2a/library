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
long long modpow(long long p, long long ex, long long modullo) {
    p = (p % modullo + modullo) % modullo;
    if (!ex) return 1;
    long long Q = modpow(p, ex / 2, modullo);
    if (ex % 2 == 1) return Q * Q % modullo * p % modullo;
    return Q * Q % modullo;
}