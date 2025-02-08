#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes" 

#include "../../math/prime_table.hpp"
#include "../../math/frac_floor.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, a, b;
    kin >> n >> a >> b;

    auto primes = kk2::PrimeTable::primes(n);
    int pi_n = (int)primes.size();
    int m = kk2::fracceil(pi_n - b, a);
    kout << pi_n << " " << m << kendl;
    for (int i = 0; i < m; i++) {
        if (i) kout << " ";
        kout << primes[i * a + b];
    }
    kout << kendl;

    return 0;
}
