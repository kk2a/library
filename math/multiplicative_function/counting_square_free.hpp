#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_COUNTING_SQUARE_FREE_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_COUNTING_SQUARE_FREE_HPP 1

#include <cmath>
#include "../enumerate_quotients.hpp"
#include "famous_function_table.hpp"

namespace kk2 {

long long counting_square_free(long long n) {
    long long I = std::pow(n, 0.2);
    long long D = kk2::sqrt_floor(n / I);
}

}


#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_COUNTING_SQUARE_FREE_HPP
