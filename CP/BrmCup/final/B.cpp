#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int t[N+1];
    ll dp[N+1];

    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> t[i];
        dp[i] = t[i] + dp[i-1];
    }
    int period = dp[N];

    ll res = -1;
    for (int i = 0; i < M; ++i) {
        int p, r, c;
        cin >> p >> r >> c;

        ll time = dp[p-1];
        if (time < c) {
            if ((c-time) % period)
                time += period * ((c-time)/period + 1);
            else
                time = c;
        }
        if (p <= r)
            time += dp[r-1] - dp[p-1];
        else
            time += period - (dp[p-1] - dp[r-1]);

        res = max(res, time);
    }
    cout << res;

    return 0;
}
