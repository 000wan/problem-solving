#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 2500;

int P[MAX_N][MAX_N];
int dp[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N; ++i) {
        int b = a[i];
        bool flag = false;
        for (int j = i+1; j < N; ++j) {
            if (!flag && a[j] == b) {
                P[i][j] = 1;
            } else {
                P[i][j] = 0;
                if (b > a[j]) flag = true;
            }

            b = a[j] - min(b, a[j]);
        }
    }

    dp[0] = 0, dp[1] = 1;
    for (int j = 0; j < N; ++j) {
        dp[j+1] = dp[j] + 1;
        for (int i = 0; i < j; ++i) {
            if (P[i][j] == 1)
                dp[j+1] = min(dp[j+1], dp[i] + j-i);
        }
    }
    cout << dp[N] << '\n';

    return 0;
}
