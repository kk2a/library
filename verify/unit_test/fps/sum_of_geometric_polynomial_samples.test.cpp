// competitive-verifier: STANDALONE

#include <cassert>
#include <cstdint>
#include <vector>

#include "../../../math_mod/power_sum.hpp"
#include "../../../modint/mont.hpp"

namespace {

using mint = kk2::mont998;

template <class Mint> Mint evaluate(const std::vector<Mint> &coefficients, Mint x) {
    Mint result = 0;
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) {
        result = result * x + *it;
    }
    return result;
}

template <class Mint, class T> Mint naive_sum(const std::vector<Mint> &coefficients, Mint r, T n) {
    Mint result = 0;
    Mint rp = 1;
    for (T i = 0; i < n; ++i, rp *= r) { result += rp * evaluate(coefficients, Mint(i)); }
    return result;
}

template <class Mint, class T> Mint reference_sum(const std::vector<Mint> &samples, Mint r, T n) {
    if (n == 0) return 0;
    if (r == Mint(0)) return samples[0];
    if (r == Mint(1)) return kk2::sum_of_polynomial_samples(samples, n);

    const int k = static_cast<int>(samples.size()) - 1;
    kk2::Comb<Mint>::set_upper(static_cast<kk2::usize>(k + 1));
    std::vector<Mint> prefix(samples.size());
    Mint r_power = 1;
    for (kk2::usize i = 0; i < samples.size(); ++i, r_power *= r) {
        prefix[i] = (i == 0 ? samples[i] * r_power : prefix[i - 1] + samples[i] * r_power);
    }

    Mint c = 0;
    Mint minus_r_power = 1;
    for (int i = 0; i <= k; ++i, minus_r_power *= -r) {
        c += kk2::Comb<Mint>::binom(static_cast<kk2::u32>(k + 1), static_cast<kk2::u32>(i))
             * minus_r_power * prefix[k - i];
    }
    c /= (Mint(1) - r).pow(k + 1);

    std::vector<Mint> tail(samples.size());
    Mint inverse_r_power = 1;
    const Mint inverse_r = r.inv();
    for (kk2::usize i = 0; i < samples.size(); ++i, inverse_r_power *= inverse_r) {
        tail[i] = (prefix[i] - c) * inverse_r_power;
    }
    const Mint tail_value = kk2::sample_point_evaluate(tail, Mint(n - 1));
    return c + r.pow(n - 1) * tail_value;
}

void test_polynomial_samples() {
    for (unsigned degree = 0; degree <= 8; ++degree) {
        std::vector<mint> coefficients(degree + 1);
        for (unsigned i = 0; i <= degree; ++i) coefficients[i] = mint(3 * i + 1);

        std::vector<mint> samples(degree + 1);
        for (unsigned i = 0; i <= degree; ++i) samples[i] = evaluate(coefficients, mint(i));

        for (const mint r : {mint(0), mint(1), mint(2), mint(5)}) {
            for (unsigned n = 0; n <= 30; ++n) {
                assert(kk2::sum_of_geometric_polynomial_samples(r, n, samples)
                       == naive_sum(coefficients, r, n));
            }
        }
    }
}

void test_infinite_sum() {
    for (const mint r : {mint(0), mint(2), mint(5)}) {
        const mint one_minus_r = mint(1) - r;
        assert(kk2::sum_of_geometric_polynomial_samples(r, std::vector<mint>{mint(3)})
               == mint(3) / one_minus_r);
        assert(kk2::sum_of_geometric_polynomial_samples(r, std::vector<mint>{mint(3), mint(5)})
               == mint(3) / one_minus_r + mint(2) * r / one_minus_r.pow(2));

        assert(kk2::sum_of_geometric_monomial(r, 0U) == mint(1) / one_minus_r);
        assert(kk2::sum_of_geometric_monomial(r, 1U) == r / one_minus_r.pow(2));
        assert(kk2::sum_of_geometric_monomial(r, 2U) == r * (mint(1) + r) / one_minus_r.pow(3));
    }
}

void test_monomial() {
    for (unsigned k = 0; k <= 8; ++k) {
        for (const mint r : {mint(0), mint(1), mint(2), mint(5)}) {
            for (unsigned n = 0; n <= 30; ++n) {
                mint expected = 0;
                mint rp = 1;
                for (unsigned i = 0; i < n; ++i, rp *= r) expected += rp * mint(i).pow(k);
                assert(kk2::sum_of_geometric_monomial(r, n, k) == expected);
            }
        }
    }
}

std::uint64_t next_random(std::uint64_t &state) {
    state ^= state << 7;
    state ^= state >> 9;
    return state;
}

void test_random_monomial() {
    std::uint64_t state = 0x0fedcba987654321ULL;
    for (int trial = 0; trial < 300; ++trial) {
        const unsigned degree = next_random(state) % 80;
        const mint r = mint(next_random(state));
        const unsigned n = degree + 2 + next_random(state) % 500;
        mint expected = 0;
        mint rp = 1;
        for (unsigned i = 0; i < n; ++i, rp *= r) expected += rp * mint(i).pow(degree);
        assert(kk2::sum_of_geometric_monomial(r, n, degree) == expected);
    }
}

void test_random_polynomial_samples() {
    std::uint64_t state = 0x123456789abcdef0ULL;
    for (int trial = 0; trial < 300; ++trial) {
        const unsigned degree = next_random(state) % 80;
        std::vector<mint> coefficients(degree + 1);
        for (auto &coefficient : coefficients) coefficient = mint(next_random(state));

        std::vector<mint> samples(degree + 1);
        for (unsigned i = 0; i <= degree; ++i) samples[i] = evaluate(coefficients, mint(i));

        const mint r = mint(next_random(state));
        const unsigned n = degree + 2 + next_random(state) % 500;
        assert(kk2::sum_of_geometric_polynomial_samples(r, n, samples)
               == naive_sum(coefficients, r, n));
        assert(kk2::sum_of_geometric_polynomial_samples(r, n, samples)
               == reference_sum(samples, r, n));
    }
}

void test_large_n() {
    std::vector<mint> coefficients{mint(7), mint(11), mint(13), mint(17), mint(19), mint(23)};
    std::vector<mint> samples(coefficients.size());
    for (unsigned i = 0; i < samples.size(); ++i) samples[i] = evaluate(coefficients, mint(i));

    const std::uint64_t period = std::uint64_t(mint::getmod()) * (mint::getmod() - 1);
    for (const mint r : {mint(2), mint(5), mint(mint::getmod() - 2)}) {
        for (const std::uint64_t offset :
             std::vector<std::uint64_t>{0, 1, 12345, std::uint64_t(mint::getmod()) + 7}) {
            assert(kk2::sum_of_geometric_polynomial_samples(r, period + offset, samples)
                   == kk2::sum_of_geometric_polynomial_samples(r, offset, samples));
            assert(kk2::sum_of_geometric_polynomial_samples(r, period + offset, samples)
                   == reference_sum(samples, r, period + offset));
        }
    }

    for (const std::uint64_t offset :
         std::vector<std::uint64_t>{0, 1, 12345, std::uint64_t(mint::getmod()) + 7}) {
        assert(kk2::sum_of_geometric_polynomial_samples(
                   mint(1), std::uint64_t(mint::getmod()) + offset, samples)
               == kk2::sum_of_geometric_polynomial_samples(mint(1), offset, samples));
        assert(kk2::sum_of_geometric_polynomial_samples(
                   mint(1), std::uint64_t(mint::getmod()) + offset, samples)
               == reference_sum(samples, mint(1), std::uint64_t(mint::getmod()) + offset));
    }
}

} // namespace

int main() {
    test_polynomial_samples();
    test_infinite_sum();
    test_monomial();
    test_random_monomial();
    test_random_polynomial_samples();
    test_large_n();
    return 0;
}
