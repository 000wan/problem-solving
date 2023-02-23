#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (auto& x : a) {
        cin >> x;
    }

    ll low = 0, high = *max_element(a.begin(), a.end())+1, mid;
    while (low+1 < high) {
        mid = (low+high)/2;
        ll cnt = 0;
        for (auto &x : a) {
            cnt += max(x-mid, (ll)0);
        }

        if (cnt < M)
            high = mid;
        else {
            low = mid;
        }
    }
    cout << low << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
