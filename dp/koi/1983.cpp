#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 400;

int dp[MAX_N+1][MAX_N+1][MAX_N+1];

int max(int a, int b, int c) {
    return max(a, max(b,c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int Na = 0, Nb = 0, x;
    int a[N+1], b[N+1];
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (x != 0) a[++Na] = x;
    }
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (x != 0) b[++Nb] = x;
    }

    dp[0][0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int l = 1; l <= Na; ++l) {
            for (int r = 1; r <= Nb; ++r) {
                dp[i][l][r] = max(dp[i-1][l-1][r], dp[i-1][l][r-1], dp[i-1][l-1][r-1] + a[l]*b[r]);
            }
        }
    }
    cout << dp[N][Na][Nb] << '\n';

    return 0;
}
