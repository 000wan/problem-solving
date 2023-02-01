#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

// Dijkstra: O(VlogE), only for positive weights
vector<int> dijkstra(int s, int V, vector<pair<int, int>> adj[]) {
    vector<int> D(V+1, INF);
	D[s] = 0;
	
	priority_queue<pair<int, int>> pq; // first: -distance, second: vertex
	pq.push(make_pair(0, s));
	
	while(!pq.empty()) {
		// Find min vertex
		int dist = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		
		if (D[v] < dist) // not the latest
			continue;
		
		// Edge relaxation
		for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
			int w = it->first;
			int weight = it->second;
			
			if (D[v] + weight < D[w]) { // update
				D[w] = D[v] + weight;
				pq.push(make_pair(-D[w], w));
			}
		}
	}
	
	return D;
}

// Floyd-Warshall: O(V^3), find all path pairs, available for negative weights
vector<vector<ll>> floyd(int V, vector<pair<int, int>> adj[]) {
    vector<vector<ll>> D(V+1, vector<ll> (V+1, INF));

    for (int v = 1; v <= V; ++v) {
        D[v][v] = 0;
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

// Bellman-Ford: O(VE), can detect negative cycles
vector<ll> bellman_ford(int s, int V, vector<pair<int, int>> adj[]) {
    vector<ll> D(V+1, INF);
	D[s] = 0;
	
    for (int i = 1; i <= V-1; ++i) { // Relax edges for V-1 times
        for (int v = 1; v <= V; ++v) { // start node of edge
            for (auto iter = adj[v].begin(); iter != adj[v].end(); ++iter) {
                int w = iter->first; // v -> w
                int weight = iter->second;
                if (D[v] != INF && D[v] + weight < D[w])
                    D[w] = D[v] + weight;
            }
        }
    }
    
    // check for negative cycle
    vector<ll> empty;
    for (int v = 1; v <= V; ++v) {
        for (auto iter = adj[v].begin(); iter != adj[v].end(); ++iter) {
            int w = iter->first; // v -> w
            int weight = iter->second;
            if (D[v] != INF && D[v] + weight < D[w])
                return empty; 
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
	
    // dijkstra
	vector<int> D = dijkstra(K, V, adj);
	for (int v = 1; v <= V; v++) {
		if (D[v] == INF)
			cout << "INF" << '\n';
		else
			cout << D[v] << '\n';
	}
   
    // floyd-warshall
    vector<vector<ll>> D = floyd(V, adj);

    for (int v = 1; v <= V; v++) {
        for (int w = 1; w <= V; w++) {
            if (D[v][w] == INF)
                cout << 0 << ' ';
            else
                cout << D[v][w] << ' ';
        }
        cout << '\n';
    }

    // bellman-ford
    vector<ll> D = bellman_ford(1, V, adj);
    if (D.empty())
        cout << -1 << '\n';
    else {
        for (int v = 2; v <= V; v++) {
            if (D[v] == INF)
                cout << -1 << '\n';
            else
                cout << D[v] << '\n';
        }
    }

	return 0;
}

