#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    ll N, M;
    cin >> N >> M;
    int a[N], cnt[N+M+1] = {}, start[N+M+1] = {};
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        start[a[i]] = 0;
    }

    int i, v;
    for (int t = 1; t <= M; ++t) {
        cin >> i >> v;
        i--;
        cnt[a[i]] += t-start[a[i]];
        a[i] = v;
        start[a[i]] = t;
    }
    for (int i = 0; i < N; ++i) {
        cnt[a[i]] += M+1 - start[a[i]];
    }

    ll res = 0;
    for (int i = 1; i <= N+M; ++i) {
        int c = cnt[i];
        res += ((M+1)*M)/2 - ((M+1-c)*(M-c))/2;
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
