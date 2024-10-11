#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560" 

#include "../../data_structure/prefix_sum_arbitrary.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vc<int> base = {n, m};
    vc<int> J_init(n * m), O_init(n * m), I_init(n * m);
    rep (i, n) {
        string s;
        cin >> s;
        rep (j, m) {
            if (s[j] == 'J') J_init[i + j * n] = 1;
            if (s[j] == 'O') O_init[i + j * n] = 1;
            if (s[j] == 'I') I_init[i + j * n] = 1;
        }
    }

    kk2::PrefixSumArbitrary<int> J_ps(base, J_init), O_ps(base, O_init), I_ps(base, I_init);
    rep (k) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1;
        cout << J_ps.sum({x1, y1}, {x2, y2}) << " " << O_ps.sum({x1, y1}, {x2, y2}) << " " << I_ps.sum({x1, y1}, {x2, y2}) << "\n";
    }

    return 0;
}
