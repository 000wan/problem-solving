#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

const int MAX_N = 1e4+1;
int N, W;
int a[MAX_N+1][2], dp[MAX_N][3];

int get(int f0, int f1) {
    fill(&dp[0][0], &dp[N][2], 0);
    dp[1][0] = f0, dp[1][1] = f1;
    dp[1][2] = a[1][0]+a[1][1] <= W ? max(f0,f1) : f0+f1; 

    bool low, high, vert;
    for (int i = 2; i <= N; ++i) {
        low = a[i][0]+a[i-1][0] <= W;
        high = a[i][1]+a[i-1][1] <= W;
        vert = a[i][0]+a[i][1] <= W;

        dp[i][0] = min(dp[i-1][2] + 1, low ? dp[i-1][1]+1 : INF);
        dp[i][1] = min(dp[i-1][2] + 1, high ? dp[i-1][0]+1 : INF);
        dp[i][2] = min(dp[i][0] + 1, dp[i][1] + 1, vert ? dp[i-1][2]+1 : INF, low && high ? dp[i-2][2]+2 : INF);
    }
    low = a[N][0]+a[1][0] <= W;
    high = a[N][1]+a[1][1] <= W;

    if (!f0 && !f1)
        return low && high ? dp[N-1][2] : INF;
    else if (!f0)
        return low ? dp[N][1] : INF;
    else if (!f1)
        return high ? dp[N][0] : INF;
    return dp[N][2];
}


void solve() {
    cin >> N >> W;
    for (int i = 0; i < 2*N; ++i) {
        cin >> a[i%N+1][i/N];
    }
    a[0][0] = a[0][1] = INF;

    int res = min(get(0,0)+2, get(0,1)+1, get(1,0)+1, get(1,1));
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
