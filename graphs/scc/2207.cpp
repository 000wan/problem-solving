#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>

const int MAX_N = 2e4;
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

void tarjan_scc(int N) {
    sccnt = vcnt = 0;
    for (int v = 0; v < N; ++v) {
        if (!visited[v]) tdfs(v);
    }
}

int NOT(int x) {
    return x%2 ? x-1 : x+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> M >> N;
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        // 2k: ~x, 2k+1: x
        u = (u < 0 ? 2*(-u)-2 : 2*u-1);
        v = (v < 0 ? 2*(-v)-2 : 2*v-1);
        adj[NOT(u)].push_back(v);
        adj[NOT(v)].push_back(u);
    }

    tarjan_scc(2*N);
    bool res = 1;
    for (int x = 0; x < N; ++x) {
        res &= scc_id[2*x] != scc_id[2*x+1];
    }
    cout << (res ? "^_^" : "OTL") << '\n';
    
    return 0;
}