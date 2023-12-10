// input
void input_graph(vector<vector<int>> &graph,
                 const int &m,
                 const bool &start1,
                 const bool &is_directed) {
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v; 
        if (start1) { u--; v--; }
        graph[u].push_back(v);
        if (!is_directed) graph[v].push_back(u);
    }
}

// {cost, vertex}
void input_wgraph(vector<vector<array<long long, 2>>> &graph,
                  const int &m,
                  const bool &start1,
                  const bool &is_directed) {
    long long u, v, c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        if (start1) { u--; v--; }
        graph[u].push_back( {c, v} );
        if (!is_directed) graph[v].push_back( {c, u} );
    }
}

// normal
vector<int> normal_bfs(const vector<vector<int>> &graph, const int &start) {
    const int siz = size(graph);
    assert(siz > start);
    vector<int> dist(siz, -1);
    dist[start] = 0;

    queue<int> que;
    que.emplace(start);

    while (!que.empty()) {
        auto q = que.front(); que.pop();
        for (auto v : graph[q]) {
            if (dist[v] != -1) continue;

            dist[v] = dist[q] + 1;
            que.emplace(v);
        }
    }
    return dist;
}


// complete_bfs
vector<int> complete_bfs(const vector<vector<int>> &complement_graph, const int start) {
    const int siz = size(complement_graph);
    assert(siz > start);
    vector<int> dist(siz, -1);
    dist[start] = 0;
    queue<int>que;
    que.push(start);

    vector<int>s, x;
    for (int i = 0; i < siz; i++) if (i != start) s.emplace_back(i);
    vector<bool>mark(siz, true);

    while (!que.empty()) {
        x.clear();
        int q = que.front(); que.pop();
        for (auto i : complement_graph[q]) mark[i] = false;

        for (auto v : s) {
            if (mark[v]) {
                dist[v] = dist[q] + 1;
                que.push(v);
            }
            else x.emplace_back(v);
        }

        for (auto i : complement_graph[q]) mark[i] = true;
        swap(s, x);
    }
    return dist;
}


// grid
vector<vector<int>> grid_bfs(vector<string> &s, char start, const string &wall = "#") {
    const int vx[] = {0, 1, 0, -1}, vy[] = {1, 0, -1, 0};
    const int h = size(s), w = size(s[0]);
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> que;
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
        if(s[i][j] == start) {
            que.emplace(i, j);
            dist[i][j] = 0;
        }
    }
    
    while(!que.empty()) {
        auto p = que.front(); que.pop();
        for(int i = 0; i < 4; i++) {
            int ny = p.first + vy[i], nx = p.second + vx[i];
            if(!(0 <= ny and ny < h and 0 <= nx and nx < w)) continue;
            if(dist[ny][nx] != -1) continue;
            if(wall.find(s[ny][nx]) != string::npos) continue;

            dist[ny][nx] = dist[p.first][p.second] + 1;
            que.emplace(ny, nx);
        }
    }
    return dist;
}


// dancing_grid
vector<vector<vector<int>>> dancing_bfs(vector<vector<string>> &s, char start, const int &t, const string &wall = "#") {
    const int vx[] = {0, 1, 0, -1}, vy[] = {1, 0, -1, 0};
    const int h = size(s[0]), w = size(s[0][0]);
    vector<vector<vector<int>>> dist(t, vector<vector<int>>(h, vector<int>(w, -1)));
    queue<array<int, 3>> que;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) for (int k = 0; k < t; k++) {
        if (s[k][i][j] == start) {
            que.push({k, i, j});
            dist[k][i][j] = 0;
        }
    }
    
    while (!que.empty()) {
        auto q = que.front(); que.pop();
        for (int i = 0; i < 4; i++) {
            int ny = q[1] + vy[i], nx = q[2] + vx[i];
            if (!(0 <= ny and ny < h and 0 <= nx and nx < w)) continue;
            if (wall.find(s[q[0]][ny][nx]) != string::npos) continue;
            ny += vy[i], nx += vx[i];
            if (dist[(q[0] + 1) % t][ny][nx] != -1) continue;

            dist[(q[0] + 1) % t][ny][nx] = dist[q[0]][q[1]][q[2]] + 1;
            que.push({(q[0] + 1) % t, ny, nx});
        }
    }
    return dist;
}


// topological_sort
vector<int> topological_sort(vector<vector<int>> graph) {
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


// diam
int diam(const vector<vector<int>> &graph) {
    vector<int> dist = normal_bfs(graph, 0);
    int big = reduce(begin(dist), end(dist), -1, [](int acc, int i){return max(acc, i);});
    int n = size(graph), idx = -1;
    rep (i, 0, n) if (dist[i] == big) idx = i; 
    dist = normal_bfs(graph, idx);
    return reduce(begin(dist), end(dist), -1, [](int acc, int i){return max(acc, i);});
}


// {cost, vertex}
array<vector<long long>, 2> dijkstra(const int &start,
                                     const vector<vector<array<long long, 2>>> &graph) {
    int n = size(graph);
    long long alt;
    const long long inf = 3343343343343343343;
    vector<long long> dist(n, inf), prev(n, -1);
    dist[start] = 0;

    priority_queue<array<long long, 2>,
                   vector<array<long long, 2>>,
                   greater<array<long long, 2>>> pq;
    pq.push( {0ll, start} );
    while (!pq.empty()) {
        auto q = pq.top(); pq.pop();
        if (dist[q[1]] < q[0]) continue;
        for (auto v : graph[q[1]]) {
            alt = q[0] + v[0];
            if (alt < dist[v[1]]) {
                pq.push( {alt, v[1]} );
                dist[v[1]] = alt;
                prev[v[1]] = q[1]; 
            }
        }
    }
    return {dist, prev} ;
}