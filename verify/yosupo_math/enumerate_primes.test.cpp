// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_primes

#include "../../math/prime_table.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, a, b;
    kin >> n >> a >> b;

    auto primes = kk2::PrimeTable::primes(n);
    int pi_n = (int)primes.size();
    auto selected_primes = primes.stride(b, a);
    kout << pi_n << " " << selected_primes.size() << kendl;
    bool first = true;
    for (int p : selected_primes) {
        if (!first) kout << " ";
        first = false;
        kout << p;
    }
    kout << kendl;

    return 0;
}
