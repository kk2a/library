// competitive-verifier: STANDALONE

#include <array>

#include "../../../fps/fps_arb.hpp"
#include "../../../fps/fps_ntt_friendly.hpp"
#include "../../../modint/mont.hpp"

namespace {

constexpr std::array operations{
    kk2::FPSOperation::CONVOLUTION,
    kk2::FPSOperation::LOG,
    kk2::FPSOperation::POWER,
    kk2::FPSOperation::DIVISION,
    kk2::FPSOperation::POLYNOMIAL_DIVISION,
    kk2::FPSOperation::INVERSE,
    kk2::FPSOperation::EXP,
    kk2::FPSOperation::SQRT,
};

constexpr std::array degrees{-1, 0, 1, 2};

template <class FPS> void call_at_boundary(const FPS &a, const FPS &b) {
    for (kk2::FPSOperation operation : operations) {
        for (bool is_ntt_friendly : {false, true}) {
            // Also exercise the default arguments for b and deg.
            (void)kk2::is_sparse_operation(operation, is_ntt_friendly, a);

            for (int deg : degrees) {
                (void)kk2::is_sparse_operation(operation, is_ntt_friendly, a, b, deg);
            }
        }
    }
}

template <class FPS> void test_boundaries() {
    const FPS empty;
    const FPS one{1};
    const FPS two{1, 0};

    // Empty, one-term, and two-term series cover the size boundaries used by
    // the cost model, while the degree loop covers -1, 0, 1, and 2.
    const std::array series{&empty, &one, &two};
    for (const FPS *a : series) {
        for (const FPS *b : series) call_at_boundary(*a, *b);
    }
}

} // namespace

int main() {
    test_boundaries<kk2::FPSNTT<kk2::mont998>>();
    test_boundaries<kk2::FPSArb<kk2::mont998>>();
}
