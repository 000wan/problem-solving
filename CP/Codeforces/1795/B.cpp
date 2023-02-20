#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a;
    int s[51] = {};
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(l, r);
        for (int i = l; i <= r; ++i) {
            s[i]++;
        }
    }

    while(true) {
        bool flag = true;
        for (int i = 1; i <= 50; ++i) {
            if (s[i] >= s[k] && i != k) flag = false;
        }
        if (flag) {
            cout << "YES" << '\n';
            return;
        }

        if (a.empty()) break;
        auto [l,r] = a.back();
        a.pop_back();
        if (l <= k && k <= r) continue;

        for (int i = l; i <= r; ++i) {
            s[i]--;
        }
    }
    cout << "NO" << '\n';
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
