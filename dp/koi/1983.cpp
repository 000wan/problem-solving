#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 400;

int dp[MAX_N+1][MAX_N+1][MAX_N+1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int x;
    vector<int> a, b;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (x != 0) a.push_back(x);
    }
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (x != 0) b.push_back(x);
    }

    int N1 = a.size(), N2 = b.size();
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int l = 1; l <= N1; ++l) {
            for (int r = 1; r <= N2; ++r) {
                dp[i][l][r] = -INF;
                if (i > l)
                    dp[i][l][r] = max(dp[i][l][r], dp[i-1][l][r-1]);
                if (i > r)
                    dp[i][l][r] = max(dp[i][l][r], dp[i-1][l-1][r]);
                dp[i][l][r] = max(dp[i][l][r], dp[i-1][l-1][r-1] + a[l-1]*b[r-1]);
            }
        }
    }
    cout << dp[N][N1][N2] << '\n';

    return 0;
}

