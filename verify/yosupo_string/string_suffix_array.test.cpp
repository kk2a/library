#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray" 

#include "../../string/suffix_array.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    string s;
    kin >> s;
    kk2::SuffixArray sa(s);
    kout << sa.get_sa() << "\n";

    return 0;
}
