#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

const int MAX_N = 4e4;
const int MAX_L = 17;
vector<pii> adj[MAX_N+1];

// LCA in O(logN) using sparse table
int cnt = 0;
int first[MAX_N+1], last[MAX_N+1];
int up[MAX_N+1][MAX_L+1];

int depth[MAX_N+1];
void dfs(int prev, int v, int h) {
    first[v] = ++cnt;
    up[v][0] = prev;
    depth[v] = h;
    for (int i = 0; i < MAX_L; ++i) {
        up[v][i+1] = up[up[v][i]][i];
    }

    for (auto& [u, w] : adj[v]) {
        if (u == prev) 
            continue;
        dfs(v, u, h+w);
    }
    last[v] = ++cnt;
}

// is v ancestor of w
bool is_ancestor(int v, int w) {
    return first[v] <= first[w] && last[w] <= last[v];
}

int lca(int v, int w) {
    if (is_ancestor(v, w)) return v;
    if (is_ancestor(w, v)) return w;
    for (int i = MAX_L; i >= 0; --i) {
        if (!is_ancestor(up[v][i], w))
            v = up[v][i];
    }
    return up[v][0];
}



void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // LCA using sparse table
    dfs(1, 1, 0);

    int Q; cin >> Q;    
    while (Q--) {
        int v, w;
        cin >> v >> w;
        int u = lca(v, w);
        cout << (depth[v]-depth[u])+(depth[w]-depth[u]) << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    solve();
    
    return 0;
}