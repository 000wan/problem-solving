#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 2e9;
const int MAX_N = 1e5;

int N;
ll a[MAX_N];
int minseg[4*MAX_N];

int init_min(int node, int l, int r) {
    if (l == r)
        return minseg[node] = l;

    int mid = (l+r)/2;
    int nl = init_min(2*node, l, mid), nr = init_min(2*node+1, mid+1, r);
    return minseg[node] = a[nl] <= a[nr] ? nl : nr;
}

int min_query(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return INF;
    if (l <= s && e <= r) return minseg[node];
    int mid = (s + e) / 2;
    int nl = min_query(2 * node, s, mid, l, r);
    int nr = min_query(2 * node + 1, mid + 1, e, l, r);
    if (nl == INF) return nr;
    if (nr == INF) return nl;
    return a[nl] <= a[nr] ? nl : nr;
}

int update(int node, int l, int r, int ind) {
    if (ind < l || r < ind) return minseg[node];
    if (l == r) return minseg[node];

    int mid = (l+r)/2;
    int nl = update(2*node, l, mid, ind);
    int nr = update(2*node+1, mid+1, r, ind);
    if (nl == INF) return minseg[node] = nr;
    if (nr == INF) return minseg[node] = nl;
    return minseg[node] = a[nl] <= a[nr] ? nl : nr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    init_min(1, 0, N-1);

    int Q;
    cin >> Q;
    while (Q--) {
        int mod, l, r;
        cin >> mod >> l >> r;
        if (mod == 1) {
            a[l-1] = r;
            update(1, 0, N-1, l-1);
        } else {
            cout << 1+min_query(1, 0, N-1, l-1, r-1) << '\n';
        }
    }

    return 0;
}