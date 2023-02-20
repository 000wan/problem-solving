#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N;
vector<int> adj[500001];
int A[500001][3];

int memo[500001][3];
int dp(int i) {
    if (memo[i][0] != -1)
        return max({memo[i][0], memo[i][1], memo[i][2]});
    
    memo[i][0] = A[i][0], memo[i][1] = A[i][1], memo[i][2] = A[i][2];
    for (auto j: adj[i]) {
        dp(j);
        memo[i][0] += max(memo[j][1], memo[j][2]);
        memo[i][1] += max(memo[j][0], memo[j][2]);
        memo[i][2] += max(memo[j][0], memo[j][1]);
    }
    int res = max({memo[i][0], memo[i][1], memo[i][2]});
    return res;
}

int selected[500001];
void sol(int i, int prev) {
    int color, M = -1;
    for (int c = 0; c < 3; ++c) {
        if (c == prev) continue;
        if (memo[i][c] > M) {
            color = c;
            M = memo[i][c];
        }
    }

    selected[i] = color;
    for (auto j : adj[i]) {
        sol(j, color);
    }
}

void init(int i) {
    for (auto j : adj[i]) {
        adj[j].erase(find(adj[j].begin(), adj[j].end(), i));
        init(j);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N-1; ++i) {
        int v, w;
        cin >> v >> w;
        adj[v].emplace_back(w);
        adj[w].emplace_back(v);
    }
    init(1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
        memo[i][0] = memo[i][1] = memo[i][2] = -1;
    }
    
    char colors[3] = {'R', 'G', 'B'};
    int res = dp(1);
    cout << res << '\n';

    sol(1, -1);
    for (int i = 1; i <= N; ++i) {
        cout << colors[selected[i]];
    }

    return 0;
}
