#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 2e9;
#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pii> a(N);
    for (auto& [x, y]: a)
        cin >> x >> y;
    sort(a.begin(), a.end());

    int res = 0;
    auto [s, e] = a[0];
    for (int i = 1; i < N; ++i) {
        auto& [x, y] = a[i];
        if (x > e) {
            res += e-s;
            s = x, e = y;
        } else {
            e = max(e, y);
        }
    }
    res += e-s;
    cout << res << '\n';

    return 0;
}
