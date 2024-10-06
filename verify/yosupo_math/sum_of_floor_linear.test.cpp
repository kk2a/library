#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "../../math/floor_sum.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int t;
    cin >> t;
    rep (t) {
        i64 n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << kk2::sum_of_floor(n, m, a, b) << "\n";
    }

    return 0;
}
