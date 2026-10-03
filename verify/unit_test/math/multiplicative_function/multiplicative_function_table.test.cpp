// competitive-verifier: STANDALONE

#include <cstdint>

#include "../../../../math/multiplicative_function/arbitrary_table.hpp"
#include "../../../../math/multiplicative_function/famous_function.hpp"
#include "../../../../math/multiplicative_function/famous_function_table.hpp"
#include "../../../../random/gen.hpp"
#include "../../../../template/template.hpp"

using namespace std;

unsigned external_unsigned_function(unsigned p, unsigned e) { return p + e; }
long long external_signed_function(long long p, long long e) { return p + e; }

static_assert(kk2::UnsignedTwoArgsFunctionPointer<decltype(&external_unsigned_function)>);
static_assert(!kk2::UnsignedTwoArgsFunctionPointer<decltype(&external_signed_function)>);

int main() {
    assert((kk2::MultiplicativeFunctionTable<unsigned, external_unsigned_function>::val(2) == 3));

    int iter = 1000;
    rep(iter) {
        int n = kk2::random::rng(2, 1000000);

        assert((kk2::MultiplicativeFunctionTable<int, kk2::mf::mobius>::val(n)
                == kk2::FamousFunctionTable::mobius(n)));
        assert((kk2::MultiplicativeFunctionTable<unsigned, kk2::mf::euler_phi>::val(n)
                == kk2::FamousFunctionTable::euler_phi(n)));
        assert((kk2::MultiplicativeFunctionTable<unsigned, kk2::mf::sigma0>::val(n)
                == kk2::FamousFunctionTable::sigma0(n)));
        assert((kk2::MultiplicativeFunctionTable<std::uint64_t, kk2::mf::sigma1>::val(n)
                == kk2::FamousFunctionTable::sigma1(n)));
    }

    return 0;
}
