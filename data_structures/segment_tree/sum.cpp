#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1e6;
int N;
ll a[MAX_N+1], seg[4*MAX_N];

void build(int v, int l, int r) {
    if (l == r) {
        seg[v] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(2*v, l, m), build(2*v+1, m+1, r);
    seg[v] = seg[2*v] + seg[2*v+1];
}

ll sum_query(int v, int s, int e, int l, int r) {
    if (l > r)
        return 0;
    if (l == s && r == e)
        return seg[v];

    int m = (s+e)/2;
    return sum_query(2*v, s, m, l, min(r, m))
        + sum_query(2*v+1, m+1, e, max(l, m+1), r);
}

void update(int v, int l, int r, int index, ll value) {
    if (l == r) {
        seg[v] = value;
        return;
    }
    int m = (l+r)/2;
    if (index <= m)
        update(2*v, l, m, index, value);
    else
        update(2*v+1, m+1, r, index, value);
    seg[v] = seg[2*v] + seg[2*v+1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    build(1, 1, N);
    ll a, b, c;
    for (int i = 0; i < M+K; ++i) {
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 1, N, b, c);
        else
            cout << sum_query(1, 1, N, b, c) << '\n';
    }

    return 0;
}
