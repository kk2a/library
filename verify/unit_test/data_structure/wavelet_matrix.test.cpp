#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../../data_structure/wavelet_matrix.hpp"
#include "../../../math/pow.hpp"
#include "../../../random/gen.hpp"
#include "../../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    rep (200) {
        int n = kk2::random::rng(1, 1e4);
        int q = 1000;
        i64 MAX = kk2::pow<i64>(10, kk2::random::rng(1, 19));
        vc<i64> a = kk2::random::random_vector<i64>(n, 0, MAX);
        if (!kk2::random::rng(0, 10)) {
            // kk2::debug::outputln(kout, "aaaa");
            int l = 0;
            while (l < n) {
                int t = kk2::random::rng(1, n - l + 1);
                fill(a.begin() + l, a.begin() + l + t, kk2::random::rng(0, MAX));
                l += t;
            }
        }
        MAX = *max_element(all(a));
        chmax(MAX, 1);
    
        kk2::WaveletMatrix<i64> wm(a);
        unordered_map<i64, vc<int>> mp;
        rep (i, n) mp[a[i]].push_back(i);
    
        vc<pli> rank_query(q);
        rep (i, q) rank_query[i] = {kk2::random::rng(0, MAX), kk2::random::rng(0, n + 1)};
    
        rep (i, q) {
            auto [b, pos] = rank_query[i];
            int simple_rank = 0;
            if (mp.count(b)) simple_rank = lower_bound(all(mp[b]), pos) - mp[b].begin();
            if (simple_rank != wm.rank(b, pos)) {
                cerr << "rank" << endl;
                exit(1);
            }
        }
    
        vc<pli> select_query(q);
        rep (i, q) select_query[i] = {kk2::random::rng(0, MAX), -1};
        rep (i, q) {
            select_query[i].second = kk2::random::rng(0, min<int>(n, 2 * (mp[select_query[i].first].size() + 10)));
        }
    
        rep (i, q) {
            auto [b, k] = select_query[i];
            int simple_select = -1;
            if (mp.count(b) and k < int(mp[b].size())) simple_select = mp[b][k];
            if (simple_select != wm.select(b, k)) {
                cerr << "select" << endl;
                exit(1);
            }
        }
    }

    return 0;
}
