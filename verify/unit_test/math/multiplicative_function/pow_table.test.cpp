// competitive-verifier: STANDALONE

#include "../../../../math/multiplicative_function/pow_table.hpp"

#include <cassert>

#include "../../../../modint/mont.hpp"

int main() {
    using mint = kk2::mont998;

    const auto zero_power = kk2::pow_table<mint>(0, 8);
    assert(zero_power.size() == 9);
    for (const mint value : zero_power) assert(value == mint(1));

    const auto fifth_power = kk2::pow_table<mint>(5, 10);
    assert(fifth_power.size() == 11);
    for (int i = 0; i <= 10; ++i) assert(fifth_power[i] == kk2::pow<mint>(mint(i), 5));

    assert(kk2::pow_table<mint>(3, 0) == std::vector<mint>{mint(0)});
    assert((kk2::pow_table<mint>(3, 1) == std::vector<mint>{mint(0), mint(1)}));

    return 0;
}
