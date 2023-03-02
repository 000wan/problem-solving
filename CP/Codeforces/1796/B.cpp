#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.front() == s2.front()) {
        cout << "YES" << '\n';
        cout << s1.front() << '*' << '\n';
        return;
    }
    if (s1.back() == s2.back()) {
        cout << "YES" << '\n';
        cout << '*' << s1.back() << '\n';
        return;
    }
    for (int i = 0; i < s1.size()-1; ++i) {
        for (int j = 0; j < s2.size()-1; ++j) {
            if (s1[i] == s2[j] && s1[i+1] == s2[j+1]) {
                cout << "YES" << '\n';
                cout << '*' << s1[i] << s1[i+1] << '*' << '\n';
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
