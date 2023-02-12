#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    std::priority_queue<int, vector<int>, greater<int>> a;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        a.emplace(x);
    }
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        a.pop();
        a.emplace(x);
    }

    ll res = 0;
    while (!a.empty()) {
        res += a.top();
        a.pop();
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
