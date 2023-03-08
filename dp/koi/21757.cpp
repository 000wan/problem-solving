#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 1e5;

ll dp[MAX_N+1][5];
ll pref[MAX_N+1][5];
ll sum[MAX_N+1];

ll mod(ll a, ll b) {
    return (b+a%b)%b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }

    if (sum[N]%4) {
        cout << 0 << '\n';
        return 0;
    }
    ll s = sum[N]/4;

    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = 1;
        for (int k = 1; k < 4; ++k) {
            dp[i][k] = dp[i-1][k];
            if (s*k == sum[i])
                dp[i][k] += dp[i-1][k-1];
        }
    }
    cout << dp[N-1][3] << '\n';

    return 0;
}
