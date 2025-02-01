#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes" 

#include "../../math/multiplicative_function/prime_counting.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    i64 n;
    kin >> n;
    kout << kk2::prime_counting(n) << kendl;

    return 0;
}
