#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

bool cmp(pair<ll,ll>& a, pair<ll,ll>& b) {
    auto& [p1,q1] = a;
    auto& [p2,q2] = b;
    if (p1*q2 == p2*q1) {
        return q1 < q2;
    }
    return p1*q2 > p2*q1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<pair<ll,ll>> a(N);
    for (auto& [p, q] : a) cin >> p >> q;

    sort(a.begin(), a.end(), cmp);
    ll Sp = 0, Sq = 0;
    for (int i = 0; i < K; ++i) {
        Sp += a[i].first, Sq += a[i].second;
    }

    cout << Sp/(double)Sq << '\n';

    return 0;
}
