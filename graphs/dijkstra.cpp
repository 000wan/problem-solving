#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define INF (int)1e9

int* dijkstra(int s, int V, vector<pair<int, int>> adj[]) {
	int* D = new int[V+1];
	
	for (int i = 0; i <= V; ++i)
		D[i] = INF;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int V, E, K;
	cin >> V >> E >> K;
	
	vector<pair<int, int>> adj[V+1]; // first: vertex, second: weight
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	
	int* D = dijkstra(K, V, adj);
	for (int v = 1; v <= V; v++) {
		if (D[v] == INF)
			cout << "INF" << '\n';
		else
			cout << D[v] << '\n';
	}
	
	return 0;
}

