#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MAX_N = 20;
    ll dp[MAX_N+1];
    dp[0] = 1;
    for (int i = 0; i < MAX_N; ++i) {
        dp[i+1] = (i+1)*dp[i] + (i%2 ? 1 : -1);
    }

    int T;
    cin >> T;

    int n;
    while (T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
