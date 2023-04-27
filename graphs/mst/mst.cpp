#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_V = 1e4;
int a[MAX_V+1], parent[MAX_V+1], height[MAX_V+1];

struct Edge {
    int v1, v2;
    int weight;
    
    Edge (int v1, int v2, int weight): v1(v1), v2(v2), weight(weight){}
    bool operator < (const Edge& e) const {
        return (weight > e.weight); // max heap -> min heap
    }
};

vector<Edge> G;
bool union_set(int v, int w);
void init(int V) {
    G.clear();
    for (int i = 1; i <= V; ++i) { // start from 1
        a[i] = i; 
        parent[i] = i;
        height[i] = 1;
    }
}

// Kruskal algorithm: Find MST, Greedy, O(ElogV) 
int kruskal(int V, int E) {
    priority_queue<Edge> pq (G.begin(), G.end());
    
    int res = 0, cnt = 0;
    while (!pq.empty()) {
        auto [v1, v2, weight] = pq.top();
        pq.pop();

        if (!union_set(v1, v2)) { // exclude cycle
            res += weight;
            cnt ++;
        }
        if (cnt == V-1) // visited all nodes
            return res;
    }
    return INF; // MST doesn't exist
}

// Union & Find data structure
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

bool union_set(int v, int w) {
    int i = union_find(v), j = union_find(w);
    union_link(i, j);
    return (i == j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    
    init(V);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G.emplace_back(a, b, c);
    }
    cout << kruskal(V, E) << '\n';
    
    return 0;
}
