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

    int g = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            g = min(g, gcd(a[i], a[j]));
        }
    }

    cout << ((g <= 2) ? "YES" : "NO") << '\n';
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
