#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

const int MAX_N = 3e5;
int N, K;
vector<int> adj[MAX_N+1];

int len[MAX_N+1];
int dp(int prev, int v) {
    int res = 0;

    int l = INF, k = INF+1;
    for (auto& w : adj[v]) {
        if (w == prev) continue;
        res += dp(v,w);
        if (len[w] < l) {
            k = l;
            l = len[w];
        } else if (len[w] < k) {
            k = len[w];
        }
    }

    if (l+1 <= K) {
        len[v] = l+1;
        if (l+k+2 <= K) {
            res -= 1;
            len[v] = INF;
        }
    } else {
        len[v] = 0;
        res += 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0, v, w; i < N-1; ++i) {
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    cout << dp(-1, 1) << '\n';

    return 0;
}
