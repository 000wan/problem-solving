#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define all(x) (x).begin(),(x).end()

const int MAX_N = 1e4;
vector<int> adj[MAX_N+1];

stack<int> st;
int sccnt, vcnt;
int scc_id[MAX_N+1], visited[MAX_N+1];
bool finished[MAX_N+1]; // is finished scc

// Tarjan's SCC algorithm: O(V+E)
int tdfs(int v) {
    int ret = visited[v] = ++vcnt;
    st.push(v);

    for (auto& w : adj[v]) {
        if (!visited[w]) // forward edge
            ret = min(ret, tdfs(w));
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

vector<vector<int>> tarjan_scc(int N) {
    sccnt = vcnt = 0;
    for (int v = 1; v <= N; ++v) {
        if (!visited[v]) tdfs(v);
    }
    vector<vector<int>> res(sccnt, vector<int>());
    for (int v = 1; v <= N; ++v) {
        res[scc_id[v]].push_back(v);
    }
    sort(all(res));
    return res;
}

// Kosaraju's SCC algorithm: O(V+E)
vector<int> adj_t[MAX_N+1];
void kdfs(int v) {
    visited[v] = 1;
    for (auto& w : adj[v]) {
        if (!visited[w]) kdfs(w);
    }
    st.push(v);
}
void backdfs(int v) {
    scc_id[v] = sccnt;
    finished[v] = 1;
    for (auto& w : adj_t[v]) {
        if (!finished[w]) backdfs(w);
    }
}

vector<vector<int>> kosaraju_scc(int N) {
    for (int v = 1; v <= N; ++v) {
        for (auto& w : adj[v]) {
            adj_t[w].push_back(v);
        }
    }

    sccnt = 0;
    for (int v = 1; v <= N; ++v) {
        if (!visited[v]) kdfs(v);
    }
    while (!st.empty()) {
        int v = st.top(); st.pop();
        if (!finished[v]) {
            backdfs(v);
            sccnt++;
        }
    }

    vector<vector<int>> res(sccnt, vector<int>());
    for (int v = 1; v <= N; ++v) {
        res[scc_id[v]].push_back(v);
    }
    sort(all(res));
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

    auto res = kosaraju_scc(N);
    cout << res.size() << '\n';
    for (auto& cc : res) {
        for (auto& x : cc) {
            cout << x << ' ';
        }
        cout << -1 << '\n';
    }
    
    return 0;
}