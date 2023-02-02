#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_V = 1e2;
vector<pair<double, double>> a;
int parent[MAX_V+1], height[MAX_V+1];

struct Edge {
    int v1, v2;
    double weight;
    
    Edge (int v1, int v2, double weight)
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
    a.emplace_back(0, 0);
    for (int i = 1; i <= V; ++i) { // start from 1
        double x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
        parent[i] = i;
        height[i] = 1;
    }
}

// Kruskal algorithm: Find MST, Greedy, O(ElogE) 
double kruskal(int V) {
    std::priority_queue<Edge> pq (G.begin(), G.end());
    
    double res = 0;
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

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

void solve() {
    int V;
    cin >> V;
    init(V);
    
    for (int i = 1; i < V; ++i) {
        for (int j = i+1; j <= V; ++j) {
            G.emplace_back(i, j, dist(a[i], a[j]));
        } 
    }

    printf("%f", kruskal(V));
}

int main()
{
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
