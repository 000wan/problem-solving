#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

// Union & Find MOD
#define FIND 1
#define UNION 0

const int MAX_N = 5e5;
int N;
int a[MAX_N], parent[MAX_N], height[MAX_N];

void init(int N) {
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

    bool flag = true;
    for (int i = 1; i <= M; ++i) {
        int x, y;
        cin >> x >> y;
        if (flag) {
            if (union_find(x, y, UNION)) {
                cout << i << '\n';
                flag = false;
            }
        }
    }
    if (flag)
        cout << 0 << '\n';

    return 0;
}
