// competitive-verifier: STANDALONE

#include "../../../template/function_util.hpp"

#include <array>
#include <cassert>
#include <functional>
#include <vector>

int main() {
    using std::vector;

    auto cube = kk2::make_vector<int>(2, 2, 3);
    assert(cube.size() == 2);
    assert(cube[0].size() == 2);
    assert(cube[0][0].size() == 3);

    kk2::fill_all(cube, 4);
    assert(cube == vector(2, vector(2, vector<int>(3, 4))));

    assert(kk2::iota_all(cube, 1) == 12);
    const vector expected_cube{
        vector{vector{1, 2, 3}, vector{4, 5, 6}   },
        vector{vector{7, 8, 9}, vector{10, 11, 12}}
    };
    assert(cube == expected_cube);

    const vector<int> one_dimensional{1, 2, 3, 4};
    const vector<vector<int>> two_dimensional{
        {1, 2},
        {},
        {3, 4}
    };
    const vector<vector<vector<int>>> three_dimensional{
        {{1}, {2}},
        {},
        {{3, 4}}
    };
    const vector<vector<int>> empty;
    const vector<vector<int>> nested_empty{{}, {}};

    assert(kk2::all_sum<long long>(one_dimensional) == 10);
    assert(kk2::all_sum<long long>(two_dimensional) == 10);
    assert(kk2::all_sum<long long>(three_dimensional) == 10);
    assert(kk2::all_sum<long long>(empty) == 0);
    assert(kk2::all_sum<long long>(nested_empty) == 0);

    assert(kk2::all_prod<long long>(one_dimensional) == 24);
    assert(kk2::all_prod<long long>(two_dimensional) == 24);
    assert(kk2::all_prod<long long>(empty) == 1);
    assert(kk2::all_min<int>(two_dimensional) == 1);
    assert(kk2::all_max<int>(two_dimensional) == 4);
    assert(kk2::all_min<int>(empty) == 0);
    assert(kk2::all_max<int>(nested_empty) == 0);

    assert(kk2::all_xor<int>(one_dimensional) == 4);
    assert(kk2::all_and<int>(one_dimensional) == 0);
    assert(kk2::all_or<int>(one_dimensional) == 7);
    assert(kk2::all_gcd<int>(two_dimensional) == 1);
    assert(kk2::all_lcm<int>(two_dimensional) == 12);
    assert(kk2::all_count(two_dimensional, 2) == 1);
    assert(kk2::all_count(nested_empty, 2) == 0);

    vector<int> empty_one_dimensional;
    kk2::fill_all(empty_one_dimensional, 9);
    assert(kk2::iota_all(empty_one_dimensional, 3) == 0);

    const auto sum = [](long long lhs, long long rhs) {
        return lhs + rhs;
    };
    assert(kk2::all_monoid_prod(two_dimensional, 0LL, sum) == 10);

    return 0;
}
