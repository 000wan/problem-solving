#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N;
    cin >> N;

    int a[N+1];
    for (int i = 1; i <= N; ++i)
        cin >> a[i];

    int dp[N+1] = {};
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= k; ++i) {
            dp[k] = max(dp[k], a[i]+dp[k-i]);
        }
    }

    cout << dp[N] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
