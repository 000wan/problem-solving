#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N;
ll memo[51][52];
ll dp(int i, int r) {
    if (i == N) return (r == 0);
    ll& ret = memo[i][r];
    if (ret != -1) return ret;
    ret = dp(i+1, r+1) + (r ? dp(i+1, r-1) : 0);
    return ret;
}

string track(int i, int r, ll k) {
    if (i == N) return "";
    if (dp(i+1, r+1) > k) {
        return "("+track(i+1, r+1, k);
    } else {
        return ")"+track(i+1, r-1, k-dp(i+1, r+1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll K;
    cin >> N >> K;
    fill(&memo[0][0], &memo[N-1][N+1], -1);
    if (dp(0, 0) <= K)
        cout << -1 << '\n';
    else cout << track(0, 0, K) << '\n';
    
    return 0;
}