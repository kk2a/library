// competitive-verifier: STANDALONE

#include "../../../math_mod/mod_sqrt.hpp"

#include <cassert>

#include "../../../math_mod/detail/mod_sqrt.hpp"
#include "../../../modint/modint.hpp"
#include "../../../modint/mont.hpp"

namespace {

template <class mint, bool ntt_friendly = false> void test_all_residues() {
    const int mod = mint::getmod();
    for (int a = 0; a < mod; ++a) {
        const long long root = kk2::mod_sqrt_detail::mod_sqrt<ntt_friendly>(mint(a));
        bool has_root = false;
        for (int x = 0; x < mod; ++x) {
            if (static_cast<long long>(x) * x % mod == a) {
                has_root = true;
                break;
            }
        }
        assert((root != -1) == has_root);
        if (root != -1) assert(root * root % mod == a);

        const long long generic_root = kk2::mod_sqrt(a, mod);
        assert((generic_root != -1) == has_root);
        if (generic_root != -1) assert(generic_root * generic_root % mod == a);
    }
}

} // namespace

int main() {
    test_all_residues<kk2::Mont<19>>();
    test_all_residues<kk2::Mont<17>, true>();
    kk2::ModInt<0>::setmod(19);
    test_all_residues<kk2::ModInt<0>>();

    using mint = kk2::mont998;
    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(0)) == 0);
    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(1)) == 1);
    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(3)) == -1);
    for (int x = 2; x < 1000; ++x) {
        const mint square = mint(x) * x;
        const long long root = kk2::mod_sqrt_detail::mod_sqrt<true>(square);
        assert(root != -1);
        assert(mint(root) * root == square);
    }
}
