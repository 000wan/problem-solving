#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 1e5;

int N;
int a[MAX_N];

int minseg[4*MAX_N];
int maxseg[4*MAX_N];

int init_min(int node, int l, int r) {
    if (l == r)
        return minseg[node] = a[l];

    int mid = (l+r)/2;
    return minseg[node] = min(init_min(2*node, l, mid), init_min(2*node+1, mid+1, r));
}
int init_max(int node, int l, int r) {
    if (l == r)
        return maxseg[node] = a[l];

    int mid = (l+r)/2;
    return maxseg[node] = max(init_max(2*node, l, mid), init_max(2*node+1, mid+1, r));
}

int min_query(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return INF;
    if (l <= s && e <= r) return minseg[node];
    int mid = (s + e) / 2;
    return min(min_query(2 * node, s, mid, l, r), min_query(2 * node + 1, mid + 1, e, l, r));
}
int max_query(int node, int s, int e, int l, int r)
{
    if (e < l || r < s) return -INF;
    if (l <= s && e <= r) return maxseg[node];
    int mid = (s + e) / 2;
    return max(max_query(2 * node, s, mid, l, r), max_query(2 * node + 1, mid + 1, e, l, r));
}

void solve() {
    int M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    init_min(1, 0, N-1);
    init_max(1, 0, N-1);
    int l, r;
    for (int i = 0; i < M; ++i) {
        cin >> l >> r;
        l--, r--;
        cout << min_query(1, 0, N-1, l, r) << ' ' << max_query(1, 0, N-1, l, r) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

