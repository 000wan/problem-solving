#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N;
    cin >> N;
    int a[N+1];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a+N);
    a[N] = 1e6;

    int res = 0;
    if (a[0] != 0)
        res += 1;
    for (int i = 0; i < N; ++i) {
        if (i >= a[i] && i+1 < a[i+1])
            res++;
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
