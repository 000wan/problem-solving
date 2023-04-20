#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 2500;
int N;
bool is_palin[MAX_N][MAX_N];
int dp[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a;
    cin >> a;
    N = a.size();

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i+k < N; ++i) {
            is_palin[i][i+k] = (a[i] == a[i+k]) && (k > 1 ? is_palin[i+1][i+k-1] : 1);
        }
    }

    for (int i = 0; i < N; ++i) {
        dp[i] = is_palin[0][i] ? 1 : INF;
        for (int k = 0; i-k > 0; ++k) {
            if (is_palin[i-k][i])
                dp[i] = min(dp[i], 1+dp[i-k-1]);
        }
    }
    cout << dp[N-1] << '\n';
    
    return 0;
}