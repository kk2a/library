#ifndef TOPOLOGICAL_SORT_HPP
#define TOPOLOGICAL_SORT_HPP 1

// topological_sort
vector<int> topological_sort(const vector<vector<int>>& graph) {
    int siz = size(graph);
	vector<int> indegree(siz);
	for (int i = 0; i < siz; i++) for (int j : graph[i]) indegree[j]++;
	vector<int> res;
	queue<int> que;
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

template <class G>
vector<int> topological_sort(const G& graph) {
	int siz = size(graph);
	vector<int> indegree(siz);
	for (int i = 0; i < siz; i++) for (int j : graph[i]) indegree[j]++;
	vector<int> res;
	queue<int> que;
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

#endif // TOPOLOGICAL_SORT_HPP
