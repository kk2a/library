#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients" 

#include "../../math/enumerate_quotients.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    i64 n;
    kin >> n;
    kk2::EnumerateQuotients<i64> res(n);
    kout << res.size() << "\n";
    kout << res.get() << "\n";

    return 0;
}
