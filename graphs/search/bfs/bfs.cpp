#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int INF = 1e9;
#define all(x) (x).begin(),(x).end()

const int MAX_N = 1e5;
vector<int> adj[MAX_N+1];
int order = 0, visited[MAX_N+1];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = ++order;
    
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto& w : adj[v]) {
            if (!visited[w]) {
                visited[w] = ++order;
                q.push(w);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, s;
    cin >> N >> M >> s;
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int v = 1; v <= N; ++v) {
        sort(all(adj[v]));
    }

    bfs(s);
    for (int v = 1; v <= N; ++v) {
        cout << visited[v] << '\n';
    }
    
    return 0;
}