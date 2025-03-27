#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" 

#include "../../math/monoid/affine.hpp"
#include "../../math/monoid/max_min_sumwithsize.hpp"
#include "../../math/monoid/max.hpp"
#include "../../math/monoid/min.hpp"
#include "../../math/monoid/update.hpp"
#include "../../random/gen.hpp"
#include "../../template/template.hpp"
using namespace std;

void test() {
    
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    rep (10000) test();

    return 0;
}
