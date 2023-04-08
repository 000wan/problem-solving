#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

// default variables
const int MAX_N = 500;
int N;
bool adj[MAX_N+1][MAX_N+1];

// topological sort by BFS
vector<int> tsort_bfs(int N) {
    int deg[N+1] = {};
    for (int v = 1; v <= N; ++v) {
        for (int w = 1; w <= N; ++w) {
            deg[w] += adj[v][w];
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
        if (q.empty())
            res.push_back(v);
        else res.push_back(-1);

        for (int w = 1; w <= N; ++w) {
            if (!adj[v][w])
                continue;
            deg[w] --;
            if (deg[w] == 0)
                q.push(w);
        }
    }
    if ((int)res.size() != N)
        return vector<int>();
    return res;
}

void solve() {
    cin >> N;
    fill(&adj[1][1], &adj[N][N+1], 0);

    vector<int> a(N);
    for (auto& i : a) {
        cin >> i;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            adj[a[i]][a[j]] = 1;
        }
    }

    int M; cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (adj[a][b]) {
            adj[a][b] = 0;
            adj[b][a] = 1;
        } else {
            adj[a][b] = 1;
            adj[b][a] = 0;
        }
    }

    auto tsort = tsort_bfs(N);
    if (tsort.empty())
        cout << "IMPOSSIBLE" << '\n';
    else {
        for (auto& i : tsort) {
            cout << (i == -1 ? '?' : i) << ' ';
        }
        cout << '\n';
    }
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