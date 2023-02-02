#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_V = 2e5;
int a[MAX_V+1], parent[MAX_V+1], height[MAX_V+1];

struct Edge {
    int v1, v2;
    int weight;
    
    Edge (int v1, int v2, int weight)
        : v1(v1)
        , v2(v2)
        , weight(weight)
    {}
    bool operator < (const Edge& e) const {
        return (weight > e.weight); // max heap -> min heap
    }
};

std::vector<Edge> G;

void union_set(int elem, int asso);
bool union_find(int v, int w);
void init(int V) {
    G.clear();
    for (int i = 0; i < V; ++i) { // start from 1
        a[i] = i;
        parent[i] = i;
        height[i] = 1;
    }
}

// Kruskal algorithm: Find MST, Greedy, O(ElogE) 
int kruskal(int V, int E) {
    std::priority_queue<Edge> pq (G.begin(), G.end());
    
    int res = 0;
    int cnt = 0;
    while (!pq.empty()) {
        auto [v1, v2, weight] = pq.top();
        pq.pop();

        if (!union_find(v1, v2)) { // exclude cycle
            res += weight;
            cnt ++;
        }
        if (cnt == V-1) // visited all nodes
            return res;
    }
    return INF; // MST doesn't exist
}

// Union & Find
void union_set(int elem, int asso) { // elem -> asso
    if (height[elem] == height[asso])
        height[asso]++;
    else if (height[elem] > height[asso])
        swap(elem, asso);

    parent[elem] = asso;
}

bool union_find(int v, int w) {
    int i = v, j = w;
    while (parent[i] != i)
        i = parent[i];
    while (parent[j] != j)
        j = parent[j];

    if (i != j)
        union_set(i, j);
    return (i == j);
}

void solve(int V, int E) {
    int total = 0;
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G.emplace_back(a, b, c);
        total += c;
    }
    cout << total - kruskal(V, E) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        int V, E;
        cin >> V >> E;
        if (V == 0 && E == 0)
            break;
        init(V);
        solve(V, E);
    }
    
    return 0;
}
