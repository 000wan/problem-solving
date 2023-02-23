#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int b[N];
    ll sum[N+1];
    sum[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        sum[i+1] = b[i] + sum[i];
    }
    
    ll cnt[N+1] = {}, remain[N+1] = {};
    for (int i = 0; i < N; ++i) {
        int j = upper_bound(sum, sum+N+1, a[i]+sum[i]) - sum-1;
        remain[j] += a[i] - (sum[j]-sum[i]);
        cnt[i] ++, cnt[j] --;
    }
    for (int i = 0; i < N; ++i) {
        cout << cnt[i] * b[i] + remain[i] << ' ';
        cnt[i+1] += cnt[i];
    }
    cout << '\n';
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
