#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 2e9+1;
#define all(x) (x).begin(),(x).end()

const int MAX_N = 5e5;
vector<int> adj[MAX_N+1];

stack<int> st;
int scc_id[MAX_N+1], visited[MAX_N+1];
bool finished[MAX_N+1]; // is finished scc

int A[MAX_N+1], sumA[MAX_N+1];
bool is_stop[MAX_N+1], stopable[MAX_N+1];

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
            sumA[sccnt] += A[t];
            stopable[sccnt] |= is_stop[t];
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
    for (int v = 1; v <= N; ++v) {
        if (!visited[v]) dfs(v);
    }
}


vector<int> scc_adj[MAX_N+1];
int memo[MAX_N+1];
int dp(int c) {
    int& ret = memo[c];
    if (ret != -1) return ret;

    int sum = 0;
    bool flag = stopable[c];
    for (auto& d : scc_adj[c]) {
        if (dp(d) != INF) {
            sum = max(sum, dp(d));
            flag |= 1;
        }
    }

    ret = flag ? sum+sumA[c] : INF;
    return ret;
}

void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    int S, P;
    cin >> S >> P;
    for (int i = 0; i < P; ++i) {
        int v; cin >> v;
        is_stop[v] = 1;
    }

    tarjan_scc(N);
    for (int v = 1; v <= N; ++v) {
        for (auto& w : adj[v]) {
            if (scc_id[v] != scc_id[w])
                scc_adj[scc_id[v]].push_back(scc_id[w]);
        }
    }
    fill(&memo[0], &memo[sccnt+1], -1);
    int res = dp(scc_id[S]);
    cout << (res == INF ? 0 : res) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}