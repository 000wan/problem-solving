#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    ll dp[N][K+1] = {};
    dp[0][0] = dp[1][0] = dp[0][1] = 1;
    dp[1][1] = 2;

    for (int i = 2; i < N; ++i) {
        dp[i][0] = 1;
        for (int k = 1; k <= K; ++k) {
            if (i == N-1)
                dp[i][k] = dp[i-1][k] + dp[i-3][k-1];
            else
                dp[i][k] = dp[i-1][k] + dp[i-2][k-1];
            dp[i][k] %= MOD;
        }
    }
    cout << dp[N-1][K] << '\n';

    return 0;
}
