#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& x: a) cin >> x;
    a.emplace_back(0);

    ll res = 0;
    int m = N-1;
    for (int i = N-1; i >= 0; --i) {
        if (a[i] > a[m]) {
            m = i;
        } else {
            res += a[m] - a[i];
        }
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
