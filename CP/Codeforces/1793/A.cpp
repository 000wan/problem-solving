#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll n, m;
    cin >> n >> m;
    
    ll res = 0;
    if (m*a < b*(m+1)) {
        res = (n/(m+1))*m*a + (n%(m+1))*min(a,b);
    } else {
        res = n*b;
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
