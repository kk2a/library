// competitive-verifier: STANDALONE

#include <cassert>
#include <cstdint>

#include "../../../math_mod/comb.hpp"

namespace {

struct CountingMint {
    static constexpr unsigned int modulus = 998244353;
    static inline int inversion_count = 0;

    unsigned int value = 0;

    CountingMint() = default;
    CountingMint(long long x) {
        x %= modulus;
        if (x < 0) x += modulus;
        value = static_cast<unsigned int>(x);
    }

    static constexpr unsigned int getmod() { return modulus; }

    unsigned int val() const { return value; }

    CountingMint &operator*=(const CountingMint &rhs) {
        value = static_cast<unsigned int>(static_cast<std::uint64_t>(value) * rhs.value % modulus);
        return *this;
    }

    CountingMint pow(unsigned int exponent) const {
        CountingMint result = 1;
        CountingMint base = *this;
        while (exponent > 0) {
            if (exponent & 1) result *= base;
            base *= base;
            exponent >>= 1;
        }
        return result;
    }

    CountingMint inv() const {
        ++inversion_count;
        return pow(modulus - 2);
    }

    friend CountingMint operator*(CountingMint lhs, const CountingMint &rhs) { return lhs *= rhs; }
    friend CountingMint operator-(const CountingMint &value) {
        return value.value == 0 ? CountingMint(0) : CountingMint(modulus - value.value);
    }
    friend bool operator==(const CountingMint &, const CountingMint &) = default;
};

} // namespace

int main() {
    using comb = kk2::Comb<CountingMint>;

    comb::set_upper(1);
    assert(CountingMint::inversion_count == 1);
    comb::set_upper(2);
    assert(CountingMint::inversion_count == 1);

    constexpr int upper = 100000;
    for (int i = 0; i <= upper; ++i) { assert(comb::fact(i) * comb::ifact(i) == CountingMint(1)); }

    // Geometric growth needs only logarithmically many modular inversions.
    assert(CountingMint::inversion_count <= 20);
    return 0;
}
