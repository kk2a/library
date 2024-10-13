#define PROBLEM "https://yukicoder.me/problems/no/430" 

#include "../../string/aho_corasick.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    string s;
    kin >> s;
    int m;
    kin >> m;
    vc<string> c(m);
    kin >> c;

    kk2::AhoCorasick<26, 'A'> ac;
    for (auto &x : c) ac.add(x);
    ac.build();
    kout << ac.all_match(s) << endl;

    return 0;
}
