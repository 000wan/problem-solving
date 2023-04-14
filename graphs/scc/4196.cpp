#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define all(x) (x).begin(),(x).end()

const int MAX_N = 1e5;
vector<int> adj[MAX_N+1];

stack<int> st;
int scc_id[MAX_N+1], visited[MAX_N+1];
bool finished[MAX_N+1]; // is finished scc

int sccnt, vcnt;
int dfs(int v) {
    int ret = visited[v] = ++vcnt;
    st.push(v);

    for (auto& w : adj[v]) {
        if (!visited[w]) // forward edge
            ret = min(ret, dfs(w));
        else if (!finished[w]) // back edge
            ret = min(ret, visited[w]);
    }

    // if v is the root of SCC
    if (ret == visited[v]) {
        while (1) {
            int t = st.top(); st.pop();
            scc_id[t] = sccnt;
            finished[t] = 1;
            if (t == v) break;
        }
        sccnt ++;
    }
    // return minimal vertex reachable from its subtree
    return ret;
}

// Tarjan's SCC algorithm: O(V+E)
void tarjan_scc(int N) {
    sccnt = vcnt = 0;
    fill_n(scc_id, N+1, 0);
    fill_n(visited, N+1, 0);
    fill_n(finished, N+1, 0);
    for (int v = 1; v <= N; ++v) {
        if (!visited[v]) dfs(v);
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    tarjan_scc(N);
    int indeg[sccnt+1] = {};
    for (int v = 1; v <= N; ++v) {
        for (auto& w : adj[v]) {
            if (scc_id[v] != scc_id[w])
                indeg[scc_id[w]]++;
        }
    }
    int res = 0;
    for (int i = 0; i < sccnt; ++i) {
        res += indeg[i] == 0;
    }
    cout << res << '\n';
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