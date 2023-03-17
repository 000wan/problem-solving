#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    std::priority_queue<ll, vector<ll>, greater<>> a;
    for (int x, i = 0; i < N; ++i) {
        cin >> x;
        a.emplace(x);
    }
    for (int i = 0; i < M; ++i) {
        ll x = a.top(); a.pop();
        ll y = a.top(); a.pop();
        a.emplace(x+y); a.emplace(x+y);
    }

    ll res = 0;
    while (!a.empty()) {
        res += a.top();
        a.pop();
    }
    cout << res << '\n';

    return 0;
}
