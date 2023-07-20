#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    ll N;
    cin >> N;
    vector<pii> a(N);
    for (auto& [s, e] : a) {
        cin >> s >> e;
    }
    sort(all(a));   

    priority_queue<ll> pq;
    pq.emplace(-a[0].second);

    for (int i = 1; i < N; ++i) {
        ll end = -pq.top();
        if (a[i].first < end) {
            pq.emplace(-a[i].second);
        } else {
            pq.pop();
            pq.emplace(-a[i].second);
        }
    }
    cout << (int)pq.size() << '\n';
    
    return 0;
}