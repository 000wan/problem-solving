#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Union & Find MOD
#define FIND 1
#define UNION 0

const int MAX_N = 1e6;
int N;
int a[MAX_N], parent[MAX_N], height[MAX_N];

void init(int n) {
    N = n+1;
    for (int i = 0; i < N; ++i) {
        a[i] = i;
        parent[i] = i;
        height[i] = 1;
    }
}

void union_set(int elem, int asso) { // elem -> asso
    if (height[elem] == height[asso])
        height[asso]++;
    else if (height[elem] > height[asso])
        swap(elem, asso);

    parent[elem] = asso;
}

bool union_find(int v, int w, int MOD) {
    int i = v, j = w;
    while (parent[i] != i)
        i = parent[i];
    while (parent[j] != j)
        j = parent[j];

    if (MOD == UNION && i != j)
        union_set(i, j);
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
        bool res = union_find(a, b, MOD);
        if (MOD == FIND) {
            if (res)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}
