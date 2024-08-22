#ifndef STRING_AHO_CORASICK_HPP
#define STRING_AHO_CORASICK_HPP 1

#include "../data_structure/trie.hpp"

template <int char_size, int margin, bool heavy=true>
struct AhoCorasick : Trie<char_size + 1, margin> {
    using Trie<char_size + 1, margin>::Trie;

    constexpr static int FAIL = char_size;
    vector<int> correct;

    void build() {
        correct.resize(this->size());
        for (int i = 0; i < (int)this->size(); ++i) {
            sort(begin(this->nodes[i].accept), end(this->nodes[i].accept));
            correct[i] = (int)this->nodes[i].accept.size();
        }
        queue<int> que;
        for (int i = 0; i <= char_size; ++i) {
            if (this->nodes[this->root].nxt[i] == -1) {
                this->nodes[this->root].nxt[i] = this->root;
            }
            else {
                this->nodes[this->nodes[this->root].nxt[i]].nxt[FAIL] = this->root;
                que.emplace(this->nodes[this->root].nxt[i]);
            }
        }
        while (!que.empty()) {
            auto& now = this->nodes[que.front()];
            int fail = now.nxt[FAIL];
            correct[que.front()] += correct[fail];
            que.pop();
            for (int i = 0; i < char_size; ++i) {
                if (now.nxt[i] == -1) {
                    now.nxt[i] = this->nodes[fail].nxt[i];
                }
                else {
                    this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];
                    if (heavy) {
                        auto& u = this->nodes[now.nxt[i]].accept;
                        auto& v = this->nodes[this->nodes[fail].nxt[i]].accept;
                        vector<int> accept;
                        set_union(begin(u), end(u), begin(v), end(v),
                                  back_inserter(accept));
                        u = accept;
                    }
                    que.emplace(now.nxt[i]);
                }
            }
        }
    }

    conditional_t<heavy, unordered_map<int, long long>, long long> match(
        const string& str, int now_=0) {
        unordered_map<int, int> visit_cnt;
        for (char c : str) {
            now_ = this->nodes[now_].nxt[c - margin];
            visit_cnt[now_]++;
        }
        conditional_t<heavy, unordered_map<int, long long>, long long> res{};
        for (auto&& [now, cnt] : visit_cnt) {
            if constexpr (heavy) {
                for (int idx : this->nodes[now].accept)
                    res[idx] += cnt;
            }
            else {
                res += (long long)correct[now] * cnt;
            }
        }
        return res;
    }
};

#endif // STRING_AHO_CORASICK_HPP
