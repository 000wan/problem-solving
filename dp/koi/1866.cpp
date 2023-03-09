#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 3000;
const int MAX_M = 1e4+1;

int N, a[MAX_N], c, d;

int dp[MAX_N+1][MAX_M];
int mcost[MAX_N+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        M = max(M, a[i]);
    }
    cin >> c >> d;

    sort(a, a+N);
    fill(&dp[0][0], &dp[0][M]+1, INF);
    for (int i = 1; i <= N; ++i) {
        mcost[i] = dp[i][0] = mcost[i-1] + c*a[i-1];
        for (int m = 1; m <= M; ++m) {
            dp[i][m] = min(mcost[i-1] + d, dp[i-1][m]) + c*abs(a[i-1]-m);
            mcost[i] = min(mcost[i], dp[i][m]);
        }
    }
    cout << mcost[N] << '\n';

    return 0;
}
