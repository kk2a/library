#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "../../math/kth_root_floor.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int t;
    cin >> t;
    rep (t) {
        u64 a, k;
        cin >> a >> k;
        cout << kk2::kth_root_floor(a, k) << "\n";
    }

    return 0;
}
