#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

// default variables
const int MAX_N = 1e5;
vector<int> adj[MAX_N+1];

// topological sort by BFS
vector<int> tsort_bfs(int N) {
    int deg[N+1] = {};
    for (int v = 1; v <= N; ++v) {
        for (auto& w : adj[v]) {
            deg[w] ++;
        }
    }
    
    queue<int> q;
    for (int v = 1; v <= N; ++v) {
        if (deg[v] == 0)
            q.push(v);
    }
    
    vector<int> res;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        res.push_back(v);
        for (auto& w : adj[v]) {
            deg[w] --;
            if (deg[w] == 0)
                q.push(w);
        }
    }
    if ((int)res.size() != N)
        return vector<int>();
    return res;
}

// topological sort by DFS
bool visited[MAX_N+1], vistack[MAX_N+1];
bool sortable = true;
void dfs(int v, vector<int>& res) {
    visited[v] = vistack[v] = 1;
    for (auto& w : adj[v]) {
        if (vistack[w]) { // backedge found
            sortable = false;
            return;
        }
        if (!visited[w])
            dfs(w, res);
    }
    vistack[v] = 0;
    res.push_back(v);
}

vector<int> tsort_dfs(int N) {
    vector<int> res;
    for (int v = 1; v <= N; ++v) {
        if (!visited[v]) dfs(v, res);
    }
    if (!sortable)
        return vector<int>();
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // auto tsort = tsort_bfs(N);
    auto tsort = tsort_dfs(N);
    for (auto& i : tsort) {
        cout << i << '\n';
    }
    
    return 0;
}