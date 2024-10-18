#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233" 

#include "../../math/convert_base.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    while (1) {
        int n;
        kin >> n;
        if (n == 0) break;
        auto b = kk2::convert_base<int>(n, -10);
        reverse(all(b));
        for (auto a : b) kout << a;
        kout << "\n";
    }

    return 0;
}
