// competitive-verifier: STANDALONE

#include "../../../fps/poly_sample_point_evaluate.hpp"

#include <cassert>
#include <vector>

#include "../../../convolution/convolution_arb.hpp"
#include "../../../fps/poly_sample_point_shift.hpp"
#include "../../../modint/mont.hpp"

template <class mint> mint evaluate(const std::vector<mint> &coefficients, mint x) {
    mint result = 0;
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) {
        result *= x;
        result += *it;
    }
    return result;
}

template <class mint> void test(kk2::detail::SamplePointShiftConvolution<mint> convolve) {
    const std::vector<mint> coefficients = {3, 1, 4, 1, 5, 9};
    std::vector<mint> samples(coefficients.size());
    for (std::size_t i = 0; i < samples.size(); i++) {
        samples[i] = evaluate(coefficients, mint(i));
    }

    for (int t = 0; t < 30; t++) {
        const mint expected = evaluate(coefficients, mint(t));
        assert(kk2::sample_point_evaluate(samples, mint(t)) == expected);
        assert(kk2::sample_point_shift(samples, mint(t), 1, convolve)
               == std::vector<mint>{expected});
    }

    const auto shifted = kk2::sample_point_shift(samples, mint(20), 10, convolve);
    for (std::size_t i = 0; i < shifted.size(); i++) {
        assert(shifted[i] == evaluate(coefficients, mint(20 + i)));
    }

    const std::vector<mint> empty;
    assert(kk2::sample_point_evaluate(empty, mint(42)) == mint(0));
    assert(kk2::sample_point_shift(samples, mint(42), 0, convolve).empty());
}

int main() {
    test<kk2::mont998>(&kk2::convolution<std::vector<kk2::mont998>>);
    test<kk2::mont107>(&kk2::convolution_arb<std::vector<kk2::mont107>>);
}
