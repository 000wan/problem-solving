#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp(int i, int j, int a[][2], int memo[][2]) {
    if (i < 0)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];

    int res = max(dp(i-1, 0, a, memo), dp(i-1, 1, a, memo));
    res = max(res, a[i][j] + dp(i-1, (j+1)%2, a, memo));
    memo[i][j] = res;
    return memo[i][j];
}

void solve() {
    int N;
    cin >> N;
    
    int a[N][2];
    int memo[N][2];
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < N; ++i) {
            cin >> a[i][j];
            memo[i][j] = -1;
        }
    }

    int res = max(dp(N-1, 0, a, memo), dp(N-1, 1, a, memo));
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    while(T--)
        solve();

    return 0;
}
