#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int x, y;
    cin >> x >> y;
    
    cout << (x-y)*2 << '\n';
    for (int i = x; i > y; --i) {
        cout << i << ' ';
    }
    for (int i = y; i < x; ++i) {
        cout << i << ' ';
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
