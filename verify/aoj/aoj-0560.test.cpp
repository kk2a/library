#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560" 

#include "../../data_structure/prefix_sum_2d.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vvc<int> J_init, O_init, I_init;
    J_init = O_init = I_init = vvc<int>(n, vc<int>(m));
    rep (i, n) {
        string s;
        cin >> s;
        rep (j, m) {
            if (s[j] == 'J') J_init[i][j] = 1;
            if (s[j] == 'O') O_init[i][j] = 1;
            if (s[j] == 'I') I_init[i][j] = 1;
        }
    }

    kk2::PrefixSum2D<int> J_ps(J_init), O_ps(O_init), I_ps(I_init);
    rep (k) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1;
        cout << J_ps(x1, y1, x2, y2) << " " << O_ps(x1, y1, x2, y2) << " " << I_ps(x1, y1, x2, y2) << "\n";
    }

    return 0;
}
