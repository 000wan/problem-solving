#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 500;

vector<int> adj[MAX_N+1];
bool visited[MAX_N+1];

bool dfs(int prev, int v) {
    visited[v] = true;

    bool ret = true;
    for (auto& w: adj[v]) {
        if (w == prev) continue;
        if (!visited[w])
            ret &= dfs(v, w);
        else return false;
    }
    return ret;
}

void solve(int t, int n, int m) {
    for (int v = 1; v <= n; ++v) {
        adj[v].clear();
        visited[v] = false;
    }

    int v, w;
    for (int i = 0; i < m; ++i) {
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    int res = 0;
    for (int v = 1; v <= n; ++v) {
        if (visited[v]) continue;
        if (dfs(-1, v)) res++;
    }

    if (res == 0) {
        cout << "Case "<<t<<": No trees." << '\n';
    } else if (res == 1) {
        cout << "Case "<<t<<": There is one tree." << '\n';
    } else {
        cout << "Case "<<t<<": A forest of "<<res<<" trees." << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int t = 0;
    while (++t) {
        cin >> n >> m;
        if (!n && !m) break;
        solve(t, n, m);
    }

    return 0;
}
