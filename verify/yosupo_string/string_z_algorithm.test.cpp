#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm" 

#include "../../string/z_algorithm.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    string s;
    kin >> s;
    kout << kk2::z_algorithm(s) << kendl;

    return 0;
}
