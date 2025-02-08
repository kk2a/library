#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D" 

#include "../../math/multiplivative_function/euler_phi.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n;
    kin >> n;
    kout << kk2::euler_phi(n) << kendl;

    return 0;
}
