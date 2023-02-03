#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += i+1;
    }
    
    int res = 0;
    std::priority_queue<int,vector<int>,greater<int>> pq (a.begin(), a.end());
    while (!pq.empty()) {
        int cost = pq.top();
        pq.pop();
        if (c < cost)
            break;
        c -= cost;
        res ++;
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
