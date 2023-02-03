#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    ll res = 0;
    std::priority_queue<int,vector<int>,greater<int>> pq (a.begin(), a.end());
    while (!pq.empty()) {
        if (pq.size() == 1) {
            res += pq.top();
            pq.pop();
            break;
        }
        ll s = pq.top();
        pq.pop();
        s += pq.top();
        pq.pop();

        if (s < 0)
            res += -s;
        else
            res += s;
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
