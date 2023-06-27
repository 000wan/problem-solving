#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

struct SegmentTree {
    int size;
    vector<ll> tree, data;
    SegmentTree(int n):
        size(n), tree(4*n), data(n) {}
    SegmentTree(int n, vector<ll> a):
        size(n), tree(4*n), data(a) {
            build();
        }
    public:
        void build() {
            build(1, 0, size-1);
        }
        ll get(int l, int r) {
            return get(1, 0, size-1, l, r);
        }
        void update(int pos, ll val) {
            update(1, 0, size-1, pos, val);
        }
    private:
        void build(int v, int s, int e) {
            if (s == e) {
                tree[v] = data[s]; return;
            }
            int mid = (s+e)/2;
            build(2*v, s, mid); build(2*v+1, mid+1, e);
            tree[v] = min(tree[2*v], tree[2*v+1]);
        }
        ll get(int v, int s, int e, int l, int r) {
            if (e < l || r < s) return INF;
            if (l <= s && e <= r) return tree[v];
            int mid = (s+e)/2;
            return min(get(2*v, s, mid, l, r), get(2*v+1, mid+1, e, l, r));
        }
        void update(int v, int s, int e, int pos, ll val) {
            if (s == e) {
                tree[v] = val; return;
            }
            int mid = (s+e)/2;
            if (pos <= mid) update(2*v, s, mid, pos, val);
            else update(2*v+1, mid+1, e, pos, val);
            tree[v] = min(tree[2*v], tree[2*v+1]);
        }
};


void solve() {
    int N; cin >> N;
    vector<ll> a(N);
    for (auto& x : a) {
        cin >> x;
    }
    int M; cin >> M;
    
    SegmentTree seg(N, a);
    while (M--) {
        int mod; cin >> mod;
        if (mod == 1) {
            int i, v; cin >> i >> v; i--;
            seg.update(i, v);
        } else {
            int i, j; cin >> i >> j; i--, j--;
            cout << seg.get(i, j) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}