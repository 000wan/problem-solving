#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    int dp[N+1] = {};
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i] = 4;
        for (int x = 1; x*x <= i; ++x) {
            dp[i] = min(dp[i], dp[i-x*x]+1);
        }
    }
    cout << dp[N] << '\n';
    
    return 0;
}