#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    int a[N+2];
    a[0] = 0, a[N+1] = 1440;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    int curr, res = 0;
    for (int i = 0; i <= N; ++i) {
        curr = a[i];
        while (curr + 120 <= a[i+1]) {
            curr += 120;
            res++;
        }
    }

    if (res >= 2)
        cout << "YES" << '\n';
    else
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
