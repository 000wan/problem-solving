#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;
const int MAX_N = 500;

int N, M;
int a[MAX_N+2][MAX_N+2];
int dp[MAX_N+1][MAX_N+1];

int dfs(int i, int j) {
    if (i == 0 || i == M+1 || j == 0 || j == N+1)
        return 0;
    if (i == 1 && j == 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    dp[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
        if (a[i+dx[k]][j+dy[k]] > a[i][j]) {
           dp[i][j] += dfs(i+dx[k], j+dy[k]);
        }
    }

    return dp[i][j];
}

void solve() {
    cin >> M >> N;
    
    for (int i = 0; i <= M+1; ++i) {
        for (int j = 0; j <= N+1; ++j) {
            if (i == 0 || i == M+1 || j == 0 || j == N+1) {
                a[i][j] = INF;
                continue;
            }
            dp[i][j] = -1;
            cin >> a[i][j];
        }
    }

    cout << dfs(M, N) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
