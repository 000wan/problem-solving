#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

struct Edge {
    int from, to, weight;
};

// Bellman-Ford: O(VE), can detect negative cycles
bool cycle_bellman_ford(int s, int V, int E, vector<Edge> edge) {
    vector<ll> D(V+1, INF);
	D[s] = 0;
	
    for (int i = 1; i <= V-1; ++i) { // Relax edges for V-1 times
        for (int j = 0; j < E; ++j) {
            int v = edge[j].from;
            int w = edge[j].to; // v -> w
            int weight = edge[j].weight;
            if (D[v] + weight < D[w])
                D[w] = D[v] + weight;
        }
    }
    
    // check for negative cycle
    for (int j = 0; j < E; ++j) {
        int v = edge[j].from;
        int w = edge[j].to; // v -> w
        int weight = edge[j].weight;
        if (D[v] + weight < D[w])
            return true;
    }

	return false;
}

void solve() {
	int V, E, W;
	cin >> V >> E >> W;
    vector<Edge> edge;	
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
        Edge e1 = {u, v, w};
        Edge e2 = {v, u, w};
		edge.push_back(e1);
		edge.push_back(e2);
	}
	for (int i = 0; i < W; i++) {
		int u, v, w;
		cin >> u >> v >> w;
        Edge e1 = {u, v, -w};
		edge.push_back(e1);
	}
    
    bool flag = cycle_bellman_ford(1, V, 2*E+W, edge);

    if (flag)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }

    return 0;
}
