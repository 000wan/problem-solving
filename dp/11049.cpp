#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    
    int r[N+1], c[N+1];
    
    for (int i = 1; i <= N; ++i) {
        cin >> r[i] >> c[i];
    }

    int dp[N+1][N+1];
    for (int i = 1; i <= N; ++i) {
        dp[i][i] = 0;
    }

    for (int j = 1; j <= N; ++j) {
        for (int i = j-1; i >= 1; --i) {
            dp[i][j] = INF;

            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + r[i]*c[k]*c[j]);
            }
        }
    }

    cout << dp[1][N] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
