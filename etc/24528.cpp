#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>
const int MOD = 998244353;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    vector<pii> a;
    for (int i = 0; i < N; ++i) {
        char c; int v; cin >> c >> v;
        a.emplace_back(c-'a', v);
    }

    ll dp[26] = {};
    for (int i = 1; i <= N; ++i) {
        auto [c, v] = a[i-1];
        dp[c] = (dp[c] + v) % MOD;
        ll sum = 0;
        for (int t = 0; t < 26; ++t) {
            if (t != c) sum = (sum + dp[t]) % MOD;
        }
        sum = (sum * v) % MOD;
        dp[c] = (dp[c] + sum) % MOD;
    }

    ll res = 0;
    for (int t = 0; t < 26; ++t) {
        res = (res + dp[t]) % MOD;
    }    
    cout << res << '\n';
    
    return 0;
}