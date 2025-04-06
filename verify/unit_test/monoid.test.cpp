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
    kk2::monoid::Affine<int> x11(2, 3), x12(3, 4);
    auto x13 = x11.eval(5);
    auto x14 = kk2::monoid::Affine<int>::op(x11, x12);
    auto x15 = kk2::monoid::Affine<int>::unit();
    auto x16 = kk2::monoid::Affine<int>::inv(x11);
    auto x17 = x11 == x12;
    auto x18 = x11 != x12;

    kk2::monoid::MaxMinSumWithSize<int, int> x21(1), x22(2, 3, 4, 5);
    auto x23 = kk2::monoid::MaxMinSumWithSize<int, int>::op(x21, x22);
    auto x24 = kk2::monoid::MaxMinSumWithSize<int, int>::unit();
    auto x25 = x21 == x22;
    auto x26 = x21 != x22;

    kk2::monoid::Max<int> x31(1), x32(2);
    auto x33 = kk2::monoid::Max<int>::op(x31, x32);
    auto x34 = kk2::monoid::Max<int>::unit();
    auto x35 = x31 == x32;
    auto x36 = x31 != x32;

    kk2::monoid::Min<int> x41(1), x42(2);
    auto x43 = kk2::monoid::Min<int>::op(x41, x42);
    auto x44 = kk2::monoid::Min<int>::unit();
    auto x45 = x41 == x42;
    auto x46 = x41 != x42;

    kk2::monoid::Update<int> x51(1), x52(2);
    auto x53 = kk2::monoid::Update<int>::op(x51, x52);
    auto x54 = kk2::monoid::Update<int>::unit();
    auto x55 = x51 == x52;
    auto x56 = x51 != x52;

    [&](auto, auto, auto, auto, auto, auto, auto, auto){}(x11, x12, x13, x14, x15, x16, x17, x18);
    [&](auto, auto, auto, auto, auto, auto){}(x21, x22, x23, x24, x25, x26);
    [&](auto, auto, auto, auto, auto, auto){}(x31, x32, x33, x34, x35, x36);
    [&](auto, auto, auto, auto, auto, auto){}(x41, x42, x43, x44, x45, x46);
    [&](auto, auto, auto, auto, auto, auto){}(x51, x52, x53, x54, x55, x56);
}

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    rep (10000) test();

    return 0;
}
