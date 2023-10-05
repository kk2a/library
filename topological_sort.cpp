#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

# define rep(i, k, l) for (i64 i = (k); i < (l); ++i)
# define repi(i, k, l) for (i64 i = (k); i >= (l); --i)

constexpr i64 mod = 998244353;
constexpr i64 inf_64 = 3343343343343343343;
constexpr int inf_32 = 1334334334;

vector<int> topological_sort(vector<vector<int>> graph) {
    int n = graph.size();
	vector<int> indegree(n);
	for (int i = 0; i < n; i++) for (int j : graph[i]) indegree[j]++;
	vector<int> res;
	queue<int> que;
	for (int i = 0; i < n; i++) if (indegree[i] == 0) que.push(i);
	while (!que.empty()) {
		int ver = que.front(); que.pop();
		res.push_back(ver);
		for (int i : graph[ver]) {
			indegree[i]--;
			if (indegree[i] == 0) que.push(i);
		}
	}
	return res;
}

int main() {
    
    return 0;
}