#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

string f = "FBFFBFFBFBFFBFFBFB";

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    for (int i = 0; i < (int)f.size(); ++i) {
        for (int l = 0; i+l < (int)f.size(); ++l) {
            if (f.substr(i, l) == s) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
    return;
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
