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

    int N, k;
    cin >> N >> k;
    for (int t = 0; t < k; ++t) {
        vector<pii> a(3);
        for (auto& [x, c] : a) {
            char s;
            cin >> x >> s;
            c = (s == 'R');
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < 3; ++j) {
                auto [u, c1] = a[i];
                auto [v, c2] = a[j];
                u = (!c1 ? 2*u-2 : 2*u-1);
                v = (!c2 ? 2*v-2 : 2*v-1);
                adj[NOT(u)].push_back(v);
                adj[NOT(v)].push_back(u);
            }
        }
    }

    tarjan_scc(2*N);
    bool res = 1;
    for (int x = 0; x < N; ++x) {
        res &= scc_id[2*x] != scc_id[2*x+1];
    }
    if (!res) {
        cout << -1 << '\n';
        return 0;
    }
    
    vector<int> sol(N, -1);
    vector<pii> order;
    for (int i = 0; i < 2*N; ++i) {
        // scc id has reverse order with topological sort
        order.emplace_back(-scc_id[i], i);
    }
    sort(all(order));
    for (auto& [id, i] : order) {
        if (sol[i/2] == -1) {
            // x first then x = false
            // ~x first then x = true
            sol[i/2] = !(i%2);
        }
    }
    for (auto& x : sol) {
        cout << (x ? 'R' : 'B');
    }
    
    return 0;
}