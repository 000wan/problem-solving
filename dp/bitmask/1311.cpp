#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N, D[21][21];
int memo[1<<20][21];
int dp(int vis, int i) {
    if (i == 0) return 0;
    int& ret = memo[vis][i];
    if (ret != -1) return ret;
    ret = INF;
    for (int j = 0; j < N; ++j) {
        if (!(vis & (1<<j))) continue;
        ret = min(ret, dp(vis^(1<<j), i-1) + D[i][j+1]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N*N; ++i) {
        cin >> D[i/N+1][i%N+1];
    }
    fill(&memo[0][0], &memo[(1<<N)-1][N+1], -1);

    cout << dp((1<<N)-1, N) << '\n';
    
    return 0;
}