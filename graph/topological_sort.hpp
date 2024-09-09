#ifndef TOPOLOGICAL_SORT_HPP
#define TOPOLOGICAL_SORT_HPP 1

#include <vector>
#include <queue>

namespace kk2 {

template <class G>
std::vector<int> topological_sort(const G& graph) {
	int siz = size(graph);
	std::vector<int> indegree(siz);
	for (int i = 0; i < siz; i++) for (int j : graph[i]) indegree[j]++;
	std::vector<int> res;
	std::queue<int> que;
	for (int i = 0; i < siz; i++) if (indegree[i] == 0) que.push(i);
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

} // namespace kk2

#endif // TOPOLOGICAL_SORT_HPP
