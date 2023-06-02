#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    int a[N], b[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }
    vector<pii> v;
    for (int i = 0; i < N; ++i) {
        v.emplace_back(b[i], a[i]);
    }
    sort(all(v));
    
    ll res = v[0].second;
    priority_queue<int> pq;
    for (int i = 1; i < N-1; i+=2) {
        pq.emplace(v[i].second);
        pq.emplace(v[i+1].second);
        res += pq.top(); pq.pop();
    }
    cout << res << '\n';
    
    return 0;
}