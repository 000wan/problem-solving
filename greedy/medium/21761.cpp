#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;

    ll x[4];
    for (auto& i : x) {
        cin >> i;
    }
    priority_queue<ll> a[4];
    for (int i = 0; i < N; ++i) {
        char x; ll y;
        cin >> x >> y;
        a[x-'A'].push(y);
    }

    while (K--) {
        int m = 0;
        double t = 0;
        for (int i = 0; i < 4; ++i) {
            if (a[i].empty()) continue;
            double u = (double)a[i].top()/x[i];
            if (u > t) {
                t = u;
                m = i;
            }
        }
        cout << (char)(m+'A') << ' ' << a[m].top() << '\n';
        x[m] += a[m].top(); a[m].pop();
    }
    
    return 0;
}