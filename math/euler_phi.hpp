#ifndef MATH_EULER_PHI_HPP
#define MATH_EULER_PHI_HPP 1

namespace kk2 {

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

} // namespace kk2

#endif // MATH_EULER_PHI_HPP
