#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const ll MOD = 998244353;
const int MAX_N = 1e6;

vector<int> two;
void init() {
    int i = 1;
    while (i <= MAX_N) {
        two.emplace_back(i);
        i = i << 1;
    }
}
int log2(int x) {
    return upper_bound(two.begin(), two.end(), x) - two.begin() - 1;
}
int len(int r, int l) {
    return log2(r)-log2(l-1);
}

void solve() {
    int l, r;
    cin >> l >> r;

    int m = 1;
    while ((l << m) <= r) m++;

    ll res2 = 0;
    res2 += r/(1<<(m-1)) - l + 1, res2 %= MOD;
    if (m >= 2) {
        ll a = (r / (1 << (m-2))) / 3 - l + 1;
        if (a > 0) res2 += (m-1) * a, res2 %= MOD;
    }
    
    cout << m << ' ' << res2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
