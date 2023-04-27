#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Union & Find MOD
#define FIND 1
#define UNION 0

const int MAX_N = 1e6+1;
int a[MAX_N], parent[MAX_N], height[MAX_N];

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        a[i] = i;
        parent[i] = i;
        height[i] = 1;
    }
}

// union by rank
void union_link(int v, int w) {
    if (v == w) return;
    if (height[v] > height[w])
        swap(v, w);
    parent[v] = w;
    if (height[v] == height[w])
        height[w]++;
}

// path compression
int union_find(int v) {
    if (v != parent[v])
        parent[v] = union_find(parent[v]);
    return parent[v];
}

bool union_set(int v, int w, int MOD) {
    int i = union_find(v), j = union_find(w);
    if (MOD == UNION)
        union_link(i, j);
    return (i == j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    init(N);

    while (M--) {
        int MOD, a, b;
        cin >> MOD >> a >> b;
        bool res = union_set(a, b, MOD);
        if (MOD == FIND) {
            cout << (res ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
