#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N;
ll memo[51][101][2];
ll dp(int i, int r, bool flag) {
    if (i == N) return flag | (r != 0);
    // () has been mismatch or currently mismatch
    ll& ret = memo[i][r+N][flag];
    if (ret != -1) return ret;
    ret = dp(i+1, r+1, flag) + dp(i+1, r-1, flag | (r-1 < 0));
    return ret;
}

string track(int i, int r, bool flag, ll k) {
    if (i == N) return "";
    if (dp(i+1, r+1, flag) > k) {
        return "("+track(i+1, r+1, flag, k);
    } else {
        bool nflag = flag | (r-1 < 0);
        return ")"+track(i+1, r-1, nflag, k-dp(i+1, r+1, flag));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll K;
    cin >> N >> K;
    fill(&memo[0][0][0], &memo[N-1][2*N][2], -1);
    if (dp(0, 0, 0) <= K)
        cout << -1 << '\n';
    else cout << track(0, 0, 0, K) << '\n';
    
    return 0;
}