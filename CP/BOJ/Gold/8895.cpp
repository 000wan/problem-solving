#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

ll binom[21][21];
void init() {
    binom[0][0] = 1;
    for (int i = 1; i <= 20; ++i) {
        binom[i][0] = binom[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
        }
    }
}

ll dp[21][21][21];
ll suml[21][21], sumr[21][21];
void memo() {
    dp[1][1][1] = dp[0][0][0] = suml[0][0] = sumr[0][0] = 1;
    for (int n = 2; n <= 20; ++n) {
        for (int l = 1; l <= n; ++l) {
            for (int r = 1; r <= n; ++r) {
                // sol 1.
                for (int k = 0; k <= n-1; ++k) {
                    dp[n][l][r] += binom[n-1][k]*sumr[k][l-1]*suml[n-1-k][r-1];
                }
                suml[n][r] += dp[n][l][r];
                sumr[n][l] += dp[n][l][r];

                // sol 2.
                dp[n][l][r] = dp[n-1][l-1][r] + dp[n-1][l][r-1] + (n-2)*dp[n-1][l][r];
            }
        }
    }
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    cout << dp[n][l][r] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init(), memo();
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
