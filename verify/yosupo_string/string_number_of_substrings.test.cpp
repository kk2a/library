#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings" 

#include "../../string/suffix_array.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    string s;
    kin >> s;
    kk2::SuffixArray sa(s);
    kk2::LCPArray lcp(sa);
    kout << s.size() * (s.size() + 1) / 2 - accumulate(all(lcp.lcp), 0ll) << kendl;

    return 0;
}
