#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1e4;
const int MAX_M = 100;
int memo[MAX_N+1][MAX_M+1];
int dp(int n, int m) {
    if (n == 0 || m == 0)
        return 0;
    if (n < m)
        return dp(m, n);
    if (n%m == 0)
        return n/m;

    int& ret = memo[n][m];
    if (ret != -1)
        return ret;
    // n > m

    if (n >= 3*m)
        return ret = 1 + dp(n-m, m);

    ret = n*m;
    for (int i = 1; i <= m/2; ++i) {
        ret = min(ret, dp(n, i)+dp(n, m-i));
    }
    for (int i = 1; i <= n/2; ++i) {
        ret = min(ret, dp(m, i)+dp(m, n-i));
    }
//    printf("%d %d %d\n", n, m, ret);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    fill(&memo[0][0], &memo[MAX_N][MAX_M+1], -1);

    cout << dp(N, M) << '\n';

    return 0;
}
