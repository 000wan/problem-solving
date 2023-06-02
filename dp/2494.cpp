#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1e4;
int N;
string a, b;

int memo[MAX_N+1][10];
int nxt[MAX_N+1][10];
int dp(int i, int l) {
    if (i == N) return 0;
    int& ret = memo[i][l];
    if (ret != -1) return ret;
    ret = INF;
    for (int d = 0; d < 10; ++d) {
        int nl = (l+d)%10;
        int r = (((a[i]-'0'+nl)%10 - (b[i]-'0')) + 10)%10;
        int t = d+r+dp(i+1, nl);
        ret = min(ret, t);
        if (ret == t)
            nxt[i][l] = d;
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    cin >> a >> b;

    fill(&memo[0][0], &memo[N-1][10], -1);
    int res = dp(0, 0);
    cout << res << '\n';
    
    for (int i = 0, l = 0; i < N; ++i) {
        int nl = (l+nxt[i][l])%10;
        int r = (((a[i]-'0'+nl)%10 - (b[i]-'0')) + 10)%10;
        
        cout << i+1 << ' ' << nxt[i][l]-r << '\n';
        l = nl;
    }
    
    return 0;
}