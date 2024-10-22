#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B" 

#include "../../string/rolling_hash.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    // kk2::Roliha::setbase();
    string t, p;
    kin >> t >> p;
    if (t.size() < p.size()) return 0;
    kk2::Roliha rt, rp(p);
    rt.insert_back(kk2::Roliha(t.substr(0, p.size() - 1)));
    for (int i = p.size() - 1; i < (int)t.size(); ++i) {
        rt.insert_back(kk2::Roliha(t[i]));
        if (rt == rp) kout << i + 1 - int(p.size()) << "\n";
        rt.erase_front(kk2::Roliha(t[i - p.size() + 1]));
    }

    return 0;
}
