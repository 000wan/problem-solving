#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int sumd(int a) {
    int res = 0;
    while (a > 0) {
        res += a%10;
        a /= 10;
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a[n];
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[i].emplace_back(x);
        while (x != sumd(x)) {
            x = sumd(x);
            a[i].emplace_back(x);
        }
    }
    
    vector<int> ind(n, 0);
    int MOD;
    int l, r;
    while (q--) {
        cin >> MOD;
        if (MOD == 1) {
            cin >> l >> r;
            for (int i = l-1; i <= r-1; ++i) {
                if (ind[i] < (int)a[i].size()-1)
                    ind[i] ++;
            }
        } else {
            cin >> x;
            x--;
            cout << a[x][ind[x]] << '\n';
        }
    }
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
