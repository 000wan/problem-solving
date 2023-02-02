#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N, M, V;
int A[10][10];
int parent[7], height[7];

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
    for (int i = 1; i <= V; ++i) { // start from 1
        parent[i] = i;
        height[i] = 1;
    }
}

// Kruskal algorithm: Find MST, Greedy, O(ElogE) 
int kruskal(int V) {
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

int team[10][10];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
void dfs(int x, int y, int index) {
    team[x][y] = index;
    for (int i=0; i<4; i++) {
        if (0 <= x+dx[i] && x+dx[i] <= N-1 && 0 <= y+dy[i] && y+dy[i] <= M-1) {
            if (A[x+dx[i]][y+dy[i]] == 0) 
                continue;
            if (team[x+dx[i]][y+dy[i]])
                continue;
            dfs(x+dx[i], y+dy[i], index);    
        }
    }
}

void init_team(vector<pair<int,int>> starts) {
    V = 0;
    for (auto& [x,y] : starts) {
        if (!team[x][y])
            dfs(x, y, ++V);
    }
}

void init_graph(vector<pair<int,int>> starts) {
    vector<vector<int>> Adj (V+1, vector<int>(V+1, INF));
    for (auto& [x,y] : starts) {
        int v = team[x][y];
        
        for (int i = x+1; i < N; ++i) {
            int w = team[i][y], d = abs(i-x)-1;
            if (!w)
                continue;
            if (d >= 2)
                Adj[v][w] = Adj[w][v] = min(Adj[v][w], d);
            break;
        }
        for (int i = x-1; i >= 0; --i) {
            int w = team[i][y], d = abs(i-x)-1;
            if (!w)
                continue;
            if (d >= 2)
                Adj[v][w] = Adj[w][v] = min(Adj[v][w], d);
            break;
        }
        for (int j = y+1; j < M; ++j) {
            int w = team[x][j], d = abs(j-y)-1;
            if (!w)
                continue;
            if (d >= 2)
                Adj[v][w] = Adj[w][v] = min(Adj[v][w], d);
            break;
        }
        for (int j = y-1; j >= 0; --j) {
            int w = team[x][j], d = abs(j-y)-1;
            if (!w)
                continue;
            if (d >= 2)
                Adj[v][w] = Adj[w][v] = min(Adj[v][w], d);
            break;
        }
    }

    for (int i = 1; i < V; ++i) { 
        for (int j = i+1; j <= V; ++j) {
            if (Adj[i][j] != INF) {
                G.emplace_back(i, j, Adj[i][j]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    std::vector<pair<int,int>> starts;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            if (A[i][j] == 1)
                starts.emplace_back(i, j);
        }
    }
    init_team(starts);
    init_graph(starts);
    init(V);

    int res = kruskal(V);
    if (res == INF)
        cout << -1 << '\n';
    else
        cout << res << '\n';

    return 0;
}
