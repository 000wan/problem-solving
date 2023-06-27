#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

struct SegmentTree {
    int size;
    vector<ll> tree, data;
    SegmentTree(int n):
        size(n), tree(4*n, 0), data(n, 0) {}
    SegmentTree(int n, vector<ll> a):
        size(n), tree(4*n), data(a) {
            build();
        }
    public:
        void build() {
            build(1, 1, size-1);
        }
        ll get(int l, int r) {
            return get(1, 1, size-1, l, r);
        }
        void update(int pos, ll val) {
            data[pos] += val;
            update(1, 1, size-1, pos, val);
        }
        int search(ll k) {
            return search(1, 1, size-1, k);
        }
    private:
        void build(int v, int s, int e) {
            if (s == e) {
                tree[v] = data[s]; return;
            }
            int mid = (s+e)/2;
            build(2*v, s, mid); build(2*v+1, mid+1, e);
            tree[v] = tree[2*v] + tree[2*v+1];
        }
        ll get(int v, int s, int e, int l, int r) {
            if (e < l || r < s) return 0;
            if (l <= s && e <= r) return tree[v];
            int mid = (s+e)/2;
            return get(2*v, s, mid, l, r) + get(2*v+1, mid+1, e, l, r);
        }
        void update(int v, int s, int e, int pos, ll val) {
            if (s == e) {
                tree[v] += val; return;
            }
            int mid = (s+e)/2;
            if (pos <= mid) update(2*v, s, mid, pos, val);
            else update(2*v+1, mid+1, e, pos, val);
            tree[v] = tree[2*v] + tree[2*v+1];
        }
        int search(int v, int s, int e, ll x) {
            if (s == e) {
                tree[v] -= 1; return s;
            }
            int mid = (s+e)/2, ret;
            if (x <= tree[2*v])
                ret = search(2*v, s, mid, x);
            else
                ret = search(2*v+1, mid+1, e, x-tree[2*v]);
            tree[v] = tree[2*v] + tree[2*v+1];
            return ret;
        }
};

const int MAX_N = 1e6;
void solve() {
    int N;
    cin >> N;
    
    SegmentTree seg(MAX_N+1); seg.build();
    while (N--) {
        int mod; cin >> mod;
        if (mod == 1) {
            int x; cin >> x;
            cout << seg.search(x) << '\n';
        } else {
            int x, c; cin >> x >> c;
            seg.update(x, c);
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