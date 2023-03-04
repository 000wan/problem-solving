#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    bool f1 = false;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'R') f1 = true;
        if (f1 && s[i] == 'L') {
            cout << 0 << '\n';
            return;
        }
        if (s[i] == 'L') {
            if (i+1 < (int)s.size() && s[i+1] == 'R') {
                cout << i+1 << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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
