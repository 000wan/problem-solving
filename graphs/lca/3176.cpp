#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

const int MAX_N = 1e5;
const int MAX_L = 17;
vector<pii> adj[MAX_N+1];

// LCA in O(logN) using sparse table
int cnt = 0;
int first[MAX_N+1], last[MAX_N+1];
int up[MAX_N+1][MAX_L+1], umin[MAX_N+1][MAX_L+1], umax[MAX_N+1][MAX_L+1];

void dfs(int prev, int v, int m) {
    first[v] = ++cnt;
    up[v][0] = prev;
    umin[v][0] = umax[v][0] = m;
    if (prev == v) {
        umin[v][0] = INF, umax[v][0] = -INF;
    }
    for (int i = 0; i < MAX_L; ++i) {
        up[v][i+1] = up[up[v][i]][i];
        umin[v][i+1] = min(umin[v][i], umin[up[v][i]][i]);
        umax[v][i+1] = max(umax[v][i], umax[up[v][i]][i]);
    }

    for (auto& [u, w] : adj[v]) {
        if (u == prev) 
            continue;
        dfs(v, u, w);
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

pii query(int v, int anc) {
    int m = INF, M = -INF;
    if (v == anc) return {m, M};

    for (int i = MAX_L; i >= 0; --i) {
        if (!is_ancestor(up[v][i], anc)) {
            m = min(m, umin[v][i]);
            M = max(M, umax[v][i]);
            v = up[v][i];
        }
    }
    m = min(m, umin[v][0]);
    M = max(M, umax[v][0]);
    pii ret = {m, M};
    return ret;
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
    dfs(1, 1, 0);

    int Q; cin >> Q;    
    while (Q--) {
        int v, w;
        cin >> v >> w;
        int u = lca(v, w);
        auto [m1, M1] = query(v, u);
        auto [m2, M2] = query(w, u);
        cout << min(m1, m2) << ' ' << max(M1, M2) << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    solve();
    
    return 0;
}