#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

struct cmp {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    bool visited[n];
    fill(visited, visited+n, false);
    
    int res = 0;
    std::priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    for (int i = 0; i < n; ++i) {
        pq.emplace(a[i]+i+1, i);
    }
    while (!pq.empty()) {
        auto [cost, i] = pq.top();
        pq.pop();
        cout << i << ' ' << cost << '\n';
        if (c < cost)
            break;
        if (visited[i])
            continue;

        if (res == 0) {
            for (int i = 0; i < n; ++i) {
                pq.emplace(a[i]+n-i, i);
            }
        }
        c -= cost;
        visited[i] = true;
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
