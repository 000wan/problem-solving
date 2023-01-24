#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

// Floyd-Warshall: O(V^3), find all path pairs, available for negative weights
vector<vector<ll>> floyd(int V, vector<pair<int, int>> adj[]) {
    vector<vector<ll>> D(V+1, vector<ll> (V+1, INF));

    for (int v = 1; v <= V; ++v) {
        D[v][v] = INF;
        for (auto iter = adj[v].begin(); iter != adj[v].end(); ++iter) {
            int w = iter->first;
            int weight = iter->second;
            D[v][w] = min(D[v][w], (ll)weight);
        }
    }

    for (int m = 1; m <= V; m++) { // middle node
        for (int v = 1; v <= V; v++) {
            for (int w = 1; w <= V; w++) {
                D[v][w] = min(D[v][w], D[v][m] + D[m][w]);
            }
        }
    }

    return D;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int V, E;
	cin >> V >> E;
	
	vector<pair<int, int>> adj[V+1]; // first: vertex, second: weight
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
    
    vector<vector<ll>> D = floyd(V, adj);
    
    ll m = INF;
    for (int v = 1; v <= V; v++) {
        m = min(m, D[v][v]);
    }
    if (m == INF) {
        cout << -1;
    } else {
        cout << m;
    }

	return 0;
}

