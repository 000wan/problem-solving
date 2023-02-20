#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

bool check(vector<char>& a) {
    if (a.empty()) return true;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i-1]) return false;    
    }
    return true;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<char> a, b;
    for (int i = 0; i < N; ++i) {
        char x;
        cin >> x;
        a.emplace_back(x);
    }
    for (int i = 0; i < M; ++i) {
        char x;
        cin >> x;
        b.emplace_back(x);
    }

    while (!b.empty()) {
        a.emplace_back(b.back());
        b.pop_back();
    }

    while (true) {
        if (check(a) && check(b)) {
            cout << "YES" << '\n';
            return;
        }
        if (a.empty()) break;
        b.emplace_back(a.back());
        a.pop_back();
    }
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
