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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    FenwickTree fen(N);
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    fen.init(a);

    for (int i = 0; i < M+K; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            fen.add(b, c-fen.data[b]);
        } else {
            cout << fen.sum(c) - fen.sum(b-1) << '\n';
        }
    }

    return 0;
}
