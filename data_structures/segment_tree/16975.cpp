    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    const int INF = 1e9;

    struct FenwickTree {
        vector<ll> tree;
        vector<ll> data;
        FenwickTree(int n): tree(n+1, 0), data(n+1, 0){}
        ll sum(int pos) {
            ll ret = 0;
            while (pos > 0) {
                ret += tree[pos];
                pos &= (pos-1); // delete last bit
            }
            return ret;
        }
        void add(int pos, ll val) {
            data[pos] += val;
            while (pos < (int)tree.size()) {
                tree[pos] += val;
                pos += (pos & -pos); // add last bit
            }
        }
        void init(vector<ll> a) {
            for (int i = 0; i < (int)a.size(); ++i) {
                add(i+1, a[i]);
            }
        }
    };

    int main()
    {
        cin.tie(0)->sync_with_stdio(0);
        
        int N;
        cin >> N;

        vector<ll> d(N+1); d[N] = 0;
        for (int i = 0, prev = 0, x; i < N; ++i) {
            cin >> x;
            d[i] = x-prev; prev = x;
        }
        FenwickTree tree(N+1);
        tree.init(d);

        int M;
        cin >> M;
        while (M--) {
            int mod; cin >> mod;
            if (mod == 1) {
                int i, j, k; cin >> i >> j >> k;
                tree.add(i, k); tree.add(j+1, -k);
            } else {
                int x; cin >> x;
                cout << tree.sum(x) << '\n';
            }
        }
        
        return 0;
    }