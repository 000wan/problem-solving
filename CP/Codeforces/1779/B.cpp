#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    
    if (n%2 == 0) {
        cout << "YES" << '\n';
        while (n--)
            cout << ((n%2 == 1) ? 1 : -1) << " \n"[n == 0];
        return;
    } else {
        int k = n/2;
        if (k <= 1) {
            cout << "NO" << '\n';
            return;
        }

        cout << "YES" << '\n';
        while (n--)
            cout << ((n%2 == 0) ? k-1 : -k) << " \n"[n == 0];
        return;
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
