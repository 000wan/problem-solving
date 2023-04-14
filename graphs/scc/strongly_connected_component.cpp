#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define all(x) (x).begin(),(x).end()

const int MAX_N = 1e4;
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
vector<vector<int>> tarjan_scc(int N) {
    sccnt = vcnt = 0;
    for (int v = 1; v <= N; ++v) {
        if (!visited[v]) dfs(v);
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

    auto res = tarjan_scc(N);
    cout << res.size() << '\n';
    for (auto& comp : res) {
        for (auto& x : comp) {
            cout << x << ' ';
        }
        cout << -1 << '\n';
    }
    
    return 0;
}