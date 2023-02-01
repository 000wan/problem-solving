#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Union & Find MOD
#define FIND 1
#define UNION 0
#define ROOT "\n"

struct Node {
    string parent;
    int height;
    int childs;
};

std::unordered_map<string, Node> a;

void init(string v) {
    if (a.find(v) != a.end())
        return;
    Node V { ROOT, 1, 1 };
    a[v] = V;
}

void union_set(string elem, string asso) { // elem -> asso
    if (a[elem].height == a[asso].height)
        a[asso].height++;
    else if (a[elem].height > a[asso].height)
        swap(elem, asso);

    a[elem].parent = asso;
    a[asso].childs += a[elem].childs;
}

void union_find(string v, string w, int MOD) {
    string i = v, j = w;
    while (a[i].parent != ROOT)
        i = a[i].parent;
    while (a[j].parent != ROOT)
        j = a[j].parent;

    if (MOD == UNION && i != j)
        union_set(i, j);
    cout << max(a[i].childs, a[j].childs) << '\n';
}

void solve() {
    a.clear();

    int M;
    cin >> M;
    
    while (M--) {
        string a, b;
        cin >> a >> b;
        init(a);
        init(b);
        union_find(a, b, UNION);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
