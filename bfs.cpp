// normal
vector<int> normal_bfs(const vector<vector<int>> &graph, const int start) {
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