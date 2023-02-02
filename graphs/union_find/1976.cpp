#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Union & Find MOD
#define FIND 1
#define UNION 0

const int MAX_N = 2e2+1;
int a[MAX_N], parent[MAX_N], height[MAX_N];

void init(int N) {
    for (int i = 1; i <= N; ++i) {
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

    int N;
    cin >> N;
    int M;
    cin >> M;
    
    init(N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int x;
            cin >> x;
            if (x == 1)
                union_find(i, j, UNION);
        }
    }
   
    int V[M];
    for (int i = 0; i < M; ++i) {
        cin >> V[i];
    }

    bool flag = true;
    for (int i = 0; i < M; ++i) {
        flag = flag && union_find(V[0], V[i], FIND);
    }
    if (flag)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}
