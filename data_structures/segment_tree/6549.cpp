#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 2e9;
const int MAX_N = 1e5;

int N;
ll a[MAX_N];
ll minseg[4*MAX_N];

ll init_min(int node, int l, int r) {
    if (l == r)
        return minseg[node] = l;

    int mid = (l+r)/2;
    int nl = init_min(2*node, l, mid), nr = init_min(2*node+1, mid+1, r);
    return minseg[node] = a[nl] <= a[nr] ? nl : nr;
}

ll min_query(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return INF;
    if (l <= s && e <= r) return minseg[node];
    int mid = (s + e) / 2;
    int nl = min_query(2 * node, s, mid, l, r), nr = min_query(2 * node + 1, mid + 1, e, l, r);
    if (nl == INF) return nr;
    if (nr == INF) return nl;
    return a[nl] <= a[nr] ? nl : nr;
}

ll solve(int l, int r) {
    if (l > r) return 0;
    int m = min_query(1, 0, N-1, l, r);

    ll res = a[m] * (r-l+1);
    res = max(res, solve(l, m-1));
    res = max(res, solve(m+1, r));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N;
        if (!N) break;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }

        init_min(1, 0, N-1);
        cout << solve(0, N-1) << '\n';
    }

    return 0;
}


