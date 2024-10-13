#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument" 

#include "../../geometry/point.hpp"
#include "../../geometry/argument_sort.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    vc<kk2::Point<i64>> p(n);
    kin >> p;
    kk2::ArgumentSort<i64>().argument_sort(p);
    rep (i, n) kout << p[i] << endl;

    return 0;
}
