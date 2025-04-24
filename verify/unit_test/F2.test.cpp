#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../modint/F2.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int a, b;
    kin >> a >> b;
    kout << a + b << kendl;

    kk2::F2 x, y(0), z(1);
    assert(x == y);
    assert(x != z);
    assert(y + y == y);
    assert(z + y == z);
    assert(y + z == z);
    assert(z + z == y);
    assert(y - y == y);
    assert(z - y == z);
    assert(z - z == y);
    assert(z - y == z);
    assert(z - z == y);
    assert(y * y == y);
    assert(z * y == z);
    assert(y * z == z);
    assert(z * z == y);
    assert(y / z == y);
    assert(z / z == z);
    assert(y.pow(0) == z);
    assert(y.pow(1) == y);
    assert(z.pow(0) == z);
    assert(z.pow(1) == z);
    assert(z.inv() == z);
    assert(-z == z);
    assert(-y == y);
    return 0;
}
