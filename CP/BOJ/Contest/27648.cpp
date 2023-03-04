#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int t = n+m-1;
    if (t > k) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << i+j-1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
