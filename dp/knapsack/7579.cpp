#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    int a[N+1];
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    int sum = 0;
    int ci[N+1];
    for (int i = 1; i <= N; ++i) {
        cin >> ci[i];
        sum += ci[i];
    }

    int dp[N+1][100*N+1] = {};
    for (int i = 1; i <= N; ++i) {
        for (int c = 0; c <= sum; ++c) {
            dp[i][c] = dp[i-1][c];
            if (c >= ci[i]) {
                dp[i][c] = max(dp[i][c], dp[i-1][c-ci[i]] + a[i]);
            }
        }
    }

    for (int c = 0; c <= sum; ++c) {
        if (dp[N][c] >= M) {
            cout << c << '\n';
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
