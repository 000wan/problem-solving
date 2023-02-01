#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define INF (int)1e9

int dijkstra(int s, int dest, int V, vector<pair<int, int>> adj[]) {
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
	
	return D[dest];
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
		adj[v].push_back(make_pair(u, w));
	}
	
	int v1, v2;
	cin >> v1 >> v2;
	
	int res = INF;
	
	int d1 = dijkstra(1, v1, V, adj);
	int d2 = dijkstra(v1, v2, V, adj);
	int d3 = dijkstra(v2, V, V, adj);
	
	if (d1 == INF || d2 == INF || d3 == INF)
		res = min(res, INF);
	else
		res = min(res, d1 + d2 + d3);
	
	int e1 = dijkstra(1, v2, V, adj);
	int e2 = dijkstra(v2, v1, V, adj);
	int e3 = dijkstra(v1, V, V, adj);
	
	if (e1 == INF || e2 == INF || e3 == INF)
		res = min(res, INF);
	else
		res = min(res, e1 + e2 + e3);
	
	if (res == INF)
		res = -1;
	cout << res;
	
	return 0;
}

