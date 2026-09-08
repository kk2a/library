// competitive-verifier: STANDALONE

#include <cassert>

#include "../../../fps/fps_ntt_friendly.hpp"
#include "../../../modint/mont.hpp"

using FPS = kk2::FPSNTT<kk2::mont998>;
using mint = kk2::mont998;

int main() {
    const FPS log_input{1, 1, 0, 0};
    const FPS log_result = log_input.log();
    assert(log_result[1] == mint(1));
    assert(log_result[2] == mint(2).inv() * -mint(1));
    assert(log_result[3] == mint(3).inv());

    const FPS inv_result = log_input.inv();
    const FPS inv_expected{1, -1, 1, -1};
    assert(inv_result == inv_expected);

    const FPS exp_input{0, 1, 0, 0};
    const FPS exp_result = exp_input.exp();
    assert(exp_result[0] == mint(1));
    assert(exp_result[1] == mint(1));
    assert(exp_result[2] == mint(2).inv());
    assert(exp_result[3] == mint(6).inv());
}
