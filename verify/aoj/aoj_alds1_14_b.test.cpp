#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B" 

#include "../../string/static_rolling_hash.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    string t, p;
    kin >> t >> p;
    kk2::Roliha rt(t), rp(p);
    for (size_t i = 0; i + p.size() <= t.size(); ++i) {
        if (rt.get(i, i + p.size()) == rp.get(0, p.size())) kout << i << "\n";
    }

    return 0;
}
