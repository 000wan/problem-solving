#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9;

ll dp[101][1<<10][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    for (int d = 0; d < 10; ++d) {
        dp[1][1<<d][d] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        for (int d = 0; d < 10; ++d) {
            for (int vis = 1; vis < (1<<10); ++vis) {
                if (!(vis & (1<<d))) continue;
                if (d+1 < 10) {
                    dp[i][vis][d] += dp[i-1][vis][d+1];
                    dp[i][vis][d] += dp[i-1][vis^(1<<d)][d+1];
                    dp[i][vis][d] %= MOD;
                }
                if (d-1 >= 0) {
                    dp[i][vis][d] += dp[i-1][vis][d-1];
                    dp[i][vis][d] += dp[i-1][vis^(1<<d)][d-1];
                    dp[i][vis][d] %= MOD;
                }
            }
        }
    }
    
    ll res = 0;
    for (int d = 1; d < 10; ++d) {
        res += dp[N][(1<<10)-1][d];
        res %= MOD;
    }
    cout << res << '\n';
    
    return 0;
}