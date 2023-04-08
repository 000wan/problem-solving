#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define all(x) (x).begin(),(x).end()

// default variables
const int MAX_N = 32000;
vector<int> adj[MAX_N+1];

// topological sort by BFS
vector<int> tsort_bfs(int N) {
    int deg[N+1] = {};
    for (int v = 1; v <= N; ++v) {
        for (auto& w : adj[v]) {
            deg[w] ++;
        }
    }
    
    priority_queue<int,vector<int>,greater<>> q;
    for (int v = 1; v <= N; ++v) {
        if (deg[v] == 0)
            q.push(v);
    }
    
    vector<int> res;
    while (!q.empty()) {
        int v = q.top(); q.pop();
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

    auto tsort = tsort_bfs(N);
    for (auto& i : tsort) {
        cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}