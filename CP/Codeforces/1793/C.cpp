#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N;
int a[(int)2e5];

int minseg[(int)4e5+10];
int maxseg[(int)4e5+10];

int segmin(int node, int l, int r) {
    if (l == r)
        return minseg[node] = a[l];

    int mid = (l+r)/2;
    return minseg[node] = min(segmin(2*node, l, mid), segmin(2*node+1, mid+1, r));
}
int segmax(int node, int l, int r) {
    if (l == r)
        return maxseg[node] = a[l];

    int mid = (l+r)/2;
    return maxseg[node] = max(segmax(2*node, l, mid), segmax(2*node+1, mid+1, r));
}

int minquery(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return INF;
    if (l <= s && e <= r) return minseg[node];
    int mid = (s + e) / 2;
    return min(minquery(2 * node, s, mid, l, r), minquery(2 * node + 1, mid + 1, e, l, r));
}
int maxquery(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return -INF;
    if (l <= s && e <= r) return maxseg[node];
    int mid = (s + e) / 2;
    return max(maxquery(2 * node, s, mid, l, r), maxquery(2 * node + 1, mid + 1, e, l, r));
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    segmin(1, 0, N-1);
    segmax(1, 0, N-1);
    int smin = INF, smax = -INF;
    while (l <= r && r < N) {
        smin = minquery(1, 0, N-1, l, r);
        smax = maxquery(1, 0, N-1, l, r);
        //cout << l << ' ' << r << ' ' << smin << ' ' << smax << '\n';
        if (a[r] == smin || a[r] == smax) {
            r++;
        }
        else if (a[l] == smin || a[l] == smax) {
            l++;
        }
        else {
            cout << l+1 << ' ' << r+1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
    return;
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
