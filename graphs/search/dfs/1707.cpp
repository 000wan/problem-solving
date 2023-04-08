#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;
const int INF = 1e9;
#define all(x) (x).begin(),(x).end()

const int MAX_N = 2e5;
vector<int> adj[MAX_N+1];
int visited[MAX_N+1];
bool flag = true;
void dfs(int v, int color) {
    visited[v] = color;
    for (auto& w : adj[v]) {
        if (!visited[w])
            dfs(w, color%2 + 1);
    }
    for (auto& w : adj[v]) {
        if (visited[w] == color) {
            flag = false;
            return;
        }
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    fill(&adj[1], &adj[N+1], vector<int>());
    fill(&visited[1], &visited[N+1], 0);
    flag = true;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int v = 1; v <= N; ++v) {
        if (!visited[v])
            dfs(v, 1);
    }
    cout << (flag ? "YES" : "NO") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}