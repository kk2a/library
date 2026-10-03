// competitive-verifier: STANDALONE

#include <cassert>

#include "../../../fps/fps_arb.hpp"
#include "../../../fps/fps_ntt_friendly.hpp"
#include "../../../fps/power_sum.hpp"
#include "../../../modint/mont.hpp"
#include "../../../random/gen.hpp"

namespace {

template <class FPS> typename FPS::value_type naive_sum(const FPS &f, unsigned n) {
    using mint = FPS::value_type;
    mint result = 0;
    for (unsigned i = 0; i < n; ++i) result += f.eval(mint(i));
    return result;
}

template <class FPS> void test_sum_of_polynomial() {
    using mint = FPS::value_type;

    assert(kk2::sum_of_polynomial(FPS{}, 0U) == mint(0));
    assert(kk2::sum_of_polynomial(FPS{}, 100U) == mint(0));

    const FPS constant{7};
    assert(kk2::sum_of_polynomial(constant, 0U) == mint(0));
    assert(kk2::sum_of_polynomial(constant, 20U) == mint(140));

    const FPS known{3, 2, 1};
    for (unsigned n = 0; n <= 30; ++n) {
        assert(kk2::sum_of_polynomial(known, n) == naive_sum(known, n));
    }

    for (int iteration = 0; iteration < 100; ++iteration) {
        const int degree = static_cast<int>(kk2::random::rng(0, 31));
        FPS f(degree + 1);
        for (auto &coefficient : f) coefficient = kk2::random::rng(-1000, 1001);

        const unsigned n = static_cast<unsigned>(kk2::random::rng(0, 101));
        assert(kk2::sum_of_polynomial(f, n) == naive_sum(f, n));
    }
}

} // namespace

int main() {
    test_sum_of_polynomial<kk2::FPSNTT<kk2::mont998>>();
    test_sum_of_polynomial<kk2::FPSArb<kk2::mont107>>();
    return 0;
}
