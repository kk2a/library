#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../unionfind/partial_persistent.hpp"
#include "../../unionfind/unionfind.hpp"
#include "../../random/gen.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    rep (200) {
        int n = kk2::random::rng(1, 1e4);
        kk2::PartialPersistentUnionFind ppu(n);
        kk2::UnionFind uf(n);
    
        int q = 1e3;
        vc<int> ask_size(q);
        vc<pi> ask_same(q);
        vc<int> res_size(q), res_same(q);
        rep (t, q) {
            int num = kk2::random::rng(1, 101);
            rep (num) {
                int a = kk2::random::rng(0, n);
                int b = kk2::random::rng(0, n);
                assert(ppu.unite(a, b, t) == uf.unite(a, b));
            }
            ask_size[t] = kk2::random::rng(0, n);
            res_size[t] = uf.size(ask_size[t]);
            ask_same[t] = {kk2::random::rng(0, n), kk2::random::rng(0, n)};
            res_same[t] = uf.same(ask_same[t].first, ask_same[t].second);
        }
    
        rep (t, q) {
            assert(ppu.size(ask_size[t], t) == res_size[t]);
            assert(ppu.same(ask_same[t].first, ask_same[t].second, t) == res_same[t]);
        }
    }

    return 0;
}
