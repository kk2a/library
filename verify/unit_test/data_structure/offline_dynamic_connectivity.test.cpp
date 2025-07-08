#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../data_structure/offline_dynamic_connectivity.hpp"
#include "../../unionfind/unionfind.hpp"
#include "../../random/gen.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    rep (200) {
        int n = 10000;
        int q = 1000;
        vc<array<int, 3>> query(q);
        vc<pi> insert_query;
        rep (i, q) {
            int t = kk2::random::rng(0, 4);
            query[i][0] = t;
            if (t == 0) {
                int a = kk2::random::rng(0, n - 1);
                int b = kk2::random::rng(a, n);
                query[i][1] = a;
                query[i][2] = b;
                insert_query.emplace_back(a, b);
            } else if (t == 1) {
                if (insert_query.empty() or kk2::random::rng(0, 2)) {
                    int a = kk2::random::rng(0, n - 1);
                    int b = kk2::random::rng(a, n);
                    query[i][1] = a;
                    query[i][2] = b;
                } else {
                    int idx = kk2::random::rng(0, (int)insert_query.size());
                    query[i][1] = insert_query[idx].first;
                    query[i][2] = insert_query[idx].second;
                }
            } else if (t == 2) {
                int a = kk2::random::rng(0, n);
                query[i][1] = a;
            } else if (t == 3) {
                int a = kk2::random::rng(0, n - 1);
                int b = kk2::random::rng(a, n);
                query[i][1] = a;
                query[i][2] = b;
            }
        }
    
        vc<int> res(q);
        kk2::OfflineDynamicConnectivity odc(n, q);
        rep (i, q) {
            if (query[i][0] == 0) odc.add_edge(i, query[i][1], query[i][2]);
            if (query[i][0] == 1) odc.del_edge(i, query[i][1], query[i][2]);
        }
        odc.build();
        odc.run([&](int i) {
            if (query[i][0] == 2) res[i] = odc.uf.size(query[i][1]);
            if (query[i][0] == 3) res[i] = odc.uf.same(query[i][1], query[i][2]);
        });
    
        std::set<pi> edges;
        vc<int> res2(q);
        rep (i, q) {
            if (query[i][0] == 0) {
                edges.emplace(query[i][1], query[i][2]);
            } else if (query[i][0] == 1) {
                edges.erase(pi(query[i][1], query[i][2]));
            } else if (query[i][0] == 2) {
                kk2::UnionFind uf(n);
                for (auto [a, b] : edges) {
                    uf.unite(a, b);
                }
                res2[i] = uf.size(query[i][1]);
            } else {
                kk2::UnionFind uf(n);
                for (auto [a, b] : edges) {
                    uf.unite(a, b);
                }
                res2[i] = uf.same(query[i][1], query[i][2]);
            }
        }
        assert(res == res2);
    }

    return 0;
}
