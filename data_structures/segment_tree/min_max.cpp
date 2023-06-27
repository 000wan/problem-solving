#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 1e5;

int A[MAX_N];
int minseg[4*MAX_N], maxseg[4*MAX_N];
void init(int v, int l, int r) {
    if (l == r) {
        minseg[v] = maxseg[v] = A[l];
        return;
    }
    int mid = (l+r)/2;
    init(2*v, l, mid); init(2*v+1, mid+1, r);

    minseg[v] = min(minseg[2*v], minseg[2*v+1]);
    maxseg[v] = max(maxseg[2*v], maxseg[2*v+1]);
}
void update(int v, int l, int r, int index, ll value) {
    if (l == r) {
        minseg[v] = maxseg[v] = value;
        return;
    }
    int m = (l+r)/2;
    if (index <= m)
        update(2*v, l, m, index, value);
    else
        update(2*v+1, m+1, r, index, value);
    minseg[v] = min(minseg[2*v], minseg[2*v+1]);
    maxseg[v] = max(maxseg[2*v], maxseg[2*v+1]);
}

int minq(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return INF;
    if (l <= s && e <= r) return minseg[node];
    int mid = (s + e) / 2;
    return min(minq(2 * node, s, mid, l, r), minq(2 * node + 1, mid + 1, e, l, r));
}
int maxq(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return -INF;
    if (l <= s && e <= r) return maxseg[node];
    int mid = (s + e) / 2;
    return max(maxq(2 * node, s, mid, l, r), maxq(2 * node + 1, mid + 1, e, l, r));
}

void solve() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        A[i] = i;
    }
    init(1, 0, N-1);

    while (M--) {
        int q, a, b; cin >> q >> a >> b;
        if (q == 1) {
            bool res = minq(1, 0, N-1, a, b) == a
                && maxq(1, 0, N-1, a, b) == b;
            cout << (res ? "YES" : "NO") << '\n';
        } else {
            int ta = A[a], tb = A[b];
            swap(A[a], A[b]);
            update(1, 0, N-1, a, tb);
            update(1, 0, N-1, b, ta);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}