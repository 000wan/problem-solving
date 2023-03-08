#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    int a[N+1], b[N+1];
    for (int i = 0; i < N; ++i) {
        cin >> a[i+1];
        b[i+1] = a[i+1] + i+1;
    }

    for (int i = 1; i <= N; ++i) {
        int l = lower_bound(b+1, b+N+1, i+1) - b-1;
        int r = upper_bound(b+1, b+N+1, i+1) - b-1;
        cout << i-l << ' ';
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
