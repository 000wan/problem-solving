#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 2000;

int N;
int a[MAX_N+1], b[MAX_N+1];

int memo[MAX_N+1][MAX_N+1];
int dp(int l, int r) {
    if (memo[l][r] != -1)
        return memo[l][r];
    if (l == N || r == N)
        return memo[l][r] = 0;

    int res = 0;
    if (a[l] > b[r])
        res = b[r]+dp(l, r+1);
    else
        res = max(dp(l+1, r), dp(l+1, r+1));

    return memo[l][r] = res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            memo[i][j] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    } 
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    } 
    cout << dp(0,0) << '\n';

    return 0;
}
