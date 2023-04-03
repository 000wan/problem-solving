#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int a[N], dp[N+1] = {}, res = 1;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        dp[a[i]] = dp[a[i]-1]+1;
        res = max(res, dp[a[i]]);
    }
    cout << N-res << '\n';
    
    return 0;
}