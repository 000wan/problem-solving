#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

const int MAX_N = 1e5;
const int MAX_L = 17;
vector<int> adj[MAX_N+1];

// LCA in O(logN) using sparse table
int cnt = 0;
int first[MAX_N+1], last[MAX_N+1];
int up[MAX_N+1][MAX_L+1];

void dfs(int prev, int v) {
    first[v] = ++cnt;
    up[v][0] = prev;
    for (int i = 0; i < MAX_L; ++i) {
        up[v][i+1] = up[up[v][i]][i];
    }

    for (auto& w : adj[v]) {
        if (w == prev) 
            continue;
        dfs(v, w);
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


// LCA in O(logN) using segment table
int depth[MAX_N+1], first[MAX_N+1];
vector<pii> euler;
void dfs(int prev, int v, int h) {
    depth[v] = h; first[v] = euler.size();
    euler.emplace_back(h, v);
    for (auto& w : adj[v]) {
        if (w == prev) 
            continue;
        dfs(v, w, h+1);
    }
    if (prev != -1)
        euler.emplace_back(depth[prev], prev);
}

int minseg[4*(2*MAX_N)];
int init_min(int node, int l, int r) {
    if (l == r)
        return minseg[node] = euler[l].second;

    int mid = (l+r)/2;
    int lv = init_min(2*node, l, mid);
    int rv = init_min(2*node+1, mid+1, r);
    return minseg[node] = depth[lv] < depth[rv] ? lv : rv;
}
int min_query(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return INF;
    if (l <= s && e <= r) return minseg[node];
    int mid = (s + e) / 2;

    int lv = min_query(2*node, s, mid, l, r);
    int rv = min_query(2*node+1, mid + 1, e, l, r);
    if (lv == INF) return rv;
    if (rv == INF) return lv;
    return depth[lv] < depth[rv] ? lv : rv;
}

int lca(int v, int w) {
    if (first[v] > first[w]) swap(v, w);
    return min_query(1, 0, euler.size()-1, first[v], first[w]);
}


void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int v, w;
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    // LCA using sparse table
    dfs(1, 1);

    // LCA using segment tree
    dfs(-1, 1, 0);
    init_min(1, 0, euler.size()-1);

    int Q; cin >> Q;    
    while (Q--) {
        int v, w;
        cin >> v >> w;
        cout << lca(v, w) << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    solve();
    
    return 0;
}